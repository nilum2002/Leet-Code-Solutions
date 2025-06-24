#include <iostream>
#include <vector>
using namespace std;


bool binSearch(vector<int> arr, int n, int start,int end){

    while (start <= end ){
        int mid = (start + end)/2;

        if (arr[mid] == n) return true;
        if (arr[mid] > n){
            end = mid -1;
        }else{
            start = mid + 1;
    }
    }
    return false;
}

int main(){
    vector<int> arr = { 1, 2 , 3, 9, 10};
    cout << (binSearch(arr ,10, 0, arr.size()-1) ? "Found" : "Not Found" )<< endl;
    
    return 0;
}