# PWR_Racing
Zadanie rekrutacyjne(załączone dwa pliki bo nie przeczytałem na początku że ma być w c++ i jak już napisalem to pomyślałem że zalącze)

Program korzysta z dwóch struktur danych:
Point: przechowuje współrzędne punktu na płaszczyźnie.
vector: przechowuje wczytane punkty z pliku.

Wczytuje punkty z pliku do wektora.
Znajduje punkt o najmniejszym x (lub najmniejszym y w przypadku takich samych x).
Rozpoczyna od tego punktu i znajduje punkty tworzące ramkę.
Iteruje przez punkty, określając ich orientację względem obecnie badanej krawędzi otoczki.
Wybiera kolejny punkt jako ten o największym kącie w stosunku do poprzedniego punktu na otoczce.
Kończy, gdy wróci do punktu startowego.

orientation(): określa orientację punktów względem siebie - czy są współliniowe, czy tworzą krawędź zgodnie z ruchem wskazówek zegara lub przeciwnie do nich.

Użytkownik podaje nazwę pliku z danymi.
Program wczytuje ilość punktów oraz ich współrzędne z pliku.
Sprawdza, czy istnieje możliwość utworzenia ramki (minimalnie 3 punkty).

Wynikiem działania programu jest wyświetlenie współrzędnych punktów, jeśli istnieje ramka, w przeciwnym razie informacja o braku możliwości jej stworzenia dla podanych punktów.
