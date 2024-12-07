#include <iostream>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;

int main() {
    int n;
    long long t;
    cin>>n>>t;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int maxx=0,left=0,right=0;
    long long currentsum=0;
   for(;right<n;right++){
    currentsum+=arr[right];
    while(currentsum>t){
        currentsum=currentsum-arr[left];
        left++;
    }
    maxx=max(maxx,right-left+1);
   }
   cout<<maxx<<endl;

    return 0;
}

