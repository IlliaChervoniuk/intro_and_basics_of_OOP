#include "Laptop.h"
#include <format>
#include <iostream>

std::string Laptop::getHardware() const {
    return hardware;
}

Laptop* Laptop::setHardware(std::string hardware) {
    this->hardware = hardware;
    return this;  // "fluent interface" - каскадне встановлення властивостей
}

std::string Laptop::toString() const {
    return std::format("{} {} hrn, {} ({} W)",
        getName(),
        getPrice(),
        hardware,
        getPower()
    );
}

std::ostream& operator <<(std::ostream& out, const Laptop& obj) {
    out << obj.toString();
    return out;
}
std::ostream& operator <<(std::ostream& out, const Laptop* obj) {
    out << *obj;
    return out;
}



/*
Type obj; -- об'єкт статичного типу, розміщується у стеку,
       створюється оголошенням (окремої команди не треба)
obj.method(); -- виклик методу об'єкта
знищується (запускається деструктор) при завершенні функції
       (при руйнуванні стеку), окремої команди не треба

Type *ptr; -- покажчик, що може зберігати адресу об'єкта типу Type
       на момент оголошення самого об'єкту немає, а значення ptr випадкове.
ptr = new Type;
ptr = new Type; -- створення об'єкту у "купі" та одержання його адреси[span_0](start_span)[span_0](end_span)
ptr->method(); -- виклик методу об'єкта через покажчик на нього[span_1](start_span)[span_1](end_span)
при завершенні функції звільняється місце для ptr, але не сам об'єкт[span_2](start_span)[span_2](end_span)
need command :
delete ptr; -- звільнити пам'ять, що виділена під об'єкт

func2(int& x){
    x = 20;
    int y = 10;
    return y;
}


func(int x) {
    Type *ptr;
    x = 20;
    ptr = new Type; ----> <Type>   2.1. Виділення пам'яті у купі (поза стеком)
    delete ptr; ----X---/   |   2.2. Звільнення виділеної пам'яті
    return; -\              |   3. Завершення функції вилучає зі стеку запис про її роботу
}           X              |       але ніяк не впливає на купу
main() {    \ stack        |
    func(1); --> [x, ptr]<-----|   1. Запуск функції додає до стеку "запис" з усіма
    {...}                  |      змінними, що потрібні для роботи функції
    int y = 10;
    func(y); --->[x, ptr]     y would stay the same
    func2(y); ---->[&x, ptr, y]
}

Витік пам'яті (memory leakage) – ефект збільшення пам'яті, виділеної для
програми, у процесі її роботи через неправильне (забуте) звільнення
попередньо виділених ділянок пам'яті
*/


