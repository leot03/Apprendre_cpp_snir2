#ifndef ELEMENT_H
#define ELEMENT_H


class Element
{
public:
    Element();
    virtual ~Element();
    virtual void Afficher() = 0;
};

#endif // ELEMENT_H
