class Solution {
public:
    long long sumAndMultiply(int n) {
        int sum = 0;
        int rev = 0;
        int rev2 = 0;
        int temp = n;

        // Sum of digits
        while (temp > 0) {
            int digit = temp % 10;
            sum += digit;
            temp /= 10;
        }

        // Reverse after removing zeros
        temp = n;
        while (temp > 0) {
            int digit = temp % 10;
            if (digit != 0) {
                rev = rev * 10 + digit;
            }
            temp /= 10;
        }

        // Reverse again to restore original order
        while (rev > 0) {
            rev2 = rev2 * 10 + rev % 10;
            rev /= 10;
        }

        return 1LL * sum * rev2;
    }
};