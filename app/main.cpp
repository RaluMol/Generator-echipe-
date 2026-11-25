#include <iostream>
#include <optional>
#include <string>
#include <vector>

#include "MotorMatching.hpp"
#include "Persoana.hpp"
#include "Proiect.hpp"
#include "RolCerut.hpp"

int main() {
    std::vector<Persoana> candidati = {
        Persoana("Ana Popescu", 15, "C++", 9, "Mihai Ionescu"),
        Persoana("Mihai Ionescu", 12, "C++", 8, "Ana Popescu"),
        Persoana("Elena Radu", 10, "Design", 8),
        Persoana("Andrei Stan", 14, "Management", 9),
        Persoana("Vlad Marin", 12, "Design", 7)
    };

    MotorMatching motor(candidati);
    std::optional<Proiect> proiectCurent;

    while (true) {
        std::cout << "\n=== ALCHIMIE DE ECHIPE ===\n"
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