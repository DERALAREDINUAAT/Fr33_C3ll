#include <iostream>

#include <SFML/Graphics.hpp>
#include <windows.h>
#include <SFML/Window/Mouse.hpp>

#include <sstream>

//*****************************/
//***  Variabile globale    ***/
//*****************************/

//mesaje
sf::Font fnt;
sf::Text mesaj("Hello!", fnt, 15);

//pozitia de citire din imaginea de baza pentru fiecare carte
int poz_carte[13][4][2] = {
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
//creaza fereastra de lucru
sf::RenderWindow window(sf::VideoMode(1300, 920), "Free Cell");
//creaza textura cu imaginea de fundal
sf::Texture tx_fundal;
//creaza textura in care se incarca imaginea de fundal
sf::Sprite sp_fundal(tx_fundal);
//riga
sf::Sprite sp_riga(tx_fundal);
//riga2
sf::Sprite sp_riga2(tx_fundal);
//selectie
sf::RectangleShape sp_sel;
//carti
sf::Sprite sp_afis[52];
sf::Sprite sp_af[52];
sf::Sprite sp_k01(tx_fundal);
sf::Sprite sp_k02(tx_fundal);
sf::Sprite sp_k03(tx_fundal);
sf::Sprite sp_k04(tx_fundal);
sf::Sprite sp_k05(tx_fundal);
sf::Sprite sp_k06(tx_fundal);
sf::Sprite sp_k07(tx_fundal);
sf::Sprite sp_k08(tx_fundal);
sf::Sprite sp_k09(tx_fundal);
sf::Sprite sp_k10(tx_fundal);
sf::Sprite sp_k11(tx_fundal);
sf::Sprite sp_k12(tx_fundal);
sf::Sprite sp_k13(tx_fundal);
sf::Sprite sp_k14(tx_fundal);
sf::Sprite sp_k15(tx_fundal);
sf::Sprite sp_k16(tx_fundal);
sf::Sprite sp_k17(tx_fundal);
sf::Sprite sp_k18(tx_fundal);
sf::Sprite sp_k19(tx_fundal);
sf::Sprite sp_k20(tx_fundal);
sf::Sprite sp_k21(tx_fundal);
sf::Sprite sp_k22(tx_fundal);
sf::Sprite sp_k23(tx_fundal);
sf::Sprite sp_k24(tx_fundal);
sf::Sprite sp_k25(tx_fundal);
sf::Sprite sp_k26(tx_fundal);
sf::Sprite sp_k27(tx_fundal);
sf::Sprite sp_k28(tx_fundal);
sf::Sprite sp_k29(tx_fundal);
sf::Sprite sp_k30(tx_fundal);
sf::Sprite sp_k31(tx_fundal);
sf::Sprite sp_k32(tx_fundal);
sf::Sprite sp_k33(tx_fundal);
sf::Sprite sp_k34(tx_fundal);
sf::Sprite sp_k35(tx_fundal);
sf::Sprite sp_k36(tx_fundal);
sf::Sprite sp_k37(tx_fundal);
sf::Sprite sp_k38(tx_fundal);
sf::Sprite sp_k39(tx_fundal);
sf::Sprite sp_k40(tx_fundal);
sf::Sprite sp_k41(tx_fundal);
sf::Sprite sp_k42(tx_fundal);
sf::Sprite sp_k43(tx_fundal);
sf::Sprite sp_k44(tx_fundal);
sf::Sprite sp_k45(tx_fundal);
sf::Sprite sp_k46(tx_fundal);
sf::Sprite sp_k47(tx_fundal);
sf::Sprite sp_k48(tx_fundal);
sf::Sprite sp_k49(tx_fundal);
sf::Sprite sp_k50(tx_fundal);
sf::Sprite sp_k51(tx_fundal);
sf::Sprite sp_k52(tx_fundal);

void initializare() {
    fnt.loadFromFile("resources/arial.ttf");
    mesaj.setFillColor(sf::Color::Yellow);
    //incarca imaginea de fundal in textura
    tx_fundal.loadFromFile("imagini/baza.png");
    //selecteaza dreptunghiul cu imaginea de fundal in sprite-ul fundal
    sp_fundal.setTextureRect(sf::IntRect(0, 0, 632, 453));
    sp_fundal.setPosition(18.f,30.f);
    sp_fundal.setScale(2.f,1.9f);
    //riga1
    sp_riga.setTextureRect(sf::IntRect(319, 453, 36, 36));
    sp_riga.setPosition(18.f + 596.f,30.f + 74.f);
    sp_riga.setScale(2.f,1.9f);
    //riga2
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
    //carti
    sp_k01.setTextureRect(sf::IntRect(poz_carte[0][0][0], poz_carte[0][0][1], 71, 96));
    sp_k01.setScale(2.f,1.9f);
    sp_afis[0]=sp_k01;
    sp_k02.setTextureRect(sf::IntRect(poz_carte[0][1][0], poz_carte[0][1][1], 71, 96));
    sp_k02.setScale(2.f,1.9f);
    sp_afis[1]=sp_k02;
    sp_k03.setTextureRect(sf::IntRect(poz_carte[0][2][0], poz_carte[0][2][1], 71, 96));
    sp_k03.setScale(2.f,1.9f);
    sp_afis[2]=sp_k03;
    sp_k04.setTextureRect(sf::IntRect(poz_carte[0][3][0], poz_carte[0][3][1], 71, 96));
    sp_k04.setScale(2.f,1.9f);
    sp_afis[3]=sp_k04;
    sp_k05.setTextureRect(sf::IntRect(poz_carte[1][0][0], poz_carte[1][0][1], 71, 96));
    sp_k05.setScale(2.f,1.9f);
    sp_afis[4]=sp_k05;
    sp_k06.setTextureRect(sf::IntRect(poz_carte[1][1][0], poz_carte[1][1][1], 71, 96));
    sp_k06.setScale(2.f,1.9f);
    sp_afis[5]=sp_k06;
    sp_k07.setTextureRect(sf::IntRect(poz_carte[1][2][0], poz_carte[1][2][1], 71, 96));
    sp_k07.setScale(2.f,1.9f);
    sp_afis[6]=sp_k07;
    sp_k08.setTextureRect(sf::IntRect(poz_carte[1][3][0], poz_carte[1][3][1], 71, 96));
    sp_k08.setScale(2.f,1.9f);
    sp_afis[7]=sp_k08;
    sp_k09.setTextureRect(sf::IntRect(poz_carte[2][0][0], poz_carte[2][0][1], 71, 96));
    sp_k09.setScale(2.f,1.9f);
    sp_afis[8]=sp_k09;
    sp_k10.setTextureRect(sf::IntRect(poz_carte[2][1][0], poz_carte[2][1][1], 71, 96));
    sp_k10.setScale(2.f,1.9f);
    sp_afis[9]=sp_k10;
    sp_k11.setTextureRect(sf::IntRect(poz_carte[2][2][0], poz_carte[2][2][1], 71, 96));
    sp_k11.setScale(2.f,1.9f);
    sp_afis[10]=sp_k11;
    sp_k12.setTextureRect(sf::IntRect(poz_carte[2][3][0], poz_carte[2][3][1], 71, 96));
    sp_k12.setScale(2.f,1.9f);
    sp_afis[11]=sp_k12;
    sp_k13.setTextureRect(sf::IntRect(poz_carte[3][0][0], poz_carte[3][0][1], 71, 96));
    sp_k13.setScale(2.f,1.9f);
    sp_afis[12]=sp_k13;
    sp_k14.setTextureRect(sf::IntRect(poz_carte[3][1][0], poz_carte[3][1][1], 71, 96));
    sp_k14.setScale(2.f,1.9f);
    sp_afis[13]=sp_k14;
    sp_k15.setTextureRect(sf::IntRect(poz_carte[3][2][0], poz_carte[3][2][1], 71, 96));
    sp_k15.setScale(2.f,1.9f);
    sp_afis[14]=sp_k15;
    sp_k16.setTextureRect(sf::IntRect(poz_carte[3][3][0], poz_carte[3][3][1], 71, 96));
    sp_k16.setScale(2.f,1.9f);
    sp_afis[15]=sp_k16;
    sp_k17.setTextureRect(sf::IntRect(poz_carte[4][0][0], poz_carte[4][0][1], 71, 96));
    sp_k17.setScale(2.f,1.9f);
    sp_afis[16]=sp_k17;
    sp_k18.setTextureRect(sf::IntRect(poz_carte[4][1][0], poz_carte[4][1][1], 71, 96));
    sp_k18.setScale(2.f,1.9f);
    sp_afis[17]=sp_k18;
    sp_k19.setTextureRect(sf::IntRect(poz_carte[4][2][0], poz_carte[4][2][1], 71, 96));
    sp_k19.setScale(2.f,1.9f);
    sp_afis[18]=sp_k19;
    sp_k20.setTextureRect(sf::IntRect(poz_carte[4][3][0], poz_carte[4][3][1], 71, 96));
    sp_k20.setScale(2.f,1.9f);
    sp_afis[19]=sp_k20;
    sp_k21.setTextureRect(sf::IntRect(poz_carte[5][0][0], poz_carte[5][0][1], 71, 96));
    sp_k21.setScale(2.f,1.9f);
    sp_afis[20]=sp_k21;
    sp_k22.setTextureRect(sf::IntRect(poz_carte[5][1][0], poz_carte[5][1][1], 71, 96));
    sp_k22.setScale(2.f,1.9f);
    sp_afis[21]=sp_k22;
    sp_k23.setTextureRect(sf::IntRect(poz_carte[5][2][0], poz_carte[5][2][1], 71, 96));
    sp_k23.setScale(2.f,1.9f);
    sp_afis[22]=sp_k23;
    sp_k24.setTextureRect(sf::IntRect(poz_carte[5][3][0], poz_carte[5][3][1], 71, 96));
    sp_k24.setScale(2.f,1.9f);
    sp_afis[23]=sp_k24;
    sp_k25.setTextureRect(sf::IntRect(poz_carte[6][0][0], poz_carte[6][0][1], 71, 96));
    sp_k25.setScale(2.f,1.9f);
    sp_afis[24]=sp_k25;
    sp_k26.setTextureRect(sf::IntRect(poz_carte[6][1][0], poz_carte[6][1][1], 71, 96));
    sp_k26.setScale(2.f,1.9f);
    sp_afis[25]=sp_k26;
    sp_k27.setTextureRect(sf::IntRect(poz_carte[6][2][0], poz_carte[6][2][1], 71, 96));
    sp_k27.setScale(2.f,1.9f);
    sp_afis[26]=sp_k27;
    sp_k28.setTextureRect(sf::IntRect(poz_carte[6][3][0], poz_carte[6][3][1], 71, 96));
    sp_k28.setScale(2.f,1.9f);
    sp_afis[27]=sp_k28;
    sp_k29.setTextureRect(sf::IntRect(poz_carte[7][0][0], poz_carte[7][0][1], 71, 96));
    sp_k29.setScale(2.f,1.9f);
    sp_afis[28]=sp_k29;
    sp_k30.setTextureRect(sf::IntRect(poz_carte[7][1][0], poz_carte[7][1][1], 71, 96));
    sp_k30.setScale(2.f,1.9f);
    sp_afis[29]=sp_k30;
    sp_k31.setTextureRect(sf::IntRect(poz_carte[7][2][0], poz_carte[7][2][1], 71, 96));
    sp_k31.setScale(2.f,1.9f);
    sp_afis[30]=sp_k31;
    sp_k32.setTextureRect(sf::IntRect(poz_carte[7][3][0], poz_carte[7][3][1], 71, 96));
    sp_k32.setScale(2.f,1.9f);
    sp_afis[31]=sp_k32;
    sp_k33.setTextureRect(sf::IntRect(poz_carte[8][0][0], poz_carte[8][0][1], 71, 96));
    sp_k33.setScale(2.f,1.9f);
    sp_afis[32]=sp_k33;
    sp_k34.setTextureRect(sf::IntRect(poz_carte[8][1][0], poz_carte[8][1][1], 71, 96));
    sp_k34.setScale(2.f,1.9f);
    sp_afis[33]=sp_k34;
    sp_k35.setTextureRect(sf::IntRect(poz_carte[8][2][0], poz_carte[8][2][1], 71, 96));
    sp_k35.setScale(2.f,1.9f);
    sp_afis[34]=sp_k35;
    sp_k36.setTextureRect(sf::IntRect(poz_carte[8][3][0], poz_carte[8][3][1], 71, 96));
    sp_k36.setScale(2.f,1.9f);
    sp_afis[35]=sp_k36;
    sp_k37.setTextureRect(sf::IntRect(poz_carte[9][0][0], poz_carte[9][0][1], 71, 96));
    sp_k37.setScale(2.f,1.9f);
    sp_afis[36]=sp_k37;
    sp_k38.setTextureRect(sf::IntRect(poz_carte[9][1][0], poz_carte[9][1][1], 71, 96));
    sp_k38.setScale(2.f,1.9f);
    sp_afis[37]=sp_k38;
    sp_k39.setTextureRect(sf::IntRect(poz_carte[9][2][0], poz_carte[9][2][1], 71, 96));
    sp_k39.setScale(2.f,1.9f);
    sp_afis[38]=sp_k39;
    sp_k40.setTextureRect(sf::IntRect(poz_carte[9][3][0], poz_carte[9][3][1], 71, 96));
    sp_k40.setScale(2.f,1.9f);
    sp_afis[39]=sp_k40;
    sp_k41.setTextureRect(sf::IntRect(poz_carte[10][0][0], poz_carte[10][0][1], 71, 96));
    sp_k41.setScale(2.f,1.9f);
    sp_afis[40]=sp_k41;
    sp_k42.setTextureRect(sf::IntRect(poz_carte[10][1][0], poz_carte[10][1][1], 71, 96));
    sp_k42.setScale(2.f,1.9f);
    sp_afis[41]=sp_k42;
    sp_k43.setTextureRect(sf::IntRect(poz_carte[10][2][0], poz_carte[10][2][1], 71, 96));
    sp_k43.setScale(2.f,1.9f);
    sp_afis[42]=sp_k43;
    sp_k44.setTextureRect(sf::IntRect(poz_carte[10][3][0], poz_carte[10][3][1], 71, 96));
    sp_k44.setScale(2.f,1.9f);
    sp_afis[43]=sp_k44;
    sp_k45.setTextureRect(sf::IntRect(poz_carte[11][0][0], poz_carte[11][0][1], 71, 96));
    sp_k45.setScale(2.f,1.9f);
    sp_afis[44]=sp_k45;
    sp_k46.setTextureRect(sf::IntRect(poz_carte[11][1][0], poz_carte[11][1][1], 71, 96));
    sp_k46.setScale(2.f,1.9f);
    sp_afis[45]=sp_k46;
    sp_k47.setTextureRect(sf::IntRect(poz_carte[11][2][0], poz_carte[11][2][1], 71, 96));
    sp_k47.setScale(2.f,1.9f);
    sp_afis[46]=sp_k47;
    sp_k48.setTextureRect(sf::IntRect(poz_carte[11][3][0], poz_carte[11][3][1], 71, 96));
    sp_k48.setScale(2.f,1.9f);
    sp_afis[47]=sp_k48;
    sp_k49.setTextureRect(sf::IntRect(poz_carte[12][0][0], poz_carte[12][0][1], 71, 96));
    sp_k49.setScale(2.f,1.9f);
    sp_afis[48]=sp_k49;
    sp_k50.setTextureRect(sf::IntRect(poz_carte[12][1][0], poz_carte[12][1][1], 71, 96));
    sp_k50.setScale(2.f,1.9f);
    sp_afis[49]=sp_k50;
    sp_k51.setTextureRect(sf::IntRect(poz_carte[12][2][0], poz_carte[12][2][1], 71, 96));
    sp_k51.setScale(2.f,1.9f);
    sp_afis[50]=sp_k51;
    sp_k52.setTextureRect(sf::IntRect(poz_carte[12][3][0], poz_carte[12][3][1], 71, 96));
    sp_k52.setScale(2.f,1.9f);
    sp_afis[51]=sp_k52;
}

class selectie {
    private:
        char categorie; // 'f'-free cell, 'b'-baza, 'c'-coloana
        int c, r; //indicele de coloana, respectiv rand al selectiei. Pentru free cell indicele de rand nu conteaza, este 0.
        int x, y; //pozitia de afisare a selectiei
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

selectie sel;

class simboluri {
    private:
        int cod;
        char simbol;
        char culoare;
    public:
        simboluri(int k, char s, char c) {
            cod = k;
            simbol = s;
            culoare = c;
        }
};

class valori {
    private:
        int cod;
        char simbol;
    public:
        valori(int k, char s) {
            cod = k;
            simbol = s;
        }
};

class carte {
    private:
        int simbol, valoare;
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
        int da_simbol() {
            return simbol;
        }
        int da_valoare() {
            return valoare;
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

//creaza pachetul de carti
pachet p;

class tabla {
    private:
        //free cell
        //baza
        //coloane
    public:
        //free cell
        carte free_cell[4];
        int free_cell_poz[4][2];
        int free_cell_k[4];
        //baza
        carte baza[4];
        int baza_poz[4][2] = {{716,70},{858,70},{1000,70},{1142,70}};
        int baza_k[4];
        //coloane
        carte coloana[8][15];
        int col_k[8];
        int col_poz[8][15][2] = {{  {26,258},  {26,283},  {26,308},  {26,333},  {26,358},  {26,383},  {26,408},  {26,433},  {26,458},  {26,483},  {26,508},  {26,533},  {26,558},  {26,583},  {26,608}},
                                { {184,258}, {184,283}, {184,308}, {184,333}, {184,358}, {184,383}, {184,408}, {184,433}, {184,458}, {184,483}, {184,508}, {184,533}, {184,558}, {184,583}, {184,608}},
                                { {342,258}, {342,283}, {342,308}, {342,333}, {342,358}, {342,383}, {342,408}, {342,433}, {342,458}, {342,483}, {342,508}, {342,533}, {342,558}, {342,583}, {342,608}},
                                { {500,258}, {500,283}, {500,308}, {500,333}, {500,358}, {500,383}, {500,408}, {500,433}, {500,458}, {500,483}, {500,508}, {500,533}, {500,558}, {500,583}, {500,608}},
                                { {658,258}, {658,283}, {658,308}, {658,333}, {658,358}, {658,383}, {658,408}, {658,433}, {658,458}, {658,483}, {658,508}, {658,533}, {658,558}, {658,583}, {658,608}},
                                { {816,258}, {816,283}, {816,308}, {816,333}, {816,358}, {816,383}, {816,408}, {816,433}, {816,458}, {816,483}, {816,508}, {816,533}, {816,558}, {816,583}, {816,608}},
                                { {974,258}, {974,283}, {974,308}, {974,333}, {974,358}, {974,383}, {974,408}, {974,433}, {974,458}, {974,483}, {974,508}, {974,533}, {974,558}, {974,583}, {974,608}},
                                {{1132,258},{1132,283},{1132,308},{1132,333},{1132,358},{1132,383},{1132,408},{1132,433},{1132,458},{1132,483},{1132,508},{1132,533},{1132,558},{1132,583},{1132,608}}};
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

        selectie identifica_selectie(float clc_x, float clc_y) {
            //mesaj.setString(std::__cxx11::to_string(free_cell_k[0]));
            //verifica daca s-a facut clic pe free cell 0
            int k_selectata = 0;
            if(free_cell_k[0] > 0) {
                if(clc_x >= free_cell_poz[0][0] && clc_x <= free_cell_poz[0][0] + 69.f * 2.f && clc_y >= free_cell_poz[0][1] && clc_y <= free_cell_poz[0][1] + 94.f * 1.9f) {
                    sel.set_categorie('f', 0, 0);
                    sel.set_pozitie(free_cell_poz[0][0], free_cell_poz[0][1]);
                    sel.set_afiseaza(1);
                    k_selectata = 1;
                }
            }
            //verifica daca s-a facut clic pe free cell 1
            if(free_cell_k[1] > 0) {
                if(clc_x >= free_cell_poz[1][0] && clc_x <= free_cell_poz[1][0] + 69.f * 2.f && clc_y >= free_cell_poz[1][1] && clc_y <= free_cell_poz[1][1] + 94.f * 1.9f) {
                    sel.set_categorie('f', 1, 0);
                    sel.set_pozitie(free_cell_poz[1][0], free_cell_poz[1][1]);
                    sel.set_afiseaza(1);
                    k_selectata = 1;
                }
            }
            //verifica daca s-a facut clic pe free cell 2
            if(free_cell_k[2] > 0) {
                if(clc_x >= free_cell_poz[2][0] && clc_x <= free_cell_poz[2][0] + 69.f * 2.f && clc_y >= free_cell_poz[2][1] && clc_y <= free_cell_poz[2][1] + 94.f * 1.9f) {
                    sel.set_categorie('f', 2, 0);
                    sel.set_pozitie(free_cell_poz[2][0], free_cell_poz[2][1]);
                    sel.set_afiseaza(1);
                    k_selectata = 1;
                }
            }
            //verifica daca s-a facut clic pe free cell 3
            if(free_cell_k[3] > 0) {
                if(clc_x >= free_cell_poz[3][0] && clc_x <= free_cell_poz[3][0] + 69.f * 2.f && clc_y >= free_cell_poz[3][1] && clc_y <= free_cell_poz[3][1] + 94.f * 1.9f) {
                    sel.set_categorie('f', 3, 0);
                    sel.set_pozitie(free_cell_poz[3][0], free_cell_poz[3][1]);
                    sel.set_afiseaza(1);
                    k_selectata = 1;
                }
            }
            //verifica daca s-a facut clic pe cartea din coloana 0
            if(col_k[0] > 0) {
                if(clc_x >= col_poz[0][col_k[0] - 1][0] && clc_x <= col_poz[0][col_k[0] - 1][0] + 69.f * 2.f && clc_y >= col_poz[0][col_k[0] - 1][1] && clc_y <= col_poz[0][col_k[0] - 1][1] + 94.f * 1.9f) {
                    sel.set_categorie('c', 0, col_k[0] - 1);
                    sel.set_pozitie(col_poz[0][col_k[0] - 1][0], col_poz[0][col_k[0] - 1][1]);
                    sel.set_afiseaza(1);
                    k_selectata = 1;
                }
            }
            //verifica daca s-a facut clic pe cartea din coloana 1
            if(col_k[1] > 0) {
                if(clc_x >= col_poz[1][col_k[1] - 1][0] && clc_x <= col_poz[1][col_k[1] - 1][0] + 69.f * 2.f && clc_y >= col_poz[1][col_k[1] - 1][1] && clc_y <= col_poz[1][col_k[1] - 1][1] + 94.f * 1.9f) {
                    sel.set_categorie('c', 1, col_k[1] - 1);
                    sel.set_pozitie(col_poz[1][col_k[1] - 1][0], col_poz[1][col_k[1] - 1][1]);
                    sel.set_afiseaza(1);
                    k_selectata = 1;
                }
            }
            //verifica daca s-a facut clic pe cartea din coloana 2
            if(col_k[2] > 0) {
                if(clc_x >= col_poz[2][col_k[2] - 1][0] && clc_x <= col_poz[2][col_k[2] - 1][0] + 69.f * 2.f && clc_y >= col_poz[2][col_k[2] - 1][1] && clc_y <= col_poz[2][col_k[2] - 1][1] + 94.f * 1.9f) {
                    sel.set_categorie('c', 2, col_k[2] - 1);
                    sel.set_pozitie(col_poz[2][col_k[2] - 1][0], col_poz[2][col_k[2] - 1][1]);
                    sel.set_afiseaza(1);
                    k_selectata = 1;
                }
            }
            //verifica daca s-a facut clic pe cartea din coloana 3
            if(col_k[3] > 0) {
                if(clc_x >= col_poz[3][col_k[3] - 1][0] && clc_x <= col_poz[3][col_k[3] - 1][0] + 69.f * 2.f && clc_y >= col_poz[3][col_k[3] - 1][1] && clc_y <= col_poz[3][col_k[3] - 1][1] + 94.f * 1.9f) {
                    sel.set_categorie('c', 3, col_k[3] - 1);
                    sel.set_pozitie(col_poz[3][col_k[3] - 1][0], col_poz[3][col_k[3] - 1][1]);
                    sel.set_afiseaza(1);
                    k_selectata = 1;
                }
            }
            //verifica daca s-a facut clic pe cartea din coloana 4
            if(col_k[4] > 0) {
                if(clc_x >= col_poz[4][col_k[4] - 1][0] && clc_x <= col_poz[4][col_k[4] - 1][0] + 69.f * 2.f && clc_y >= col_poz[4][col_k[4] - 1][1] && clc_y <= col_poz[4][col_k[4] - 1][1] + 94.f * 1.9f) {
                    sel.set_categorie('c', 4, col_k[4] - 1);
                    sel.set_pozitie(col_poz[4][col_k[4] - 1][0], col_poz[4][col_k[4] - 1][1]);
                    sel.set_afiseaza(1);
                    k_selectata = 1;
                }
            }
            //verifica daca s-a facut clic pe cartea din coloana 5
            if(col_k[5] > 0) {
                if(clc_x >= col_poz[5][col_k[5] - 1][0] && clc_x <= col_poz[5][col_k[5] - 1][0] + 69.f * 2.f && clc_y >= col_poz[5][col_k[5] - 1][1] && clc_y <= col_poz[5][col_k[5] - 1][1] + 94.f * 1.9f) {
                    sel.set_categorie('c', 5, col_k[5] - 1);
                    sel.set_pozitie(col_poz[5][col_k[5] - 1][0], col_poz[5][col_k[5] - 1][1]);
                    sel.set_afiseaza(1);
                    k_selectata = 1;
                }
            }
            //verifica daca s-a facut clic pe cartea din coloana 6
            if(col_k[6] > 0) {
                if(clc_x >= col_poz[6][col_k[6] - 1][0] && clc_x <= col_poz[6][col_k[6] - 1][0] + 69.f * 2.f && clc_y >= col_poz[6][col_k[6] - 1][1] && clc_y <= col_poz[6][col_k[6] - 1][1] + 94.f * 1.9f) {
                    sel.set_categorie('c', 6, col_k[6] - 1);
                    sel.set_pozitie(col_poz[6][col_k[6] - 1][0], col_poz[6][col_k[6] - 1][1]);
                    sel.set_afiseaza(1);
                    k_selectata = 1;
                }
            }
            //verifica daca s-a facut clic pe cartea din coloana 7
            if(col_k[7] > 0) {
                if(clc_x >= col_poz[7][col_k[7] - 1][0] && clc_x <= col_poz[7][col_k[7] - 1][0] + 69.f * 2.f && clc_y >= col_poz[7][col_k[7] - 1][1] && clc_y <= col_poz[7][col_k[7] - 1][1] + 94.f * 1.9f) {
                    sel.set_categorie('c', 7, col_k[7] - 1);
                    sel.set_pozitie(col_poz[7][col_k[7] - 1][0], col_poz[7][col_k[7] - 1][1]);
                    sel.set_afiseaza(1);
                    k_selectata = 1;
                }
            }
            if(k_selectata == 0) {
                sel.set_afiseaza(0);
            }
            return sel;
        }
        selectie muta_cartea(float clc_x, float clc_y, char c, int kl, int rn, int qv, int qs) {
            //mesaj.setString(std::__cxx11::to_string(kl));
            sel.set_afiseaza(0);
            //verifica daca s-a facut clic pe free cell 0
            if(free_cell_k[0] == 0) {
                //mutarea se face daca nu exista carte in free cell 0
                if(clc_x >= free_cell_poz[0][0] && clc_x <= free_cell_poz[0][0] + 69.f * 2.f && clc_y >= free_cell_poz[0][1] && clc_y <= free_cell_poz[0][1] + 94.f * 1.9f) {
                    //cartea este din una dintre coloane
                    if(c == 'c') {
                        //preia cartea in free cel
                        free_cell_k[0] = 1;
                        free_cell[0] = coloana[kl][rn];
                        //elimina cartea din coloana
                        carte qrt;
                        coloana[kl][rn] = qrt;
                        col_k[kl] -= 1;
                    }
                    //cartea este dintr-o alta free cell
                    if(c == 'f' && kl != 0) {
                        //preia cartea in acest free cel
                        free_cell_k[0] = 1;
                        free_cell[0] = free_cell[kl];
                        //elimina cartea din free cel
                        carte qrt;
                        free_cell[kl] = qrt;
                        free_cell_k[kl] = 0;
                    }
                }
            }
            //verifica daca s-a facut clic pe free cell 1
            if(free_cell_k[1] == 0) {
                //mutarea se face daca nu exista carte in free cell 1
                if(clc_x >= free_cell_poz[1][0] && clc_x <= free_cell_poz[1][0] + 69.f * 2.f && clc_y >= free_cell_poz[1][1] && clc_y <= free_cell_poz[1][1] + 94.f * 1.9f) {
                    //cartea este din una dintre coloane
                    if(c == 'c') {
                        //preia cartea in free cel
                        free_cell_k[1] = 1;
                        free_cell[1] = coloana[kl][rn];
                        //elimina cartea din coloana
                        carte qrt;
                        coloana[kl][rn] = qrt;
                        col_k[kl] -= 1;
                    }
                    //cartea este dintr-o alta free cell
                    if(c == 'f' && kl != 1) {
                        //preia cartea in acest free cel
                        free_cell_k[1] = 1;
                        free_cell[1] = free_cell[kl];
                        //elimina cartea din free cel
                        carte qrt;
                        free_cell[kl] = qrt;
                        free_cell_k[kl] = 0;
                    }
                }
            }
            //verifica daca s-a facut clic pe free cell 2
            if(free_cell_k[2] == 0) {
                //mutarea se face daca nu exista carte in free cell 2
                if(clc_x >= free_cell_poz[2][0] && clc_x <= free_cell_poz[2][0] + 69.f * 2.f && clc_y >= free_cell_poz[2][1] && clc_y <= free_cell_poz[2][1] + 94.f * 1.9f) {
                    //cartea este din una dintre coloane
                    if(c == 'c') {
                        //preia cartea in free cel
                        free_cell_k[2] = 1;
                        free_cell[2] = coloana[kl][rn];
                        //elimina cartea din coloana
                        carte qrt;
                        coloana[kl][rn] = qrt;
                        col_k[kl] -= 1;
                    }
                    //cartea este dintr-o alta free cell
                    if(c == 'f' && kl != 2) {
                        //preia cartea in acest free cel
                        free_cell_k[2] = 1;
                        free_cell[2] = free_cell[kl];
                        //elimina cartea din free cel
                        carte qrt;
                        free_cell[kl] = qrt;
                        free_cell_k[kl] = 0;
                    }
                }
            }
            //verifica daca s-a facut clic pe free cell 3
            if(free_cell_k[3] == 0) {
                //mutarea se face daca nu exista carte in free cell 3
                if(clc_x >= free_cell_poz[3][0] && clc_x <= free_cell_poz[3][0] + 69.f * 2.f && clc_y >= free_cell_poz[3][1] && clc_y <= free_cell_poz[3][1] + 94.f * 1.9f) {
                    //cartea este din una dintre coloane
                    if(c == 'c') {
                        //preia cartea in free cel
                        free_cell_k[3] = 1;
                        free_cell[3] = coloana[kl][rn];
                        //elimina cartea din coloana
                        carte qrt;
                        coloana[kl][rn] = qrt;
                        col_k[kl] -= 1;
                    }
                    //cartea este dintr-o alta free cell
                    if(c == 'f' && kl != 3) {
                        //preia cartea in acest free cel
                        free_cell_k[3] = 1;
                        free_cell[3] = free_cell[kl];
                        //elimina cartea din free cel
                        carte qrt;
                        free_cell[kl] = qrt;
                        free_cell_k[kl] = 0;
                    }
                }
            }
            //verifica daca s-a facut clic pe baza 0
            if(qs == 0 && ((baza_k[0] == 0 && qv == 0) || (baza_k[0] == 1 && baza[0].da_valoare() + 1 == qv))) {
                //mutarea se face daca se respecta simbolul, iar cartea este urmatoarea valoare
                if(clc_x >= baza_poz[0][0] && clc_x <= baza_poz[0][0] + 69.f * 2.f && clc_y >= baza_poz[0][1] && clc_y <= baza_poz[0][1] + 94.f * 1.9f) {
                    //cartea este din una dintre coloane
                    if(c == 'c') {
                        //preia cartea in baza
                        baza_k[0] = 1;
                        baza[0] = coloana[kl][rn];
                        //elimina cartea din coloana
                        carte qrt;
                        coloana[kl][rn] = qrt;
                        col_k[kl] -= 1;
                    }
                    //cartea este dintr-o free cell
                    if(c == 'f') {
                        //preia cartea in baz
                        baza_k[0] = 1;
                        baza[0] = free_cell[kl];
                        //elimina cartea din free cell
                        carte qrt;
                        free_cell[kl] = qrt;
                        free_cell_k[kl] = 0;
                    }
                }
            }
            //verifica daca s-a facut clic pe baza 1
            if(qs == 1 && ((baza_k[1] == 0 && qv == 0) || (baza_k[1] == 1 && baza[1].da_valoare() + 1 == qv))) {
                //mutarea se face daca se respecta simbolul, iar cartea este urmatoarea valoare
                if(clc_x >= baza_poz[1][0] && clc_x <= baza_poz[1][0] + 69.f * 2.f && clc_y >= baza_poz[1][1] && clc_y <= baza_poz[1][1] + 94.f * 1.9f) {
                    //cartea este din una dintre coloane
                    if(c == 'c') {
                        //preia cartea in baza
                        baza_k[1] = 1;
                        baza[1] = coloana[kl][rn];
                        //elimina cartea din coloana
                        carte qrt;
                        coloana[kl][rn] = qrt;
                        col_k[kl] -= 1;
                    }
                    //cartea este dintr-o free cell
                    if(c == 'f') {
                        //preia cartea in baz
                        baza_k[1] = 1;
                        baza[1] = free_cell[kl];
                        //elimina cartea din free cell
                        carte qrt;
                        free_cell[kl] = qrt;
                        free_cell_k[kl] = 0;
                    }
                }
            }
            //verifica daca s-a facut clic pe baza 0
            if(qs == 2 && ((baza_k[2] == 0 && qv == 0) || (baza_k[2] == 1 && baza[2].da_valoare() + 1 == qv))) {
                //mutarea se face daca se respecta simbolul, iar cartea este urmatoarea valoare
                if(clc_x >= baza_poz[2][0] && clc_x <= baza_poz[2][0] + 69.f * 2.f && clc_y >= baza_poz[2][1] && clc_y <= baza_poz[2][1] + 94.f * 1.9f) {
                    //cartea este din una dintre coloane
                    if(c == 'c') {
                        //preia cartea in baza
                        baza_k[2] = 1;
                        baza[2] = coloana[kl][rn];
                        //elimina cartea din coloana
                        carte qrt;
                        coloana[kl][rn] = qrt;
                        col_k[kl] -= 1;
                    }
                    //cartea este dintr-o free cell
                    if(c == 'f') {
                        //preia cartea in baz
                        baza_k[2] = 1;
                        baza[2] = free_cell[kl];
                        //elimina cartea din free cell
                        carte qrt;
                        free_cell[kl] = qrt;
                        free_cell_k[kl] = 0;
                    }
                }
            }
            //verifica daca s-a facut clic pe baza 3
            if(qs == 3 && ((baza_k[3] == 0 && qv == 0) || (baza_k[3] == 1 && baza[3].da_valoare() + 1 == qv))) {
                //mutarea se face daca se respecta simbolul, iar cartea este urmatoarea valoare
                if(clc_x >= baza_poz[3][0] && clc_x <= baza_poz[3][0] + 69.f * 2.f && clc_y >= baza_poz[3][1] && clc_y <= baza_poz[3][1] + 94.f * 1.9f) {
                    //cartea este din una dintre coloane
                    if(c == 'c') {
                        //preia cartea in baza
                        baza_k[3] = 1;
                        baza[3] = coloana[kl][rn];
                        //elimina cartea din coloana
                        carte qrt;
                        coloana[kl][rn] = qrt;
                        col_k[kl] -= 1;
                    }
                    //cartea este dintr-o free cell
                    if(c == 'f') {
                        //preia cartea in baz
                        baza_k[3] = 1;
                        baza[3] = free_cell[kl];
                        //elimina cartea din free cell
                        carte qrt;
                        free_cell[kl] = qrt;
                        free_cell_k[kl] = 0;
                    }
                }
            }
            //verifica daca s-a facut clic pe coloana
            for(int nkl=0; nkl<8; nkl++) {
                if(clc_x >= col_poz[nkl][1][0] && clc_x <= col_poz[nkl][1][0] + 69.f * 2.f && clc_y >= col_poz[nkl][0][1] && clc_y <= col_poz[nkl][14][1] + 94.f * 1.9f) {
                    mesaj.setString(std::__cxx11::to_string(col_k[nkl]));
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
                            carte qrt;
                            coloana[kl][rn] = qrt;
                            col_k[kl] -= 1;
                        }
                        if(c == 'f') {
                            coloana[nkl][col_k[nkl]-1] = free_cell[kl];
                            //elimina cartea din free cell
                            carte qrt;
                            free_cell[kl] = qrt;
                            free_cell_k[kl] = 0;
                        }
                    }
                }
            }
            return sel;
        }
};

//initializeaza tabla de joc
tabla tb;

void afiseaza_tabla(int mod) {
    //afiseaza fereastra cu imaginea de fundal
    window.clear();
    window.draw(sp_fundal);
    //afiseaza riga
    if(mod==0) {
        window.draw(sp_riga);
    }
    if(mod==1) {
        window.draw(sp_riga2);
    }
    //afiseaza free cell
    for(int x=0; x<4; x++) {
        //daca exista carte
        if(tb.free_cell_k[x] == 1) {
            carte ktmp = tb.free_cell[x];
            int kord = ktmp.da_valoare() * 4 + ktmp.da_simbol();
            sp_afis[kord].setPosition(tb.free_cell_poz[x][0], tb.free_cell_poz[x][1]);
            window.draw(sp_afis[kord]);
        }
    }
    //afiseaza baza
    for(int x=0; x<4; x++) {
        //daca exista carte
        if(tb.baza_k[x] == 1) {
            carte ktmp = tb.baza[x];
            int kord = ktmp.da_valoare() * 4 + ktmp.da_simbol();
            sp_afis[kord].setPosition(tb.baza_poz[x][0], tb.baza_poz[x][1]);
            window.draw(sp_afis[kord]);
        }
    }
    //afiseaza coloanele
    //for(int i=0; i<52; i++) {
    //    window.draw(sp_af[i]);
    //}
    for(int x=0; x<8; x++) {
        for(int y=0; y<tb.col_k[x]; y++) {
            //citeste valoarea cartii si ii stabileste ordinea in pachetul de carti
            carte ktmp = tb.coloana[x][y];
            int kord = ktmp.da_valoare() * 4 + ktmp.da_simbol();
            sp_afis[kord].setPosition(tb.col_poz[x][y][0], tb.col_poz[x][y][1]);
            window.draw(sp_afis[kord]);
        }
    }
    //afiseaza selectia
    if(sel.da_afiseaza() == 1) {
        sp_sel.setPosition(float(sel.da_x()), float(sel.da_y()));
        window.draw(sp_sel);
    }
    //mesaj de verificare carti
    /*
    int kq;
    carte w;
    w = p.da_cartea(51);
    kq = w.da_valoare() * 4 + w.da_simbol();
    mesaj.setString(std::__cxx11::to_string(kq));
    */
    window.draw(mesaj);
    window.display();
}

int main()
{
    //simboluri pentru carti
    simboluri inima(0, 'i', 'r');
    simboluri frunza(1, 'f', 'n');
    simboluri romb(2, 'r', 'r');
    simboluri trefla(3, 't', 'n');
    //valori pentru carti
    valori as(0, 'A');
    valori doi(1, '2');
    valori trei(2, '3');
    valori patru(3, '4');
    valori cinci(4, '5');
    valori sase(5, '6');
    valori sapte(6, '7');
    valori opt(7, '8');
    valori noua(8, '9');
    valori zece(9, '1');
    valori juvete(10, 'J');
    valori dama(11, 'Q');
    valori popa(12, 'K');
    //pozitia de citire din imaginea de baza pentru fiecare carte selectata
    int poz_carte_s[13][4][2] = {
        {{632,564}, {632,656}, {632,472}, {632,380} },
        {{703,564}, {703,656}, {703,472}, {703,380} },
        {{774,564}, {774,656}, {774,472}, {774,380} },
        {{845,564}, {845,656}, {845,472}, {845,380} },
        {{916,564}, {916,656}, {916,472}, {916,380} },
        {{987,564}, {987,656}, {987,472}, {987,380} },
        {{1058,564},{1058,656},{1058,472},{1058,380}},
        {{1129,564},{1129,656},{1129,472},{1129,380}},
        {{1200,564},{1200,656},{1200,472},{1200,380}},
        {{1271,564},{1271,656},{1271,472},{1271,380}},
        {{1342,564},{1342,656},{1342,472},{1342,380}},
        {{1413,564},{1413,656},{1413,472},{1413,380}},
        {{1484,564},{1484,656},{1484,472},{1484,380}}
    };

    //sf::String sCarti;
    
    //amesteca pachetul de carti
    srand(time(0));
    p.amesteca();
    //imparte cartile pe coloane
    for(int i = 0; i < 52; i++) {
        int nCol, nRnd;
        nCol = i % 8;
        nRnd = i / 8;
        tb.coloana[nCol][nRnd] = p.da_cartea(i);
        //sCarti.insert(0,std::__cxx11::to_string(p.da_cartea(i).da_simbol()));
        //sCarti.insert(0,std::__cxx11::to_string(p.da_cartea(i).da_valoare()));
        //sCarti.insert(0,' ');
    }
    //mesaj.setString(sCarti);

    initializare();

    afiseaza_tabla(0);

    //modul de lucru se defineste prin valorile
    // 's' - selecteaza cartea pe care se face clic
    // 'm' - muta cartea selectata pe pozitia pe care s-a facut clic
    char mod_lucru = 's';

    int dr = 0;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (sf::Mouse::getPosition(window).x > 632) {
            dr = 1;
            afiseaza_tabla(dr);
        }
        else {
            dr = 0;
            afiseaza_tabla(dr);
        }

        /*
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            // left click...
            //sf::Mouse::setPosition(sf::Vector2i(100, 200), window);

        }
        */

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {   //clic dreapta
            //citeste pozitia mausului
            //identifica cartea selectata
            switch(mod_lucru) {
                case 's':
                    //mesaj.setString("Mod selectare");
                    sel = tb.identifica_selectie(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
                    afiseaza_tabla(dr);
                    if(sel.da_afiseaza() == 1) mod_lucru = 'm';
                    while(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                        //asteapta eliberarea mausului
                    }
                break;
                case 'm':
                    //mesaj.setString("Mod mutare");
                    //identifica cartea selectata
                    carte k_sel;
                    if(sel.da_categoria() == 'c') k_sel = tb.coloana[sel.da_coloana()][sel.da_rand()];
                    if(sel.da_categoria() == 'f') k_sel = tb.free_cell[sel.da_coloana()];
                    //identifica pozitia in care muta cartea selectata
                    sel = tb.muta_cartea(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y, sel.da_categoria(), sel.da_coloana(), sel.da_rand(), k_sel.da_valoare(), k_sel.da_simbol());
                    afiseaza_tabla(dr);
                    if(sel.da_afiseaza() == 0) mod_lucru = 's';
                    while(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                        //asteapta eliberarea mausului
                    }
                break;
            }
        }


    }

    return 0;
}
