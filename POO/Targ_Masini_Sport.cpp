#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <typeinfo>
#include <time.h>

#include<bits/stdc++.h>
using namespace std;


class MasinaSport{
protected:
    static int NrMasini;
    static int NrMasiniVandute;
    string Producator;
    string Model;
    string Motor;
    string Carburant;
    string TipCutieViteze;
    string Culoare;
    int Pret;
    float VitezaMaxima;
    float Consum; //L/100KM
    int PutereMaxima; //CP
    int Emisii; //CO2 G/KM
    bool Expusa=false; ///Daca masina a fost adaugata la expozitie
public:
    MasinaSport(string Producator,string Model,string Motor,string Carburant,string TipCutieViteze,string Culoare,float Pret,float VitezaMaxima,float Consum,int PutereMaxima,int Emisii);
    MasinaSport(MasinaSport&);
    virtual ~MasinaSport();

    virtual void citire(istream &in);
    virtual void afisare(ostream &out);
    friend istream& operator>>(istream &in, MasinaSport& z);
    friend ostream& operator<<(ostream &out, MasinaSport& z);
    MasinaSport& operator=(MasinaSport &z);

    virtual void AfisareModel(){cout<<Model;}
    void Expunere(){Expusa=true;}
    bool EsteExpusa() const {return Expusa;}         ///functie constanta care ne spune daca masina este expusa sau nu
    static void NumarMasini(){cout<<NrMasini;}
    static void NumarMasiniVandute(){cout<<NrMasiniVandute;}
};
int MasinaSport::NrMasini;
int MasinaSport::NrMasiniVandute;

MasinaSport::MasinaSport(string Producator="",string Model="",string Motor="",string Carburant="",string TipCutieViteze="",string Culoare="",float Pret=0,float VitezaMaxima=0,float Consum=0,int PutereMaxima=0,int Emisii=0){
this->Producator=Producator;
this->Model=Model;
this->Motor=Motor;
this->Carburant=Carburant;
this->TipCutieViteze=TipCutieViteze;
this->Culoare=Culoare;

try
    {
        if (Pret<0)
            throw Pret;
        else if(VitezaMaxima<0)
        {
            int   VitezaMAX = static_cast<int>(VitezaMaxima);
            throw VitezaMAX;
        }
        else if(Consum<0)
        {
            int   Cons = static_cast<int>(Consum);
            throw Cons;
        }
        else if(PutereMaxima<0)
            throw PutereMaxima;
        else if(Emisii<0)
            throw Emisii;
    }
    catch (int x)
    {
        cout<<"Eroare in constructor, nu se pot introduce valori negative.\n";
        exit(EXIT_FAILURE);
    }

this->Pret=Pret;
this->VitezaMaxima=VitezaMaxima;
this->Consum=Consum;
this->PutereMaxima=PutereMaxima;
this->Emisii=Emisii;

NrMasini++;
}

MasinaSport::MasinaSport(MasinaSport &z){
    this->Producator=z.Producator;
    this->Model=z.Model;
    this->Motor=z.Motor;
    this->Carburant=z.Carburant;
    this->TipCutieViteze=z.TipCutieViteze;
    this->Culoare=z.Culoare;
    this->Pret=z.Pret;
    this->VitezaMaxima=z.VitezaMaxima;
    this->Consum=z.Consum;
    this->PutereMaxima=z.PutereMaxima;
    this->Emisii=z.Emisii;
}

MasinaSport::~MasinaSport(){
    Pret=-1000;
    NrMasini--;
}

