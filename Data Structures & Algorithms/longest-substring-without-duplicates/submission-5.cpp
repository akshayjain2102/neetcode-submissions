class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int maxl = 0;
        int length = 0;
        for(int i=0;i<n;i++){
            int hash[255] = {0};
            for(int j=i;j<n;j++){
                if(hash[s[j]] == 1) break;
                length = j-i+1;
                hash[s[j]]++;
            }
            maxl = max(length,maxl);
        }
        return maxl;
    }
};
