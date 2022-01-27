#pragma once
#include"PhieuMuon.h"
#include<vector>
class DanhSachPhieuMuon
{
private:
	vector<PhieuMuon> list;
public:

	DanhSachPhieuMuon();

	bool chuaTraSach(string maDocGia);
	bool Kiem_Tra_Muon_Sach(string ma);
	bool La_Sach_Da_Muon(DocGia* docgia, string ma);

	void setDsPhieuMuon(vector<PhieuMuon>);
	int getSize();
	PhieuMuon getPhieuMuon(int index);

	void hienthiDanhSach();
	void themPhieuMuon(PhieuMuon phieumuon);
	void Xoa_Phieu_Muon(DocGia* docgia);
	

	~DanhSachPhieuMuon();
};

