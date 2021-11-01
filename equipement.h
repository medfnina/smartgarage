#ifndef EQUIPEMENT_H
#define EQUIPEMENT_H


class equipement
{
    public:
        equipement();
        virtual ~equipement();

        int Getidt() { return idt; }
        void Setidt(int val) { idt = val; }
        int Getposition() { return position; }
        void Setposition(int val) { position = val; }

    protected:

    private:
        int idt;
        int position;
};

#endif // EQUIPEMENT_H
