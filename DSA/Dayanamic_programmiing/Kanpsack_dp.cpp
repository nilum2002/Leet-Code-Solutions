#include<bits/stdc++.h>
using namespace std;




/* 


the time complexity of this method is O(n*w)
the space complexity of this method is O(n*w)
w- weights 


*/



int knapsack_dp(int n, int c, vector<int>&w, vector<int> &p){



    vector<vector<int>> dp(n+1, vector<int>(c+1, 0));


    for (int i = 1; i <= n ; i++){ // weights 
        for (int j = 0; j <= c ; j++){ // capacity
            if (w[i-1] <= c){
                dp[i][j] = max(dp[i-1][j],p[i-1] + dp[i-1][j-w[i-1]]  );
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    // for (int i = 1 ; i < dp.size(); i++){
    //     for (int j = 0; j < dp[i].size(); j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    return dp[n][c];

}





int main(){
    
    int n = 3;
    int c = 8;

    vector<int> w = {3, 2 , 4};
    vector<int> p = { 6, 8, 7};

 
    cout << knapsack_dp(n, c, w, p);



}
