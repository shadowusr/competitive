#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

/*
 Maintain an array of lengths of consecutive elements. If the first prefix length is greater than 1 (>1), then we can remove that prefix and increase the number of operations. Now if the prefix length is equal to 1 (==1), then search for the first length in the array that is greater than 1 and reduce it. If such length is not found, remove the last length from the array (maintain 2 pointers one left and one right and reduce the right pointer).
 Example :- 1 5 10111
 After 1st operation -> 011
 After 2nd operation -> 1
 Thus 3 operations are required.

 A counter example as to why we should reduce from the first large prefix instead of the largest one:

 An example test case is -> 1 13 1010010101111
 That approach gives 6 while the answer should be 7
 The problem is that we should not remove from the biggest chunk because we may exhaust it early. The ideal way is to remove from the first chunk which is greater than 1. That way we can optimally utilize the chunks. In the example, it exhausts (1111) which could have been used for 6th element while we could have reduced the (00) for the 1st element.
 */

int main() {
    char c, prev;
    int t, n, index;
    vector<int> arr;
    cin >> t;
    while (t--) {
        cin >> n;
        prev = '#';
        index = 0;
        arr = vector<int>(200100);
        for (int i = 0; i < n; i++) {
            cin >> c;
            if (c != prev && prev != '#') index++;
            arr[index]++;
            prev = c;
        }
        int ans = 0;
        int lastGreatest = 0;
        for (int lo = 0, hi = index; lo <= hi; ) {
            if (arr[lo] == 1) {
                bool found = false;
                for (int j = max(lo + 1, lastGreatest); j <= hi; j++) {
                    if (arr[j] > 1) {
                        arr[j]--;
                        found = true;
                        lastGreatest = j;
                        break;
                    }
                }
                if (!found) {
                    lastGreatest = hi;
                    hi--;
                }
            }
            ans++;
            lo++;
        }
        cout << ans << endl;
    }
}

