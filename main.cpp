#include <iostream>
#include <fstream>
#include <filesystem>

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

    fileLecture.close();
    fileEcriture.close();

    /** Calcul des tailles des fichiers
     * Il faut fermer le fichier en écriture pour avoir accès à la taille
     */


    auto tailleSource = std::filesystem::file_size(nomFichierSrc);
    auto tailleDestination = std::filesystem::file_size(nomFichierDst);

    std::cout << "Taille fichier origine :  "<< tailleSource << std::endl;
    std::cout << "Taille fichier destination :  " << tailleDestination << std::endl;
    std::cout << tailleSource - tailleDestination <<" octet(s) ont été supprimé." << std::endl;

    return EXIT_SUCCESS;

}