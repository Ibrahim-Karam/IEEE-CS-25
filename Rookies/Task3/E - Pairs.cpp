#include <iostream>
#include <unordered_set>
using namespace std;

int pairs(int k, int arr[], int n) {
    unordered_set<int> seen;
    int count = 0;

    for (int i = 0; i < n; i++) {
        if (seen.count(arr[i] - k)) {
            count++;
        }
        if (seen.count(arr[i] + k)) {
            count++;
        }
        seen.insert(arr[i]);
    }

    return count;
}

int main() {
    int n, k;
    cin >> n >> k;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << pairs(k, arr, n) << endl;

    return 0;
}