void MasinaSport::citire(istream &in){
    cout<<"Introduceti numele producatorului:"<<endl;
    cin>>Producator;
    cout<<"Introduceti numele modelului:"<<endl;
    cin>>Model;
    cout<<"Introduceti numele motorului:"<<endl;
    cin>>Motor;
    cout<<"Introduceti tipul de carburant:"<<endl;
    cin>>Carburant;
    cout<<"Introduceti tipul de cutie de viteze:"<<endl;
    cin>>TipCutieViteze;
    cout<<"Introduceti culoarea masinii:"<<endl;
    cin>>Culoare;

    cout<<"Introduceti pretul masinii (in EURO):"<<endl;
    int p;
    cin>>p;
    try
    {
        if (p<0)
            throw p;
    }
    catch (int x)
    {
        cout<<"Eroare la citire, nu se poate introduce un pret negativ.\n";
        exit(EXIT_FAILURE);
    }
    Pret=p;

    cout<<"Introduceti viteza maxima (KM/H):"<<endl;
    cin>>VitezaMaxima;
    cout<<"Introduceti consumul masinii (L/100KM):"<<endl;
    cin>>Consum;
    cout<<"Introduceti puterea maxima (CP):"<<endl;
    cin>>PutereMaxima;
    cout<<"Introduceti nivelul de emisii (CO2 G/KM):"<<endl;
    cin>>Emisii;
}

istream& operator>>(istream& in,MasinaSport& z){
    z.citire(in);
    return in;
}

void MasinaSport::afisare(ostream &out){
    cout<<Producator<<" ";
    cout<<Model<<endl;
    cout<<"Culoare: "<<Culoare<<endl;
    cout<<"Motor: "<<Motor<<", ";
    cout<<Carburant<<endl;
    cout<<"Cutie de viteze: "<<TipCutieViteze<<endl;
    cout<<"Putere Maxima: "<<PutereMaxima<<" CP"<<endl;
    cout<<"Viteza Maxima: "<<VitezaMaxima<<" KM/H"<<endl;
    cout<<"Consum: "<<Consum<<" L/100KM"<<endl;
    cout<<"Emisii: "<<Emisii<<" G/KM"<<endl;
    cout<<"Pret: "<<Pret<<" EURO"<<endl;
}

ostream& operator<<(ostream& out, MasinaSport& z){
    z.afisare(out);
    return out;
}

MasinaSport& MasinaSport::operator=(MasinaSport &z){
    if (this!=&z)
    {
        Producator = z.Producator;
        Model = z.Model;
        Motor = z.Motor;
        Carburant = z.Carburant;
        TipCutieViteze = z.TipCutieViteze;
        Culoare = z.Culoare;
        Pret = z.Pret;
        VitezaMaxima = z.VitezaMaxima;
        Consum = z.Consum;
        PutereMaxima = z.PutereMaxima;
        Emisii = z.Emisii;
    }
    return *this;
}




class Coupe:public MasinaSport{
public:
    Coupe(string Producator,string Model,string Motor,string Carburant,string TipCutieViteze,string Culoare,float Pret,float VitezaMaxima,float Consum,int PutereMaxima,int Emisii);
    Coupe(Coupe&);
    ~Coupe();

    void citire(istream &in);
    void afisare(ostream &out);
    Coupe& operator=(Coupe &z);

    void AfisareModel(){cout<<"(CP)"<<Model;}
};

Coupe::Coupe(string Producator="",string Model="",string Motor="",string Carburant="",string TipCutieViteze="",string Culoare="",float Pret=0,float VitezaMaxima=0,float Consum=0,int PutereMaxima=0,int Emisii=0):MasinaSport(Producator,Model,Motor,Carburant,TipCutieViteze,Culoare,Pret,VitezaMaxima,Consum,PutereMaxima,Emisii){
}

Coupe::Coupe(Coupe &z):MasinaSport(z){
}

Coupe::~Coupe(){
    cout<<"A fost distrus un obiect de tip Coupe"<<endl;
}

void Coupe::citire(istream &in){
    MasinaSport::citire(in);
}

void Coupe::afisare(ostream &out){
    cout<<"Coupe"<<endl;
    MasinaSport::afisare(out);
}

Coupe& Coupe :: operator=(Coupe &z)
{
    if(this!=&z)
    {
        MasinaSport::operator=(z);
    }
    return *this;
}




class HotHatch:public MasinaSport{
public:
    HotHatch(string Producator,string Model,string Motor,string Carburant,string TipCutieViteze,string Culoare,float Pret,float VitezaMaxima,float Consum,int PutereMaxima,int Emisii);
    HotHatch(HotHatch &z);
    ~HotHatch();

    void citire(istream &in);
    void afisare(ostream &out);
    HotHatch& operator=(HotHatch &z);

    void AfisareModel(){cout<<"(HH)"<<Model;}
};

