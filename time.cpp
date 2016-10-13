#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

void military(string t){
    int am=(t[9]-'A'==0)?1:0;
    //trim am pm
    t=t.substr(0,8);
    //if am retain same except for 12:00:00AM
    if(am){
        if(t=="12:00:00")//subtract 12:00:00
            t.replace(0,2,"00");
        //else retain same
    } 
        
    else{//add 12:00:00;
        string M=t.substr(0,2);
        M[0]=M[0]+'12';
        cout<<M;
    }
        
}
int main(){
    string time;
    cin >> time;
    military(time);
    return 0;
}

