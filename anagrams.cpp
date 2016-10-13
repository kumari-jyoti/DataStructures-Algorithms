#include<iostream>
using namespace std;
#include<vector>
#include<unordered_map>
#include<algorithm>

int anagrams(vector<string> dict)
{
	unordered_map<string,string> A;
	int n=dict.size();
	int anacount=0;
	for(int i=0;i<n;i++)
	{
		string key=dict[i];
		sort(key.begin(),key.end());
		
		std::pair<std::string,string> mypair (key,dict[i]);
		if(A.find(key)!=A.end())
			A[key]=A[key]+dict[i];
		else
		A.insert(mypair);	
	}
	for(auto it=A.begin();it!=A.end();++it)
	{
		int keylen=it->first.size();
		int vallen=it->second.size();
		cout<<it->first<<" "<<it->second<<'\n';
		if(keylen!=vallen)
			{
				
				anacount+=vallen/keylen;
			}
	}

return anacount;
}

int main()
{	
	vector<string> dict;
	dict.push_back("act");
	dict.push_back("cat");
	dict.push_back("hello");
	dict.push_back("lloeh");
	dict.push_back("owllye");
	dict.push_back("taco");
	dict.push_back("yellow");
	return anagrams(dict);
}