HotHatch::HotHatch(string Producator="",string Model="",string Motor="",string Carburant="",string TipCutieViteze="",string Culoare="",float Pret=0,float VitezaMaxima=0,float Consum=0,int PutereMaxima=0,int Emisii=0):MasinaSport(Producator,Model,Motor,Carburant,TipCutieViteze,Culoare,Pret,VitezaMaxima,Consum,PutereMaxima,Emisii){
}

HotHatch::HotHatch(HotHatch &z):MasinaSport(z){
}

HotHatch::~HotHatch(){
    cout<<"A fost distrus un obiect de tip HotHatch"<<endl;
}

void HotHatch::citire(istream &in){
    MasinaSport::citire(in);
}

void HotHatch::afisare(ostream &out){
    cout<<"Hot-Hatch"<<endl;
    MasinaSport::afisare(out);
}

HotHatch& HotHatch :: operator=(HotHatch &z)
{
    if(this!=&z)
    {
        MasinaSport::operator=(z);
    }
    return *this;
}




class Cabrio:public MasinaSport{
private:
    string Acoperis; //textil sau metalic
public:
    Cabrio(string Producator,string Model,string Motor,string Carburant,string TipCutieViteze,string Culoare,float Pret,float VitezaMaxima,float Consum,int PutereMaxima,int Emisii,string Acoperis);
    Cabrio(Cabrio&);
    ~Cabrio();

    void citire(istream &in);
    void afisare(ostream &out);
    friend istream& operator>>(istream &in, Cabrio& z);
    friend ostream& operator<<(ostream &out, Cabrio& z);
    Cabrio& operator=(Cabrio &z);

    void AfisareModel(){cout<<"(CB)"<<Model;}
};

Cabrio::Cabrio(string Producator="",string Model="",string Motor="",string Carburant="",string TipCutieViteze="",string Culoare="",float Pret=0,float VitezaMaxima=0,float Consum=0,int PutereMaxima=0,int Emisii=0,string Acoperis=""):MasinaSport(Producator,Model,Motor,Carburant,TipCutieViteze,Culoare,Pret,VitezaMaxima,Consum,PutereMaxima,Emisii)
{
    this->Acoperis=Acoperis;
}

Cabrio::~Cabrio(){
    Acoperis="";
    cout<<"A fost distrus un obiect de tip Cabrio"<<endl;
}

Cabrio::Cabrio(Cabrio &z):MasinaSport(z)
{
   Acoperis=z.Acoperis;
}

void Cabrio::citire(istream &in){
    MasinaSport::citire(in);
    cout<<"Introduceti materialul din care este facut acoperisul:"<<endl;
    cin>>Acoperis;
}

void Cabrio::afisare(ostream &out){
    cout<<"Cabrio"<<endl;
    MasinaSport::afisare(out);
    cout<<"Material acoperis: "<<Acoperis<<endl;
}

istream& operator>>(istream& in,Cabrio& z){
    z.citire(in);
    return in;
}

ostream& operator<<(ostream& out, Cabrio& z){
    z.afisare(out);
    return out;
}


Cabrio& Cabrio :: operator=(Cabrio &z)
{
    if(this!=&z)
    {
        MasinaSport::operator=(z);
        Acoperis=z.Acoperis;
    }
    return *this;
}




class SUPERSPORT:public MasinaSport{
private:
    int PretVanzare; /// -1 daca masina nu a fost vanduta
public:
    SUPERSPORT(string Producator,string Model,string Motor,string Carburant,string TipCutieViteze,string Culoare,float Pret,float VitezaMaxima,float Consum,int PutereMaxima,int Emisii,float PretVanzare);
    SUPERSPORT(SUPERSPORT&);
    ~SUPERSPORT();

    void citire(istream &in);
    void afisare(ostream &out);
    friend istream& operator>>(istream &in, SUPERSPORT& z);
    friend ostream& operator<<(ostream &out, SUPERSPORT& z);
    SUPERSPORT& operator=(SUPERSPORT &z);

    void AfisareModel(){cout<<"(SS)"<<Model;}
    int GetPretVanzare() const {return PretVanzare;}     ///Functie constanta care returneaza pretul la care a fost vanduta masina
    bool Vanzare();     ///Daca masina este vanduta returneaza true,daca tranzactia esueaza returneaza false

};

