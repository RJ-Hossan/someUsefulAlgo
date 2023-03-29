#include <bits/stdc++.h>
using namespace std;

int _count(int n, int coin[], int sum){
	int table[sum+1];
	memset(table, 0, sizeof(table));
	table[0] = 1;
	for(int i=0; i<n; i++)
		for(int j=coin[i]; j<=sum; j++)
			table[j] += table[j-coin[i]];
	return table[sum];
}

int main(){
    int n, sum;
    cin >> n;
    int coin[n];
    for(int i=0; i<n; i++) cin >> coin[i];
    cin >> sum;
    cout << _count(n, coin, sum) << "\n";
    return 0;
}

