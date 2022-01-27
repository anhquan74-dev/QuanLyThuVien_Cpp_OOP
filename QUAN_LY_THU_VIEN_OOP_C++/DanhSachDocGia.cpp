#include "DanhSachDocGia.h"

DanhSachDocGia::DanhSachDocGia() {

}

int DanhSachDocGia::getSize() {
    return dsDocGia.size();
}

void DanhSachDocGia::setDSDocGia(vector<DocGia*> list) {
    dsDocGia = list;
}

DocGia* DanhSachDocGia::getDocGia(int index) {
	return dsDocGia[index];
}

void DanhSachDocGia::setDocGia(int index, DocGia* docgia) {
	dsDocGia[index] = docgia;
}


void DanhSachDocGia::hienthiDSDocGia() {
    if (dsDocGia.size() > 0) {
        cout << "                                                          ======== DANH SACH DOC GIA ========                                                                       " << endl;
        cout << "                                                                                                                                                                    " << endl;
        cout << "                                                                                                                                                                    " << endl;
        cout << left << setw(10) << "Ma DG" << setw(20) << "Ho Ten" << setw(15);
        cout << "Ngay sinh" << setw(12) << "Gioi tinh" << setw(11) << "Dia chi" << setw(15) << "So DT" << setw(15);
        cout << "Ngay lap the" << setw(18) << "Thang hieu luc" << setw(20) << "Nguoi dai dien" << setw(15) << "CMND" << setw(20) << "Tien lam the" << endl;
        cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
        for (int i = 0; i < dsDocGia.size(); i++) {
            dsDocGia[i]->display();
        }
        cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    }
    else {
        cout << "Danh sach trong." << endl;
    } 
}

void DanhSachDocGia::themDocGia() {
    char c;
    do {
        int choose1;
        cout << "--------------------------------- THEM DOC GIA ------------------------------------" << endl;
        cout << "Chon loai DOC GIA ban muon them [1]-DOC GIA TRE EM / [2]-DOC GIA NGUOI LON: ";
        cin >> choose1;
        if (choose1 == 1) {
            DocGia* docgiaTE = new DocGiaTreEm();
            docgiaTE->input();
            dsDocGia.push_back(docgiaTE);
            docgiaTE->ghiDG();
        }
        else {
            DocGia* docgiaNL = new DocGiaNguoiLon();
            docgiaNL->input();
            dsDocGia.push_back(docgiaNL);
            docgiaNL->ghiDG();
        }
        cout << "Da them doc gia vao danh sach!" << endl;
        cout << "Ban co muon them doc gia khac khong? [y/n] : ";
        cin >> c;
    } while (c == 'y');
    
}


void DanhSachDocGia::xoaDocGia() {
    cout << "--------------------------------- XOA DOC GIA ------------------------------------" << endl;
    cout << "Nhap thong tin doc gia ban muon xoa: " << endl;
    cin.seekg(0, ios::end);
    cin.clear();
    string maDG;
    do {
        cout << "Nhap ma doc gia: ";
        getline(cin, maDG);
    } while (maDG.length() == 0);
    

    if (laMaDG(maDG)) {
        cout << "                                               Thong tin doc gia ban muon xoa                                 " << endl;
        cout << endl;
        cout << left << setw(10) << "Ma DG" << setw(20) << "Ho Ten" << setw(15);
        cout << "Ngay sinh" << setw(12) << "Gioi tinh" << setw(11) << "Dia chi" << setw(15) << "So DT" << setw(15);
        cout << "Ngay lap the" << setw(18) << "Thang hieu luc" << setw(20) << "Nguoi dai dien" << setw(15) << "CMND" << setw(20) << "Tien lam the" << endl;
        cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
        int temp = -1;
        for (int i = 0; i < dsDocGia.size(); i++) {
            if (dsDocGia[i]->getMaDG() == maDG) {
                dsDocGia[i]->display();
                temp = i;
                break;
            }
        }
        cout << "Ban co muon xoa doc gia nay khong! (y/n): ";
        char c;
        cin >> c;
        if (c == 'y') {
            dsDocGia.erase(dsDocGia.begin() + temp);
            remove("QUAN_LY_DOC_GIA.txt");
            for (int i = 0; i < dsDocGia.size(); i++) {
                dsDocGia[i]->ghiDG();
            }
            cout << "Da xoa thong tin doc gia!" << endl;
        }
        
    }
    else {
        cout << "Khong tim thay doc gia" << endl;
    }
    
}


bool DanhSachDocGia::laMaDG(string maDG) {
    for (int i = 0; i < dsDocGia.size(); i++) {
        if (dsDocGia[i]->getMaDG() == maDG) {
            return true;
        }
    }
    return false;
}

