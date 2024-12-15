#include <iostream>
#include <climits>
using namespace std;

const int MAXSTALL=100;
const int MAXCOWS=20;
const int MAXACS=10;

struct Cow{
    int start, end, cooling;
};

struct AC {
    int start, end, power, cost;
};

int N,M;
Cow cows[MAXCOWS];
AC conditioners[MAXACS];
int cooling[MAXSTALL + 1];
int minCost = INT_MAX;
bool check() {
    for(int i=0;i<N;i++){
        for(int j=cows[i].start;j<=cows[i].end;j++){
            if (cooling[j]<cows[i].cooling) {
                return false;
            }
        }
    }
    return true;
}
void solve(int idx, int cost) {
    if (idx==M) {
        if(check()){
            minCost=min(minCost,cost);
        }
        return;
    }
    solve(idx + 1, cost);
    for (int i = conditioners[idx].start; i <= conditioners[idx].end; i++) {
        cooling[i] += conditioners[idx].power;
    }

    solve(idx + 1, cost + conditioners[idx].cost);
    for (int i = conditioners[idx].start; i <= conditioners[idx].end; i++) {
        cooling[i] -= conditioners[idx].power;
    }
}
int main() {
    cin>>N>>M;
    for(int i=0;i<N;i++){
        cin>>cows[i].start>>cows[i].end>>cows[i].cooling;
    }
    for(int i=0;i<M;i++){
        cin>>conditioners[i].start>>conditioners[i].end>>conditioners[i].power>>conditioners[i].cost;
    }
    for(int i=0;i<=MAXSTALL;i++){
        cooling[i]=0;
    }
    solve(0, 0);

    cout<<minCost<<endl;

    return 0;
}
