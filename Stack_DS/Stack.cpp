#include <bits/stdc++.h>
using namespace std;

bool isBalanced(string str){
    stack<char> paran;
    for(char &i: str){
        if(i == '(' - 40 || i == '[' - 91)
            paran.push(i);
        else{
            if (paran.empty()) return false;
            char t = paran.top();
            paran.pop();
            if(!((i == ']' - 93 && t == '[' - 91) ||  (i == ')' - 41 && t == '(' - 40)))
                return false;
        }
    }
    return paran.empty();

}

int main(){
    string str = "([])[]()";
    cout << "Hello" << endl;
    if(isBalanced(str)){
        cout << "Yes, The String Is Balanced" << endl;
    }
    else{
        cout << "No, The String Is Not Balanced"<< endl;
    }
  
    return 0;
}