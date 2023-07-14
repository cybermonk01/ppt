#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> deckRevealedIncreasing(vector<int>& deck) {
    int n = deck.size();
    sort(deck.begin(), deck.end());

    queue<int> indices;
    for (int i = 0; i < n; i++) {
        indices.push(i);
    }

    vector<int> result(n);
    for (int card : deck) {
        result[indices.front()] = card;
        indices.pop();
        if (!indices.empty()) {
            indices.push(indices.front());
            indices.pop();
        }
    }

    return result;
}

int main() {
    vector<int> deck = {17, 13, 11, 2, 3, 5, 7};

    vector<int> ordering = deckRevealedIncreasing(deck);

    cout << "Ordering: ";
    for (int card : ordering) {
        cout << card << " ";
    }
    cout << endl;

    return 0;
}
