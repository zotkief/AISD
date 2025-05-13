zotkief@zotkief-Latitude-7490:~/gitHub/AISD/lista3/wysłanie/zadanie3$ echo #Paweł Rzatkiewicz;

zotkief@zotkief-Latitude-7490:~/gitHub/AISD/lista3/wysłanie/zadanie3$ svn export https://repo.cs.pwr.edu.pl/279723-dir/mw1/lista3/zadanie3/
cd zadanie3


zotkief@zotkief-Latitude-7490:~/gitHub/AISD/lista3/wysłanie/zadanie3$ g++ decreaseGen.cpp -o decreaseGen; g++ increaseGen.cpp -o increaseGen; g++ randomGen.cpp -o randomGen
zotkief@zotkief-Latitude-7490:~/gitHub/AISD/lista3/wysłanie/zadanie3$ g++ select.cpp -o select
zotkief@zotkief-Latitude-7490:~/gitHub/AISD/lista3/wysłanie/zadanie3$ echo #przykład wywołania

zotkief@zotkief-Latitude-7490:~/gitHub/AISD/lista3/wysłanie/zadanie3$ ./randomGen 25 | ./select 10 9
tablica wyjściowa
17 24 40 05 14 39 16 43 13 10 10 42 00 34 25 41 19 32 16 21 46 17 00 41 08 
17 24 40 05 14 39 16 43 13 10 10 42 00 34 25 41 19 32 16 21 46 17 00 41 08 
17 25 17 
25 17 
08 05 14 16 13 10 10 00 16 00 
10 00 
05 14 16 13 10 10 00 16 08 
14 10 16 16 13 
16 16 
wynik:
statystyka pozycyjna:16
stan kocowy:
00 05 08 00 10 13 10 14 16 16 17 42 43 34 25 41 19 32 40 21 46 17 39 41 24 
początkowy stan tablicy:
17 24 40 05 14 39 16 43 13 10 10 42 00 34 25 41 19 32 16 21 46 17 00 41 08 
posortowana:
00 00 05 08 10 10 13 14 16 16 17 17 19 21 24 25 32 34 39 40 41 41 42 43 46 
175 602


zotkief@zotkief-Latitude-7490:~/gitHub/AISD/lista3/wysłanie/zadanie3$ echo #W przypadku ilości elementów w grupach równej 3 ilośc porównań nie zmieniła się znacznie, ale wzrosła ilość przestawień, wynikać może to z faktu że wybór pivota jest dłuższy, przez większą ilość podciągów. Natomiast w przypadku dzielenia ciągów ma części 7 i 9 elementowe zwiększona ilość przestawień wynika głównie z większej większej złożoności przy wyznaczaniu mediany małych zbiorów.

zotkief@zotkief-Latitude-7490:~/gitHub/AISD/lista3/wysłanie/zadanie3$ echo #ogólnie można wywnioskować, że przy na tyle małych danych wielkość podciągów nie wpływa znacznie na złożoność.

zotkief@zotkief-Latitude-7490:~/gitHub/AISD/lista3/wysłanie/zadanie3$ tmux capture-pane -p -S'-' -E'-' -J > sprawozdanie.md


































