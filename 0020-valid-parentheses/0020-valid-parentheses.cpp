class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        char x;
        for (auto ch : s) {
            if (ch == '[' or ch == '{' or ch == '(') {
                st.push(ch);
            } else {
                if (st.empty())
                    return false;
                switch (ch) {
                case ')':
                    x = st.top();
                    st.pop();
                    if (x == '{' or x == '[')
                        return false;
                    break;

                case '}':
                    x = st.top();
                    st.pop();
                    if (x == '(' or x == '[')
                        return false;
                    break;

                case ']':
                    x = st.top();
                    st.pop();
                    if (x == '{' or x == '(')
                        return false;
                    break;
                }
            }
        }
        return st.empty();
    }
};