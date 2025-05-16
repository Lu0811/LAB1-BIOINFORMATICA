#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include "Bioinformatics.h"

void procesarFASTA(const std::string& filename, Bioinformatics& bio, std::ostream& out) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error al abrir el archivo: " << filename << "\n";
        return;
    }

    std::string linea, id, secuencia;
    while (std::getline(file, linea)) {
        if (linea.empty()) continue;
        if (linea[0] == '>') {
            if (!id.empty()) {
                out << "ID: " << id << "\n";
                std::string tipo = bio.identificarCadena(secuencia);
                out << "Tipo detectado: " << tipo << "\n";
                if (tipo == "ADN") {
                    std::string arn = bio.transcribirADNaARN(secuencia);
                    out << "Transcripcion a ARN: " << arn.substr(0, 50) << "...\n";
                } else if (tipo == "Proteína") {
                    auto aa = bio.obtenerAminoacidos(secuencia);
                    for (size_t i = 0; i < aa.size(); ++i) {
                        out << static_cast<char>(toupper(secuencia[i])) << ": " << aa[i] << "\n";
                    }
                }
                out << "--------------------------------------\n";
                secuencia.clear();
            }
            id = linea.substr(1);
        } else {
            linea.erase(std::remove_if(linea.begin(), linea.end(), ::isspace), linea.end());
            secuencia += linea;
        }
    }
    if (!id.empty()) {
        out << "ID: " << id << "\n";
        std::string tipo = bio.identificarCadena(secuencia);
        out << "Tipo detectado: " << tipo << "\n";
        if (tipo == "ADN") {
            std::string arn = bio.transcribirADNaARN(secuencia);
            out << "Transcripcion a ARN: " << arn.substr(0, 50) << "...\n";
        } else if (tipo == "Proteína") {
            auto aa = bio.obtenerAminoacidos(secuencia);
            for (size_t i = 0; i < aa.size(); ++i) {
                out << static_cast<char>(toupper(secuencia[i])) << ": " << aa[i] << "\n";
            }
        }
        out << "--------------------------------------\n";
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Uso: " << argv[0] << " archivo.fasta [archivo_salida.txt]\n";
        return 1;
    }

    Bioinformatics bio;

    if (argc == 3) {
        std::ofstream archivoSalida(argv[2]);
        if (!archivoSalida.is_open()) {
            std::cerr << "Error al crear archivo salida: " << argv[2] << "\n";
            return 1;
        }
        procesarFASTA(argv[1], bio, archivoSalida);
        std::cout << "Resultados guardados en " << argv[2] << "\n";
    } else {
        procesarFASTA(argv[1], bio, std::cout);
    }

    return 0;
}
