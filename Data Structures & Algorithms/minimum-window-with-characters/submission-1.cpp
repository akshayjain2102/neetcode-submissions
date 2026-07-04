class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        int hash[256]={0};
        for(int i=0;i<m;i++){
            hash[t[i]]++;
        }
        int stIDX = -1;
        int minL = INT_MAX;
        int r = 0,l=0;
        int count = 0;
        while(r < n){
            if(hash[s[r]] > 0) count++;
            hash[s[r]]--;
            while(count == m){
                if(r-l+1 < minL){
                    minL = r-l+1;
                    stIDX = l;
                }
                hash[s[l]]++;
                if(hash[s[l]] > 0) count --;
                l++;
            }
            r++;
        }
       
        if(stIDX == -1) return "";
        return s.substr(stIDX,minL);
    }
};
