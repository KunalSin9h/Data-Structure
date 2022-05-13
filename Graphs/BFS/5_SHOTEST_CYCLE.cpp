/**
 * 5. Finding the shortest cycle in a directed unweighted graph!
 *
 * Discription : Start a breadth-first search from each vertex. As soon as we try to go from the current vertex back to the source vertex, 
 *               we have found the shortest cycle containing the source vertex.
 *               At this point we can stop the BFS, and start a new BFS from the next vertex. 
 *               From all such cycles (at most one from each BFS) choose the shortest.
 *
 * Just like Checking The Existence of Cycle in Graph, we can check from each vertex:{Source vertex} and we found the cycle note the lenght
 * and break and start new BFS from next Cycle
 *
 * Time : Poly
 **/

#include <iostream>
using namespace std;

int main(){



    return 0;
}

