#include <bits/stdc++.h>
using namespace std;
long long Rescursion(int index,long long G1,long long G2, const vector<int> &x) {
    if(index==x.size()){
        return abs(G1-G2);
    }
    long long a= Rescursion(index+1,G1+x[index],G2,x);
    long long b= Rescursion(index+1,G1,G2+x[index],x);
    return min(a,b);
}
int main(){
    int n;
    cin>>n;
    vector<int> x(n);
    for(int i=0;i<n;i++){
        cin>>x[i];
    }
    cout<<Rescursion(0,0,0,x)<<endl;

    return 0;
}
