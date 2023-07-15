#include <iostream>
#include <vector>

std::vector<std::vector<int>> transposeMatrix(const std::vector<std::vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    std::vector<std::vector<int>> transpose(cols, std::vector<int>(rows));

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            transpose[j][i] = matrix[i][j];
        }
    }

    return transpose;
}

int main() {
    std::vector<std::vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    std::vector<std::vector<int>> transpose = transposeMatrix(matrix);

    std::cout << "Output: [";
    for (int i = 0; i < transpose.size(); ++i) {
        std::cout << "[";
        for (int j = 0; j < transpose[i].size(); ++j) {
            std::cout << transpose[i][j];
            if (j < transpose[i].size() - 1) {
                std::cout << ", ";
            }
        }
        std::cout << "]";
        if (i < transpose.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;

    return 0;
}
