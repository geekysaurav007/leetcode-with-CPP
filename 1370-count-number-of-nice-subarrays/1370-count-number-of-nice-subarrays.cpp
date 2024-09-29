class Solution {
public:
    int numberOfSubarrays(vector<int>& arr, int k) {
        int count = 0, left = 0, right = 0, oddCount = 0, temp = 0;

        while (right < arr.size()) {
            // Increment odd count if the current element is odd
            if (arr[right] % 2 == 1) {
                oddCount++;
                temp = 0; // Reset temp when a new odd is added
            }

            // When the count of odd numbers exceeds k
            while (oddCount == k) {
                temp++; // Count valid subarrays for the current window
                if (arr[left] % 2 == 1)
                    oddCount--;
                left++;
            }

            count += temp; // Add temp to count for each valid odd number
                           // subarray ending at 'right'
            right++;
        }

        return count;
    }
    };