#include <conio.h>
#include <iostream>
using namespace std;

//=============-menu-=============

int get_key()
{
    int key = _getch();
    if ((key == 0) || (key == 224))
        key = _getch();
    return key;
}

int menu1()
{
    cout << "\nКласс Матрицы.\n\n"
        "1 - Посмотреть/изменить исследуемые матрицы.\n"
        "2 - Сложение матриц\n"
        "3 - Разность матриц\n"
        "4 - Произведение матриц\n"
        "5 - Умножение матрицы на скаляр\n"
        "6 - Деление матрицы на скаляр\n"
        "7 - Вычисление следа матрицы\n\n"
        "Выход: Esc";


    while (true)
    {
        int key = get_key();
        if ((key == 27) || (key > '0' && key <= '7'))
            return key;
    }
}

int menu2()
{
    cout << "\n\n";
    cout << "Продолжить: Enter";
    while (true)
    {
        int key = get_key();
        if (key == 13) return key;
    }
}

int menu3()
{
    cout << "1 - да\n2 - нет";
    while (true)
    {
        int key = get_key();
        if (key == '1' || key == '2') return key;
    }
}

//==========-input control-==========

//-----------double----------------
bool double_control(char* xn)
{
    char* tmp = xn;
    int zap_p = 0;
    const char mask[] = ".-1234567890";
    int checker = 0;
    while (*tmp)
    {
        if (strchr(mask, *tmp)) checker++;
        tmp++;
    }
    if (checker != strlen(xn))
        return false;
    if (checker == 0)
        return false;

    if (*xn == '-' && *(xn + 1) == '\0')
    {
        return false;
    }
    if ((*xn == ','))
        return false;

    tmp = xn;
    while (*tmp)
    {
        if ((*tmp == ','))
        {
            zap_p++;
        }
        if ((*(tmp + 1) == '-') || (*tmp == '\0'))
        {
            return false;
        }
        tmp++;
    }
    if (zap_p > 1) return false;
    return true;
}

double double_checker()
{
    char n_data[64];
    while (true) {
        gets_s(n_data);
        bool check = double_control(n_data);
        if (check == true) break;
        else
        {
            cout << "  Неверный формат данных! Повторите попытку: ";
        }
    }
    double data = (double)atof(n_data);
    return data;
}

//--------------int-----------------
bool int_control(char* xn)
{
    char* tmp = xn;
    int zap_p = 0;
    const char mask[] = "-1234567890";
    int checker = 0;
    while (*tmp)
    {
        if (strchr(mask, *tmp)) checker++;
        tmp++;
    }
    if (checker != strlen(xn))
        return false;
    if (checker == 0)
        return false;

    if (*xn == '-' && *(xn + 1) == '\0')
    {
        return false;
    }
    if ((*xn == ','))
        return false;

    tmp = xn;
    while (*tmp)
    {
        if ((*tmp == ','))
        {
            zap_p++;
        }
        if ((*(tmp + 1) == '-') || (*tmp == '\0'))
        {
            return false;
        }
        tmp++;
    }
    if (zap_p > 1) return false;
    return true;
}

int int_checker()
{
    char n_data[64];
    while (true) {
        gets_s(n_data);
        bool check = int_control(n_data);
        if (check == true) break;
        else
        {
            printf("  Неверный формат данных! Повторите попытку: ");
        }
    }
    int data = (int)atoi(n_data);
    return data;
}