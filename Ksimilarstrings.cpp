class Solution {
public:

    int kSimilarity(string A, string B) {
        
        if(A== B){return 0;}
        queue<pair<string, int>> pending;
        pending.push(make_pair(A, 0));
        unordered_map<string, bool> visited;
        visited[A] = 1;
        
        while(!pending.empty()){

        	pair<string, int> front = pending.front();
            pending.pop();
            
        	string temp = front.first;
        	int count = front.second;
            //cout << temp << endl;
        	if(temp == B){
        		return count;
        	}
        	int index = 0;
            while(temp[index] == B[index]){
                index++;
            }
        	for(int i = index + 1; i < temp.length(); i++){
        		if(temp[i] == B[index]){
        			swap(temp[index], temp[i]);
                    
        			if(visited.count(temp) == 0){
                        pending.push(make_pair(temp, count+1));
                        visited[temp] = 1;
                    }
                    swap(temp[index], temp[i]);
        		}
        	}
        }
        return -1;
    }
};