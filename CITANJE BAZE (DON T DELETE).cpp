#include <iostream>
#include <fstream>
#include<string.h>
using namespace std;

struct namirnica {
	char charset[30];
};

main()
{	
	ifstream fileIn;
	string fileTxt;
	// velicina fajla 
	int k;
	char dataOut[1000];
	//open a read file;
	fileIn.open("Prodavnica_Inventar.txt");
	cout<<"File opened."<<endl<<endl; 	
	//reads file data to string size 
	cout<<"Loading file ... "<<endl<<endl;
	fileIn>>fileTxt;
	k = fileTxt.length();
	cout<<"String size in file : "<<k<<endl<<endl;
	fileIn.close();
	fileIn.open("Prodavnica_Inventar.txt");
	fileIn>>dataOut;
	cout<<"File closed."<<endl<<endl;
	//closes file
	fileIn.close();
	
	// OVO GORE SVE SAMO PRAVI CHARSET DATA OUT I PRAVI TI K (kao velicinu baze u charovima)
	
	// ASCII from 97 to 122; //Imas k kao velicinu baze i imas dataOut kao charset
	namirnica n_array[1000];
	
	//59 = ;
	//42 = *
	
	int i = 0;
	int n = 0;
	int j = 0;
	
	//salta kroz cijelu bazu
	while(i <= k)
	{
		//provjerava da li je slucajno trenutni karakter ; i ako jeste prelazi na sljedecu namirnicu;
		if(dataOut[i] != 59)
		{
			n_array[n].charset[j] = dataOut[i];
			j++;
		}
		else if(dataOut[i] == 59)
		{
			j = 0;
			n++;
		}
		
		i++;
	}
	
	//OVO ISPISUJE SVE NAMIRNICE;
	
	cout<<endl<<" Sve namirnice su : "<<endl<<endl<<"\tIME :\t\tCIJENA :\tKOLICINA :\tBAR KOD : "<<endl<<endl;
	
	for(int i = 0; i < 20; i++)
	{
		cout<<"\t";
		for(int j = 0; j < 30; j++)
		{
			if(n_array[i].charset[j] != 42)
			{
				cout<<n_array[i].charset[j];		
			}
			else
			{
				cout<<"\t\t";
			}
		}
		
		cout<<endl<<endl;
	}

	
	//JEDNA NAMIRNICA JE SKUP OD 30 KARAKTERA !!!

	return 0;	
}
