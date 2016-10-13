#include <iostream>
using namespace std;

void TOI(int n,char from, char to, char aux)
{
	if(n==1)
		{
			cout<<"move 1 from "<<from<<" to "<<to<<"\n";
			return;
		}
	TOI(n-1,from,aux,to);
	cout<<"move "<<n<<" from "<<from<<" to "<<to<<"\n";
	TOI(n-1,aux,to,from);
}
int main()
{
	cout<<"enter number of discs";
	int n;
	cin>>n;
	TOI(n,'A','C','B');//from rod, to rod, aux rod
	return 0;
}
