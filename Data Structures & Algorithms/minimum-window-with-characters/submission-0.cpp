class Solution {
public:
    string minWindow(string s, string t) {
        int n1 = s.size();
        int n2 = t.size();
        int stIDX = -1;
        int minL = INT_MAX;
        for(int i=0;i<n1;i++){
            int hash[256]={0};
            for(int j=0;j<n2;j++){
                hash[t[j]]++;
            }
            int count = 0;
            for(int j=i;j<n1;j++){
                if(hash[s[j]] > 0){
                    count++;
                }
                hash[s[j]]--;
                if(count == n2){
                    if(j-i+1 < minL){
                        minL = j-i+1;
                        stIDX = i;
                    }
                    break;
                }
            }
        }
        if(stIDX == -1) return "";
        return s.substr(stIDX,minL);
    }
};
