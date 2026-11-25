#include "MotorMatching.hpp"
#include <utility>

MotorMatching::MotorMatching(std::vector<Persoana> candidati)
    : candidati(std::move(candidati)) {}

std::vector<std::pair<std::string, std::string>>
MotorMatching::formeazaEchipa(const Proiect& proiect) const {
    std::vector<std::pair<std::string, std::string>> alocari;
    std::vector<Persoana> alesi;

    for (const auto& rol : proiect.getRoluri()) {
        for (const auto& candidat : candidati) {
            if (!candidat.poateOcupa(rol)) {
                continue;
            }

            bool valid = true;
            for (const auto& membru : alesi) {
                if (membru.getNume() == candidat.getNume() ||
                    !membru.esteCompatibilCu(candidat)) {
                    valid = false;
                    break;
                }
            }

            if (valid) {
                alesi.push_back(candidat);
                alocari.emplace_back(rol.getTitlu(), candidat.getNume());
                break;
            }
        }
    }
    return alocari;
}

std::ostream& operator<<(std::ostream& out, const MotorMatching& motor) {
    out << "Candidati disponibili (" << motor.candidati.size() << "):\n";
    for (const auto& c : motor.candidati) {
        out << "  * " << c << '\n';
    }
    return out;
}