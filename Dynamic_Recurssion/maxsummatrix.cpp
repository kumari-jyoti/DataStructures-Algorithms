#include<iostream>
using namespace std;

int main(){
	int a[4][5] = {{1, 2, -1, -4, -20},
                       {-8, -3, 4, 2, 1},
                       {3, 8, 10, 1, 3},
                       {-4, -1, 1, 7, -6}
                      };

	int sum[4][5];
	sum[0][0] = a[0][0]; 
	for(int i=1;i<4;i++){
		sum[i][0] = sum[i-1][0] + a[i][0];
	}
	
	for(int j=1;j<5;j++){
		sum[0][j] = sum[0][j-1] + a[0][j];
	}
	
	for(int i=1; i<4;i++) {
		for(int j=1; j<5;j++) {
			sum[i][j] = a[i][j] +sum[i][j-1] +sum[i-1][j]-sum[i-1][j-1];
		}
	}

	int maxsum=sum[0][0];
	int r=0; int c=0;
	for(int i=0;i<4;i++)
		for(int j=0;j<5;j++){
			if(sum[i][j]>maxsum){
				 maxsum=sum[i][j];
				 r=i;
				 c=j;
			}
		}
			
	cout<<maxsum<<" "<<r<<" "<<c;
	return 0;
			
}
