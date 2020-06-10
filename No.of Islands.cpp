class Solution {
public:
    void helper(vector<vector<char>>& grid, int i, int j){
        int r = grid.size();
        int c = grid[0].size();
        if(i >= r || i < 0 || j >= c || j < 0 || grid[i][j] == '0'){
            return;
        }
        grid[i][j] = '0';
        helper(grid, i + 1, j);
        helper(grid, i - 1, j);
        helper(grid, i, j + 1);
        helper(grid, i, j - 1);
        
    }
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                
                if(grid[i][j] == '1'){
                    
                    helper(grid, i, j);
                    count++;
                }
            }
        }
        return count;
    }
};