#include <iostream>
#include <vector>

using namespace std;


bool bin_search_rec(vector<int> arr,int n, int start , int end){
    if (start > end) return false;

    int mid = (start+ end)/2;
    if (arr[mid] == n) return true;
    if (arr[mid] > n){
        return bin_search_rec(arr, n, start, mid-1);
    }else{
        return bin_search_rec(arr,n , mid+1, end);
    }

}






int main(){
    vector<int> arr = { 1, 2 , 3, 9, 10};
    cout << (bin_search_rec(arr ,10, 0, arr.size()-1) ? "Found" : "Not Found" );
}