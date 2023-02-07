#include "textcolor.h"
#include "QuanLy.h"
#pragma once

using namespace std;

QuanLy::QuanLy()
{
}
QuanLy::~QuanLy()
{
}
void QuanLy::nhap()
{
    int CatchKey;
    int selection;
    textcolor(2);
    cout << "Chon 0 de khoi tao nhan vat" << endl;
    textcolor(1);
    cout << "Chon 1 de khoi tao quai vat" << endl;
    textcolor(15);
    cout << "Chon: ";
    while (cin >> selection && selection != 0 && selection != 1)
    {
        textcolor(4);
        cout << "Chi nhap 0 hoac 1!\n";
        textcolor(15);
        cout << "Nhap lai: ";
    }
    switch (selection)
    {
    case 0:
        if (temp1 > 10)
        {
            textcolor(4);
            cout << "So nhan vat da full.\n";
        }
        else
        {
            textcolor(15);
            cout << "Nhap so luong nhan vat muon khoi tao " << "(Luu y!!! Mot tai khoan chi co toi da 10 nhan vat.): ";
            while (cin >> Num_of_characters && Num_of_characters >10)
            {
                textcolor(4);
                cout << "Khong the nhap qua 10.\n";
                textcolor(15);
                cout << "Vui long nhap lai: ";
            }
            for (int i = temp1 + 1; i <= Num_of_characters + temp1; i++)
            {
                danhsach_NV[i] = new NhanVat;
                textcolor(15);
                cout << "Nhap thong tin nhan vat thu " << i << ":" << endl;
                danhsach_NV[i]->nhap();
            }
            temp1 += Num_of_characters;
            do {
                textcolor(7);
                cout << "\t Chon 1 de tiep tuc khoi tao .\n";
                textcolor(8);
                cout << "\t Chon 2 de dung.\n";
                textcolor(15);
                cout << "Chon: ";
                cin >> CatchKey;
            } while (CatchKey != 1 && CatchKey != 2);
            if (CatchKey == 1)
                return QuanLy::nhap();
            else if (CatchKey == 2)
                break;
        }


    case 1:
        textcolor(15);
        cout << "Nhap so luong quai vat muon khoi tao: ";
        cin >> Num_of_monsters;
        for (int i = temp2+1; i <= Num_of_monsters+temp2; i++)
        {
            danhsach_QV[i] = new Quai;
            textcolor(15);
            cout << "Nhap thong tin quai vat thu " << i << ": " << endl;
            danhsach_QV[i]->nhap();
        }
        temp2 += Num_of_monsters;
        do {
            textcolor(7);
            cout << "\t Chon 1 de tiep tuc khoi tao .\n";
            textcolor(8);
            cout << "\t Chon 2 de dung.\n";
            textcolor(15);
            cout << "Chon: ";
            cin >> CatchKey;
        } while (CatchKey != 1 && CatchKey != 2);
        if (CatchKey == 1)
            return QuanLy::nhap();
        else if (CatchKey == 2)
            break;
    }
    system("pause");
    system("cls");
}

