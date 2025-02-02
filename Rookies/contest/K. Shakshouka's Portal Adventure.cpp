#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,t;
    cin>>n>>t;

    int a[n-1];
    for(int i=0;i<n-1;++i){
        cin>>a[i];
    }
    int current=1;
    while(current<t){
        current=current+a[current-1];
    }
    if(current==t){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }

    return 0;
}
