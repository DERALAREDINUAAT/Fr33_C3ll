class selectie {
    private:
        char categorie; // 'f'-free cell, 'b'-baza, 'c'-coloana
        int c;
        int r; //indicele de coloana, respectiv rand al selectiei. Pentru free cell indicele de rand nu conteaza, este 0.
        int x;
        int y; //pozitia de afisare a selectiei
        int afiseaza; //daca chenarul de selectare trebuie afisat
        int terminat; //ia valoarea 1 cand jocul a fost incheiat cu succes
    public:
        selectie() {
            categorie = 'f';
            c = 0;
            r = 0;
            x = 20;
            y = 70;
            afiseaza = 0;
            terminat = 0;
        }
        selectie(char categ, int cx, int cy, int afx, int afy, int af, int t) {
            categorie = categ;
            c = cx;
            r = cy;
            x = afx;
            y = afy;
            afiseaza = af;
            terminat = t;
        }
        selectie(const selectie &q) {
            categorie = q.categorie;
            c = q.c;
            r = q.r;
            x = q.x;
            y = q.y;
            afiseaza = q.afiseaza;
            terminat = q.terminat;
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
            terminat = q.terminat;
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
            if (poz_x + 71 > 1300 || poz_y + 96 > 920) {
                err_pozitie epoz;
                throw epoz;
            }
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
        int da_terminat() {
            return terminat;
        }
        void set_terminat(int t) {
            terminat = t;
        }
};

class difficulty {
    private:
        int dificultate;
    public:
        difficulty() {
            dificultate = 0;
        }
        difficulty(int diff) {
            if (diff > 3) {
                err_diff ediff;
                throw ediff;
            }
            dificultate = diff;
        }
        virtual difficulty *Clone() = 0;
        virtual ~difficulty() {}
        virtual int da_dificultate() = 0;
};

class difficulty0: public difficulty {
    private:
    public:
        difficulty0(): difficulty(0) {} 
        explicit difficulty0(int diff): difficulty(diff) {} 
        difficulty0 *Clone() override {
            return new difficulty0(*this);
        } 
        ~difficulty0() override {}
        virtual int da_dificultate() override {
            return 0;
        } 
};

class difficulty1: public difficulty0 {
    private:
    public:
        difficulty1(): difficulty0(1) {} 
        explicit difficulty1(int diff): difficulty0(diff) {}
        difficulty1 *Clone() override {
            return new difficulty1(*this);
        } 
        ~difficulty1() override {}
        int da_dificultate() override {
            return 1;
        } 
};

class difficulty2: public difficulty1 {
    private:
    public:
        difficulty2(): difficulty1(2) {}
        explicit difficulty2(int diff): difficulty1(diff) {}
        difficulty2 *Clone() override {
            return new difficulty2(*this);
        } 
        ~difficulty2() override {}
        int da_dificultate() override {
            return 2;
        } 
};

class difficulty3: public difficulty2 {
    private:
    public:
        difficulty3(): difficulty2(3) {} 
        explicit difficulty3(int diff): difficulty2(diff) {}
        difficulty3 *Clone() override {
            return new difficulty3(*this);
        } 
        ~difficulty3() override {}
        int da_dificultate() override {
            return 3;
        } 
};
