bool isBadVersion(int version) {
   
    return version >= 4;
}

int firstBadVersion(int n) {
    int left = 1;
    int right = n;

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (isBadVersion(mid)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    return left;
}

int main() {
    int n = 10;
    int firstBad = firstBadVersion(n);

    return 0;
}
