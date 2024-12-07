#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--) {
        int n;
        long long l, r;
        cin >> n >> l >> r;

        long long arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        sort(arr, arr + n);

        long long count = 0;

        for (int i = 0; i < n; i++) {
            long long left_bound = lower_bound(arr + i + 1, arr + n, l - arr[i]) - arr;
            long long right_bound = upper_bound(arr + i + 1, arr + n, r - arr[i]) - arr;

            count += (right_bound - left_bound);
        }

        cout << count << endl;
    }

    return 0;
}

