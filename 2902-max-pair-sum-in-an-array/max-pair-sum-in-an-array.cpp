class Solution {
public:
    int getMaxDigit(int num) {
        int mx = 0;
        while (num > 0) {
            mx = max(mx, num % 10);
            num /= 10;
        }
        return mx;
    }

    int maxSum(vector<int>& nums) {
        vector<int> best(10, 0);
        int ans = -1;

        for (int num : nums) {
            int d = getMaxDigit(num);

            if (best[d] != 0) {
                ans = max(ans, best[d] + num);
            }

            best[d] = max(best[d], num);
        }

        return ans;
    }
};