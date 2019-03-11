#include <iostream>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
using namespace std;
float HP2,ATK2,mana;
char komenda;
char zdarzenie;//w-walka n-nic p-przedmiot
int d = 20;
int n = 10;
class Wrog
{
    public:
    float HP,ATK;
    char slabosc; //a= Atak wrêcz, z= Zaklêcia, p= Przedmioty,
    char rodzaj;
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
    int sila = 10;
    int agil = 10;
    int intl = 10;

    HP =10 + sila + rand()%d +n;
    ATK = 2 + sila*0.1 + rand()%d*0.1 +n*0.1;


    }

};
int main()
{
    srand (time(NULL));

    int sila2 = 10;
    int agil2 = 10;
    int intl2 = 10;
    HP2 = sila2 + 10 + rand()%d +n;
    ATK2 = 2 + sila2*0.1 + rand()%d*0.1
     +n*0.1;
    Wrog stwor;
    mana=3;
    cout <<" Spotkales "<<stwor.typ<<" ma "<<stwor.HP<<" zycia i "<<stwor.ATK<<" ataku "<<endl;
    cout <<" Ty masz "<<HP2<<" zycia "<<mana<<" many i "<<ATK2<<" ataku "<<endl
do
    {
        cout<< "Ilosc many: "<<mana<<endl;
        komenda=getch();
        switch (komenda)
        {
        case 'z':
        {if (mana>0)
        {
        stwor.HP = stwor.HP-ATK2*2;
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

    // }
   // cout<<" Game over"<<endl;


    return 0;
}
