class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();
        vector<int> hash1(26,0);
        vector<int> hash2(26,0);
        for(int i =0;i<n1;i++){
            hash1[s1[i]-'a']++;
        }
        int l=0;
        for(int i=0;i<n2;i++){
            hash2[s2[i]-'a']++;

            if(i-l+1 > n1){
                hash2[s2[l]-'a']--;
                l++;
            }
            if(i-l+1 == n1 && hash1 == hash2){
                return true;
            }
        }
        return false;
    }
};
