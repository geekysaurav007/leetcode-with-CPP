class Solution {
public:
    int strStr(string haystack, string needle) {
        if (haystack.length() < needle.length()) {
            return -1;
        }
        for(int i=0;i<=haystack.length()-needle.length();i++){
            string c1=haystack.substr(i,needle.length());
           if(c1==needle){
            return i;
           }
        }
        return -1;
    }
};