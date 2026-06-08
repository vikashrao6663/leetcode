class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();

        int k = 1;
        int i = 0, j = 0;
        int flips = 0;
        int maxlen = 0;

        while(j < n) {
            if(nums[j] == 0) {
                flips++;
            }

            while(flips > k) {
                if(nums[i] == 0) {
                    flips--;
                }
                i++;
            }

            maxlen = max(maxlen, j - i + 1);
            j++;
        }

        return maxlen - 1;
    }
};