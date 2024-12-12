#include <iostream>
using namespace std;

const int maxx=1000;
char c[maxx][maxx];
int n,m;
void check(int a,int b) {
    if (a<0 || a>=n || b<0 || b>=m || c[a][b]!='.'){
        return;
        }
    c[a][b]='#';
    check(a-1,b);
    check(a+1,b);
    check(a,b-1);
    check(a,b+1);
}
int main() {
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>c[i][j];
        }
    }
    int countt=0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (c[i][j] == '.') {
                countt++;
                check(i,j);
            }
        }
    }

    cout<<countt<<endl;
    return 0;
}
