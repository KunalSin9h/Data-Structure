/**
 * 5. Finding the shortest cycle in a directed unweighted graph!
 *
 * Description : Start a breadth-first search from each vertex. As soon as we try to go from the current vertex back to the source vertex, 
 *               we have found the shortest cycle containing the source vertex.
 *               At this point we can stop the BFS, and start a new BFS from the next vertex. 
 *               From all such cycles (at most one from each BFS) choose the shortest.
 *
 * Just like Checking The Existence of Cycle in Graph, we can check from each vertex:{Source vertex} and we found the cycle note the lenght
 * and break and start new BFS from next Cycle
 *
 * Time : O(v^2)
 **/

#include <iostream>
#include <vector>
using namespace std;

int main(){

    // input for directed graph
    int v, e;
    cin >> v >> e;

    std::vector<vector<int>> G(v);
    while(e--){
        int x, y;
        cin >> x >> y;
        x--;y--;
        G[x].emplace_back(y);
    }

        


    return 0;
}

