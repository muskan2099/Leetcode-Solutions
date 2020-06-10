class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int ans = 0;
        //count, row, col
        queue<pair<int, pair<int, int>>> orange;
        
        int twos = 0;
        int ones = 0;
        int zeros = 0;
        //adding all 0s
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(grid[i][j] == 2){
                    twos++;
                    orange.push(make_pair(0, make_pair(i, j)));
                }
                else if(grid[i][j] == 1){
                    ones++;
                }
                else{
                    zeros++;
                }
            }
        }
        //test case
        if(ones == 0){
            return 0;
        }
        if(ones != 0 && twos == 0){
            return -1;
        }
        if(zeros != 0 && twos == 0){
            return 0;
        }
        //running in four directions
        while(!orange.empty()){
            pair<int, pair<int, int>> front = orange.front();
            
            int count = front.first;
            int row = front.second.first;
            int col = front.second.second;
            
            orange.pop();
            
            //for top
            if(row > 0 && grid[row - 1][col] == 1){
                grid[row - 1][col] = 2;
                orange.push(make_pair(count + 1, make_pair(row - 1, col)));
                ans = max(ans, count+1);
            }
            //for bottom
            if(row < grid.size() - 1 && grid[row + 1][col] == 1){
                grid[row + 1][col] = 2;
                orange.push(make_pair(count + 1, make_pair(row + 1, col)));
                ans = max(ans, count+1);
            }
            //for right
            if(col < grid[row].size() - 1 && grid[row][col + 1] == 1){
                grid[row][col + 1] = 2;
                orange.push(make_pair(count + 1, make_pair(row, col + 1)));
                ans = max(ans, count+1);
            }
            //for left
            if(col > 0 && grid[row][col - 1] == 1){
                grid[row][col - 1] = 2;
                orange.push(make_pair(count + 1, make_pair(row, col - 1)));
                ans = max(ans, count+1);
            }
        }
        //checking if all are rotten
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }
        return ans;
    }
};