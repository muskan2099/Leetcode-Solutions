class Solution {
public:
    void helper(vector<vector<int>>& grid, int i, int j){
        int r = grid.size();
        int c = grid[0].size();
        if(i >= r || i < 0 || j >= c || j < 0 || grid[i][j] == 0 || grid[i][j] == 2){
            return;
        }
        grid[i][j] = 2;
        helper(grid, i + 1, j);
        helper(grid, i - 1, j);
        helper(grid, i, j + 1);
        helper(grid, i, j - 1);
        
    }
    int numEnclaves(vector<vector<int>>& grid) {
        
        // for top row
        for(int i = 0; i < grid[0].size(); i++){
            if(grid[0][i] == 1){
                helper(grid, 0, i);
            }
        }
        //for last row
        for(int i = 0; i < grid[0].size(); i++){
            if(grid[grid.size() - 1][i] == 1){
                helper(grid, grid.size() - 1, i);
            }
        }
        //for first col
        for(int i = 0; i < grid.size(); i++){
            if(grid[i][0] == 1){
                helper(grid, i, 0);
            }
        }
        //for last col
        for(int i = 0; i < grid.size(); i++){
            if(grid[i][grid[0].size() - 1] == 1){
                helper(grid, i, grid[0].size() - 1);
            }
        }
        int count = 0;
        
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1){
                    count++;
                }
            }
        }
        return count;
    }
};