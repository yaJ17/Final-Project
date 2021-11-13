#include<iostream>
using namespace std;
int main()
{
	int character=0;
    char ch='A';
    
	for ( character=0;ch < 'Z';character++){
		character=int(ch); 
    		character++;  
		ch=char(character);
		if(ch!='A'&&ch!='E'&&ch!='I'&&ch!='O'&&ch!='U'){
			cout<< ch << " ";
		}
	}

	}

