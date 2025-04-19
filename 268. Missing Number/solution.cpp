#include <bits/stdc++.h>


using namespace std;





int missingNumber(vector<int>& nums) {
    vector<int> arr;
    int sum = nums.size()*(nums.size()+1)/2;
    int tot = 0;
    for (int n: nums){
        tot += n;
    }
    return sum-tot;
}