#include <iostream>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
using namespace std;
float HP2,ATK2,mana;
char komenda;
int zdarzenie;//0-walka 1-nic 2-przedmiot
int d = 20;
int n = 10;
int i = 0;
int PD = 0;
class Wrog
{
    public:
    float HP,ATK;
    char slabosc; //a= Atak wrecz, z= Zaklecia, p= Przedmioty,
    char rodzaj;
    int sila = 1;
    int agil = 1;
    int intl = 1;
    int lvl;
    string typ;
    Wrog()
    {

    rodzaj = rand()%6 +1;
    if (rodzaj==1)
    {
        typ="paj¥k";
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
    else if(rodzaj==6)
    {
        typ="kultysta";
    }


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
int wynik(int HPgracz,int HPwrog)
   {

    int zycie;

    if(HPwrog<=0)
        {zycie = 1;}
    else if(HPgracz<=0)
        {zycie = 0;}
    else if ((HPgracz>0)&&(HPwrog>0)){
                cout<< "zycie wroga " << HPwrog <<", twoje zycie "<<HPgracz << endl;
                zycie = 2;}

                return zycie;
   }

int main()
{
    srand (time(NULL));
    int zycie = 2;
    int exp;
    int wexp;
    int wybor;
    int lvl=1;
    int sila2 = 5;
    int agil2 = 60;
    int intl2 = 5;
    HP2 =sila2*10 + rand()%d*5+n*5;
    ATK2 =sila2 + rand()%d+n;
    do
    {
    zdarzenie=(rand()+rand()/54)%3;
    if(zdarzenie==0)//walka
    {
    i++;
    Wrog stwor;

    stwor.lvl+=1;
    if (i==1)
    {
        stwor.lvl=1;
    }
    cout<<stwor.lvl<<endl;
    stwor.HP=stwor.lvl*10;
    stwor.ATK=stwor.lvl;
    stwor.agil=stwor.lvl;
    stwor.intl=stwor.lvl;
    if (stwor.rodzaj==1)
    {
        stwor.HP=stwor.HP*0.5;
        stwor.ATK=stwor.ATK*1.25;
        stwor.agil=stwor.agil*2;
        stwor.intl=stwor.intl*0;
    }
    if (stwor.rodzaj==2)
    {
        stwor.HP=stwor.HP*1.5;
        stwor.ATK=stwor.ATK*1.5;
        stwor.agil=stwor.agil*0.5;
        stwor.intl=stwor.intl*0.5;
    }
    if (stwor.rodzaj==3)
    {
        stwor.HP=stwor.HP*0.75;
        stwor.ATK=stwor.ATK*1;
        stwor.agil=stwor.agil*1.25;
        stwor.intl=stwor.intl*1;
    }
    if (stwor.rodzaj==4)
    {
        stwor.HP=stwor.HP*2;
        stwor.ATK=stwor.ATK*2;
        stwor.agil=stwor.agil*0;
        stwor.intl=stwor.intl*0;
    }
    if (stwor.rodzaj==5)
    {
        stwor.HP=stwor.HP*0.5;
        stwor.ATK=stwor.ATK*0.75;
        stwor.agil=stwor.agil*2;
        stwor.intl=stwor.intl*0;
    }
    if (stwor.rodzaj==6)
    {
        stwor.HP=stwor.HP*1;
        stwor.ATK=stwor.ATK*0.75;
        stwor.agil=stwor.agil*0.75;
        stwor.intl=stwor.intl*2;
    }
    cout << stwor.HP <<","<<HP2 << endl;
    cout << stwor.ATK<<","<<ATK2 << endl;
    mana=3;
    cout <<" Spotkaˆe~˜ "<<stwor.typ<<" ma "<<stwor.HP<<" ¾ycia i "<<stwor.ATK<<" ataku "<<endl;
     cout <<" Ty masz "<<HP2<<" ¾ycia "<<mana<<" many i "<<ATK2<<" ataku "<<endl;
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
                zycie = wynik(HP2,stwor.HP);
                if (zycie ==0)
                    {
                    cout<<" Game over"<<endl; zycie=-1; break;}
                if (zycie==1){

                    cout<<"win"<<endl;
                    wexp = stwor.lvl*10+stwor.lvl/100*rand()%100;
                    exp+=wexp;
                if (exp>lvl*100)
                    {

                        exp-=lvl*100;
                        lvl+=1;
                        agil2+=1;
                        intl2+=1;
                        sila2+=1;
                        HP2+=10;
                        ATK2+=1;
                        cout<<"Wybierz statystyki 2 razy. 1=sila 2=zrecznosc 3=inteligencja"<<endl;
                        cin>>wybor;
                        if (wybor=1)
                        {
                            sila2++;
                            HP2+=10;
                            ATK2+=1;
                        }
                        if (wybor=2)
                        {
                            agil2++;
                        }
                        if (wybor=1)
                        {
                            intl2++;
                        }
                        wybor = 0;
                        cin>>wybor;
                        if (wybor=1)
                        {
                            sila2++;
                        }
                        if (wybor=2)
                        {
                            agil2++;
                        }
                        if (wybor=1)
                        {
                            intl2++;
                        }
                        wybor = 0;
                    }
                }
                }
                else if (mana<=0)
                {
                cout<<"Brak many"<< endl;
                HP2 = HP2-stwor.ATK;
                if(HP2<=0) HP2=0;
                else if(stwor.HP<0) stwor.HP=0;
                else if ((HP2>0)&&(stwor.HP>0))cout << stwor.HP <<","<<HP2 << endl;
                if ((HP2<=0))cout<<"Przegrana. Polegˆe˜  na " <<i<<" potworze."<< endl;
                else if ((HP2>0)&&(stwor.HP<=0))
                {
                PD++;
                cout<<"Wygrana. Pokonaˆe˜  "<<i<<" potwora."<<"Dostajesz 1 punkt do~wiadczenia, masz ich teraz "<<PD<<"."<<endl;
                }
                }
                }
                break;

            case 'a':
                {
                stwor.HP = stwor.HP-ATK2;
                HP2 = HP2-stwor.ATK;

                zycie = wynik(HP2, stwor.HP);

                if (zycie ==0)
                    {
                    cout<<" Game over"<<endl; zycie=-1; break;}
                if (zycie==1){
                    cout<<"zwyciestwo"<<endl;
                    wexp = stwor.lvl*100+rand()%stwor.lvl;
                    exp+=wexp;

                     cout<<stwor.lvl<<endl;
                if (exp>lvl*100)
                    {
                        cout<<"lvl up"<<endl;
                        exp-=lvl*100;
                        lvl+=1;
                        agil2+=1;
                        intl2+=1;
                        sila2+=1;
                        HP2+=10;
                        ATK2+=1;
                        cout<<"Wybierz statystyki 2 razy. 1=sila 2=zrecznosc 3=inteligencja"<<endl;
                        cin>>wybor;
                        if (wybor=1)
                        {
                            sila2++;
                            HP2+=10;
                            ATK2+=1;

                        }
                        if (wybor=2)
                        {
                            agil2++;
                        }
                        if (wybor=1)
                        {
                            intl2++;
                        }
                        wybor = 0;
                        cin>>wybor;
                        if (wybor=1)
                        {
                            sila2++;
                        }
                        if (wybor=2)
                        {
                            agil2++;
                        }
                        if (wybor=1)
                        {
                            intl2++;
                        }
                        wybor = 0;
                    }

                }
                }
                break;
            case 'p':
                {

                }
                break;
            default:
                {
                cout<<"brak mo¾liwosci ataku lub leczenia"<<endl;
                }
        }
        if (zycie ==0)
        {
            cout<<" Game over"<<endl; zycie=-1; break;
        }
    }while(zycie>1);

    }
    else if(zdarzenie==1)//Nic
    {
        cout<<"Nic tu nie ma.Id« dalej"<<endl;
    }
    else if(zdarzenie==2)//Przedmiot
    {
        cout<<"Znalazˆe˜ przedmiot..."<<endl<<"ale nie zostaˆ jeszcze wprowadzony XD"<<endl;
    }
    getchar();
    if (zycie ==0)
    {
    cout<<" Game over"<<endl; zycie=-1; break;
    }
    }while(zycie>0);
    if (zycie ==0){
   cout<<" Game over"<<endl;
    }

    return 0;
}
;

