#include <iostream>
#include <random>
#include <limits>


void viderLigne() {
     std::cin.ignore(std::numeric_limits<std::streamsize>::max() , '\n');

    
}

int LireProposition(int min , int max) {
int n;
   while(!(std::cin >> n ) || (n<min) || (n>max)){
        std::cin.clear();
        viderLigne();
        std::cout << "Entrez un nombre entre " << min << " et " << max << std::endl;
    }
    viderLigne();
    return n;
}

void jouerUnePartie(std::mt19937& moteur , int borneMin , int borneMax , int essaiemax){
    std::uniform_int_distribution<int> dist(borneMin,borneMax);
    int nombresecret = dist(moteur);
    int proposition;
    int essaie=1;
   

    std::cout << "Devine le Nombre auquel je pense"<< std::endl;
    std::cout << "Donne ta proposition: ";
    proposition = LireProposition(borneMin,borneMax);
   

    while (proposition != nombresecret && essaie < essaiemax){
       if (proposition < nombresecret)
       {
        std::cout << "Plus Grand" << std::endl;
        
       }
       else if (proposition > nombresecret)
       {
         std::cout << "Plus petit" << std::endl;
       }
       std::cout << "Il vous reste " << essaiemax - essaie << " essaies" << std::endl;
       std::cout  << "Reessaie : ";
       proposition  = LireProposition(borneMin,borneMax);
       essaie++;
        
       }
    
    if (proposition == nombresecret )
    {
          std::cout << "Nous avons un gagnant en " << essaie << " essaies ." << std::endl;

    }
    else 
    {
        std::cout << "Vous avez atteint la  limite d'essaies" << "le nombre secret etait " << nombresecret << std::endl;
    }
}





int main() {
    char reponse='n';
    const int borneMin = 1;
    const int borneMax =10;
    std::random_device rd;
    std::mt19937 moteur(rd());
    const int essaiemax=5;

    do
    {
      jouerUnePartie(moteur , borneMin , borneMax , essaiemax);
    std::cout << "Rejouer (o/n) : " << std::endl;
    std::cin >> reponse;
    viderLigne();
  } while(reponse == 'o');
    
}

