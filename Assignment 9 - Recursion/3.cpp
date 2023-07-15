#include <iostream>

int factorial(int N) {
    int result = 1;
    for (int i = 1; i <= N; ++i) {
        result *= i;
    }
    return result;
}

int main() {
    int N1 = 5;
    int N2 = 4;

    std::cout << "Output 1: " << factorial(N1) << std::endl;  
    std::cout << "Output 2: " << factorial(N2) << std::endl; 

    return 0;
}
