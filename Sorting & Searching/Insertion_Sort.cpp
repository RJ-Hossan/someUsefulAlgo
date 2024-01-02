#include<bits/stdc++.h>

using namespace std;

void insertion_sort(int a[], int size){
    for(int i=1; i<size; i++){
        int key = a[i], j = i - 1;
        // For sorting descending order, change the sign to ">"
        while(key < a[j] and j>=0){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }
}

int main(){
    int t;
    cin>> t;
    while(t--){
        int n;
        cin >> n;
        int a[n];
        for(int i=0; i<n; i++)  cin >> a[i];
        insertion_sort(a, n);
        cout << "After sorting: \n";
        for(int i=0; i<n; i++)  cout << a[i] << " ";
        cout << endl; 
    }
    return 0;
}

// Sample Input and Output:
// 2
// 5
// 89 -34 5 23 -45
// After sorting:
// -45 -34 5 23 89 
// 4   
// 90 49 0 34
// After sorting:
// 0 34 49 90

// Space complexity: O(1)
// Time complexity: O(n^2)
// Stability : Yes