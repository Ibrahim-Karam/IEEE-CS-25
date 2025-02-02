#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    int piles[n];
    for(int i=0;i<n;++i){
        cin>>piles[i];
    }
    int c[n];
    c[0]=piles[0];
    for(int i=1;i<n;++i){
        c[i]=c[i-1]+piles[i];
    }
    int m;
    cin>>m;
    while(m--){
        int q;
        cin>>q;
        int pile=lower_bound(c,c+n,q) - c;
        cout<<pile+1<<endl;
    }

    return 0;
}
