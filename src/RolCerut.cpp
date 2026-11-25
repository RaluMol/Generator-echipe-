#include "RolCerut.hpp"
#include <utility>

RolCerut::RolCerut(std::string titlu, std::string abilitate, int nivelMinim, int oreNecesare)
    : titlu(std::move(titlu)),
      abilitate(std::move(abilitate)),
      nivelMinim(nivelMinim),
      oreNecesare(oreNecesare) {}

const std::string& RolCerut::getTitlu() const { return titlu; }
const std::string& RolCerut::getAbilitate() const { return abilitate; }
int RolCerut::getNivelMinim() const { return nivelMinim; }
int RolCerut::getOreNecesare() const { return oreNecesare; }

std::ostream& operator<<(std::ostream& out, const RolCerut& rol) {
    out << rol.titlu << " [" << rol.abilitate << " >= " << rol.nivelMinim
        << ", " << rol.oreNecesare << " h/sapt]";
    return out;
}