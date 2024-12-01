#include <iostream>

using namespace std;

int main()
{
  int n,polices=0,countt=0;
  cin>>n;

  while(n--){
    int x;
    cin>>x;
    if(x>0){
        polices+=x;
    }
    else if(x==-1){
        if(polices>0){
                polices--;
        }
        else{
            countt++;
        }
    }
  }
  cout<<countt<<endl;

    return 0;
}
