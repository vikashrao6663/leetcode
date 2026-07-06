class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int n = nums.size();
    unordered_map<int,int>mp;
    int count = 0;
    for(int i =0;i<n;i++){
        int need = k-nums[i];
        if(mp[need]>0){
            count++;
            mp[need]--;
        }
        else mp[nums[i]]++;
    } 
    return count;   
    }
};