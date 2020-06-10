class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int ans = 0;
        //count, row, col
        queue<pair<int, pair<int, int>>> made;
        
        vector<vector<int>> output(matrix.size());
        
        for(int i = 0; i < matrix.size(); i++){
            output[i] = vector<int>(matrix[i].size());
        }
        
        //adding all 0s
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[i].size(); j++){
                if(matrix[i][j] == 0){
                    made.push(make_pair(0, make_pair(i, j)));
                    output[i][j] = 0;
                }
            }
        }
        while(!made.empty()){
            pair<int, pair<int, int>> front = made.front();
            
            int count = front.first;
            int row = front.second.first;
            int col = front.second.second;
            
            made.pop();
            
            //for top
            if(row > 0 && matrix[row - 1][col] == 1){
                matrix[row - 1][col] = 0;
                made.push(make_pair(count + 1, make_pair(row - 1, col)));
                output[row - 1][col] = count + 1;
            }
            //for bottom
            if(row < matrix.size() - 1 && matrix[row + 1][col] == 1){
                matrix[row + 1][col] = 0;
                made.push(make_pair(count + 1, make_pair(row + 1, col)));
                output[row + 1][col] = count + 1;
            }
            //for right
            if(col < matrix[row].size() - 1 && matrix[row][col + 1] == 1){
                matrix[row][col + 1] = 0;
                made.push(make_pair(count + 1, make_pair(row, col + 1)));
                output[row][col + 1] = count + 1;
            }
            //for left
            if(col > 0 && matrix[row][col - 1] == 1){
                matrix[row][col - 1] = 0;
                made.push(make_pair(count + 1, make_pair(row, col - 1)));
                output[row][col - 1] = count + 1;
            }
        }
        return output;
    }
};