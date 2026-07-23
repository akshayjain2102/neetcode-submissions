class Solution {
public:
    bool ispalindrome(string s){
        string s2 = s;
        reverse(s2.begin(),s2.end());
        return s==s2;
    }
    void palinpart(string s,vector<vector<string>>& ans,vector<string>& res){
        if(s.size() == 0){
            ans.push_back(res);
            return;
        }
        for(int i=0;i<s.size();i++){
            string part = s.substr(0,i+1);
            if(ispalindrome(part)){
                res.push_back(part);
                palinpart(s.substr(i+1),ans,res);
                res.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> res;
        palinpart(s,ans,res);
        return ans;
    }
};
