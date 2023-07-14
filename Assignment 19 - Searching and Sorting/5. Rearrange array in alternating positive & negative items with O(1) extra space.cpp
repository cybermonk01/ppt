#include <iostream>
#include <vector>

using namespace std;

void rearrangeArray(vector<int>& arr) {
    int n = arr.size();

    int lastNegIdx = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] < 0) {
            lastNegIdx = i;
        }
    }


    int posIdx = 0;
    int negIdx = lastNegIdx + 1;

    while (posIdx < negIdx && negIdx < n && arr[posIdx] < 0) {
        swap(arr[posIdx], arr[negIdx]);
        posIdx += 2;
        negIdx++;
    }
}

int main() {
   
    vector<int> arr1 = {1, 2, 3, -4, -1, 4};
    rearrangeArray(arr1);

    cout << "Rearranged Array 1: ";
    for (int num : arr1) {
        cout << num << " ";
    }
    cout << endl;

    vector<int> arr2 = {-5, -2, 5, 2, 4, 7, 1, 8, 0, -8};
    rearrangeArray(arr2);

    cout << "Rearranged Array 2: ";
    for (int num : arr2) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
