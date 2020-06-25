#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(unordered_map<string, priority_queue<string, vector<string>, greater<string>>> &graph, string start, vector<string> &output){
        
        while(graph[start].size() != 0){
            string des = graph[start].top();
            graph[start].pop();
            
            dfs(graph, des, output);
        }
        output.push_back(start);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {

        vector<string> output;
        //priority_queue<string, vector<string>, greater<string>> heap;

        unordered_map<string, priority_queue<string, vector<string>, greater<string>>> graph;

        for(int i = 0; i < tickets.size(); i++){
        	string src = tickets[i][0];
        	string dest = tickets[i][1];

        	graph[src].push(dest);
        	//smaller first
        }
        //printgraph(graph);
        
        dfs(graph, "JFK", output);
        
        reverse(output.begin(), output.end());
        
        return output;
    }
};