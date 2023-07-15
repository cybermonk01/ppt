#include <iostream>

int power(int N, int P) {
    int result = 1;
    for (int i = 0; i < P; ++i) {
        result *= N;
    }
    return result;
}

int main() {
    int N1 = 5, P1 = 2;
    int N2 = 2, P2 = 5;

    std::cout << "Output 1: " << power(N1, P1) << std::endl; 
    std::cout << "Output 2: " << power(N2, P2) << std::endl; 

    return 0;
}
