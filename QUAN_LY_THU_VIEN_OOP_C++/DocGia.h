#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<cstring>
#include"XuLy.h"
#include"Date.h"
using namespace std;

class DocGia
{
protected:
	string maDG;
	string hoTen;
	Date ngaySinh;
	string gioiTinh;
	string diaChi;
	string soDT;
	Date ngayLapThe;
	int thangHieuLuc;
public:
	DocGia();

	virtual string getMaDG() = 0;
	string getHoTen();
	string getGioiTinh();
	virtual void setMaDG(string ma) = 0;
	
	char getFirstCharMaDG();	
	
	virtual int Tien_Lam_The() = 0;

	virtual void input();
	virtual void display() = 0;
	virtual void displayVertical() = 0;

	virtual void ghiDG() = 0;
	virtual void inPDF(ofstream& fo) = 0;
	virtual void docDG(ifstream &ifs) = 0;

	~DocGia();
};

