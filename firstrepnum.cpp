#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;

void printfirstrepnum(vector<int> A)
{
	unordered_set<int> s;
	int min=-1;
	int n=A.size();
	for(int i=n-1;i>=0;i--){
		unordered_set<int>::const_iterator got=s.find(A[i]);
		if(got!=s.end()) min=i;
		else
		s.insert(A[i]);		
	}
	cout<<A[min]<<endl;
}

int main(){
	vector<int> A={10, 5, 3, 4, 3, 5, 6};
	printfirstrepnum(A);
}
