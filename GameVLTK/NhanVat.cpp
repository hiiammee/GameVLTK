#include "textcolor.h"
#include "NhanVat.h"
#include "constants.h"
#pragma once

using namespace std;
using namespace constants;
NhanVat::NhanVat()
{
}
NhanVat::~NhanVat()
{
}
void NhanVat::setHp(int HP)
{
	hp = HP;
}
unsigned NhanVat::getHp()
{
	return hp;
}
void NhanVat::setExp(int EXP)
{
	exp = EXP;
}
double NhanVat::getExp()
{
	return exp;
}
void NhanVat::setName(string Name)
{
	name = Name;
}
string NhanVat::getName()
{
	return name;
}
void NhanVat::setCap(int Cap)
{
	cap = Cap;
}
int NhanVat::getCap()
{
	return cap;
}

void NhanVat::setKill_points(int k_p)
{
	kill_points += k_p;
}

int NhanVat::getKill_points()
{
	return kill_points;
}
void NhanVat::nhap()
{
	int chose = 0;
	Base::nhap();
	//
	switch (Base::getHe())
	{
	case 0:
	{
		textcolor(14);
		cout << "Chon mon phai: 0.Thieu lam 1.Thien vuong " << endl;
		while (cin >> chose && chose != 0 && chose != 1)
		{
			textcolor(4);
			cout << "Chi nhap 0 hoac 1!\nNhap lai: ";
		}
		switch (chose)
		{
		case 0: strcpy_s(Monphai, "Thieu lam");  break;
		case 1: strcpy_s(Monphai, "Thien vuong"); break;
		}
		break;
	}
	case 1:
	{
		textcolor(10);
		cout << "Chon mon phai: 0.Ngu doc 1.Duong mon " << endl;
		while (cin >> chose && chose != 0 && chose != 1)
		{
			textcolor(4);
			cout << "Chi nhap 0 hoac 1!\nNhap lai: ";
		}
		switch (chose)
		{
		case 0:strcpy_s(Monphai, "Ngu doc");  break;
		case 1:strcpy_s(Monphai, "Duong mon"); break;
		}
		break;
	}
	case 2:
	{
		textcolor(9);
		cout << "Chon mon phai: 0.Nga My 1.Thuy Yen Mon " << endl;
		while (cin >> chose && chose != 0 && chose != 1)
		{
			textcolor(12);
			cout << "Chi nhap 0 hoac 1!\nNhap lai: ";
		}
		switch (chose)
		{
		case 0: strcpy_s(Monphai, "Nga My");  break;
		case 1: strcpy_s(Monphai, "Thuy Yen Mon"); break;
		}
		break;
	}
	case 3:
	{
		textcolor(4);
		cout << "Chon mon phai: 0.Cai Bang 1.Thien Nhan Giao " << endl;
		while (cin >> chose && chose != 0 && chose != 1)
		{
			textcolor(4);
			cout << "Chi nhap 0 hoac 1!\nNhap lai: ";
		}
		switch (chose)
		{
		case 0: strcpy_s(Monphai, "Cai Bang");  break;
		case 1: strcpy_s(Monphai, "Thien Nhan Giao"); break;
		}
		break;
	}
	case 4:
	{
		textcolor(8);
		cout << "Chon mon phai: 0.Con Lon 1.Vo Dang " << endl;
		while (cin >> chose && chose != 0 && chose != 1)
		{
			textcolor(4);
			cout << "Chi nhap 0 hoac 1!\nNhap lai: ";
		}
		switch (chose)
		{
		case 0: strcpy_s(Monphai, "Con Lon");  break;
		case 1: strcpy_s(Monphai, "Vo Dang"); break;
		}
		break;
	}
	}
	textcolor(15);
	cout << "Nhap ten nhan vat: ";
	cin >> name;
	textcolor(15);
	cout << "Nhap vao cap do nhan vat: ";
	cin >> cap;
	Base::setST(cap * 5);
	defense = Base::getST() * 0.6;
	exp = 0;
	if (cap > 0 && cap <= 40)
	{
		hp = cap * HP_character_1;
		exp_full = cap * EXP_1 * 100;
	}
	else if (cap > 40 && cap <= 70)
	{
		hp = 40 * HP_character_1 + (cap - 40) * HP_character_2;
		exp_full = 40 * EXP_1 * 100 + (cap - 40) * EXP_2 * 500;
	}
	else if (cap > 70 && cap <= 100)
	{
		hp = 40 * HP_character_1 + (70 - 40) * HP_character_2 + (cap - 70) * HP_character_3;
		exp_full = 40 * EXP_1 * 100 + (70 - 40) * EXP_2 * 500 + (cap - 70) * EXP_3 * 2000;
	}
}

void NhanVat::xuat()
{
	Base::xuat();
	textcolor(15);
	cout << name << '\t';
	cout << Monphai << '\t';
	cout << Satthuong << "\t\t";
	cout << cap << '\t';
	cout << hp << endl;
}
