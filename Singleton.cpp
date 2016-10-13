#include<iostream>
using namespace std;

class Singleton{
	private:
    static bool flaginstance;
    static Singleton *single;
    Singleton()
    {
        //private constructor
    }
	public:
		 static Singleton* getInstance();
    void method();
    ~Singleton()
    {
        flaginstance = false;
    }
		
};
bool Singleton::flaginstance = false;
Singleton* Singleton::single = NULL;
Singleton* Singleton::getInstance()
{
    if(! flaginstance)
    {
        single = new Singleton();
        flaginstance = true;
        return single;
    }
    else
    {
        return single;
    }
}
void Singleton:: method(){
		cout << "Method of the singleton class" << endl;
		}
int main(){

    Singleton *sc1,*sc2;//note pointers not object
    sc1 = Singleton::getInstance();//note: not sc1.getInstance(); rather function returns a pointer to the class
    sc1->method();
    sc2 = Singleton::getInstance();
    sc2->method();

    return 0;
	
}
