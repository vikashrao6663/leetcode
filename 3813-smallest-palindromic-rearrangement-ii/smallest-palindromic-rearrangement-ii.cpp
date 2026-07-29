class Solution {
public:
    static const int LIMIT = 1000001;

    long long comb(int n, int k) {
        k = min(k, n - k);
        long long ans = 1;
        for (int i = 1; i <= k; i++) {
            ans = ans * (n - i + 1) / i;
            if (ans >= LIMIT) return LIMIT;
        }
        return ans;
    }

    long long ways(vector<int>& cnt) {
        int rem = 0;
        for (int x : cnt) rem += x;

        long long ans = 1;

        for (int x : cnt) {
            if (x == 0) continue;
            ans *= comb(rem, x);
            if (ans >= LIMIT) return LIMIT;
            rem -= x;
        }

        return ans;
    }

    string smallestPalindrome(string s, int k) {
        vector<int> freq(26);

        for (char c : s)
            freq[c - 'a']++;

        vector<int> half(26);
        string mid = "";

        for (int i = 0; i < 26; i++) {
            half[i] = freq[i] / 2;
            if (freq[i] & 1)
                mid.push_back(char('a' + i));
        }

        if (ways(half) < k)
            return "";

        string left;

        int len = 0;
        for (int x : half) len += x;

        while ((int)left.size() < len) {

            for (int c = 0; c < 26; c++) {

                if (half[c] == 0) continue;

                half[c]--;

                long long cur = ways(half);

                if (cur >= k) {
                    left.push_back(char('a' + c));
                    break;
                }

                k -= cur;
                half[c]++;
            }
        }

        string right = left;
        reverse(right.begin(), right.end());

        return left + mid + right;
    }
};