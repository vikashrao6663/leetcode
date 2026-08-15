class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
    vector<int> arr;
    for (auto &row : matrix) {
    arr.insert(arr.end(), row.begin(), row.end());
}  
    sort(arr.begin(),arr.end());
    return arr[k-1];
    }
};