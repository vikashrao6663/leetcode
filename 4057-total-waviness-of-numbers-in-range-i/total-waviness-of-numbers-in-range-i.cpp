class Solution {
public:

    int waviness(int n) {
        vector<int> d;

        while(n > 0) {
            d.push_back(n % 10);
            n /= 10;
        }

        //reverse(d.begin(), d.end());

        int changes = 0;

        for(int i = 1; i < d.size() - 1; i++) {
            if((d[i] > d[i-1] && d[i] > d[i+1]) ||
               (d[i] < d[i-1] && d[i] < d[i+1])) {
                changes++;
            }
        }

        return changes;
    }

    int totalWaviness(int num1, int num2) {
        int ans = 0;

        for(int i = num1; i <= num2; i++) {
            ans += waviness(i);
        }

        return ans;
    }
};