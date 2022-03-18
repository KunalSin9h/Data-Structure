#include <bits/stdc++.h>
using namespace std;

// Explanation: https://stackoverflow.com/questions/27875691/need-a-clear-explanation-of-range-updates-and-range-queries-binary-indexed-tree/27877427#27877427
// or see Photo "Explanation_for_ru_rq.png" in this directory
struct Fenwick{
std::vector<int> T1; /* Normal range update/point query tree (T1)*/ 
std::vector<int> T2; /*Tree for Fixing Errors (T2)*/
int N;
Fenwick(int n) : N{n+1}{T1.assign(N, 0);T2.assign(N, 0);};
Fenwick(std::vector<int> &A) : Fenwick((int)A.size()){
    for(int i = 0;i<N-1; ++i) point_update(i, A[i]);
}
void update(std::vector<int> &T, int i, int x){
    for(++i; i < N; i += (i&(-i))) T.at(i) += x;
}
void range_update(int l, int r, int x){
    // Normal Range Update Point Query Tree (T1)
    update(T1, l, x);
    update(T1, r+1, -x);
    // Adding fix
    update(T2, l, x*(l-1));
    update(T2, r+1, -x*r); // simplified of : -x*(l-1) - (r-l+1)*x
}
void point_update(int i, int x){ // Usefull only for Constructing form A array
    range_update(i, i, x);
}
int point_query(std::vector<int> &T, int i){
    int res = 0;
    for(++i; i > 0; i -= (i&(-i)))res += T.at(i);;
    return res;
}
int prefix_sum(int i){
    // i is 0-Based indexing     
    return (point_query(T1, i)*(i + 1) - point_query(T2, i)); // Error - Fix := Ans
}
int range_query(int l, int r){
    return prefix_sum(r) - prefix_sum(l-1);
}
int get_element(int i){
    return range_query(i, i);
}
};

int main(){
    cin.tie(0)->sync_with_stdio(0);

    vector<int> A{1, 1, 1, 1, 1};

    Fenwick F(A);
    // 1 1 1 1 1 1
    // 11 11 11 1 1
    F.range_update(0, 2, 10);
    F.point_update(4,  500);
    cout << F.get_element(0) << '\n'; // 11
    cout << F.get_element(1) << '\n'; // 11
    cout << F.get_element(2) << '\n'; // 11
    cout << F.get_element(3) << '\n'; // 1
    cout << F.get_element(4) << '\n'; // 501

    /*
    cout << F.range_query(0, 1) << '\n'; // 20
    cout << F.range_query(2, 2) << '\n'; // 10 
    cout << F.range_query(3, 3) << '\n'; // 0
//    F.range_update(3, 4, 500);
    cout << F.range_query(3, 4) << '\n'; // 100
    cout << F.range_query(4, 4) << '\n'; // 500
    */
    return 0;
}