import multiprocessing
import subprocess

def execute_command(command):
    try:
        result = subprocess.run(command, shell=True, check=True)
        print(f"Executed: {command}")
    except subprocess.CalledProcessError as e:
        print(f"Error executing: {command}")
        print(e)

def main():
    # Otwórz plik i czytaj jego zawartość
    with open('cztery.txt', 'r') as file:
        commands = [line.strip() for line in file if line.strip()]

    # Określ liczbę dostępnych procesorów
    num_cpus = multiprocessing.cpu_count()

    # Utwórz pulę procesów
    with multiprocessing.Pool(processes=num_cpus) as pool:
        # Mapuj funkcję execute_command na każdą komendę z pliku
        pool.map(execute_command, commands)

if __name__ == "__main__":
    main()
