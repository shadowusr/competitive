#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t, n;
    vector<int> a;
    cin >> t;
    while (t--) {
        cin >> n;
        a = vector<int>(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        bool player = 0;
        int lastIndex = -1, maxV, maxI = -1;
        while (1) {
            maxV = -1;

            for (int i = 0; i < a.size(); i++) {
                if (i == lastIndex) continue;
                if (maxV < a[i]) {
                    maxV = a[i];
                    maxI = i;
                }
            }

            if (maxV <= 0) break;

            a[maxI]--;
            lastIndex = maxI;

            player = !player;
        }

        if (player) cout << "T\n";
        else cout << "HL\n";
    }
}


/*
 This solution is just an implementation of the optimal strategy: always getting a stone from a pile which has max number of stones.
 However, if limits were more strict, this approach wouldn't have worked out.

 The more optimal approach consists of just two cases:
 - if there are S stones and a pile which has > S / 2 stones, then T will always win as he always can get stones from this pile
 - if each pile has <= S / 2 stones and S is even, HL always wins. The condition allows us to assign a perfect matching of stones, where one stone is matched with exactly one stone from a different pile.
 - if each pile has <= S / 2 stones and S is odd, T always wins. After taking just one stone we arrive at a previous case, where next player to make a move loses.
 */