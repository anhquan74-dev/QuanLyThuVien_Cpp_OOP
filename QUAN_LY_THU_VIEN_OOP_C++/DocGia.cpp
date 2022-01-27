#include "DocGia.h"

DocGia::DocGia() {

}


string DocGia::getGioiTinh() {
	return gioiTinh;
}

string DocGia::getHoTen() {
	return hoTen;
}


char DocGia::getFirstCharMaDG() {
	return maDG[0];
}


void DocGia::input() {

	cout << "- Nhap ho va ten:\t   ";

	string HoTen;
	cin.seekg(0, ios::end);
	cin.clear();

	do {
		getline(cin, HoTen);
		if (!La_Chuoi_Chuan_Khong_Chua_So(HoTen) || HoTen.length() == 0) {
			cout << "-> Ten khong hop le! Moi ban nhap lai: ";
		}
	} while (HoTen.length() == 0 || !La_Chuoi_Chuan_Khong_Chua_So(HoTen));

	hoTen = format_Chuoi(HoTen);


	cout << "- Nhap ngay sinh: \n";
	ngaySinh.input();


	cout << "- Nhap gioi tinh:\t   ";
	cin.seekg(0, ios::end);
	cin.clear();
	do {
		getline(cin, gioiTinh);
		if (!La_Gioi_Tinh(gioiTinh) || gioiTinh.length() == 0) {
			cout << "-> Gioi tinh khong hop le! Moi ban nhap lai: ";
		}
	} while (gioiTinh.length() == 0 || !La_Gioi_Tinh(gioiTinh));
	gioiTinh = format_Chuoi(gioiTinh);

	cout << "- Nhap dia chi:\t\t   ";
	do
	{
		getline(cin, diaChi);
		if (diaChi.length() == 0) {
			cout << "-> Nhap sai! Moi ban nhap lai: ";
		}
	} while (diaChi.length() == 0);


	cout << "- Nhap so dien thoai:\t   ";
	do
	{
		getline(cin, soDT);
		if (!La_So_Dien_Thoai(soDT) || soDT.length() == 0) {
			cout << "-> So dien thoai la so (gom 10 chu so)! Moi ban nhap lai: ";
		}
	} while (!La_So_Dien_Thoai(soDT) || soDT.length() == 0);

	cout << "- Nhap ngay lap the:\t   \n";
	ngayLapThe.input();

	cout << "- Nhap so thang hieu luc:  ";
	cin.seekg(0, ios::end);
	cin.clear();
	string thang;
	do
	{
		getline(cin, thang);
		if (!La_So_Nguyen(thang) || stoi(thang) <= 0 || stoi(thang) > 24) {
			cout << "-> Thang hieu luc <= 24! Moi ban nhap lai: ";
		}
	} while (!La_So_Nguyen(thang) || stoi(thang) <= 0 || stoi(thang) > 24);
	thangHieuLuc = stoi(thang);
}


DocGia::~DocGia() {

}