#include <iostream>
#include <string>

using namespace std;

int main(void)
{

        int column;
        int row;
        int column2;
        int row2;


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
                        cout << " " << tab[i][j] << " ";

                }
                cout << "|";
        }
        cout << endl;

        for (int i = 0; i < column2; ++i, cout << endl)

        {
                cout << "\t |";
                for (int j = 0; j < row2; ++j)
                {
                        cout << " " << tab2[i][j] << " ";

                }
                cout << "|";
        };


        cout << "wybierz jakie dzialanie mam wykonac \n 1 - Dodawanie\n 2 - Odejmowanie" << endl;
        int equation;
        cin >> equation;


        switch (equation)
        {



        case 1:
                //Dodawanie
                if (column != column2 || row != row2) {
                        cout << "nie mozna dodawac macierzy o roznych wymiarach";
                        break;
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
                break;
                //odejmowanie
        case 2:

                if (column != column2 || row != row2) {
                        cout << "nie mozna dodawac macierzy o roznych wymiarach";
                        break;
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
                        break;

        default: cout << "wybrano zly numer" << endl;




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
