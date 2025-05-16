#include "Bioinformatics.h"
#include <algorithm>
#include <cctype>
#include <unordered_map>

std::string Bioinformatics::identificarCadena(const std::string& secuencia) {
    bool tieneT = false, tieneU = false;
    bool soloADN = true, soloARN = true, soloProteina = true;

    for (char c : secuencia) {
        char uc = std::toupper(c);
        if (uc == 'T') tieneT = true;
        if (uc == 'U') tieneU = true;

        if (uc != 'A' && uc != 'C' && uc != 'G' && uc != 'T') soloADN = false;
        if (uc != 'A' && uc != 'C' && uc != 'G' && uc != 'U') soloARN = false;
        if (!std::isalpha(uc) || uc == 'B' || uc == 'J' || uc == 'O' || uc == 'U' || uc == 'X' || uc == 'Z')
            soloProteina = false;
    }

    if (soloADN && tieneT) return "ADN";
    if (soloARN && tieneU) return "ARN";
    if (soloProteina) return "Proteína";
    return "Desconocido";
}

std::string Bioinformatics::transcribirADNaARN(const std::string& adn) {
    std::string arn = adn;
    std::transform(arn.begin(), arn.end(), arn.begin(),
                   [](char c){ return (std::toupper(c) == 'T') ? 'U' : c; });
    return arn;
}

std::vector<std::string> Bioinformatics::obtenerAminoacidos(const std::string& proteina) {
    static const std::unordered_map<char,std::string> tablaAA = {
        {'A',"Alanina"}, {'C',"Cisteina"}, {'D',"Acido aspartico"},
        {'E',"Acido glutamico"}, {'F',"Fenilalanina"}, {'G',"Glicina"},
        {'H',"Histidina"}, {'I',"Isoleucina"}, {'K',"Lisina"},
        {'L',"Leucina"}, {'M',"Metionina"}, {'N',"Asparagina"},
        {'P',"Prolina"}, {'Q',"Glutamina"}, {'R',"Arginina"},
        {'S',"Serina"}, {'T',"Treonina"}, {'V',"Valina"},
        {'W',"Triptofano"}, {'Y',"Tirosina"}
    };

    std::vector<std::string> resultado;
    for(char c : proteina){
        char uc = std::toupper(c);
        auto it = tablaAA.find(uc);
        resultado.push_back(it != tablaAA.end() ? it->second : "Desconocido");
    }
    return resultado;
}
