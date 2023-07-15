 #include <iostream>
#include <string>

bool backspaceCompare(std::string s, std::string t) {
    int i = s.length() - 1;
    int j = t.length() - 1;
    int skipS = 0, skipT = 0;

    while (i >= 0 || j >= 0) {
         while (i >= 0) {
            if (s[i] == '#') {
                skipS++;
                i--;
            } else if (skipS > 0) {
                skipS--;
                i--;
            } else {
                break;
            }
        }

         while (j >= 0) {
            if (t[j] == '#') {
                skipT++;
                j--;
            } else if (skipT > 0) {
                skipT--;
                j--;
            } else {
                break;
            }
        }

         if (i >= 0 && j >= 0 && s[i] != t[j]) {
            return false;
        }

         if ((i >= 0) != (j >= 0)) {
            return false;
        }

        i--;
        j--;
    }

    return true;
}

int main() {
    std::string s = "ab#c";
    std::string t = "ad#c";

    if (backspaceCompare(s, t)) {
        std::cout << "true" << std::endl;
    } else {
        std::cout << "false" << std::endl;
    }

    return 0;
}
