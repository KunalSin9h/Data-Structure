#include <iostream>
#include <list>
#include <map>
#include <vector>
using namespace std;

class Node{
public:
    string name;
    list<string> neb;

    Node(string n){
        this->name = n;
    }
};

class Graph{
    map<string, Node*> m;
public:
    Graph(const vector<string> &cities){
        for(const string &city : cities){
            m[city] = new Node(city);
        }
    }

    void addEdge(string x, string y, bool undir = false){
        m[x]->neb.push_back(y);
        if(undir)m[y]->neb.push_back(x);
    }

    void showGraph(){
        for(const auto &a : m){
            cout << a.first << " -> ";
            for(const auto &i: a.second->neb){
                cout << i << ", ";
            }
            cout << '\n';
        }
    }
};

/*
class Graph{
    int vertex;
    list<int> *l;
public:
    Graph(int v) : vertex{v}{
        l = new list<int>[vertex];
    }
    void addEdge(int i, int j, bool undir = true){
        l[i].push_back(j);
        if(undir)l[j].push_back(i);
    }
    void showGraph(){
        for(int i = 0; i < vertex; ++i){
            cout << i << " -> ";
            for(const int &node : l[i])cout << node << ' ';
            cout << endl;
        }
    }
};
*/

int main(){
    vector<string> loc{"New-Market", "City", "Boat-Club", "Manisha", "MP-Nagar"};
    Graph Google_Maps(loc);

    Google_Maps.addEdge("New-Market", "City");
    Google_Maps.addEdge("City", "MP-Nagar");
    Google_Maps.addEdge("MP-Nagar", "Manisha");
    Google_Maps.addEdge("Manisha", "Boat-Club");
    Google_Maps.addEdge("Boat-Club", "New-Market");
    Google_Maps.addEdge("Manisha", "City");

    Google_Maps.showGraph();

    return 0;
}