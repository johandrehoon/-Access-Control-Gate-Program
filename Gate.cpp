#include "Gate.h"

Gate::Gate(QString d, int p) : description(d), password(p) {}

QString Gate::getDescription() {
    return description;
}

bool Gate::checkPassword(int p) {
    return p == password;
}
