
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
