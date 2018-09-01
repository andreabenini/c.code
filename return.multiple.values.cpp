#include <utility>
#include <iostream>
#include <tuple>            // C++11, for std::tie

std::pair<double, double> foo() {
    return std::make_pair(42., 3.14);
}
int main() {
    std::pair<double, double> p = foo();
    std::cout << p.first << ", " << p.second << std::endl;

    // C++11: use std::tie to unpack into pre-existing variables
    double x, y;
    std::tie(x,y) = foo();
    std::cout << x << ", " << y << std::endl;

    // C++17: structured bindings
    auto [xx, yy] = foo(); // xx, yy are double
}
