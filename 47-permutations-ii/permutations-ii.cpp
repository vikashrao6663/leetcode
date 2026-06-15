class Solution {
public:
    void getperms(vector<int>& nums, int idx, vector<vector<int>>& ans) {

        // jb idx == nums.size() ho jaye to print/store krwa do
        if(idx == nums.size()) {
            ans.push_back(nums);
            return;
        }

        // 1 idx ko store krwa ke baki sbko recursion se
        for(int i = idx; i < nums.size(); i++) {

            bool duplicate = false;

            for(int j = idx; j < i; j++) {
                if(nums[j] == nums[i]) {
                    duplicate = true;
                    break;
                }
            }

            if(duplicate) continue;

            swap(nums[idx], nums[i]);

            getperms(nums, idx + 1, ans);

            // backtracking
            swap(nums[idx], nums[i]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        getperms(nums, 0, ans);

        return ans;
    }
};