#include <iostream>
#include <vector>


using namespace std;

void merge(vector<int> &arr, int start, int mid , int end){
    int nl = mid - start+1;
    int nr = end - mid;

    vector<int> left(nl);
    vector<int> right(nr);

    for (int i = 0; i < nl; i ++){
        left[i] = arr[start+i];
    }
    for (int i = 0; i < nl; i ++){
        right[i] = arr[mid+i+1];
    }


    int i = 0; 
    int j = 0;
    int k = start; 

    while ( i < nl && j < nr){
        if (left[i] <=  right[j]){
            arr[k] = left[i];
            k++;
            i++;
        }else{
            arr[k]= right[j];
            k++;
            j++;
        }
    }

    while (  i < nl){
        arr[k] = left[i];
        k++;
        i++;
    }

    while (  j < nr){
        arr[k] = right[j];
        k++;
        j++;
    }

}

void merge_sort(vector<int> &arr, int start , int end){
    if (start>= end) return ;

    if ( start < end){
        int mid = (start+end)/2;

        merge_sort(arr, start, mid);
        merge_sort(arr, mid+1, end);
        merge(arr, start, mid ,end );
    }
}




int main(){
    vector<int> unsorted_arr = { 2, 1, -1, 8, 7, 8};

    cout << "Unsorted array" << endl;
    for (int i =0;i <  unsorted_arr.size(); i++){
        cout << unsorted_arr[i] << " ";
    }cout << endl;



    cout<< "Sorted Array" << endl;

    merge_sort(unsorted_arr, 0, unsorted_arr.size()-1);

    for (int i= 0;i <  unsorted_arr.size(); i++){
        cout << unsorted_arr[i] << " ";
    }
    cout << endl;
    return 0;
}