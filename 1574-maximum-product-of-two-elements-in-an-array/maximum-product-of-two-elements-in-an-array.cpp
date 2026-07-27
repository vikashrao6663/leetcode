class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n =nums.size();
        int sum=0;
        sort(nums.begin(),nums.end(),greater<int>());
     for(int i =0;i<n;i++){
      sum=(nums[i]-1)*(nums[i+1]-1); 
      break; 
     }   
     return sum;
    }
};