#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool func(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
    return a.first.second < b.first.second;
}

int binarySearch(const vector<pair<pair<int, int>, int> >& job, int keyindex) {
    int low = 0, high = keyindex - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (job[mid].first.second <= job[keyindex].first.first) {
            if (job[mid + 1].first.second <= job[keyindex].first.first) {
                low = mid + 1;
            } else {
                return mid;
            }
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

void weight_interval(vector<pair<pair<int, int>, int> >& job, int n) {
    sort(job.begin(), job.end(), func);

    vector<int> t(n, 0);

    t[0] = job[0].second;
    for (int i = 1; i < n; i++) {
        int index = binarySearch(job, i);
        int wplus = job[i].second;
        if (index != -1) {
            wplus += t[index];
        }
        t[i] = max(wplus, t[i - 1]);
    }

    cout << t[n - 1];
}

int main() {
    int n, s, f, w;
    vector<pair<pair<int, int>, int> > job;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s >> f >> w;
        job.push_back(make_pair(make_pair(s, f), w));
    }

    weight_interval(job, n);
    return 0;
}

