#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

bool uniqueOccurrences(vector<int>& arr) {
    unordered_map<int, int> count_map;

    // Count occurrences of each number
    for (int num : arr) {
        count_map[num]++;
    }

    unordered_set<int> occurrences;

    // Check if occurrence counts are unique
    for (const auto& pair : count_map) {
        if (!occurrences.insert(pair.second).second) { 
            return false; // Duplicate occurrence count found
        }
    }

    return true;
}

int main() {
    vector<int> arr = {1, 2, 2, 1, 1, 3};
    cout << (uniqueOccurrences(arr) ? "true" : "false") << endl;
}





