class Solution {
public:
    int maxArea(vector<int>& heights) {
      int n = heights.size();
      int ans = 0;
      int area;
      for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
          area = min(heights[i],heights[j])*(j-i);
          ans = max(ans,area);
        }
      }  
      return ans;
    }
};
