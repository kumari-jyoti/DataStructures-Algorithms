#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int n,b;
	cin>>n>>b;
	
	int i,j,k,l,ans=0, temp=0;
	
	vector<vector<int> > dp(n+1, vector<int> (b+1,0));
	
	dp[0][0]=1;
	
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=b;j++)
		{
			if(i==j && i==1)
				dp[i][j]=1;
			else if(i<j)
				dp[i][j]=0;
			else
			{
				ans=0;
				for(k=0;k<i;k++)
				{
					temp=dp[k][j-1];
					if(temp>0)
					{
						for(l=0;l<j-1;l++)
						{
							ans+=temp*dp[i-k-1][l];
						}
					}
				}
				ans*=2;
				
				for(k=0;k<i;k++)
				{
					ans+=dp[k][j-1]*dp[i-k-1][j-1];
				}
				dp[i][j]=ans;
			}
		}
		
	}
	
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=b;j++)
		{
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
}
