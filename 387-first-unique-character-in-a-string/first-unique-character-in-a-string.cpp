class Solution {
public:
    int firstUniqChar(string s) {

        int n = s.size();

        for(int i = 0; i < n; i++) {

            int j;

            for(j = 0; j < n; j++) {

                if(i != j && s[i] == s[j]) {
                    break;
                }
            }

            if(j == n) {
                return i;
            }
        }

        return -1;
    }
};