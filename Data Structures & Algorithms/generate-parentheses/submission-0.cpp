class Solution {
public:
    void gep(vector<string>& ans,int o,int c,string& res,int n){
        if(res.length() == 2*n){
            ans.push_back(res);
            return;
        }
        if(o < n){
            res.push_back('(');
            gep(ans,o+1,c,res,n);
            res.pop_back();
        }
        if(c < o){
            res.push_back(')');
            gep(ans,o,c+1,res,n);
            res.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string res;
        gep(ans,0,0,res,n);
        return ans;
    }
};
