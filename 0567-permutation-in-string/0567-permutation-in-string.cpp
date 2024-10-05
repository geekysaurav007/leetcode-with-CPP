class Solution {
public:
    bool check(map<char, int>& m1, string target) {
        map<char, int> t;
        for (int i = 0; i < target.size(); i++) {
            t[target[i]]++;
        }
        for (const auto& [key, value] : t) {
            if (!m1.count(key))
                return false;
            if (m1[key] != t[key])
                return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        map<char, int> m1;
        bool ans=false;
        if(s1.size()>s2.size()) return false;
        for (int i = 0; i < s1.size(); i++) {
            m1[s1[i]]++;
        }
        for (int i = 0; i <= s2.size()-s1.size(); i++) {
            string target = s2.substr(i, s1.size());
            ans= check(m1, target);
            if(ans) break;
        }
        return ans;
    }
};