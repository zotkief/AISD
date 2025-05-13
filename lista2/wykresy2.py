import numpy as np
import matplotlib.pyplot as plt
from matplotlib.backends.backend_pdf import PdfPages

# Zakres wartości N
start_N = 3000
end_N = 50000
step = 1000

# Listy do przechowywania wyników
sorts = ["qui","dua"]
sortsl = ["quicksort","dual pivot qs"]
colors = ['r','b','g']
randoms = ["ran","dec","inc"]
randomsl = ["ciąg losowy","ciąg malejący","ciąg rosnący"]
K = ["1","10","100"]

types=['c(n)','s(n)','c(n)/n','s(n)/n']


with PdfPages('wykresy.pdf') as pdf:
    for t in range(4):
        for k in range(3):
            for j in range(3):
                # Tworzenie wykresów
                plt.figure(figsize=(10, 4))
                # Wykres średniej liczby porównań
                plt.xlabel('Rozmiar N')
                plt.ylabel(types[t])
                plt.title('k='+K[k]+', '+randomsl[j]+', '+types[t])
                plt.grid(True)

                plt.tight_layout()
                for i in range(2):
                    comparison_means = []
                    swap_means = []
                    Ns = []

                    for N in range(start_N, end_N + step, step):
                        filename = f'wyniki/{randoms[j]}{sorts[i]}{N}x{K[k]}.txt'



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
                                if t<2:
                                    comparison_means.append(comparison_mean)
                                    swap_means.append(swap_mean)
                                else:
                                    comparison_means.append(comparison_mean/N)
                                    swap_means.append(swap_mean/N)

                        except FileNotFoundError:
                            print(f'Plik {filename} nie został znaleziony.')
                            continue
                    
                    if t%2==0:
                        plt.scatter(Ns, comparison_means, marker='o', color=colors[i], label=sortsl[i],s=10)
                    else:
                        plt.scatter(Ns, swap_means, marker='o', color=colors[i], label=sortsl[i],s=10)
                plt.legend()
                pdf.savefig()
