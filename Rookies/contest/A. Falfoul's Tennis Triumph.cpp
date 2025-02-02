#include <bits/stdc++.h>
using namespace std;

int main()
{
int N,total=0,consecutiveWins=0;
cin>>N;
for(int i=0;i<N;i++){
    int x;
    cin>>x;
    if(x==1){
        total+=1;
        consecutiveWins+=1;
        if(consecutiveWins>=3){
            total+=1;
        }
    }
    else{
        total=total-1;
        consecutiveWins=0;
    }

}
cout<<total<<endl;



    return 0;
}
