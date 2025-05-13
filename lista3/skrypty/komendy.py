import subprocess

def execute_command(command):
    try:
        # Wykonanie komendy bez multiprocessing
        result = subprocess.run(command, shell=True, check=True)
        print(f"Executed: {command}")
    except subprocess.CalledProcessError as e:
        print(f"Error executing: {command}")
        print(e)

def main():
    # Otwórz plik komendy.txt i czytaj jej zawartość
    with open('comm_3.txt', 'r') as file:
        commands = [line.strip() for line in file if line.strip()]

    # Wykonaj każdą komendę w tej samej kolejności
    for command in commands:
        execute_command(command)

if __name__ == "__main__":
    main()
