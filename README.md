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
````

### 2. Instalar dependencias (si es necesario)

Si estás trabajando en un sistema que no tiene CMake y/o Google Test instalados, puedes instalarlo de la siguiente manera:

* **Para Linux (Ubuntu/Debian):**

```bash
sudo apt-get update
sudo apt-get install cmake g++
```

* **Para macOS (con Homebrew):**

```bash
brew install cmake
brew install googletest
```

* **Para Windows:**

  * Descarga e instala CMake desde [aquí](https://cmake.org/download/).
  * Si utilizas Visual Studio, Google Test debería estar integrado.

### 3. Compilar el proyecto

1. Crea una carpeta para la construcción dentro del proyecto:

   ```bash
   mkdir build
   cd build
   ```

2. Ejecuta CMake desde la carpeta `build` para generar los archivos de construcción:

   ```bash
   cmake ..
   ```

3. Ahora compila el proyecto con el siguiente comando:

   ```bash
   cmake --build .
   ```

Esto compilará el proyecto y generará el ejecutable `mainprog.exe` (o `mainprog` en sistemas Unix) en la carpeta `build`.

### 4. Ejecutar el programa

Una vez que el proyecto esté compilado, puedes ejecutar el programa.

1. **Ejecutar el programa con un archivo FASTA**:

   Usa el siguiente comando para ejecutar el programa y proporcionar un archivo FASTA como entrada:

   ```bash
   ./mainprog ../data/archivo.fasta
   ```

   Aquí, `archivo.fasta` es el archivo que contiene las secuencias biológicas en formato FASTA que deseas analizar. Asegúrate de que el archivo esté en la carpeta `data`.

2. **Ejecutar el programa y guardar los resultados en un archivo de texto**:

   Si deseas guardar los resultados en un archivo, puedes ejecutar el programa de la siguiente manera:

   ```bash
   ./mainprog ../data/archivo.fasta resultados.txt
   ```

   Esto guardará la salida del programa en el archivo `resultados.txt` en la carpeta `build`.

### 5. Ejecutar pruebas unitarias

Si deseas ejecutar las pruebas unitarias para verificar que todo funcione correctamente, puedes hacerlo con los siguientes comandos:

1. **Compilar los tests**:

   ```bash
   cmake --build . --target testprog
   ```

2. **Ejecutar las pruebas unitarias**:

   ```bash
   ctest --output-on-failure
   ```

Esto ejecutará todos los tests configurados para verificar que las funciones de detección de tipo de secuencia, transcripción y traducción estén funcionando correctamente.

---

