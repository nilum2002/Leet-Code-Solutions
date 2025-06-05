#include<iostream>
#include <vector>



using namespace std ;

void selectionSort(vector<int>&arr){


    for (int i = 0; i < arr.size()-1; i++){
        int min_idx = i;

        for (int j = i +1; j < arr.size(); j++){
            if (arr[min_idx] > arr[j]){
                min_idx = j;
            }
        }
        swap(arr[i], arr[min_idx]);
    }
}



int main(){
    vector<int> arr = {-1, 5, -8, 10, 4};

    selectionSort(arr);


    for (int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }
}