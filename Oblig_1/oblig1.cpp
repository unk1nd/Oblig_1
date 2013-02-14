#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
#include <cmath>

using namespace std;

bool meny()
{
	cout << "Hovedmeny" << endl;
	cout << "Velg en oppgave:\n" << endl;
	cout << "1. Kulevolum" << endl;
	cout << "2. Annengradslikning" << endl;
	cout << "3. Avstand mellom geografiske punkter" << endl;
	cout << "4. Annuitetsl" << (char)134 << "n" << endl;
	cout << "5. Tall som tekst" << endl;
	cout << "0. Avslutt\n" << endl;

	char valg;
	cin >> valg;

	// OPPGAVE_1: Kulevolum
	if (valg == '1') 
	{
		// V= 4/3*PI*R^3
		cout << "Du har valgt oppgave 1: Kulevolum" << endl;
		cout << "(4/3) * PI * radius^3\n" << endl;
		cout << "Skriv inn radius for å beregne kulevolum:" << endl;
		float radius;
		
		cin >> radius;
		
		//NB UTREGNING BLIR FEIL, FINN UT HVORFOR!!!!!!!!!!!!!!!!!!!! pow(radius,3) evt få med if-setningen for å skjekke om input er over 0
		cout << "Volumet til kulen blir: " << (1.333) * M_PI * pow(radius,3) << endl; 
		/*if (radius > 0)
		{
			double volum;
			cout.precision(2);
			volum = 4/3 * M_PI * pow(radius,3);
			return volum;
			cout << "Volumet til kulen blir: " << volum << endl;
		}
		else
		{
			cout << "Er tallet ditt positivt?" << endl;	
		}*/
		
	}

	// OPPGAVE_2: Annengradslikning
	else if (valg == '2')
	{
		cout << "Du valgte oppgave 2: Annengradslikning" << endl;
		cout << "aX^2 + bX + c\n" << endl;

		float a, b, c;
		float z;

		cout << "Skriv inn verdier for a, b og c:" << endl;
		cin >> a >> b >> c;

		z = pow(b,2)-(4*a*c);

		if (a==0)
		{
			cout << "Likningen er ikke annengrads, l" << (char)155 << "sningen er: " << -c/b << endl; 
		}
		else
		{
			if (z < 0)
			{
				cout << "R" << (char)155 << "ttene er imagin" << (char)145 << "re." << endl;
			}
			else
			{
				cout << "x1 = " << (-b + sqrt(z))/(2*a) << endl;
				cout << "x2 = " << (-b - sqrt(z))/(2*a) << endl;
			}
		}
	}

	// OPPGAVE_3: Avstand mellom geografiske punkter (Haversine Formula)
	else if (valg == '3')
	{
		cout << "Du valgte oppgave 3: Avstand mellom geografiske punkter" << endl;
		double lat1,lat2,long2,long1;
		//double lat1=45.54243333333333,lat2=45.53722222,long1=-122.96045277777778,long2=-122.9630556;
		
		cout << "Skriv inn latitude på punkt1" << endl;
		cin >> lat1;

		cout << "Skriv inn longitude på punkt1" << endl;
		cin >> long1;

		cout << "Skriv inn latitude på punkt2" << endl;
		cin >> lat2;

		cout << "Skriv inn longitude på punkt2" << endl;
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
		
		cout << "Avstanden er på: " << distance << " km" << endl;

		/*		double hgrad1, hgrad2, bgrad1, bgrad2, avstand; //hgrad=høydegrad, bgrad=breddegrad
		const double radiusJord = 6378.137; //i km

		cout << "Skriv inn punkt 1:" << endl;
		cin >> hgrad1 >> bgrad1;
		
		cout << "Skriv inn punkt 2:" << endl;
		cin >> hgrad2 >> bgrad2;

		double ahgrad1 = hgrad1*(M_PI/180);
		double abgrad1 = bgrad1*(M_PI/180);
		double ahgrad2 = hgrad2*(M_PI/180);
		double abgrad2 = bgrad2*(M_PI/180);

		double aBgrad = abgrad1 - abgrad2;
		double aHgrad = ahgrad1 - ahgrad2;
		
		double aHarv = pow(sin(aHgrad/2.0),2.0)+cos(ahgrad1)*cos(ahgrad2)*pow(sin(aBgrad/2),2);
		double cHarv = 2*atan2(sqrt(aHarv),sqrt(1.0-aHarv));

		avstand = radiusJord*cHarv;

		printf("Avstanden mellom (%d, %d) og (%d, %d) er %d", hgrad1, bgrad1, hgrad2, bgrad2, avstand);

		/*double aHarv= pow(sin(dLat/2.0),2.0)+cos(dlat1)*cos(dlat2)*pow(sin(dLong/2),2);
        double cHarv=2*atan2(sqrt(aHarv),sqrt(1.0-aHarv));


        //earth's radius from wikipedia varies between 6,356.750 km — 6,378.135 km (˜3,949.901 — 3,963.189 miles)
        //The IUGG value for the equatorial radius of the Earth is 6378.137 km (3963.19 mile)

        const double earth=3963.19;//I am doing miles, just change this to radius in kilometers to get distances in km
        double distance=earth*cHarv;*/

	}

	// OPPGAVE_4: Annuitetslån
	else if (valg == '4')
	{
		cout << "Du valgte oppgave 4: Annuitetslån" << endl;
		cout << "Oppgi startlån, rente(i %) og antall år: " << endl;
		double startlån, rente, terminbelop;
		int år;
		
  
		//rente = rente/100;
		// T = terminbelop, L = startlån, T = L * (p%) * ((1+p%)^n / (1+p%)^n -1) 
		terminbelop = startlån * rente * ((pow(1+rente,år)) / (pow(1+rente,år))-1);

		printf("Terminbelop = %d",terminbelop);
		printf("Aar		Terminbelop		Renter	Avdrag			Restgjeld");
		
		for (int i = 0; i++; i == år)
		{

		}
	}

	// OPPGAVE_5: Tall som tekst
	else if (valg == '5')
	{
		cout << "Du valgte oppgave 5: Tall som tekst" << endl;
		cout << "Skriv inn et tall f.o.m. 0 t.o.m. 1000" << endl;
		int tall;
		cin >> tall;



	}

	// OPPGAVE_0: Avslutt program
	else if (valg == '0')
	{
		cout << "Du valgte oppgave 0: Avslutt" << endl;
		cout << "Programmet avslutter..." << endl;
		exit(0);
	}

	/*else
	{
		return false;
	}
	return true;*/
	
}

int main()
{
	while (!meny())
	{
		cout << "lol" << endl;
		cout << "prøv igjen" << endl;
	}

}
