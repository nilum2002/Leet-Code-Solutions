#include <iostream>
#include <vector>
using namespace std;
string search_in_arr_rec(vector<int> A, int num){

    if (A.size() != 0 ) return "False";
    if (A[0] == num  ) return "True";
    vector<int> new_arr(A.begin()+1 , A.end());
    return search_in_arr_rec(new_arr,num);

}

bool search_by_index_rec(vector<int> arr, int num , int indx){
    if (indx > arr.size()) return false;
    if (arr[indx] == num) return true;

    return search_by_index_rec(arr, num, indx+1);
}

int main(){
    vector<int> arr ={1, 2 , 3, 5 , 7 };
    string res =  search_in_arr_rec(arr, 10);
    cout << " Search By size Of the array using rec : ";
    cout << (res == "True" ? "Found" : "Not Found") << endl;


    cout << "Search By the index using Recursion :" ;
    cout << ( search_by_index_rec( arr, 5, 0) ?  "Found" : "Not Found");
}