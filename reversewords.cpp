#include <iostream>
#include <string>
#include <regex>
using namespace std;

std::string & ltrim(std::string & str)
{
  auto it2 =  std::find_if( str.begin() , str.end() , [](char ch){ return !std::isspace<char>(ch , std::locale::classic() ) ; } );
  str.erase( str.begin() , it2);
  return str;   
}

std::string & rtrim(std::string & str)
{
  auto it1 =  std::find_if( str.rbegin() , str.rend() , [](char ch){ return !std::isspace<char>(ch , std::locale::classic() ) ; } );
  str.erase( it1.base() , str.end() );
  return str;   
}
std::string & trim(std::string & str)
{
   return ltrim(rtrim(str));
}

void reverse(char *begin, char *end)
{
  char temp;
  while (begin < end)
  {
    temp = *begin;
    *begin++ = *end;
    *end-- = temp;
  }
}

int main() {
	string A="fddu xq l vy azs";
    int n=A.length();
    char s[n];
    int j=0;
    int i=0;
   	trim(A);
   	for(;i<n;i++)
   		s[i]=A[i];
   		
   	s[i]='\0';
    char *word_begin = NULL;
    char *temp = s; /* temp is for word boundry */
    
 
    /*STEP 1 of the above algorithm */
    /*while( *temp )
    {
        if (( word_begin == NULL ) && (*temp != ' ') )
        {
            word_begin=temp;
        }

        if(word_begin && ((*(temp+1) == ' ') || (*(temp+1) == '\0')))
        {
            reverse(word_begin, temp);//reversing each word
            word_begin = NULL;
        }
        temp++;
    } */
    n=strlen(s);
    reverse(s, temp-1);
    cout<<s<<endl;
  	A=s;
  	cout<<A;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}

