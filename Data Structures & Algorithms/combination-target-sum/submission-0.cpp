class Solution {
public:
    set<vector<int>> st; // for unqiue numbers
    void comb(vector<int>& nums, int target,vector<vector<int>>& ans,vector<int>& res,int idx){
        if(idx == nums.size() || target < 0) return;
        if(target == 0){
             if(st.find(res) == st.end()) {
                ans.push_back(res);
                st.insert(res);
            }
            return;
        }
        res.push_back(nums[idx]);
        comb(nums,target-nums[idx],ans,res,idx+1); // single
        comb(nums,target-nums[idx],ans,res,idx); // multiple
        res.pop_back();
        comb(nums,target,ans,res,idx+1);     // exclusion
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> res;
        comb(nums,target,ans,res,0);
        return ans;
    }
};
