#include<iostream>
#include"inventar_Prodavnice.cpp"
#include<ctime>
#include<stdlib.h>
#include<fstream>
#include<cstring>
#include<sstream>
#include"File_System_Usage.cpp"
using namespace std;

int main()
{	
	//Initialization of System -------------------------------------------------
	srand(time(NULL));
	
	string string_FromFile;
	int user_Choice;
	string user_Choice_YN;
	char ime_Namirnice_Za_Citati[10];
	int k;
	char dataOut[1000];
	// namrnica init
	namirnica namirnica;
	//namirnica niz_Namirnica[200];
	
	// ------------------------------------------------------- CLI UI / UX ---------------------------------------------------- //
	
	cout<<"Dobro dosli u Vasu prodavnicu. Izaberite opciju koju zelite : \n \t";
	
	do{
		cout<<"Opcija 1 : Unesi Namirnicu; \n \tOpcija 2 : Procitaj Namirnicu; \n \tOpcija 3 : Procitaj sve namirnice; \n \tOpcija 4 : Obrisi bazu;";
		cout<<endl<<endl<<"Vas unos : \t";
		cin>>user_Choice;
		system("cls");
		switch(user_Choice)
		{
			case 1:		
			{
				cout<<"Unesi namirnicu : "<<endl;
				cout<<"\t - Unesi ime namirnice : ";
				cin>>namirnica.ime_Namirnice;
				cout<<endl<<"\t - Unesi cijenu namirnice : ";
				cin>>namirnica.cijena_Namirnice;
				cout<<endl<<"\t - Unesi kolicinu namirnice : ";
				cin>>namirnica.kolicina_Namirnice;
				namirnica.bar_Kod_Namirnice = Give_Bar_Code();
				//file Input System ------------------------ 
				Namirnica_ToFile(namirnica);
				break;
			}
			case 2:
			{
				cout<<"Molimo unesite naziv namirnice koju zelite citati : "<<endl;
				cin>>ime_Namirnice_Za_Citati;
				Printaj_Namirnicu(ime_Namirnice_Za_Citati);
				break;
			}
			case 3:
			{
				//ovo ce ti biti load funckija;
				Procitaj_Bazu();
				break;
			}
			case 4:
			{
				cout<<"WARNING! \n \t Da li ste sigurni da zelite ponistiti kompletnu bazu : Y / N (Y = Da, N = Ne) "<<endl<<endl;
				cin>>user_Choice_YN;
				if(user_Choice_YN == "n" || user_Choice_YN == "N")
				{
					break;
				}
				else if(user_Choice_YN == "y" || user_Choice_YN == "Y")
				{
					cout<<"Baza Obrisana uspjesno.";
					
					DropDataBase();
					break;
				}
			}
			default:
			{
				cout<<"Error//MissInput//UserSide//ThrowException : 205 : Molimo unesite broj opcije koju zelite kao jednoznacan broj i pritisnite tipku ENTER."<<endl;
				break;		
			}
		}
		cout<<endl<<endl;
		cout<<"Unesite novu komandu : "<<endl<<endl;
	}while(1);
	
	// ---------------------------------------------------------------------------------------------------------- //

	// End of System --------------------------------------------------------
	return 0;
}
