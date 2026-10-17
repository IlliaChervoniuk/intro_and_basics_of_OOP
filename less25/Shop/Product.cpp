#include "Product.h"
#include <string>

std::string Product::getName() {
    return name;
}

void Product::setName(std::string name) {
    this->name = name;
}

double Product::getPrice() {
    return price;
}

void Product::setPrice(double price) {
    this->price = price;
}
