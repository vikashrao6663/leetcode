class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        int n =nums.size();
        int left=0;
        int ans=0;
        //pura feq count kr liya mai 
        for(int i=0;i<n;i++){
            freq[nums[i]]++;
        //isme uskaa count chkeck krge ki jo v count k se badi ho to minus minus krge 

        while(freq[nums[i]]>k){
            freq[nums[left]]--;
            left++;
        }
         ans=max(ans,i-left+1);

        }
        return ans;
    }
};