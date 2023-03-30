#include<bits/stdc++.h>
using namespace std;

int binary_search(int a[], int target, int low, int high){
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(a[mid] == target)    return mid;
        else if(a[mid] < target)   low = mid + 1;
        else    high = mid - 1;
    }
    return -1;
    // cout << "The target element found at index no : " << index << endl;
}

int main(){
    int t;  cin >> t;
    while(t--){
        int n;  cin >> n;
        int a[n];
        for(int i=0; i<n; i++)  cin >> a[i];
        sort(a, a+n);
        int x;  cin >> x;
        if(binary_search(a, x, 0, n-1) == -1) cout << "The element isn't in the list.\n";
        else{
            cout << "The target element found at index no : ";
            cout << binary_search(a, x, 0, n-1) << endl;    // Indexing 0 base
        }
    }
    return 0;
}

/*
    Time Complexity: O(log n)
    Auxiliary Space: O(1)
*/
