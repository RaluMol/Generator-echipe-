#pragma once
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include "Persoana.hpp"
#include "Proiect.hpp"

class MotorMatching {
private:
    std::vector<Persoana> candidati;

public:
    explicit MotorMatching(std::vector<Persoana> candidati);

    std::vector<std::pair<std::string, std::string>> formeazaEchipa(const Proiect& proiect) const;

    friend std::ostream& operator<<(std::ostream& out, const MotorMatching& motor);
};