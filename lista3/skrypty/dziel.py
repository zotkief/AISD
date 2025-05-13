def dziel(plik_wejsciowy, prefix_wyjscowy, liczba_linii_na_plik=100):
    with open(plik_wejsciowy, 'r') as plik:
        numer_pliku = 1
        while True:
            linie = [next(plik) for _ in range(liczba_linii_na_plik)]
            if not linie:
                break
            # Zapisz zestaw linii do nowego pliku
            z_numerem_pliku = f"{prefix_wyjscowy}_{numer_pliku}.txt"
            with open(z_numerem_pliku, 'w') as plik_wyjscie:
                plik_wyjscie.writelines(linie)
            numer_pliku += 1

# Przykład użycia:
dziel("komendy.txt", "comm")
