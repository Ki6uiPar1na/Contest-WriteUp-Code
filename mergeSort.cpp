#include<bits/stdc++.h>
using namespace std;

void merge(vector<int> &v, int low, int mid, int high){
    vector<int> left(v.begin() + low, v.begin() + mid + 1);
    vector<int> right(v.begin() + mid + 1, v.begin() + high + 1);

    int i = 0, j = 0, k = low;

    while(i < left.size() and j < right.size()){
        if(left[i] < right[j]){
            v[k++] = left[i++];
        }
        else{
            v[k++] = right[j++];
        }

    }

    while (i < left.size()){
        v[k++] = left[i++];
    }

    while(j < right.size()){
        v[k++] = right[j++];
    }

    
}

void mergeSort(vector<int> &v, int low, int high){
    int mid = low + (high - low) / 2;
    if(low < high){
        mergeSort(v, low, mid);
        mergeSort(v, mid + 1, high);
        merge(v, low, mid, high);
    }
}
int main()
{
    int n; cin >> n; 
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }

    mergeSort(v, 0, n - 1);

    cout << "After sorting: ";
    for(int i = 0; i < n; i++){
        cout << v[i] << ' ';
    }
    cout << endl;
}