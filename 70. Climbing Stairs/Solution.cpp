#include <iostream>
#include <vector>

using namespace std;



int climbStairs(int n) {
    if (n == 1 ){
        return 1;
    }
    if (n==2){
        return 2;
    }

    // when you use dynamic programming approach it will not get Time limit exceeding error 
    // return climbStairs(n-1) +  climbStairs(n-2);

    vector<int> dp = {1, 2};
    for (int i = 2 ; i < n; i++){
        dp.push_back(dp[dp.size()-1]+ dp[dp.size()-2]);
    }
    return dp[dp.size()-1];
    
}














int main(){
    int c;
    cin >> c;
    cout << climbStairs(c) << endl;




}