SUPERSPORT::SUPERSPORT(string Producator="",string Model="",string Motor="",string Carburant="",string TipCutieViteze="",string Culoare="",float Pret=0,float VitezaMaxima=0,float Consum=0,int PutereMaxima=0,int Emisii=0,float PretVanzare=-1):MasinaSport(Producator,Model,Motor,Carburant,TipCutieViteze,Culoare,Pret,VitezaMaxima,Consum,PutereMaxima,Emisii)
{
    this->PretVanzare=PretVanzare;
}

SUPERSPORT::~SUPERSPORT(){
    PretVanzare=0;
    cout<<"A fost distrus un obiect de tip SUPERSPORT"<<endl;
}

SUPERSPORT::SUPERSPORT(SUPERSPORT &z):MasinaSport(z)
{
   PretVanzare=z.PretVanzare;
}

void SUPERSPORT::citire(istream &in){
    MasinaSport::citire(in);
    cout<<"Introduceti pretul la care a fost vanduta masina(-1 daca nu a fost vanduta):"<<endl;
    cin>>PretVanzare;
}

void SUPERSPORT::afisare(ostream &out){
    cout<<"Supersport"<<endl;
    MasinaSport::afisare(out);
    if(PretVanzare==-1)
        cout<<"Masina nu a fost vanduta"<<endl;
    else
        cout<<"Pret Vanzare: "<<PretVanzare<<" EURO"<<endl;
}

istream& operator>>(istream& in,SUPERSPORT& z){
    z.citire(in);
    return in;
}

ostream& operator<<(ostream& out, SUPERSPORT& z){
    z.afisare(out);
    return out;
}

SUPERSPORT& SUPERSPORT :: operator=(SUPERSPORT &z)
{
    if(this!=&z)
    {
        MasinaSport::operator=(z);
        PretVanzare=z.PretVanzare;
    }
    return *this;
}

bool SUPERSPORT::Vanzare()
{
        float pvanzare;
        cout<<"Pretul masinii incepe de la "<<Pret<<" EURO"<<endl;
        cout<<"Introduceti pretul(in EURO) la care a fost vanduta masina: ";
        cin>>pvanzare;
        if(pvanzare<0)
        {
            cout<<"Nu se poate oferi un pret negativ"<<endl;
            return false;
        }
        if(pvanzare<Pret)
            cout<<"Nu se poate oferi un pret mai mic decat cel stabilit initial"<<endl;
        else
        {
            cout<<"Masina a fost vanduta la pretul de "<<pvanzare<<" EURO"<<endl;
            PretVanzare=pvanzare;
            NrMasiniVandute++;
            return true;
        }

        return false;
}










template <class T>
class Expozitie {
private:
    int NrMasiniExpozitie;           ///Numarul total de masini de la expozitia curenta
    int NrCoupe;                     ///Numarul de masini de tip Coupe de la expozitia curenta
    int NrHotHatch;                  ///Numarul de masini de tip Hot-Hatch de la expozitia curenta
    int NrCabrio;                    ///Numarul de masini de tip Cabrio de la expozitia curenta
    vector<MasinaSport*> MasiniExpuse;
public:
    Expozitie(){NrMasiniExpozitie=0;NrCoupe=0;NrHotHatch=0;NrCabrio=0;}
    void IntroducereMasina(T const&);
    void AfisareExpozitie();
    void AfisareNumereCategorii();
    void NumarMasiniExpozitie(){cout<<"Au fost expuse "<<NrMasiniExpozitie<<" masini Sport:"<<endl;}
};

template <class T>
void Expozitie<T>::IntroducereMasina (T const& masina) {
    MasinaSport *MS=0;
    MS = dynamic_cast<Coupe*>(masina);      ///Incearca cast la Coupe,daca obiectul este de acest tip NrCoupe creste cu 1
    if(MS!=0)
        NrCoupe++;
    MS = dynamic_cast<HotHatch*>(masina);   ///Incearca cast la HotHatch,daca obiectul este de acest tip NrHotHatch creste cu 1
    if(MS!=0)
        NrHotHatch++;
    MS = dynamic_cast<Cabrio*>(masina);     ///Incearca cast la Cabrio,daca obiectul este de acest tip NrCabrio creste cu 1
    if(MS!=0)
        NrCabrio++;

    MasiniExpuse.push_back(masina);
    NrMasiniExpozitie++;
}

