#include <iostream>
#include <fstream>

int main() {

    std::string nomFichierSrc;
    std::string nomFichierDst;
    char byte = 0;
    unsigned long nombreLu = 0, nombreEcrit = 0;

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
        nombreLu++;
        if(byte != 0x0D) {  // different Carrier Return
            fileEcriture.put(byte);
            nombreEcrit++;
        }
    }

    std::cout << "Taille fichier origine :  "<< nombreLu << std::endl;
    std::cout << "Taille fichier destination :  "<< nombreEcrit << std::endl;
    std::cout << nombreLu - nombreEcrit <<" octet(s) ont été supprimé." << std::endl;
    fileLecture.close();
    fileEcriture.close();

    return EXIT_SUCCESS;

}