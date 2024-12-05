#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
 int n;
 cin>>n;
 int arr[n];
 for(int i=0;i<n;i++){
    cin>>arr[i];
 }
 sort(arr,arr+n);
 int days;
 cin>>days;
 for(int i=0;i<days;i++){
    int x,countt=0;
    cin>>x;
    countt=upper_bound(arr,arr+n,x)-arr;
    cout<<countt<<endl;

 }


 return 0;
}
