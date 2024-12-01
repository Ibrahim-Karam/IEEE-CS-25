#include <iostream>
using namespace std;

int main() {
   string a="qwertyuiop";
   string b="asdfghjkl;";
   string c="zxcvbnm,./";             // R                                           //allyouneedislove
   char ch;                           // s;;upimrrfod;pbr
   cin>>ch;
   string s;
   cin>>s;

   if(ch=='R'){
    for(int i=0;i<s.size();i++){

       for(int j=0;j<31;j++){
        if(s[i]==a[j]){
            cout<<a[j-1];
            break;
        }
        else if(s[i]==b[j]){
             cout<<b[j-1];
             break;
        }
        else if(s[i]==c[j]){
             cout<<c[j-1];
             break;
        }

    }

   }

   }
   else{
    for(int i=0;i<s.size();i++){

       for(int j=0;j<31;j++){                                    // L
        if(s[i]==a[j]){                                         // sif                               //dog
            cout<<a[j+1];
            break;
        }
        else if(s[i]==b[j]){
             cout<<b[j+1];
             break;
        }
        else if(s[i]==c[j]){
             cout<<c[j+1];
             break;
        }

    }

   }
   }
    return 0;
}
