#include <iostream>
#include <vector>

bool validMountainArray(std::vector<int>& arr) {
    int n = arr.size();
    
    if (n < 3) {
        return false;
    }
    
    int i = 0;
    
     while (i < n - 1 && arr[i] < arr[i + 1]) {
        i++;
    }
    
     if (i == 0 || i == n - 1) {
        return false;
    }
    
     while (i < n - 1 && arr[i] > arr[i + 1]) {
        i++;
    }
    
     return i == n - 1;
}

int main() {
    std::vector<int> arr = {2, 1};
    bool result = validMountainArray(arr);
    std::cout << std::boolalpha << result << std::endl; // Output: false

    return 0;
}
