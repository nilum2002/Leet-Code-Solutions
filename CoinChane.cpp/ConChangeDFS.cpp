#include<bits/stdc++.h>


using namespace std;

int dfs(vector<int> &coins , int amount , vector<int>& memo){
    if (amount == 0) return 0;
    if (amount < 0) return INT_MAX;
    if (memo[amount] != -1) return memo[amount];

    int min_coins = INT_MAX;
    for (int c : coins){
        int res = dfs(coins, amount-c, memo);
        if (res != INT_MAX){
            min_coins = min(min_coins, res+1);
        }
        
    }

    memo[amount] = min_coins;     
    return memo[amount];


}
int coin_Change(vector<int>coins, int amount){

    vector<int> memo(amount+1, -1);
    return dfs(coins,amount, memo);



}








int main(){
    vector<int> coins = {1 , 2, 5};
    int amount = 11;

    cout << coin_Change(coins, amount) << endl;

}