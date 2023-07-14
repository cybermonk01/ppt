#include <iostream>
#include <queue>

using namespace std;

class RecentCounter {
public:
    RecentCounter() {
        
    }
    
    int ping(int t) {
        requests.push(t);
        
        while (!requests.empty() && requests.front() < t - 3000) {
            requests.pop();
        }
        
        return requests.size();
    }
    
private:
    queue<int> requests;
};

int main() {
    RecentCounter counter;
    cout << counter.ping(1) << endl;
    cout << counter.ping(100) << endl;
    cout << counter.ping(3001) << endl;
    cout << counter.ping(3002) << endl;

    return 0;
}

