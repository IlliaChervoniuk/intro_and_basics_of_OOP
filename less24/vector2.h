#pragma once
#include <iostream>
#include <stdexcept>
#include <string>

template <typename T>
class vector2 {
private:
    T x;
    T y;
    std::string name;

public:
    vector2() : x(0), y(0), name("") {}

    vector2(T x, T y, std::string name = "")
        : x(x), y(y), name(name) {}

    T getX() const { return x; }
    T getY() const { return y; }
    std::string getName() const { return name; }

    void setX(T value) { x = value; }
    void setY(T value) { y = value; }
    void setName(std::string value) { name = value; }

    std::string to_string() const {
        std::string result = "Vector";
        if (name != "") {
            result += " '" + name + "'";
        }
        result += ": (" + std::to_string(x) + ", " + std::to_string(y) + ")";
        return result;
    }

    template <typename U>
    vector2 operator+(const vector2<U>& other) const {
        return vector2(x + static_cast<T>(other.getX()),
                       y + static_cast<T>(other.getY()), name + "+" + other.getName());
    }

    template <typename U>
    vector2 operator-(const vector2<U>& other) const {
        return vector2(x - static_cast<T>(other.getX()),
                       y - static_cast<T>(other.getY()), name + "-" + other.getName());
    }

    template <typename U>
    vector2& operator+=(const vector2<U>& other) {
        x += static_cast<T>(other.getX());
        y += static_cast<T>(other.getY());
        return *this;
    }

    template <typename U>
    vector2& operator-=(const vector2<U>& other) {
        x -= static_cast<T>(other.getX());
        y -= static_cast<T>(other.getY());
        return *this;
    }

    template <typename U>
    vector2 operator*(const vector2<U>& other) const {
        return vector2(x * static_cast<T>(other.getX()),
                       y * static_cast<T>(other.getY()));
    }

    template <typename U>
    vector2 operator/(const vector2<U>& other) const {
        if (other.getX() == 0 || other.getY() == 0) {
            throw std::runtime_error("Cannot divide by zero");
        }
        return vector2(x / static_cast<T>(other.getX()),
                       y / static_cast<T>(other.getY()));
    }

    friend std::ostream& operator<<(std::ostream& out, const vector2& value) {
        out << value.to_string();
        return out;
    }
};
