#include <iostream>
#include <string> 
using namespace std;

int main(){
    int T;
    cin >> T;
    while(T--){
        string n;
        cin >> n;
        int s = n.size();
        cout << (n[0] -  48) + (n[s-1] - 48) << endl;
    }
    return 0;
}