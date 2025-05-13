#include <iostream>
#include <fstream>
#include <cstdlib>
#include <sstream>

int main() {
    std::ofstream wyniki("wyniki.txt");

    if (!wyniki.is_open()) {
        std::cerr << "Nie można otworzyć pliku wyniki.txt!" << std::endl;
        return 1;
    }

    for (int n = 1; n <= 50; ++n) {
        // Tworzenie komendy do wywołania
        std::stringstream command;
        command << "./../zad1/randomGen 10000 | ./mixSort " << n;

        // Otwieranie procesu i zczytywanie wyjścia
        FILE* pipe = popen(command.str().c_str(), "r");
        if (!pipe) {
            std::cerr << "Błąd podczas wykonywania polecenia!" << std::endl;
            continue;
        }

        int number1, number2;
        // Odczytujemy 2 liczby z wyjścia
        fscanf(pipe, "%d %d", &number1, &number2);

        // Zamykamy pipe
        pclose(pipe);

        // Zapisujemy liczby do pliku
        wyniki <<n<<" "<< number1 << " " << number2 << "\n";
    }

    wyniki.close();
    return 0;
}
