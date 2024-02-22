@echo off

rem Créer un répertoire build s'il n'existe pas
if not exist build mkdir build

rem Se déplacer dans le répertoire build
cd build

rem Exécuter CMake dans le répertoire build
cmake ..

rem Lancer la construction
cmake --build .

rem Revenir au répertoire d'origine
cd ..