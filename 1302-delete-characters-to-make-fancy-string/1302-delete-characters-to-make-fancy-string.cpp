class Solution {
public:
    string makeFancyString(string s) {
        string ans;
        int count = 1;
        ans += s[0]; // Add the first character to the result

        for (int i = 1; i < s.length(); i++) {
            if (s[i] == s[i - 1]) {
                count++;
            } else {
                count = 1; // Reset count if the current character is different
            }
            if (count < 3) {
                ans += s[i]; // Append character only if count is less than 3
            }
        }

        return ans;
    }
};