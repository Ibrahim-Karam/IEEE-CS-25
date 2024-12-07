#include <iostream>
using namespace std;

int main() {
    int n;
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int time_a=0,time_b=0,index_a = 0,index_b=n-1;

    while(index_a<=index_b){
        if(time_a<=time_b){
            time_a+=arr[index_a];
            index_a++;
        }
        else{
            time_b+=arr[index_b];
            index_b--;
        }
    }
    int bob=n-index_b-1;
    cout<<index_a<<" "<<bob<<endl;

    return 0;
}
