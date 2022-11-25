#ifndef BOUTONPOUSSOIR_H
#define BOUTONPOUSSOIR_H

#include <QWidget>

namespace Ui {
class BoutonPoussoir;
}

class BoutonPoussoir : public QWidget
{
    Q_OBJECT

public:
    explicit BoutonPoussoir(QWidget *parent = nullptr);
    ~BoutonPoussoir();

private slots:
    void on_pushButtonBP_clicked();

private:
    Ui::BoutonPoussoir *ui;
};

#endif // BOUTONPOUSSOIR_H
