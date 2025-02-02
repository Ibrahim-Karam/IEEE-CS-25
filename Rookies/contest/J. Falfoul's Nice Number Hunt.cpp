#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    int nice[]={6,9,66,69,96,99};
    while(t--){
        int n;
        cin>>n;
        for(int i=0;i<6;++i){
            if(nice[i]>=n){
                cout<<nice[i]<<endl;
                break;
            }
        }
    }

    return 0;
}
