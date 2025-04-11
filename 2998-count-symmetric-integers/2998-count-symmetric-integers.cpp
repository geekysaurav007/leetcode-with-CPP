class Solution {
public:
    int check(int start, int end, string s) {
        int sum = 0;
        for (int i = start; i <= end; i++) {
            sum += (int)s[i];
        }
        return sum;
    }
    int countSymmetricIntegers(int low, int high) {
        int cnt = 0;
        for (int i = low; i <= high; i++) {
            string n = to_string(i);
            int l = n.length();
            if (n.length() % 2 == 0 &&
                    check(0, l / 2 - 1, n) == check(l / 2, l - 1, n)) {
                // int left = check(0, l / 2 - 1, n);
                // int right = check(l / 2, l - 1, n);
                // if (left == right) {
                //     cnt++;
                // }
                cnt++;
            }
        }
        return cnt;
    }
};