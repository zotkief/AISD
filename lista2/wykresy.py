import numpy as np
import matplotlib.pyplot as plt

# Zakres wartości N
start_N = 1000
end_N = 50000
step = 1000

# Listy do przechowywania wyników
Ns = []
comparison_means = []
swap_means = []

sorts = ["mix","qui"]
colors = ['red','blue']

# Tworzenie wykresów
plt.figure(figsize=(10, 6))
# Wykres średniej liczby porównań
plt.subplot(2, 1, 1)
plt.xlabel('Rozmiar N')
plt.ylabel('Średnia liczba porównań')
plt.title('Średnia liczba porównań w zależności od N')
plt.grid(True)
for i in range(2):
    for N in range(start_N, end_N + step, step):
        filename = f'wyniki/ran{sorts[i]}{str(N)}x1.txt'


        try:
            # Odczytanie danych z pliku
            with open(filename, 'r') as file:
                comparisons = []
                swaps = []
                
                # Odczytanie każdej linii i podział danych
                for line in file:
                    # Zakładam, że dane są w formacie: <porównania> <przestawienia>
                    comparison, swap = map(int, line.split())
                    comparisons.append(comparison)
                    swaps.append(swap)

                # Obliczenie średniej liczby porównań i przestawień
                comparison_mean = np.mean(comparisons)
                swap_mean = np.mean(swaps)

                # Zapisanie wyników
                Ns.append(N)
                comparison_means.append(comparison_mean)
                swap_means.append(swap_mean)

        except FileNotFoundError:
            print(f'Plik {filename} nie został znaleziony.')
            continue

            
    plt.scatter(Ns, comparison_means, marker='o', color=colors[i], label='Średnia liczba porównań')
# Wykres średniej liczby przestawień
plt.subplot(2, 1, 2)
plt.xlabel('Rozmiar N')
plt.ylabel('Średnia liczba przestawień')
plt.title('Średnia liczba przestawień w zależności od N')
plt.grid(True)

plt.tight_layout()

for i in range(2):
    for N in range(start_N, end_N + step, step):
        filename = f'wyniki/ran{sorts[i]}{str(N)}x1.txt'


        try:
            # Odczytanie danych z pliku
            with open(filename, 'r') as file:
                comparisons = []
                swaps = []
                
                # Odczytanie każdej linii i podział danych
                for line in file:
                    # Zakładam, że dane są w formacie: <porównania> <przestawienia>
                    comparison, swap = map(int, line.split())
                    comparisons.append(comparison)
                    swaps.append(swap)

                # Obliczenie średniej liczby porównań i przestawień
                comparison_mean = np.mean(comparisons)
                swap_mean = np.mean(swaps)

                # Zapisanie wyników
                Ns.append(N)
                comparison_means.append(comparison_mean)
                swap_means.append(swap_mean)

        except FileNotFoundError:
            print(f'Plik {filename} nie został znaleziony.')
            continue

    plt.scatter(Ns, swap_means, marker='o', color=colors[i], label='Średnia liczba przestawień')

plt.show()
