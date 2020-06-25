#include <bits/stdc++.h>
using namespace std;
int kadane(int input[], int n){
	int sum = 0;
	int maxsum = INT_MIN;

	for(int i = 0; i < 2*n; i++){
		sum += input[i%n];
		if(sum > maxsum){
			maxsum = sum;
		}
		if(sum < 0){
			sum = 0;
		}
	}
	return maxsum;
}
int Kconcat(int input[], int n, int k){
	int sumarray = 0;
	for(int i = 0; i < n; i++){
		sumarray += input[i];
	}

	int kad = kadane(input, n);

	//if sum is positive
	if(sumarray > 0){
		return kad + (k - 2)*sumarray;
	}

	else{

		return kad;
	}
}
int main(){
	int input[4] = {1,-2, 1};
	int k = 5;
	int output = Kconcat(input, 3, 2);
	cout << output << endl;
	return 0;
}