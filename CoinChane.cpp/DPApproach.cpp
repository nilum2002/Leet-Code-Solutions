#include <bits/stdc++.h>
using  namespace std;




int coin_change(vector<int> coins, int amount){
    vector<int> dp (amount+1, amount+1);
    dp[0] = 0;
    for (int i = 1; i < amount+1; i++){
        for (int c : coins){
            if (i-c >= 0){
                dp[i] = min(dp[i], 1+dp[i-c]);
            }
            
    }
    }

    return dp[amount] != amount+1 ? dp[amount] : -1 ;
    
}




int main(){
    vector<int> coins = {1, 3, 4 ,7};
    int amount = 0;

    cout << coin_change(coins, amount)<< endl;
}