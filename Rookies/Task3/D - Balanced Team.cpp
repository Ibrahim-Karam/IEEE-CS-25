#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr, arr + n);
    int maxx = 0;
    int left = 0;

    for (int right=0;right<n;right++){
        while(arr[right]-arr[left]>5) {
            left++;
        }
        maxx=max(maxx,right-left+1);
    }

    cout<<maxx<<endl;

    return 0;
}
