#include<iostream>
using namespace std;

bool ifpower2(int x){
	int y=x&-x;
	if(x==y) return true;
	return false;
}

int main(){
	int x=256;
	cout<<ifpower2(x);
	return 0;
}
