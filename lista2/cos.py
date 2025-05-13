import os
import numpy as np
import matplotlib.pyplot as plt
import math

# Funkcja do przetwarzania pliku
def process_file(file_name, N):
    with open(file_name, 'r') as file:
        # Zakłada, że w pliku znajduje się tylko jedna liczba
        value = float(file.read().strip())
    return value / (N * math.log2(N))

# Lista do przechowywania przetworzonych wyników
x_values = []
y_values = []

# Iteracja przez N od 1 do 50
for N in range(2, 51):
    file_name = f"cos{N}.txt"
    
    if os.path.exists(file_name):
        result = process_file(file_name, N)
        x_values.append(N)
        y_values.append(result/1000)
        if N==50:
            plt.axhline(y=result/1000, color='red', linestyle='--', linewidth=2)
            plt.text(x=0.1, y=result/1000, s='y = '+str(round(result/1000,3)), color='red', va='bottom', ha='left')

# Tworzenie wykresu
plt.plot(x_values, y_values, marker='o')
plt.title('wyznaczenie wartości współczynnika przy n*log(n)')
plt.xlabel('N')
plt.ylabel('Wartość współczynnika')
plt.grid(True)
plt.show()
