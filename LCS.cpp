#include<bits/stdc++.h>
using namespace std;

const int maxi = 1000;
int lcs(string x, string y, int x_len, int y_len, int dp[][maxi]){

    if(x_len == 0 or y_len == 0) return 0;

    if(dp[x_len-1][y_len-1] != -1) return dp[x_len-1][y_len-1];

    if(x[x_len-1] == y[y_len-1]){
        return dp[x_len-1][y_len-1] = lcs(x, y, x_len-1, y_len-1, dp) + 1;
    }

    else{
        return max(lcs(x, y, x_len, y_len-1, dp), lcs(x, y, x_len-1, y_len, dp));
    }

}

int main(){
    string x, y;
    cin >> x >> y;
    int len1 = x.length(), len2 = y.length();
    int dp[len1][maxi];
    memset(dp, -1, sizeof(dp));
    cout << lcs(x, y, len1, len2, dp) << endl;
    return 0;
}
