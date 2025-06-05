#include <iostream>
#include <vector>


using namespace std;


int partition(vector<int> &arr, int start, int end){

    int pivot = arr[end];
    int i = start-1;


    for (int j = start; j < end ; j++){
        if (arr[j] < pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[end]);
    return i + 1;

}


void quick_sort(vector<int> &arr, int start , int end){
    if ( start < end){
        int pi = partition(arr, start,end);

        quick_sort(arr, start, pi-1);
        quick_sort(arr, pi+1, end);

    }
}




int main(){
    vector<int> arr = { -1, -5, 7, 2, 3, 5};


    quick_sort(arr, 0, arr.size()-1);


    for (int i = 0 ; i < arr.size(); i++){
        cout << arr[i] << " ";
    }


}