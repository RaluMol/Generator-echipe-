#include "Persoana.hpp"
#include <utility>

Persoana::Persoana(std::string nume, int orePeSaptamana, std::string abilitate,
                   int nivel, std::string incompatibilCu)
    : nume(std::move(nume)),
      orePeSaptamana(orePeSaptamana),
      abilitate(std::move(abilitate)),
      nivel(nivel),
      incompatibilCu(std::move(incompatibilCu)) {}

const std::string& Persoana::getNume() const { return nume; }
const std::string& Persoana::getAbilitate() const { return abilitate; }

bool Persoana::poateOcupa(const RolCerut& rol) const {
    return abilitate == rol.getAbilitate() &&
           orePeSaptamana >= rol.getOreNecesare();
}

bool Persoana::esteCompatibilCu(const Persoana& alta) const {
    return incompatibilCu != alta.nume && alta.incompatibilCu != nume;
}

std::ostream& operator<<(std::ostream& out, const Persoana& p) {
    out << p.nume << " (" << p.abilitate << ": " << p.nivel
        << "/10, " << p.orePeSaptamana << " h/sapt)";
    if (!p.incompatibilCu.empty()) {
        out << " [incompatibil cu: " << p.incompatibilCu << "]";
    }
    return out;
}