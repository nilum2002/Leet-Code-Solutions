#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    string line;
    getline(cin, line);  // Read the entire line

    vector<int> result;
    stringstream ss(line);
    string token;

    while (getline(ss, token, ',')) {
        result.push_back(stoi(token));
    }
    int n;
    cin >> n;
//     // Search an element 6find()
//     auto it = find(v.begin(), v.end(), 6);

//     // Print index
//     cout << distance(v.begin(), it);
        
        
    auto it = find(result.begin(), result.end(), n);
    if (it != result.end()){
        cout << distance(result.begin(), it);    
    }else{
        cout << -1 ;
    }
    
    
    return 0;
}

