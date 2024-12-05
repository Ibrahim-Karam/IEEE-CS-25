#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    long long d;
    cin>>n>>d;
    long long x[n];
    for(int i=0;i<n;i++) {
        cin>>x[i];
    }
    long long countt=0;
    for(int i=0;i<n;i++) {
        int k=upper_bound(x+i,x+n,x[i]+d)-x-1;
        long long count=k-i+1;
        if (count>=3){
            countt+=((count-2)*(count-1))/2;
        }
    }

    cout<<countt<< endl;

    return 0;
}
