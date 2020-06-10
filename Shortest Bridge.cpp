class Solution {
public:
    int shortestBridge(vector<vector<int>>& A) {
        
        queue<pair<int, pair<int, int>>> pending;
        queue<pair<int, pair<int, int>>> finalpending;
        
        int ans = 0;
        bool flag = 0;
        //finding the start of one of the islands
        for(int i = 0; i < A.size();i++){
        	for(int j = 0; j < A[i].size(); j++){
        		if(A[i][j] == 1){
        			A[i][j] = 4;
        			flag = 1;
        			pending.push(make_pair(0, make_pair(i, j)));
        			finalpending.push(make_pair(0, make_pair(i, j)));
        			break;
        		}
                if(flag == 1){
                    break;
                }
        	}
            if(flag == 1){
                break;
            }
        }
        
        //running the dfs of first island, change the val and add to pending
        //cout << " SIZE" << pending.size() <<endl;
 		while(!pending.empty()){

 			pair<int, pair<int, int>> front = pending.front();
 			int row = front.second.first;
 			int col = front.second.second;

 			int count = front.first;
            

 			pending.pop();
 			finalpending.push(front);

 			//for top
            if(row > 0 && A[row - 1][col] == 1){
                A[row - 1][col] = 4;
                pending.push(make_pair(0, make_pair(row - 1, col)));
            }
            //for bottom
            if(row < A.size() - 1 && A[row + 1][col] == 1){
                A[row + 1][col] = 4;
                pending.push(make_pair(0, make_pair(row + 1, col)));
            }
            //for right
            if(col < A[row].size() - 1 && A[row][col + 1] == 1){
                A[row][col + 1] = 4;
                pending.push(make_pair(0, make_pair(row, col + 1)));
            }
            //for left
            if(col > 0 && A[row][col - 1] == 1){
                A[row][col - 1] = 4;
                pending.push(make_pair(0, make_pair(row, col - 1)));
            }
 		}       
 		//generating the final count;
 		//iterating on final pending;
        //cout << "FINAL SIZE" << finalpending.size() <<endl;
 		while(!finalpending.empty()){
 			pair<int, pair<int, int>> front = finalpending.front();
 			int row = front.second.first;
 			int col = front.second.second;

 			int count = front.first;
            //cout << count << endl;
            
 			finalpending.pop();

 			//for top
            if(row > 0 && A[row - 1][col] != 4){
            	if(A[row - 1][col] == 1){
            		ans = count;
                    break;
            	}
                else{
                    A[row - 1][col] = 4;
                finalpending.push(make_pair(count + 1, make_pair(row - 1, col)));
                }
            }
            //for bottom
            if(row < A.size() - 1 && A[row + 1][col] != 4){
            	if(A[row + 1][col] == 1){
            		ans = count;
                    break;
            	}
                else{
                    A[row + 1][col] = 4;
                finalpending.push(make_pair(count + 1, make_pair(row + 1, col)));
                }
            }
            //for right
            if(col < A[row].size() - 1 && A[row][col + 1] != 4){
            	if(A[row][col + 1] == 1){
            		ans = count;
                    break;
            	}
                else{
                    A[row][col + 1] = 4;
                finalpending.push(make_pair(count + 1, make_pair(row, col + 1)));
                }
            }
            //for left
            if(col > 0 && A[row][col - 1] != 4){
            	if(A[row][col - 1] == 1){
            		ans = count;
                    break;
            	}
                else{
                    A[row][col - 1] = 4;
                finalpending.push(make_pair(count + 1, make_pair(row, col - 1)));
                }
            }
 		}
        return ans;
    }
};
