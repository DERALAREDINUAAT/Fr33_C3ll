
class carton {
    protected:
        int valoare;
    public:
        carton() {
            valoare = 0;
        }
        explicit carton(int v) {
            valoare = v;
        }
        void set_valoare(int v) {
            valoare = v;
        }
};

class carte: public carton {
    //carton cu simbol = carte de inima, frunza, romb sau trefla
    private:
        int simbol;
    public:
        carte() {
            simbol = 0;
        }
        carte(int s, int v): carton(v) {
            simbol = s;
        }
        carte(const carte &q): carton(q.valoare) {
            simbol = q.simbol;
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
            simbol = q.simbol;
            carton::set_valoare(q.valoare);
        }
        int da_simbol() {
            return simbol;
        }
        int da_valoare() {
            return valoare;
        }
        void set_simbol(int s) {
            simbol = s;
        }
        carte da_carte() {
            return *this;
        }
};

class pachet: public carte {
    private:
        int ord_i[13][4], ord[13][4];
        carte k[4][13];
        static const int nrCartiPachet = 52;
        static const int nrCartiCalup1 = 20;
        static const int nrcartiCalup2 = 36;
        void amesteca_calup(int dela, int panala) {
            for(int i=dela; i<panala; i++) {
                int marja = panala - i;
                int al = rand() % marja;
                int aux = ord[i / 4][i % 4];
                ord[i / 4][i % 4] = ord[(al + i) / 4][(al + i) % 4];
                ord[(al + i) / 4][(al + i) % 4] = aux;
            }
        }
        void inverseaza_calup(int dela, int panala) {
            for(int i=dela; i<panala; i++) {
                int aux = ord[i / 4][i % 4];
                ord[i / 4][i % 4] = ord[(51 + dela - i) / 4][(51 + dela - i) % 4];
                ord[(51 + dela - i) / 4][(51 + dela - i) % 4] = aux;
            }
        }
    public:
        pachet() {
            int o = 0;
            for(int i=0; i<13; i++) {
                for(int j=0; j<4; j++) {
                    ord_i[i][j] = o;
                    ord[i][j] = o;
                    carton::set_valoare(i);
                    carte::set_simbol(j);
                    k[j][i] = carte::da_carte();
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
        void amesteca(int dificultate) {
            switch(dificultate) {
            case 0:
                amesteca_calup(0, nrCartiPachet);
                break;
            case 1:
                amesteca_calup(0, nrCartiCalup1);
                amesteca_calup(nrCartiCalup1, nrcartiCalup2);
                amesteca_calup(nrcartiCalup2, nrCartiPachet);
                inverseaza_calup(0, nrCartiPachet / 2);
                break;
            case 2:
                amesteca_calup(0, nrCartiCalup1);
                amesteca_calup(nrCartiCalup1, nrcartiCalup2);
                amesteca_calup(nrcartiCalup2, nrCartiPachet);
                break;
            case 3:
                amesteca_calup(0, nrCartiCalup1);
                amesteca_calup(nrCartiCalup1, nrcartiCalup2);
                amesteca_calup(nrcartiCalup2, nrCartiPachet);
                inverseaza_calup(nrCartiCalup1, nrcartiCalup2);
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
            carton::set_valoare(v);
            carte::set_simbol(s);
            carte g = carte::da_carte();
            return g;
        }
};
