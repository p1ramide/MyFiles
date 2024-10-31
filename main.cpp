#include <iostream>
#include <clocale>
#include <fstream>
#include <string>

using std::string;

void creaFile();
void pulisci();
void leggiFile();

int main(void) {
    std::setlocale(LC_ALL, "it_IT.utf8");

    creaFile();
    leggiFile();

    return 0;
}

void pulisci() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void creaFile() {
    string nomeFile;
    string contenutoFile;
    
    pulisci();

    std::cout << "\n Inserire il nome del file da creare: ";
    std::getline(std::cin, nomeFile);

    nomeFile += ".txt";
    std::ofstream file(nomeFile, std::ios::app);

    std::cout << "\n Inserire contenuto del file: ";
    std::getline(std::cin, contenutoFile);

    file.is_open() ? file << contenutoFile, std::cout << "\n Scrittura del file eseguita con successo." : std::cout << "\n Errore nell'apertura del file.";
    file.close();
}

void leggiFile() {
    string nomeFile;
    string linea;
    string contenutoFile;

    pulisci();

    std::cout << "\n Inserire il nome del file da leggere: ";
    std::getline(std::cin, nomeFile);

    nomeFile += ".txt";
    std::ifstream file(nomeFile);

    if (file.is_open()) {
        std::cout << "\n Il contenuto del file è: ";

        while (std::getline(file, linea)) {
            std::cout << "\n " << linea << "\n";
        }
    } else {
        std::cout << "\n Errore nella lettura del file."
    }

    file.close();
}
