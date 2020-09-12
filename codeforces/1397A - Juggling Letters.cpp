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

    int t, n;
    vector<int> cnt;
    string s;
    cin >> t;
    while (t--) {
        cin >> n;
        cnt = vector<int>(30, 0);
        for (int i = 0; i < n; i++) {
            cin >> s;
            for (int j = 0; j < s.length(); j++) {
                cnt[s[j] - 'a']++;
            }
        }

        bool ans = true;
        for (int i = 0; i < cnt.size(); i++) {
            ans &= !(cnt[i] % n);
        }

        cout << (ans ? "YES" : "NO") << endl;
    }
}
