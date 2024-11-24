#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Window/Mouse.hpp>

#include <sstream>
#include <fstream>

class carte {
    private:
        int simbol;
        int valoare;
    public:
        carte() {
            simbol = 0;
            valoare = 0;
        }
        carte(int s, int v) {
            simbol = s;
            valoare = v;
        }
        carte(const carte &q) {
            simbol = q.simbol;
            valoare = q.valoare;
        }
        ~carte() {

        }
        void operator =(const carte &q) {
            simbol = q.simbol;
            valoare = q.valoare;
        }
        int da_simbol() {
            return simbol;
        }
        int da_valoare() {
            return valoare;
        }
};

class selectie {
    private:
        char categorie; // 'f'-free cell, 'b'-baza, 'c'-coloana
        int c;
        int r; //indicele de coloana, respectiv rand al selectiei. Pentru free cell indicele de rand nu conteaza, este 0.
        int x;
        int y; //pozitia de afisare a selectiei
        int afiseaza; //daca chenarul de selectare trebuie afisat
    public:
        selectie() {
            categorie = 'f';
            c = 0;
            r = 0;
            x = 20;
            y = 70;
            afiseaza = 0;
        }
        selectie(char categ, int cx, int cy, int afx, int afy, int af) {
            categorie = categ;
            c = cx;
            r = cy;
            x = afx;
            y = afy;
            afiseaza = af;
        }
        selectie(const selectie &q) {
            categorie = q.categorie;
            c = q.c;
            r = q.r;
            x = q.x;
            y = q.y;
            afiseaza = q.afiseaza;
        }
        ~selectie() {

        }
        void operator =(const selectie &q) {
            categorie = q.categorie;
            c = q.c;
            r = q.r;
            x = q.x;
            y = q.y;
            afiseaza = q.afiseaza;
        }
        int da_afiseaza() {
            return afiseaza;
        }
        void set_afiseaza(int i) {
            afiseaza = i;
        }
        int da_x() {
            return x;
        }
        int da_y() {
            return y;
        }
        void set_pozitie(int poz_x, int poz_y) {
            x = poz_x;
            y = poz_y;
        }
        void set_categorie(char k, int ix, int iy) {
            categorie = k;
            c = ix;
            r = iy;
        }
        char da_categoria() {
            return categorie;
        }
        int da_coloana() {
            return c;
        }
        int da_rand() {
            return r;
        }
};

