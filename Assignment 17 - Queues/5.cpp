#include <iostream>
#include <vector>

using namespace std;

int findTheWinner(int n, int k) {
    vector<int> friends(n);
    for (int i = 0; i < n; i++) {
        friends[i] = i + 1;
    }

    int idx = 0;
    while (friends.size() > 1) {
        idx = (idx + k - 1) % friends.size();
        friends.erase(friends.begin() + idx);
    }

    return friends[0];
}

int main() {
    int n = 5;
    int k = 2;

    int winner = findTheWinner(n, k);

    cout << "The winner is: " << winner << endl;

    return 0;
}
