#include <iostream>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
using namespace std;
float HP2,ATK2,mana,HP;
char komenda;
int zdarzenie;//0-walka 1-nic 2-przedmiot
int d = 20;
int n = 10;
int i = 0;
int PD = 0;
int ATK_Mnoz = 1;
int Heal_Mnoz = 1;
int Agil_Mnoz = 1;
int sila2 = 10;
int agil2 = 60;
int intl2 = 10;
int p =1;
int l =0;
char numer_przed;
class Wrog
{

    public:
    float HP,ATK;
    char slabosc; //a= Atak wrecz, z= Zaklecia, p= Przedmioty,
    char rodzaj;
    int sila = 10;
    int agil = 10;
    int intl = 11;
    string typ;
    Wrog()
    {

    rodzaj = rand()%5 +1;
    if (rodzaj==1)
    {
        typ="pajYk";
    }
    else if(rodzaj==2)
    {
        typ="ork";
    }
    else if(rodzaj==3)
    {
        typ="trol";
    }
    else if(rodzaj==4)
    {
        typ="ogr";
    }
    else if(rodzaj==5)
    {
        typ="szczur";
    }

    HP =10 + sila + rand()%d +n;
    ATK = 2 + sila*0.1 + rand()%d*0.1 +n*0.1;


    }

};
class Przedmiot
{
    public:
    string typ;
    int Heal, ATK, Mnoz_Atk, Mnoz_Heal, Mnoz_agil, Mana, Czas;

    Przedmiot()
    {
    typ="";
    Heal=0;
    ATK=0;
    Mnoz_Atk=0;
    Mnoz_Heal=0;
    Mnoz_agil=0;
    Mana=0;
    Czas=0;
    }
    void uzycie ()
    {
    HP2+=Heal;
    HP=HP-ATK;
    mana+=Mana;
    typ="";
    Heal=0;
    ATK=0;
    Mnoz_Atk=0;
    Mnoz_Heal=0;
    Mnoz_agil=0;
    Mana=0;
    Czas=0;
    }
};
int fail(int WrogATK,int agil2int,int Wrogagil)
    {
        int fail1;
        int i;
        for (i=1;i<WrogATK;i++)
            {
            if (rand()%100<(agil2int-Wrogagil))fail1 = fail1+1;
            if (rand()%100<(Wrogagil-agil2int))fail1 = fail1-1;
            }
        return fail1;
    }

