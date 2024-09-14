class Solution {
public:
    bool isPallindrome(string& s, int index, int i) {
        while (index < i) {
            if (s[index] != s[i]) {
                return false;
            } else {
                index++;
                i--;
            }
        }
        return true;
    }
    void partition(int index, string& s, vector<string>& temp,
                   vector<vector<string>>& ans) {
        if (index == s.length()) {
            ans.push_back(temp);
            return;
        }
        for (int i = index; i < s.length(); i++) {
            if (isPallindrome(s, index, i)) {
                temp.push_back(s.substr(index, i-index + 1));
                partition(i + 1, s, temp, ans);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        partition(0, s, temp, ans);
        return ans;
    }
};