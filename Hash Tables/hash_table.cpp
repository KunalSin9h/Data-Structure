#include <iostream>
#include <cmath>
using namespace std;
#define MAX 1000
typedef long long ll;

bool hash_table[2][MAX + 1];

bool search(int target){
    if(target >= 0){
        if(hash_table[0][target] == true)    
            return true;
    }
    else{
        if(hash_table[1][abs(target)] == true)
            return true;
    }
    return false;
}


void insert(int a[], int n){
    for(int i=0;i<n; ++i){
        if(a[i] >= 0)
            hash_table[0][a[i]] = true;
        else
            hash_table[1][abs(a[i])] = true;
    }
}

int main(){
    int a[] = {1, -2, -3, 3, 4, 53, -43};
    int n = sizeof(a)/sizeof(a[0]);
    insert(a, n);

    int target = 50;
    if(search(target))cout << "Yes" << endl;
    else cout << "No" << endl;



    return 0;
}