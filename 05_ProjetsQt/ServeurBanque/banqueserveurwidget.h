#ifndef BANQUESERVEURWIDGET_H
#define BANQUESERVEURWIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class BanqueServeurWidget; }
QT_END_NAMESPACE

class BanqueServeurWidget : public QWidget
{
    Q_OBJECT

public:
    BanqueServeurWidget(QWidget *parent = nullptr);
    ~BanqueServeurWidget();

private:
    Ui::BanqueServeurWidget *ui;
};
#endif // BANQUESERVEURWIDGET_H
