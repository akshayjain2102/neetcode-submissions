class Solution {
public:
    int findMin(vector<int> &nums) {
        int l=0,r = nums.size()-1;
        int ans = nums[0];
        while( l<=r){
            int mid = (l+r)/2;
            if(nums[l] > nums[mid]){
                if(nums[mid] < ans) ans = nums[mid];
                r = mid -1;
            }
            else{
                if(nums[l] < ans) ans = nums[l];
                l = mid +1;
            }
        }
        return ans;
    }
};
