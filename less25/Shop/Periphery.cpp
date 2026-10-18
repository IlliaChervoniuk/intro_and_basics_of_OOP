#include "Periphery.h"

std::string Periphery::getConnection() const {
    return connection;
}

Periphery * Periphery::setConnection(std::string conection) {
    this->connection = conection;
    return this;
}
