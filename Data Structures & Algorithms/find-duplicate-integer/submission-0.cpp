class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        unordered_set<int> set;
        for(int i=0;i<n;i++){
            if(set.find(nums[i]) != set.end()){
                ans = nums[i];
            }
            set.insert(nums[i]);
        }   
        return ans;
    }
};
