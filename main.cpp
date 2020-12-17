// Program wykonujacy operacje na macierzach
#include <iostream>
#include <string>

using namespace std;

void dodaj(double** tab, double**tab2, int row, int row2, int column, int column2); //funkcja wykonujaca operacje dodawania na macierzach
void odejmij(double** tab, double**tab2, int row, int row2, int column, int column2);//funkcja wykonujaca operacje odejmowania na macierzach
void wyznacznik(double** tab, int w); //funkcja nieskonczona, narazie liczy wyznaczniki tylko dla macierzy max 3 stopnia


int main(void)
{
    //deklaracja zmiennych - rozmiarow macierzy
    int column;
    int row;
    int column2;
    int row2;


    //wybranie operacji jaka ma zostac wykonana na macierzach
    cout << "Wybierz dzialanie jakie ma zostac wykonane na macierzach:\n 1:  dodawanie\n 2: odejmowanie\n 3: wyznacznik\n" << endl;
    int equation;
    cin >> equation;
    if(equation > 2){
        //wprowadzenie przez uzytkownika wielkosci macierzy
        cout << "podaj ilosc kolumn macierzy" << endl;
        cin >> column;
        cout << "podaj ilosc wierszy macierzy" << endl;
        cin >> row;

        //deklarowanie tablic i wypisywanie
        double** tab = new double* [column];
        for (int i = 0; i < column; ++i)
        {
            tab[i] = new double[row];
            cout << "zacznij wypelniac tabele. wiersz" << " " << i + 1 << endl;
            for (int j = 0; j < row; ++j)
                cin >> tab[i][j];
                }
        for (int i = 0; i < column; ++i, cout << endl)
        {
            cout << "\t |";
            for (int j = 0; j < row; ++j)
        {
            cout << "  " << tab[i][j] << "  ";
        }
            cout << "|";
        }
        cout << endl;

        switch(equation)
        {
            case 3:
                wyznacznik(tab, row); //funkcja liczaca wyznacznik funkcji(nieskonczona)
                 break;

            case 4: //miejsce na nowa funkcje
                 break;

            default:
                cout<<"Podano zly numer!";

        }
        for (int i(0); i < column; ++i)
            delete[] tab[i];
        delete[] tab;
        tab = NULL;

    }
    else{
        //wprowadzenie przez uzytkownika wielkosci macierzy
        cout << "podaj ilosc kolumn pierwszej macierzy" << endl;
        cin >> column;
        cout << "podaj ilosc wierszy pierwszej macierzy" << endl;
        cin >> row;

        cout << "podaj ilosc kolumn drugiej macierzy" << endl;
        cin >> column2;
        cout << "podaj ilosc wierszy drugiej macierzy" << endl;
        cin >> row2;

        //deklarowanie tablic i wypisywanie
        double** tab = new double* [column];
        for (int i = 0; i < column; ++i)
        {
            tab[i] = new double[row];
            cout << "zacznij wypelniac tabele. wiersz" << " " << i + 1 << endl;
            for (int j = 0; j < row; ++j)
                cin >> tab[i][j];
        }

        double** tab2 = new double* [column2];
        for (int i = 0; i < column2; ++i)
        {
            tab2[i] = new double[row2];
            cout << "zacznij wypelniac tabele. wiersz" << " " << i + 1 << endl;
            for (int j = 0; j < row2; ++j)
                cin >> tab2[i][j];
        }


        for (int i = 0; i < column; ++i, cout << endl)

        {
            cout << "\t |";
            for (int j = 0; j < row; ++j)
            {
                cout << "  " << tab[i][j] << "  ";

            }
            cout << "|";
        }
        cout << endl;

        for (int i = 0; i < column2; ++i, cout << endl)

        {
            cout << "\t |";
            for (int j = 0; j < row2; ++j)
            {
                cout << "  " << tab2[i][j] << " ";

            }
            cout << "|";
        };
        switch (equation)
            {
            case 1:
                dodaj(tab, tab2, row, row2, column, column2); //Dodawanie
                break;

            case 2:
                odejmij(tab, tab2, row, row2, column, column2);//odejmowanie
                break;

            default:
                cout << "wybrano zly numer" << endl;
            }
        //odblokowanie pamięci
        for (int i(0); i < column; ++i)
            delete[] tab[i];
        delete[] tab;
        tab = NULL;
        for (int i(0); i < column2; ++i)
            delete[] tab2[i];
        delete[] tab2;
        tab2 = NULL;
        }

}

void dodaj(double** tab, double**tab2, int row, int row2, int column, int column2)
{
    if (column != column2 || row != row2)
    {
        cout << "nie mozna dodawac macierzy o roznych wymiarach";
    }
    else
    {
        double** tab_result = new double* [column2];
        for (int i = 0; i < column2; ++i)
        {
            tab_result[i] = new double[row2];
            for (int j = 0; j < row2; ++j)
                tab_result[i][j] = tab[i][j] + tab2[i][j];
        }
        cout << "wynikiem dodawania tych macierzy jest" << endl;


        for (int i = 0; i < column2; ++i, cout << endl)
        {
            cout << "\t |";
            for (int j = 0; j < row2; ++j)
            {
                cout << " " << tab_result[i][j] << " ";
            }
            cout << "|";
        };
        for (int i(0); i < column2; ++i)
            delete[] tab_result[i];
        delete[] tab_result;
        tab_result = NULL;
    }
}

void odejmij(double** tab, double**tab2, int row, int row2, int column, int column2)
{
    if (column != column2 || row != row2)
    {
        cout << "nie mozna dodawac macierzy o roznych wymiarach";

    }
    else
    {
        double** tab_result = new double* [column2];
        for (int i = 0; i < column2; ++i)
        {
            tab_result[i] = new double[row2];
            for (int j = 0; j < row2; ++j)
                tab_result[i][j] = tab[i][j] - tab2[i][j];
        }
        cout << "wynikiem odejmowania tych macierzy jest" << endl;


        for (int i = 0; i < column2; ++i, cout << endl)

        {
            cout << "\t |";
            for (int j = 0; j < row2; ++j)
            {
                cout << " " << tab_result[i][j] << " ";

            }
            cout << "|";
        };

        for (int i(0); i < column2; ++i)
            delete[] tab_result[i];
        delete[] tab_result;
        tab_result = NULL;
    }
}

void wyznacznik(double** tab, int w){
    double wyzn;
    if(w == 1)
        cout<<tab[0][0];
    else if(w == 2){
        wyzn = tab[0][0]*tab[1][1] - tab[0][1]*tab[1][0];
        cout<<wyzn;
    }
    else if(w == 3){
        wyzn = tab[0][0]*tab[1][1]*tab[2][2]+tab[0][1]*tab[1][2]*tab[2][0]+tab[0][2]*tab[1][0]*tab[2][1];
        wyzn += -tab[2][0]*tab[1][1]*tab[0][2]-tab[2][1]*tab[1][2]*tab[0][0]-tab[2][2]*tab[1][0]*tab[0][1];
        cout<<wyzn;

    }
    else{
        double** temp = new double* [w-1];
        for(int i=0; i<w; i++)
            temp[i] = new double[w-1];
        double k;
        for(int i=0; i<w-1; i++){
            k = -(tab[i][w-1])/(tab[w-1][w-1]);
            cout<<endl<<k<<endl;
            for(int j=0; j<w-1; j++){
                temp[i][j] = tab[i][j]+tab[w-1][j]*k;
            }
        }

        wyznacznik(temp, w-1);
        for (int i(0); i < w; ++i)
            delete[] temp[i];
        delete[] temp;
        temp = NULL;
    }
}

