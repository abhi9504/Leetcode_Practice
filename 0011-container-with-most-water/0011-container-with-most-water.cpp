class Solution {
public:
    int maxArea(vector<int>& height) {
      // Abhi Code Karo
      // Using Two Ptr
      int n = height.size();
      int s = 0;
      int e = n-1;
      int maxArea = 0;

      while(s < e) {
        int currArea = min(height[s], height[e]) * (e - s);
        maxArea = max(maxArea, currArea);

        if(height[s] < height[e])  s++;
        else e--;
      }  
      return maxArea;
    }
};