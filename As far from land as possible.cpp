class Solution {
public:
    int maxDistance(vector<vector<int>>& matrix) {
        int ans = 0;
        //count, row, col
        queue<pair<int, pair<int, int>>> made;
        
        
        //adding all 1s
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[i].size(); j++){
                if(matrix[i][j] == 1){
                    made.push(make_pair(0, make_pair(i, j)));
                }
            }
        }
        
        while(!made.empty()){
            pair<int, pair<int, int>> front = made.front();
            
            int count = front.first;
            int row = front.second.first;
            int col = front.second.second;
            ans = max(ans, count);
            made.pop();
            
            //for top
            if(row > 0 && matrix[row - 1][col] == 0){
                matrix[row - 1][col] = 1;
                made.push(make_pair(count + 1, make_pair(row - 1, col)));
                
            }
            //for bottom
            if(row < matrix.size() - 1 && matrix[row + 1][col] == 0){
                matrix[row + 1][col] = 1;
                made.push(make_pair(count + 1, make_pair(row + 1, col)));
                
            }
            //for right
            if(col < matrix[row].size() - 1 && matrix[row][col + 1] == 0){
                matrix[row][col + 1] = 1;
                made.push(make_pair(count + 1, make_pair(row, col + 1)));
                
            }
            //for left
            if(col > 0 && matrix[row][col - 1] == 0){
                matrix[row][col - 1] = 1;
                made.push(make_pair(count + 1, make_pair(row, col - 1)));
                
            }
        }
        if(ans == 0){
            return -1;
        }
        else{
            return ans;
        }
    }
};