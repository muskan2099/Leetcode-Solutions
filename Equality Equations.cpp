class Solution {
public:
	char find(unordered_map<char, char> &parent, char x){
        //cout << "THIS IS FIND" << endl;
        if(parent[x] == x){
            return x;
        }
        char px = find(parent, parent[x]);
        parent[x] = px;
        return px;
    }
    
    void unionofdsu(unordered_map<char, char> &parent, unordered_map<char, int> &rank, char a, char b){
        //cout << "THIS IS UNION" << endl;
        char la = find(parent, a);
        char lb = find(parent, b);
        
        if(la != lb){
            if(rank[la] > rank[lb]){
                parent[lb] = la;
            }
            else if(rank[la] < rank[lb]){
                parent[la] = lb;
            }
            else{
                parent[la] = lb;
                rank[lb]++;
            }
        }
    }
    bool equationsPossible(vector<string>& equations) {

        unordered_map<char, char> parent;
        unordered_map<char, int> rank;

        for(int i = 0; i < equations.size(); i++){

        	if(equations[i][1] == '='){

        		char ch1 = equations[i][0];
        		char ch2 = equations[i][3];

        		if(parent.count(ch1) == 0){
        			parent[ch1] = ch1;
        			rank[ch1] = 1;
        		}
        		if(parent.count(ch2) == 0){
        			parent[ch2] = ch2;
        			rank[ch1] = 1;
        		}
        		unionofdsu(parent, rank, ch1, ch2);
        	}        	
        }
        for(int i = 0; i < equations.size(); i++){

        	if(equations[i][1] == '!'){

        		char ch1 = equations[i][0];
        		char ch2 = equations[i][3];
                
                if(ch1 == ch2){
                    return false;
                }
               
        		if((parent.count(ch1) != 0 && parent.count(ch2) != 0) && find(parent, ch1) == find(parent, ch2)){
        			return false;
        		}
        	}
        }
        return true;
    }
};