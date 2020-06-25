class Solution {
public:
    vector<vector<bool>>visited;
    vector<vector<int>> output;
	bool dfs(vector<vector<int>> grid, int row, int col, int initial, int color){
    
       // cout << "THIS IS DFS" << endl;
		if(row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || grid[row][col] != initial){
			return true;
		}

		if(visited[row][col]){
			return grid[row][col] != initial;
		}
		visited[row][col] = 1;
		if(dfs(grid, row + 1, col, initial, color)){
			output[row][col] = color;
		}
		if(dfs(grid, row - 1, col, initial, color)){
			output[row][col] = color;
		}
		if(dfs(grid, row, col + 1, initial, color)){
			output[row][col] = color;
		}
		if(dfs(grid, row, col - 1, initial, color)){
			output[row][col] = color;
		}

		return false;
	}
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int r0, int c0, int color) {
        
        int initial = grid[r0][c0];

        visited.resize(grid.size(), vector<bool>(grid[0].size(), 0));
        
        output = grid;
        dfs(grid, r0, c0, initial, color);

        return output;
    }
};