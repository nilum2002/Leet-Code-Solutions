

#include <bits/stdc++.h>

using namespace std;




// this approch takes O(n) time complexity

bool containsDuplicate(vector<int>& nums) {

    // two points approch 

    sort(nums.begin(), nums.end());


    int left = 0;
    int right = 1;


    while(right < nums.size()){
        if (nums[right] == nums[left]){
            return true;
        }
        else{
            right++;
            left++;
        }
    }
    return false;
}


int main(){

    vector<int> arr = {1, 2 , 3 ,1};


    cout << containsDuplicate(arr);



}