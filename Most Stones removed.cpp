class Solution {
public:
	int find(unordered_map<int, int> &parent, int x){
        //cout << "THIS IS FIND" << endl;
        if(parent[x] == x){
            return x;
        }
        int px = find(parent, parent[x]);
        parent[x] = px;
        return px;
    }
    
    bool unionofdsu(unordered_map<int, int> &parent, unordered_map<int, int> &rank, int a, int b){
        //cout << "THIS IS UNION" << endl;
        int la = find(parent, a);
        int lb = find(parent, b);
        if(la == lb){
        	return false;
        }
        else if(la != lb){
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
        return true;
    }
    int removeStones(vector<vector<int>>& stones) {

        unordered_map<int, int> parent;
        unordered_map<int, int> rank;
        //initialise rank

        int count = 0;

        for(int i = 0; i < stones.size(); i++){
        	int x = stones[i][0];
        	int y = 0 - 1 - stones[i][1];

        	if(parent.count(x) == 0){
        		count++;
        		parent[x] = x;
        		rank[x] = 1;
        	}
        	if(parent.count(y) == 0){
        		count++;
        		parent[y] = y;
        		rank[y] = 1;
        	}
        	if(unionofdsu(parent, rank, x, y)){
        		count--;
        	}
        }
        return stones.size() - count;
    }
};