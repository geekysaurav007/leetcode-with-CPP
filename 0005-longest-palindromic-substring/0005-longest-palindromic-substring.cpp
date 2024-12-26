class Solution {
public:
    bool pallindrome(int i, int j, string &s) {
        while (i <= j) {
            if (s[i++] != s[j--])
                return false;
        }
        return true;
    }
    string longestPalindrome(string s) {
        string ans;
         int maxlen = 0,start=0;
        if(s.length()==1) return s;
        for (int i = 0; i < s.length(); i++) {
            for (int j = i ; j < s.length(); j++) {
                if (pallindrome(i, j, s)) {
                    if (j - i + 1 > maxlen) { // Update max length if a longer palindrome is found
                        maxlen = j - i + 1;
                        start = i; // Store the starting index of the palindrome
                    }
                }
            }
        }
        return s.substr(start,maxlen);
    }
};