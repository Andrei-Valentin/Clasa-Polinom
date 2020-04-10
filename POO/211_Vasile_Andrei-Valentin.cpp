#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <math.h>

#include<bits/stdc++.h>

using namespace std;

class Complex{
private:
    int re;
    int im;
public:
    Complex(int re,int im);
    Complex (Complex&);
    ~Complex ();

    void afisare(ostream &out);
    void citire(istream &in);
    friend istream& operator>>(istream &in, Complex& z);                        ///Supraincarcare operator >>
    friend ostream& operator<<(ostream &out, Complex& z);                       ///Supraincarcare operator <<
    Complex& operator=(Complex const &z);                                       ///Supraincarcare operator =

    friend Complex& operator+(Complex& z1, Complex& z2);
    friend Complex& operator-(Complex& z1, Complex& z2);
    friend Complex& operator*(Complex const &z1, Complex const &z2);
    friend Complex& operator*(Complex& z1,int intreg);


    int getre(){return re;};
    int getim(){return im;};
};

Complex::Complex(int re=0,int im=0){
        this->re=re;
        this->im=im;
    }

Complex::Complex(Complex &z){
    this->re = z.re;
    this->im = z.im;
}

Complex::~Complex(){
    this->re=0;
    this->im=0;
}
void Complex::citire(istream &in){
        cout<<"Cititi partea reala"<<endl;
        in>>re;
        cout<<"Cititi partea imaginara"<<endl;
        in>>im;
}
istream& operator>>(istream& in,Complex& z){
    z.citire(in);
    return in;
}

void Complex::afisare(ostream &out){
    if (im==0) {
        out<<re;
    }
    else{
        if (im < 0){
            out<<re<<im<<"*i";
        }
        else{
            out<<re<<"+"<<im<<"*i";
        }
    }
}
ostream& operator<<(ostream& out, Complex& z){
    z.afisare(out);
    return out;
}

Complex& Complex::operator=(Complex const &z){
    re=z.re;
    im=z.im;
}

inline Complex& operator+(Complex &z1, Complex& z2){
    Complex *z = new Complex;
    z->re = z1.re + z2.re;
    z->im = z1.im + z2.im;
    return *z;
}

inline Complex& operator-(Complex& z1, Complex& z2){
    Complex *z = new Complex;
    z->re = z1.re - z2.re;
    z->im = z1.im - z2.im;
    return *z;
}

inline Complex& operator*(Complex const &z1, Complex const &z2){
    Complex *z=new Complex;
    z->re = z1.re * z2.re - z1.im * z2.im;
    z->im = z1.re * z2.im + z2.re * z1.im;
    return *z;
}

inline Complex& operator*(Complex& z1,int intreg){
    Complex *z=new Complex;
    z->re = z1.re * intreg;
    z->im = z1.im * intreg;
    return *z;
}

class Matrice{
protected:
    Complex **v;
    static int nrobiecte;                                                       ///Variabila statica care va contoriza numarul de obiecte
public:
    Matrice(Complex **v);
    Matrice();
    Matrice (Matrice&);
    virtual ~Matrice ();

    virtual void afisare(ostream &out);
    virtual void citire(istream &in);
    friend istream& operator>>(istream &in, Matrice& z);                        ///Supraincarcare operator >>
    friend ostream& operator<<(ostream &out, Matrice& z);                       ///Supraincarcare operator <<
    Matrice& operator=(Matrice &z);                                             ///Supraincarcare operator =

    static void numarObiecte(){cout<<nrobiecte;}                                ///Functie statica ce afiseaza variabila statica nrobiecte
    static void minusObiecte(){nrobiecte--;}                                    ///Pentru a putea mentine numaratoarea corecta la exemplul de upcasting
    void CitireMemorareAfisare(int &Mcurenta,bool *Exista,Matrice *M[]);        ///Citirea informatiilor a n obiecte,memorarea si afisarea acestora
    virtual void VerificareDiagonala(){cout<<"Matricea de tip baza nu poate fi diagonala"<<endl;}///Metoda verificare daca o matrice e diagonala
};

int Matrice::nrobiecte;

Matrice::Matrice(Complex **v){
    this->v=v;
}

