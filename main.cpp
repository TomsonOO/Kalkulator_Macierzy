// Program wykonujacy operacje na macierzach
#include <iostream>
#include <string>

using namespace std;

void add(double** tab, double** tab2, int row, int row2, int column, int column2); //funkcja wykonujaca operacje dodawania na macierzach
void subtract(double** tab, double** tab2, int row, int row2, int column, int column2);//funkcja wykonujaca operacje odejmowania na macierzach
void multiply(double** tab, double** tab2, int row, int row2, int column, int column2); //funkcja wykonujaca operacje mnozenia na macierzach
void multiplybyscalar(double** tab, int row, int column, double scalar); //funkcja wykonujaca operacje mnozenia macierzy przez skalar
void determinant(double** tab, int dimension, double detMultiplier); //funkcja liczaca wyznacznik macierzy
void transpose(double** tab, int row, int column); //funkcja licząca macierz transponowaną

int main(void)
{
    //deklaracja zmiennych - rozmiarow macierzy
    int column;
    int row;
    while (true)
    {
        //wybranie operacji jaka ma zostac wykonana na macierzach
        cout << "Wybierz dzialanie jakie ma zostac wykonane na macierzach:\n 1: Dodawanie\n 2: Odejmowanie\n 3: Mnozenie\n 4: Mnozenie przez skalar\n 5: Wyznacznik\n 6: Macierz transponowana\n 7: Zakoncz program\n" << endl;
        int equation;
        cin >> equation;
        if (equation == 7) {
            exit(1);
        }
        if (equation > 3)
        {
            //wprowadzenie przez uzytkownika wielkosci macierzy
            cout << "Podaj ilosc kolumn macierzy:" << endl;
            cin >> column;
            cout << "Podaj ilosc wierszy macierzy:" << endl;
            cin >> row;

            if (equation == 4 && row != column)
            {
                cout << "Wyznacznik mozna obliczyc tylko z macierzy kwadratowej!\n\n";
            }
            else
            {
                //deklarowanie tablic i wypisywanie
                double** tab = new double* [row];
                for (int i = 0; i < row; ++i)
                {
                    tab[i] = new double[row];
                    cout << "Zacznij wypelniac macierz. Wiersz" << " " << i + 1 << ':' << endl;
                    for (int j = 0; j < column; ++j)
                        cin >> tab[i][j];
                }
                for (int i = 0; i < row; ++i, cout << endl)
                {
                    cout << "\t|\t";
                    for (int j = 0; j < column; ++j)
                    {
                        cout << tab[i][j] << "\t";
                    }
                    cout << "|";
                }
                double scalar;
                if (equation == 4) {
                    cout << "Podaj liczbe (skalar) przez ktora chcesz pomnozyc macierz:" << endl;
                    cin >> scalar;
                    cout << endl;
                }
                double detMultiplier = 1; // zmienna potrzebna do policzenia wyznacznikow macierzy stopnia wiekszego niz 3

                switch (equation)
                {
                case 4:
                    multiplybyscalar(tab, row, column, scalar);
                    break;
                case 5:
                    determinant(tab, row, detMultiplier); //funkcja liczaca wyznacznik funkcji
                    break;
                case 6:
                    transpose(tab, row, column); //transponowanie
                    break;

                default:
                    cout << "Podano zly numer!";
                    break;

                }
                for (int i(0); i < row; ++i)
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

            if (column != row2 && equation == 3) {
                cout << "Mnozyc mozna tylko gdy liczba kolumn pierwszej macierzy jest rowna liczbie wierszy drugiej!" << endl;
            }

            else {
                //deklarowanie tablic i wypisywanie
                double** tab = new double* [row];
                for (int i = 0; i < row; ++i)
                {
                    tab[i] = new double[row];
                    cout << "Zacznij wypelniac macierz pierwsza. Wiersz" << " " << i + 1 << ':' << endl;
                    for (int j = 0; j < column; ++j)
                        cin >> tab[i][j];
                }

                double** tab2 = new double* [row2];
                for (int i = 0; i < row2; i++)
                {
                    tab2[i] = new double[row2];
                    cout << "Zacznij wypelniac macierz druga. Wiersz" << " " << i + 1 << ':' << endl;
                    for (int j = 0; j < column2; j++)
                        cin >> tab2[i][j];
                }


                for (int i = 0; i < row; ++i, cout << endl)

                {
                    cout << "\t|\t";
                    for (int j = 0; j < column; ++j)
                    {
                        cout << tab[i][j] << "\t";

                    }
                    cout << "|";
                }
                cout << endl;

                for (int i = 0; i < row2; i++, cout << endl)

                {
                    cout << "\t|\t";
                    for (int j = 0; j < column2; ++j)
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
                case 3:
                    multiply(tab, tab2, row, row2, column, column2);
                    break;
                default:
                    cout << "Wybrano zly numer!" << endl;
                }
                //odblokowanie pamięci
                for (int i(0); i < row; ++i)
                    delete[] tab[i];
                delete[] tab;
                tab = NULL;
                for (int i(0); i < row; ++i)
                    delete[] tab2[i];
                delete[] tab2;
                tab2 = NULL;
            }
        }
    }
}

void add(double** tab, double** tab2, int row, int row2, int column, int column2)
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

void subtract(double** tab, double** tab2, int row, int row2, int column, int column2)
{
    if (column != column2 || row != row2)
    {
        cout << "Nie mozna odejmowac macierzy o roznych wymiarach!";

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
    if (dimension == 1) // wyznacznik macierzy pierwszego stopnia
        cout << "WYznacznik tej macierzy wynosi:" << tab[0][0]<<endl;
    else if (dimension == 2) //wyznacznik macierzy drugiego stopnia
    {
        double det = tab[0][0] * tab[1][1] - tab[0][1] * tab[1][0];
        cout << "WYznacznik tej macierzy wynosi:" <<  det << endl;
    }
    else if (dimension == 3)// wyznacznik trzeciego stopnia
    {
        double det = tab[0][0] * tab[1][1] * tab[2][2] + tab[0][1] * tab[1][2] * tab[2][0] + tab[0][2] * tab[1][0] * tab[2][1];
        det += -tab[2][0] * tab[1][1] * tab[0][2] - tab[2][1] * tab[1][2] * tab[0][0] - tab[2][2] * tab[1][0] * tab[0][1];
        det *= detMultiplier;
        cout << "WYznacznik tej macierzy wynosi:" << det << endl;
    }
    else //wyznacznik czwartego stopnia luz wyzej
    {
        double** temp = new double* [dimension - 1]; //deklaracja tablicy
        for (int i = 0; i < dimension; i++)
            temp[i] = new double[dimension - 1];
        double k; // zmienna ktora wykorzystamy do przeprowadzenia operacji elementarnej na tablicy
        for (int i = 0; i < dimension - 1; i++)
        {
            if( tab[dimension-1][dimension - 1] != 0 && (tab[i][dimension - 1]) != 0 )
                k = -(tab[i][dimension - 1]) / (tab[dimension - 1][dimension - 1]);
            else
                k = 0;
            for (int j = 0; j < dimension - 1; j++)
            {
                temp[i][j] = tab[i][j] + tab[dimension - 1][j] * k; // wykonanie operacji elementarnej na macierzy przeslanej do funkcji
            }
        }

        detMultiplier *= tab[dimension - 1][dimension - 1]; // zmienna ktora posluzy nam do wyznaczenia wyznacznika
        determinant(temp, dimension - 1, detMultiplier); // zastosowanie rekurencji
        for (int i = 0; i < dimension; ++i) // zwolnienie pamieci
            delete[] temp[i];
        delete[] temp;
        temp = NULL;
    }
}
void transpose(double** tab, int row, int column) {

    double** tab_result = new double* [column];
    for (int i = 0; i < column; i++) {
        tab_result[i] = new double[row];
        for (int j = 0; j < row; j++) {

            tab_result[i][j] = tab[j][i];
        }
    }
    cout << "Macierza transponowana do twojej macierzy jest: \n" << endl;
    for (int i = 0; i < column; ++i, cout << endl)

    {
        cout << "\t|\t";
        for (int j = 0; j < row; ++j)
        {
            cout << tab_result[i][j] << "\t";

        }
        cout << "|";
    }
    for (int i(0); i < column; ++i)
        delete[] tab_result[i];
    delete[] tab_result;
    tab_result = NULL;

}
void multiplybyscalar(double** tab, int row, int column, double scalar) {
    double** tab_result = new double* [row];
    for (int i = 0; i < row; i++) {
        tab_result[i] = new double[row];
        for (int j = 0; j < column; j++) {

            tab_result[i][j] = scalar * tab[i][j];
        }
    }
    cout << "Macierza pomnozona przez skalar = " << scalar << " jest: \n" << endl;
    for (int i = 0; i < row; ++i, cout << endl)

    {
        cout << "\t|\t";
        for (int j = 0; j < column; ++j)
        {
            cout << tab_result[i][j] << "\t";

        }
        cout << "|";
    };
    for (int i(0); i < row; ++i)
        delete[] tab_result[i];
    delete[] tab_result;
    tab_result = NULL;
}
void multiply(double** tab, double** tab2, int row, int row2, int column, int column2) {
    double** tab_result = new double* [row];
    double temp;
    for (int i = 0; i < row; i++) {
        tab_result[i] = new double[row];
        for (int j = 0; j < column2; j++) {
            temp = 0;
            for (int k = 0; k < column; k++) {
                temp += tab[i][k] * tab2[k][j];
                tab_result[i][j] = temp;
            }
        }
    }
    cout << "Wynikiem mnozenia macierzy jest: \n" << endl;
    for (int i = 0; i < row; ++i, cout << endl)

    {
        cout << "\t|\t";
        for (int j = 0; j < row2; ++j)
        {
            cout << tab_result[i][j] << "\t";

        }
        cout << "|";
    };
    for (int i(0); i < column; ++i)
        delete[] tab_result[i];
    delete[] tab_result;
    tab_result = NULL;
}
