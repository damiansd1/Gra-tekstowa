#include <iostream>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
using namespace std;
float HP2,ATK2,mana;
char komenda;
int zdarzenie;//0-walka 1-nic 2-przedmiot
int d = 20;
int n = 10;

class Wrog
{
    public:
    float HP,ATK;
    char slabosc; //a= Atak wrêcz, z= Zaklêcia, p= Przedmioty,
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
        typ="pajonk";
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
    srand (time(NULL));

    int sila2 = 10;
    int agil2 = 60;
    int intl2 = 10;
   do
    {
    zdarzenie=(rand()+rand()/54)%2;
    if(zdarzenie==0)//walka
    {
    Wrog stwor;
        HP2 = sila2 + 10 + rand()%d +n;
    ATK2 = 2 + sila2*0.1 + rand()%d*0.1+n*0.1;
    cout << stwor.HP <<","<<HP2 << endl;
    cout << stwor.ATK<<","<<ATK2 << endl;
    mana=3;
    cout <<" Spotkales "<<stwor.typ<<" ma "<<stwor.HP<<" zycia i "<<stwor.ATK<<" ataku "<<endl;
     cout <<" Ty masz "<<HP2<<" zycia "<<mana<<" many i "<<ATK2<<" ataku "<<endl;
do
    {
        cout<< "Ilosc many: "<<mana<<endl;
        komenda=getch();
        switch (komenda)
        {
        case 'z':
        {if (mana>0)
        {
        stwor.HP = stwor.HP-ATK2;
    HP2 = HP2-stwor.ATK;
            mana = mana - 1;
                if(HP2<=0) HP2=0;
        else if(stwor.HP<0) stwor.HP=0;
        else if ((HP2>0)&&(stwor.HP>0))cout << stwor.HP <<","<<HP2 << endl;
        if((HP2<=0)&& (stwor.HP<=0))cout<<"remis" << endl;
        else if ((HP2<=0)&&(stwor.HP>0))cout<<"przegrana" << endl;
        else if ((HP2>0)&&(stwor.HP<=0))cout<<"wygrana" << endl;
        }
        else if (mana<=0)
        {
             cout<<"Brak many"<< endl;
            HP2 = HP2-stwor.ATK;
            if(HP2<=0) HP2=0;
        else if(stwor.HP<0) stwor.HP=0;
        else if ((HP2>0)&&(stwor.HP>0))cout << stwor.HP <<","<<HP2 << endl;
         if((HP2<=0)&& (stwor.HP<=0))cout<<"remis" << endl;
        else if ((HP2<=0)&&(stwor.HP>0))cout<<"przegrana" << endl;
        else if ((HP2>0)&&(stwor.HP<=0))cout<<"wygrana" << endl;
        }
        }
        break;

        case 'a':
        {
        stwor.HP = stwor.HP-ATK2;
        HP2 = HP2-stwor.ATK;
        if(HP2<=0) HP2=0;
        else if(stwor.HP<0) stwor.HP=0;
        else if ((HP2>0)&&(stwor.HP>0))cout << stwor.HP <<","<<HP2 << endl;
        if((HP2<=0)&& (stwor.HP<=0))cout<<"remis" << endl;
        else if ((HP2<=0)&&(stwor.HP>0))cout<<"przegrana" << endl;
        else if ((HP2>0)&&(stwor.HP<=0))cout<<"wygrana" << endl;
        }



        break;
        default:
            {
            cout<<"brak mozliwosci ataku lub leczenia"<<endl;
            }
    }
    }while((stwor.HP>=0)&&(HP2>=0)&&(stwor.HP!=0)&&(HP2!=0));

    }
    else if(zdarzenie==1)//Nic
    {
        cout<<"Nic tu nie ma.Idź dalej"<<endl;
    }
    else if(zdarzenie==2)//Przedmiot
    {
        cout<<"Znalazłeś przedmiot..."<<endl<<"ale nie został jeszcze wprowadzony XD"<<endl;
    }
    getchar();
    }while(HP2>0);
   cout<<" Game over"<<endl;


    return 0;
}
