#include <iostream>
#include <vector>

long long int arrayProduct(const std::vector<int>& arr) {
    long long int product = 1;
    for (int num : arr) {
        product *= num;
    }
    return product;
}

int main() {
    std::vector<int> arr1 = {1, 2, 3, 4, 5};
    std::vector<int> arr2 = {1, 6, 3};

    std::cout << "Output 1: " << arrayProduct(arr1) << std::endl; 
    std::cout << "Output 2: " << arrayProduct(arr2) << std::endl; 

    return 0;
}
