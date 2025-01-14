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
