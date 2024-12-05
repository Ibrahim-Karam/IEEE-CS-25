#include <iostream>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;

int main() {
    int n,m;
    cin>>n>>m;
    long long arra[n];
    long long arrb[m];
    for(int i=0;i<n;i++){
        cin>>arra[i];
    }
    for(int i=0;i<m;i++){
        cin>>arrb[i];
    }
    long long r=0;
    for(int j=0;j<n;j++){
        int index=lower_bound(arrb, arrb+m , arra[j])-arrb;
        long long d1=(index<m) ? abs(arrb[index]-arra[j]) : LLONG_MAX;
        long long d2=(index>0) ? abs(arrb[index-1]-arra[j]) : LLONG_MAX;
        long long min_dist = min(d1,d2);
        r=max(r,min_dist);
    }
    cout<<r<<endl;


    return 0;
}
