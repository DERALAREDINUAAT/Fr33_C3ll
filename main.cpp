#include <iostream>
#include <exception>
#include <ctime>

#include <SFML/Graphics.hpp>
#include <SFML/Window/Mouse.hpp>
//#include <SFML/Audio.hpp>

#include <sstream>
#include <fstream>

#include "Scor.h"
#include "Exceptii.h"
#include "Carte.h"
#include "Selectie.h"
#include "Dificultate.h"
#include "Tabla.h"

int main()
{
    //definire eroare de incarcare
    try {
        //test afisare carte
        std::cout << "Test afisare carte\n";
        carte kk(0, 11);
        std::cout << kk << '\n';
        stabileste_dificultatea st;
        st.afiseaza_init();
        st.joaca_init();
        int df = st.da_dificultate();
        qwk joc(df);
        //amesteca pachetul de carti
        srand(time(0));

        //std::cout << "Afiseaza tabla de joc\n";
        joc.afiseaza_tabla(0);

        //modul de lucru se defineste prin valorile
        // 's' - selecteaza cartea pe care se face clic
        // 'm' - muta cartea selectata pe pozitia pe care s-a facut clic
        char mod_lucru = 's';

        int dr = 0;

        joc.joaca(mod_lucru, dr);
    }
    catch (std::exception& e) {
        std::cout << e.what() << '\n';
        system("pause"); 
    }

    return 0;
}
