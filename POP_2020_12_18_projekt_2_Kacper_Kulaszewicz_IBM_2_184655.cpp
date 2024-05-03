//Code Blocks 17.12
#include <iostream>
#include <cstdlib>

using namespace std;

string plansza(string **t, int w, int k) //funkcja generujaca plansze poczatkowa
{
    char str[1];
    for(int i=0; i<w; i++)
    {
        for(int j=0; j<k; j++)
        {
            t[i][j]="-";                 //wpisujemy do tablicy pola ktore beda zmieniane na X i 0
            if (i==0 && j==0)
            {
               t[i][j]=" ";              //wpisujemy do tablicy pole o kordach 0,0
            }
            if (i==0 && j!=0)
            {
                t[i][j]=char(64+j);      //wpisujemy do tablicy numeracje kolumn 0d A do T
            }
            if(i!=0 && j==0)
            {
                itoa(i,str,10);          //wpisujemy do tablicy numeracje wierszy od 1 do 9
                t[i][j]=str;
            }
        }
    }
    return **t;                           //zwracamy nasza tablice pozatkowa
}


void wyswietl(string **t, int w, int k)  //w tej funkcji wypisujemy cala nasza tablice
{
    cout<<endl;
    for(int i=0; i<w; i++)
    {
        for(int j=0; j<k; j++)
        {
            cout<<t[i][j];
        }
        cout<<endl;
    }

}

void krzyzyk(string **t, int w, int k) //ta funkcja odpowiada za zamienianie - na X z uwzglednieniem wszelkich zlych wpisan przez uzytkownika
{
    string kord;                        //definiujemy kordy
    cout<<endl;
    cout<<"Kolej Gracza X:"<<endl;
    cout<<"podaj nr pola wedlug wzoru:"<<endl;
    cout<<"1B gdzie: 1-wiersz, B-kolumna"<<endl;
    cin>> kord;                          //wczytujemy kordy
    int len=kord.length();                //sprawdzamy długość kordow podanych przez gracza x
    char wier=kord[0];                    //rozdzielamy je na wiersz
    char kol=kord[1];                      //i kolumne
    int wiersz=int(wier-'0');               //tutaj zamieniamy wiersz na inta
    int kolumna=int(kol-64);                //a tutaj kolumne
    if(len==2 && wiersz>0 && wiersz<w && kolumna>0 && kolumna<k && t[wiersz][kolumna]!="X" && t[wiersz][kolumna]!="0")
    {                                              //w linijce powyzej wpisujemy warunki aby uzytkownik byl zmuszony podac poprawne kordy
        for(int i=0; i<w; i++)
        {
            for(int j=0; j<k; j++)
            {
                t[wiersz][kolumna]="X";            //zamieniamy znak - na X w podanym przez uzytkownika miejsu
            }
        }
    }
    else                                           //jezeli uzytkownik poda zle korsy prosimy go o ponowne wprowadzenie
    {
        system("cls");                              //czyscimy  ekran aby byla schludniej wygladal nasz program
        wyswietl(t,w,k);
        cout<<endl;
        cout<<"dane niepoprawne, jeszcze raz:"<<endl;
        krzyzyk(t,w,k);
    }
}


void kolko(string **t, int w, int k)                 //funkcja analogiczna do tej powyzej tylko z 0 zamiast X
{
    string kord;
    cout<<endl;
    cout<<"Kolej Gracza 0:"<<endl;
    cout<<"podaj nr pola wedlug wzoru:"<<endl;
    cout<<"1B gdzie: 1-wiersz, B-kolumna"<<endl;
    cin>> kord;
    int len=kord.length();
    char wier=kord[0];
    char kol=kord[1];
    int wiersz=int(wier-'0');
    int kolumna=int(kol-64);
    if(len==2 && wiersz>0 && wiersz<w && kolumna>0 && kolumna<k && t[wiersz][kolumna]!="X" && t[wiersz][kolumna]!="0")
    {
        for(int i=0; i<w; i++)
        {
            for(int j=0; j<k; j++)
            {
                t[wiersz][kolumna]="0";
            }
        }
    }
    else
    {
        system("cls");
        wyswietl(t,w,k);
        cout<<endl;
        cout<<"dane niepoprawne, jeszcze raz:"<<endl;
        kolko(t,w,k);
    }
}

