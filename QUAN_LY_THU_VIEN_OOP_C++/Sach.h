#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include "XuLy.h"
using namespace std;

class Sach {
private:
    string maSach;
    string tenSach;
    string tacGia;
    string nhaXuatBan;
    string theLoai;
    int namXuatBan;
    int soLuong;
    int giaSach;
public:
    Sach();

    void setMaSach(string maSach);
    void setTenSach(string tenSach);
    void setTacGia(string tacGia);
    void setTheLoai(string theLoai);
    void setSoLuong(int soLuong);
    void setGiaSach(int giaSach);

    string getMaSach();
    string getTenSach();
    string getTacGia();
    string getTheLoai();
    int getSoLuong();
    int getGiaSach();


    void ghiFile();
    void docFile(ifstream&);

    void input(string ma, string theloai);
    void display();

    ~Sach();
};
