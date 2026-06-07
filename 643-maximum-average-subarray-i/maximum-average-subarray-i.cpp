class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();

        int sum = 0;
        for(int x = 0; x < k; x++) {
            sum += nums[x];
        }

        int maxsum = sum;

        int i = 0;
        int j = k;

        while(j < n) {
            sum = sum - nums[i] + nums[j];

            maxsum = max(maxsum, sum);

            i++;
            j++;
        }

        return (double)maxsum / k;
    }
};