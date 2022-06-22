#include <bits/stdc++.h>
using namespace std;

template<typename T> struct mqueue{
private:
    typedef std::array<std::stack<T> , 3> AST;
    AST left, right;
    void push_3(AST &A, T x){
        A[0].push(x);
        if(A[1].empty())A[1].push(x);
        else A[1].push(std::min<T>(x, A[1].top()));
        if(A[2].empty())A[2].push(x);
        else A[2].push(std::max<T>(x, A[2].top()));
    }
    void pop_3(AST &A){
        A[0].pop(); 
        A[1].pop(); 
        A[2].pop(); 
    }
    void refill(){
        if(left[0].empty()){
            while(!right[0].empty()){
                push_3(left, right[0].top());
                pop_3(right);
            }
        }
    }
public:
    void push(T x){
        push_3(right, x);
    }
    void pop(){
        refill();
        pop_3(left);
    }
    
    bool empty(){
        return (left[0].empty() && right[0].empty());
    } 
    int size(){
        return left[0].size() && right[0].size();
    }
    T front(){
        refill();
        assert(!empty());
        return left[0].top();
    }
    T min(){
        T a = left[1].empty()?numeric_limits<T>::max():left[1].top();
        T b = right[1].empty()?numeric_limits<T>::max():right[1].top();
        assert(!empty());
        return std::min<T>(a, b);
    }
    T max(){
        T a = left[2].empty()?numeric_limits<T>::min():left[2].top();
        T b = right[2].empty()?numeric_limits<T>::min():right[2].top();
        assert(!empty());
        return std::max<T>(a, b);
    }
};

int main(){
    mqueue<int> k;
    k.push(10);
    k.push(100);
    cout << k.min() << '\n';
    cout << k.max() << '\n';
    return 0;
}