Matrice::Matrice(){
    nrobiecte++;
    cout<<"Matricea a fost creata"<<endl;
}

Matrice::Matrice(Matrice &z){
    this->v=z.v;
}

Matrice::~Matrice(){
    nrobiecte--;
    cout<<"Matricea a fost distrusa"<<endl;

}

void Matrice::citire(istream &in){
    cout<<"Nu se poate citi o matrice de tip baza"<<endl;
}

istream& operator>>(istream& in,Matrice& z){
    z.citire(in);
    return in;
}

void Matrice::afisare(ostream &out){
        cout<<"Nu se poate afisa o matrice de tip baza"<<endl;
}
ostream& operator<<(ostream& out, Matrice& z){
    z.afisare(out);
    return out;
}

Matrice& Matrice::operator=(Matrice &z){
            this->v=z.v;
}




class Matrice_oarecare: public Matrice{
private:
    int lin;
    int col;
public:
    Matrice_oarecare(int lin,int col,Complex **v);
    Matrice_oarecare();
    Matrice_oarecare (Matrice_oarecare&);
    ~Matrice_oarecare ();

    void afisare(ostream &out);
    void citire(istream &in);
    friend istream& operator>>(istream &in, Matrice_oarecare& z);               ///Supraincarcare operator >>
    friend ostream& operator<<(ostream &out, Matrice_oarecare& z);              ///Supraincarcare operator <<
    Matrice_oarecare& operator=(Matrice_oarecare &z);                           ///Supraincarcare operator =

    void VerificareDiagonala();
};


Matrice_oarecare::Matrice_oarecare(int lin,int col,Complex **v){
    this->lin=lin;
    this->col=col;

    v = new Complex *[lin];
    for(int i = 0; i < lin; i++)
        v[i] = new Complex[col];

}

Matrice_oarecare::Matrice_oarecare()
{
    cout<<"Introduceti numar de linii"<<endl;
    cin>>lin;
    cout<<"Introduceti numar de coloane"<<endl;
    cin>>col;

    v = new Complex *[lin];
    for(int i = 0; i < lin; i++)
        v[i] = new Complex[col];

}

Matrice_oarecare::Matrice_oarecare(Matrice_oarecare &z){
    this->v=z.v;
}

Matrice_oarecare:: ~Matrice_oarecare (){
    for (int i = 0; i < lin; ++i)
        delete [] v[i];
    delete [] v;
}

void Matrice_oarecare::citire(istream &in){
        for(int i = 0; i < lin; i++)
            for(int j = 0; j < col; j++)
            {
                cout<<"Cititi elementul de pe linia "<<i<<" coloana "<<j<<endl;
                cin>>v[i][j];
            }
}

void Matrice_oarecare::afisare(ostream &out){
        for(int i = 0; i < lin; i++)
        {
            for(int j = 0; j < col; j++)
            {
                cout<<v[i][j]<<" ";

            }
            cout<<endl;
        }
}

istream& operator>>(istream& in,Matrice_oarecare& z){
    z.citire(in);
    return in;
}

ostream& operator<<(ostream& out, Matrice_oarecare& z){
    z.afisare(out);
    return out;
}

Matrice_oarecare& Matrice_oarecare::operator=(Matrice_oarecare &z){
    if((lin==z.lin) && (col==z.col))
	for (int i=0; i<lin; i++)
		for (int j=0; j<col; j++)
            v[i][j] = z.v[i][j];
    else
    {
        cout<<endl;
        cout<<"Matricile au dimensiuni diferite,operatorul = nu a fost aplicat"<<endl;
    }
}

