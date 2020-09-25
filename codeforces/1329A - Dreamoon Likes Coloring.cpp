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
    long long n, m;
    long long sum = 0;
    cin >> n >> m;
    vector<int> l(m);

    for (int i = 0; i < m; i++) {
        cin >> l[i];
        sum += l[i];
    }
    if (sum < n) {
        cout << "-1\n";
        return 0;
    }

    vector<long long> suff(m, 0);
    suff[m - 1] = l[m - 1];
    for (int i = m - 2; i >= 0; i--) {
        suff[i] += suff[i + 1] + l[i];
    }

    vector<int> ans(m);
    for (int i = 0; i < m; i++) {
        ans[i] = max(i + 1ll, n - suff[i] + 1);
        if (ans[i] + l[i] - 1 > n) {
            cout << "-1\n";
            return 0;
        }
    }

    for (auto item : ans) {
        cout << item << " ";
    }
    cout << endl;
}

/* 1329A - Dreamoon Likes Coloring
https://sohojeprogramming.blogspot.com/2020/04/1330c-dreamoon-likes-coloring.html
Solution.
 Basically all you need to do is to place m segments within n cells in a given order, so that all cells are colored and all colors are present (if cell is colored multiple times, it stores the last color only).
 There are two cases when there's no solution:
 - We don't have enough segments to cover all cells. It happens when sum(l_i) < n.
 - At some point there's a big segment that overrides too many cells and some colors are eventually not present. Example: 10 5    2 2 2 2 8

 Otherwise we can build a suffix sum array of l_i.
 Example:
 7 3
 3 1 4
 Suffix array suff: 8 5 4.
 The answer consists of m numbers (steps).
 Suppose we are at step i. suff[i] means that we have to place suff[i] elements before the end of the array.
 Consider that we have to place segment of length 2 in 2 cells. Obviously, it has to start at 1 and will occupy all cells.
 This leads us to a formulae: n - suff[i] + 1.
 For example, when we are at step 1, we need to place 8 elements. Formulae gives us -1, but it's an invalid position. The minimum start of a segment at step i (0 <= i < m) is i + 1.
 Therefore the answer at step i is max(i + 1, n - suff[i] + 1).
 */