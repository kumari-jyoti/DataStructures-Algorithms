#include<iostream>
#include<string.h>
#include<algorithm>
#include<unordered_map>
using namespace std;

//number of unique subsets
int cnt=1;

//printing each subset
void print(char result[],int upto){
	cout<<cnt<<". ";
	for(int i=0;i<upto;i++){
		cout<<result[i];
	}	cnt++;
	cout<<endl;
}

//finding all unique subsets
void USubSet(char input[],int count[], char result[],int pos, int len){
	print(result,len);
		for(int i=pos;i<strlen(input);i++){//start from pos as all subsets having previous elements has been found
			if(count[i]==0)
				continue;
			result[len]=input[i];//gives subset of length len
			/*char* t=new char[level+1];
			strncpy(t,result,level+1);
			cout<<t<<endl;*/
			count[i]--;	
			USubSet(input,count,result,i,len+1);//retain at same pos if freq>0 else in above loop pos will get incremented
			count[i]++;	//backtrack
		}				
}

//finding unique characters in the string and their frequencies
void SubSets(char a[],int len){
	unordered_map<char, int> count_map;
	for(int i=0;i<len;i++)
		if(count_map.find(a[i])!=count_map.end())//if char there in map, increment its count
			count_map[a[i]]++;
		else//insert the char and its count as 0
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
	
	char result[len];//for storing the subsets, max length will be len
	USubSet(input,freq,result,0, 0);
}

//main function
int main(){
	//input string
	char a[]="AABC";
	//length of string
	int n=strlen(a);
	SubSets(a,n);
}
