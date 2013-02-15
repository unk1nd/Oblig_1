#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
#include <cmath>
#include "windows.h"

/*
	Obligatorisk innlevering 1 i C++
	av Mikael Bendiksen og Lisa Marie Sørensen
	15.02.2012
	Høgskolen i Narvik
*/


using namespace std;

bool meny()
	{
		cout << "\n------------------------------------" << endl;
		cout << "		Hovedmeny" << endl;
		cout << "------------------------------------" << endl;
		cout << "Velg en oppgave:\n" << endl;
		cout << "1. Kulevolum" << endl;
		cout << "2. Annengradslikning" << endl;
		cout << "3. Avstand mellom geografiske punkter" << endl;
		cout << "4. Annuitetsl" << (char)134 << "n" << endl;
		cout << "5. Tall som tekst" << endl;
		cout << "------------------------------------" << endl;
		cout << "9. Om programmet" << endl;
		cout << "0. Avslutt\n" << endl;
		cout << "------------------------------------" << endl;

		char valg;
		cin >> valg;

		// OPPGAVE_1: Kulevolum
		if (valg == '1') 
		{
			cout << "\nDu har valgt oppgave 1: Kulevolum" << endl;
			cout << "(4/3) * PI * radius^3\n" << endl;
			cout << "Skriv inn radius for å beregne kulevolum:" << endl;
			float radius;
		
			cin >> radius;
			cout << "\nVolumet til kulen blir: " << (1.333) * M_PI * pow(radius,3) << endl; 		
		}

		// OPPGAVE_2: Annengradslikning
		else if (valg == '2')
		{
			cout << "\nDu valgte oppgave 2: Annengradslikning" << endl;
			cout << "aX^2 + bX + c\n" << endl;

			float a, b, c;
			float z;

			cout << "Skriv inn verdier for a, b og c:" << endl;
			cin >> a >> b >> c;

			z = pow(b,2)-(4*a*c);

			if (a==0)
			{
				cout << "\nLikningen er ikke annengrads, l" << (char)155 << "sningen er: " << -c/b << endl; 
			}
			else
			{
				if (z < 0)
				{
					cout << "\nR" << (char)155 << "ttene er imagin" << (char)145 << "re." << endl;
				}
				else
				{
					cout << "x1 = " << (-b + sqrt(z))/(2*a) << endl;
					cout << "x2 = " << (-b - sqrt(z))/(2*a) << endl;
				}
			}

			// gå tilbake til meny
			meny();
		}

		// OPPGAVE_3: Avstand mellom geografiske punkter (Haversine Formula)
		else if (valg == '3')
		{
			cout << "\nDu valgte oppgave 3: Avstand mellom geografiske punkter" << endl;
			double lat1,lat2,long2,long1;
		
			cout << "\nSkriv inn latitude p" << (char)134 << " punkt1" << endl;
			cin >> lat1;

			cout << "\nSkriv inn longitude p" << (char)134 << " punkt1" << endl;
			cin >> long1;

			cout << "\nSkriv inn latitude p" << (char)134 << " punkt2" << endl;
			cin >> lat2;

			cout << "\nSkriv inn longitude p" << (char)134 << " punkt2" << endl;
			cin >> long2;

			double PI = 4.0*atan(1.0);
        
			double dlat1=lat1*(PI/180);

			double dlong1=long1*(PI/180);
			double dlat2=lat2*(PI/180);
			double dlong2=long2*(PI/180);

			double dLong=dlong2-dlong1;
			double dLat=dlat2-dlat1;

			double aHarv= pow(sin(dLat/2.0),2.0)+cos(dlat1)*cos(dlat2)*pow(sin(dLong/2),2);
			double cHarv=2*atan2(sqrt(aHarv),sqrt(1.0-aHarv));
        
			const double earth=6378.137;
			double distance=earth*cHarv;
		
			cout << "\nAvstanden er p" << (char)134 << ": " << distance << " km." << endl;

			// gå tilbake til meny
			meny();
		}

		// OPPGAVE_4: Annuitetslån
		else if (valg == '4')
		{
			cout << "\nDu valgte oppgave 4: Annuitetsl" << (char)134 << "n" << endl;
			cout << "Oppgi startl" << (char)134 << "n, rente(i %) og antall " << (char)134 << "r: " << endl;

			double startlån, rente, renteprosent, terminbelop, rentesum, avdrag;
			int år;

			cout << "\nSkriv inn L" << (char)134 << "nebel" << (char)155 << "p" << endl;
			cin >> startlån;

			cout << "\nSkriv inn rentesats i prosent" << endl;
			cin >> renteprosent;
		
			cout << "\nSkriv inn antall " << (char)134 << "r" << endl;
			cin >> år;
  
			rente = renteprosent/100;
			terminbelop = startlån * rente * ((pow(1+rente,år)) / (pow(1+rente,år)-1));
			double resterlån = startlån;
	
			cout << "------------------------------------------------------------------" << endl;
			cout << "Terminbel" << (char)155 << "p: " << terminbelop << endl;
			cout << (char)134 << "r	Terminbel" << (char)143 << "p	Renter	Avdrag	Restgjeld" << endl;
			cout << "------------------------------------------------------------------" << endl;
		
			for (int i = 1; i <= år; i++)
			{
			
				rentesum = resterlån * renteprosent / 100;
				avdrag = terminbelop - rentesum;
				resterlån = resterlån - avdrag;
				
				if (i == år)
				{
					resterlån = 0.00;
				}

				cout.precision(0);
				cout << i << "	" << fixed << terminbelop << "		" << fixed << rentesum << "	"<< fixed << avdrag << "	"<< fixed << resterlån << endl;
			
			}
			cout << "------------------------------------------------------------------" << endl;
			cout << "" << endl;
			Sleep(5000);

		
			// gå tilbake til meny
			meny();
		}

		// OPPGAVE_5: Tall som tekst
		else if (valg == '5')
		{
			cout << "Du valgte oppgave 5: Tall som tekst" << endl;
			cout << "Skriv inn et tall f.o.m. 0 t.o.m. 1000" << endl;
			int tall;
			cin >> tall;

			// gå tilbake til meny
			meny();
		}

		// OPPGAVE_0: Avslutt program
		else if (valg == '0')
		{
			cout << "\nDu valgte oppgave 0: Avslutt" << endl;
			cout << "\nProgrammet avslutter...\n\n" << endl;
			exit(0);
		}

		// Om programmet
		else if (valg == '9') 
		{
			cout << "Du valgte: Om programmet" << endl;
			cout << "-----------------------------" << endl;
			cout << "Programmet er skrevet av" << endl;
			cout << "Mikael Bendiksen" << endl;
			cout << "og" << endl;
			cout << "Lisa Marie S" << (char)155 << "rensen" << endl;
			cout << "som en obligatorisk innlevering i c++ faget" << endl;
			cout << "ved H" << (char)155 << "gskolen i Narvik" << endl;
			cout << "15.02.2013" << endl;
			cout << "-----------------------------" << endl;

			meny();
		}
}


int main()
	{
		while (!meny())
		{
			cout << "-------------" << endl;
			cout << "----ERROR----" << endl;
			cout << "-------------" << endl;
		}
	}
