#include <bits/stdc++.h>
using namespace std;

/**
 * Modified implementation of stack to have min()/max() functions
**/

template<typename T>
struct mstack{
private:
    std::stack<T> base, lower, upper;
    size_t size_ {0};
public:
    void push(T x){
        size_++;
        base.push(x);
        T new_min = lower.empty()? x : std::min<T>(x, lower.top());
        T new_max = upper.empty()? x : std::max<T>(x, upper.top());
        lower.push(new_min);
        upper.push(new_max);
    }
    void pop(){
        assert(size_ > 0);
        size_--;
        base.pop();
        lower.pop();
        upper.pop();
    }
    T top(){
        return base.top();
    }
    size_t size(){
        return size_;
    }
    bool empty(){
        return size_ == 0;
    }
    T min(){
        assert(size_ > 0);
        return lower.top();
    }
    T max(){
        assert(size_ > 0);
        return upper.top();
    }
};

int main(){
    cin.tie(0)->sync_with_stdio(0);

    stack<int> base, lower, upper;

    auto push = [&](int x)->void{
        base.push(x);
        int new_min = lower.empty()? x : std::min(x, lower.top());
        int new_max = upper.empty()? x : std::max(x, upper.top());
        lower.push(new_min);
        upper.push(new_max);
    };

    auto pop = [&]()->void{
        assert(base.size() > 0);
        base.pop();
        lower.pop();
        upper.pop();
    };

    auto smin = [&]()->int{
        assert(base.size() > 0);
        return lower.top();
    };
    auto smax = [&]()->int{
        assert(base.size() > 0);
        return upper.top();
    };



    return 0;
}
