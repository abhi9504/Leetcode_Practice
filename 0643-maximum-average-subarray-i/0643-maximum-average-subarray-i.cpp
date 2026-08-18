class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
      // Day 2  / 30
      int n = nums.size();
      int j = k-1;
      int sum = 0;
      int maxSum = 0;
      int i = 0;

      for(int i=0; i<=j; i++) {
        sum += nums[i];
      }  
      maxSum = sum;
      j++;

      while(j < n) {
        sum = sum - nums[i];
        i++;
        sum = sum + nums[j];
        j++;
        maxSum = max(sum, maxSum);
      }

      double avg =  maxSum / (double) k;
      
      return avg;
    }
};