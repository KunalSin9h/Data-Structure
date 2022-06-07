#include <iostream>
using namespace std;

#include <bits/debug.h>

// A -> a
// a -> a
char tosmall(char c){
    return c|' ';
}

// a -> A
// A -> A
char tolarge(char c){
    return c&'_';
}

// ind = (ind + 1)%n
// ind = (ind + n - 1)%n

int main(){

    while(true){

        char c;
        cin >> c;
    
        cout << tosmall(c) << '\n';

    }


    return 0;
}
