#include <iostream>
#include <stdio.h>
#include <string.h>
#include <fstream>
#include <string.h>

using namespace std;

int main()
{
    string alfabet,cuvant;
    int n,klinii,mlinii,stcurenta,i,j,k,ok=0,a,b;
    char litera;

    ifstream fisier;
 fisier.open("afd.in");
 if (fisier.is_open())
 {
    while (!fisier.eof())
    {
        //citire din fisier
        fisier >> n;
        char matrice[n+1][n+1];
        int starifinale[n+1];
        fisier.ignore(10000,'\n');

        for (i=0;i<n+1;i++)
        {
            fisier >> starifinale[i];
        }

        fisier.ignore(10000,'\n');
        getline(fisier,alfabet);

        fisier >> klinii;
        fisier.ignore(10000,'\n');

        for (i=0;i<klinii;i++)
        {
           fisier >> litera ;
           fisier >> a ;
           fisier >> b ;
           matrice[a][b]=litera;
        }

        fisier.ignore(10000,'\n');
        fisier >> mlinii;
        fisier.ignore(10000,'\n');

        for (i=0;i<mlinii;i++)
        {
            getline(fisier,cuvant);
            //verificare cuvant
            stcurenta=0;
            for(j=0;j<cuvant.length();j++)
            {
                litera=cuvant[j];
                ok=0;
                for(k=0;k<=n;k++)
                {
                    if(litera==matrice[stcurenta][k])
                    {
                        stcurenta=k;
                        ok=1;
                        break;
                    }
                }
                if(ok==0)
                    break;
            }
            if((starifinale[stcurenta]==1) && (ok!=0))
                cout<<"Da"<<endl;
            else
                cout<<"Nu"<<endl;

            ok=0;
        }
    }
}




fisier.close();




    return 0;
}

