class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int>ans;
        int n = nums.size();
     for(int i =0;i<n;i++){
        if(nums[i]==0){
            ans.push_back(0);
        }
     }
      for(int j =0;j<n;j++){
        if(nums[j]==1){
            ans.push_back(1);
        }
     }  
      for(int k =0;k<n;k++){
        if(nums[k]==2){
            ans.push_back(2);
        }
     } 
     nums =ans;
    }
};