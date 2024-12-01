#include <iostream>

using namespace std;

int main()
{
   int n,a=0,b=0;;
   cin>>n;
   int arr[n];
   for (int i=0;i<n;i++){
        cin >> arr[i];
        if(arr[i]>arr[a]) {
            a=i;    // max
        }
        if(arr[i]<=arr[b]) {
            b=i;    // min
        }
    }
   int countt=a;
   if (b>a) {
        countt =countt+(n-1-b);
    }
    else{
        countt+= (n-1-b-1);
    }
    cout<<countt<<endl;


    return 0;
}
