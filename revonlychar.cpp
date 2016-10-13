#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;

bool isnotchar(char a){
	int diff=tolower(a)-'a';
	if(diff<0 || diff>26) return true;
	return false;
}
void rev_onlychar(string* p){
	string s=*p;
	int i=0, n=s.length();
	int j=n-1;
	while(1){
		while(i<j && isnotchar(s[i]))
			i++;
		while(j>i && isnotchar(s[j]))
			j--;
		if(i>=j) break;
		char temp=s[i];
		s[i]=s[j];
		s[j]=temp;
		i++;
		j--;
	}
	*p=s;
}
int main(){
	string s="a#$bc*d!!Ef___g";
	cout<<s<<endl;
	rev_onlychar(&s);
	cout<<s;
}