void Matrice_oarecare::VerificareDiagonala(){
    bool diagonala=true,nenul=false;
    if((lin>1)&&(col>1))
    {
        if(lin==col)                    /// Pentru matricea oarecare trebuie sa verificam daca matricea are dimensiunile egale
        {
            for(int i = 0; i < lin; i++)
                for(int j = 0; j < col; j++)
                {
                    if((i!=j) && ((v[i][j].getre()!=0)||(v[i][j].getim()!=0)))      /// Daca elementul nu se afla pe diagonala si e diferit de 0
                    {                                                               /// atunci matricea nu e diagonala
                        diagonala=false;
                        break;
                    }
                    if((i==j)&& ((v[i][j].getre()!=0)||(v[i][j].getim()!=0)))       /// Daca elementul se afla pe diagonala si e diferit de 0
                        nenul=true;                                                 /// nenul devine true
                }

            if((diagonala==true) && (nenul==true))                                  /// Daca nu avem elemente nenule pe alte pozitii decat pe diagonala
                cout<<"Matricea este diagonala";                                    /// si avem cel putin un el nenul pe diagonala=>matricea e diagonala
            else
                cout<<"Matricea nu este diagonala";
        }
        else
            cout<<"Matricea nu este diagonala deoarece numarul de linii este diferit de numarul de coloane";
    }
    else
        cout<<"Matricea nu este diagonala deoarece are dimensiunile prea mici";
}




class Matrice_patratica: public Matrice{
private:
    int dim;
public:
    Matrice_patratica(int dim,Complex **v);
    Matrice_patratica();
    Matrice_patratica (Matrice_patratica&);
    ~Matrice_patratica ();

    void afisare(ostream &out);
    void citire(istream &in);
    friend istream& operator>>(istream &in, Matrice_patratica& z);              ///Supraincarcare operator >>
    friend ostream& operator<<(ostream &out, Matrice_patratica& z);             ///Supraincarcare operator <<
    Matrice_patratica& operator=(Matrice_patratica &z);                         ///Supraincarcare operator =

    void VerificareDiagonala();
    Complex det(Complex **v,int dim);                                           ///Metoda pentru calcularea determinantului
};


Matrice_patratica::Matrice_patratica(int dim,Complex **v){
    this->dim=dim;

    v = new Complex *[dim];
    for(int i = 0; i < dim; i++)
        v[i] = new Complex[dim];

}

Matrice_patratica::Matrice_patratica(){
    cout<<"Introduceti dimensiunea "<<endl;
    cin>>dim;

    v = new Complex *[dim];
    for(int i = 0; i < dim; i++)
    v[i] = new Complex[dim];
}

Matrice_patratica::Matrice_patratica(Matrice_patratica &z){
    this->v=z.v;
}

Matrice_patratica:: ~Matrice_patratica (){
    for (int i = 0; i < dim; ++i)
        delete [] v[i];
    delete [] v;
}


void Matrice_patratica::citire(istream &in){
        for(int i = 0; i < dim; i++)
            for(int j = 0; j < dim; j++)
            {
                cout<<"Cititi elementul de pe linia "<<i<<" coloana "<<j<<endl;
                cin>>v[i][j];
            }
}

istream& operator>>(istream& in,Matrice_patratica& z){
    z.citire(in);
    return in;
}

void Matrice_patratica::afisare(ostream &out){
        for(int i = 0; i < dim; i++)
        {
            for(int j = 0; j < dim; j++)
            {
                cout<<v[i][j]<<" ";

            }
            cout<<endl;
        }

        Complex determinant;
        determinant=det(v,dim);
        cout<<"Determinantul este: "<<determinant<<endl;
}

ostream& operator<<(ostream& out, Matrice_patratica& z){
    z.afisare(out);
    return out;
}

Matrice_patratica& Matrice_patratica::operator=(Matrice_patratica &z){
    if(dim==z.dim)
        for (int i=0; i<dim; i++)
            for (int j=0; j<dim; j++)
                v[i][j] = z.v[i][j];
    else
    {
        cout<<endl;
        cout<<"Matricile au dimensiuni diferite,operatorul = nu a fost aplicat"<<endl;
    }

}

Complex Matrice_patratica::det(Complex **v,int dimensiune){
    int pas,i,j,a=0,b=0;
    Complex determinant;
    Complex **minor;

    minor= new Complex *[50];
        for(int i = 0; i < 50; i++)
            minor[i] = new Complex[50];

    if(dimensiune==1)
        return v[0][0];
    else if(dimensiune==2)
    {
        determinant=(v[0][0]*v[1][1]-v[0][1]*v[1][0]);
        return determinant;
    }
    else
    {
        for(int pas=0;pas<dimensiune;pas++)
        {
            for(i=0;i<dimensiune;i++)
            {
                for(j=0;j<dimensiune;j++)
                    if((i!=0) && (j!=pas))
                    {
                        minor[a][b]=v[i][j];
                        b++;
                        if(b==dimensiune-1)
                        {
                           a++;
                           b=0;
                        }
                    }
            }
            a=0;
            b=0;

            if(pas%2==0)
                determinant=determinant+v[0][pas]*det(minor,dimensiune-1);
            else
                determinant=determinant-v[0][pas]*det(minor,dimensiune-1);
        }
        return determinant;
    }
}

