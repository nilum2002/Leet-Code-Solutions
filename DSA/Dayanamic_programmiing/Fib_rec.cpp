#include <bits/stdc++.h>
using namespace std;


int  fib_n(int n){
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fib_n(n-1) + fib_n(n-2);
}




int main(){

     cout << fib_n(5);


}