void QuanLy::xuat()
{
    textcolor(2);
    cout << "Thong tin nhan vat" << endl;
    textcolor(15);
    cout << "Thu tu\tHe ngu hanh\tTen\tMon phai\tSat thuong\tLevel\tHp" << endl;
    for (int i = 1; i <= temp1; i++)
    {
        cout << i << '\t';
        danhsach_NV[i]->xuat();
    }
    cout << endl << endl << endl;
    textcolor(1);
    cout << "Thong tin quai vat" << endl;
    textcolor(15);
    cout << "Thu tu\tHe ngu hanh\tLoai\tSat thuong\tLevel\tHp" << endl;
    for (int i = 1; i <= temp2; i++)
    {
        cout << i << '\t';
        danhsach_QV[i]->xuat();
    }
    cout << endl;

}
void QuanLy::tuongtac()
{
    int Key;
    textcolor(13);
    cout << "Chon 1: Player PK.\n";
    textcolor(14);
    cout << "Chon 2: San quai.\n";
    textcolor(15);
    cout << "Chon: ";
    while (cin >> Key && Key != 1 && Key != 2)
    {
        textcolor(4);
        cout << "Chi nhap 1 hoac 2!!\n";
        cout << "Nhap lai: ";
    }
    if (Key == 2)
    {
        if (temp1 == 0 || temp2 == 0)
        {
            textcolor(4);
            cout << "khong du doi tuong de thuc hien tuong tac.\n";
            return QuanLy::tuongtac();
        }
        else
        {
            int CatchKey;
            int x, y;
            textcolor(15);
            cout << "chon thu tu nhan vat tuong tac:\t ";
            while (cin >> x && x > temp1)
            {
                textcolor(4);
                cout << "khong ton tai nhan vat tuong ung.\n";
                textcolor(15);
                cout << "Nhap lai: ";
            }
            textcolor(15);
            cout << "chon thu tu quai vat tuong tac:\t ";
            while (cin >> y && y > temp2)
            {
                textcolor(4);
                cout << "khong ton tai quai vat tuong ung.\n";
                textcolor(15);
                cout << "Nhap lai: ";
            }
            double temp1 = danhsach_NV[x]->getST();
            double temp2 = danhsach_QV[y]->getST();
            danhsach_NV[x]->tinhTuongtac(*danhsach_QV[y]);
            while (danhsach_NV[x]->getHp() > 0 && danhsach_QV[y]->getHp() > 0)
            {
                double m = danhsach_QV[y]->getHp() - danhsach_NV[x]->getST();
                if (m < 0)
                    m = 0;
                cout << danhsach_NV[x]->getName() << " gay " << danhsach_NV[x]->getST() << " sat thuong len quai vat vo danh" << endl;
                danhsach_QV[y]->setHp(m);
                cout << "So mau con lai cua quai vat " << danhsach_QV[y]->getHp() << endl << endl;
                double HP_decrease = danhsach_QV[y]->getST() - danhsach_NV[x]->defense;
                if (HP_decrease < 0)
                    HP_decrease = 0;
                double n = danhsach_NV[x]->getHp() - HP_decrease;
                if (n < 0)
                    n = 0;
                cout << "Quat vat gay " << HP_decrease << " sat thuong len " << danhsach_NV[x]->getName() << endl;
                danhsach_NV[x]->setHp(n);
                cout << "So mau con lai cua " << danhsach_NV[x]->getName() << " la " << danhsach_NV[x]->getHp() << endl << endl;
                if (danhsach_NV[x]->getHp() <= 0)
                {
                    cout << danhsach_NV[x]->getName() << " bi tieu diet boi quai vat vo danh" << endl;
                }
                if (danhsach_QV[y]->getHp() <= 0)
                {
                    cout << danhsach_NV[x]->getName() << " da tieu diet quai vat" << endl;
                    cout << "nhan duoc " << danhsach_QV[y]->getExp_reward() << " kinh nghiem." << endl;
                    double kinh_nghiem = danhsach_QV[y]->getExp_reward() + danhsach_NV[x]->getExp();
                    danhsach_NV[x]->setExp(kinh_nghiem);
                    if (danhsach_NV[x]->getExp() >= danhsach_NV[x]->getExp_full())
                    {
                        cout << "level up" << endl;
                        cout << "level hien tai la: " << danhsach_NV[x]->getCap();
                        danhsach_NV[x]->cap++;
                        danhsach_NV[x]->setExp(0);
                    }

                }
                system("pause");

            }
            system("cls");
            danhsach_NV[x]->setST(temp1);
            danhsach_QV[y]->setST(temp2);
            do {
                textcolor(7);
                cout << "\t Chon 1 de tiep tuc tuong tac .\n";
                textcolor(8);
                cout << "\t Chon 2 de thoat.\n";
                textcolor(15);
                cout << "Chon: ";
                cin >> CatchKey;
            } while (CatchKey != 1 && CatchKey != 2);
            if (CatchKey == 1)
            {
                system("cls");
                xuat();
                return QuanLy::tuongtac();
            }
            else if (CatchKey == 2)
            {
                system("cls");
                return;
            }
        }
    }
    else
    {
        if (temp1 < 2)
        {
            textcolor(4);
            cout << "Tuong tac can co 2 nhan vat tro len.\n";
            return QuanLy::tuongtac();
        }
        else
        {
            int CatchKey;
            int x, y;
            textcolor(15);
            cout << "chon thu tu nhan vat tuong tac thu nhat: ";
            while (cin >> x && x > temp1)
            {
                textcolor(4);
                cout << "khong ton tai nhan vat tuong ung.\n";
                textcolor(15);
                cout << "Nhap lai: ";
            }
            textcolor(15);
            cout << "chon thu tu nhan vat tuong tac thu hai: ";
            while (cin >> y && y > temp1)
            {
                textcolor(4);
                cout << "khong ton tai nhan vat tuong ung.\n";
                textcolor(15);
                cout << "Nhap lai: ";
            }
            if (danhsach_NV[x]->getCap() == danhsach_NV[y]->getCap()
                && danhsach_NV[x]->TuongKhac(*danhsach_NV[y]) == -1
                && danhsach_NV[x]->TuongSinh(*danhsach_NV[y]) == -1)
            {
                textcolor(175);
                cout << "Hai nhan vat ngang bang nhau.\n";
                system("pause");
            }
            else
            {
                double temp1 = danhsach_NV[x]->getST();
                double temp2 = danhsach_NV[y]->getST();
                danhsach_NV[x]->tinhTuongtac(*danhsach_NV[y]);
                while (danhsach_NV[x]->getHp() > 0 && danhsach_NV[y]->getHp() > 0)
                {
                    double HP_decrease1 = danhsach_NV[x]->getST() - danhsach_NV[y]->defense;
                    if (HP_decrease1 < 0)
                        HP_decrease1 = 0;
                    double m = danhsach_NV[y]->getHp() - HP_decrease1;
                    if (m < 0)
                        m = 0;
                    cout << danhsach_NV[x]->getName() << " gay " << HP_decrease1 << " sat thuong len " << danhsach_NV[y]->getName() << endl;
                    danhsach_NV[y]->setHp(m);
                    cout << "So mau con lai cua " << danhsach_NV[y]->getName() << " la " << danhsach_NV[y]->getHp() << endl << endl;
                    double HP_decrease2 = danhsach_NV[y]->getST() - danhsach_NV[x]->defense;
                    if (HP_decrease2 < 0)
                        HP_decrease2 = 0;
                    double n = danhsach_NV[x]->getHp() - HP_decrease2;
                    if (n < 0)
                        n = 0;
                    cout << danhsach_NV[y]->getName() << " gay " << HP_decrease2 << " sat thuong len " << danhsach_NV[x]->getName() << endl;
                    danhsach_NV[x]->setHp(n);
                    cout << "So mau con lai cua " << danhsach_NV[x]->getName() << " la " << danhsach_NV[x]->getHp() << endl << endl;
                    if (danhsach_NV[x]->getHp() <= 0)
                    {
                        cout << danhsach_NV[y]->getName() << " da ha guc " << danhsach_NV[x]->getName() << endl;
                        cout << danhsach_NV[y]->getName() << " tang 10 diem do sat.\n";
                        danhsach_NV[y]->setKill_points(10);
                        cout << "Diem do sat hien tai la: " << danhsach_NV[y]->getKill_points() << endl;
                    }
                    if (danhsach_NV[y]->getHp() <= 0)
                    {
                        cout << danhsach_NV[x]->getName() << " da ha guc " << danhsach_NV[y]->getName() << endl;
                        cout << danhsach_NV[x]->getName() << " tang 10 diem do sat.\n";
                        danhsach_NV[x]->setKill_points(10);
                        cout << "Diem do sat hien tai la: " << danhsach_NV[x]->getKill_points() << endl;

                    }
                    system("pause");

                }
                system("cls");
                danhsach_NV[x]->setST(temp1);
                danhsach_NV[y]->setST(temp2);
                do {
                    textcolor(7);
                    cout << "\t Chon 1 de tiep tuc tuong tac .\n";
                    textcolor(8);
                    cout << "\t Chon 2 de thoat.\n";
                    textcolor(15);
                    cout << "Chon: ";
                    cin >> CatchKey;
                } while (CatchKey != 1 && CatchKey != 2);
                if (CatchKey == 1)
                {
                    system("cls");
                    xuat();
                    return QuanLy::tuongtac();
                }
                else if (CatchKey == 2)
                {
                    system("cls");
                    return;
                }
            }
        }
    }
}

void QuanLy::timSTLN()
{
    double max1 = 0;
    double max2 = 0;
    int index = 0;
    for (int i = 1; i <= temp1; i++)
    {
        if (max1 <= danhsach_NV[i]->getST())
        {
            max1 = danhsach_NV[i]->getST();
            index = i;
        }
    }
    cout << endl << endl;
    textcolor(47);
    cout << "Nhan vat co sat thuong lon nhat la nhan vat thu " << index  << " voi sat thuong la: " << max1 << endl;
    index = 0;
    for (int i = 1; i <= temp2; i++)
    {
        if (max2 <= danhsach_QV[i]->getST())
        {
            max2 = danhsach_QV[i]->getST();
            index = i;
        }
    }
    cout << endl << endl;
    textcolor(31);
    cout << "Quai vat co sat thuong lon nhat la quai vat thu " << index << " voi sat thuong la: " << max2 << endl << endl;
}
