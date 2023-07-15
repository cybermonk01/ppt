#include <vector>
#include <iostream>

using namespace std;

vector<int> plusOne(vector<int>& digits) {
    int n = digits.size();
    int carry = 1;

    for (int i = n - 1; i >= 0; i--) {
        int sum = digits[i] + carry;
        digits[i] = sum % 10;
        carry = sum / 10;
    }

    if (carry == 1) {
        digits.insert(digits.begin(), 1);
    }

    return digits;
}
int main() {
    vector<int> digits = { 1, 2, 3 };
    vector<int> result = plusOne(digits);

   cout << "Result: ";
    for (int digit : result) {
       cout << digit << " ";
    }

    return 0;
}




