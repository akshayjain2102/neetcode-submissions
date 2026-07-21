class Solution {
public:
    set<vector<int>> st;
    void comb(vector<int>& nums, int target,vector<vector<int>>& ans,vector<int>& res,int idx){
        if(target == 0){
            ans.push_back(res);
            return;
        }
        if(idx == nums.size() ||  target < 0) return;
        
        res.push_back(nums[idx]);
        comb(nums,target-nums[idx],ans,res,idx+1);
        res.pop_back();
        while( idx+1 < nums.size() && nums[idx] == nums[idx+1]) {
            idx++;
        }
        comb(nums,target,ans,res,idx+1);
    }
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> res;
        comb(nums,target,ans,res,0);
        return ans;
    }
};