void DanhSachDocGia::suaTTDocGia() {
    cout << "--------------------------------- SUA DOC GIA ------------------------------------" << endl;
    cout << "Nhap thong tin doc gia ban muon chinh sua: " << endl;
    cout << "Nhap ma doc gia: ";
    string maDG;
    cin.seekg(0, ios::end);
    cin.clear();
    do {
        getline(cin, maDG);
    } while (maDG.length() == 0);
    
    if (laMaDG(maDG)) {
        cout << "                                               Thong tin doc gia can chinh sua                                  " << endl;
        cout << endl;
        cout << left << setw(10) << "Ma DG" << setw(20) << "Ho Ten" << setw(15);
        cout << "Ngay sinh" << setw(12) << "Gioi tinh" << setw(11) << "Dia chi" << setw(15) << "So DT" << setw(15);
        cout << "Ngay lap the" << setw(18) << "Thang hieu luc" << setw(20) << "Nguoi dai dien" << setw(15) << "CMND" << setw(20) << "Tien lam the" << endl;
        cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
        int temp = -1;
        for (int i = 0; i < dsDocGia.size(); i++) {
            if (dsDocGia[i]->getMaDG() == maDG) {
                dsDocGia[i]->display();
                temp = i;
                break;
            }
        }

        dsDocGia[temp]->input();
        remove("QUAN_LY_DOC_GIA.txt");
        for (int i = 0; i < dsDocGia.size(); i++) {
            dsDocGia[i]->ghiDG();
        }
        cout << "Da sua!" << endl;
    }
    else {
        cout << "Ma doc gia khong ton tai!" << endl;
    }
}

void DanhSachDocGia::timkiemDocGiaTheoTen() {
    cout << "--------------------------------- TIM KIEM DOC GIA ------------------------------------" << endl;
    cout << "Nhap ten doc gia can tim: ";
    string name;
    do {
        getline(cin, name);
    } while (name.length() == 0);
    

    int flag = -1;
    
    for (int i = 0; i < dsDocGia.size(); i++) {
        string ten = dsDocGia[i]->getHoTen();
        if (laChuoiCon(ten, name)) {
            flag = i;
        }
    }

    if (flag == -1) {
        cout << "Khong co doc gia nao!" << endl;
    }
    else {
        cout << "Doc gia can tim la: " << endl;
        cout << "                                               Thong tin doc gia tim                                         " << endl;
        cout << endl; 
        cout << left << setw(10) << "Ma DG" << setw(20) << "Ho Ten" << setw(15);
        cout << "Ngay sinh" << setw(12) << "Gioi tinh" << setw(11) << "Dia chi" << setw(15) << "So DT" << setw(15);
        cout << "Ngay lap the" << setw(18) << "Thang hieu luc" << setw(20) << "Nguoi dai dien" << setw(15) << "CMND" << setw(20) << "Tien lam the" << endl;
        cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
        dsDocGia[flag]->display();
    }
}

void DanhSachDocGia::timkiemDocGiaTheoMa() {
    cout << "--------------------------------- TIM KIEM DOC GIA ------------------------------------" << endl;
    cout << "Nhap ma doc gia can tim: ";
    string ma;
    do {
        getline(cin, ma);
    } while (ma.length() == 0);

    int flag = -1;
    cout << "Doc gia can tim la: " << endl;
    for (int i = 0; i < dsDocGia.size(); i++) {
        if (dsDocGia[i]->getMaDG() == ma) {
            flag = i;
            break;
        }
    }

    if (flag == -1) {
        cout << "Khong tim thay doc gia" << endl;
    }
    else {
        cout << "                                               Thong tin doc gia can tim                                        " << endl;
        cout << endl;
        cout << left << setw(10) << "Ma DG" << setw(20) << "Ho Ten" << setw(15);
        cout << "Ngay sinh" << setw(12) << "Gioi tinh" << setw(11) << "Dia chi" << setw(15) << "So DT" << setw(15);
        cout << "Ngay lap the" << setw(18) << "Thang hieu luc" << setw(20) << "Nguoi dai dien" << setw(15) << "CMND" << setw(20) << "Tien lam the" << endl;
        cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
        dsDocGia[flag]->display();
    }

}

bool soSanhTen(DocGia* dg1, DocGia* dg2) {
    return So_Sanh_Chuoi(dg1->getHoTen(), dg2->getHoTen()) < 0;
}

bool soSanhLoai(DocGia* dg1, DocGia* dg2) {
    return dg1->getFirstCharMaDG() > dg2->getFirstCharMaDG();
}

void DanhSachDocGia::Sap_Xep_Doc_Gia_Theo_Ten() {
    sort(dsDocGia.begin(), dsDocGia.end(), soSanhTen);
   
    remove("QUAN_LY_DOC_GIA.txt");
    for (int i = 0; i < dsDocGia.size(); i++) {
        dsDocGia[i]->ghiDG();
    }
    cout << "Da sap xep!" << endl;
}

void DanhSachDocGia::Sap_Xep_Doc_Gia_Theo_Loai() {
    sort(dsDocGia.begin(), dsDocGia.end(), soSanhLoai); 

    remove("QUAN_LY_DOC_GIA.txt");
    for (int i = 0; i < dsDocGia.size(); i++) {
        dsDocGia[i]->ghiDG();
    }
    cout << "Da sap xep!" << endl;
}

DanhSachDocGia::~DanhSachDocGia() {

}