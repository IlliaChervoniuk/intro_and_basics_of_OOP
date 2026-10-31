#include "vector2.h"

int main() {
    vector2<int> first(8, 12, "first");
    vector2<int> second(2, 3, "second");

    std::cout << first + second << '\n';
    std::cout << first - second << '\n';
    std::cout << first * second << '\n';
    std::cout << first / second << '\n';

    vector2<float> third(5.5f, 7.0f, "third");
    vector2<float> fourth(1.5f, 2.0f, "fourth");
    third += fourth;
    std::cout << third << '\n';
    third -= fourth;
    std::cout << third << '\n';

    vector2<double> fifth(3.25, 4.5, "fifth");
    vector2<double> sixth(1.25, 1.5, "sixth");
    std::cout << fifth + sixth << '\n';
    std::cout << fifth / sixth << '\n';

    vector2<double> copy = fifth;
    vector2<double> moved = std::move(copy);
    std::cout << moved << '\n';

    return 0;
}
