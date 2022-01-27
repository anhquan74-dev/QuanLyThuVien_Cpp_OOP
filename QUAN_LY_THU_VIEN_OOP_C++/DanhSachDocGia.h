#pragma once
#include"DocGia.h"
#include"DocGiaTreEm.h"
#include"DocGiaNguoiLon.h"
#include "XuLy.h"
#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
#include<string>
#include<algorithm>
using namespace std;

class DanhSachDocGia
{
private:
	vector<DocGia*> dsDocGia;
public:
	
	DanhSachDocGia();

	int getSize();
	DocGia* getDocGia(int);
	void setDSDocGia(vector<DocGia*>);
	void setDocGia(int index, DocGia* docgia);

	bool laMaDG(string maDG);
	
	void hienthiDSDocGia();
	void themDocGia();
	void xoaDocGia();
	void suaTTDocGia();
	void timkiemDocGiaTheoTen();
	void timkiemDocGiaTheoMa();

	friend bool soSanhTen(DocGia* dg1, DocGia* dg2);
	friend bool soSanhLoai(DocGia* dg1, DocGia* dg2);
	void Sap_Xep_Doc_Gia_Theo_Ten();
	void Sap_Xep_Doc_Gia_Theo_Loai();

	~DanhSachDocGia();
};

