#include <iostream>
using namespace std;
bool write(long long v,long long n,long long k){
    long long summ=0;
    long long curr=v;
    while(curr>0){
        summ+=curr;
        if (summ>=n)return true;
        curr/=k;
    }
    return summ>=n;
}

int main() {
    long long n, k;
    cin>>n>>k;

    long long left=1,right=n,result=n;

    while(left<=right){
        long long mid=left+(right-left)/2;
        if (write(mid,n,k)){
            result=mid;
            right=mid-1;
        }
        else{
            left=mid+1;
        }
    }

    cout<<result<<endl;
    return 0;
}
