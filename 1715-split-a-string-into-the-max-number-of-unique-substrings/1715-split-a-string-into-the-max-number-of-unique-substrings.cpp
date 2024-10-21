class Solution {
public:
    void solve(string s, set<string> &st, int index, int& maxcount, int curr) {

        if (index == s.size()) {
            maxcount = max(maxcount, curr);
            return;
        }
        for (int i = index; i < s.size(); i++) {
           string str = s.substr(index, i - index + 1);
            if (st.find(str) == st.end()) {
                st.insert(str);
                solve(s, st, i + 1, maxcount, curr + 1);
                st.erase(str);
            }
        }
    }
    int maxUniqueSplit(string s) {
        set<string> st;
        int maxcount = 0;
        int currcount = 0;
        solve(s, st, 0, maxcount, currcount);
        return maxcount;
    }
};