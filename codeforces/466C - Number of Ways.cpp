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

    long long n, sum = 0;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        sum += v[i];
    }

    if (sum % 3) {
        cout << "0\n";
        return 0;
    }
    sum /= 3;

    long long ts1 = 0, ts2 = 0, j, last1 = -1, last2 = -1;
    vector<long long> ac(n), bc(n), nc(n);
    for (int i = 0; i < n; i++) {
        //ac[i] = ac[max(i - 1, 0)];
        ts1 += v[i];
        if (ts1 == sum) {
            ac[i]++;
            if (last1 != -1) {
                ac[i] += ac[last1];
            }
            last1 = i;
        }

        j = n - i - 1;
        //bc[j] = bc[min(n - 1, j + 1)];
        ts2 += v[j];
        if (ts2 == sum) {
            bc[j]++;
            if (last2 != -1) {
                bc[j] += bc[last2];
            }
            last2 = j;
        }
        nc[j] = max(nc[min(j + 1, n - 1)], bc[j]);
    }

    long long ans = 0;
    for (int i = 0; i < n - 2; i++) {
        ans += (ac[i] > 0) * (nc[i + 2]);
    }
    /*for (int i = n - 1; i > 1; i--) {
        ans += (bc[i] > 0) * (ac[i - 2]);
    }*/

    cout << ans << endl;
}