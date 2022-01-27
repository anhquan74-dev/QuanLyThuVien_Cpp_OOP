#pragma once
#include"DocGia.h"
#include"Sach.h"
class PhieuTra
{
private:
	DocGia* docgia;
	Sach* sach;
	int soLuongSach;
	Date ngayTraThucTe;
	int soSachBiMat;
public:
	PhieuTra();
	void input();
	void display();
	~PhieuTra();
};

