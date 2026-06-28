class Solution {
public:
    int digitFrequencyScore(int n) {
  int res = 0;
  while(n>0){
    int digit=n%10;
    res =res+digit;
    n=n/10;
  }
  return res;
    }
};