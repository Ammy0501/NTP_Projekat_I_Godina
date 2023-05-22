#include<iostream>
#include<ctime>
#include<sstream>
#include<stdlib.h>
using namespace std;

struct namirnica{
	string ime_Namirnice;
	string kolicina_Namirnice;
	string cijena_Namirnice;
	string bar_Kod_Namirnice;
	char charset[30];
};


string Give_Bar_Code()
{
	int j;
    string bar;

    for(int i = 1; i <= 10; i++)
    {
        j = rand()%9 + 1;
        
        switch(j)
        {
        case 1:
            bar += "x";
            break;
        case 2:
            bar += "j";
            break;
        case 3:
            bar += "y";
            break;
        case 4:
            bar += "q";
            break;
        case 5:
            bar += "i";
            break;
        case 6:
            bar += "w";
            break;
        case 7:
            bar += "1";
            break;
        case 8:
            bar += "0";
            break;
        case 9:
        	bar += "e";
        	break;
        }
    }
    return bar;
}



