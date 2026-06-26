class Solution {
public:
    int reverse(int x) {
       long long rev = 0;

while (x != 0) {

    int digit = x % 10;      // Last digit nikalo

    rev = rev * 10 + digit;  // Reverse me add karo

    x = x / 10;              // Last digit hata do
} 

if(rev > INT_MAX || rev < INT_MIN)
            return 0;
            
return rev;
    }
};