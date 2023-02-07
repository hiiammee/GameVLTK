#include "textcolor.h"
#include "QuaiVat.h"
#include "constants.h"
#pragma once

using namespace std;
using namespace constants;

Quai::Quai()
{
}
Quai::~Quai()
{
}
void Quai::setHp(double HP)
{
    hp = HP;
}
unsigned Quai::getHp()
{
    return hp;
}
void Quai::setExp_reward(double x)
{
    exp_reward = x;
}
double Quai::getExp_reward()
{
    return exp_reward;
}
void Quai::nhap()
{
    Base::nhap();
    textcolor(15);
    cout << "Nhap vao cap do quai: ";
    cin >> cap;
    textcolor(15);
    cout << "Nhap loai quai." << endl;
    textcolor(15);
    cout << "Chon 0: Creep" << endl;
    textcolor(15);
    cout << "Chon 1: Boss" << endl;
    cout << "Chon: ";
    while (cin >> Loai && Loai != 0 && Loai != 1)
    {
        textcolor(4);
        cout << "Chi nhap 0 hoac 1!\nNhap lai: ";
    }

    switch (Loai)
    {
    case 0:
        Base::setST(cap * 3);
        if (cap > 0 && cap <= 40)
        {
            hp = cap * HP_1;
            exp_reward = cap * EXP_1;
        }
        else if (cap > 40 && cap <= 70)
        {
            hp = 40 * HP_1 + (cap - 40) * HP_2;
            exp_reward = 40 * EXP_1 + (cap - 40) * EXP_2;
        }
        else if (cap > 70 && cap <= 100)
        {
            hp = 40 * HP_1 + (70 - 40) * HP_2 + (cap - 70) * HP_3;
            exp_reward = 40 * EXP_1 + (70 - 40) * EXP_2 + (cap - 70) * EXP_3;
        }
        break;
    case 1:
        Base::setST(cap * 7);
        if (cap > 0 && cap <= 40)
        {
            hp = cap * HP_1 * 4;
            exp_reward = cap * EXP_1 * 4;
        }
        else if (cap > 40 && cap <= 70)
        {
            hp = (40 * HP_1 + (cap - 40) * HP_2) * 4;
            exp_reward = (40 * EXP_1 + (cap - 40) * EXP_2) * 4;
        }
        else if (cap > 70 && cap <= 100)
        {
            hp = (40 * HP_1 + (70 - 40) * HP_2 + (cap - 70) * HP_3) * 1.2;
            exp_reward = (40 * EXP_1 + (70 - 40) * EXP_2 + (cap - 70) * EXP_3) * 4;
        }
        break;
    default:Base::setST(cap * 3);
    }
}
void Quai::xuat()
{
    Base::xuat();
    textcolor(15);
    switch (Loai)
    {
    case 0: cout << "Thuong\t"; break;
    case 1:
        textcolor(4);
        cout << "Boss\t"; break;
    }
    textcolor(15);
    cout << Satthuong << "\t\t";
    cout << cap << '\t';
    cout << hp << endl;
}
