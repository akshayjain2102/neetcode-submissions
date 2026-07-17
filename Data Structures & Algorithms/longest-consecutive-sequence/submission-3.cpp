class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       sort(nums.begin(),nums.end());
       int n = nums.size();
       if(n == 0) return 0;
       int lastsma = INT_MIN;
       int count = 0;
       int ans = 1;
       for(int i=0;i<n;i++){
        if(nums[i]-1 == lastsma){
            count++;
            lastsma = nums[i];
        }
        else if(lastsma != nums[i] ){
            lastsma = nums[i];
            count = 1;
        }
        ans = max(ans,count);
       } 
       return ans;
    }
};
