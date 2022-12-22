#ifndef RETRAIT_H
#define RETRAIT_H

#include <QDialog>

namespace Ui {
    class retrait;
}

class retrait : public QDialog {
    Q_OBJECT

    public:
        explicit retrait(QWidget *parent = nullptr);
        ~retrait();

    private:
        Ui::retrait *ui;
};

#endif // RETRAIT_H
