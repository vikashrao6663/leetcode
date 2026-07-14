class Solution {
public:
    static const int MOD = 1e9 + 7;

    int dp[201][201][201];

    int solve(int i, int g1, int g2, vector<int>& nums) {
        if (i == nums.size()) {
            return (g1 != 0 && g1 == g2);
        }

        if (dp[i][g1][g2] != -1)
            return dp[i][g1][g2];

        long long ans = 0;

        // Skip
        ans += solve(i + 1, g1, g2, nums);

        // Put in first subsequence
        ans += solve(i + 1, gcd(g1, nums[i]), g2, nums);

        // Put in second subsequence
        ans += solve(i + 1, g1, gcd(g2, nums[i]), nums);

        return dp[i][g1][g2] = ans % MOD;
    }

    int subsequencePairCount(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, 0, nums);
    }
};