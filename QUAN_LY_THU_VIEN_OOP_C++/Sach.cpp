#include "Sach.h"

Sach::Sach() {

}

void Sach::setMaSach(string maSach) {
    this->maSach = maSach;
}
void Sach::setTenSach(string tenSach) {
    this->tenSach = tenSach;
}
void Sach::setTacGia(string tacGia) {
    this->tacGia = tacGia;
}

void Sach::setTheLoai(string theLoai) {
    this->theLoai = theLoai;
}

void Sach::setSoLuong(int soLuong) {
    this->soLuong = soLuong;
}
void Sach::setGiaSach(int giaSach) {
    this->giaSach = giaSach;
}

string Sach::getMaSach() {
    return maSach;
}
string Sach::getTenSach() {
    return tenSach;
}
string Sach::getTacGia() {
    return tacGia;
}


string Sach::getTheLoai() {
    return theLoai;
}

int Sach::getSoLuong() {
    return soLuong;
}
int Sach::getGiaSach() {
    return giaSach;
}


void Sach::input(string ma, string theloai) {

    this->maSach = ma;
    this->theLoai = theloai;

    cout << "Nhap Ten Sach: ";
    do {
        getline(cin, tenSach);
        if (!La_Chuoi_Chuan_Khong_Chua_So(tenSach) || tenSach.length() == 0) {
            cout << "Nhap sai! Moi nhap lai: ";
        }
    } while (!La_Chuoi_Chuan_Khong_Chua_So(tenSach) || tenSach.length() == 0);
    tenSach = format_Chuoi(tenSach);

    cout << "Nhap Ten Tac Gia: ";
    do {
        getline(cin, tacGia);
        if (!La_Chuoi_Chuan_Khong_Chua_So(tacGia) || tacGia.length() == 0) {
            cout << "Nhap sai! Moi nhap lai: ";
        }
    } while (!La_Chuoi_Chuan_Khong_Chua_So(tacGia) || tacGia.length() == 0);
    tacGia = format_Chuoi(tacGia);

    cout << "Nhap Nha Xuat Ban: ";
    do {
        getline(cin, nhaXuatBan);
        if (!La_Chuoi_Chuan_Khong_Chua_So(nhaXuatBan) || nhaXuatBan.length() == 0) {
            cout << "Nhap sai! Moi nhap lai: ";
        }
    } while (!La_Chuoi_Chuan_Khong_Chua_So(nhaXuatBan) || nhaXuatBan.length() == 0);
    nhaXuatBan = format_Chuoi(nhaXuatBan);

    cout << "Nhap Nam Xuat Ban: ";
    string namString;
    do
    {
        getline(cin, namString);
        if (!La_So_Nguyen(namString) || stoi(namString) <= 0) {
            cout << "Nhap sai! Moi nhap lai: ";
        }
    } while (!La_So_Nguyen(namString) || stoi(namString) <= 0);
    namXuatBan = stoi(namString);



    cout << "Nhap Gia Sach: ";
    string giaString;
    do
    {
        getline(cin, giaString);
        if (!La_So_Nguyen(giaString) || stoi(giaString) <= 0) {
            cout << "Nhap sai! Moi nhap lai: ";
        }
    } while (!La_So_Nguyen(giaString) || stoi(giaString) <= 0);
    giaSach = stoi(giaString);

    cout << "Nhap So Luong: ";
    string soluongString;
    do
    {
        getline(cin, soluongString);
        if (!La_So_Nguyen(soluongString) || stoi(soluongString) <= 0) {
            cout << "Nhap sai! Moi nhap lai: ";
        }
    } while (!La_So_Nguyen(soluongString) || stoi(soluongString) <= 0);
    soLuong = stoi(soluongString);
}

void Sach::display() { 
    cout << left << setw(10) << maSach << setw(30) << tenSach << setw(25) << tacGia
        << setw(20) << nhaXuatBan << setw(15) << namXuatBan << setw(30) << theLoai
        << setw(15) << giaSach << setw(10) << soLuong << endl;
}

void Sach::ghiFile() {
    ofstream fo("QUAN_LY_SACH.txt", ios::app);
    fo << maSach << endl;
    fo << tenSach << endl;
    fo << tacGia << endl;
    fo << nhaXuatBan << endl;
    fo << namXuatBan << endl;
    fo << theLoai << endl;
    fo << giaSach << endl;
    fo << soLuong << endl;
    fo.close();
}

void Sach::docFile(ifstream& fi) {
    do {
        getline(fi, maSach);
    } while (maSach.length() == 0);
    getline(fi, tenSach);
    getline(fi, tacGia);
    getline(fi, nhaXuatBan); 
    fi >> namXuatBan;
    do {
        getline(fi, theLoai);
    } while (theLoai.length() == 0);
    fi >> giaSach;
    fi >> soLuong;
}

Sach::~Sach() {

}