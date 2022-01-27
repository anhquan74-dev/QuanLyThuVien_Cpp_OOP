#pragma once
#include"DocGia.h"
#include"DocGiaTreEm.h"
#include"DocGiaNguoiLon.h"
#include"DanhSachDocGia.h"
#include"Sach.h"
#include<fstream>
#include<iomanip>

class PhieuMuon
{
private:
	DocGia* docgia;
	Sach* sach;
	int soLuongSach;
	Date ngayMuon;
	Date ngayTraDuKien;
public:
	PhieuMuon();
	PhieuMuon(DocGia* docgia, Sach* sach, int soLuongSach, Date ngayMuon, Date ngayTraDuKien);

	string getMaDocGia();
	Date getNgayMuon();
	int getSoLuongSach();
	string getMaSach(int index);

	void ghiFile();
	void inPhieuMuon();
	void docFile(ifstream& fi, DanhSachDocGia& dsDocGia);

	void displayVertical();
	void display();

	~PhieuMuon();
};

