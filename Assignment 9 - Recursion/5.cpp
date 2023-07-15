#include <iostream>
#include <vector>

int findMaxRecursive(const std::vector<int>& arr, int index) {
     if (index == arr.size() - 1) {
        return arr[index];
    }

     int maxRest = findMaxRecursive(arr, index + 1);
    return std::max(arr[index], maxRest);
}

int findMax(const std::vector<int>& arr) {
     return findMaxRecursive(arr, 0);
}

int main() {
    std::vector<int> arr1 = {1, 4, 3, -5, -4, 8, 6};
    std::vector<int> arr2 = {1, 4, 45, 6, 10, -8};

    std::cout << "Output 1: " << findMax(arr1) << std::endl;  
    std::cout << "Output 2: " << findMax(arr2) << std::endl;  

    return 0;
}
