#pragma once
#include"DocGia.h"
#include<iostream>
#include<vector>
#include<algorithm>

class QuanLyDocGia
{
private:
	vector<DocGia*> dsDocGia;
public:
	QuanLyDocGia();
	void hienthiDSDocGia();
	void themDocGia(DocGia*);
	void xoaDocGia();
	void suaTTDocGia();
	void sapxepLoaiDocGIa();
	~QuanLyDocGia();
};

