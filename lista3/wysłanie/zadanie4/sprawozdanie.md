zotkief@zotkief-Latitude-7490:~/gitHub/AISD/lista3/wysłanie/zadanie4$ echo #Paweł Rzatkiewicz;

zotkief@zotkief-Latitude-7490:~/gitHub/AISD/lista3/wysłanie/zadanie4$ svn export https://repo.cs.pwr.edu.pl/279723-dir/mw1/lista3/zadanie4/
cd zadanie4

zotkief@zotkief-Latitude-7490:~/gitHub/AISD/lista3/wysłanie/zadanie4$ g++ binaryS.cpp -o bs
zotkief@zotkief-Latitude-7490:~/gitHub/AISD/lista3/wysłanie/zadanie4$ ./bs 25 1
szukane:3
porownanie
2 2 2 3 3 4 5 8 9 9 11 14 15 16 18 23 24 27 27 27 28 28 28 28 28 29 
porownanie
2 2 2 3 3 4 5 8 9 9 11 14 
porownanie
2 2 2 3 3 
porownanie
3 3 
wynik:1
7 15816
zotkief@zotkief-Latitude-7490:~/gitHub/AISD/lista3/wysłanie/zadanie4$ ./bs 25 1
szukane:26
porownanie
0 0 0 3 8 8 9 9 13 15 18 18 21 21 22 25 25 25 26 26 26 26 27 27 27 27 
porownanie
21 22 25 25 25 26 26 26 26 27 27 27 27 
wynik:1
3 9477
zotkief@zotkief-Latitude-7490:~/gitHub/AISD/lista3/wysłanie/zadanie4$ echo #z wykresów móżna wywnioskować złożoność log(n) co zgadza się z wyliczeniami z master theorem

zotkief@zotkief-Latitude-7490:~/gitHub/AISD/lista3/wysłanie/zadanie4$ echo #współczynniki przy log(n) można wyczytać z wykresów zawartych w pliku wykresy.pdf. w przypadku wyszukiwanie wartości będących w tablicy złożoność porównań to ok 2.5*log(n) a w przypadku wartości z poza tablicy dokładna złożoność jest zależna od wielkości tablicy i oscyluje między 2.9*log(n) i 3.1*log(n). Dokładne złożoności w przypadku czasu to ok 70*log(n) - 90*log(n) (wynik w milisekundach).

zotkief@zotkief-Latitude-7490:~/gitHub/AISD/lista3/wysłanie/zadanie4$  tmux capture-pane -p -S'-' -E'-' -J > sprawozdanie.md
















