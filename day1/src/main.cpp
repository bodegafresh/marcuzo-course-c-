#include <rxcpp/rx.hpp>
#include <iostream>
using namespace rxcpp;

int main() {
    auto observable = rxcpp::observable<>::from(10, 20, 30, 40);

    observable.subscribe(
        [](int value) { std::cout << "Next: " << value << std::endl; },
        []() { std::cout << "Completed!" << std::endl; }
    );

    return 0;
}