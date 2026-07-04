class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        map<char, int> mpp;
        int left = 0;
        int length = 0;
        for(int r=0;r<n;r++){
            mpp[s[r]]++;
            while(mpp[s[r]] > 1){
                mpp[s[left]]--;
                left++;
            }
            length = max(length,r-left+1);
        }
        return length;
    }
};
