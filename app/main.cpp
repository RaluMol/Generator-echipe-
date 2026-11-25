#include <iostream>
#include <optional>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

#include "MotorMatching.hpp"
#include "Persoana.hpp"
#include "Proiect.hpp"
#include "RolCerut.hpp"

std::vector<Persoana> incarcaCandidati(const std::string& cale) {
    std::vector<Persoana> lista;
    std::ifstream fin(cale);
    if (!fin) {
        fin.open("../" + cale);  // fallback daca se ruleaza din folderul build/
    }
    if (!fin) {
        std::cerr << "Nu s-a putut deschide fisierul: " << cale << '\n';
        return lista;
    }

    std::string linie;
    while (std::getline(fin, linie)) {
        if (linie.empty()) continue;

        std::stringstream ss(linie);
        std::string nume, oreStr, abilitate, nivelStr, incompatibil;

        std::getline(ss, nume, ';');
        std::getline(ss, oreStr, ';');
        std::getline(ss, abilitate, ';');
        std::getline(ss, nivelStr, ';');
        std::getline(ss, incompatibil, ';');

        lista.emplace_back(nume, std::stoi(oreStr), abilitate,
                           std::stoi(nivelStr), incompatibil);
    }
    return lista;
}
int main() {
 

MotorMatching motor(incarcaCandidati("assets/candidati.txt"));
    std::optional<Proiect> proiectCurent;

    while (true) {
        std::cout << "\n=== ECHIPE proiecte ===\n"
                  << "1. Afiseaza candidatii\n"
                  << "2. Creeaza proiect nou\n"
                  << "3. Testeaza scenariu alternativ (Regula celor 3)\n"
                  << "4. Formeaza echipa optima\n"
                  << "0. Iesire\n"
                  << "Alegere: ";

        int optiune = 0;
        if (!(std::cin >> optiune) || optiune == 0) {
            std::cout << "La revedere!\n";
            break;
        }

        if (optiune == 1) {
            std::cout << '\n' << motor;
        } else if (optiune == 2) {
            std::string nume;
            int buget = 0;
            int durata = 0;
            std::cout << "Nume proiect: ";
            std::getline(std::cin >> std::ws, nume);
            std::cout << "Buget (RON): ";
            std::cin >> buget;
            std::cout << "Durata (saptamani): ";
            std::cin >> durata;

            Proiect p(nume, buget, durata);
            p.adaugaRol(RolCerut("Developer C++", "C++", 8, 10));
            p.adaugaRol(RolCerut("UI Designer", "Design", 7, 8));
            p.adaugaRol(RolCerut("Project Manager", "Management", 8, 10));

            proiectCurent.emplace(p);
            std::cout << '\n' << *proiectCurent;
        } else if (optiune == 3) {
            if (!proiectCurent.has_value()) {
                std::cout << "Creeaza mai intai un proiect (optiunea 2).\n";
                continue;
            }
            // Constructor de copiere
            Proiect alternativ = *proiectCurent;
            alternativ.setBuget(proiectCurent->getBuget() + 2000);

            // Operator=
            Proiect copieControl("Temp", 0, 0);
            copieControl = alternativ;

            std::cout << "\nOriginal: " << proiectCurent->getNume()
                      << " (" << proiectCurent->getBuget() << " RON)\n"
                      << "Alternativ: " << copieControl.getNume()
                      << " (" << copieControl.getBuget() << " RON)\n";
        } else if (optiune == 4) {
            if (!proiectCurent.has_value()) {
                std::cout << "Creeaza mai intai un proiect (optiunea 2).\n";
                continue;
            }
            auto echipa = motor.formeazaEchipa(*proiectCurent);
            std::cout << "\nEchipa formata (" << echipa.size() << "/"
                      << proiectCurent->getRoluri().size() << " roluri):\n";
            for (const auto& [rol, persoana] : echipa) {
                std::cout << "  - " << rol << ": " << persoana << '\n';
            }
        }
    }
    return 0;
}