class Solution {
public:

    void getallcombine(vector<int>& arr, int idx, int tar,
                       vector<vector<int>>& ans, vector<int>& combine) {

        if(tar == 0) {
            ans.push_back(combine);
            return;
        }
        if(idx == arr.size() || tar < 0) {
            return;
        }
        combine.push_back(arr[idx]);
        // multiple times current element le sakte hain
        getallcombine(arr, idx, tar - arr[idx], ans, combine);
        combine.pop_back();
        // current element ko skip karo
        getallcombine(arr, idx + 1, tar, ans, combine);
    }
    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        vector<vector<int>> ans;
        vector<int> combine;
        getallcombine(arr, 0, target, ans, combine);

        return ans;
    }
};