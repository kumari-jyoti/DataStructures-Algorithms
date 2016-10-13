#include<stdio.h> 
#include<stdarg.h> 
#include<iostream>
using namespace std;

char* convert(unsigned int num, int base){
	static char rep[]="0123456789ABCDEF";
	static char buf[50];
	char* ptr;
	ptr=&buf[49];
	*ptr='\0';
	
	do{
		*--ptr=rep[num%base];
		num/=base;
	}while(num!=0);
	return ptr;
}

void myscanf(char* format,...){
	char* traverse;
	int i;
	char* st;
	va_list arg;
	va_start(arg,format);
	for(traverse=format;*traverse!='\0';traverse++){
		if(*traverse!='%')
		switch(*traverse){
			case 'c': {
			char c=getchar();
						
				break;
			}
		    case 'd': {i=va_arg(arg,int);
		    
			i=getchar();
			cout<<i;
				break;
			}
			case 's':{gets(st);
				break;
			} 
			case 'o':{unsigned int a=getchar();
					convert(a,8);
				break;
			} 
			case 'x':{unsigned int a=getchar();
					convert(a,16);
				break;
			}
		}
	}
}

void myprintf(char* format,...){
	char* traverse;
	int i;
	char* s;
	va_list arg;
	va_start(arg,format);
	for(traverse=format;*traverse!='\0';traverse++){
		while(*traverse!='%'){
			putchar(*traverse);
			traverse++;
		}
		traverse++;
		switch(*traverse){
			case 'c': i=va_arg(arg,int);
						putchar(i);
						break;
		  case 'd' : i = va_arg(arg,int);         //Fetch Decimal/Integer argument
                        if(i<0) 
                        { 
                            i = -i;
                            putchar('-'); 
                        } 
                        puts(convert(i,10));
                        break;
			case 's': s=va_arg(arg,char*);
						puts(s);
						break;
			case 'o': i=va_arg(arg,unsigned int);
						puts(convert(i,8));
						break;
			case 'x':i=va_arg(arg,unsigned int);
						puts(convert(i,16));
						break;
		}
	}
	va_end(arg);
}

int main(){
	int a;
	myscanf("%d",a);
	cout<<a<<endl;
	myprintf(" WWW.FIRMCODES.COM \n %d", a);
	return 0;
}
