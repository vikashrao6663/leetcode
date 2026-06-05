class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
     int n=nums.size();
     int i = 0 ,j = 0 ,flips = 0 ;
     int maxlen=0,len=INT_MIN;

     while(j<n){
        if(nums[j]==1)j++;
        else {
            if(flips<k){
                flips++;
                j++;
            }
            else{
                len = j-i;
                maxlen =max(maxlen,len);
                while(nums[i]==1) i++;
                i++;
                j++;
            }
        }
     } 
     len=j-i;
     maxlen =max(maxlen,len);
     return maxlen;  
    }
};