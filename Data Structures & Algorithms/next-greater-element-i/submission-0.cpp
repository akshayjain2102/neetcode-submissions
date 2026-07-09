class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            ans[i] = -1;
            for(int j=0;j<m;j++){
                if(nums2[j] == nums1[i]){
                    while(j<m){
                        if(nums2[j] > nums1[i]){
                            ans[i] = nums2[j];
                            break;
                        }
                        j++;
                    }
                }
                
            }
        }
        return ans;
    }
};