template<class T>
void Expozitie<T>::AfisareExpozitie(){
    for(int i=0;i<NrMasiniExpozitie;i++)
    {
        MasiniExpuse[i]->AfisareModel();
        cout<<" ";
    }
}

template<class T>
void Expozitie<T>::AfisareNumereCategorii(){
    cout<<"La aceasta expozitie au fost expuse "<<NrCoupe<<" masini de tip Coupe, "<<NrHotHatch<<" masini Hot-Hatch si "<<NrCabrio<<" masini Cabrio"<<endl;
}




template <>
class Expozitie<SUPERSPORT> {
private:
    int SS_NrMasiniExpozitie;           ///Numarul total de masini supersport de la expozitia curenta
    int SS_NrMasiniVandute;             ///Numarul total de masini supersport vandute la expozitia curenta
    vector<SUPERSPORT*> SS_MasiniExpuse;
    vector<SUPERSPORT*> SS_MasiniVandute;
public:
    Expozitie(){SS_NrMasiniExpozitie=0;SS_NrMasiniVandute=0;}
    void SS_IntroducereMasina(SUPERSPORT *);
    void SS_AfisareExpozitie();
    void SS_AfisareVanzari();
    void SS_Vanzare(int nrvanzare);

    void SS_NumarMasiniExpozitie(){cout<<"Expozitia are "<<SS_NrMasiniExpozitie<<" masini Supersport in stoc:"<<endl;}
    void SS_NumarMasiniVandute(){cout<<"Au fost vandute "<<SS_NrMasiniVandute<<" masini Supersport:"<<endl;}
};

void Expozitie<SUPERSPORT>::SS_IntroducereMasina (SUPERSPORT * masina) {
    if(masina->GetPretVanzare()==-1)
    {
        SS_MasiniExpuse.push_back(masina);
        SS_NrMasiniExpozitie++;
    }
    else
    {
        SS_MasiniVandute.push_back(masina);
        SS_NrMasiniVandute++;
    }

}

void Expozitie<SUPERSPORT>::SS_AfisareExpozitie(){
    for(int i=0;i<SS_NrMasiniExpozitie;i++)
    {
        SS_MasiniExpuse[i]->AfisareModel();
        cout<<" ";
    }
}

void Expozitie<SUPERSPORT>::SS_AfisareVanzari(){
    for(int i=0;i<SS_NrMasiniVandute;i++)
    {
        SS_MasiniVandute[i]->AfisareModel();
        cout<<" ";
    }
}

Expozitie<SUPERSPORT>& operator-=(Expozitie<SUPERSPORT>& z,int nrvanzare){
        z.SS_Vanzare(nrvanzare);
}

void Expozitie<SUPERSPORT>::SS_Vanzare(int nrvanzare){
    if((nrvanzare<=0)||(nrvanzare>SS_NrMasiniExpozitie))
        cout<<"Nu ati introdus un numar valid"<<endl;
    else
    {
        if(SS_MasiniExpuse[nrvanzare-1]->Vanzare()==false)
            cout<<"Masina nu a putut fi vanduta"<<endl;
        else
        {
            SS_MasiniVandute.push_back(SS_MasiniExpuse[nrvanzare-1]);
            for(int i=nrvanzare-1;i<SS_NrMasiniExpozitie-1;i++)     ///Acopera golul din vector creat de vanzarea unei masini
                SS_MasiniExpuse[i]=SS_MasiniExpuse[i+1];

            SS_MasiniExpuse.pop_back();

            SS_NrMasiniExpozitie--;
            SS_NrMasiniVandute++;
        }
    }
}



