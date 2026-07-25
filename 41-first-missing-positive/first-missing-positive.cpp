class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        vector<int> temp;
        for (int i =0;i<nums.size();i++) {
            if (nums[i] > 0)
                temp.push_back(nums[i]);
        }
        sort(temp.begin(), temp.end());

        int expected = 1;

        for (int i = 0; i < temp.size(); i++) {
            if (temp[i] < expected)
                continue;         

            if (temp[i] == expected)
                expected++;

            else
                return expected;
        }

        return expected;
    }
};