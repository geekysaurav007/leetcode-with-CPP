class Solution {
public:
        bool canArrange(vector<int> & nums, int k) {
            int n = nums.size();
            vector<int> arr;
            int count = 0;
            for (int i = 0; i < n; i++) {
                nums[i] = ((nums[i] % k) + k) % k;
                if (nums[i] != 0) {
                    arr.push_back(nums[i]);
                } else {
                    count++;
                }
            }

            sort(arr.begin(), arr.end());
            int i = 0;
            int j = arr.size() - 1;
            if (count % 2 != 0) {
                return false;
            }
            while (i <= j) {
                if ((arr[i] + arr[j]) % k != 0) {
                    return false;
                }
                i++;
                j--;
            }
            return true;
        }
    
};