class Solution {
public:
    int count = 0;
    int val = -1;
    int size = 0;
    
	void dfs(vector<vector<int>>& graph, unordered_set<int> &infected, int sv, vector<int> &visited){
    
        
		if(infected.find(sv) != infected.end()){
			val = sv;
			count++;
		}
		size++;
        visited[sv] = 1;
		for(int i = 0; i < graph[sv].size(); i++){
			if(visited[i] == 0 && graph[sv][i] == 1){
				dfs(graph, infected, i, visited);
			}
		}
	}
    int minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial) {
        unordered_set<int> infected;
        int minimumval = INT_MAX;
        
        for(int i = 0; i < initial.size(); i++){
        	infected.insert(initial[i]);
        	minimumval = min(minimumval, initial[i]);
        }

        bool flag = 0;
        int ans;

        vector<int> visited(graph.size(), 0);
        int maximumsize = INT_MIN;
        for(int i = 0; i < graph.size(); i++){
        	               
        		count = 0;
        		val = -1;
        		size = 0;
            if(visited[i] == 0){
        		dfs(graph, infected, i, visited);
                
        		if(count == 1){
                    if(maximumsize < size){
                        maximumsize = size;
                        ans = val;
                    }
                    else if(maximumsize == size && val < ans){
                        ans = val;
                    }
                    flag = 1;
                }
        	}
        }
        if(flag == 1){
        	return ans;
        }
        return minimumval;
    }
};