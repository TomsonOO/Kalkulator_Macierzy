// Program wykonujacy operacje na macierzach
#include <iostream>
#include <string>

using namespace std;

void add(double** tab, double**tab2, int row, int row2, int column, int column2); //funkcja wykonujaca operacje dodawania na macierzach
void subtract(double** tab, double**tab2, int row, int row2, int column, int column2);//funkcja wykonujaca operacje odejmowania na macierzach
void determinant(double** tab, int dimension, double detMultiplier ); //funkcja liczaca wyznacznik macierzy

int main(void)
{
    //deklaracja zmiennych - rozmiarow macierzy
    int column;
    int row;
    while(true)
    {
        //wybranie operacji jaka ma zostac wykonana na macierzach
        cout << "Wybierz dzialanie jakie ma zostac wykonane na macierzach:\n 1: Dodawanie\n 2: Odejmowanie\n 3: Wyznacznik\n 4: Zakoncz program\n" << endl;
        int equation;
        cin >> equation;
        if(equation == 4)
            exit(1);
        if(equation > 2)
        {
            //wprowadzenie przez uzytkownika wielkosci macierzy
            cout << "Podaj ilosc kolumn macierzy:" << endl;
            cin >> column;
            cout << "Podaj ilosc wierszy macierzy:" << endl;
            cin >> row;

            if(equation == 3 && row != column)
            {
                cout<<"Wyznacznik mozna obliczyc tylko z macierzy kwadratowej!\n\n";
            }
            else
            {
                //deklarowanie tablic i wypisywanie
                double** tab = new double* [column];
                for (int i = 0; i < column; ++i)
                {
                    tab[i] = new double[row];
                    cout << "Zacznij wypelniac tabele. Wiersz" << " " << i + 1 << ':' << endl;
                    for (int j = 0; j < row; ++j)
                        cin >> tab[i][j];
                }
                for (int i = 0; i < column; ++i, cout << endl)
                {
                    cout << "\t|\t";
                    for (int j = 0; j < row; ++j)
                    {
                        cout <<tab[i][j]<< "\t";
                    }
                    cout << "|";
                }
                cout << endl;
                double detMultiplier = 1; // zmienna potrzebna do policzenia wyznacznikow macierzy stopnia wiekszego niz 3

                switch(equation)
                {
                case 3:
                    if (column != row)
                    {
                        cout << "Nie mozna wyznaczyc wyznacznika macierzy o roznych wymiarach!";
                        break;
                    }
                    determinant(tab, row, detMultiplier); //funkcja liczaca wyznacznik funkcji(nieskonczona)
                    break;

                default:
                    cout<<"Podano zly numer!";
                    break;

                }
                for (int i(0); i < column; ++i)
                    delete[] tab[i];
                delete[] tab;
                tab = NULL;
            }
        }
        else
        {
            int column2; // wymiary drugiej macierzy
            int row2;
            //wprowadzenie przez uzytkownika wielkosci macierzy
            cout << "Podaj ilosc kolumn pierwszej macierzy" << endl;
            cin >> column;
            cout << "Podaj ilosc wierszy pierwszej macierzy" << endl;
            cin >> row;

            cout << "Podaj ilosc kolumn drugiej macierzy" << endl;
            cin >> column2;
            cout << "Podaj ilosc wierszy drugiej macierzy" << endl;
            cin >> row2;

            //deklarowanie tablic i wypisywanie
            double** tab = new double* [column];
            for (int i = 0; i < column; ++i)
            {
                tab[i] = new double[row];
                cout << "Zacznij wypelniac tabele. Wiersz" << " " << i + 1 << ':' << endl;
                for (int j = 0; j < row; ++j)
                    cin >> tab[i][j];
            }

            double** tab2 = new double* [column2];
            for (int i = 0; i < column2; ++i)
            {
                tab2[i] = new double[row2];
                cout << "Zacznij wypelniac tabele. Wiersz" << " " << i + 1 << ':' << endl;
                for (int j = 0; j < row2; ++j)
                    cin >> tab2[i][j];
            }


            for (int i = 0; i < column; ++i, cout << endl)

            {
                cout << "\t|\t";
                for (int j = 0; j < row; ++j)
                {
                    cout << tab[i][j] << "\t";

                }
                cout << "|";
            }
            cout << endl;

            for (int i = 0; i < column2; ++i, cout << endl)

            {
                cout << "\t|\t";
                for (int j = 0; j < row2; ++j)
                {
                    cout << tab2[i][j] << "\t";

                }
                cout << "|";
            };
            switch (equation)
            {
            case 1:
                add(tab, tab2, row, row2, column, column2); //Dodawanie
                break;

            case 2:
                subtract(tab, tab2, row, row2, column, column2);//odejmowanie
                break;

            default:
                cout << "Wybrano zly numer!" << endl;
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
}

void add(double** tab, double**tab2, int row, int row2, int column, int column2)
{
    if (column != column2 || row != row2)
    {
        cout << "Nie mozna dodawac macierzy o roznych wymiarach!";
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
        cout << "Wynikiem dodawania tych macierzy jest: \n" << endl;


        for (int i = 0; i < column2; ++i, cout << endl)
        {
            cout << "\t|\t";
            for (int j = 0; j < row2; ++j)
            {
                cout << tab_result[i][j] << "\t";
            }
            cout << "|";
        };
        for (int i(0); i < column2; ++i)
            delete[] tab_result[i];
        delete[] tab_result;
        tab_result = NULL;
    }
}

void subtract(double** tab, double**tab2, int row, int row2, int column, int column2)
{
    if (column != column2 || row != row2)
    {
        cout << "Nie mozna dodawac macierzy o roznych wymiarach!";

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
        cout << "Wynikiem odejmowania tych macierzy jest: \n" << endl;

        for (int i = 0; i < column2; ++i, cout << endl)

        {
            cout << "\t|\t";
            for (int j = 0; j < row2; ++j)
            {
                cout << tab_result[i][j] << "\t";

            }
            cout << "|";
        };
        for (int i(0); i < column2; ++i)
            delete[] tab_result[i];
        delete[] tab_result;
        tab_result = NULL;
    }
}

void determinant(double** tab, int dimension, double detMultiplier)
{
    if(dimension == 1) // wyznacznik macierzy pierwszego stopnia
        cout<<tab[0][0];
    else if(dimension == 2) //wyznacznik macierzy drugiego stopnia
    {
        double det = tab[0][0]*tab[1][1] - tab[0][1]*tab[1][0];
        cout<<det;
    }
    else if(dimension == 3)// wyznacznik trzeciego stopnia
    {
        double det = tab[0][0]*tab[1][1]*tab[2][2]+tab[0][1]*tab[1][2]*tab[2][0]+tab[0][2]*tab[1][0]*tab[2][1];
        det += -tab[2][0]*tab[1][1]*tab[0][2]-tab[2][1]*tab[1][2]*tab[0][0]-tab[2][2]*tab[1][0]*tab[0][1];
        det *= detMultiplier;
        cout<<det;
    }
    else //wyznacznik czwartego stopnia luz wyzej
    {
        double** temp = new double* [dimension-1]; //deklaracja tablicy
        for(int i=0; i<dimension; i++)
            temp[i] = new double[dimension-1];
        double k; // zmienna ktora wykorzystamy do przeprowadzenia operacji elementarnej na tablicy
        for(int i=0; i<dimension-1; i++)
        {
            k = -(tab[i][dimension-1])/(tab[dimension-1][dimension-1]);
            for(int j=0; j<dimension-1; j++)
            {
                temp[i][j] = tab[i][j]+tab[dimension-1][j]*k; // wykonanie operacji elementarnej na macierzy przeslanej do funkcji
            }
        }

        detMultiplier *= tab[dimension-1][dimension-1]; // zmienna ktora posluzy nam do wyznaczenia wyznacznika
        determinant(temp, dimension-1, detMultiplier); // zastosowanie rekurencji
        for (int i=0; i<dimension; ++i) // zwolnienie pamieci
            delete[] temp[i];
        delete[] temp;
        temp = NULL;
    }
}

