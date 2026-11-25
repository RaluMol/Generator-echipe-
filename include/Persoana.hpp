#pragma once
#include <iostream>
#include <string>
#include "RolCerut.hpp"

class Persoana {
private:
    std::string nume;
    int orePeSaptamana;
    std::string abilitate;
    int nivel;
    std::string incompatibilCu;

public:
    Persoana(std::string nume, int orePeSaptamana, std::string abilitate,
             int nivel, std::string incompatibilCu = "");

    const std::string& getNume() const;
    const std::string& getAbilitate() const;

    bool poateOcupa(const RolCerut& rol) const;
    bool esteCompatibilCu(const Persoana& alta) const;

    friend std::ostream& operator<<(std::ostream& out, const Persoana& p);
};