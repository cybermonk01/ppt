#include <iostream>
#include <stack>

using namespace std;

int reverseNumber(int num) {
    stack<int> st;
    while (num > 0) {
        int digit = num % 10;
        st.push(digit);
        num /= 10;
    }

    int reverseNum = 0;
    int multiplier = 1;

    while (!st.empty()) {
        reverseNum += st.top() * multiplier;
        st.pop();
        multiplier *= 10;
    }

    return reverseNum;
}

int main() {
    int num1 = 365;
    int num2 = 6899;

    int reverse1 = reverseNumber(num1);
    int reverse2 = reverseNumber(num2);

    cout << "Input: " << num1 << endl;
    cout << "Output: " << reverse1 << endl;

    cout << "Input: " << num2 << endl;
    cout << "Output: " << reverse2 << endl;

    return 0;
}

