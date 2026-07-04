class Solution {
public:
    int maxArea(vector<int>& heights) {
       int i = 0;
       int j = heights.size()-1;
       int ans = 0;
       while(i < j) {
        int area = min(heights[i],heights[j])*(j-i);
        ans = max(area, ans);
        if(heights[i] <= heights[j]){
          i++;
        }
        else if(heights[i] > heights[j]){
          j--;
        }
       }
       return ans; 
    }
};
