#include <iostream>

int sumOfFirstNNaturalNumbers(int n) {
    return (n * (n + 1)) / 2;
}

int main() {
    int n1 = 3;
    int n2 = 5;

    std::cout << "Output 1: " << sumOfFirstNNaturalNumbers(n1) << std::endl;  
    std::cout << "Output 2: " << sumOfFirstNNaturalNumbers(n2) << std::endl; 

    return 0;
}
