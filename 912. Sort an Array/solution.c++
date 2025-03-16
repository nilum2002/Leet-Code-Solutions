#include <iostream>
#include <vector>
using namespace std; 

void merge(vector<int> &arr, int left, int mid, int right){
    int nl = mid - left + 1;
    int nr = right - mid ;
    vector<int> L(nl), R(nr);
    for (int i = 0; i <nl; i++){
        L[i] = arr[left+ i];
    }
    for (int i = 0; i <nr; i++){
        R[i] = arr[mid + 1 + i];
    }
    int i  = 0, j = 0, k = left;
    while ( i < nl && j < nr){
        if (L[i] < R[j]){
            arr[k] = L[i];
            k++;
            i++;
        }else{
            arr[k] = R[j];
            k++;
            j++;
        }
    }

    while (i < nl){
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < nr){
        arr[k] = R[j];
        j++;
        k++;
    }






}





void merge_sort(vector<int> &arr, int left, int right){
    if (left >= right){
        return;
    }
    int mid = (left+right)/2;
    merge_sort(arr, left, mid);
    merge_sort(arr, mid+1, right);
    merge(arr, left, mid, right);
}



vector<int> sortArray(vector<int>& nums) {
    merge_sort(nums, 0, nums.size()-1);
    return nums;
}

// use merge sort here - time complexity is O(nlogn)

int main(){
    vector<int> nums = {10, 2, 5, 4 , 1, 6, 3};
    sortArray(nums);
    cout << "[";
    for(int n: nums ){
        cout << n ;
    }
    cout << "]";
    cout << endl;
}