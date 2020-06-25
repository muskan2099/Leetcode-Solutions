class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> output(nums.size());
        int pro = 1;
        vector<int> prefix(nums.size());
        prefix[0] = nums[0];
        for(int i = 1; i < nums.size(); i++){
            prefix[i] = nums[i] * prefix[i-1];
        }
        for(int i = nums.size() - 1; i > 0; i--){
            
            output[i] = prefix[i - 1] * pro;
            pro = pro * nums[i];
        }
        output[0] = pro;
        return output;
    }
};