class tabla {
    private:
        //free cell
        carte free_cell[4];
        int free_cell_poz[4][2];
        int free_cell_k[4];
        //baza
        carte baza[4];
        int baza_poz[4][2];
        int baza_k[4];
        //coloane
        carte coloana[8][15];
        int col_poz[8][15][2];
        int col_k[8];
    public:
        tabla() {
            //free cell
            free_cell_k[0] = 0;
            free_cell_k[1] = 0;
            free_cell_k[2] = 0;
            free_cell_k[3] = 0;
            int fcp[4][2] = {{20,70},{162,70},{304,70},{446,70}};
            for(int i=0; i<4; i++) {
                for(int j=0; j<2; j++) {
                    free_cell_poz[i][j] = fcp[i][j];
                }
            }
            //baza
            baza_k[0] = 0;
            baza_k[1] = 0;
            baza_k[2] = 0;
            baza_k[3] = 0;
            int bzp[4][2] = {{716,70},{858,70},{1000,70},{1142,70}};
            for(int i=0; i<4; i++) {
                for(int j=0; j<2; j++) {
                    baza_poz[i][j] = bzp[i][j];
                }
            }
            //coloane
            const int cl[8] = {7, 7, 7, 7, 6, 6, 6, 6};
            for(int i=0; i<8; i++) {
                col_k[i] = cl[i];
            }
            std::ifstream sourceFileStream{ "resources/coord_coloane.txt" };
            for(int i=0; i<8; i++) {
                for(int j=0; j<15; j++) {
                    for(int k=0; k<2; k++) {
                        sourceFileStream >> col_poz[i][j][k];
                    }
                }
            }
        }
        carte ffree_cell(int i) {
            return free_cell[i];
        }
        int ffree_cell_poz(int i, int j) {
            return free_cell_poz[i][j];
        }
        int ffree_cell_k(int i) {
            return free_cell_k[i];
        }
        carte fbaza(int i) {
            return baza[i];
        }
        int fbaza_poz(int i, int j) {
            return baza_poz[i][j];
        }
        int fbaza_k(int i) {
            return baza_k[i];
        }
        carte fcoloana(int i, int j) {
            return coloana[i][j];
        }
        void fscoloana(int i, int j, carte q) {
            coloana[i][j] = q;
        }
        int fcol_poz(int i, int j, int k) {
            return col_poz[i][j][k];
        }
        int fcol_k(int i) {
            return col_k[i];
        }
        selectie identifica_selectie(float clc_x, float clc_y, selectie sell) {
            //verifica daca s-a facut clic pe free cell de la 0 la 3
            int k_selectata = 0;
            for(int fc=0; fc<4; fc++) {
                if(free_cell_k[fc] > 0 && clc_x >= free_cell_poz[fc][0] && clc_x <= free_cell_poz[fc][0] + 69.f * 2.f && clc_y >= free_cell_poz[fc][1] && clc_y <= free_cell_poz[fc][1] + 94.f * 1.9f) {
                    sell.set_categorie('f', fc, 0);
                    sell.set_pozitie(free_cell_poz[fc][0], free_cell_poz[fc][1]);
                    sell.set_afiseaza(1);
                    k_selectata = 1;
                    break;
                }
            }
            if(k_selectata == 0 ) {
                //verifica daca s-a facut clic pe cartea din coloana de la 0 la 7
                for(int cc=0; cc<8; cc++) {
                    if(col_k[cc] > 0 && clc_x >= col_poz[cc][col_k[cc] - 1][0] && clc_x <= col_poz[cc][col_k[cc] - 1][0] + 69.f * 2.f && clc_y >= col_poz[cc][col_k[cc] - 1][1] && clc_y <= col_poz[cc][col_k[cc] - 1][1] + 94.f * 1.9f) {
                        sell.set_categorie('c', cc, col_k[cc] - 1);
                        sell.set_pozitie(col_poz[cc][col_k[cc] - 1][0], col_poz[cc][col_k[cc] - 1][1]);
                        sell.set_afiseaza(1);
                        k_selectata = 1;
                        break;
                    }
                }
            }
            if(k_selectata == 0) {
                sell.set_afiseaza(0);
            }
            return sell;
        }
        selectie muta_cartea(float clc_x, float clc_y, char c, int kl, int rn, int qv, int qs, selectie sell) {
            sell.set_afiseaza(0);
            carte qrt;
            //verifica daca s-a facut clic pe free cell
            for(int i=0; i<4; i++) {
                //mutarea se face daca nu exista carte in free cell 0
                if(free_cell_k[i] == 0 && clc_x >= free_cell_poz[i][0] && clc_x <= free_cell_poz[i][0] + 69.f * 2.f && clc_y >= free_cell_poz[i][1] && clc_y <= free_cell_poz[i][1] + 94.f * 1.9f) {
                    //cartea este din una dintre coloane
                    free_cell_k[i] = 1;
                    if(c == 'c') {
                        //preia cartea in free cel
                        free_cell[i] = coloana[kl][rn];
                        //elimina cartea din coloana
                        coloana[kl][rn] = qrt;
                        col_k[kl] -= 1;
                    }
                    //cartea este dintr-o alta free cell
                    if(c == 'f' && kl != 0) {
                        //preia cartea in acest free cel
                        free_cell[i] = free_cell[kl];
                        //elimina cartea din free cel
                        free_cell[kl] = qrt;
                        free_cell_k[kl] = 0;
                    }
                }
            }
            //verifica daca s-a facut clic pe baza 0
            for(int i=0; i<4; i++) {
                //mutarea se face daca se respecta simbolul, iar cartea este urmatoarea valoare
                if((qs == i && ((baza_k[i] == 0 && qv == 0) || (baza_k[i] == 1 && baza[i].da_valoare() + 1 == qv))) && clc_x >= baza_poz[i][0] && clc_x <= baza_poz[i][0] + 69.f * 2.f && clc_y >= baza_poz[i][1] && clc_y <= baza_poz[i][1] + 94.f * 1.9f) {
                    //cartea este din una dintre coloane
                    baza_k[i] = 1;
                    if(c == 'c') {
                        //preia cartea in baza
                        baza[i] = coloana[kl][rn];
                        //elimina cartea din coloana
                        coloana[kl][rn] = qrt;
                        col_k[kl] -= 1;
                    }
                    //cartea este dintr-o free cell
                    if(c == 'f') {
                        //preia cartea in baz
                        baza[i] = free_cell[kl];
                        //elimina cartea din free cell
                        free_cell[kl] = qrt;
                        free_cell_k[kl] = 0;
                    }
                }
            }
            //verifica daca s-a facut clic pe coloana
            for(int nkl=0; nkl<8; nkl++) {
                if(clc_x >= col_poz[nkl][1][0] && clc_x <= col_poz[nkl][1][0] + 69.f * 2.f && clc_y >= col_poz[nkl][0][1] && clc_y <= col_poz[nkl][14][1] + 94.f * 1.9f) {
                    if((c == 'f' || (c == 'c' && nkl != kl)) && (col_k[nkl] == 0 || (col_k[nkl] > 0 && col_k[nkl] < 15 && (coloana[nkl][col_k[nkl]-1].da_valoare() == qv + 1) && ((coloana[nkl][col_k[nkl]-1].da_simbol() % 2) != (qs % 2))))) {
                        //mutarea se face daca:
                        //   --selectia vine de pe un free cell ori de pe alta coloana
                        //   --aceasta coloana nu are nicio carte, iar cartea selectata poate fi oricare
                        //   --sau aceasta coloana are mai putin de 15 carti si cartea selectata are valoarea +1 fata de ultima carte din coloana si simbol(culoare) schimbat (par peste impar ori impar peste par)
                        //preia cartea in baza
                        col_k[nkl] += 1;
                        if(c == 'c') {
                            coloana[nkl][col_k[nkl]-1] = coloana[kl][rn];
                            //elimina cartea din coloana
                            coloana[kl][rn] = qrt;
                            col_k[kl] -= 1;
                        }
                        if(c == 'f') {
                            coloana[nkl][col_k[nkl]-1] = free_cell[kl];
                            //elimina cartea din free cell
                            free_cell[kl] = qrt;
                            free_cell_k[kl] = 0;
                        }
                    }
                }
            }
            return sell;
        }
};

