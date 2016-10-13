#include<iostream>
using namespace std;

# define MAX_SIZE 100

void print(string str,int len, int open, int close){
	//base condition
	if(close==len){
		cout<<str<<endl;
		return;
	}
	else
	{
		//2 choice open again, close previous open
		if(open<len)
			print(str+"(",len,open+1,close);	
		if(open>close)
			print(str+")",len,open,close+1);
	}
}

int main(){
	int N;
	cin>>N;
	print("",N, 0,0);
}

/* OR
#include<iostream>
using namespace std;

# define MAX_SIZE 100

char str[MAX_SIZE];
void print(int len, int open, int close, int pos){
	//base condition
	if(close==len){
		cout<<str<<endl;
		return;
	}
	else
	{
		//2 choice open again, close previous open
		if(open<len){
			str[pos]='(';
			print(len,open+1,close,pos+1);	
		}
		if(open>close){
			str[pos]=')';
			print(len,open,close+1,pos+1);
		}
	}
}

int main(){
	int N;
	cin>>N;
	print(N, 0,0,0);
}
*/
