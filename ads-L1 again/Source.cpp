//=)
//sheeeesh

#include <locale.h>
#include <iostream>
#include <ostream>
#include "Matrix.h"
using namespace std;

bool double_control(char* xn);
double double_checker();
bool int_control(char* xn);
int int_checker();


int get_key();
int menu1();
int menu2();
int menu3();

Matrix operator * (double h, Matrix matrix);
Matrix operator / (double h, Matrix matrix);
std::ostream& operator << (std::ostream& s, const Matrix& matrix);

int main() {
    setlocale(LC_ALL, "");

    Matrix A(2, 2);
    Matrix B(2, 2), C(2, 2);
    A(0, 0) = 1;
    A(0, 1) = 2;
    A(1, 0) = 3;
    A(1, 1) = 4;

    B(0, 0) = 1;
    B(0, 1) = 2;
    B(1, 0) = 3;
    B(1, 1) = 4;

    while (true) {
        system("cls");
        int m1 = menu1();
        switch (m1) {
        case 27: return 0;
        case 49: {
            system("cls");
            cout << "\tИсследуемые матрицы:\n\n";
            cout << "A:\n" << A << endl;
            cout << "B:\n" << B;

            cout << "\n\nХотите изменить матрицы?" << endl;
            int m3 = menu3();
            switch (m3) {
            case 49: {
                system("cls");
                cout << "\n--------Задание матрицы А--------" << endl;
                A.EnterMatrix();

                cout << "\n--------Задание матрицы B--------" << endl;
                B.EnterMatrix();

                break;
            }
            case 50: {
                break;
            }
            }

            break;
        }
        case 50: {
            system("cls");
            cout << "\tСложение матриц.\n\n";
            bool check = 0;
            try {
                C = A + B;
                check = 1;
            }
            catch (const char* message) {
                cout << message;
            }

            if (check) {
                cout << "A + B:\n\n" << endl;
                cout << A << "\n +\n\n" << B << "\n = \n\n";
                cout << A + B;
            }

            break;
        }
        case 51: {
            system("cls");
            cout << "\tРазность матриц.\n\n";
            bool check = 0;
            try {
                C = A - B;
                check = 1;
            }
            catch (const char* message) {
                cout << message;
            }

            if (check) {
                C = A - B;
                cout << "A - B:\n\n" << endl;
                cout << A << "\n -\n\n" << B << "\n = \n\n";
                cout << C;
            }

            break;
        }
        case 52: {
            system("cls");
            cout << "\tУмножение матриц.\n\n";
            bool check = 0;
            try {
                C = A * B;
                check = 1;
            }
            catch (const char* message) {
                cout << message;
            }

            if (check) {
                C = A * B;
                cout << "A * B:\n\n" << endl;
                cout << A << "\n *\n\n" << B << "\n = \n\n";
                cout << C;
            }

            break;
        }
        case 53: {
            system("cls");
            cout << "\tУмножение матрицы на скаляр.\n\n";
            double a;
            cout << "Введите значение (скаляр): ";
            a = double_checker();
           // cin.get();
            cout << "A * a:\n\n" << endl;
            cout << A << "\n *\n\n " << a << "\n\n = \n\n";
            C = A * a;
            cout << C;

            break;
        }
        case 54: {
            system("cls");
            cout << "\tДеление матрицы на скаляр.\n\n";
            double a;
            cout << "Введите значение (скаляр): ";
            a = double_checker();
          //  cin.get();
            cout << "A \ a:\n\n" << endl;
            cout << A << "\n /\n\n " << a << "\n\n = \n\n";
            C = A / a;
            cout << C;

            break;
        }
        case 55: {
            system("cls");
            cout << "\tВычисление следа матрицы.\n\n";
            cout << "Tr(A) = " << A.tr();
            break;
        }

        }
        while (true)
        {
            int m2 = menu2();
            if (m2 == 13) break;
        }
    }
}