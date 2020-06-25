class Solution {
public:    

    int slidingPuzzle(vector<vector<int>>& board) {
        vector<vector<int>> possible = {{1,3}, {0, 2, 4}, {1, 5}, {0, 4}
                                       ,{1,3,5}, {2, 4}}; 
        string converted = "";
        string check = "123450";
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 3; j++){
                converted += to_string(board[i][j]);
            }
        }
        queue<pair<string, int>> pending;
        unordered_map<string, bool> visited;
        pending.push(make_pair(converted, 0));
        
        visited[converted] = 1;
        
        while(!pending.empty()){
            pair<string, int> front = pending.front();
            pending.pop();
            
        	string temp = front.first;
        	int count = front.second;
            
            //cout << temp << endl;
            if(temp == check){
                return count;
            }
            
            int index;
            for(int i = 0; i < 6; i++){
                if(temp[i] == '0'){
                    index = i;
                    break;
                }
            }
            vector<int> towork = possible[index];
            for(int i = 0; i < towork.size(); i++){
                
                swap(temp[towork[i]], temp[index]);
                
                if(visited.count(temp) == 0){
                    pending.push(make_pair(temp, count+1));
                    visited[temp] = 1;
                }
                
                swap(temp[towork[i]], temp[index]);
            }
        }
        return -1;
    }
};