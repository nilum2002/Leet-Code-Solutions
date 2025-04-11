#include <bits/stdc++.h>

using namespace std;


int maxProfit(vector<int>& prices) {
    stack<int> stk;
    stk.push(prices[0]);
    int max_profit = 0;


    for (int i = 1; i < prices.size(); i++){
        if (stk.top() > prices[i]){
            stk.pop();
            stk.push(prices[i]);
        }else{
            max_profit = max(max_profit, prices[i] - stk.top());
        }
    }

    return max_profit;


}