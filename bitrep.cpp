#include<iostream>
#include <bitset>
using namespace std;

void printbin(int n){
	for(int i=1;i<=n;i++){
		bitset<8> x(i);
		cout<<x;
		cout<<endl;
	}
}

int main(){
	int n;
	cin>>n;
	printbin(n);
}
