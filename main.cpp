#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <fstream>

using namespace std;

int silnia(int liczba)
{
    int wynik=1;
    if(liczba==0)
        wynik=1;
    else
    while(liczba!=1)
    {
        wynik=wynik*liczba;
        liczba--;
    }
return wynik;
}

int main()
{
	setlocale(LC_ALL, "");

int liczba[500], n=0, i, x=0;

	fstream plik, plik2;

	plik.open("liczby.txt");
	plik2.open("wyniki.txt", ios::out);

	while(plik>>liczba[n])
   	n++;

	for(i=0;i<n;i++)
	{
	   plik>>liczba[i];

		if(liczba[i]==1)
		x++;
		while(liczba[i]%3==0)
		{
			liczba[i]=liczba[i]/3;
			if(liczba[i]==1)
			{
			x++;
//			break;
			}
		}
	}
	cout<<x<<endl;;




plik.close();

plik.open("liczby.txt");

int lp, cyfra, iloczyn;
float suma;

	for(i=0;i<500;i++)
	{

	   plik>>liczba[i];

	    lp=liczba[i];
	    suma=0;

	while(liczba[i]>=10)
		{

			cyfra=liczba[i]%10;
			liczba[i]=liczba[i]/10;
			iloczyn=1;
            if(cyfra>0)
			{
			    iloczyn=silnia(cyfra);

			  // for(int c=cyfra;c>=1;c--)
				//{iloczyn=iloczyn*c;}
				suma=suma+iloczyn;
			}
			if(cyfra==0)
                suma++;

        		}
		iloczyn=1;

		for(int r=liczba[i]; r>=1;r--)
            iloczyn=iloczyn*r;

        suma=suma+iloczyn;

       if(suma==lp)
      cout<<"sumalp="<<lp<<endl;

}
}



