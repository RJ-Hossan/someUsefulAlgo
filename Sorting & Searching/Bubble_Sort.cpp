#include<bits/stdc++.h>
using namespace std;

void bubble_sort(int a[], int n){
    for(int i=0; i<n-1; i++){
        bool _swap = false;
        for(int j=0; j<n-i-1; j++){
            if(a[j] > a[j+1])                 // For descending order : if(a[j] < a[j+1]) 
                swap(a[j], a[j+1]);
                _swap = true;
        }
    }
    cout << "After Sorting : \n";
    for(int i=0; i<n; i++)  cout << a[i] << " ";        // Ascending Order
    cout << "\n";
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;  cin >> n;
        int a[n];
        for(int i=0; i<n; i++)  cin >> a[i];
        bubble_sort(a, n);
    }
    return 0;
}

// Time Complexity : O(n^2)
// Space Complexity : O(1)


/*
    Input : 
    2
    5
    10 20 3 -12 09
    6
    12 3 9 11 22 45

    Output:
    After Sorting : 
    -12 3 9 10 20 
    After Sorting : 
    3 9 11 12 22 45
*/