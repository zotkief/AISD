zotkief@zotkief-Latitude-7490:~/gitHub/AISD/lista3/wysłanie/zadanie1$ echo #Paweł Rzatkiewicz;

zotkief@zotkief-Latitude-7490:~/gitHub/AISD/lista3/wysłanie/zadanie1$ svn export https://repo.cs.pwr.edu.pl/279723-dir/mw1/lista3/zadanie1/
cd zadanie1

zotkief@zotkief-Latitude-7490:~/gitHub/AISD/lista3/wysłanie/zadanie1$ g++ decreaseGen.cpp -o decreaseGen; g++ increaseGen.cpp -o increaseGen; g++ randomGen.cpp -o randomGen
zotkief@zotkief-Latitude-7490:~/gitHub/AISD/lista3/wysłanie/zadanie1$ g++ randomSelect.cpp -o randomSelect; g++ select.cpp -o select
zotkief@zotkief-Latitude-7490:~/gitHub/AISD/lista3/wysłanie/zadanie1$ ./randomGen 8 | ./randomSelect 5
tablica wyjściowa
13 03 02 00 12 04 02 04 
13 03 02 00 12 04 02 04 
03 02 04 12 04 02 13 
03 02 04 04 02 
04 
wynik:
statystyka pozycyjna:4
stan kocowy:
00 03 02 02 04 04 12 13 
początkowy stan tablicy:
13 03 02 00 12 04 02 04 
posortowana:
00 02 02 03 04 04 12 13 
17 42
zotkief@zotkief-Latitude-7490:~/gitHub/AISD/lista3/wysłanie/zadanie1$ ./randomGen 22 | ./randomSelect 5
tablica wyjściowa
41 16 15 36 15 12 30 10 15 04 11 15 22 26 05 32 00 00 28 02 21 11 
41 16 15 36 15 12 30 10 15 04 11 15 22 26 05 32 00 00 28 02 21 11 
10 04 05 00 00 02 
10 
wynik:
statystyka pozycyjna:10
stan kocowy:
04 02 00 00 05 10 11 41 15 16 11 15 22 26 15 32 36 15 28 12 21 30 
początkowy stan tablicy:
41 16 15 36 15 12 30 10 15 04 11 15 22 26 05 32 00 00 28 02 21 11 
posortowana:
00 00 02 04 05 10 11 11 12 15 15 15 15 16 21 22 26 28 30 32 36 41 
26 42
zotkief@zotkief-Latitude-7490:~/gitHub/AISD/lista3/wysłanie/zadanie1$ ./decreaseGen 8 | ./randomSelect 5
tablica wyjściowa
14 09 08 08 08 08 06 06 
14 09 08 08 08 08 06 06 
14 08 08 09 08 
08 08 09 14 
14 09 08 
08 
wynik:
statystyka pozycyjna:8
stan kocowy:
06 06 08 08 08 08 09 14 
początkowy stan tablicy:
14 09 08 08 08 08 06 06 
posortowana:
06 06 08 08 08 08 09 14 
16 33
zotkief@zotkief-Latitude-7490:~/gitHub/AISD/lista3/wysłanie/zadanie1$ ./decreaseGen 22 | ./randomSelect 5
tablica wyjściowa
42 40 31 26 24 24 19 19 12 12 11 11 11 09 06 05 05 05 05 05 02 00 
42 40 31 26 24 24 19 19 12 12 11 11 11 09 06 05 05 05 05 05 02 00 
00 09 06 05 05 05 05 05 02 
05 09 05 05 05 06 
09 06 05 05 05 
06 05 05 09 
wynik:
statystyka pozycyjna:5
stan kocowy:
00 02 05 05 05 05 09 05 06 11 42 11 11 40 31 26 24 24 19 19 12 12 
początkowy stan tablicy:
42 40 31 26 24 24 19 19 12 12 11 11 11 09 06 05 05 05 05 05 02 00 
posortowana:
00 02 05 05 05 05 05 06 09 11 11 11 12 12 19 19 24 24 26 31 40 42 
41 63
zotkief@zotkief-Latitude-7490:~/gitHub/AISD/lista3/wysłanie/zadanie1$ ./increaseGen 8 | ./randomSelect 5
tablica wyjściowa
03 05 06 09 11 11 11 15 
03 05 06 09 11 11 11 15 
11 11 11 15 
15 11 11 
wynik:
statystyka pozycyjna:11
stan kocowy:
03 05 06 09 11 11 11 15 
początkowy stan tablicy:
03 05 06 09 11 11 11 15 
posortowana:
03 05 06 09 11 11 11 15 
12 27
zotkief@zotkief-Latitude-7490:~/gitHub/AISD/lista3/wysłanie/zadanie1$ ./increaseGen 22 | ./randomSelect 5
tablica wyjściowa
00 01 01 06 06 08 09 13 13 13 13 14 14 17 18 23 24 24 24 31 32 32 
00 01 01 06 06 08 09 13 13 13 13 14 14 17 18 23 24 24 24 31 32 32 
00 01 01 06 06 08 09 
06 08 09 
wynik:
statystyka pozycyjna:8
stan kocowy:
00 01 01 06 06 08 09 13 13 13 32 14 14 17 18 23 24 24 24 31 32 13 
początkowy stan tablicy:
00 01 01 06 06 08 09 13 13 13 13 14 14 17 18 23 24 24 24 31 32 32 
posortowana:
00 01 01 06 06 08 09 13 13 13 13 14 14 17 18 23 24 24 24 31 32 32 
29 51
zotkief@zotkief-Latitude-7490:~/gitHub/AISD/lista3/wysłanie/zadanie1$ ./randomGen 8 | ./select 5
tablica wyjściowa
09 05 10 03 11 11 00 15 
09 05 10 03 11 11 00 15 
09 11 
11 11 10 15 
wynik:
statystyka pozycyjna:10
stan kocowy:
05 03 00 09 10 11 15 11 
początkowy stan tablicy:
09 05 10 03 11 11 00 15 
posortowana:
00 03 05 09 10 11 11 15 
24 103
zotkief@zotkief-Latitude-7490:~/gitHub/AISD/lista3/wysłanie/zadanie1$ ./randomGen 22 | ./select 5 
tablica wyjściowa
39 27 36 25 00 19 00 05 37 12 20 20 37 32 30 11 08 09 17 21 18 26 
39 27 36 25 00 19 00 05 37 12 20 20 37 32 30 11 08 09 17 21 18 26 
27 12 30 11 26 
25 00 19 00 05 12 20 20 11 08 09 17 21 18 
05 12 18 
00 00 05 11 08 09 
05 09 
11 08 09 
wynik:
statystyka pozycyjna:9
stan kocowy:
00 00 05 08 09 11 12 20 25 19 18 17 21 20 26 37 36 39 27 37 32 30 
początkowy stan tablicy:
39 27 36 25 00 19 00 05 37 12 20 20 37 32 30 11 08 09 17 21 18 26 
posortowana:
00 00 05 08 09 11 12 17 18 19 20 20 21 25 26 27 30 32 36 37 37 39 
119 434
zotkief@zotkief-Latitude-7490:~/gitHub/AISD/lista3/wysłanie/zadanie1$ ./decreaseGen 8 | ./select 5
tablica wyjściowa
13 12 11 09 04 03 03 02 
13 12 11 09 04 03 03 02 
11 03 
11 09 04 13 03 12 
09 12 
wynik:
statystyka pozycyjna:9
stan kocowy:
02 03 04 03 09 13 12 11 
początkowy stan tablicy:
13 12 11 09 04 03 03 02 
posortowana:
02 03 03 04 09 11 12 13 
37 125
zotkief@zotkief-Latitude-7490:~/gitHub/AISD/lista3/wysłanie/zadanie1$ ./decreaseGen 22 | ./select 5
tablica wyjściowa
tablica wyjściowa
42 41 40 38 34 33 31 31 30 29 29 29 28 25 23 23 14 14 14 13 13 08 
42 41 40 38 34 33 31 31 30 29 29 29 28 25 23 23 14 14 14 13 13 08 
40 31 28 14 13 
08 25 23 23 14 14 14 13 13 
23 14 
25 14 14 23 23 
14 14 
wynik:
statystyka pozycyjna:14
stan kocowy:
08 13 13 14 14 14 23 23 25 28 29 29 42 41 40 38 34 33 31 31 30 29 
początkowy stan tablicy:
42 41 40 38 34 33 31 31 30 29 29 29 28 25 23 23 14 14 14 13 13 08 
posortowana:
08 13 13 14 14 14 23 23 25 28 29 29 29 30 31 31 33 34 38 40 41 42 
113 347
zotkief@zotkief-Latitude-7490:~/gitHub/AISD/lista3/wysłanie/zadanie1$ ./increaseGen 8 | ./select 5
tablica wyjściowa
04 04 04 05 06 06 09 13 
04 04 04 05 06 06 09 13 
04 09 
04 04 05 06 06 09 13 
05 13 
06 06 09 13 
06 06 
wynik:
statystyka pozycyjna:6
stan kocowy:
04 04 04 05 06 06 09 13 
początkowy stan tablicy:
04 04 04 05 06 06 09 13 
posortowana:
04 04 04 05 06 06 09 13 
36 171
zotkief@zotkief-Latitude-7490:~/gitHub/AISD/lista3/wysłanie/zadanie1$ ./increaseGen 22 | ./select 5
tablica wyjściowa
01 01 01 01 01 02 02 04 07 09 11 11 15 17 17 17 21 23 24 25 29 30 
01 01 01 01 01 02 02 04 07 09 11 11 15 17 17 17 21 23 24 25 29 30 
01 04 15 23 30 
01 01 01 01 01 02 02 04 07 09 11 11 
01 04 11 
01 01 01 01 01 02 02 
01 02 
01 01 01 01 02 02 
01 02 
01 01 01 02 02 
01 01 02 02 
01 01 
wynik:
statystyka pozycyjna:1
stan kocowy:
01 01 01 01 01 02 02 04 07 09 11 11 15 17 17 17 21 23 24 25 29 30 
początkowy stan tablicy:
01 01 01 01 01 02 02 04 07 09 11 11 15 17 17 17 21 23 24 25 29 30 
posortowana:
01 01 01 01 01 02 02 04 07 09 11 11 15 17 17 17 21 23 24 25 29 30 
110 527
zotkief@zotkief-Latitude-7490:~/gitHub/AISD/lista3/wysłanie/zadanie1$ tmux capture-pane -p -S'-' -E'-' -J > sprawozdanie.md

