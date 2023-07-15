#include <iostream>
#include <vector>

std::vector<int> findCommonElements(std::vector<int>& arr1, std::vector<int>& arr2, std::vector<int>& arr3) {
    std::vector<int> result;

    int i = 0, j = 0, k = 0;
    while (i < arr1.size() && j < arr2.size() && k < arr3.size()) {
        if (arr1[i] == arr2[j] && arr2[j] == arr3[k]) {
            result.push_back(arr1[i]);
            ++i;
            ++j;
            ++k;
        } else if (arr1[i] <= arr2[j] && arr1[i] <= arr3[k]) {
            ++i;
        } else if (arr2[j] <= arr1[i] && arr2[j] <= arr3[k]) {
            ++j;
        } else {
            ++k;
        }
    }

    return result;
}

int main() {
    std::vector<int> arr1 = {1, 2, 3, 4, 5};
    std::vector<int> arr2 = {1, 2, 5, 7, 9};
    std::vector<int> arr3 = {1, 3, 4, 5, 8};

    std::vector<int> commonElements = findCommonElements(arr1, arr2, arr3);

    std::cout << "Output: [";
    for (int i = 0; i < commonElements.size(); ++i) {
        std::cout << commonElements[i];
        if (i < commonElements.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;

    return 0;
}
