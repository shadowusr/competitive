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

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    unsigned long long minCost = numeric_limits<unsigned long long>::max();
    //cout << v.back() << "  " << pow(v.back(), 1.0 / (n - 1)) << endl;
    for (int c = 1; c <= ceil(pow(v.back(), 1.0 / (n - 1))) && pow(c, n - 1) < numeric_limits<long long>::max(); c++) {
        unsigned long long cost = 0;

        for (int i = 0; i < n; i++) {
            cost += abs(v[i] - pow(c, i));
        }

        if (minCost > cost) {
            minCost = cost;
            //cout << "Optimal c: " << c << endl;
        }
    }

    cout << minCost << endl;
}
