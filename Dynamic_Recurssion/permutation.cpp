#include<iostream>
#include<string.h>
#include<algorithm>
#include<unordered_map>
using namespace std;

void swap(char *c1, char *c2){
	char temp=*c1;
	*c1=*c2;
	*c2=temp;
}

void print_per(char* a, int l, int r){
	if(l==r)
		cout<<a<<endl;
	else{
		for(int i=l;i<=r;i++){
			swap(a+l,a+i);
			print_per(a,l+1,r);
			swap(a+l,a+i);	
		}
		
	}
}

int main(){
	char a[]="ABC";
	int n=strlen(a);
	print_per(a,0,n-1);
}
