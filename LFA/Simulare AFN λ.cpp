#include <iostream>
#include <stdio.h>
#include <string.h>
#include <fstream>
#include <string.h>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string alfabet,cuvant,multimestarifinale;
    int n,klinii,mlinii,stcurenta,i,j,k,ok=0,a,b;
    char litera;
    bool existaLambda=false;
    stack <int> drum;   //stiva care retine drumul

    ifstream fisier;
    fisier.open("afnlambda.in");

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

        getline(fisier,alfabet);

        getline( fisier, multimestarifinale );
        istringstream is( multimestarifinale );
        int sf;
        while( is >> sf )
        {
            starifinale[sf]=1;
        }

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
                    else if((matrice[stcurenta][k]=='λ') && (skip[stcurenta][k]!=1))
                    {
                        drum.push(stcurenta);
                        stcurenta=k;
                        for(int contor=0;contor<n;contor++)
                        skip[stcurenta][contor]=0;
                        j=j-1;
                        ok=1;
                        break;
                    }
                }
                if(ok==0)
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

                else
                    if((j+1==cuvant.length() ) && (starifinale[stcurenta]!=1))
                    {
                        for(int contor=0;contor<=n;contor++)
                            if(matrice[stcurenta][contor]=='λ')
                            {
                                existaLambda=true;
                                break;
                            }
                        if(existaLambda==true)  //daca cuvantul s-a terminat dar nu este intr-o stare finala cautam lambda tranzitiile pana la o stare finala
                        {
                            while(!drum.empty())
                            {
                                for(k=0;k<=n;k++)
                                {
                                    if((matrice[stcurenta][k]=='λ') && (skip[stcurenta][k]!=1))
                                    {
                                        drum.push(stcurenta);
                                        stcurenta=k;
                                        for(int contor=0;contor<n;contor++)
                                            skip[stcurenta][contor]=0;
                                        ok=1;
                                        break;
                                    }
                                }
                                if(ok==0)
                                {
                                    k=stcurenta;
                                    stcurenta=drum.top();
                                    skip[stcurenta][k]=1;
                                    drum.pop();
                                }
                                ok=0;

                                if(starifinale[stcurenta]==1)
                                {
                                    ok=1;
                                    break;
                                }
                            }
                        }

                        else
                        {
                            k=stcurenta;
                            stcurenta=drum.top();
                            skip[stcurenta][k]=1;
                            drum.pop();
                            j--;
                        }

                   }
            }
            if((starifinale[stcurenta]==1) && (ok!=0))
                cout<<"1"<<endl;
            else
                cout<<"0"<<endl;

            ok=0;
            existaLambda=false;

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

