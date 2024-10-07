class Solution {
public:
    int minLength(string s) {
        while (1) {
            bool flag = true;
            for (int i = 0; i < s.size(); i++) {
                string s2 = s.substr(i, 2);
                if (s2 == "AB" || s2 == "CD") {
                    flag=false;
                    s.erase(i, 2);
                }
            }
            if(flag) break;
        }
        return s.size();
    }
};