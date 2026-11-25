#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "RolCerut.hpp"

class Proiect {
private:
    std::string nume;
    int buget;
    int durataSaptamani;
    std::vector<RolCerut> roluri;

public:
    Proiect(std::string nume, int buget, int durataSaptamani);

    // Regula celor 3
    Proiect(const Proiect& alt);
    Proiect& operator=(const Proiect& alt);
    ~Proiect();

    void adaugaRol(const RolCerut& rol);
    void setBuget(int bugetNou);

    const std::string& getNume() const;
    int getBuget() const;
    const std::vector<RolCerut>& getRoluri() const;
    int calculeazaOreTotale() const;

    friend std::ostream& operator<<(std::ostream& out, const Proiect& p);
};