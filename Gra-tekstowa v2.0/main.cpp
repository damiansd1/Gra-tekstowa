#include <iostream>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
using namespace std;
float HP2,ATK2,mana;
char komenda,rspell;
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
    int sila = 10;
    int agil = 10;
    int intl = 11;
    int lvlW = rand()%5 +1;
    string typ;
    Wrog()
    {

    rodzaj = rand()%5 +1;
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
    int sATK;
    int sila2 = 3;
    int agil2 = 3;
    int intl2 = 10;
    mana = intl2;
    HP2 = sila2*5 + rand()%d +n;
    ATK2 = 2 + sila2 + rand()%d*0.1+n*0.1;
    do
    {
    zdarzenie=(rand()+rand()/54)%3;
    if(zdarzenie==0)//walka
    {
    i++;
    Wrog stwor;

    cout << stwor.HP <<","<<HP2 << endl;
    cout << stwor.ATK<<","<<ATK2 << endl;
    mana = intl2;

    cout <<" Spotkaˆe~˜ "<<stwor.typ<<" ma "<<stwor.HP<<" ¾ycia i "<<stwor.ATK<<" ataku "<<endl;
     cout <<" Ty masz "<<HP2<<" ¾ycia "<<mana<<" many i "<<ATK2<<" ataku "<<endl;
do
    {
        cout<< "Ilosc many: "<<mana<<endl;
        komenda=getch();
        switch (komenda)
            {
            case 'z':
                {
                cout<<"1. Mala kula ognia, ATK:"<<intl2*2<<" koszt many 1"<<endl;
                cout<<"2. Tajemne pociski, ATK:"<<"losowo od "<<intl2<< " do "<<intl2*5<<" koszt many 3"<<endl;
                cout<<"3. Mały pocisk mrozu. Zamraza przeciwnika na 1 ture. ATK;"<<intl2*2<<" koszt many 5"<<endl;
                cout<<"4. Kula ognia, ATK:"<<intl2*5<<" koszt many 5"<<endl;
                cout<<"5. Większe tajemne pociski, ATK:"<<"losowo od "<<intl2*2<< " do "<<intl2*10<<" koszt many 10"<<endl;
                cout<<"6. Pocisk mrozu. Zamraza przeciwnika na 1 ture. ATK;"<<intl2*5<<" koszt many 15"<<endl;
                cout<<"7. Pyrowybuch, ATK:"<<intl2*2<<" koszt many 1"<<endl;
                cout<<"8. Ognisty deszcz, ATK:"<<"losowo od "<<intl2<< " do "<<intl2*5<<" koszt many 3"<<endl;
                cout<<"9. Nowa mrozu. Zamraza przeciwnika na 1 ture. ATK;"<<intl2*2<<" koszt many 5"<<endl;
                rspell=getch();
                if (rspell=='1')
                {
                   if (mana>0)
                    {
                    stwor.HP = stwor.HP-(intl2*2);
                    HP2 = HP2-stwor.ATK;
                    mana = mana - 1;
                    if(HP2<=0) HP2=0;
                    else if(stwor.HP<0) stwor.HP=0;
                    else if ((HP2>0)&&(stwor.HP>0))cout << stwor.HP <<","<<HP2 << endl;
                    if ((HP2<=0))cout<<"Przegrana. Poleg^e˜  na " <<i<<" potworze."<< endl;
                    else if ((HP2>0)&&(stwor.HP<=0))
                    {
                    PD=PD+stwor.lvlW;
                    cout<<"Wygrana. Pokonaˆe˜  "<<i<<" potwora."<<"Dostajesz "<<stwor.lvlW<<"  punkt do~wiadczenia, masz ich teraz "<<PD<<"."<<endl;
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
                    PD=PD+stwor.lvlW;
                    cout<<"Wygrana. Pokonaˆe˜  "<<i<<" potwora."<<"Dostajesz 1 punkt do~wiadczenia, masz ich teraz "<<PD<<"."<<endl;
                    }
                    }
                }
                }
                if (rspell=='2')
                {
                    if (mana>=3)
                    {
                            mana = mana-3;
                            sATK = 0;
                        for(int n=1;n<6;n++)
                        {
                            cout<< n <<endl;
                            sATK+=((rand()%intl2)*4/5) ;
                            sATK+=(intl2*1/5);
                        }
                    cout << sATK <<endl;
                    }
                    if (mana<3)
                        cout<<"brak many"<<endl;

                }
                if (rspell=='3')
                {
                    if (mana>=5)
                    {
                    stwor.HP = stwor.HP-(intl2*2);
                    mana = mana - 5;
                    }
                    if (mana<5)
                        cout<<"brak many"<<endl;

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
                if ((HP2<=0))cout<<"Przegrana. Polegˆe˜  na " <<i<<" potworze."<< endl;
                else if ((HP2>0)&&(stwor.HP<=0))
                {
                PD=PD+stwor.lvlW;
                cout<<"Wygrana. Pokonaˆe˜  "<<i<<" potwora."<<"Dostajesz 1 punkt do~wiadczenia, masz ich teraz "<<PD<<"."<<endl;
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
    }while((stwor.HP>=0)&&(HP2>=0)&&(stwor.HP!=0)&&(HP2!=0));

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
    }while(HP2>0);
   cout<<" Game over"<<endl;


    return 0;
}
;

