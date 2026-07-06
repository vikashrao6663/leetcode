class Solution {
public:
    string longestPalindrome(string s) {

        int n = s.size();          // String ki length
        int start = 0;             // Longest palindrome ka starting index
        int maxLen = 1;            // Abhi tak longest palindrome ki length

        // Har character ko center maanenge
        for (int i = 0; i < n; i++) {

            // ---------------- ODD LENGTH PALINDROME ----------------
            int l = i;             // Left pointer center par
            int r = i;             // Right pointer bhi center par

            // Jab tak left aur right same hain, expand karte jao
            while (l >= 0 && r < n && s[l] == s[r]) {

                // Current palindrome ki length
                if (r - l + 1 > maxLen) {
                    maxLen = r - l + 1;   // Nayi maximum length
                    start = l;            // Naya starting index
                }

                l--;    // Ek step left jao
                r++;    // Ek step right jao
            }

            // ---------------- EVEN LENGTH PALINDROME ----------------
            l = i;          // Left pointer
            r = i + 1;      // Right pointer next character

            // Jab tak dono same hain, expand karte jao
            while (l >= 0 && r < n && s[l] == s[r]) {

                if (r - l + 1 > maxLen) {
                    maxLen = r - l + 1;
                    start = l;
                }

                l--;        // Left expand
                r++;        // Right expand
            }
        }

        // Longest palindrome return karo
        return s.substr(start, maxLen);
    }
};