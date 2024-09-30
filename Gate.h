#ifndef GATE_H
#define GATE_H

#include <QString>

class Gate {
private:
    QString description;
    int password;

public:
    Gate(QString d, int p);
    QString getDescription();
    bool checkPassword(int p);
};

#endif // GATE_H