/*void dol(string **t, int w, int k, int wspol, int t2)   //tu zacznia sie moja nieudolna proba stowrzenia warunku zwyciestwa
{
    for(int i=1; i<w; i++)
        {
            for(int j=1; j<k; j++)
            {
                int wspol;
                if(t[i][j]==t[i+1][j] && i<w && i>0)
                {
                    i>>t2;
                    j>>t2;
                }
                while(t[i][j]==t[i+1][j] && i<w && i>0)
                {
                    wspol=i+1;
                    wspol>>t2;
                    j>>t2;
                }
            }
        }
}

void prawo(string **t, int w, int k, int wspol, int t2)
{
    for(int i=1; i<w; i++)
        {
            for(int j=1; j<k; j++)
            {
                int wspol;
                if(t[i][j]==t[i][j+1] && j<k && j>0)
                {
                    i>>t2;
                    j>>t2;
                }
                while(t[i][j]==t[i][j+1] && j<k && j>0)
                {
                    wspol=j+1;
                    wspol>>t2;
                    j>>t2;
                }

            }
        }
}

void lewo(string **t, int w, int k, int wspol)
{
    for(int i=1; i<w; i++)
        {
            for(int j=1; j<k; j++)
            {
                int wspol;
                while(t[i][j]==t[i][j-1] && j<k && j>0)
                {
                    wspol=j-1;
                }

            }
        }
}

void gora(string **t, int w, int k, int wspol)
{
    for(int i=1; i<w; i++)
        {
            for(int j=1; j<k; j++)
            {
                int wspol;
                while(t[i][j]==t[i-1][j] && i<w && i>0)
                {
                    wspol=i-1;
                }
            }
        }
}

void prawagora(string **t, int w, int k, int wspol, int wspol2)
{
    for(int i=1; i<w; i++)
        {
            for(int j=1; j<k; j++)
            {
                int wspol;
                while(t[i][j]==t[i+1][j+1] && i<w && i>0 && j<k && j>0)
                {
                    wspol=i+1;
                    wspol2=j+1;
                }
            }
        }
}

void prawydol(string **t, int w, int k, int wspol, int wspol2)
{
    for(int i=1; i<w; i++)
        {
            for(int j=1; j<k; j++)
            {
                int wspol;
                while(t[i][j]==t[i-1][j+1] && i<w && i>0 && j<k && j>0)
                {
                    wspol=i-1;
                    wspol2=j+1;
                }
            }
        }
}

void lewagora(string **t, int w, int k, int wspol, int wspol2)
{
    for(int i=1; i<w; i++)
        {
            for(int j=1; j<k; j++)
            {
                int wspol;
                while(t[i][j]==t[i+1][j-1] && i<w && i>0 && j<k && j>0)
                {
                    wspol=i+1;
                    wspol2=j-1;
                }
            }
        }
}

void lewydol(string **t, int w, int k, int wspol, int wspol2)
{
    for(int i=1; i<w; i++)
        {
            for(int j=1; j<k; j++)
            {
                int wspol;
                while(t[i][j]==t[i-1][j-1] && i<w && i>0 && j<k && j>0)
                {
                    wspol=i-1;
                    wspol2=j-1;
                }
            }
        }
}



bool wygrana(string **t, int w, int k)
{
    int z=100;
    int tablicka[z];
    for(int i=1; i<w; i++)
        {
            for(int j=1; j<k; j++)
            {
                if((t[i][j])!="-")
                {
                    i>>tablicka;
                    j>>tablicka;
                    while()
                    {
                        if(t[i][j]==t[i+1][j])
                    }
                }
            }
        }
}

bool wygranaa(string **t, int w, int k)
{
    const int z=100;
    int odwiedzane[z];
    for(int i=1; i<w; i++)
        {
            for(int j=1; j<k; j++)
            {
                int wspolw=i;
                int wspolk=j;
                if (t[i][j]!="-")
                {

                }
            }
        }
}
*/                                          //a w tym miejscu sie konczy

bool koncowka(string **t, int w, int k)     //ta fukcja dba o to ze gra sie konczy w momencie gdy nie ma gdzie postawic X i 0
{
    bool koniec=false;
    for(int i=1; i<w; i++)
        {
            for(int j=1; j<k; j++)
            {
                if(t[i][j]=="-")
                {
                    koniec=true;
                }
            }
        }
    return koniec;
}

int main()
{
    string **tab;                          //tu tworzymy tablice w ktorej bedzie nasza plansza
    const int wierszyk=10;
    const int kolumienka=21;
    tab= new string *[wierszyk];
    for(int i=0; i<wierszyk; i++)
    {
        tab[i]= new string[kolumienka];
    }
    plansza(tab,wierszyk,kolumienka);          //wczytujemy pierwsza plansze a nastepnie wyswietlamy
    wyswietl(tab,wierszyk,kolumienka);
    bool wygrana=false;
    while(!wygrana && koncowka(tab,wierszyk,kolumienka))                             //ta petla powoduje ze gracze beda na zmiane stawiali X i 0 az do konca gry
    {
        krzyzyk(tab,wierszyk,kolumienka);
        system("cls");
        wyswietl(tab,wierszyk,kolumienka);
        kolko(tab,wierszyk,kolumienka);
        system("cls");
        wyswietl(tab,wierszyk,kolumienka);
    }
    cout<<endl;
    cout<<"koniec rozgrywki"<<endl;                 //gdy skonczy sie miejsce lub ktos wygra konczy sie rozgrywka

    for (int i=0; i<kolumienka; i++)        //a do konca juz usuwamy tablice z nasza plansza
    {
        delete[] tab[i];
    }

    delete[] *tab;

    return 0;                                  //tu konczy sie program
}
