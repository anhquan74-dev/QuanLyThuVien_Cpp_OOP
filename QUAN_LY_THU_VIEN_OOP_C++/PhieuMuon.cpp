#include "PhieuMuon.h"

PhieuMuon::PhieuMuon() {

}

PhieuMuon::PhieuMuon(DocGia* docgia, Sach* sach, int soLuongSach, Date ngayMuon, Date ngayTraDuKien) {
	this->docgia = docgia;
	this->sach = sach;
	this->soLuongSach = soLuongSach;
	this->ngayMuon = ngayMuon;
	this->ngayTraDuKien = ngayTraDuKien;
}

string PhieuMuon::getMaDocGia() {
	return docgia->getMaDG();
}

Date PhieuMuon::getNgayMuon() {
	return ngayMuon;
}

string PhieuMuon::getMaSach(int index) {
	return (sach + index)->getMaSach();
}

int PhieuMuon::getSoLuongSach() {
	return soLuongSach;
}

void PhieuMuon::ghiFile() {
	ofstream fo("QUAN_LY_PHIEU_MUON.txt", ios::app);
	fo << docgia->getMaDG() << endl;
	fo << soLuongSach << endl;
	for (int i = 0; i < soLuongSach; i++) {
		fo << (sach+i)->getMaSach() << endl;
	}
	for (int i = 0; i < soLuongSach; i++) {
		fo << (sach + i)->getTenSach() << endl;
	}
	fo << ngayMuon.writeInFile() << endl;
	fo << ngayTraDuKien.writeInFile() << endl;
	fo.close();
}

void PhieuMuon::inPhieuMuon() {
	ofstream fo("PHIEU_MUON.pdf", ios::out);
	fo << "---------------------------- THONG TIN PHIEU MUON SACH---------------------------" << endl;
	docgia->inPDF(fo);
	fo << left << setw(30) << "|\t\t- Danh sach sach duoc muon: " << setw(25) << " " << "\t\t|" << endl;
	for (int i = 0; i < soLuongSach; i++) {
		fo << left << setw(20) << "|" << i + 1 << ". " << setw(57) << sach[i].getTenSach() << "|" << endl;
	}
	fo << left << setw(30) << "|\t\t- Ngay muon: " << setw(25) << ngayMuon.displayFromFile() << "\t\t|" << endl;
	fo << left << setw(30) << "|\t\t- Ngay tra du kien: " << setw(25) << ngayTraDuKien.displayFromFile() << "\t\t|" << endl;
	fo << "---------------------------------------------------------------------------------" << endl;
	fo.close();
}

void PhieuMuon::docFile(ifstream& fi, DanhSachDocGia &dsDocGia) {

	string maDG;
	do {
		getline(fi, maDG);
	} while (maDG.length() == 0);

	if (maDG[0] == 'T' && maDG[1] == 'E') {
		docgia = new DocGiaTreEm;
		for (int i = 0; i < dsDocGia.getSize(); i++) {
			if (dsDocGia.getDocGia(i)->getMaDG() == maDG) {
				docgia = dsDocGia.getDocGia(i);
			}
		}

	}
	else {
		docgia = new DocGiaNguoiLon;
		for (int i = 0; i < dsDocGia.getSize(); i++) {
			if (dsDocGia.getDocGia(i)->getMaDG() == maDG) {
				docgia = dsDocGia.getDocGia(i);
			}
		}
	}
	
	fi >> soLuongSach;

	string maSach;
	getline(fi, maSach);
	Sach* s = new Sach[soLuongSach];
	for (int i = 0; i < soLuongSach; i++) {
		getline(fi, maSach);
		(s+i)->setMaSach(maSach);
	}
	string tenSach;
	for (int i = 0; i < soLuongSach; i++) {
		getline(fi, tenSach);
		(s + i)->setTenSach(tenSach);
	}
	sach = s;

	string ngay;
	getline(fi, ngay, ' ');
	int ngayInt = stoi(ngay);
	ngayMuon.setDay(ngayInt);

	string thang;
	getline(fi, thang, ' ');
	int thangInt = stoi(thang);
	ngayMuon.setMonth(thangInt);

	string nam;
	getline(fi, nam);
	int namInt = stoi(nam);
	ngayMuon.setYear(namInt);


	string ngayTraDK;
	getline(fi, ngayTraDK, ' ');
	int ngayTraDKInt = stoi(ngayTraDK);
	ngayTraDuKien.setDay(ngayTraDKInt);


	string thangTraDK;
	getline(fi, thangTraDK, ' ');
	int thangTraDKInt = stoi(thangTraDK);
	ngayTraDuKien.setMonth(thangTraDKInt);

	string namTraDK;
	getline(fi, namTraDK);
	int namTraDKInt = stoi(namTraDK);
	ngayTraDuKien.setYear(namTraDKInt);

}

void PhieuMuon::displayVertical() {
	cout << "---------------------------- THONG TIN PHIEU MUON SACH---------------------------" << endl;
	docgia->displayVertical();
	cout << left << setw(30) << "|\t\t- Danh sach sach duoc muon: " << setw(25) << " " << "\t\t|" << endl;
	for (int i = 0; i < soLuongSach; i++) {
		cout << left << setw(20) << "|" << i + 1 << ". " << setw(57) << sach[i].getTenSach() << "|" << endl;
	}
	cout << left << setw(30) << "|\t\t- Ngay muon: " << setw(25) << ngayMuon.displayFromFile() << "\t\t|" << endl;
	cout << left << setw(30) << "|\t\t- Ngay tra du kien: " << setw(25) << ngayTraDuKien.displayFromFile() << "\t\t|" << endl;
	cout << "---------------------------------------------------------------------------------" << endl;
}

void PhieuMuon::display() {
	cout << left << setw(15) << docgia->getMaDG() << setw(25) << docgia->getHoTen() << setw(20) << ngayMuon.displayFromFile()
		<< setw(20) << ngayTraDuKien.displayFromFile() << endl;
	for (int i = 0; i < soLuongSach; i++) {
		cout << left << setw(80) << " " << setw(15) << (sach+i)->getMaSach() << setw(25) << (sach+i)->getTenSach() << setw(10) << "1" << endl;
	}
	cout << left << setw(120) << " " << setw(10) << "Tong SL: " << endl;
	cout << left << setw(120) << " " << setw(10) << soLuongSach << endl;
}

PhieuMuon::~PhieuMuon() {

}