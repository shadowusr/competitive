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

    int len, sum;
    cin >> len >> sum;

    if ((sum == 0 && len > 1) || (sum > len * 9)) {
        cout << "-1 -1\n";
        return 0;
    }

    int tmp = sum;
    string maxN, minN;
    for (int i = 0; i < len; i++) {
        if (tmp >= 9) {
            maxN += '9';
            tmp -= 9;
        } else {
            maxN += ('0' + tmp);
            tmp = 0;
        }
    }
    tmp = sum;
    for (int i = 0; i < len; i++) {
        if (i == len - 1) {
            minN += ('0' + tmp);
        } else if (tmp > 9) {
            minN += '9';
            tmp -= 9;
        } else if (tmp > 1) {
            minN += ('0' + tmp - 1);
            tmp = 1;
        } else if (tmp == 1) {
            minN += '0';
        }
    }
    reverse(minN.begin(), minN.end());

    cout << minN << " " << maxN << endl;
}