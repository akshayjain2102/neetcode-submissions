class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size();
        int m = t.size();
        if( n != m) return false;
        vector<int> hash1(26,0), hash2(26,0);
        for(int i =0;i<n;i++){
            hash1[s[i]-'a']++;
            hash2[t[i]-'a']++;
        }
        if(hash1 == hash2) return true;
        return false;

    }
};
