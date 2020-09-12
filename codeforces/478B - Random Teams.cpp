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

inline unsigned long long pairsCount(unsigned long long n) {
    return n * (n - 1) / 2;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    unsigned long long n, g;
    cin >> n >> g;

    unsigned long long maxp = pairsCount(n - g + 1);
    unsigned long long x = ceil((double) n / g);
    unsigned long long k = n - g * x + g;
    unsigned long long minp = pairsCount(x) * k + pairsCount(x - 1) * (g - k);

    cout << minp << " " << maxp << endl;
}