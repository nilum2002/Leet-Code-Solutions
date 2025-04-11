#include <bits/stdc++.h>


using namespace std;


bool containsDuplicate(vector<int>& nums) {

    // two points approch 

    set<int> hash_set;  // Using unordered_set (hash set)

    for (int n : nums){
        if (hash_set.find(n) != hash_set.end()){
            return true ;
        }else{
            hash_set.insert(n);
        }
    }
    return false;
}


int main(){

    vector<int> arr = {1, 2 , 3 ,1};


    cout << containsDuplicate(arr);



}