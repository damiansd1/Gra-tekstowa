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
    char rspell;
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
    int sATK;
    int rspell;
    int wexp;
    int wybor;
    int lvl=1;
    int sila2 = 5;
    int agil2 = 60;
    int intl2 = 10;
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
        stwor.lvl=10;
    }
    cout<<stwor.lvl<<endl;
    stwor.HP=stwor.lvl*10;
    stwor.ATK=stwor.lvl;
    stwor.agil=stwor.lvl;
    stwor.intl=stwor.lvl;
    if(i==10)
    {
        stwor.rodzaj = rand()%3 +7;
        else if(rodzaj==7)
    {
        typ="Wodz Orkow";
    }
     else if(rodzaj==8)
    {
        typ="Mistrzowska Zabojczyni";
    }
     else if(rodzaj==9)
    {
        typ="Mroczny Mag";
    }
    }

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
    }if (stwor.rodzaj==7)
    {
        stwor.HP=stwor.HP*10;
        stwor.ATK=stwor.ATK*5;
        stwor.agil=stwor.agil*1;
        stwor.intl=stwor.intl*0;
    }
    if (stwor.rodzaj==8)
    {
        stwor.HP=stwor.HP*5;
        stwor.ATK=stwor.ATK*7;
        stwor.agil=stwor.agil*10;
        stwor.intl=stwor.intl*5;
    }
    if (stwor.rodzaj==9)
    {
        stwor.HP=stwor.HP*5;
        stwor.ATK=stwor.ATK*5;
        stwor.agil=stwor.agil*3;
        stwor.intl=stwor.intl*10;
    }
     mana=intl2;
    cout << stwor.HP <<","<<HP2 << endl;
    cout << stwor.ATK<<","<<ATK2 << endl;
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
                cout<<"4. Smocze zioniecie, ATK:"<<intl2*5<<" koszt many 5"<<endl;
                cout<<"5. Większe tajemne pociski, ATK:"<<"losowo od "<<intl2*2<< " do "<<intl2*10<<" koszt many 10"<<endl;
                cout<<"6. Zamiec. Zamraza przeciwnika na 1 ture. ATK;"<<intl2*5<<" koszt many 10"<<endl;
                cout<<"7. Pyrowybuch, ATK:"<<intl2*10<<" koszt many 10"<<endl;
                cout<<"8. Ognisty deszcz, ATK:"<<"losowo od "<<intl2*4<< " do "<<intl2*20<<" koszt many 20"<<endl;
                cout<<"9. Nowa mrozu. Zamraza przeciwnika na 1 ture. ATK;"<<intl2*10<<" koszt many 20"<<endl;
                rspell=getch();
                if (rspell=='1')
                {
                   if (mana>0)
                    {
                    stwor.HP = stwor.HP-(intl2*2);
                    HP2 = HP2-stwor.ATK;
                    mana = mana - 1;
                    }
                    else if (mana<=0)
                    {
                    cout<<"Brak many"<< endl;
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
                            stwor.HP = stwor.HP-sATK;
                            HP2 = HP2-stwor.ATK;
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
                if (rspell=='4')
                {
                   if (mana>=5)
                    {
                    stwor.HP = stwor.HP-(intl2*5);
                    HP2 = HP2-stwor.ATK;
                    mana = mana - 5;
                    }
                    else if (mana<5)
                    {
                    cout<<"Brak many"<< endl;
                    }

                }
                if (rspell=='5')
                {
                    if (mana>=10)
                    {
                            mana = mana-10;
                            sATK = 0;
                        for(int n=1;n<11;n++)
                        {
                            cout<< n <<endl;
                            sATK+=((rand()%intl2)*4/5) ;
                            sATK+=(intl2*1/5);
                        }
                            stwor.HP = stwor.HP-sATK;
                            HP2 = HP2-stwor.ATK;
                    }
                    if (mana<3)
                        cout<<"brak many"<<endl;

                }
                if (rspell=='6')
                {
                    if (mana>=10)
                    {
                    stwor.HP = stwor.HP-(intl2*5);
                    mana = mana - 5;
                    }
                    if (mana<10)
                        cout<<"brak many"<<endl;

                }
                if (rspell=='7')
                {
                   if (mana>=10)
                    {
                    stwor.HP = stwor.HP-(intl2*10);
                    HP2 = HP2-stwor.ATK;
                    mana = mana - 10;
                    }
                    else if (mana<10)
                    {
                    cout<<"Brak many"<< endl;
                    }

                }
                if (rspell=='8')
                {
                    if (mana>=15)
                    {
                            mana = mana-10;
                            sATK = 0;
                        for(int n=1;n<21;n++)
                        {
                            cout<< n <<endl;
                            sATK+=((rand()%intl2)*4/5) ;
                            sATK+=(intl2*1/5);
                        }
                            stwor.HP = stwor.HP-sATK;
                            HP2 = HP2-stwor.ATK;
                    }
                    if (mana<15)
                        cout<<"brak many"<<endl;

                }
                if (rspell=='9')
                {
                    if (mana>=15)
                    {
                    stwor.HP = stwor.HP-(intl2*10);
                    mana = mana - 15;
                    }
                    if (mana<15)
                        cout<<"brak many"<<endl;

                }
                zycie = wynik(HP2, stwor.HP);

                if (zycie ==0)
                    {
                    cout<<" Game over"<<endl; zycie=-1; break;}
                if (zycie==1){
                    cout<<"zwyciestwo"<<endl;
                    wexp = stwor.lvl*100+rand()%stwor.lvl;
                    exp+=wexp;

                     cout<<stwor.lvl<<endl;
                }
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





                break;
                }

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

