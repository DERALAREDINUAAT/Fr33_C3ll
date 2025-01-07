
class symbol {
    protected:
        int simbol;
    public:
        symbol() {
            simbol = 0;
        }
        symbol(int s) {
            simbol = s;
        }
        void set_simbol(int s) {
            simbol = s;
        }
};

class carte: public symbol {
    private:
        int valoare;
    public:
        carte() {
            valoare = 0;
        }
        carte(int s, int v): symbol(s) {
            valoare = v;
        }
        carte(const carte &q): symbol(q.simbol) {
            valoare = q.valoare;
        }
        ~carte() {

        }
        friend std::ostream& operator<<(std::ostream& os, const carte& kt) {
            switch(kt.valoare) {
            case 0:
                os << "As-";
                break;
            case 1:
                os << "2-";
                break;
            case 2:
                os << "3-";
                break;
            case 3:
                os << "4-";
                break;
            case 4:
                os << "5-";
                break;
            case 5:
                os << "6-";
                break;
            case 6:
                os << "7-";
                break;
            case 7:
                os << "8-";
                break;
            case 8:
                os << "9-";
                break;
            case 9:
                os << "10-";
                break;
            case 10:
                os << "Juvete-";
                break;
            case 11:
                os << "Dama-";
                break;
            case 12:
                os << "Popa-";
                break;
            }
            switch(kt.simbol) {
            case 0:
                os << "inima";
                break;
            case 1:
                os << "frunza";
                break;
            case 2:
                os << "romb";
                break;
            case 3:
                os << "trefla";
                break;
            }
            return os;
        }
        void operator =(const carte &q)  {
            valoare = q.valoare;
            symbol::set_simbol(q.simbol);
        }
        int da_simbol() {
            return simbol;
        }
        int da_valoare() {
            return valoare;
        }
};

class diffic {
    protected:
        int dificultate;
    public:
        diffic() {
            dificultate = 0;
        }
        diffic(int diff) {
            dificultate = diff;
        }
        void set_dificultate(int diff) {
            dificultate = diff;
        }
};

class pachet : public diffic {
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
        friend std::ostream& operator<<(std::ostream& os, const pachet& pk) {
            for(int i=0; i<52; i++) {
                int vo = i / 4;
                int so = i % 4;
                int o = pk.ord[vo][so];
                int v = o / 4;
                int s = o % 4;
                os << pk.k[s][v] << '\n';
            }
            return os;
        }
        void amesteca() {
            switch(dificultate) {
            case 0:
                for(int i=0; i<52; i++) {
                    int marja = 52 - i;
                    int al = rand() % marja;
                    int aux = ord[i / 4][i % 4];
                    ord[i / 4][i % 4] = ord[(al + i) / 4][(al + i) % 4];
                    ord[(al + i) / 4][(al + i) % 4] = aux;
                }
                break;
            case 1:
                for(int i=0; i<20; i++) {
                    int marja = 20 - i;
                    int al = rand() % marja;
                    int aux = ord[i / 4][i % 4];
                    ord[i / 4][i % 4] = ord[(al + i) / 4][(al + i) % 4];
                    ord[(al + i) / 4][(al + i) % 4] = aux;
                }
                for(int i=20; i<36; i++) {
                    int marja = 36 - i;
                    int al = rand() % marja;
                    int aux = ord[i / 4][i % 4];
                    ord[i / 4][i % 4] = ord[(al + i) / 4][(al + i) % 4];
                    ord[(al + i) / 4][(al + i) % 4] = aux;
                }
                for(int i=36; i<52; i++) {
                    int marja = 52 - i;
                    int al = rand() % marja;
                    int aux = ord[i / 4][i % 4];
                    ord[i / 4][i % 4] = ord[(al + i) / 4][(al + i) % 4];
                    ord[(al + i) / 4][(al + i) % 4] = aux;
                }
                for(int i=0; i<26; i++) {
                    int aux = ord[i / 4][i % 4];
                    ord[i / 4][i % 4] = ord[(51 - i) / 4][(51 - i) % 4];
                    ord[(51 - i) / 4][(51 - i) % 4] = aux;
                }
                break;
            case 2:
                for(int i=0; i<20; i++) {
                    int marja = 20 - i;
                    int al = rand() % marja;
                    int aux = ord[i / 4][i % 4];
                    ord[i / 4][i % 4] = ord[(al + i) / 4][(al + i) % 4];
                    ord[(al + i) / 4][(al + i) % 4] = aux;
                }
                for(int i=20; i<36; i++) {
                    int marja = 36 - i;
                    int al = rand() % marja;
                    int aux = ord[i / 4][i % 4];
                    ord[i / 4][i % 4] = ord[(al + i) / 4][(al + i) % 4];
                    ord[(al + i) / 4][(al + i) % 4] = aux;
                }
                for(int i=36; i<52; i++) {
                    int marja = 52 - i;
                    int al = rand() % marja;
                    int aux = ord[i / 4][i % 4];
                    ord[i / 4][i % 4] = ord[(al + i) / 4][(al + i) % 4];
                    ord[(al + i) / 4][(al + i) % 4] = aux;
                }
                break;
            case 3:
                for(int i=0; i<20; i++) {
                    int marja = 20 - i;
                    int al = rand() % marja;
                    int aux = ord[i / 4][i % 4];
                    ord[i / 4][i % 4] = ord[(al + i) / 4][(al + i) % 4];
                    ord[(al + i) / 4][(al + i) % 4] = aux;
                }
                for(int i=20; i<36; i++) {
                    int marja = 36 - i;
                    int al = rand() % marja;
                    int aux = ord[i / 4][i % 4];
                    ord[i / 4][i % 4] = ord[(al + i) / 4][(al + i) % 4];
                    ord[(al + i) / 4][(al + i) % 4] = aux;
                }
                for(int i=36; i<52; i++) {
                    int marja = 52 - i;
                    int al = rand() % marja;
                    int aux = ord[i / 4][i % 4];
                    ord[i / 4][i % 4] = ord[(al + i) / 4][(al + i) % 4];
                    ord[(al + i) / 4][(al + i) % 4] = aux;
                }
                for(int i=20; i<36; i++) {
                    int aux = ord[i / 4][i % 4];
                    ord[i / 4][i % 4] = ord[(71 - i) / 4][(71 - i) % 4];
                    ord[(71 - i) / 4][(71 - i) % 4] = aux;
                }
                break;
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
