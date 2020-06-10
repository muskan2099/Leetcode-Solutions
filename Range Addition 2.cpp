class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        
        int firstmin = m;
        int secondmin = n;
        
        for(int i = 0; i < ops.size(); i++){
            firstmin = min(firstmin, ops[i][0]);
            secondmin = min(secondmin, ops[i][1]);
        }
        return firstmin*secondmin;
    }
};