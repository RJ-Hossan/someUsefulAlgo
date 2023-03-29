#include<bits/stdc++.h>
using namespace std;

int maxi = 1e5+7;
int knapSack(int W, int weight[], int n, int value[]){
	int knap[n+1][W+1];
	for(int i=0; i<=n; i++){
		for(int w=0; w<=W; w++){
			if(i==0 || w==0) knap[i][w] = 0;
			else if(weight[i-1] <= w)
				knap[i][w] = max(knap[i-1][w], knap[i-1][w-weight[i-1]] + value[i-1]);
			else
				knap[i][w] = knap[i-1][w];
		}
	}
	return knap[n][W];
}
int main(){
	int n, max_weight;
	int weight[n+1], value[maxi];
	cin >> n >> max_weight;
	for(int i=0; i<n; i++)	cin >> weight[i];
	for(int i=0; i<n; i++)	cin >> value[i];
	cout << knapSack(max_weight, weight, n, value) << endl;
	return 0;
}
