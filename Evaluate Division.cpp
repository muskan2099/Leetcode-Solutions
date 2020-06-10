class Solution {
public:
    double BFS(unordered_map<string, unordered_map<string, double>> graph, string start, string end){
        
        if(start == end){
            return 1.0;
        }
        
        queue<pair<string, double>> pending;
        unordered_map<string, bool> visited;
                
        pending.push(make_pair(start, 1.0));
        visited.insert({start, 1});
        
        while(!pending.empty()){
            pair<string, double> top = pending.front();
            pending.pop();
            
            string front = top.first;
            double temp = top.second;
            
            if(front == end){
                return temp;
            }
            
            unordered_map<string, double> :: iterator it;   
            
            for(it = graph[front].begin(); it != graph[front].end(); it++){ 
                
                if(visited.count(it -> first) == 0){
                                        
                        pending.push(make_pair(it -> first, temp*(it -> second)));
                        visited.insert({it -> first, 1});  
                }
            }
        }
        return -1.00;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        //constructing the graph;
        
        unordered_map<string, unordered_map<string, double>> graph;
        for(int i = 0; i < equations.size(); i++){
            graph[equations[i][0]].insert({equations[i][1], values[i]});
            graph[equations[i][1]].insert({equations[i][0], 1.0/values[i]});
        }
        vector<double> output;
        for(int i = 0; i < queries.size(); i++){
            if(graph.count(queries[i][0]) == 0 || graph.count(queries[i][1]) == 0){
                output.push_back(-1.00);
                continue;
            }
            double ans = BFS(graph, queries[i][0], queries[i][1]);
            output.push_back(ans);
        }
        return output;
    }
};