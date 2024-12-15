#include <iostream>
using namespace std;
void Rescursion(long long n) {
    cout<<n<<" ";
    if(n==1){
        return;
    }
    if(n%2==0){
        Rescursion(n/2);
    }else{
        Rescursion(3*n+1);
    }
}
int main() {
    long long n;
    cin>>n;

    Rescursion(n);

    return 0;
}


