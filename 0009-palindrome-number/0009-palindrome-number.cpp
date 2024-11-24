class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        int k=x;
         long long rem, sum=0;
        while (x != 0) {
           
            rem = x % 10;
            sum = sum *10 +rem;
            x = x / 10;
        }
        if(sum==k) return true;
        else return false;
    }
};