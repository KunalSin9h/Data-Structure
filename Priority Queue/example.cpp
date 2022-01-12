#include <iostream>
#include <queue> // for priority_queue
#include <set>
using namespace std;

#define ll long long
using str = string;
typedef pair<int, int> pi;


int main(){
    priority_queue<int, set<int>> pq;
    pq.insert(1000000);
    pq.intset(10);
    pq.insert(100);
    pq.insert(99);

    while(!pq.empty()){
        int res = pq.top(); 
        pq.pop();
        cout << res << " ";
    }
    cout << '\n';

     
    return 0;
}