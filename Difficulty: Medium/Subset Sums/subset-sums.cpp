//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  void func(int index,int sum,vector<int> &arr,vector<int> &subsum,int n){
     
      if(index==n){
          subsum.push_back(sum);
          return;
      }
      func(index+1,sum+arr[index],arr,subsum,n);
      func(index+1,sum,arr,subsum,n);
    
  }
    vector<int> subsetSums(vector<int> arr, int n) {
       vector<int>subsum;
       int sum=0;
       func(0,sum ,arr,subsum,n);
       return subsum;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr, N);
        sort(ans.begin(), ans.end());
        for (auto sum : ans) {
            cout << sum << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends