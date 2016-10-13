#include<iostream>
#include<vector>
using namespace std;

computeLPSArray(string str,int n,int lps[])
{
	int len=0;
	lps[0]=0;
	int i=1;
	
	for(i;i<n;i++)
	{
		if(str[i]==str[len])
		{
			len++;
			lps[i]=len;
		}
		else
		{
			if(len!=0)
			{
				len = lps[len-1];
				i--;
			}
			else
				lps[i]=0;
		}
	}
	
}

bool isrepsub(string str)
{
    int n = str.size();
    int lps[n];
 
    computeLPSArray(str, n, lps);

    int len = lps[n-1];

    return (len > 0 && n%(n-len) == 0)? true: false;
}
int main()
{
	vector<string> A;
	A.push_back("abaaba");
	A.push_back("ABABAB");
	A.push_back("ABCDABCD");
	A.push_back("GEEKSFORGEEKS");
	A.push_back("GEEKGEEK");
	A.push_back("AAAACAAAAC");
	A.push_back("ABCDABC");
	
	for(int i=0;i<A.size();i++)
	{
		cout<<isrepsub(A[i])<<endl;
	}
	return 0;
}
