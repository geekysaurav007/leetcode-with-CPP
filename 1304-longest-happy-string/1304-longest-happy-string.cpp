class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> p;
        if (a)
            p.push({a, 'a'});
        if (b)
            p.push({b, 'b'});
        if (c)
            p.push({c, 'c'});
        string ans;
        while (!p.empty()) {
            auto a = p.top();
            p.pop();
            int count1 = a.first;
            char c1 = a.second;
            if (count1 > 2) {
                ans.push_back(c1);
                ans.push_back(c1);
                count1 -= 2;
            } else {
                ans.push_back(c1);
                count1--;
            }

            if (p.empty())
                return ans;

            auto b = p.top();
            int count2 = b.first;
            char c2 = b.second;
            p.pop();
            if (count2 >= 2 and count2 > count1) {
                ans.push_back(c2);
                ans.push_back(c2);
                count2 -= 2;
            } else {
                count2--;
                ans.push_back(c2);
            }

            cout << ans << " ";
            if (count1)
                p.push({count1, c1});
            if (count2)
                p.push({count2, c2});
        }
        return ans;
    }
};