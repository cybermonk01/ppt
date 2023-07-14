#include <iostream>
#include <vector>

using namespace std;

int countStudents(vector<int>& students, vector<int>& sandwiches) {
    int n = students.size();
    int m = sandwiches.size();

    int count[2] = {0};

    for (int i = 0; i < n; i++) {
        count[students[i]]++;
    }

    int served = 0;
    for (int i = 0; i < m; i++) {
        if (count[sandwiches[i]] > 0) {
            count[sandwiches[i]]--;
            served++;
        } else {
            break;
        }
    }

    return n - served;
}

int main() {
    vector<int> students = {1,1,0,0};
    vector<int> sandwiches = {0,1,0,1};

    int unableToEat = countStudents(students, sandwiches);

    cout << unableToEat << endl;

    return 0;
}
