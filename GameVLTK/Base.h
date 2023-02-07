#include <iostream>
#include <string.h>
#pragma once
using namespace std;

class Base
{
private:
	friend class QuanLy;
protected:
	int He;// 0. KIm, 1. Moc , 2. Thuy, 3.Hoa,4. Tho
	double Satthuong;
	double defense;
	int cap;
	string name;
	unsigned hp;
	double exp;
	double exp_reward;
	double exp_full;
	int kill_points = 0;
public:
	Base();
	~Base();
	virtual void setHp(double HP);
	virtual unsigned getHp();
	virtual string getName();
	virtual double getExp_reward();
	virtual void setExp(double EXP);
	virtual double getExp();
	virtual double getExp_full();
	virtual void setCap(int CAP);
	virtual int getCap();
	virtual void nhap();
	virtual void xuat();
	virtual void setKill_points(int k_p);
	virtual int getKill_points();
	void tinhTuongtac(Base& b);
	int TuongSinh(Base& b);
	int TuongKhac(Base& b);
	double getST();
	void setST(double _ST);
	void setHe(int m);
	int getHe();
};


