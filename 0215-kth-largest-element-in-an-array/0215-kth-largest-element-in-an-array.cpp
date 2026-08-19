class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
       // Abhi Code Karo
       int n = nums.size();
       priority_queue<int, vector<int>, greater<int>> minHeap;
       for(int i=0; i<n; i++) {
        minHeap.push(nums[i]);
       } 

       while(minHeap.size() > k) {
        minHeap.pop();
       }
       return minHeap.top();
    }
};