class Solution {
public:

    void subsets(vector<int>& nums,vector<int>& res,int idx,vector<vector<int>>& ans){
        if(idx == nums.size()){
            ans.push_back({res});
            return;
        }
        res.push_back(nums[idx]);
        subsets(nums,res,idx+1,ans);

        res.pop_back();
        subsets(nums,res,idx+1,ans);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> res;
        subsets(nums,res,0,ans);
        return ans;
    }

};
