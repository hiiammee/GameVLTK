#include "Base.h"
#include <string.h>
#pragma once

class NhanVat : public Base
{
private:
	char Monphai[40];
public:
	NhanVat();
	virtual ~NhanVat();
	void setHp(int HP);
	unsigned getHp();
	void setExp(int EXP);
	double getExp();
	void setName(string Name);
	string getName();
	void setCap(int Cap);
	int getCap();
	void setKill_points(int K_p);
	int getKill_points();
	void nhap();
	void xuat();
	
};
