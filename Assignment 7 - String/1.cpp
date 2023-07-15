#include <iostream>
#include <unordered_map>

bool areIsomorphic(std::string s, std::string t) {
    if (s.length() != t.length()) {
        return false;  
    }

    std::unordered_map<char, char> sToTMap;
    std::unordered_map<char, char> tToSMap;

    for (int i = 0; i < s.length(); i++) {
        char charS = s[i];
        char charT = t[i];
 
        if (sToTMap.find(charS) != sToTMap.end()) {
            if (sToTMap[charS] != charT) {
                return false;  
            }
        } else {
            sToTMap[charS] = charT;
        }
 
        if (tToSMap.find(charT) != tToSMap.end()) {
            if (tToSMap[charT] != charS) {
                return false;  
            }
        } else {
            tToSMap[charT] = charS;
        }
    }

    return true;
}

int main() {
    std::string s = "egg";
    std::string t = "add";

    if (areIsomorphic(s, t)) {
        std::cout << "Strings are isomorphic." << std::endl;
    } else {
        std::cout << "Strings are not isomorphic." << std::endl;
    }

    return 0;
}
