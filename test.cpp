#include <bits/stdc++.h>
using namespace std;

vector<int> getElements(vector<int> arr, vector<vector<int>> queries) {
    vector<int> result;
    int columns = arr[0]; // Number of columns in each row of the 2D array

    for (const auto& query : queries) {
        int row = query[0] - 1; 
        int col = query[1] - 1; 

        
        int index = row * columns + col + 1; 
        result.push_back(arr[index]);
    }

    return result;
}

int main() {
    // Example usage
    vector<int> arr = {2, 4, 1, 34, 12, -33, 78, 44, 65, -14, -92};
    vector<vector<int>> queries = {{4, 1}, {3, 2}, {5, 1}, {1, 1}};
    
    vector<int> result = getElements(arr, queries);
    for (int val : result) {
        cout << val << endl;
    }

    return 0;
}
