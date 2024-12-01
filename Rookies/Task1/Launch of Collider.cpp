#include <iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    string s;
    cin>>s;
    int arr[n];
    for (int i=0;i<n;i++){
        cin>>arr[i];
    }
    int mintime = -1;
    for(int i=0;i<n-1;i++){
        if (s[i]=='R' && s[i+1]=='L'){
            int t=(arr[i+1]-arr[i])/2;
            if (mintime==-1 || t<mintime){
                mintime=t;
            }
        }
    }
    cout<<mintime<<endl;


    return 0;
}
