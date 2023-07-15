#include <iostream>
#include <vector>

bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
    int m = matrix.size();
    int n = matrix[0].size();
    
    int left = 0, right = m * n - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        int midValue = matrix[mid / n][mid % n];
        
        if (midValue == target) {
            return true;
        } else if (midValue < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return false;
}

int main() {
    std::vector<std::vector<int>> matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };
    int target = 3;
    
    bool result = searchMatrix(matrix, target);
    std::cout << std::boolalpha << result << std::endl; // Output: true

    return 0;
}
