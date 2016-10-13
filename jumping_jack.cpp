#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int jacksteps(int N, int K){
    int prev=0;
    int cur;
    for(int i=1;i<=N;i++){
        if((prev+i)==K)
            continue;
        else
            prev+=i;
    }
    return prev;
}
int main() {
    int N,K;
    cin>>N;
    cin>>K;
    cout<<jacksteps(N,K);
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}

