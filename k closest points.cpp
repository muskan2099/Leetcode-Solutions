class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        int *ansarr = new int[points.size()];
        
        for(int i = 0; i < points.size(); i++){
        	int x = points[i][0];
        	int y = points[i][1];

        	int val = abs(x*x - y*y);

        	ansarr[i] = sqrt(val);
        }

        priority_queue<int> heap;
        for(int i = 0; i < k; i++){
        	heap.push(ansarr[i]);
        }
        for(int i = k; i < points.size(); i++){
        	if(ansarr[i] < ansarr[heap.top()]){
        		heap.pop();
        		heap.push(i);
        	}
        }
        vector<vector<int>> output(k, vector<int>(2,0));
        while(heap.size() != 0){
        	output[i][0] = points[heap.top()][0];
        	output[i][1] = points[heap.top()][1];

        	heap.pop();
        }
        return output;
    }
};