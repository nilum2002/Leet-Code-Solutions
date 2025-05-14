#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;









int rob(vector<int>& nums) {
        // int money01 = 0;
        // int money02 = 0;
        // for (int i = 0; i < nums.size(); i++){
        //     if (i%2 ==0 ){
        //         money01 += nums[i];

        //     }else{
        //         money02 += nums[i];
        //     }
        // }
        // return max(money01, money02);

        int rob01 , rob02 = 0;


        for (auto n : nums){
            int temp = max(rob01+n, rob02);
            rob01 = rob02;
            rob02 = temp;
        }

        return rob02;
    }