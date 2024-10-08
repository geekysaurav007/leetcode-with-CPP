class Solution {
public:
    int helper(string s, int k) {
        int l = 0, r = 0, n = s.size(), cnt = 0;
        map<char, int> mp;
        while (r < n) {
            mp[s[r]]++;
            while (mp.size() > k) {
                mp[s[l]]--;
                if (mp[s[l]] == 0) {
                    mp.erase(s[l]);
                }
                l++;
            }

            cnt += r - l + 1;

            r++;
        }
        return cnt;
    }
    int numberOfSubstrings(string s) {
        int k = 3;
        int x = helper(s, k);
        int y = helper(s, k - 1);
        return x - y;
    }
};