class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        vector<int> vals(st.begin(), st.end());

        const int MAXX = 2048;

        vector<bool> pairXor(MAXX, false);
        for (int x : vals) {
            for (int y : vals) {
                pairXor[x ^ y] = true;
            }
        }

        vector<bool> ans(MAXX, false);
        for (int xy = 0; xy < MAXX; ++xy) {
            if (!pairXor[xy]) continue;
            for (int z : vals) {
                ans[xy ^ z] = true;
            }
        }

        int res = 0;
        for (bool x : ans) res += x;
        return res;
    }
};