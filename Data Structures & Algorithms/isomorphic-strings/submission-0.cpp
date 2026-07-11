class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.size();
        int m = t.size();
        if( n != m ) return 0;
        unordered_map<char,char> mpp1,mpp2;
        for(int i=0;i<m;i++){
            if(mpp1.find(t[i]) != mpp1.end()){
                if(s[i] != mpp1[t[i]] ) return 0;
            }
            if(mpp2.find(s[i]) != mpp2.end()){
                if(t[i] != mpp2[s[i]] ) return 0;
            }
            mpp1[t[i]] = s[i];
            mpp2[s[i]] = t[i];
        }
        return 1;
    }
};