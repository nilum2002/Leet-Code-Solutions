#include <bits/stdc++.h>


using namespace std;



int max_sum_arr(vector<int> nums){
    int max_sum = nums[0];
    int curr_sum = nums[0];


    for (int i = 1; i < nums.size(); i++){
        curr_sum = max(curr_sum+ nums[i], nums[i]);
        max_sum = max( curr_sum, max_sum);
    }

    return max_sum;


}