int main()
{
    Przedmiot P1;
    Przedmiot P2;
    Przedmiot P3;
    Przedmiot P4;
    Przedmiot P5;
    P1.typ = "Mikstura burżuj kryształu";
    P1.ATK = 10*(i+1);
    P1.Heal = 10*(i+1);
    P1.Mana = -2;
    srand (time(NULL));
    HP2 = sila2 + 10 + rand()%d +n;
    ATK2 = 2 + sila2*0.1 + rand()%d*0.1+n*0.1;
    do
    {
    zdarzenie=(rand()+rand()/54)%3;
    if(zdarzenie==2)//walka
    {
    i++;
    Wrog stwor;
    HP=stwor.HP;
    cout << HP <<","<<HP2 << endl;
    cout << stwor.ATK<<","<<ATK2 << endl;
    mana=3;
    cout <<" Spotka^e˜ "<<stwor.typ<<" ma "<<HP<<" 3ycia i "<<stwor.ATK<<" ataku "<<endl;
     cout <<" Ty masz "<<HP2<<" 3ycia "<<mana<<" many i "<<ATK2<<" ataku "<<endl;
do
    {
        cout<< "Ilosc many: "<<mana<<endl;
        komenda=getch();
        switch (komenda)
            {
            case 'z':
                {if (mana>0)
                {
                HP = HP-ATK2;
                HP2 = HP2-(stwor.ATK-fail(stwor.ATK,agil2,stwor.agil));
                mana = mana - 1;
                if(HP2<=0) HP2=0;
                else if(HP<0) HP=0;
                else if ((HP2>0)&&(HP>0))cout << HP <<","<<HP2 << endl;
                if ((HP2<=0))cout<<"Przegrana. Poleg^e~  na " <<i<<" potworze."<< endl;
                else if ((HP2>0)&&(HP<=0))
                {
                PD++;
                cout<<"Wygrana. Pokona^e~  "<<i<<" potwora."<<"Dostajesz 1 punkt do~wiadczenia, masz ich teraz "<<PD<<"."<<endl;
                }
                }
                else if (mana<=0)
                {
                cout<<"Brak many"<< endl;
                HP2 =  HP2-(stwor.ATK-fail(stwor.ATK,agil2,stwor.agil));
                if(HP2<=0) HP2=0;
                else if(HP<0) HP=0;
                else if ((HP2>0)&&(HP>0))cout << HP <<","<<HP2 << endl;
                if ((HP2<=0))cout<<"Przegrana. Poleg^e~  na " <<i<<" potworze."<< endl;
                else if ((HP2>0)&&(HP<=0))
                {
                PD++;
                cout<<"Wygrana. Pokona^e~  "<<i<<" potwora."<<"Dostajesz 1 punkt do~wiadczenia, masz ich teraz "<<PD<<"."<<endl;
                }
                }
                }
                break;

            case 'a':
                {
                HP = HP-ATK2;
                HP2 = HP2-(stwor.ATK-fail(stwor.ATK,agil2,stwor.agil));
                if(HP2<=0) HP2=0;
                else if(HP<0) HP=0;
                else if ((HP2>0)&&(HP>0))cout << HP <<","<<HP2 << endl;
                if ((HP2<=0))cout<<"Przegrana. Poleg^e~  na " <<i<<" potworze."<< endl;
                else if ((HP2>0)&&(HP<=0))
                {
                PD++;
                cout<<"Wygrana. Pokona^e~  "<<i<<" potwora."<<"Dostajesz 1 punkt do~wiadczenia, masz ich teraz "<<PD<<"."<<endl;
                }
                }
                break;
            case 'p':
                {
                 cout<<"1. "<<P1.typ<<endl<<"2. "<<P2.typ<<endl<<"3. "<<P3.typ<<endl<<"4. "<<P4.typ<<endl<<"5. "<<P5.typ<<endl;
                 numer_przed=getch();
                 switch(numer_przed)
                 {
                 case'1':
                    {
                        P1.uzycie();
                        cout << HP <<","<<HP2 << endl;
                    }
                    break;
                    case'2':
                    {
                        P2.uzycie();
                        cout << HP <<","<<HP2 << endl;
                    }
                    break;
                    case'3':
                    {
                        P3.uzycie();
                        cout << HP <<","<<HP2 << endl;
                    }
                    break;
                    case'4':
                    {
                        P4.uzycie();
                        cout << HP <<","<<HP2 << endl;
                    }
                    break;
                    case'5':
                    {
                        P5.uzycie();
                        cout << HP <<","<<HP2 << endl;
                    }
                    break;
                 }
                }
                break;
            default:
                {
                cout<<"brak mo3liwosci ataku lub leczenia"<<endl;
                }
        }
    }while((HP>=0)&&(HP2>=0)&&(HP!=0)&&(HP2!=0));

    }
    else if(zdarzenie==1)//Nic
    {
        cout<<"Nic tu nie ma.Id® dalej"<<endl;
    }
    else if(zdarzenie==0)//Przedmiot
    {   p++;
        l=rand()%5+1;
        switch (p)
        {
        case 1:
            {
            switch (l)
            {
        case 1:
            {
           P1.typ ="Mikstura heal";
           P1.Heal= 5*(i+1);
            }
            break;
        case 2:
            {
            P1.typ = "Mała mikstura many";
            P1.Mana = 1;
            }
            break;
        case 3:
            {
            P1.typ = "Mikstura małych obrarzeń";
            P1.ATK = 5*(i+1);
            }
            break;
        case 4:
            {
            P1.typ = "Mikstura burżuj kryształu";
            P1.ATK = 10*(i+1);
            P1.Heal = 10*(i+1);
            P1.Mana = -2;
            }
            break;
            }
            cout<<"Znalaz^e~ przedmiot"<<P1.typ<<endl<<"Heal "<<P1.Heal<<", ATK "<<P1.ATK<<", Mana "<<P1.Mana<<endl;
            }
            break;
            case 2:
            {
            switch (l)
            {
        case 1:
            {
           P2.typ ="Mikstura heal";
           P2.Heal= 5*(i+1);
            }
            break;
        case 2:
            {
            P2.typ = "Mała mikstura many";
            P2.Mana = 1;
            }
            break;
        case 3:
            {
            P2.typ = "Mikstura małych obrarzeń";
            P2.ATK = 5*(i+1);
            }
            break;
        case 4:
            {
            P2.typ = "Mikstura burżuj kryształu";
            P2.ATK = 10*(i+1);
            P2.Heal = 10*(i+1);
            P2.Mana = -2;
            }
            break;
            }
            cout<<"Znalaz^e~ przedmiot"<<P2.typ<<endl<<"Heal "<<P2.Heal<<", ATK "<<P2.ATK<<", Mana "<<P2.Mana<<endl;
            }
            break;
            case 3:
            {
            switch (l)
            {
        case 1:
            {
           P3.typ ="Mikstura heal";
           P3.Heal= 5*(i+1);
            }
            break;
        case 2:
            {
            P3.typ = "Mała mikstura many";
            P3.Mana = 1;
            }
            break;
        case 3:
            {
            P3.typ = "Mikstura małych obrarzeń";
            P3.ATK = 5*(i+1);
            }
            break;
        case 4:
            {
            P3.typ = "Mikstura burżuj kryształu";
            P3.ATK = 10*(i+1);
            P3.Heal = 10*(i+1);
            P3.Mana = -2;
            }
            break;
            }
            cout<<"Znalaz^e~ przedmiot"<<P3.typ<<endl<<"Heal "<<P3.Heal<<", ATK "<<P3.ATK<<", Mana "<<P3.Mana<<endl;
            }
            break;
            case 4:
            {
            switch (l)
            {
        case 1:
            {
           P4.typ ="Mikstura heal";
           P4.Heal= 5*(i+1);
            }
            break;
        case 2:
            {
            P4.typ = "Mała mikstura many";
            P4.Mana = 1;
            }
            break;
        case 3:
            {
            P4.typ = "Mikstura małych obrarzeń";
            P4.ATK = 5*(i+1);
            }
            break;
        case 4:
            {
            P4.typ = "Mikstura burżuj kryształu";
            P4.ATK = 10*(i+1);
            P4.Heal = 10*(i+1);
            P4.Mana = -2;
            }
            break;
            }
            cout<<"Znalaz^e~ przedmiot"<<P4.typ<<endl<<"Heal "<<P4.Heal<<", ATK "<<P4.ATK<<", Mana "<<P4.Mana<<endl;
            }
            break;
            case 5:
            {
            switch (l)
            {
        case 1:
            {
           P5.typ ="Mikstura heal";
           P5.Heal= 5*(i+1);
            }
            break;
        case 2:
            {
            P5.typ = "Mała mikstura many";
            P5.Mana = 1;
            }
            break;
        case 3:
            {
            P5.typ = "Mikstura małych obrarzeń";
            P5.ATK = 5*(i+1);
            }
            break;
        case 4:
            {
            P5.typ = "Mikstura burżuj kryształu";
            P5.ATK = 10*(i+1);
            P5.Heal = 10*(i+1);
            P5.Mana = -2;
            }
            break;
            }
            cout<<"Znalaz^e~ przedmiot"<<P5.typ<<endl<<"Heal "<<P5.Heal<<", ATK "<<P5.ATK<<", Mana "<<P5.Mana<<endl;
            }
            break;
        }
    }
    getchar();
    }while(HP2>0);
   cout<<" Game over"<<endl;


    return 0;
}
;

