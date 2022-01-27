#include "DanhSach_Sach.h"

DanhSach_Sach::DanhSach_Sach() {

}

void DanhSach_Sach::setDsSach(vector<Sach*> list) {
    this->list = list;
}

bool DanhSach_Sach::laMaSach(string ma) {
    for (int i = 0; i < list.size(); i++) {
        if (ma == list[i]->getMaSach()) {
            return true;
        }
    }
    return false;
}

bool DanhSach_Sach::conSach(string ma) {
    for (int i = 0; i < list.size(); i++) {
        if (ma == list[i]->getMaSach() && list[i]->getSoLuong() > 0) {
            return true;
        }
    }
    return false;
}

Sach* DanhSach_Sach::getSach(int index) {
    return list[index];
}

int DanhSach_Sach::getSize() {
    return list.size();
}



void DanhSach_Sach::hienthiDSSach() {
    if (list.size() > 0) {
        cout << "                                                            ======== DANH SACH SACH ========                                                                       " << endl;
        cout << "                                                                                                                                                                    " << endl;
        cout << "                                                                                                                                                                    " << endl;
        cout << left << setw(10) << "Ma Sach" << setw(30) << "Ten Sach" << setw(25) << "Tac gia"
            << setw(20) << "Nha Xuat Ban" << setw(15) << "Nam Xuat Ban" << setw(30) << "The Loai"
            << setw(15) << "Gia Sach" << setw(10) << "So Luong" << endl;
        cout << "---------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
        for (int i = 0; i < list.size(); i++) {
            list[i]->display();
        }
        cout << "---------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    }
    else {
        cout << "Danh sach trong." << endl;
    }
}

void DanhSach_Sach::themSach(string ma, string theloai) {
    char c;
    do
    {
        Sach* sach = new Sach;
        sach->input(ma, theloai);
        sach->ghiFile();
        list.push_back(sach);
        cout << "Da them Sach!" << endl;
        cout << "Ban co muon them sach khac? (y/n): ";
        cin >> c;
    } while (c != 'n');    
}

void DanhSach_Sach::xoaSach() {
    cout << "Nhap thong tin sach ban muon xoa: " << endl;
    cout << "Nhap ma sach: ";
    string ma;
    do {
        getline(cin, ma);
    } while (ma.length() == 0);

    int temp = -1;
    for (int i = 0; i < list.size(); i++) {
        if (list[i]->getMaSach() == ma) {
            temp = i;
            break;
        }
    }

    if (temp == -1) {
        cout << "Khong tim thay sach!" << endl;
    }
    else {
        cout << "Thong tin sach ban muon xoa la: " << endl;
        cout << left << setw(10) << "Ma Sach" << setw(30) << "Ten Sach" << setw(25) << "Tac gia"
            << setw(20) << "Nha Xuat Ban" << setw(15) << "Nam Xuat Ban" << setw(30) << "The Loai"
            << setw(15) << "Gia Sach" << setw(10) << "So Luong" << endl;
        cout << "----------------------------------------------------------------------------------------------------------------------" << endl;
        list[temp]->display();
        cout << "Ban co muon xoa sach khong? (y/n): ";
        char choose;
        cin >> choose;
        if (choose == 'y') {
            list.erase(list.begin() + temp);
            cout << "Da xoa thong tin sach!" << endl;

            remove("QUAN_LY_SACH.txt");
            for (int i = 0; i < list.size(); i++) {
                list[i]->ghiFile();
            }
        }      
    }
    
}

void DanhSach_Sach::suaTTSach(string theloai) {
    cout << "Nhap thong tin sach ban muon chinh sua: " << endl;
    cout << "Nhap ma sach: ";
    string ma;
    do {
        getline(cin, ma);       
    } while (ma.length() == 0);

    if (!laMaSach(ma)) {
        cout << "Ma khong ton tai!" << endl;
    }
    else {
        cout << "Thong tin sach can chinh sua" << endl;
        cout << left << setw(10) << "Ma Sach" << setw(30) << "Ten Sach" << setw(25) << "Tac gia"
            << setw(20) << "Nha Xuat Ban" << setw(15) << "Nam Xuat Ban" << setw(30) << "The Loai"
            << setw(15) << "Gia Sach" << setw(10) << "So Luong" << endl;
        cout << "------------------------------------------------------------------------------------------------------------------------------------------" << endl;

        int flag = -1;
        for (int i = 0; i < list.size(); i++) {
            if (list[i]->getMaSach() == ma) {
                flag = i;
                break;
            }
        }

        list[flag]->display();

        cout << "------Moi ban chinh sua thong tin------" << endl;
        list[flag]->input(ma, theloai);

        cout << "Da sua!" << endl;

        remove("QUAN_LY_SACH.txt");
        for (int i = 0; i < list.size(); i++) {
            list[i]->ghiFile();
        }
    }
    
}

void DanhSach_Sach::Tim_Kiem_Sach_Theo_Ten() {
    cout << "Nhap ten sach can tim: ";
    string name;

    do {
        getline(cin, name);
    } while (name.length() == 0);

    int flag = -1;
    
    for (int i = 0; i < list.size(); i++) {
        string ten = list[i]->getTenSach();
        if (laChuoiCon(ten, name)) {
            flag = i;
        }
    }

    if (flag == -1) {
        cout << "Khong co sach nao!" << endl;
    }
    else {
        cout << "Sach can tim la: " << endl;
        cout << left << setw(10) << "Ma Sach" << setw(30) << "Ten Sach" << setw(25) << "Tac gia"
            << setw(20) << "Nha Xuat Ban" << setw(15) << "Nam Xuat Ban" << setw(30) << "The Loai"
            << setw(15) << "Gia Sach" << setw(10) << "So Luong" << endl;
        cout << "----------------------------------------------------------------------------------------------------------------------" << endl;
        list[flag]->display();
    }
}

void DanhSach_Sach::Tim_Kiem_Sach_Theo_Ma() {
    cout << "Nhap ma sach can tim: ";
    string ma;
    do {
        getline(cin, ma);
    } while (ma.length() == 0);

    int flag = -1;
    
    for (int i = 0; i < list.size(); i++) {
        if (list[i]->getMaSach() == ma) {

            flag = i;
            break;
        }
    }

    if (flag == -1) {
        cout << "Khong co sach nao!" << endl;
    }
    else {
        cout << "Sach can tim la: " << endl;
        cout << left << setw(10) << "Ma Sach" << setw(30) << "Ten Sach" << setw(25) << "Tac gia"
            << setw(20) << "Nha Xuat Ban" << setw(15) << "Nam Xuat Ban" << setw(30) << "The Loai"
            << setw(15) << "Gia Sach" << setw(10) << "So Luong" << endl;
        cout << "----------------------------------------------------------------------------------------------------------------------" << endl;
        list[flag]->display();
    }
}

void DanhSach_Sach::Tim_Kiem_Sach_Theo_TacGia() {
    cout << "Nhap ten tac gia can tim: ";
    string name;
    do {
        getline(cin, name);
    } while (name.length() == 0);

    int flag = -1;
    
    for (int i = 0; i < list.size(); i++) {
        string ten = list[i]->getTacGia();
        if (laChuoiCon(ten, name)) {
            flag = i;
        }
    }

    if (flag == -1) {
        cout << "Khong co doc gia nao!" << endl;
    }
    else {
        cout << "Sach can tim la: " << endl;
        cout << left << setw(10) << "Ma Sach" << setw(30) << "Ten Sach" << setw(25) << "Tac gia"
            << setw(20) << "Nha Xuat Ban" << setw(15) << "Nam Xuat Ban" << setw(30) << "The Loai"
            << setw(15) << "Gia Sach" << setw(10) << "So Luong" << endl;
        cout << "----------------------------------------------------------------------------------------------------------------------" << endl;
        list[flag]->display();
    }
}

bool soSanhTL(Sach* sach1, Sach* sach2) {
    return sach1->getTheLoai() < sach2->getTheLoai();
}

void DanhSach_Sach::Sap_Xep_Sach_Theo_TheLoai() {
    sort(list.begin(), list.end(), soSanhTL);
    
    remove("QUAN_LY_SACH.txt");
    for (int i = 0; i < list.size(); i++) {
        list[i]->ghiFile();
    }
    cout << "Da sap xep!" << endl;
}

bool soSanhTG(Sach* sach1, Sach* sach2) {
    return So_Sanh_Chuoi(sach1->getTacGia(), sach2->getTacGia()) < 0;
}

void DanhSach_Sach::Sap_Xep_Sach_Theo_TenTacGia() {
    sort(list.begin(), list.end(), soSanhTG);
    
    remove("QUAN_LY_SACH.txt");
    for (int i = 0; i < list.size(); i++) {
        list[i]->ghiFile();
    }
    cout << "Da sap xep!" << endl;
}



DanhSach_Sach::~DanhSach_Sach() {

}