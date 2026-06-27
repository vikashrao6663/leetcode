class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        int n = nums.size();
        set<vector<int>> ans;

        if(n < 4) return {};

        sort(nums.begin(), nums.end());

        for(int i = 0; i < n - 3; i++) {

            for(int j = i + 1; j < n - 2; j++) {

                int left = j + 1;
                int right = n - 1;

                while(left < right) {

                    long long sum = 1LL * nums[i] + nums[j] + nums[left] + nums[right];

                    if(sum == target) {
                        ans.insert({nums[i], nums[j], nums[left], nums[right]});
                        left++;
                        right--;
                    }
                    else if(sum < target) {
                        left++;
                    }
                    else {
                        right--;
                    }
                }
            }
        }

        return vector<vector<int>>(ans.begin(), ans.end());
    }
};