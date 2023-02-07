#include "Base.h"
#pragma once


class Quai : public Base
{
private:
	int Loai;	 // 0. Thuong 1.Boss
public:
	Quai();
	~Quai();
	void setHp(double HP);
	unsigned getHp();
	void setExp_reward(double x);
	double getExp_reward();
	void nhap();
	void xuat();
};
