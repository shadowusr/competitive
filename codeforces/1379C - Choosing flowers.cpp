#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
#include <set>
#include <unordered_map>
#include <queue>
#include <cstring>
#include <iomanip>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int t, n, m;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        vector<pair<int, int> > a(m);

        for (int i = 0; i < m; i++) {
            cin >> a[i].first >> a[i].second;
        }
        sort(a.begin(), a.end(), [] (auto a, auto b) { return (a.first > b.first) || (a.first == b.first && a.second > b.second); });
        vector<unsigned long long> s(m + 1, 0);

        for (int i = 1; i <= m; i++) {
            s[i] = s[i - 1] + a[i - 1].first;
        }

        unsigned long long ans = 0;

        for (int i = 0; i < m; i++) { // iterating over all possible b_i
            int cB = a[i].second;
            // Looking for the index of the lowest possible a_i which is still > than b_i
            int lo = 0, hi = m - 1, mid;
            while (lo <= hi) {
                mid = (lo + hi) / 2;
                if (a[mid].first > cB) {
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                    mid -= 1;
                }
            }
            unsigned long long tmp = 0;
            if (mid >= 0) {
                mid = min(mid + 1, n);
                tmp += s[mid];
                if (mid - 1 < i && mid < n) {
                    tmp += a[i].first;
                    mid++;
                }
                tmp += (unsigned long long) a[i].second * max(0, n - mid);
            } else {
                tmp += a[i].first;
                tmp += (unsigned long long) a[i].second * (n - 1);
            }

            ans = max(ans, tmp);
        }
        cout << ans << endl;
    }
}

/*
1
 6 7
 7 1
 6 1
 5 1
 4 1
 4 1
 4 1
 1 5

 1
 7 7
 7 1
 6 1
 5 5
 4 1
 4 1
 4 1
 1 1


 1
2 3
2 100
50 100
3 2


 1
 3 4
 10 1
 10 100
 1 1
 1 1

 1
 5 7
 7 1
 6 1
 5 1
 4 1
 4 5
 4 1
 1 1

 1
 5 5
 8 1
 7 1
 5 6
 3 1
 1 1

 1
 4 6
2 10
6 4
2 5
5 6
9 9
1 8
 */