class pachet {
    private:
        int ord_i[13][4], ord[13][4];
        carte k[4][13];
    public:
        pachet() {
            int o = 0;
            for(int i=0; i<13; i++) {
                for(int j=0; j<4; j++) {
                    ord_i[i][j] = o;
                    ord[i][j] = o;
                    k[j][i] = carte(j,i);
                    o++;
                }
            }
        }
        ~pachet(){}
        void amesteca() {
            for(int i=0; i<52; i++) {
                int marja = 52 - i;
                int al = rand() % marja;
                int aux = ord[i / 4][i % 4];
                ord[i / 4][i % 4] = ord[(al + i) / 4][(al + i) % 4];
                ord[(al + i) / 4][(al + i) % 4] = aux;
            }
        }
        carte da_cartea(int o) {
            //stabileste in ord care este cartea
            int v = o / 4;
            int s = o % 4;
            //citeste valoare de acolo
            int c = ord[v][s];
            //apoi determina ce carte reprezinta acea valoare
            v = c / 4;
            s = c % 4;
            //si o intoarce ca rezultat
            carte g = k[s][v];
            return g;
        }
};

class qwk {
    private:
        int poz_carte[13][4][2];
        sf::Font fnt;
        sf::Text mesaj;
        sf::RenderWindow window;//fereastra de lucru
        sf::Texture tx_fundal;//textura cu imaginea de fundal
        sf::Sprite sp_fundal;//spriteul in care se incarca imaginea de fundal
        sf::Sprite sp_riga1;
        sf::Sprite sp_riga2;
        sf::RectangleShape sp_sel;//selectie
        selectie sel;
        tabla tb;
        pachet p;
        sf::Sprite sp_afis[52];
        void afiseaza_zona(int kx, carte krt, int kpoz0, int kpoz1) {
            if(kx == 1) {
                carte ktmp = krt;
                int kord = ktmp.da_valoare() * 4 + ktmp.da_simbol();
                sp_afis[kord].setPosition(kpoz0, kpoz1);
                window.draw(sp_afis[kord]);
            }
        }
    public:
        qwk() {
            //pozitia de citire din imaginea de baza pentru fiecare carte
            std::ifstream sourceFileStream{ "resources/coord_carti.txt" };
            for(int i=0; i<13; i++) {
                for(int j=0; j<4; j++) {
                    sourceFileStream >> poz_carte[i][j][0];
                    sourceFileStream >> poz_carte[i][j][1];
                }
            }
            fnt.loadFromFile("resources/arial.ttf");
            mesaj.setString("Hello!");
            mesaj.setFont(fnt);
            mesaj.setCharacterSize(15);
            mesaj.setFillColor(sf::Color::Yellow);
            window.create(sf::VideoMode(1300, 920), "Free Cell");
            //incarca imaginea de fundal in textura
            tx_fundal.loadFromFile("resources/baza.png");
            //selecteaza dreptunghiul cu imaginea de fundal in sprite-ul fundal
            sp_fundal.setTexture(tx_fundal);
            sp_fundal.setTextureRect(sf::IntRect(0, 0, 632, 453));
            sp_fundal.setPosition(18.f,30.f);
            sp_fundal.setScale(2.f,1.9f);
            //riga1
            sp_riga1.setTexture(tx_fundal);
            sp_riga1.setTextureRect(sf::IntRect(319, 453, 36, 36));
            sp_riga1.setPosition(18.f + 596.f,30.f + 74.f);
            sp_riga1.setScale(2.f,1.9f);
            //riga2
            sp_riga2.setTexture(tx_fundal);
            sp_riga2.setTextureRect(sf::IntRect(355, 453, 36, 36));
            sp_riga2.setPosition(18.f + 596.f,30.f + 74.f);
            sp_riga2.setScale(2.f,1.9f);
            //selectie
            sp_sel.setSize(sf::Vector2f(71, 96));
            sp_sel.setPosition(18.f + 0.f,30.f + 0.f);
            sp_sel.setOutlineColor(sf::Color::Magenta);
            sp_sel.setFillColor(sf::Color(255, 255, 255, 64));
            sp_sel.setOutlineThickness(2);
            sp_sel.setScale(2.f,1.9f);
            //definire carti
            for(int y = 0; y < 52; y++) {
                sp_afis[y].setTexture(tx_fundal);
                sp_afis[y].setTextureRect(sf::IntRect(poz_carte[y / 4][y % 4][0], poz_carte[y / 4][y % 4][1], 71, 96));
                sp_afis[y].setScale(2.f,1.9f);
            }
            p.amesteca();
            //imparte cartile pe coloane
            for(int i = 0; i < 52; i++) {
                int nCol, nRnd;
                nCol = i % 8;
                nRnd = i / 8;
                tb.fscoloana(nCol, nRnd, p.da_cartea(i));
            }
        }
        void afiseaza_tabla(int mod) {
            //afiseaza fereastra cu imaginea de fundal
            window.clear();
            window.draw(sp_fundal);
            //afiseaza riga
            if(mod==0) {
                window.draw(sp_riga1);
            }
            if(mod==1) {
                window.draw(sp_riga2);
            }
            //afiseaza free cell
            for(int x=0; x<4; x++) {
                afiseaza_zona(tb.ffree_cell_k(x), tb.ffree_cell(x), tb.ffree_cell_poz(x, 0), tb.ffree_cell_poz(x, 1));
            }
            //afiseaza baza
            for(int x=0; x<4; x++) {
                afiseaza_zona(tb.fbaza_k(x), tb.fbaza(x), tb.fbaza_poz(x, 0), tb.fbaza_poz(x, 1));
            }
            for(int x=0; x<8; x++) {
                for(int y=0; y<tb.fcol_k(x); y++) {
                    afiseaza_zona(1, tb.fcoloana(x, y), tb.fcol_poz(x, y, 0), tb.fcol_poz(x, y, 1));
                }
            }
            //afiseaza selectia
            if(sel.da_afiseaza() == 1) {
                sp_sel.setPosition(float(sel.da_x()), float(sel.da_y()));
                window.draw(sp_sel);
            }
            window.draw(mesaj);
            window.display();
        }

