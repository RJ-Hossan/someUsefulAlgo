#include<bits/stdc++.h>
using namespace std;

void max_(int a[], int n){
    int checker = a[0];
    for(int i=0; i<n; i++){
        if(a[i] > checker){
            checker = a[i];
        }
    }
    cout << "Maximum Element : " << checker << endl;
}

void min_(int a[], int n){
    int checker = a[0];
    for(int i=0; i<n; i++){
        if(a[i] < checker){
            checker = a[i];
        }
    }
    cout << "Minimum Element : " << checker << endl;
}


int main(){
    int t, i = 1;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n];
        for(int i=0; i<n; i++)  cin >> a[i];
        cout << "Case : " << i << "\n";
        max_(a, n);     // Maximum Element Function Calling
        min_(a, n);     // Minimum Element Function Calling

        i++;
    }
    return 0;
}