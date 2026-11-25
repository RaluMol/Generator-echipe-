#include "Proiect.hpp"
#include <utility>

Proiect::Proiect(std::string nume, int buget, int durataSaptamani)
    : nume(std::move(nume)), buget(buget), durataSaptamani(durataSaptamani) {}

Proiect::Proiect(const Proiect& alt)
    : nume(alt.nume + " (Copie)"),
      buget(alt.buget),
      durataSaptamani(alt.durataSaptamani),
      roluri(alt.roluri) {}

Proiect& Proiect::operator=(const Proiect& alt) {
    if (this != &alt) {
        nume = alt.nume;
        buget = alt.buget;
        durataSaptamani = alt.durataSaptamani;
        roluri = alt.roluri;
    }
    return *this;
}

Proiect::~Proiect() = default;

void Proiect::adaugaRol(const RolCerut& rol) { roluri.push_back(rol); }
void Proiect::setBuget(int bugetNou) { buget = bugetNou; }

const std::string& Proiect::getNume() const { return nume; }
int Proiect::getBuget() const { return buget; }
const std::vector<RolCerut>& Proiect::getRoluri() const { return roluri; }

int Proiect::calculeazaOreTotale() const {
    int total = 0;
    for (const auto& rol : roluri) {
        total += rol.getOreNecesare();
    }
    return total;
}

std::ostream& operator<<(std::ostream& out, const Proiect& p) {
    out << "Proiect: " << p.nume << " | Buget: " << p.buget
        << " RON | Durata: " << p.durataSaptamani << " sapt | Ore/sapt: "
        << p.calculeazaOreTotale() << "\nRoluri:\n";
    for (const auto& rol : p.roluri) {
        out << "  - " << rol << '\n';
    }
    return out;
}