void Matrice_patratica::VerificareDiagonala(){
    bool diagonala=true,nenul=false;
    if(dim>1)
    {
        for(int i = 0; i < dim; i++)
            for(int j = 0; j < dim; j++)
            {
                if((i!=j) && ((v[i][j].getre()!=0)||(v[i][j].getim()!=0)))       /// Daca elementul nu se afla pe diagonala si e diferit de 0
                    {                                                            /// atunci matricea nu e diagonala
                        diagonala=false;
                        break;
                    }
                if((i==j)&& ((v[i][j].getre()!=0)||(v[i][j].getim()!=0)))        /// Daca elementul se afla pe diagonala si e diferit de 0
                    nenul=true;                                                  /// nenul devine true
            }
        if((diagonala==true) && (nenul==true))                                   /// Daca nu avem elemente nenule pe alte pozitii decat pe diagonala
            cout<<"Matricea este diagonala";                                     /// si avem cel putin un el nenul pe diagonala=>matricea e diagonala
        else
            cout<<"Matricea nu este diagonala";
    }
    else
        cout<<"Matricea nu este diagonala deoarece are dimensiunea prea mica";

}




void tip(Matrice *&m, int &Mcurenta,int (&Exista)[50]) {
    string s;
    cout<<"\n";
    cout<<"Introduceti tipul pentru Matricea "<<Mcurenta+1<<": ";
    cin>>s;
    try{
        if(s=="oarecare" || s=="Oarecare"){
                Exista[Mcurenta]=1;
                m=new Matrice_oarecare;
                cin>>*m;

                Mcurenta++;
        }
        else
            if(s=="patratica" || s=="Patratica"){
                Exista[Mcurenta]=2;
                m=new Matrice_patratica;
                cin>>*m;

                Mcurenta++;
            }
        else
            if(s=="baza" || s=="Baza"){
                m=new Matrice;
                Exista[Mcurenta]=-1;
                cin>>*m;

                Mcurenta++;
            }
                else
                    throw 10;
    }
    catch (bad_alloc var){
        cout << "Allocation Failure\n";
        exit(EXIT_FAILURE);
    }
    catch(int j){
        cout<<"Nu ati introdus un tip valid. Incercati oarecare/patratica sau baza.\n ";
    }
}




