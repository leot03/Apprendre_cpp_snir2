#ifndef ELEMENT_H
#define ELEMENT_H


class Element
{
public:
    Element(const int _vitesse = 1);
    virtual ~Element();
    virtual void Afficher() = 0;

    int getNumero() const;
    void setNumero(const int _numero);
protected:
    int numero;
    double vitesse;

};

#endif // ELEMENT_H
