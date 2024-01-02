#include<bits/stdc++.h>
using namespace std;

void selection_sort(int a[], int size){
    for(int i=0; i<size-1; i++){
       int min_index = i;
       for(int j=i+1; j<size; j++){
          // To sorting the series in descending order, change the sign to '>'
          if(a[j] < a[min_index])
             min_index = j;
       }
       swap(a[min_index], a[i]);
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n];
        for(int i=0; i<n; i++) cin >> a[i];
        selection_sort(a, n);
        for(int i=0; i<n; i++) cout << a[i] << " ";
        cout << "\n";
    }
    return 0;
}

// Sample Input:
// 2
// 5
// 10 -3 23 54 69
 
// 6
// 9 -34 9 -45 33 89


// Sample Output:
// -3 10 23 54 69
// -45 -34 9 9 33 89 

// Time complexity: O(n^2)
// Space complexity: O(1)
