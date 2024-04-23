#include <iostream>
#include <climits>
#include <vector>
using namespace std;

int minCostDP(const vector<pair<int, int> >& boxes, int n) {
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;
    
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < boxes.size(); ++j) {
            int ni = boxes[j].first;
            int pi = boxes[j].second;
            
            if (i >= ni && dp[i - ni] != INT_MAX) {
                dp[i] = min(dp[i], dp[i - ni] + pi);
            }
        }
    }
    
    return dp[n];
}

int main() {
    int n;
    vector<pair<int, int> > boxes;

    for (int i = 0; i < 3; ++i) {
        int ni, pi;
        cin >> ni >> pi;
        boxes.push_back(make_pair(ni, pi));
    }
    
    cin >> n;
    if (boxes[0].first > n) {
        cout << boxes[0].second;
    } else {
        int minCost = minCostDP(boxes, n);
        cout << minCost;
    }
    
    return 0;
}

