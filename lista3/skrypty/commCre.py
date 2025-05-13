import random
# Definicja zbiorów
set1 = ["randomGen", "increaseGen","decreaseGen"]
ns1=["ran","inc","dec"]
set2 = [ "mqs","mds","qs","ds"]
ns2=["mqs","mds","qs","ds"]

numset=[0.1,0.5,0.9]

parts=['3','5','7','9']

# Zakres wartości
for n in range(100, 10001, 100):
    print("echo "+str(n)+"\n")
    print(f"\n")
    for s1 in range(0,3):
        for s2 in range(0,4):
            #result=" ./../algorytmy/"+set2[s2]+" "+str(n)+" 5  "+k+" >> ../wyniki3/"+str(i)+"f.txt"
            result="./../algorytmy/"+set1[s1]+" "+str(n)+" | ./../algorytmy/"+set2[s2]+" >> ../wyniki4/"+ns1[s1]+ns2[s2]+".txt"
            print(result)
