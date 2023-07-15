#include <iostream>
#include <vector>

int minimumDeleteSum(string s1, string s2) {
    int m = s1.size();
    int n = s2.size();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + static_cast<int>(s1[i - 1]);
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    int asciiSum = 0;
    for (char c : s1) {
        asciiSum += static_cast<int>(c);
    }
    for (char c : s2) {
        asciiSum += static_cast<int>(c);
    }

    int lcsSum = dp[m][n];

    return asciiSum - 2 * lcsSum;
}

int main() {
    string s1 = "sea";
    string s2 = "eat";
    int result = minimumDeleteSum(s1, s2);
    std::cout << "Output: " << result << std::endl;
    return 0;
}
