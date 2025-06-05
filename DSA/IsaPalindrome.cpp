#include <iostream>



using namespace std;


bool isPalindrome(string S, int start, int end){
    if ( start >= end){
        return true; // "" , "b"
    }

    if ( S[start] != S[end]) return false;


    return isPalindrome(S, start+1, end-1);
}



int main(){
    string S = "ab";
    cout << (isPalindrome(S, 0, S.size()-1 ) ? "Is a Palindrome" : "Not a Palindrome");
}