bool tip(MasinaSport *&m, int &MasinaCurenta,bool (&Exista)[50]) {
    string s;
    bool reusit=false;
    cout<<"\n";
    cout<<"Introduceti tipul pentru Masina "<<MasinaCurenta+1<<": ";
    cin>>s;
    try{
        if(s=="coupe" || s=="Coupe"){
                Exista[MasinaCurenta]=true;
                m=new Coupe;
                cin>>*m;
                reusit=true;
        }
        else
            if(s=="HotHatch" || s=="Hothatch" || s=="hothatch"){
                Exista[MasinaCurenta]=true;
                m=new HotHatch;
                cin>>*m;
                reusit=true;
            }
        else
            if(s=="Cabrio" || s=="cabrio"){
                Exista[MasinaCurenta]=true;
                m=new Cabrio;
                cin>>*m;
                reusit=true;
            }
        else
            if(s=="Supersport" || s=="supersport" || s=="SUPERSPORT" || s=="SuperSport"){
                Exista[MasinaCurenta]=true;
                m=new SUPERSPORT;
                cin>>*m;
                reusit=true;
            }

                else
                    throw 10;
    }
    catch (bad_alloc var){
        cout << "Allocation Failure\n";
        exit(EXIT_FAILURE);
    }
    catch(int j){
        cout<<"Nu ati introdus o clasa valida. Incercati Coupe,HotHatch,Cabrio sau Supersport.\n ";
    }
    return reusit;
}




