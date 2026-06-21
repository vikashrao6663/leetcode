class Solution {
public:
int rev(int n) {
    int reverse = 0;

    while (n> 0) {
        int digit = n % 10;      // Last digit nikalo
        reverse = reverse * 10 + digit; // Reverse banao
        n = n/ 10;            // Last digit hatao
    }

    return reverse;
}
    int countNicePairs(vector<int>& nums) {
     int n = nums.size(); 
     int count =0;
     unordered_map<int ,int > m;
     for(int i =0;i<n;i++){
        nums[i] -=rev(nums[i]);
     }  
     for (int i = 0;i<n;i++){
        if(m.find(nums[i])!=m.end()){
            count =count%1000000007;
            count += m[nums[i]];
            m[nums[i]]++;
        }else m[nums[i]]++;
     }
     return count%1000000007;
    }
};