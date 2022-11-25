#ifndef PORTE_H
#define PORTE_H

#include <QWidget>

namespace Ui {
class Porte;
}

class Porte : public QWidget
{
    Q_OBJECT

public:
    explicit Porte(QWidget *parent = nullptr);
    ~Porte();
    void devreouiller();
    void verouiller();

private:
    Ui::Porte *ui;
    // Digicode laPorte;
};

#endif // PORTE_H
