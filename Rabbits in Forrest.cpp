class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> hash;
        for(int i = 0; i < answers.size(); i++){
        	if(hash.count(answers[i]) == 0){
        		hash[answers[i]] = 1;
        	}
        	else{
        		hash[answers[i]]++;
        	}
        }
        int ans = 0;
        unordered_map<int, int> :: iterator it;
        for(it = hash.begin(); it != hash.end(); it++){

        	int groupsize = it->first + 1;
        	int groupcount = ceil((float)it->second / (float)groupsize);
        	ans += groupcount*groupsize;
        }
        return ans;
    }
};