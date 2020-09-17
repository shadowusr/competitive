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

inline long long f(long long n, long long m, long long k) {
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += min(m, (k - 1) / i);
    }
    return ans;
}

int main() {
    long long n, m, k;
    cin >> n >> m >> k;

    long long a = 1, b = n * m, mid;
    while (a <= b) {
        mid = (a + b) / 2;

        long long tmp = f(n, m, mid);
        if (tmp < k && f(n, m, mid + 1) >= k) {
            break;
        }

        if (tmp < k) {
            a = mid + 1;
        } else {
            b = mid - 1;
        }
    }

    cout << mid << endl;
}

/*
448D - Multiplication Table
 Bizon the Champion isn't just charming, he also is very smart.

While some of us were learning the multiplication table, Bizon the Champion had fun in his own manner. Bizon the Champion painted an n × m multiplication table, where the element on the intersection of the i-th row and j-th column equals i·j (the rows and columns of the table are numbered starting from 1). Then he was asked: what number in the table is the k-th largest number? Bizon the Champion always answered correctly and immediately. Can you repeat his success?

Consider the given multiplication table. If you write out all n·m numbers from the table in the non-decreasing order, then the k-th number you write out is called the k-th largest number.

Input
The single line contains integers n, m and k (1 ≤ n, m ≤ 5·105; 1 ≤ k ≤ n·m).

Output
Print the k-th largest number in a n × m multiplication table.

Examples
input
2 2 2
output
2
input
2 3 4
output
3
input
1 10 5
output
5

 Solution:
 Key idea is to use binary search to find k-th largest number.
 Let function f(x) be the number of elements that are less than x.
 To compute it, consider the following table:
i|                  |elements < x|
1|1 2 3  4  5  6 ...|(x-1)/1     |
2|2 4 6  8 10 12 ...|(x-1)/2     |
3|3 6 9 12 15 18 ...|(x-1)/3     |
. . .
 Thus to get the value of f one has to iterate over all rows of the table and get the sum.

 This function is used in binary search. Initial boundaries of the search are 1, n * m.
 We are looking for the largest x such that number of elements less than x is < k.

 For example, in the 2 x 3 table
 1 2 3
 2 4 6
 4-th largest number is 3, because there are 3 numbers that are less than 3.

 */