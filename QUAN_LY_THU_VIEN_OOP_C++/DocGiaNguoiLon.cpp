#include "DocGiaNguoiLon.h"
#include<iomanip>

DocGiaNguoiLon::DocGiaNguoiLon() {

}

string DocGiaNguoiLon::getMaDG() {
	return maDG;
}

void DocGiaNguoiLon::setMaDG(string ma) {
	maDG = ma;
}

void DocGiaNguoiLon::input() {
	cout << "- Nhap ma doc gia:\t   ";
	cin.seekg(0, ios::end);
	cin.clear();
	do
	{
		getline(cin, maDG);
		if (maDG.substr(0, 2) != "NL" || maDG.length() == 0) {
			cout << "-> Ma doc gia bat dau bang hai ky tu NL! Moi ban nhap lai: ";
		}
	} while (maDG.substr(0, 2) != "NL" || maDG.length() == 0);

	DocGia::input();

	cout << "- Nhap so CMND:\t\t   ";
	do
	{
		getline(cin, soCMND);
		if (!La_CMND(soCMND) || soCMND.length() == 0) {
			cout << "-> CMND phai bao gom 9 chu so! Moi ban nhap lai: ";
		}
	} while (!La_CMND(soCMND) || soCMND.length() == 0);
}

void DocGiaNguoiLon::display() {
	cout << left << setw(10) << maDG << setw(20) << hoTen;
	cout << setw(15) << ngaySinh.displayFromFile();
	cout << setw(12) << gioiTinh << setw(11) << diaChi << setw(15) << soDT;
	cout << setw(15) << ngayLapThe.displayFromFile();
	cout << setw(18) << thangHieuLuc;
	cout << setw(20) << "X" << setw(15) << soCMND << setw(20) << Tien_Lam_The() << endl;
}

void DocGiaNguoiLon::displayVertical() {
	cout << left << setw(30) << "|\t\t- Ma doc gia: " << setw(25) << maDG << "\t\t|" << endl;
	cout << left << setw(30) << "|\t\t- Ho va ten: " << setw(25) << hoTen << "\t\t|" << endl;
	cout << left << setw(30) << "|\t\t- Ngay sinh: " << setw(25) << ngaySinh.displayFromFile() << "\t\t|" << endl;
	cout << left << setw(30) << "|\t\t- Gioi tinh: " << setw(25) << gioiTinh << "\t\t|" << endl;
	cout << left << setw(30) << "|\t\t- Dia chi: " << setw(25) << diaChi << "\t\t|" << endl;
	cout << left << setw(30) << "|\t\t- So dien thoai: " << setw(25) << soDT << "\t\t|" << endl;
	cout << left << setw(30) << "|\t\t- Ngay lap the: " << setw(25) << ngayLapThe.displayFromFile() << "\t\t|" << endl;
	cout << left << setw(30) << "|\t\t- Thang hieu luc: " << setw(25) << thangHieuLuc << "\t\t|" << endl;
	cout << left << setw(30) << "|\t\t- CMND: " << setw(25) << soCMND << "\t\t|" << endl;
	cout << left << setw(30) << "|\t\t- Tien lam the: " << setw(25) << Tien_Lam_The() << "\t\t|" << endl;
}

int DocGiaNguoiLon::Tien_Lam_The() {
	return thangHieuLuc * 10000;
}

void DocGiaNguoiLon::ghiDG() {
	ofstream ofs("QUAN_LY_DOC_GIA.txt", ios::app);
	ofs << maDG << endl;
	ofs << hoTen << endl;
	ofs << ngaySinh.writeInFile() << endl;
	ofs << gioiTinh << endl;
	ofs << diaChi << endl;
	ofs << soDT << endl;
	ofs << ngayLapThe.writeInFile() << endl;
	ofs << thangHieuLuc << endl;
	ofs << soCMND << endl;
	ofs.close();
}

void DocGiaNguoiLon::inPDF(ofstream& fo) {
	fo << left << setw(30) << "|\t\t- Ma doc gia: " << setw(25) << maDG << "\t\t|" << endl;
	fo << left << setw(30) << "|\t\t- Ho va ten: " << setw(25) << hoTen << "\t\t|" << endl;
	fo << left << setw(30) << "|\t\t- Ngay sinh: " << setw(25) << ngaySinh.displayFromFile() << "\t\t|" << endl;
	fo << left << setw(30) << "|\t\t- Gioi tinh: " << setw(25) << gioiTinh << "\t\t|" << endl;
	fo << left << setw(30) << "|\t\t- Dia chi: " << setw(25) << diaChi << "\t\t|" << endl;
	fo << left << setw(30) << "|\t\t- So dien thoai: " << setw(25) << soDT << "\t\t|" << endl;
	fo << left << setw(30) << "|\t\t- Ngay lap the: " << setw(25) << ngayLapThe.displayFromFile() << "\t\t|" << endl;
	fo << left << setw(30) << "|\t\t- Thang hieu luc: " << setw(25) << thangHieuLuc << "\t\t|" << endl;
	fo << left << setw(30) << "|\t\t- CMND: " << setw(25) << soCMND << "\t\t|" << endl;
	fo << left << setw(30) << "|\t\t- Tien lam the: " << setw(25) << Tien_Lam_The() << "\t\t|" << endl;
}

void DocGiaNguoiLon::docDG(ifstream& ifs) {
	getline(ifs, maDG);
	getline(ifs, hoTen);

	string ngay;
	getline(ifs,ngay,' ');
	int ngayInt = stoi(ngay);
	ngaySinh.setDay(ngayInt);

	string thang;
	getline(ifs, thang, ' ');
	int thangInt = stoi(thang);
	ngaySinh.setMonth(thangInt);

	string nam;
	getline(ifs, nam);
	int namInt = stoi(nam);
	ngaySinh.setYear(namInt);

	getline(ifs, gioiTinh);

	getline(ifs, diaChi);
	getline(ifs, soDT);

	string ngayLT;
	getline(ifs, ngayLT, ' ');
	int ngayLTInt = stoi(ngayLT);
	ngayLapThe.setDay(ngayLTInt);


	string thangLT;
	getline(ifs, thangLT, ' ');
	int thangLTInt = stoi(thangLT);
	ngayLapThe.setMonth(thangLTInt);

	string namLT;
	getline(ifs, namLT);
	int namLTInt = stoi(namLT);
	ngayLapThe.setYear(namLTInt);

	ifs >> thangHieuLuc;

	getline(ifs, soCMND);
	getline(ifs, soCMND);

}

DocGiaNguoiLon::~DocGiaNguoiLon() {

}
