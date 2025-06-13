#include<iostream>
#include<vector>


using namespace std;

void heapify(vector<int> &arr, int n , int i){
    // i root 

    int largest = i;


    // left 
    int l = 2*i+1;
    // right 
    int r = 2*i+2;


    if ( l < n && arr[l]> arr[largest]){
        largest = l;
    }

    if (r < n && arr[r] > arr[largest]){
        largest = r;
    }

    if ( i != largest){
        swap(arr[i], arr[largest]);
        heapify(arr, n , largest);
    }

} 




void heapSort(vector<int>&arr, int n){


    // buid heap


    for (int i = 0; i < n/2-1; i++){
        heapify(arr, n, i);

    }


    // get the heap sort 

    for (int i = n-1 ; i >0;i-- ){
        swap(arr[0], arr[i]);
        // size of the array which is to be heapify is become i and the root is always be 0
        heapify(arr, i, 0);
    }



}



int main(){

    vector<int> arr = { -1, 5, 8, 6, 1, 2, 5};
    int n = arr.size();


    heapSort(arr, n);
    // print array 

    for (int i = 0; i < n ; i++){
        cout << arr[i] << " " ;

    }

    

}