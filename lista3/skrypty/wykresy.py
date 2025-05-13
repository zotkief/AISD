import numpy as np
import matplotlib.pyplot as plt
from matplotlib.backends.backend_pdf import PdfPages
import statistics
import math

file_names=[]
names=[]

algo=['dec','ran','inc']
algoN=['ciągi malejące, ','ciągi losowe, ','ciągi rosnące, ']

part=['mqs','mds']
partN=['quicksort+select','dual pivot+select']


for i in range(0,3):
    for j in range(0,2):
        filename = f'{algo[i]}{part[j]}.txt'
        filename='../wyniki4/'+filename
        label = f'{algoN[i]}{partN[j]}'
        file_names.append(filename)
        names.append(label)


with PdfPages('wykresy.pdf') as pdf:
    for i in range(0,6):
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
                swap=statistics.mean(swap)
                time=statistics.mean(time)
                swap=swap/((k+1)*1000*math.log((k+1)*1000))
                time=time/((k+1)*1000*math.log((k+1)*1000))
                swapM.append(swap)
                timeM.append(time)
            
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
