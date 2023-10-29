import sys
import math


# Funkcja sprawdza orientację mnożąc wektory 0 wspoliniowe 1 przeciwnie do wskazowek zegara 2 zgodnie
def orientation(p, q, r):
    value = (q[1] - p[1]) * (r[0] - q[0]) - \
        (q[0] - p[0]) * (r[1] - q[1])
    if value == 0:
        return 0
    return 1 if value > 0 else 2


# funkcja znajduje punkty ktore otaczaja wszystkie inne
def find_border(points):
    # jesli jest mniej niz 3 punkty nie było by co otaczac
    n = len(points)
    if n < 3:
        return points

    # punkt o najmniejszym y a jak takie samo y to o min x
    min_point = min(points, key=lambda point: (point[1], point[0]))

    # punkty posortowane wzgledem (kąta) a wlasciwiej arctg do min_point
    points_kat = sorted(points, key=lambda point: (
        math.atan2(point[1] - min_point[1], point[0] - min_point[0])))

    ramka = [points_kat[0], points_kat[1]]

    # iteruje przez posortowane punkty usuwajac te ktore nie sa w ramce
    for i in range(2, n):
        while len(ramka) > 1 and orientation(ramka[-2], ramka[-1], points_kat[i]) != 2:
            ramka.pop()
        ramka.append(points_kat[i])

    return ramka


# odczytuje plik i zwraca ewentulane błedy
# filename = input('Podaj nazwę pliku (wraz z jego rozszerzeniem) w którym będą znajdować punkty: ')
filename = 'text.txt'
try:
    with open(filename, 'r') as file:
        lines = file.readlines()
except FileNotFoundError:
    print('Podany plik nie istnieje')
    sys.exit()
except:
    print('Error')
    sys.exit()

# tworzy tuple z danych z pliku
points = []
for line in lines[1:]:
    print(line)
    points.append(tuple((map(float, line.split()))))

print(find_border(points))
