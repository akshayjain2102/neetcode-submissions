class Solution {
public:
    bool search(vector<int>& nums, int n){
        for(int i=0;i<nums.size();i++){
            if(n == nums[i]) return true;
        }
        return false;
    }
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i=0;i<n;i++){
            int count = 1;
            int x = nums[i];
            while( search(nums,x+1)){
                count++;
                x++;
            }
            ans = max(count,ans);
        }
        return ans;
    }
};
