#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Window/Mouse.hpp>

#include <sstream>

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
            int cp[8][15][2] = {{  {26,258},  {26,283},  {26,308},  {26,333},  {26,358},  {26,383},  {26,408},  {26,433},  {26,458},  {26,483},  {26,508},  {26,533},  {26,558},  {26,583},  {26,608}},
                                    { {184,258}, {184,283}, {184,308}, {184,333}, {184,358}, {184,383}, {184,408}, {184,433}, {184,458}, {184,483}, {184,508}, {184,533}, {184,558}, {184,583}, {184,608}},
                                    { {342,258}, {342,283}, {342,308}, {342,333}, {342,358}, {342,383}, {342,408}, {342,433}, {342,458}, {342,483}, {342,508}, {342,533}, {342,558}, {342,583}, {342,608}},
                                    { {500,258}, {500,283}, {500,308}, {500,333}, {500,358}, {500,383}, {500,408}, {500,433}, {500,458}, {500,483}, {500,508}, {500,533}, {500,558}, {500,583}, {500,608}},
                                    { {658,258}, {658,283}, {658,308}, {658,333}, {658,358}, {658,383}, {658,408}, {658,433}, {658,458}, {658,483}, {658,508}, {658,533}, {658,558}, {658,583}, {658,608}},
                                    { {816,258}, {816,283}, {816,308}, {816,333}, {816,358}, {816,383}, {816,408}, {816,433}, {816,458}, {816,483}, {816,508}, {816,533}, {816,558}, {816,583}, {816,608}},
                                    { {974,258}, {974,283}, {974,308}, {974,333}, {974,358}, {974,383}, {974,408}, {974,433}, {974,458}, {974,483}, {974,508}, {974,533}, {974,558}, {974,583}, {974,608}},
                                    {{1132,258},{1132,283},{1132,308},{1132,333},{1132,358},{1132,383},{1132,408},{1132,433},{1132,458},{1132,483},{1132,508},{1132,533},{1132,558},{1132,583},{1132,608}}};
            for(int i=0; i<8; i++) {
                for(int j=0; j<15; j++) {
                    for(int k=0; k<2; k++) {
                        col_poz[i][j][k] = cp[i][j][k];
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
            int pzk[13][4][2] = {
                {{632,192}, {632,288}, {632,96}, {632,0} },
                {{703,192}, {703,288}, {703,96}, {703,0} },
                {{774,192}, {774,288}, {774,96}, {774,0} },
                {{845,192}, {845,288}, {845,96}, {845,0} },
                {{916,192}, {916,288}, {916,96}, {916,0} },
                {{987,192}, {987,288}, {987,96}, {987,0} },
                {{1058,192},{1058,288},{1058,96},{1058,0}},
                {{1129,192},{1129,288},{1129,96},{1129,0}},
                {{1200,192},{1200,288},{1200,96},{1200,0}},
                {{1271,192},{1271,288},{1271,96},{1271,0}},
                {{1342,192},{1342,288},{1342,96},{1342,0}},
                {{1413,192},{1413,288},{1413,96},{1413,0}},
                {{1484,192},{1484,288},{1484,96},{1484,0}}
            };
            for(int i=0; i<13; i++) {
                for(int j=0; j<4; j++) {
                    poz_carte[i][j][0] = pzk[i][j][0];
                    poz_carte[i][j][1] = pzk[i][j][1];
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
