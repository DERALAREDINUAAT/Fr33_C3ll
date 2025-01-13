
class err_load: public std::exception {
    private:
        int cod;
    public:
        err_load() {
            cod = 0;
        }
        virtual const char* what() const throw() {
            switch(cod) {
                case 0:
                    return "Eroare necunoscuta";
                    break;
                case 1:
                    return "Eroare - nu a putut fi incarcat fisierul text ";
                    break;
                case 2:
                    return "Eroare - nu a putut fi incarcata imaginea ";
                    break;
                case 3:
                    return "Eroare - nu a putut fi incarcat fontul ";
                    break;
            }
            return "Eroare necunoscuta";
        }

        void set_cod(int k) {
            cod = k;
        }
};

class err_diff: public std::exception {
    private:
    public:
        virtual const char* what() const throw() {
            return "Eroare - dificultatea aleasa are o valoare nepermisa, este prea mare!";
        }
};

class err_pozitie: public std::exception {
    private:
    public:
        virtual const char* what() const throw() {
            return "Eroare - Selectia este in afara ecranului!";
        }
};
