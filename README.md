# LAB1-Bioinformática

Este es un proyecto de bioinformática diseñado para analizar secuencias biológicas en formato FASTA. El programa permite detectar el tipo de secuencia (ADN, ARN o proteína), realizar la transcripción de ADN a ARN y traducir secuencias de proteínas en sus aminoácidos correspondientes.

## Requisitos previos

1. **C++ (con soporte para C++17 o superior)**:
   - El código está escrito en C++17, por lo que necesitarás tener un compilador que lo soporte.
   - Asegúrate de tener `g++` o `clang++` instalado en tu sistema.

2. **CMake**:
   - CMake es utilizado para gestionar la construcción del proyecto. Asegúrate de tener CMake instalado en tu sistema.
   - [Descargar CMake](https://cmake.org/download/)

3. **Google Test (para pruebas unitarias)**:
   - Google Test es usado para realizar pruebas unitarias. Si deseas ejecutar las pruebas, asegúrate de tener acceso a esta librería.
   - El proyecto incluye la descarga y configuración de Google Test automáticamente durante la construcción con CMake.

## Pasos para ejecutar el proyecto desde cero

### 1. Clonar el repositorio

Si aún no has clonado el repositorio, hazlo usando el siguiente comando:

```bash
git clone https://github.com/tu-usuario/LAB1-Bioinformatica.git
cd LAB1-Bioinformatica
