class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size();
        int high = 0;
        int low = 0;
    for(char c :s){
      if(c=='('){
        high++;
        low++;
      }
      else if (c ==')'){
        low--;high--;
      }
      else if(c=='*'){
        low--;
        high++;
      }
      if(high<0) return false ;

      low =max(0,low) ;
    }
     return low == 0;  
    }
};