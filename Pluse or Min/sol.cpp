#include <iostream>
using namespace std;



void sol(int a, int b , int c){
    if ( a < c || b < c){
        cout << "+" << endl;
    }else{
        cout << "-" << endl;
    }
}


int main(){
    int t;
    cin >> t;

    while (t--){
        int a, b, c;
        cin >> a >> b >> c;
        sol(a,b,c);
    }
}