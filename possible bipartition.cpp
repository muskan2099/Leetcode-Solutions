class Solution {
public:
    bool helper(vector<vector<int>>& graph, int start, int *visited){
         bool flag = 0;
         queue<int> pending;
        //for group A == 10 
        //for group B == 20
        pending.push(start);
        visited[start] = 10;
        
        while(!pending.empty()){
            int front = pending.front();
            int group = visited[front];
            pending.pop();
            
            vector<int> neighbours = graph[front];
            
            for(int i = 0; i < neighbours.size(); i++){
                if(visited[neighbours[i]] == -1){
                    if(group == 10){
                        pending.push(neighbours[i]);
                        visited[neighbours[i]] = 20;
                    }
                    else{
                        pending.push(neighbours[i]);
                        visited[neighbours[i]] = 10;
                    }
                }
                else{
                    int ngroup = visited[neighbours[i]];
                    if(ngroup != group){
                        continue;
                    }
                    else if(ngroup == group){
                        flag = 1;
                    }
                }
            }
        }
        
        if(flag == 0){
            return true;
        }
        else{
            return false;
        }
    }
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        
        vector<vector<int>> graph(N);
        for(int i = 0; i < dislikes.size(); i++){
            graph[dislikes[i][0] - 1].push_back(dislikes[i][1] - 1);
            graph[dislikes[i][1] - 1].push_back(dislikes[i][0] - 1);
        }
        int *visited = new int[graph.size()];
        for(int i = 0; i < graph.size(); i++){
            visited[i] = -1;
        }
        //bool flag = 0;
        for(int i = 0; i < graph.size(); i++){
            if(visited[i] == -1){
                if(!helper(graph, i, visited)){
                    return false;
                }
            }
        }
       return true;
    }
};