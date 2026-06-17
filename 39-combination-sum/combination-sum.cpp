class Solution {
public:
set<vector<int>>s;
void getallcombine(vector<int>&arr,int idx,int tar,vector<vector<int>>&ans,vector<int>&combine){
if(idx == arr.size() || tar<0){
    return ;
} 
if(tar ==0){
    if(s.find(combine)==s.end()){
        ans.push_back(combine);
        s.insert(combine);
    }
    return;
}
combine.push_back(arr[idx]);
//single
 getallcombine(arr,idx+1,tar-arr[idx],ans,combine);
 //multiple
 getallcombine(arr,idx,tar-arr[idx],ans,combine);
 combine.pop_back();
 // exclusion
  getallcombine(arr,idx+1,tar,ans,combine);
}

    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
    vector<vector<int>>ans;
    vector<int>combine;
    getallcombine(arr,0,target,ans,combine);
    return ans;
    }
};