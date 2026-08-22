class Solution {
public:
    bool checkDivisibility(int n) {
        int product=1;
        int nums=n;
        int sum=0;
        while(n>0){
         product*=n%10;
         sum+=n%10;
         n=n/10;
        }
        return nums % (sum+product)==0;
    }
};