        void joaca(char p_mod_lucru, int p_dr) {
            while (window.isOpen()) {
                sf::Event event;
                while (window.pollEvent(event))
                {
                    if (event.type == sf::Event::Closed) {
                        window.close();
                        return;
                    }
                }

                if (sf::Mouse::getPosition(window).x > 632) {
                    p_dr = 1;
                    afiseaza_tabla(p_dr);
                }
                else {
                    p_dr = 0;
                    afiseaza_tabla(p_dr);
                }

                if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                {   //clic dreapta
                    //citeste pozitia mausului
                    //identifica cartea selectata
                    switch(p_mod_lucru) {
                        case 's':
                            //mesaj.setString("Mod selectare");
                            sel = tb.identifica_selectie(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y, sel);
                            afiseaza_tabla(p_dr);
                            if(sel.da_afiseaza() == 1) p_mod_lucru = 'm';
                            while(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                                //asteapta eliberarea mausului
                            }
                        break;
                        case 'm':
                            //mesaj.setString("Mod mutare");
                            //identifica cartea selectata
                            carte k_sel;
                            if(sel.da_categoria() == 'c') k_sel = tb.fcoloana(sel.da_coloana(), sel.da_rand());
                            if(sel.da_categoria() == 'f') k_sel = tb.ffree_cell(sel.da_coloana());
                            //identifica pozitia in care muta cartea selectata
                            sel = tb.muta_cartea(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y, sel.da_categoria(), sel.da_coloana(), sel.da_rand(), k_sel.da_valoare(), k_sel.da_simbol(), sel);
                            afiseaza_tabla(p_dr);
                            if(sel.da_afiseaza() == 0) p_mod_lucru = 's';
                            while(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                                //asteapta eliberarea mausului
                            }
                        break;
                    }
                }
            }
        }
};

int main()
{
    qwk qw;
    //amesteca pachetul de carti
    srand(time(0));

    qw.afiseaza_tabla(0);

    //modul de lucru se defineste prin valorile
    // 's' - selecteaza cartea pe care se face clic
    // 'm' - muta cartea selectata pe pozitia pe care s-a facut clic
    char mod_lucru = 's';

    int dr = 0;

    qw.joaca(mod_lucru, dr);
    return 0;
}
