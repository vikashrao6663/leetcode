class Solution {
public:
    int binaryGap(int N) {

        int last = -1;   // last position of 1
        int pos = 0;     // current bit position
        int maxGap = 0;

        while(N > 0) {

            if(N & 1) {
                if(last != -1) {
                    maxGap = max(maxGap, pos - last);
                }
                last = pos;
            }

            pos++;
            N >>= 1;
        }

        return maxGap;
    }
};