#pragma once
#include <string>
#include <vector>

class Bioinformatics {
public:
    std::string identificarCadena(const std::string& secuencia);
    std::string transcribirADNaARN(const std::string& adn);
    std::vector<std::string> obtenerAminoacidos(const std::string& proteina);
};