void menu_output(vector<MasinaSport*> M,int MasinaCurenta,bool *Exista,Expozitie<MasinaSport*>&Expozitie1,Expozitie<SUPERSPORT>&Expozitie2)
{
    cout<<"\n Vasile Andrei-Valentin 211 - Proiect - Targ Masini Sport: \n";
    cout<<"\n\t MENIU:";
    cout<<"\n===========================================\n";
    if(MasinaCurenta>0)
    {
        cout<<"Masini introduse: "<<endl;
        for(int i=1;i<=MasinaCurenta;i++)
        {
            if(Exista[i-1]==true)
            {
                cout<<"("<<i<<")";
                M[i-1]->AfisareModel();
                cout<<" ";
            }
        }
        cout<<endl;
        Expozitie1.NumarMasiniExpozitie();
        Expozitie1.AfisareExpozitie();
        cout<<endl;
        Expozitie2.SS_NumarMasiniExpozitie();
        Expozitie2.SS_AfisareExpozitie();
        cout<<endl;
        Expozitie2.SS_NumarMasiniVandute();
        Expozitie2.SS_AfisareVanzari();
        cout<<endl;


    }
    else
        cout<<"Nu s-a introdus inca nicio masina"<<endl;

    cout<<"\n";
    cout<<"1. Citire informatii masina"; cout<<"\n";
    cout<<"2. Afisare informatii masina"; cout<<"\n";
    cout<<"3. Citire si afisare informatii pentru mai multe masini"; cout<<"\n";
    cout<<"4. Introducere masina random"; cout<<"\n";
    cout<<"5. Adaugare masina la Expozitie"; cout<<"\n";
    cout<<"6. Adaugarea tuturor masinilor la Expozitie"; cout<<"\n";
    cout<<"7. Afisare numar de masini din fiecare categorie sport expusa"; cout<<"\n";
    cout<<"8. Vanzare masina"; cout<<"\n";

    cout<<endl;
    cout<<"0. Iesire."; cout<<"\n";
}
void menu()
{
    int option;///optiunea aleasa din meniu
    option=0;
    int MasinaCurenta=0;
    bool Exista[50] = { false };
    bool reusit;
    vector<MasinaSport*> Masini;
    Expozitie<MasinaSport*> Expozitie1;
    Expozitie<SUPERSPORT> Expozitie2;
    MasinaSport *M;
    SUPERSPORT *SS = 0;
    int r,random;

    do
    {
        menu_output(Masini,MasinaCurenta,Exista,Expozitie1,Expozitie2);

        cout<<"\nIntroduceti numarul actiunii: ";
        scanf("%d", &option);

        if (option==1)                                                          ///1. Citire informatii masina
        {
            reusit=tip(M,MasinaCurenta,Exista); //daca a fost introdus un tip valid,obiectul este introdus in vector si MasinaCurenta creste
            if(reusit==true)
            {
                Masini.push_back(M);
                MasinaCurenta++;
            }


            cout<<endl;
            cout<<"In total au fost introduse ";
            MasinaSport::NumarMasini();
            cout<<" masini"<<endl;
        }


        if (option==2)                                                          ///2.Afisare informatii masina
        {

            cout<<"Au fost introduse ";
            MasinaSport::NumarMasini();
            cout<<" masini"<<endl;

            int nrafisat;
            cout<<"Introduceti numarul matricei care trebuie afisata ";
            cin>>nrafisat;
            if (Exista[nrafisat-1]!=0 && nrafisat>0)
            {
                cout<<endl;
                cout<<"Masina "<<nrafisat<<" este: "<<endl;
                cout<<*Masini[nrafisat-1];
            }

            else
            cout<<"Masina cu numarul "<<nrafisat<<" nu a fost citita";
        }


        if(option==3)                                                           ///3.Citire si afisare informatii pentru mai multe masini
        {
            int numarmasini;
            cout<<"Introduceti numarul de masini pe care vreti sa il introduceti"<<endl;
            cin>>numarmasini;

            if(numarmasini>0)
            {
                int curent=MasinaCurenta;
                for(int i=curent;i<curent+numarmasini;i++)
                {
                    reusit=tip(M,MasinaCurenta,Exista);
                    if(reusit==true)
                    {
                        Masini.push_back(M);
                        MasinaCurenta++;
                    }
                }


                cout<<"Masinile sunt:"<<endl;
                for(int i=curent;i<curent+numarmasini;i++)
                {
                    cout<<"Masina "<<i+1<<":"<<endl;
                    cout<<*Masini[i];
                    cout<<endl;
                }

                cout<<endl;
                cout<<"In total au fost citite ";
                MasinaSport::NumarMasini();
                cout<<" masini"<<endl;
            }
            else
                cout<<"Nu se pot introduce "<<numarmasini<<" masini"<<endl;
        }


        if (option==4)                                                           ///4.Introducere masina random
        {
            string PCoupe[4]={"Subaru","BMW","Mercedes","Jaguar"};
            string PHothatch[4] ={"Honda", "Hyundai", "Renault-Sport","Mazda"};
            string PCabrio[4] = {"Mustang", "Audi-Cabriolet", "Mercedes-Cabriolet", "Chevrolet"};
            string PSupersport[4] = {"Bugatti", "Audi", "Lexus", "Dacia"};
            char Litera1 = 'A' + rand()%26;
            char Litera2 = 'A' + rand()%26;

            string Modele[4] = {"Rapid", "Furios", "Sportback", "Stradale"};
            string ModeleSuperSport[4] = {"Fast&Furious", "Lightning", "Super", "Turbo"};

            string Culori[8] = { "Lava Red", "Gold","Desert Tan", "Anthracite Black", "Ice White", "Shadow Silver", "Lime Green", "Midnight Blue"};
            string Motoare[4] = {"V6", "V8", "V12", "Electric"};
            string Carburanti[2] = {"Benzina", "Motorina"};
            string CutiiViteze[2] = {"Automata", "Manuala"};
            string MaterialeAcoperis[2] = {"Metal", "Textil"};

            string NP,NM,Motor,Carburant,CutieViteze,Culoare;
            float VitezaMaxima,Consum;
            int Pret,PutereMaxima,Emisii;

            string Acoperis;    //doar la Cabrio
            int PretVanzare;    //doar la SUPERSPORT

            srand (time(NULL)+r);
            r++;
            random=rand() % 4;



            Motor=Motoare[(rand()+rand()%7)%4];
            Carburant=Carburanti[rand()%2];
            if(Motor=="Electric")
                Carburant="";
            CutieViteze=CutiiViteze[rand()%2];
            Culoare=Culori[rand()%8];
            Pret=rand() % 50000 + 30000;
            VitezaMaxima=rand() % 250 + 100;
            Consum=rand () % 10 + 5 ;
            PutereMaxima=rand () % 200 + 150 ;
            Emisii=rand() % 100 + 100;


            if(random==0)           //Coupe
            {
                NP=PCoupe[(rand()+rand()%7)%4];
                NM=Modele[(rand()+rand()%7)%4];
                NM=NM+Litera1+Litera2;
                M=new Coupe(NP,NM,Motor,Carburant,CutieViteze,Culoare,Pret,VitezaMaxima,Consum,PutereMaxima,Emisii);
            }

            if(random==1)           //HotHatch
            {
                NP=PHothatch[(rand()+rand()%7)%4];
                NM=Modele[(rand()+rand()%7)%4];
                NM=NM+Litera1+Litera2;
                M=new HotHatch(NP,NM,Motor,Carburant,CutieViteze,Culoare,Pret,VitezaMaxima,Consum,PutereMaxima,Emisii);
            }

            if(random==2)           //Cabrio
            {
                NP=PCabrio[(rand()+rand()%7)%4];
                NM=Modele[(rand()+rand()%7)%4];
                NM=NM+Litera1+Litera2;
                Acoperis=MaterialeAcoperis[rand()%2];
                M=new Cabrio(NP,NM,Motor,Carburant,CutieViteze,Culoare,Pret,VitezaMaxima,Consum,PutereMaxima,Emisii,Acoperis);
            }

            if(random==3)           //SuperSport
            {
                NP=PSupersport[(rand()+rand()%7)%4];
                NM=ModeleSuperSport[(rand()+rand()%7)%4];
                NM=NM+Litera1+Litera2;
                Pret=rand() % 1000000 + 100000;
                PutereMaxima=rand() % 500 + 700;
                Emisii=rand() % 300 + 300;
                PretVanzare=Pret+rand()%500000;
                if(PretVanzare%2==1)
                    PretVanzare=-1;
                M=new SUPERSPORT(NP,NM,Motor,Carburant,CutieViteze,Culoare,Pret,VitezaMaxima,Consum,PutereMaxima,Emisii,PretVanzare);
            }

            Masini.push_back(M);
            Exista[MasinaCurenta]=true;
            MasinaCurenta++;

        }


        if (option==5)                                                          ///5.Adaugare masina la Expozitie
        {
            int nrmasina;
            cout<<"Introduceti numarul masinii pe care vreti sa o adaugati la Expozitie: ";
            cin>>nrmasina;
            if((nrmasina<=0)||(nrmasina>MasinaCurenta))
                cout<<"Nu ati introdus un numar valid";
            else if(Masini[nrmasina-1]->EsteExpusa()==true)
                cout<<"Masina a fost deja expusa"<<endl;
            else
            {
                SS = dynamic_cast<SUPERSPORT*>(Masini[nrmasina-1]);
                if(SS != 0)
                {
                    Expozitie2.SS_IntroducereMasina(SS);
                    Masini[nrmasina-1]->Expunere();
                }
                else
                {
                    Expozitie1.IntroducereMasina(Masini[nrmasina-1]);
                    Masini[nrmasina-1]->Expunere();
                }
            }
        }


        if (option==6)                                                          ///6.Adaugarea tuturor masinilor la Expozitie
        {
            for(int i=0;i<MasinaCurenta;i++)
            {
                if(Masini[i]->EsteExpusa()==false)
                {
                    SS = dynamic_cast<SUPERSPORT*>(Masini[i]);
                    if(SS != 0)
                    {
                        Expozitie2.SS_IntroducereMasina(SS);
                        Masini[i]->Expunere();
                    }
                    else
                    {
                        Expozitie1.IntroducereMasina(Masini[i]);
                        Masini[i]->Expunere();
                    }
                }
            }
        }


        if  (option==7)                                                         ///7. Afisare numar de masini din fiecare categorie sport expusa
        {
            Expozitie1.AfisareNumereCategorii();
        }

        if (option==8)                                                          ///8. Vanzare masina
        {
            int nrvanzare;
            cout<<"Introduceti numarul masinii care urmeaza sa fie vanduta: ";
            cin>>nrvanzare;
            Expozitie2-=nrvanzare;
        }




        if (option==0)
        {
            cout<<endl;
            cout<<"EXIT!"<<endl;

       for(int i=0;i<MasinaCurenta;i++)
                delete Masini[i];

        cout<<"Numar obiecte de tip masina ramase ";
        MasinaSport::NumarMasini();
        cout<<endl;
        }

        if (option<0||option>8)
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
