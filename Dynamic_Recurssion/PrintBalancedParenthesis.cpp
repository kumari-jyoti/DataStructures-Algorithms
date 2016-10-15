#include<iostream>
using namespace std;

//printing balanced parenthesis
void print(string str,int len, int open, int close){
	//base condition
	if(close==len){//if number of remaining close braces has reached maximum exit
		cout<<str<<endl;
		return;
	}
	else
	{
		//2 choice- open again, close previous open
		if(open<len)//if open is less than len then can open agiain
			print(str+"(",len,open+1,close);	
		if(open>close)//if number of open braces are more than closed ones, can close the previous one
			print(str+")",len,open,close+1);
	}
}

//main function
int main(){
	int N;//number of open or close braces
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
