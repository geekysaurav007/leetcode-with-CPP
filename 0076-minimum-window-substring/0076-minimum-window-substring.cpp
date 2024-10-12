class Solution {
public:
    string minWindow(string s, string t) {
        map<char, int> mp;
        for (auto ch : t) {
            mp[ch]++;
        }
        int count = t.length(), l = 0, r = 0;
        int si = 0;
        int ws = INT_MAX;
        int n = s.length();
        while (r < n) {
            if (mp[s[r]] >
                0) { // agar char alreday map me hai toh count ko ghatao
                count--;
            }
            mp[s[r]]--; // nhi toh negative me daal do..kyuki chaiye nahi

            while (count == 0) {
                int currsize = r - l + 1; // current window ka size
                if (ws > currsize) { // abhi ka window ka size agar chota hai
                                     // toh ws ko update
                    ws = currsize;
                    si = l; // es window ka starting index mark kr lo
                }

                mp[s[l]]++; // shrink
                if (mp[s[l]] > 0)
                    count++;
                l++;
            }
            r++;
        }
        if (ws == INT_MAX) {
            return "";
        } else {
            return s.substr(si, ws);
        }
    }
};