#ifndef MODIFIEDCHECKBOX_H
#define MODIFIEDCHECKBOX_H

#include <QCheckBox>
#include <QObject>

class ModifiedCheckBox : public QCheckBox {
    Q_OBJECT
public:
    int id;
};

#endif // MODIFIEDCHECKBOX_H
