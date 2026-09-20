class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
      // Abhi code karo
      int n = numbers.size();
      int s = 0;
      int e = n-1;

      while(s < e) {
        int currSum = numbers[s] + numbers[e];
        
        if(currSum == target)  return {s+1, e+1};
        else if(currSum < target)  s++;
        else e--;
      }  
      return {};
    }
};