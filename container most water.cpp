class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0;
        int finalans = INT_MIN;
        
        int i = 0;
         int j = height.size() - 1;
        
        while(i < j){
            ans = (j - i)*min(height[i], height[j]);
            if(ans > finalans){
                finalans = ans;
            }
            else{
                if(height[i] < height[j]){
                    i++;
                }
                else{
                    j--;
                }
            }
        }
        return finalans;
    }
};