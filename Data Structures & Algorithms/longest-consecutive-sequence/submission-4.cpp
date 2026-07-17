class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        unordered_set<int> st;
        for(int i=0;i<n;i++){
            st.insert(nums[i]);
        }
        int longest = 1;
        for(int i=0;i<n;i++){
            int x = nums[i];
            if(st.find(x-1) == st.end()){
                int count = 1;
                while(st.find(x+1) != st.end()){
                    count++;
                    x = x+1;
                }
                longest = max(longest,count);

            }
        }
        return longest;
    }
};
