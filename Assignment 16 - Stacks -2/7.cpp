#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int countWordsLeft(const vector<string>& words) {
    stack<string> st;

    for (const string& word : words) {
        if (!st.empty() && st.top() == word) {
            st.pop();
        } else {
            st.push(word);
        }
    }

    return st.size();
}

int main() {
    string input = "ab aa aa bcd ab";

     stringstream ss(input);
    string word;
    vector<string> words;

    while (ss >> word) {
        words.push_back(word);
    }

    int wordsLeft = countWordsLeft(words);

    cout << "Number of words left: " << wordsLeft << endl;

    return 0;
}
