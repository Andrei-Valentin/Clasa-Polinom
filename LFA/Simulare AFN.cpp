#include <iostream>
#include <stdio.h>
#include <string.h>
#include <fstream>
#include <string.h>
#include <bits/stdc++.h>
using namespace std;


int main()
{
    string alfabet,cuvant;
    int n,klinii,mlinii,stcurenta,i,j,k,ok=0,a,b;
    char litera;
    stack <int> drum;   //stiva care retine drumul

    ifstream fisier;
    fisier.open("afn.in");

 if (fisier.is_open())
 {
    while (!fisier.eof())
    {
        //citire din fisier
        fisier >> n;
        char matrice[n+1][n+1];
        int starifinale[n+1];   //vectorul de  caracteristica a starilor finale
        int skip[n+1][n+1]={0}; // pentru a nu repeta acelasi drum daca nu este bun
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
                        if(skip[stcurenta][k]==1)
                        {
                            continue; //daca drumul este blocat va sari peste el
                        }
                        else
                        {
                            //daca un nod pe care poate merge,introduce nodul din care a venit in stiva
                            //si deblocheaza drumurile catre vecinii nodului curent
                            drum.push(stcurenta);
                            stcurenta=k;
                            for(int contor=0;contor<n;contor++)
                            skip[stcurenta][contor]=0;

                            ok=1;
                            break;
                        }

                    }
                }
                if(ok==0)
                    {
                        if(drum.empty()) //daca am ajuns la inceputul drumului si nu mai avem alte optiuni cuvantul nu e acceptat
                            break;
                        else
                        {
                            k=stcurenta;
                            stcurenta=drum.top(); //revine la nodul anterior
                            skip[stcurenta][k]=1; //blocheaza drumul la nod
                            drum.pop();
                            j=j-1;                //repeta pasul dupa ce a blocat drumul gresit
                        }
                    }

               else if((j+1==cuvant.length() ) && (starifinale[stcurenta]!=1))
                {
                        k=stcurenta;
                        stcurenta=drum.top();
                        skip[stcurenta][k]=1;
                        drum.pop();
                        j=j-1;
                }
            }
            if((starifinale[stcurenta]==1) && (ok!=0))
                cout<<"1"<<endl;
            else
                cout<<"0"<<endl;

            ok=0;
            for(int m=0;m<n+1;m++)
                for(int l=0;l<n+1;l++)
                    skip[m][l]=0;

            while(!drum.empty())
                drum.pop();
        }
    }
}

    fisier.close();
    return 0;
}

