#include <iostream>
#include <vector>


using namespace std;
// j k
// 5 3 2 1
void insertionSort(vector<int> &arr){

    for (int i = 1 ; i < arr.size(); i++){
        int key = arr[i];
        int j = i -1;

        while (j >= 0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }

        arr[j+1] = key;
    }

}

int main(){
    vector<int> arr = { -1, -5, 7, 2, 3, 5};


    insertionSort(arr);


    for (int i = 0 ; i < arr.size(); i++){
        cout << arr[i] << " ";
    }


}