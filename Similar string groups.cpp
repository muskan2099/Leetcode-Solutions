class Solution {
public:
	int find(vector<int> &parent, int x){
        //cout << "THIS IS FIND" << endl;
        if(parent[x] == x){
            return x;
        }
        int px = find(parent, parent[x]);
        parent[x] = px;
        return px;
    }
    
    bool unionofdsu(vector<int> &parent, vector<int> &rank, int a, int b){
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
    int numSimilarGroups(vector<string>& A) {

        unordered_map<string, int> hashing;
        vector<int> parent(A.size());
        vector<int> rank(A.size());
        for(int i = 0; i < A.size(); i++){
        	hashing[A[i]] = i;
        	parent[i] = i;
        	rank[i] = 1;
        }
        int count = A.size();
        //checking for similarity
        for(int i= 0; i < A.size() - 1; i++){
        	for(int j = i+1; j < A.size(); j++){

        		string s1 = A[i];
        		string s2 = A[j];
                
                //cout << s1 << " " << s2 << endl;
        		int k = 0;
        		int diff = 0;
        		while(k < s1.length()){

        			if(s1[k] != s2[k]){
        				diff++;
        			}
        			k++;
        		}

        		if(diff == 0 || diff == 2){
        			if(unionofdsu(parent, rank, i, j)){
        				count--;
        			}
        		}
        	}
        }
        return count;
    }
};