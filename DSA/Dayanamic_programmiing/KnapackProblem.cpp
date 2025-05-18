#include <bits/stdc++.h>
using namespace std;

/*
problem Description:
 A thief robbing a store and find n items 
 the ith item has a weight w[i] and a value v[i]
 the thief(the Knapack) can carry a maximum weight of W



n = 5
c = 10
w = {2, 3, 4, 5, 9}
v = {3, 4, 5, 6, 10}


the implementation of brute force method (recursive)
the time complexity of this method is O(2^n)
the space complexity of this method is O(n)


*/
// c - capacity
// w - weights 
// p - profits 





int knapsack_bruteforce(int index ,int c, vector<int>&w, vector<int>&p ){

    if ( index == 0 || c == 0){
        return 0;
    }

    if (w[index-1] > c ){
        return knapsack_bruteforce(index-1, c, w, p);
    }

    int include = p[index-1] + knapsack_bruteforce(index-1, c- w[index-1], w, p);
    int exclude = knapsack_bruteforce(index-1, c, w, p);
    return max(include, exclude);






}








int main(){
    int n = 3;
    int c = 8;

    vector<int> w = {3, 2 , 4};
    vector<int> p = { 6, 8, 7};


    cout << knapsack_bruteforce(n, c, w, p);



}