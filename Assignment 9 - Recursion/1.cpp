#include <iostream>

bool isPowerOfTwo(int n) {
    return n > 0 && (n & (n - 1)) == 0;
}

int main() {
    int n1 = 1;
    int n2 = 16;
    int n3 = 3;

    std::cout << "Output 1: " << std::boolalpha << isPowerOfTwo(n1) << std::endl; 
    std::cout << "Output 2: " << std::boolalpha << isPowerOfTwo(n2) << std::endl; 
    std::cout << "Output 3: " << std::boolalpha << isPowerOfTwo(n3) << std::endl; 

    return 0;
}
