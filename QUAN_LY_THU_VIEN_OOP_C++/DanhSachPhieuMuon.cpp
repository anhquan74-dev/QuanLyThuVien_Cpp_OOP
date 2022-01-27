#include "DanhSachPhieuMuon.h"

DanhSachPhieuMuon::DanhSachPhieuMuon() {

}

void DanhSachPhieuMuon::setDsPhieuMuon(vector<PhieuMuon> dsPhieuMuon) {
    list = dsPhieuMuon;
}

bool DanhSachPhieuMuon::Kiem_Tra_Muon_Sach(string ma) {
    for (int i = 0; i < list.size(); i++) {
        if (list[i].getMaDocGia() == ma) {
            return true;
        }
    }
    return false;
}

bool DanhSachPhieuMuon::La_Sach_Da_Muon(DocGia* docgia, string ma) {
    int temp = 0;
    for (int i = 0; i < list.size(); i++) {
        if (list[i].getMaDocGia() == docgia->getMaDG()) {
            temp = i;
            break;
        }
    }
    
    for (int i = 0; i < list[temp].getSoLuongSach(); i++) {
        if (list[temp].getMaSach(i) == ma) {
            return true;
        }
    }

    return false;
}

int DanhSachPhieuMuon::getSize() {
    return list.size();
}

PhieuMuon DanhSachPhieuMuon::getPhieuMuon(int index) {
    return list[index];
}

void DanhSachPhieuMuon::Xoa_Phieu_Muon(DocGia* docgia) {
    int tmp = 0;
    for (int i = 0; i < list.size(); i++) {
        if (docgia->getMaDG() == list[i].getMaDocGia()) {
            tmp = i;
            break;
        }
    }

    list.erase(list.begin() + tmp);
    remove("QUAN_LY_PHIEU_MUON.txt");
    for (int i = 0; i < list.size(); i++) {
        list[i].ghiFile();
    }
}



void DanhSachPhieuMuon::hienthiDanhSach() {
    if (list.size() > 0) {
        cout << "                                    ======== DANH SACH PHIEU MUON ========" << endl;
        cout <<  endl;
        cout << left << setw(15) << "Ma doc gia"<< setw(25) << "Ten doc gia" << setw(20) << "Ngay muon sach"
            << setw(20) << "Ngay du kien tra" << setw(15) << "Ma Sach Muon" << setw(25) << "Ten sach" << setw(10) << "So Luong" << endl;
        cout << "=================================================================================================================================" << endl;
        for (int i = 0; i < list.size(); i++) {
            list[i].display();
            cout << "---------------------------------------------------------------------------------------------------------------------------------" << endl;
        }
    }
    else {
        cout << "Danh sach trong." << endl;
    }
}

void DanhSachPhieuMuon::themPhieuMuon(PhieuMuon phieumuon) {
	list.push_back(phieumuon);
    phieumuon.ghiFile();
}

bool DanhSachPhieuMuon::chuaTraSach(string maDocGia) {
	for (int i = 0; i < list.size(); i++) {
		if (maDocGia == list[i].getMaDocGia()) {
			return true;
		}
	}
	return false;
}

DanhSachPhieuMuon::~DanhSachPhieuMuon() {

}