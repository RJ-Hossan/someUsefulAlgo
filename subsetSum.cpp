#include<bits/stdc++.h>
using namespace std;

bool subset_sum(int n, int Set[], int sum){
	bool subset[n + 1][sum + 1];
	for(int i=0; i<=n; i++)  subset[i][0] = true;
	for(int i=1; i<=sum; i++)  subset[0][i] = false;

	for(int i=1; i<=n; i++) {
		for(int j=1; j<=sum; j++) {
			if(j<Set[i-1])
				subset[i][j] = subset[i-1][j];
			if(j>=Set[i-1])
				subset[i][j] = subset[i-1][j] || subset[i-1][j-Set[i-1]];
		}
	}
	return subset[n][sum];
}

int main(){
    int n, sum;
    cin >> n;
    int s[n];
    for(int i=0; i<n; i++) cin >> s[i];
    cin >> sum;
    if(subset_sum(n, s, sum) == true) cout << "Sum exist in the subset\n";
    else cout << "Sum does not exist in the subset\n";
	return 0;
}


