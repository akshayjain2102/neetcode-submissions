class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> mpp;
        for(int i=0;i<n;i++){
            vector<int> freq(26,0);
            for(int j=0;j<strs[i].size();j++){
                freq[strs[i][j]-'a']++;
            }
            string key;
            for(int k=0;k<26;k++){
                key += to_string(freq[k])+"#";
            }
            mpp[key].push_back(strs[i]);
        }
         for(auto it: mpp){
            ans.push_back(it.second);
        }
        return ans;
    }
};
