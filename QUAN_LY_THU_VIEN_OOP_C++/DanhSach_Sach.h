#pragma once
#include<vector>
#include"Sach.h"
#include<algorithm>

class DanhSach_Sach
{
private:
	vector<Sach*> list;
public:
	DanhSach_Sach();

	bool laMaSach(string ma);
	bool conSach(string ma);

	void setDsSach(vector<Sach*>);	
	Sach* getSach(int index);
	int getSize();

	void hienthiDSSach();
	void themSach(string ma, string theloai);
	void xoaSach();
	void suaTTSach(string theloai);
	void Tim_Kiem_Sach_Theo_Ten();
	void Tim_Kiem_Sach_Theo_Ma();
	void Tim_Kiem_Sach_Theo_TacGia();

	friend bool soSanhTL(Sach* sach1, Sach* sach2);
	friend bool soSanhTG(Sach* sach1, Sach* sach2);
	void Sap_Xep_Sach_Theo_TheLoai();
	void Sap_Xep_Sach_Theo_TenTacGia();

	~DanhSach_Sach();
};

