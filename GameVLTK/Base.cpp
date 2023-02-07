#include "textcolor.h"
#include "Base.h"
#pragma once

using namespace std;

Base::Base()
{
}
Base::~Base()
{
}
void Base::setHp(double HP)
{
	hp = HP;
}
unsigned Base::getHp()
{
	return hp;
}
string Base::getName()
{
	return name;
}
double Base::getExp_reward()
{
	return exp_reward;
}
void Base::setExp(double EXP)
{
	exp = EXP;
}
double Base::getExp()
{
	return exp;
}
double Base::getExp_full()
{
	return exp_full;
}
void Base::setCap(int CAP)
{
	cap = CAP;
}
int Base::getCap()
{
	return cap;
}
double Base::getST()
{
	return Satthuong;
}
void Base::setST(double _ST)
{
	Satthuong = _ST;
}
void Base::setHe(int m)
{
	He = m;
}
int Base::getHe()
{
	return He;
}

void Base::setKill_points(int k_p)
{
	kill_points = k_p;
}

int Base::getKill_points()
{
	return kill_points;
}
void Base::nhap()
{
	textcolor(15);
	cout << "Chon he ";
	textcolor(14);
	cout << "0.Kim\t";
	textcolor(10);
	cout << "1.Moc\t";
	textcolor(9);
	cout << "2.Thuy\t";
	textcolor(4);
	cout << "3.Hoa\t";
	textcolor(8);
	cout << "4.Tho\n";
	textcolor(15);
	cout << "Chon: ";
	while (cin >> He && He != 0 && He != 1 && He != 2 && He != 3 && He != 4)
	{
		textcolor(4);
		cout << "Chi nhap 0,1,2,3 hoac 4!\nNhap lai: ";
	}
}
void Base::xuat()
{
	switch (He)
	{
	case 0:
		textcolor(14);
		cout << "He Kim" << "\t\t"; break;
	case 1:
		textcolor(10);
		cout << "He Moc" << "\t\t"; break;
	case 2:
		textcolor(9);
		cout << "He Thuy" << "\t\t"; break;
	case 3:
		textcolor(4);
		cout << "He Hoa" << "\t\t"; break;
	case 4:
		textcolor(8);
		cout << "He Tho" << "\t\t"; break;
	}
}
void Base::tinhTuongtac(Base& b)
{
	double STtuongtacAB = this->getST();
	double STtuongtacBA = b.getST();
	if (TuongKhac(b)==1)
	{
		STtuongtacAB *= 1.2;
		setST(STtuongtacAB);
		STtuongtacBA *= 0.8;
		b.setST(STtuongtacBA);
	}

	else if (TuongKhac(b)==0)
	{
		STtuongtacAB *= 0.8;
		setST(STtuongtacAB);
		STtuongtacBA *= 1.2;
		b.setST(STtuongtacBA);
	}
	if (TuongSinh(b)==1)
	{
		STtuongtacAB *= 1.1;
		setST(STtuongtacAB);
	}
	else if (TuongSinh(b)==0)
	{
		STtuongtacBA *= 1.1;
		b.setST(STtuongtacBA);
	}
}

int Base::TuongKhac(Base& b)
{
	if ((this->He == 0 && b.getHe() == 1) ||
		(this->He == 1 && b.getHe() == 4) ||
		(this->He == 2 && b.getHe() == 3) ||
		(this->He == 3 && b.getHe() == 0) ||
		(this->He == 4 && b.getHe() == 2))
		return 1;
	else {
		if ((b.getHe() == 0 && this->He == 1) ||
			(b.getHe() == 1 && this->He == 4) ||
			(b.getHe() == 2 && this->He == 3) ||
			(b.getHe() == 3 && this->He == 0) ||
			(b.getHe() == 4 && this->He == 2))
		{
			return 0;
		}
	}
	return -1;
}

int Base::TuongSinh(Base& b)
{
	if ((this->He == 0 && b.getHe() == 2) ||
		(this->He == 1 && b.getHe() == 3) ||
		(this->He == 2 && b.getHe() == 1) ||
		(this->He == 3 && b.getHe() == 4) ||
		(this->He == 4 && b.getHe() == 0))
		return 1;
	else
	{
		if ((b.getHe() == 2 && this->He == 0) ||
			(b.getHe() == 3 && this->He == 1) ||
			(b.getHe() == 1 && this->He == 2) ||
			(b.getHe() == 4 && this->He == 3) ||
			(b.getHe() == 0 && this->He == 4))
			return 0;
	}
	return -1;
}
