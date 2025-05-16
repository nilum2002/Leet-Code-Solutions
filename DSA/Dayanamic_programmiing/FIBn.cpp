#include<bits/stdc++.h>
using namespace std;


// fib n using dynamic programming
// used method here is memoization
// this is a top down approach
// the time complexity of this approach is O(n)
// the space complexity of this approach is O(n)
// the time complexity of the normal recursive approach is O(2^n)
// the space complexity of the normal recursive approach is O(n)

unordered_map<int,long long> memo ;


int fib_n (int n){
    if (memo.find(n)!= memo.end()){
        return memo[n];
    }

    if ( n == 0) return 0;
    if (n == 1) return 1;

    
    memo[n] = fib_n(n-1) + fib_n(n-2);
    return memo[n];  


    
}







int main (){
    cout << fib_n(5);
    cout << endl;
    for (int i = 0; i < memo.size(); i++){
        cout << memo[i] << ", ";
    }




}