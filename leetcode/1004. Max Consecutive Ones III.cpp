// Queue-based solution
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ans = 0,
        currentLength = 0,
        start = 0, // stores where current sequence of 1s start (index)
        spentFlips = 0;
        // This queue stores positions on which we spent our flips
        queue<int> q;

        for (int i = 0; i < nums.size(); i++) {
            currentLength++;

            if (nums[i] == 0) {
                q.push(i);
                if (spentFlips < k) {
                    spentFlips++;
                } else {
                    currentLength -= q.front() - start + 1;
                    start = q.front() + 1;
                    q.pop();
                }
            }
            ans = max(ans, currentLength);
        }

        return ans;
    }
};

// Sliding window approach
class Solution2 {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ans = 0,
        lo = 0,
        hi = 0, // sliding window [lo, hi)
        spentFlips = 0;

        for (int i = 0; i < nums.size(); i++) {
            hi++;

            if (nums[i] == 0) {
                if (spentFlips < k) {
                    spentFlips++;
                } else {
                    while(nums[lo]) lo++;
                    lo = min(lo + 1, hi);
                }
            }
            ans = max(ans, hi - lo);
        }

        return ans;
    }
};