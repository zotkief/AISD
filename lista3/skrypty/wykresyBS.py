import numpy as np
import matplotlib.pyplot as plt
from matplotlib.backends.backend_pdf import PdfPages
import statistics
import math

file_names=[]
names=[]

algo=['dec','ran','inc']
algoN=['ciągi malejące, ilość części=','ciągi losowe, ilość części=','ciągi rosnące ilość części=']

part=['0','1','2','3']
partN=['3','5','7','9']

side=['0','1','2']
sideN=[', wartość blisko początku',', wartość blisko środka', ', wartość blisko końca']


for i in range(0,3):
    for j in range(0,4):
        for k in range(0,3):
            filename = f'{algo[i]}{part[j]}{side[k]}.txt'
            filename='../wyniki2/'+filename
            label = f'{algoN[i]}{partN[j]}{sideN[k]}'
            file_names.append(filename)
            names.append(label)


with PdfPages('wykresy.pdf') as pdf:
    for i in range(0,36):
        with open(file_names[i], 'r') as f:
            swapM=[]
            timeM=[]

            plt.tight_layout()
            for k in range(0,50):
                swap=[]
                time=[]
                for j in range(0,5):
                    line=f.readline()
                    parts = line.strip().split()
                    swap.append(int(parts[0]))
                    time.append(int(parts[1]))
                swapM.append(statistics.mean(swap))
                timeM.append(statistics.mean(time))
            
            plt.figure(figsize=(10, 4))
                # Wykres średniej liczby porównań
            plt.xlabel('Rozmiar N')
            plt.ylabel('przestawienia')
            plt.title(names[i])
            plt.grid(True)

            plt.scatter(x=range(1000,50001,1000),y=timeM,marker='o', label='przestawienia',s=10)
            plt.legend()

            pdf.savefig()

            plt.figure(figsize=(10, 4))
                # Wykres średniej liczby porównań
            plt.xlabel('Rozmiar N')
            plt.ylabel('porównania')
            plt.title(names[i])
            plt.grid(True)

            plt.scatter(x=range(1000,50001,1000),y=swapM,marker='o', label='porównania',s=10)
            plt.legend()


            pdf.savefig()
