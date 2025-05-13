import matplotlib.pyplot as plt

# Funkcja do wczytania danych z pliku
def wczytaj_dane(plik):
    dane = []
    with open(plik, "r") as f:
        for linia in f:
            liczby = list(map(int, linia.split()))
            if len(liczby) == 3:
                dane.append(liczby)
    return dane

# Wczytujemy dane
dane = wczytaj_dane("wyniki.txt")

# Upewniamy się, że mamy co najmniej 50 zestawów danych
if len(dane) < 50:
    print("Za mało danych w pliku!")
    exit()

# Wybieramy pierwsze 50 zestawów
dane = dane[:50]

# Przygotowanie danych do wykresu
x = [wiersz[0] for wiersz in dane]  # Pierwsza liczba jako argument (x)
y_czerwone = [wiersz[1] for wiersz in dane]  # Druga liczba (czerwone kropki)
y_zielone = [wiersz[2] for wiersz in dane]  # Trzecia liczba (zielone kropki)

plt.axvline(x=7, color='blue', linestyle=':', linewidth=2)
plt.text(y=0.1, x=8, s='y = 0.5', color='blue', va='bottom', ha='left')

# Tworzenie wykresu
plt.figure(figsize=(10, 6))

# Wykres dla drugiej liczby - czerwone kropki
plt.scatter(x, y_czerwone, color='red', label='porównania', marker='o')

# Wykres dla trzeciej liczby - zielone kropki
plt.scatter(x, y_zielone, color='green', label='przestawienia', marker='o')

# Ustawienia wykresu
plt.title("granica opłacalności zmiany algorytmu (na przykładzie sortowania 10000 losowych liczb)")
plt.xlabel("granica zmiany")
plt.ylabel("y")
plt.legend()

# Zapisanie wykresu do pliku PDF
plt.savefig("granica.png", format="png")

# Wyświetlenie wykresu
plt.show()
