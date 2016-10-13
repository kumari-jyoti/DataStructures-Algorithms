#include<iostream>
using namespace std;

int rowwithmax1(bool mat[R][C]){
	int maxrow=0;
	for(int j=0;j<C;j++)
		if(mat[0][j]) break;
	if(j==c)//no 1
		j=c-1;
	for(int i=1;i<R;i++){
		while(j>=0 && mat[i][j]){
			j=j-1;
			maxrow=i;
		}
	}
	
	return maxrow;
	
}
