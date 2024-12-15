#include <iostream>
#include <set>
#include <string>
using namespace std;
set<string> p;
void Rescursion(string &s, int index) {
    if (index==s.size()){
        p.insert(s);
        return;
    }

    for(int i=index;i<s.size();i++){
        swap(s[index],s[i]);
        Rescursion(s,index+1);
        swap(s[index],s[i]);
    }
}

int main() {
    string s;
    cin >> s;
    Rescursion(s, 0);
    cout<<p.size()<<endl;
    for(const auto &str :p) {
        cout<<str<<endl;
    }
    return 0;
}

