#include<bits/stdc++.h> 

using namespace std; 
int minSwaps(int arr[], int n) 
{ 	
	vector<pair<int, int>> storage; // for pair index
	for(int i = 0; i < n; i++){
		storage.push_back(make_pair(arr[i], i));
	} 
	sort(storage.begin(), storage.end());
	/*for(int i = 0; i < n; i++){
	    cout << storage[i].first << endl;
	}*/
	bool *visited = new bool[n];
	for(int i = 0; i < n; i++){
		visited[i] = 0;
	}
	int ans = 0;
	for(int i = 0; i < n; i++){
		//on storage
		int pairindex = storage[i].second;
		int originalindex = i;
		if(visited[i]){
		    continue;
		}
		if(pairindex == originalindex){
			continue;
		}
			int count = 0;
			int j = i;
			
			while(!visited[j]){
				visited[j] = 1;
				j = storage[j].second;
				count++;
			}
			if(count > 0){
			    ans += (count - 1);
			}
	}
	return ans;
} 

// Driver program to test the above function 
int main() 
{ 
	int arr[] = {1, 5, 4, 3, 2}; 
	int n = (sizeof(arr) / sizeof(int)); 
	cout << minSwaps(arr, n); 
	return 0; 
} 
