#include <iostream>

int findNthTerm(int a, int d, int N) {
    return a + (N - 1) * d;
}

int main() {
    int a1 = 2, d1 = 1, N1 = 5;
    int a2 = 5, d2 = 2, N2 = 10;

    std::cout << "Output 1: " << findNthTerm(a1, d1, N1) << std::endl; 
    std::cout << "Output 2: " << findNthTerm(a2, d2, N2) << std::endl;  

    return 0;
}
