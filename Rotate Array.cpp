class Solution {
public:
    void helper(vector<int>& nums, int start, int end){
        while(start <= end){
            int temp = nums[start];
            nums[start] = nums[end];
            nums[end] = temp;
            start++;
            end--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        
       
        int n = nums.size();
        if(n==1 || n == 0 || k ==0 || n == k){
            return;
        }
        k = k%n;
        int start = n-k;
        int end = n-1;
        
        helper(nums, start, end);
        
        start = 0;
        end = n-k-1;
        
        helper(nums, start, end);
        
        start = 0;
        end = n-1;
        
        helper(nums, start, end);
        
    }
};