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
int d = 20;//zmienne do generacji
int n = 10;
int i = 0;
int PD = 0;
int ATK_Mnoz = 1;
int Heal_Mnoz = 1;
int Agil_Mnoz = 1;
int l =1;
int r;
char odp;
int fail2;
int LVL=0;
char numer_przed;
char numer_przed2;
int zycie = 2;
int exp;
int sATK;
int rspell;
int wexp;
int wybor;
int lvl=0;
int sila2 = 3;//statystyki początkowe gracza. xxx2 statystyka gracza
int agil2 = 3;
int intl2 = 3;
int HP;
int Wrogz;
bool zamrozenie=false;
class Wrog
{
    public:
    float HP,ATK;
    char slabosc; //a= Atak wrecz, z= Zaklecia, p= Przedmioty,
    char rodzaj;
    char rspell;
    int sila;
    int agil;
    int intl;
    int lvl;
    int mana;
    bool zamrozenie;
    int niewrazliwosc;//niewrażliwość
    string typ;
    Wrog()
    {

    rodzaj =rand()%6 +1;//generacja rodzaju przeciwnika
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
class Przedmiot
{
    public:
    string typ;
    int Heal, ATK, Mnoz_Atk, Mnoz_Heal, Mnoz_agil, Mana, Czas;//właściwości przedmiotów
    Przedmiot()
    {
     Heal=0;
     ATK=0;
     Mana=0;
     typ="";
    }
    void uzycie ()
    {
    if((mana+Mana)>=0)
    {
     HP2+=Heal;
     HP=HP-ATK;
     mana+=Mana;
     Sleep(10);
     typ="";
     Heal=0;
     ATK=0;
     Mana=0;
    }
     else if ((mana+Mana)<0)
    {
    cout<<"Brak many"<< endl;
    }
    }
};
int fail(float WrogATK,int agil2,int Wrogagil)//funkcja uniku
    {
        int fail1=0;
        int e;
         WrogATK=10;
        cout<<WrogATK<<endl;
        for (int e=1;e<WrogATK;e++)
            {
            if (agil2>Wrogagil)
            {
                if(rand()%100+1<(agil2-Wrogagil))//losowanie sukcesu uniku
                {fail1 = fail1+1;}
            }
            if (Wrogagil>agil2)
            {
                if(rand()%100+1<(Wrogagil-agil2))//losowanie sukcesu ataku krytycznego dla przeciwnika
                {fail1 = fail1-1;}
            }

             }


        return fail1;
}
int wynik(int HPgracz,int HPwrog)//sprawdzanie stanu postaci 1=zwycięstwo 0=śmierć 2=walka
   {

    int zycie;

    if(HPwrog<=0)
        {zycie = 1;}
    else if(HPgracz<=0)
        {zycie = 0;}
    else if ((HPgracz>0)&&(HPwrog>0)){
                cout<<"Mana "<<mana<<" zycie wroga " << HPwrog <<", twoje zycie "<<HPgracz << endl;
                zycie = 2;}

                return zycie;
   }


int main()
{
     Przedmiot P1;
    Przedmiot P2;
    Przedmiot P3;
    Przedmiot P4;
    Przedmiot P5;
    P1.typ ="Mikstura Burżuj kryształu";//ustawianie startowego przedmiotu
    P1.ATK =30*(lvl+1);
    P1.Heal =30*(lvl+1);
    P1.Mana= -10;
    srand (time(NULL));
    HP2 =sila2*10;
    ATK2 =sila2;
    do
    {
         Wrog stwor;

    zdarzenie=(rand()+rand()/54)%3;//generacja zdarzenia
    if((zdarzenie==0)||(zdarzenie==4))//walka
    {
    i++;

    stwor.lvl+=1;
    if (i==1)//ustawianie poziomu przeciwnika
    {
        stwor.lvl=1;
    }
    {//generowanie wroga
    stwor.HP=stwor.lvl*10;
    stwor.ATK=stwor.lvl;
    stwor.agil=stwor.lvl;
    stwor.intl=stwor.lvl;
    if(i==10)//generacja bossa
    {
        stwor.rodzaj = rand()%3 +7;
    if(stwor.rodzaj==7)
    {
        stwor.typ="Wodz Orkow";
    }
     else if(stwor.rodzaj==8)
    {
        stwor.typ="Mistrzowska Zabojczyni";
    }
     else if(stwor.rodzaj==9)
    {
        stwor.typ="Mroczny Mag";
    }
    }

    if (stwor.rodzaj==1)//przydzielanie statystyk poszczególnym przeciwnikom
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
    }
     stwor.mana=stwor.intl;
     mana=intl2;//przydział many dla bohatera
     HP=stwor.HP;//specjalna zmienna dla przedmiotów
    cout << HP <<","<<HP2 << endl;//wyświetlanie ekranu początkowego walki
    cout << stwor.ATK<<","<<ATK2 << endl;
    cout <<" Spotkaˆe~˜ "<<stwor.typ<<" ma "<<HP<<" ¾ycia i "<<stwor.ATK<<" ataku "<<endl;
     cout <<" Ty masz "<<HP2<<" ¾ycia "<<mana<<" many i "<<ATK2<<" ataku "<<endl;
    do
    {

        cout<< "Ilosc many: "<<mana<<endl;
        Start:
        komenda=getch();
        switch (komenda)
            {
            case 'z'://zaklęcia. Lista i poszególne zaklęcia.
                {
                cout<<"1. Mala kula ognia, ATK:"<<intl2*2<<" koszt many 1"<<endl;
                cout<<"2. Tajemne pociski, ATK:"<<"losowo od "<<intl2<< " do "<<intl2*5<<" koszt many 5"<<endl;
                cout<<"3. Mały pocisk mrozu. Zamraza przeciwnika na 1 ture. ATK;"<<intl2*2<<" koszt many 5"<<endl;
                cout<<"4. Smocze zioniecie, ATK:"<<intl2*5<<" koszt many 5"<<endl;
                cout<<"5. Większe tajemne pociski, ATK:"<<"losowo od "<<intl2*2<< " do "<<intl2*10<<" koszt many 10"<<endl;
                cout<<"6. Zamiec. Zamraza przeciwnika na 1 ture. ATK;"<<intl2*5<<" koszt many 10"<<endl;
                cout<<"7. Pyrowybuch, ATK:"<<intl2*10<<" koszt many 15"<<endl;
                cout<<"8. Ognisty deszcz, ATK:"<<"losowo od "<<intl2*4<< " do "<<intl2*20<<" koszt many 20"<<endl;
                cout<<"9. Nowa mrozu. Zamraza przeciwnika na 1 ture. ATK;"<<intl2*10<<" koszt many 20"<<endl;
                rspell=getch();
                if (rspell=='1')
                {
                   if (mana>0)
                    {
                    stwor.HP = stwor.HP-(intl2*2)*stwor.niewrazliwosc;
                    HP2 = HP2-(stwor.ATK-fail(stwor.ATK,agil2,stwor.agil));
                    mana = mana - 1;
                    }
                    else if (mana<=0)
                    {
                    cout<<"Brak many"<< endl;
                    }

                }
                if (rspell=='2')
                {
                    if (mana>=5)
                    {

                            sATK = 0;
                        for(int n=1;n<6;n++)
                        {
                            sATK+=((rand()%intl2)*4/5) ;
                            sATK+=(intl2*1/5);
                            cout<<sATK<<endl;
                        }
                            stwor.HP = stwor.HP-sATK*stwor.niewrazliwosc;
                            HP2 = HP2-(stwor.ATK-fail(stwor.ATK,agil2,stwor.agil));
                            mana = mana-3;
                    }
                    else if (mana<3)
                        cout<<"brak many"<<endl;

                }
                if (rspell=='3')
                {
                    if (mana>=5)
                    {
                    stwor.HP = stwor.HP-(intl2*2)*stwor.niewrazliwosc;
                    mana = mana - 5;
                    zamrozenie = true;
                    }
                    if (mana<5)
                        cout<<"brak many"<<endl;

                }
                if (rspell=='4')
                {
                   if (mana>=5)
                    {
                    stwor.HP = stwor.HP-(intl2*5)*stwor.niewrazliwosc;
                    HP2 = HP2-(stwor.ATK-fail(stwor.ATK,agil2,stwor.agil));
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
                            stwor.HP = stwor.HP-sATK*stwor.niewrazliwosc;
                            HP2 = HP2-(stwor.ATK-fail(stwor.ATK,agil2,stwor.agil));
                    }
                    if (mana<3)
                        cout<<"brak many"<<endl;

                }
                if (rspell=='6')
                {
                    if (mana>=stwor.ATK-fail(stwor.ATK,agil2,stwor.agil))
                    {
                    stwor.HP = stwor.HP-(intl2*5)*stwor.niewrazliwosc;
                    mana = mana - 5;
                    zamrozenie = true;
                    }
                    if (mana<10)
                        cout<<"brak many"<<endl;

                }
                if (rspell=='7')
                {
                   if (mana>=15)
                    {
                    stwor.HP = stwor.HP-(intl2*10)*stwor.niewrazliwosc;
                    HP2 = HP2-(stwor.ATK-fail(stwor.ATK,agil2,stwor.agil));
                    mana = mana - 10;
                    }
                    else if (mana<18)
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
                            stwor.HP = stwor.HP-sATK*stwor.niewrazliwosc;
                            HP2 = HP2-(stwor.ATK-fail(stwor.ATK,agil2,stwor.agil));
                    }
                    if (mana<15)
                        cout<<"brak many"<<endl;

                }
                if (rspell=='9')
                {
                    if (mana>=15)
                    {
                    stwor.HP = stwor.HP-(intl2*10)*stwor.niewrazliwosc;
                    mana = mana - 15;
                    zamrozenie = true;
                    }
                    if (mana<15)
                        cout<<"brak many"<<endl;

                }
                zycie = wynik(HP2, stwor.HP);//skrypt wykonujący akcję w zależności od stanu bohatera 1=wygrana i zwiększenie doświadzenia 2=nic 0=śmierć

                if (zycie ==0)//skrypt śmierci. pojawia się wszędzie na wszelki wypadek i żeby zapobiec powtórzenią skryptu zmieniamy parametr na -1
                    {
                    cout<<" Game over"<<endl; zycie=-1; break;}
                if (zycie==1){//skrypt zwycięstwa
                    cout<<"zwyciestwo"<<endl;
                    wexp = stwor.lvl*100+rand()%stwor.lvl;
                    exp+=wexp;


                }
                if (exp>lvl*100)//zdobywanie poziomów
                    {
                        cout<<"lvl up"<<endl;
                        exp-=lvl*100;
                        lvl+=1;
                        agil2+=1;
                        intl2+=1;
                        sila2+=1;
                        HP2+=10;
                        ATK2+=1;
                        cout<<"Wybierz statystyki 2 razy. 1=sila 2=zrecznosc 3=inteligencja"<<endl;//wybór statystyk dodatkowych
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

            case 'a'://skrypt podstawowego ataku wszystko to samo co wcześniej
                {
                stwor.HP = stwor.HP-ATK2*stwor.niewrazliwosc;
                HP2 = HP2-stwor.ATK-fail(stwor.ATK,agil2,stwor.agil);

                zycie = wynik(HP2, stwor.HP);

                if (zycie ==0)
                    {
                    cout<<" Game over"<<endl; zycie=-1; break;}
                if (zycie==1){
                    cout<<"zwyciestwo"<<endl;
                    wexp = stwor.lvl*100+rand()%stwor.lvl;
                    exp+=wexp;


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
            case 'p'://skrypt urzycia przedmiotów
                {

                 cout<<"1. "<<P1.typ<<endl<<"2. "<<P2.typ<<endl<<"3. "<<P3.typ<<endl<<"4. "<<P4.typ<<endl<<"5. "<<P5.typ<<endl;
                 numer_przed=getch();
                 switch(numer_przed)
                 {
                 case'1'://użycie 1 przedmiotu
                    {
                        HP=stwor.HP;
                        P1.uzycie();
                        zycie = wynik(HP2, HP);
                        stwor.HP=HP;
                if (zycie ==0)
                    {
                    cout<<" Game over"<<endl; zycie=-1; break;}
                if (zycie==1){
                    cout<<"zwyciestwo"<<endl;
                    wexp = stwor.lvl*100+rand()%stwor.lvl;
                    exp+=wexp;
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
                }
                    break;
                    case'2'://użycie 2 przedmiotu
                    {   HP=stwor.HP;
                        P2.uzycie();
                        zycie = wynik(HP2, HP);
                        stwor.HP=HP;
                        if (zycie ==0)
                    {
                    cout<<" Game over"<<endl; zycie=-1; break;}
                if (zycie==1){
                    cout<<"zwyciestwo"<<endl;
                    wexp = stwor.lvl*100+rand()%stwor.lvl;
                    exp+=wexp;


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
                    case'3'://użycie 3 przedmiotu
                    {
                        HP=stwor.HP;
                        P3.uzycie();
                        zycie = wynik(HP2, HP);
                        stwor.HP=HP;
                        if (zycie ==0)
                    {
                    cout<<" Game over"<<endl; zycie=-1; break;}
                if (zycie==1){
                    cout<<"zwyciestwo"<<endl;
                    wexp = stwor.lvl*100+rand()%stwor.lvl;
                    exp+=wexp;


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
                    case'4'://użycie 4 przedmiotu
                    {
                        HP=stwor.HP;
                        P4.uzycie();
                        zycie = wynik(HP2,HP);
                        stwor.HP=HP;
                        if (zycie ==0)
                    {
                    cout<<" Game over"<<endl; zycie=-1; break;}
                if (zycie==1){
                    cout<<"zwyciestwo"<<endl;
                    wexp = stwor.lvl*100+rand()%stwor.lvl;
                    exp+=wexp;


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
                    case'5'://użycie 5 przedmiotu
                    {   HP=stwor.HP;
                        P5.uzycie();
                        zycie = wynik(HP2, stwor.HP);
                        stwor.HP=HP;
                        if (zycie ==0)
                    {
                    cout<<" Game over"<<endl; zycie=-1; break;}
                if (zycie==1){
                    cout<<"zwyciestwo"<<endl;
                    wexp = stwor.lvl*100+rand()%stwor.lvl;
                    exp+=wexp;


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
                 }
                 goto Start;
                }
                 default:
                {
                cout<<"brak mo¾liwosci ataku lub leczenia"<<endl;
                }

                break;

            }
        if (zycie ==0)
        {
            cout<<" Game over"<<endl; zycie=-1; break;
        }
        stwor.niewrazliwosc=1;
        if((stwor.HP>0)&&(zamrozenie!=true))//czary wroga
        {
        switch (stwor.rodzaj)
        {
    case 2:
        {
        Wrogz=rand()%3;
         if((Wrogz==2)&&(stwor.mana>=1))
         {
            cout<<"Wróg urzył 'dodatkowego ataku'"<<endl;
            stwor.mana-=1;
            HP2-=stwor.ATK;
            wynik(HP2,stwor.HP);
         }
        }
        break;
    case 3:
        {
         Wrogz=rand()%4;
         if((Wrogz==2)&&(stwor.mana>=3))
         {
            cout<<"Wróg urzył 'ataku loa'"<<endl;
            stwor.mana-=3;
            HP2-=1*stwor.intl;
            wynik(HP2,stwor.HP);
         }
        if((Wrogz==2)&&(stwor.mana>=3))
         {
            cout<<"Wróg urzył 'leczenia loa'"<<endl;
            stwor.mana-=1;
            stwor.HP+=3*stwor.intl;
            wynik(HP2,stwor.HP);
         }
        }
        break;
    case 8:
        {
          Wrogz=rand()%6;
        if((Wrogz==4)&&(stwor.mana>=5))
         {
            cout<<"Wróg urzył 'Zabójczego uderzenia'"<<endl;
            stwor.mana-=5;
            HP2-=HP2/2;
            wynik(HP2,stwor.HP);
         }
        if((Wrogz==5)&&(stwor.mana>=3))
         {
            cout<<"Wróg urzył 'Ukrycia'"<<endl;
            stwor.mana-=3;
            stwor.niewrazliwosc=0;
            wynik(HP2,stwor.HP);
            cout<<" Wróg jest niewrażliwy"<<endl;
         }
        }
    case 9:
        {
          Wrogz=rand()%6;
        if(((Wrogz==3)||(Wrogz==4)||(Wrogz==5))&&(stwor.mana>=5))
         {
            cout<<"Wróg urzył 'Wyssania życia'"<<endl;
            stwor.mana-=5;
            HP2-=5*stwor.intl;
            stwor.HP+=5*stwor.intl;
            wynik(HP2,stwor.HP);
         }
        }
        }
        }
        if ((stwor.HP<=0)&&(stwor.rodzaj==9))//czary agonalne
        {
         cout<<"Wróg urzył 'Ostatniego słowa'"<<endl;
        HP2=HP2/2;
        wynik(HP2,stwor.HP);
        }
    }while(zycie>1);
    }

    else if((zdarzenie==1)||(zdarzenie==3))//Nic
    {
        cout<<"Nic tu nie ma.Id« dalej"<<endl;
    }
    else if(zdarzenie==2)//Przedmiot
  {
        if(P1.typ=="")//sprawdanie kolejnych wypadków w przypadku znaleziena przedmiotu.
        {
        r=rand()%4;
        switch(r)//losowanie typu przedmiotu.
        {
    case 0://ustawianie cech przedmiotu.
        {
        P1.typ ="Mikstura Burżuj kryształu";
        P1.ATK =30*(lvl+1);
        P1.Heal =30*(lvl+1);
        P1.Mana= -10;
        }
        break;
        case 1://ustawianie cech przedmiotu
        {
        P1.typ ="Mikstura Many";
        P1.Mana=4*(lvl*1);
        }
        break;
        case 2://ustawianie cech przedmiotu
        {
        P1.typ ="Mała mikstura obrażeń";
        P1.ATK = 10*(lvl+1);
        }
        break;
        case 3://ustawianie cech przedmiotu
        {
        P1.typ ="Małą mikstura heal";
        P1.Heal =10*(lvl+1);
        }
        break;
        }
        cout<<"Znalaz^e~ przedmiot: "<<P1.typ<<endl<<" ATK:"<<P1.ATK<<" Heal:"<<P1.Heal<<" Mana:"<<P1.Mana<<endl;//Inforacje na temat znaezionego przedmiotu
        }
         else
        {
        if(P2.typ=="")
        {
         r=rand()%4;
        switch(r)
        {
    case 0:
        {
        P2.typ ="Mikstura Burżuj kryształu";
        P2.ATK =30*(lvl+1);
        P2.Heal =30*(lvl+1);
        P2.Mana= -10;
        }
        break;
    case 1:
        {
        P2.typ ="Mikstura Many";
        P2.Mana=4*(lvl*1);
        }
        break;
        case 2:
        {
        P2.typ ="Mała mikstura obrażeń";
        P2.ATK = 10*(lvl+1);
        }
        break;
        case 3:
        {
        P2.typ ="Małą mikstura heal";
        P2.Heal =10*(lvl+1);
        }
        break;
        }
        cout<<"Znalaz^e~ przedmiot: "<<P2.typ<<endl<<" ATK:"<<P2.ATK<<" Heal:"<<P2.Heal<<" Mana:"<<P2.Mana<<endl;
        }
        else
        {
        if(P3.typ=="")
        {
        r=rand()%4;
        switch(r)
        {
    case 0:
        {
        P3.typ ="Mikstura Burżuj kryształu";
        P3.ATK =30*(lvl+1);
        P3.Heal =30*(lvl+1);
        P3.Mana= -10;
        }
        break;
    case 1:
        {
        P3.typ ="Mikstura Many";
        P3.Mana=4*(lvl*1);
        }
        break;
        case 2:
        {
        P3.typ ="Mała mikstura obrażeń";
        P3.ATK = 10*(lvl+1);
        }
        break;
        case 3:
        {
        P3.typ ="Małą mikstura heal";
        P3.Heal =10*(lvl+1);
        }
        break;
        }
        cout<<"Znalaz^e~ przedmiot: "<<P3.typ<<endl<<" ATK:"<<P3.ATK<<" Heal:"<<P3.Heal<<" Mana:"<<P3.Mana<<endl;
        }
        else
        {
        if(P4.typ=="")
        {
        r=rand()%4;
        switch(r)
        {
    case 0:
        {
        P4.typ ="Mikstura Burżuj kryształu";
        P4.ATK =30*(lvl+1);
        P4.Heal =30*(lvl+1);
        P4.Mana= -10;
        }
        break;
    case 1:
        {
        P4.typ ="Mikstura Many";
        P4.Mana=4*(lvl*1);
        }
        break;
        case 2:
        {
        P4.typ ="Mała mikstura obrażeń";
        P4.ATK = 10*(lvl+1);
        }
        break;
        case 3:
        {
        P4.typ ="Małą mikstura heal";
        P4.Heal =10*(lvl+1);
        }
        break;
        }
        cout<<"Znalaz^e~ przedmiot: "<<P4.typ<<endl<<" ATK:"<<P4.ATK<<" Heal:"<<P4.Heal<<" Mana:"<<P4.Mana<<endl;
        }

        else
        {
        if(P5.typ=="")
        {
        r=rand()%4;
        switch(r)
        {
    case 0:
        {
        P5.typ ="Mikstura Burżuj kryształu";
        P5.ATK =30*(lvl+1);
        P5.Heal =30*(lvl+1);
        P5.Mana= -10;
        }
        break;
    case 1:
        {
        P5.typ ="Mikstura Many";
        P5.Mana=4*(lvl*1);
        }
        break;
        case 2:
        {
        P5.typ ="Mała mikstura obrażeń";
        P5.ATK = 10*(lvl+1);
        }
        break;
        case 3:
        {
        P5.typ ="Małą mikstura heal";
        P5.Heal =10*(lvl+1);
        }
        break;
        }
        cout<<"Znalaz^e~ przedmiot: "<<P5.typ<<endl<<" ATK:"<<P5.ATK<<" Heal:"<<P5.Heal<<" Mana:"<<P5.Mana<<endl;
        }
        else
        {

        cout<<"Znalazłęś przedmiot ale masz ich za dużo."<<endl<<"1. "<<P1.typ<<endl<<"2. "<<P2.typ<<endl<<"3. "<<P3.typ<<endl<<"4. "<<P4.typ<<endl<<"5. "<<P5.typ<<endl<<"Czy chcesz któryś zastąpić T/N"<<endl;
        odp=getch();
        if ((odp=='t')||(odp=='T'))
        {
        cout<<endl<<"Który?"<<endl;
        numer_przed2=getch();
        switch(numer_przed2)
        {
        case '1':
        {
        r=rand()%4;
        switch(r)
        {
    case 0:
        {
        P1.typ ="Mikstura Burżuj kryształu";
        P1.ATK =30*(lvl+1);
        P1.Heal =30*(lvl+1);
        P1.Mana= -10;
        }
        break;
        case 1:
        {
        P1.typ ="Mikstura Many";
        P1.Mana=4*(lvl*1);
        }
        break;
        case 2:
        {
        P1.typ ="Mała mikstura obrażeń";
        P1.ATK = 10*(lvl+1);
        }
        break;
        case 3:
        {
        P1.typ ="Małą mikstura heal";
        P1.Heal =10*(lvl+1);
        }
        break;
        }
        cout<<"Znalaz^e~ przedmiot: "<<P1.typ<<endl<<" ATK:"<<P1.ATK<<" Heal:"<<P1.Heal<<" Mana:"<<P1.Mana<<endl;
        }
        break;
        case '2':
        {
        r=rand()%4;
        switch(r)
        {
    case 0:
        {
        P2.typ ="Mikstura Burżuj kryształu";
        P2.ATK =30*(lvl+1);
        P2.Heal =30*(lvl+1);
        P2.Mana= -10;
        }
        break;
    case 1:
        {
        P2.typ ="Mikstura Many";
        P2.Mana=4*(lvl*1);
        }
        break;
        case 2:
        {
        P2.typ ="Mała mikstura obrażeń";
        P2.ATK = 10*(lvl+1);
        }
        break;
        case 3:
        {
        P2.typ ="Małą mikstura heal";
        P2.Heal =10*(lvl+1);
        }
        break;
        }
        cout<<"Znalaz^e~ przedmiot: "<<P2.typ<<endl<<" ATK:"<<P2.ATK<<" Heal:"<<P2.Heal<<" Mana:"<<P2.Mana<<endl;
        }
        break;
        case '3':
        {
        r=rand()%4;
        switch(r)
        {
    case 0:
        {
        P3.typ ="Mikstura Burżuj kryształu";
        P3.ATK =30*(lvl+1);
        P3.Heal =30*(lvl+1);
        P3.Mana= -10;
        }
        break;
    case 1:
        {
        P3.typ ="Mikstura Many";
        P3.Mana=4*(lvl*1);
        }
        break;
        case 2:
        {
        P3.typ ="Mała mikstura obrażeń";
        P3.ATK = 10*(lvl+1);
        }
        break;
        case 3:
        {
        P3.typ ="Małą mikstura heal";
        P3.Heal =10*(lvl+1);
        }
        break;
        }
        cout<<"Znalaz^e~ przedmiot: "<<P3.typ<<endl<<" ATK:"<<P3.ATK<<" Heal:"<<P3.Heal<<" Mana:"<<P3.Mana<<endl;
        }
        break;
        case '4':
        {
        r=rand()%4;
        switch(r)
        {
    case 0:
        {
        P4.typ ="Mikstura Burżuj kryształu";
        P4.ATK =30*(lvl+1);
        P4.Heal =30*(lvl+1);
        P4.Mana= -10;
        }
        break;
    case 1:
        {
        P4.typ ="Mikstura Many";
        P4.Mana=4*(lvl*1);
        }
        break;
        case 2:
        {
        P4.typ ="Mała mikstura obrażeń";
        P4.ATK = 10*(lvl+1);
        }
        break;
        case 3:
        {
        P4.typ ="Małą mikstura heal";
        P4.Heal =10*(lvl+1);
        }
        break;
        }
        cout<<"Znalaz^e~ przedmiot: "<<P4.typ<<endl<<" ATK:"<<P4.ATK<<" Heal:"<<P4.Heal<<" Mana:"<<P4.Mana<<endl;
        }
        break;
        case '5':
        {
        r=rand()%4;
        switch(r)
        {
    case 0:
        {
        P5.typ ="Mikstura Burżuj kryształu";
        P5.ATK =30*(lvl+1);
        P5.Heal =30*(lvl+1);
        P5.Mana= -10;
        }
        break;
    case 1:
        {
        P5.typ ="Mikstura Many";
        P5.Mana=4*(lvl*1);
        }
        break;
        case 2:
        {
        P5.typ ="Mała mikstura obrażeń";
        P5.ATK = 10*(lvl+1);
        }
        break;
        case 3:
        {
        P5.typ ="Małą mikstura heal";
        P5.Heal =10*(lvl+1);
        }
        break;
        }
        cout<<"Znalaz^e~ przedmiot: "<<P5.typ<<endl<<" ATK:"<<P5.ATK<<" Heal:"<<P5.Heal<<" Mana:"<<P5.Mana<<endl;
        }
        break;
        }
        }
        else if((odp=='n')||(odp=='N'))
        {
        cout<<"Ok kliknij Enter"<<endl;
        }
        }

        }
        }
        }
        }
        }



    if (zycie ==0)
    {
    cout<<" Game over"<<endl; zycie=-1; break;
    }
    getchar();
    }while(zycie>0);
    if (zycie ==0){//koniec mam nadzieje że miło się przeglądało. Damian i Adam
   cout<<" Game over"<<endl;
    }

    return 0;
}
;
