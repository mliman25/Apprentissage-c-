#include <iostream>
#include <fstream>
#include <string>

// argc permet de voir le nombre de mot ecrit dans la ligne de commande
// argv permet de stocker les differents mot dans un tableau

int afficherFichier(std::string nom, bool numeroter)
{

    std::ifstream fichier(nom);

    if (!fichier)
    {
        std::cerr << "Le fichier n'as pas pu etre ouvert : " << nom << std::endl;
        return 1;
    }

    if (numeroter)
    {
        int numero = 1;
        std::string ligne;
        while (std::getline(fichier, ligne))
        {
            std::cout << numero << " " << ligne << std::endl;
            numero++;
        }
    }
    else
    {
        std::string ligne;
        while (std::getline(fichier, ligne))
        {
            std::cout << ligne << std::endl;
        }
    }
    return 0;

}




int main(int argc, char *argv[])
{

    if (argc == 1)
    {
        std::cerr << "Usage:./minicat fichier.txt" << std::endl;
        return 1;
    }
    bool numeroter = false;
    int i = 1;
    std::string premier = argv[1];

    if (premier == "-n")
    {
        i = 2;
        if(i >= argc){
            std::cerr << "Erreur veuillez donner le nom du fichier a numeroter " << std::endl;
            return 1;
        }
        numeroter = true;
    }

    int detectionErreur = 0;

    for (i; i < argc; i++)
    {

        if (afficherFichier(argv[i], numeroter) == 1)
        {
            detectionErreur = 1;
        }
    }

    return detectionErreur;
}