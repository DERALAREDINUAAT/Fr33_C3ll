class scor {
    protected:
        int scorul;
        int scor_mutari_baza; //se incrementeaza cu fiecare carte adaugata in baza
        int scor_mutari; //se decrementeaza la fiecare 10 mutari
        int scor_timp; // se decrementeaza la fiecare 30 secunde
        int scor_amestecare; //se determina initial si amplifica incrementarea scorului dupa numarul de mutari in baza
    public:
        scor() {
            scorul = 0;
            scor_mutari_baza = 0;
            scor_mutari = 100;
            scor_timp = 200;
            scor_amestecare = 1;
        }
        int da_scorul() {
            return scorul;
        }
        void calculeaza_scor(){
            scorul = scor_mutari_baza * scor_amestecare + scor_mutari + scor_timp;
        }
};

class scor_dupa_grad_amestecare_pachet : public scor {
    protected:
        int grad_amestecare;
    public:
        scor_dupa_grad_amestecare_pachet() {
            grad_amestecare = 1;
        }
        void set_grad_amestecare(int i) {
            grad_amestecare = i;
            scor_amestecare = grad_amestecare;
        }
};


class scor_dupa_timp : public scor_dupa_grad_amestecare_pachet {
    private:
        time_t moment_reper;
        int durata;
    public:
        scor_dupa_timp() {
            moment_reper = 0;
            durata = 0;
        }
        void set_moment_reper() {
            moment_reper = time(NULL);
            durata = 0;
        }
        void incremenreaza_timp() {
            time_t moment_actual;
            moment_actual = time(NULL);
            durata = difftime(moment_actual, moment_reper);
            scor_timp = 200 - durata / 30;
        }
};

class scor_dupa_mutari : public scor_dupa_timp {
    private:
        int numar_mutari;
    public:
        scor_dupa_mutari() {
            numar_mutari = 0;
        }
        void incr_mutari() {
            numar_mutari += 1;
            scor_mutari = 100 - numar_mutari / 10;
        }
        void incr_mutari_baza() {
            scor_mutari_baza += 1;
        }
} skm;
