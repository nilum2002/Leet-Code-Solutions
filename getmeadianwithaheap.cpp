#include <vector>
#include <queue>

using namespace std;

vector<double> runningMedian(vector<int> a) {
    priority_queue<int> left; // max-heap
    priority_queue<int, vector<int>, greater<int>> right; // min-heap

    vector<double> res;

    for (int num : a) {
        // Step 1: Insert into heaps
        if (left.empty() || num <= left.top())
            left.push(num);
        else
            right.push(num);

        // Step 2: Balance the heaps
        if (left.size() > right.size() + 1) {
            right.push(left.top());
            left.pop();
        } else if (right.size() > left.size()) {
            left.push(right.top());
            right.pop();
        }

        // Step 3: Calculate median
        if (left.size() == right.size()) {
            res.push_back((left.top() + right.top()) / 2.0);
        } else {
            res.push_back(left.top());
        }
    }

    return res;
}
