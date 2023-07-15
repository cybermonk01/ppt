#include <iostream>

int towerOfHanoi(int N, char from_rod, char to_rod, char aux_rod) {
    if (N == 1) {
        std::cout << "move disk 1 from rod " << from_rod << " to rod " << to_rod << std::endl;
        return 1;
    }

    int moves = 0;

     moves += towerOfHanoi(N - 1, from_rod, aux_rod, to_rod);

     std::cout << "move disk " << N << " from rod " << from_rod << " to rod " << to_rod << std::endl;
    ++moves;

     moves += towerOfHanoi(N - 1, aux_rod, to_rod, from_rod);

    return moves;
}

int main() {
    int N = 2;

    std::cout << "Output:" << std::endl;
    int totalMoves = towerOfHanoi(N, '1', '3', '2');
    std::cout << totalMoves << std::endl;

    return 0;
}
