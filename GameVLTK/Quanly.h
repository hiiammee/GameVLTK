#include <iostream>
#include "Base.h"
#include "QuaiVat.h"
#include "NhanVat.h"
#pragma once

class QuanLy
{
private:
	int temp1 = 0;
	int temp2 = 0;
	int Num_of_characters;
	int Num_of_monsters;
	Base** danhsach_NV = new Base * [10];
	Base** danhsach_QV = new Base * [1000];
public:
	QuanLy();
	~QuanLy();
	void nhap();
	void xuat();
	void tuongtac();
	void timSTLN();
};

