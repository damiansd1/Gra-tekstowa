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
int ATK_Mnoz = 1;
int Heal_Mnoz = 1;
int Agil_Mnoz = 1;
int l =1;
int r;
char odp;
int LVL=0;
char numer_przed;
char numer_przed2;
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
int HP;
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
class Przedmiot
{
    public:
    string typ;
    int Heal, ATK, Mnoz_Atk, Mnoz_Heal, Mnoz_agil, Mana, Czas;
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
int wynik(int HPgracz,int HPwrog)
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
    P1.typ ="Mikstura Burżuj kryształu";
        P1.ATK =30*(lvl+1);
        P1.Heal =30*(lvl+1);
        P1.Mana= -10;
    srand (time(NULL));
    HP2 =sila2*10 + rand()%d*5+n*5;
    ATK2 =sila2 + rand()%d+n;
    do
    {
         Wrog stwor;

    zdarzenie=(rand()+rand()/54)%3+;
    if(zdarzenie==0)//walka
    {
    i++;

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
     HP=stwor.HP;
    cout << HP <<","<<HP2 << endl;
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
            case 'z':
                {
                cout<<"1. Mala kula ognia, ATK:"<<intl2*2<<" koszt many 1"<<endl;
                cout<<"2. Tajemne pociski, ATK:"<<"losowo od "<<intl2<< " do "<<intl2*5<<" koszt many 3"<<endl;
                cout<<"3. Mały pocisk mrozu. Zamraza przeciwnika na 1 ture. ATK;"<<intl2*2<<" koszt many 5"<<endl;
                cout<<"4. Smocze zioniecie, ATK:"<<intl2*5<<" koszt many 5"<<endl;
                cout<<"5. Większe tajemne pociski, ATK:"<<"losowo od "<<intl2*2<< " do "<<intl2*10<<" koszt many 10"<<endl;
                cout<<"6. Zamiec. Zamraza przeciwnika na 1 ture. ATK;"<<intl2*5<<" koszt many 10"<<endl;
                cout<<"7. Pyrowybuch, ATK:"<<intl2*10<<" koszt many 18"<<endl;
                cout<<"8. Ognisty deszcz, ATK:"<<"losowo od "<<intl2*4<< " do "<<intl2*20<<" koszt many 20"<<endl;
                cout<<"9. Nowa mrozu. Zamraza przeciwnika na 1 ture. ATK;"<<intl2*10<<" koszt many 20"<<endl;
                rspell=getch();
                if (rspell=='1')
                {
                   if (mana>0)
                    {
                    HP = HP-(intl2*2);
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
                            HP = HP-sATK;
                            HP2 = HP2-stwor.ATK;
                    }
                    if (mana<3)
                        cout<<"brak many"<<endl;

                }
                if (rspell=='3')
                {
                    if (mana>=5)
                    {
                    HP = HP-(intl2*2);
                    mana = mana - 5;
                    }
                    if (mana<5)
                        cout<<"brak many"<<endl;

                }
                if (rspell=='4')
                {
                   if (mana>=5)
                    {
                    HP = HP-(intl2*5);
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
                            HP = HP-sATK;
                            HP2 = HP2-stwor.ATK;
                    }
                    if (mana<3)
                        cout<<"brak many"<<endl;

                }
                if (rspell=='6')
                {
                    if (mana>=10)
                    {
                    HP = HP-(intl2*5);
                    mana = mana - 5;
                    }
                    if (mana<10)
                        cout<<"brak many"<<endl;

                }
                if (rspell=='7')
                {
                   if (mana>=18)
                    {
                    HP = HP-(intl2*10);
                    HP2 = HP2-stwor.ATK;
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
                            HP = HP-sATK;
                            HP2 = HP2-stwor.ATK;
                    }
                    if (mana<15)
                        cout<<"brak many"<<endl;

                }
                if (rspell=='9')
                {
                    if (mana>=15)
                    {
                    HP = HP-(intl2*10);
                    mana = mana - 15;
                    }
                    if (mana<15)
                        cout<<"brak many"<<endl;

                }
                zycie = wynik(HP2, HP);

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
                HP = HP-ATK2;
                HP2 = HP2-stwor.ATK;

                zycie = wynik(HP2, HP);

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

                 cout<<"1. "<<P1.typ<<endl<<"2. "<<P2.typ<<endl<<"3. "<<P3.typ<<endl<<"4. "<<P4.typ<<endl<<"5. "<<P5.typ<<endl;
                 numer_przed=getch();
                 switch(numer_przed)
                 {
                 case'1':
                    {
                        P1.uzycie();
                        zycie = wynik(HP2, HP);
                    }
                    break;
                    case'2':
                    {
                        P2.uzycie();
                        zycie = wynik(HP2, HP);
                    }
                    break;
                    case'3':
                    {
                        P3.uzycie();
                        zycie = wynik(HP2, HP);
                    }
                    break;
                    case'4':
                    {
                        P4.uzycie();
                        zycie = wynik(HP2, HP);
                    }
                    break;
                    case'5':
                    {
                        P5.uzycie();
                        zycie = wynik(HP2, HP);
                    }
                    break;
                 }
                 goto Start;
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
        l++;
        switch(l)
        {
     case 1:
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
        P1.Mana=4*(lvl);
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
        P1.Heal =30*(lvl+1);
        }
        break;
        }
        cout<<"Znalaz^e~ przedmiot: "<<P1.typ<<endl<<" ATK:"<<P1.ATK<<" Heal:"<<P1.Heal<<" Mana:"<<P1.Mana<<endl;
        }
        break;
        case 2:
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
        P2.Mana=4*(lvl);
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
        P2.Heal =30*(lvl+1);
        }
        break;
        }
        cout<<"Znalaz^e~ przedmiot: "<<P2.typ<<endl<<" ATK:"<<P2.ATK<<" Heal:"<<P2.Heal<<" Mana:"<<P2.Mana<<endl;
        }
        break;
        case 3:
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
        P3.Mana=4*(lvl);
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
        P3.Heal =30*(lvl+1);
        }
        break;
        }
        cout<<"Znalaz^e~ przedmiot: "<<P3.typ<<endl<<" ATK:"<<P3.ATK<<" Heal:"<<P3.Heal<<" Mana:"<<P3.Mana<<endl;
        }
        break;
        case 4:
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
        P4.Mana=4*(lvl);
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
        P4.Heal =30*(lvl+1);
        }
        break;
        }
        cout<<"Znalaz^e~ przedmiot: "<<P4.typ<<endl<<" ATK:"<<P4.ATK<<" Heal:"<<P4.Heal<<" Mana:"<<P4.Mana<<endl;
        }
        break;
        case 5:
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
        P5.Mana=4*(lvl);
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
        P5.Heal =30*(lvl+1);
        }
        break;
        }
        cout<<"Znalaz^e~ przedmiot: "<<P5.typ<<endl<<" ATK:"<<P5.ATK<<" Heal:"<<P5.Heal<<" Mana:"<<P5.Mana<<endl;
        }
        break;
        default:
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
        P1.Mana=4*(lvl);
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
        P1.Heal =30*(lvl+1);
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
        P2.Mana=4*(lvl);
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
        P2.Heal =30*(lvl+1);
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
        P3.Mana=4*(lvl);
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
        P3.Heal =30*(lvl+1);
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
        P4.Mana=4*(lvl);
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
        P4.Heal =30*(lvl+1);
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
        P5.Mana=4*(lvl);
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
        P5.Heal =30*(lvl+1);
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
            break;
        }
        }
        }
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

