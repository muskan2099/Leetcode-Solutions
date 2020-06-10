class Solution {
public:
	int find(int* &parent, int nodes, int x){
        //cout << "THIS IS FIND" << endl;
        if(parent[x] == x){
            return x;
        }
        int px = find(parent,nodes, parent[x]);
        parent[x] = px;
        return px;
    }
    void unionofdsu(int * &parent, int* &rank, int nodes, int a, int b){
        //cout << "THIS IS UNION" << endl;
        int la = find(parent, nodes, a);
        int lb = find(parent, nodes, b);

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
    bool unionofdsu2(int * &parent, int* &rank, int nodes, int a, int b){
        //cout << "THIS IS UNION" << endl;
        int la = find(parent, nodes, a);
        int lb = find(parent, nodes, b);
        if(la == lb){
        	return true;
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
        return false;
    }
	int getindex(int row, int col, int n, int m){

		return row*m + col;
	}
    int regionsBySlashes(vector<string>& grid) {
    	int n = grid.size() + 1;
        int m = grid.size();
        int *parent = new int[n*n];
        int *rank = new int[n*n];
        for(int i = 0; i < n*n; i++){
        	parent[i] = i;
        	rank[i] = 1;
        }

        //making the boundary
        for(int i = 0; i < n; i++){
        	int indextop = getindex(0, i, n, n);
        	unionofdsu(parent, rank, n*n, 0, indextop);
        }
        for(int i = 0; i < n; i++){
        	int index = getindex(n-1, i, n, n);
        	unionofdsu(parent, rank, n*n, 0, index);
        }
        for(int i = 0; i < n; i++){
        	int index = getindex(i, 0, n, n);
        	unionofdsu(parent, rank, n*n, 0, index);
        }
        for(int i = 0; i < n; i++){
        	int index = getindex(i, n-1, n, n);
        	unionofdsu(parent, rank, n*n, 0, index);
        }

        //attending the queries
        int count = 0;
        for(int i = 0; i < m; i++){
        	for(int j = 0; j < m; j++){

        		if(grid[i][j] == '\\'){
        			int index1 = getindex(i, j, n, n);
        			int index2 = getindex(i+1, j+1, n, n);

        			if(unionofdsu2(parent, rank, n*n, index2, index1)){
        				count++;
        			}
        		}
        		else if(grid[i][j] == '/'){
        			int index1 = getindex(i, j+1, n, n);
        			int index2 = getindex(i+1, j, n, n);

        			if(unionofdsu2(parent, rank, n*n, index2, index1)){
        				count++;
        			}
        		}
        	}
        }
        return count + 1;
    }
};