void menu_output(int Mcurenta,int *Exista)
{
    cout<<"\n Vasile Andrei-Valentin 211 - Proiect - Matrice de numere complexe reprezentate ca tablouri bidimensionale: \n";
    cout<<"\n\t MENIU:";
    cout<<"\n===========================================\n";
    if(Mcurenta>0)
    {
        cout<<"Matrici citite: ";
        for(int i=1;i<=Mcurenta;i++)
        {
            if(Exista[i-1]==1)
                cout<<"MO"<<i<<" ";
            else if (Exista[i-1]==2)
                cout<<"MP"<<i<<" ";
            else if (Exista[i-1]==-1)
                cout<<"M"<<i<<" ";
        }
      cout<<endl;
    }
    else
        cout<<"Nu s-a citit inca nicio matrice"<<endl;

    cout<<"\n";
    cout<<"1. Citire matrice"; cout<<"\n";
    cout<<"2. Afisare matrice"; cout<<"\n";
    cout<<"3. Citire si afisare pentru mai multe matrici"; cout<<"\n";
    cout<<"4. Verificare daca o matrice este diagonala"; cout<<"\n";
    cout<<"5. Exemplu de upcasting"; cout<<"\n";

    cout<<endl;
    cout<<"0. Iesire."; cout<<"\n";
}
void menu()
{
    int option;///optiunea aleasa din meniu
    option=0;
    int Mcurenta=0,dim,lin,col;
    int Exista[50] = { 0 };
    Matrice *M[50] = { NULL };

    do
    {
        menu_output(Mcurenta,Exista);

        cout<<"\nIntroduceti numarul actiunii: ";
        scanf("%d", &option);

        if (option==1)                                                          ///1. Citire matrice
        {
            tip(M[Mcurenta],Mcurenta,Exista);

            cout<<endl;
            cout<<"In total au fost citite ";
            Matrice::numarObiecte();
            cout<<" matrici"<<endl;
        }


        if (option==2)                                                          ///2.Afisare matrice
        {

            cout<<"Au fost citite ";
            Matrice::numarObiecte();
            cout<<" matrici"<<endl;

            int nrafisat;
            cout<<"Introduceti numarul matricei care trebuie afisata ";
            cin>>nrafisat;
            if (Exista[nrafisat-1]!=0 && nrafisat>0)
            {
                cout<<endl;
                cout<<"Matricea "<<nrafisat<<" este: "<<endl;
                cout<<*M[nrafisat-1];
            }

            else
            cout<<"Matricea cu numarul "<<nrafisat<<" nu a fost citita";
        }


        if(option==3)                                                           ///3.Citire si afisare pentru mai multe matrici
        {
            int nrmatrici;
            cout<<"Introduceti numarul de matrici pe care vreti sa il cititi"<<endl;
            cin>>nrmatrici;

            if(nrmatrici>0)
            {
                int curent=Mcurenta;
                for(int i=curent;i<curent+nrmatrici;i++)
                    tip(M[Mcurenta],Mcurenta,Exista);

                cout<<"Matricile sunt:"<<endl;
                for(int i=curent;i<curent+nrmatrici;i++)
                {
                    cout<<"Matricea "<<i+1<<":"<<endl;
                    cout<<*M[i];
                    cout<<endl;
                }

                cout<<endl;
                cout<<"In total au fost citite ";
                Matrice::numarObiecte();
                cout<<" matrici"<<endl;
            }
            else
                cout<<"Nu se pot citi "<<nrmatrici<<" matrici"<<endl;
        }


        if (option==4)                                                      ///4.Metoda care sa verifice daca o matrice triunghiulara este diagonala
        {
            cout<<"Au fost citite ";
            Matrice::numarObiecte();
            cout<<" matrici"<<endl;


            int nrverificat;
            cout<<"Introduceti numarul matricei care trebuie verificata ";
            cin>>nrverificat;
            if (Exista[nrverificat-1]!=0 && nrverificat>0)
            {
                cout<<endl;
                cout<<"Matricea "<<nrverificat<<endl;
                M[nrverificat-1]->VerificareDiagonala();
            }

            else
            cout<<"Matricea cu numarul "<<nrverificat<<" nu a fost citita";
        }


        if (option==5)                                                          ///5.Exemplu de upcasting
        {
            string st;
            cout<<"\n";
            cout<<"Introduceti tipul de matrice pe care sa il etichetati ca matrice baza: ";
            cin>>st;
            try{
                if(st=="oarecare" || st=="Oarecare"){
                        Matrice_oarecare *a=(Matrice_oarecare*)new Matrice;
                        a->minusObiecte();
                        cout<<endl;
                        cin>>*a;
                        cout<<*a;
                }
                else
                    if(st=="patratica" || st=="Patratica"){
                        Matrice_patratica *a=(Matrice_patratica*)new Matrice ;
                        a->minusObiecte();
                        cin>>*a;
                        cout<<*a;
                    }
                        else
                            throw 10;
            }
            catch (bad_alloc var){
                cout << "Allocation Failure\n";
                exit(EXIT_FAILURE);
            }
            catch(int j){
                cout<<"Nu ati introdus un tip valid. Incercati oarecare sau patratica.\n ";
            }
        }


        if (option==0)
        {
            cout<<endl;
            cout<<"EXIT!"<<endl;

        for(int i=0;i<50;i++)
            if(M[i]!= NULL)
                delete M[i];

        cout<<"Numar de matrici ramase ";
        Matrice::numarObiecte();
        cout<<endl;
        }

        if (option<0||option>5)
        {
            cout<<endl;
            cout<<"Selectie invalida"<<endl;
        }
        cout<<endl;
        system("pause");
        system("cls");
    }
    while(option!=0);
}


int main()
{
    menu();
    return 0;
}
