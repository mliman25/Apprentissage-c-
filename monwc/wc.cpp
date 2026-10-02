#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

int main(int argc , char* argv[]){
    if (argc == 1){
        std::cerr << "Auncun Fichier detecter ,  Cas d'usage : ./wc nomfichier.txt" << std::endl;
        return 1;
    }

    std::ifstream fichier(argv[1]);

    if (!fichier){
        std::cerr << "le fichier n'as pas pu s'ouvrir" << std::endl;
        return 1;
    }

    int lignes =0;
    int caracteres = 0;
    std::string z;
    int nombreMot=0;

    while (std::getline(fichier , z)){
        lignes ++;
        caracteres += z.size();
        std::istringstream flux(z);
        std::string unMot;
        while(flux >> unMot){
            nombreMot++;
        }


    }
    std::cout << lignes << " " << nombreMot << " " << caracteres << std::endl;
    return 0;




}