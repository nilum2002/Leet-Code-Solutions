#include <iostream>

using namespace std;




void decent_number(int n) {
    if (n == 1) {
        cout << -1 << endl;
        return;
    }
    
    // (n/3)*3 gives the largest multiple of 3 less than or equal to n
    for (int fives =  (n/3)*3; fives >= 0; fives -= 3){
        int threes = n-fives;
        if (threes%5 == 0 && fives%3 == 0){
            for (int i = 0; i < fives; i++){
                cout << 5;
            }
            for (int i = 0; i < threes; i++){
                cout << 3;
            }
            cout << endl;
            return;
        }


        

    }
    cout << -1 << endl; // If no valid combination is found


}




int main(){

    int n;
    n = 7;

    decent_number(n);
}