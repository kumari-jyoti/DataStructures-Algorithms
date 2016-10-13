#include<iostream>
#include<string.h>
#include<algorithm>
#include<unordered_map>
using namespace std;

void permuteutil(char input[],int count[], char result[],int level, int len){
	if(level==len){
		cout<<result<<endl;
		return;
	}
	else{
		for(int i=0;i<strlen(input);i++){
			if(count[i]==0)
				continue;
			result[level]=input[i];
			count[i]--;
			permuteutil(input,count,result,level+1,len);
			count[i]++;	
		}				
	}
}

void permute(char a[],int len){
	unordered_map<char, int> count_map;
	for(int i=0;i<len;i++)
		if(count_map.find(a[i])!=count_map.end())
			count_map[a[i]]++;
		else
		{
			pair<char,int> mypair(a[i],1);
			count_map.insert(mypair);
		}
						
	int n=count_map.size();	//cout<<n<<endl;	
	char input[n];//storing diff chars
	int freq[n];//storing their frequencies
	int j=0;
	for(auto it=count_map.begin();it!=count_map.end();it++){
		input[j]=it->first;
		freq[j]=it->second;
		//cout<<input[j]<<" "<<freq[j]<<endl;
		j++;	
	}
	
	char result[len];
	permuteutil(input,freq,result,0, len);
}

int main(){
	char a[]="ABC";
	int n=strlen(a);
	permute(a,n);
}
