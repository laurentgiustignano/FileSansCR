#include <iostream>
#include <fstream>

int main() {

    std::string nomFichierSrc;
    std::string nomFichierDst;
    char byte = 0;

    std::cout << "Donnez le nom du fichier source : ";
    std::cin >> nomFichierSrc;

    std::cout << "Donnez le nom du fichier destination : ";
    std::cin >> nomFichierDst;

    std::ifstream fileLecture(nomFichierSrc);
    if (!fileLecture.is_open()) {
        std::cerr << "Ouverture en lecture impossible de - '" << nomFichierSrc << "'" << std::endl;
        throw ; //EXIT_FAILURE;
    }

    std::ofstream  fileEcriture(nomFichierDst);
    if (!fileEcriture.is_open()) {
        std::cerr << "Ouverture en ecriture impossible de - '" << nomFichierDst << "'" << std::endl;
        throw ; //EXIT_FAILURE;
    }

    while (fileLecture.get(byte)) {
        if(byte != 0x0D) {  // different Carrier Return
            fileEcriture.put(byte);
        }
    }

    std::cout << "Fin " << std::endl;
    fileLecture.close();
    fileEcriture.close();

    return EXIT_SUCCESS;

}