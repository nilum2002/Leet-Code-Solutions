#include <bits/stdc++.h>
using namespace std;






// this is a bootom up approach
// the time complexity of this approach is O(n)
// the space complexity of this approach is O(n)
// the time complexity of the normal recursive approach is O(2^n)
// the space complexity of the normal recursive approach is O(n)
// the time complexity of the memoization approach is O(n)
// the space complexity of the memoization approach is O(n)
// the time complexity of the bottom up approach is O(n)
// the space complexity of the bottom up approach is O(n)
// the time complexity of the iterative approach is O(n)
// the space complexity of the iterative approach is O(1)


long long fib_n(int n){
    if (n ==0) return 0;
    if (n == 1) return 1;


    vector<long long> dp(n+1);
    dp[0] = 0;
    dp[1] = 1;


    for (int i = 2 ; i <= n; i++){
        dp[i] = dp[i-1] + dp[i-2] ;

    }


    return dp[n];






}



int main(){
    cout << fib_n(5);



}