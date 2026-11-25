#pragma once
#include <iostream>
#include <string>

class RolCerut {
private:
    std::string titlu;
    std::string abilitate;
    int nivelMinim;
    int oreNecesare;

public:
    RolCerut(std::string titlu, std::string abilitate, int nivelMinim, int oreNecesare);

    const std::string& getTitlu() const;
    const std::string& getAbilitate() const;
    int getNivelMinim() const;
    int getOreNecesare() const;

    friend std::ostream& operator<<(std::ostream& out, const RolCerut& rol);
};