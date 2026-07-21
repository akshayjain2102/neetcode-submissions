class Solution {
public:
    void subsets(vector<int>& nums,vector<vector<int>>& ans,int i,vector<int> res){
        if( i == nums.size() ){
            ans.push_back(res);
            return;
        }

        res.push_back(nums[i]);
        subsets(nums,ans,i+1,res);

        res.pop_back();
        int idx = i+1;
        while( idx < nums.size() && nums[idx] == nums[idx-1]) {
            idx++;
            }
        subsets(nums,ans,idx,res);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> res;
        subsets(nums,ans,0,res);
        return ans;
    }
};