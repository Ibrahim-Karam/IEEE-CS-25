#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll countValidSequences(const vector<int>& a, int k, int q) {
    ll result = 0;
    int n = a.size();
    int start = 0;
    while (start < n) {
        if (a[start] > q) {
            start++;
            continue;
        }
        int end = start;
        while (end < n && a[end] <= q) {
            end++;
        }
        int length = end - start;
        if (length >= k) {
            result += (ll)(length - k + 1) * (length - k + 2) / 2;
        }
        start = end;
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, k, q;
        cin >> n >> k >> q;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        cout << countValidSequences(a, k, q) << "\n";
    }
    return 0;
}
