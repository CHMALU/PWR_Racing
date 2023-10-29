#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

// struktura punktu z dwoma wspolrzednymi
struct Point
{
    double x, y;
};

// Funkcja sprawdza orientację mnożąc wektory 0 wspoliniowe 1 przeciwnie do wskazowek zegara 2 zgodnie
int orientation(Point p, Point q, Point r)
{
    double val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0)
        return 0;
    return (val > 0) ? 1 : 2;
}

// funkcja znajduje punkty ktore otaczaja wszystkie inne
vector<Point> find_border(vector<Point> &points)
{
    // jesli jest mniej niz 3 punkty nie było by co otaczac
    int n = points.size();
    if (n < 3)
        return vector<Point>();

    vector<Point> ramka;

    // punkt o najmniejszym x a jak takie samo x to o min y
    int leftmost = 0;
    for (int i = 1; i < n; i++)
    {
        if (points[i].x < points[leftmost].x)
            leftmost = i;
    }

    // dodaje do ramki odpowiednie punkty
    int p = leftmost, q;
    do
    {
        ramka.push_back(points[p]);
        q = (p + 1) % n;

        for (int i = 0; i < n; i++)
        {
            if (orientation(points[p], points[i], points[q]) == 2)
                q = i;
        }

        p = q;

    } while (p != leftmost);

    return ramka;
}

int main()
{
    // otwiera plik
    string filename;
    cout << "Podaj nazwę pliku z danymi: ";
    cin >> filename;

    ifstream file(filename);
    if (!file.is_open())
    {
        cout << "Error";
        return 1;
    }

    int lenPoints;
    file >> lenPoints;

    // przypisuje punkty do vektora
    vector<Point> points(lenPoints);
    for (int i = 0; i < lenPoints; ++i)
    {
        file >> points[i].x >> points[i].y;
    }
    file.close();

    // wypisuje punkty ktore tworza ramke jesli jest
    vector<Point> ramka = find_border(points);
    if (ramka.empty())
    {
        cout << "Nie ma ramki" << endl;
    }
    else
    {
        for (const auto &point : ramka)
        {
            cout << point.x << ", " << point.y << endl;
        }
    }

    return 0;
}
