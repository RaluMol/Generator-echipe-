#include <cassert>
#include <vector>

#include "MotorMatching.hpp"
#include "Persoana.hpp"
#include "Proiect.hpp"
#include "RolCerut.hpp"

int main() {
    Proiect p("Test", 5000, 6);
    p.adaugaRol(RolCerut("Dev", "C++", 8, 10));
    p.adaugaRol(RolCerut("Design", "Design", 7, 8));
    assert(p.calculeazaOreTotale() == 18);

    // Test Regula celor 3
    Proiect copie = p;
    copie.setBuget(9000);
    assert(p.getBuget() == 5000);
    assert(copie.getBuget() == 9000);

    // Test incompatibilitate + matching
    std::vector<Persoana> candidati = {
        Persoana("Ana", 15, "C++", 9, "Elena"),
        Persoana("Elena", 10, "Design", 8, "Ana"),
        Persoana("Vlad", 10, "Design", 8)
    };
    MotorMatching motor(candidati);
    auto echipa = motor.formeazaEchipa(p);
    assert(echipa.size() == 2);
    assert(echipa[0].second == "Ana");
    assert(echipa[1].second == "Vlad");

    return 0;
}