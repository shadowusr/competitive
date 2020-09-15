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

vector<int> v;

void build(int level, bool isOr) {
    if (level == 1) return;

    for (int i = 1 << level; i < 1 << (level + 1); i++) {
        if (isOr) {
            v[i / 2] |= v[i];
        } else {
            v[i / 2] ^= v[i];
        }
    }

    build(level - 1, !isOr);
}

void update(int index, bool isOr) {
    if (index == 1) return;

    int a, b;
    if (index % 2) {
        a = index - 1;
        b = index;
    } else {
        a = index;
        b = index + 1;
    }

    if (isOr) {
        v[a / 2] = v[a] | v[b];
    } else {
        v[a / 2] = v[a] ^ v[b];
    }

    update(index / 2, !isOr);
}

int main() {

    int n, m;
    cin >> n >> m;
    v = vector<int>(1 << (n + 1));
    for (int i = 0; i < 1 << n; ++i) {
        cin >> v[(1 << n) + i];
    }
    build(n, true);


    int index, value;
    for (int i = 0; i < m; ++i) {
        cin >> index >> value;

        v[(1 << n) + index - 1] = value;
        update((1 << n) + index - 1, true);

        cout << v[1] << endl;
    }
}