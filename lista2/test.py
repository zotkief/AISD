import matplotlib.pyplot as plt

def wczytaj_dane(plik):
    dane = []
    with open(plik, "r") as f:
        for linia in f:
            liczby = list(map(int, linia.split()))
            if len(liczby) == 3:
                dane.append(liczby)
    return dane

dane = wczytaj_dane("wyniki.txt")

if len(dane) < 50:
    print("Za mało danych w pliku!")
    exit()

dane = dane[:50]

x = [wiersz[0] for wiersz in dane] 
y_czerwone = [wiersz[1] for wiersz in dane] 
y_zielone = [wiersz[2] for wiersz in dane]

plt.figure(figsize=(10, 6))

plt.scatter(x, y_czerwone, color='red', label='porównania', marker='o')

plt.scatter(x, y_zielone, color='green', label='przestawienia', marker='o')

plt.title("granica opłacalności zmiany algorytmu (na przykładzie sortowania 10000 losowych liczb)")
plt.xlabel("granica zmiany")
plt.ylabel("y")
plt.legend()

plt.savefig("granica.png", format="png")

plt.show()
