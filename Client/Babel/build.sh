#!/bin/bash

# Créer un répertoire build s'il n'existe pas
if [ ! -d "build" ]; then
    mkdir build
fi

# Se déplacer dans le répertoire build
cd build || exit

# Exécuter CMake dans le répertoire build
cmake ..

# Lancer la construction
cmake --build .

# Revenir au répertoire d'origine
cd ..
