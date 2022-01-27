#include"DanhSachDocGia.h"
#include"DocGia.h"
#include"DocGiaTreEm.h"
#include"DocGiaNguoiLon.h"
#include "Sach.h"
#include "DanhSach_Sach.h"
#include"DanhSachPhieuMuon.h"
#include <iostream>
#include<fstream>
#include<iomanip>
#include<ctime>
using namespace std;

vector<DocGia*> Doc_Tu_File_DocGia();
vector<Sach*> Doc_Tu_File_Sach();
vector<PhieuMuon> Doc_Tu_File_PhieuMuon(DanhSachDocGia &dsDocGia);
void Nhap_Thong_Tin_Sach(string maStr, string theloaiStr, DanhSach_Sach& dsSach);

int main()
{
    

    DanhSachDocGia dsDocGia;
    vector<DocGia*> listDG = Doc_Tu_File_DocGia();
    dsDocGia.setDSDocGia(listDG);

    DanhSach_Sach dsSach;
    vector<Sach*> listS = Doc_Tu_File_Sach();
    dsSach.setDsSach(listS);

    DanhSachPhieuMuon dsPhieuMuon;
    vector<PhieuMuon> listPM = Doc_Tu_File_PhieuMuon(dsDocGia);
    dsPhieuMuon.setDsPhieuMuon(listPM);

    int chucNangChinh;
    string s;
    char c;
    do {
        cout << "==============================================================" << endl;
        cout << "|                CHUONG TRINH QUAN LY THU VIEN               |" << endl;
        cout << "==============================================================" << endl;
        cout << "|    [1] Quan ly doc gia.                                    |" << endl;
        cout << "|    [2] Quan ly sach.                                       |" << endl;
        cout << "|    [3] Lap phieu muon sach.                                |" << endl;
        cout << "|    [4] Lap phieu tra sach.                                 |" << endl;
        cout << "|    [5] Cac thong ke co ban.                                |" << endl;
        cout << "|    [0] Thoat chuong trinh.                                 |" << endl;
        cout << "==============================================================" << endl;
        cout << "-> Enter your choice [0 -> 5] : ";
        do {
            getline(cin, s);
            if (s.length() != 1 || tolower(s[0]) < '0' || tolower(s[0]) > '5') {
                cout << "Error choice! Re-enter: ";
            }
        } while (s.length() != 1 || tolower(s[0]) < '0' || tolower(s[0]) > '5');
        chucNangChinh = stoi(s);
        switch (chucNangChinh) {
        case 1:
        {
            system("cls");
            int chucNangCon1;
            do {
                cout << "CHUC NANG QUAN LY DOC GIA" << endl;
                cout << "========================================" << endl;
                cout << "|   [1] Hien thi danh sach doc gia.    |" << endl;
                cout << "|   [2] Them doc gia.                  |" << endl;
                cout << "|   [3] Chinh sua thong tin doc gia.   |" << endl;
                cout << "|   [4] Xoa thong tin doc gia.         |" << endl;
                cout << "|   [5] Tim kiem doc gia.              |" << endl;
                cout << "|   [6] Sap xep thong tin doc gia.     |" << endl;
                cout << "|   [0] Tro ve menu chinh.             |" << endl;
                cout << "=======================================" << endl;
                cout << "-> Enter your choice [0 -> 6] : ";
                cin.seekg(0, ios::end);
                cin.clear();
                do {
                    getline(cin, s);
                    if (s.length() != 1 || s[0] < '0' || s[0] > '6') {
                        cout << "Error choice! Re-enter: ";
                    }
                } while (s.length() != 1 || s[0] < '0' || s[0] > '6');
                chucNangCon1 = stoi(s);
                switch (chucNangCon1) {
                case 1:
                {
                    system("cls");
                    dsDocGia.hienthiDSDocGia();
                    Xu_Ly_Tiep_Tuc(chucNangCon1, chucNangChinh);
                    break;
                }    
                case 2:
                {
                    dsDocGia.themDocGia();
                    Xu_Ly_Tiep_Tuc(chucNangCon1, chucNangChinh);
                    break;
                }  
                case 3:
                {
                    dsDocGia.suaTTDocGia();
                    Xu_Ly_Tiep_Tuc(chucNangCon1, chucNangChinh);
                    break;
                }  
                case 4:
                {
                    dsDocGia.xoaDocGia();
                    Xu_Ly_Tiep_Tuc(chucNangCon1, chucNangChinh);
                    break;
                }   
                case 5:
                {
                    system("cls");
                    int timkiemdocgia;
                    do
                    {
                        cout << "   -------------- TIM KIEM DOC GIA --------------" << endl;
                        cout << "   | [1] Tim kiem doc gia theo ten.             |" << endl;
                        cout << "   | [2] Tim kiem doc gia theo ma doc gia.      |" << endl;
                        cout << "   | [0] Tro ve.                                |" << endl;
                        cout << "   ----------------------------------------------" << endl;
                        cout << "   Enter your choice [0 -> 2]: ";
                        cin.seekg(0, ios::end);
                        cin.clear();
                        do {
                            getline(cin, s);
                            if (s.length() != 1 || s[0] < '0' || s[0] > '2') {
                                cout << "Error choice! Re-enter: ";
                            }     
                        } while (s.length() != 1 || s[0] < '0' || s[0] > '2');
                        timkiemdocgia = stoi(s);
                        switch (timkiemdocgia) {
                        case 1:
                        {
                            dsDocGia.timkiemDocGiaTheoTen();
                            Xu_Ly_Tiep_Tuc(chucNangCon1, chucNangChinh);
                            break;
                        }
                        case 2:
                        {
                            dsDocGia.timkiemDocGiaTheoMa();
                            Xu_Ly_Tiep_Tuc(chucNangCon1, chucNangChinh);
                            break;
                        }
                        default:
                            system("cls");
                            break;
                        }
                    }while (timkiemdocgia != 0);
                    
                    break;
                }     
                case 6:
                {
                    system("cls");
                    int sapxepdocgia;
                    do
                    {
                        cout << "   --------------- SAP XEP DOC GIA --------------" << endl;
                        cout << "   | [1] Sap xep theo loai doc gia.             |" << endl;
                        cout << "   | [2] Sap xep theo ten doc gia.              |" << endl;
                        cout << "   | [0] Tro ve.                                |" << endl;
                        cout << "   ----------------------------------------------" << endl;
                        cout << "   Enter your choice [0 -> 2]: ";
                        cin.seekg(0, ios::end);
                        cin.clear();
                        do {
                            getline(cin, s);
                            if (s.length() != 1 || s[0] < '0' || s[0] > '2') {
                                cout << "Error choice! Re-enter: ";
                            }      
                        } while (s.length() != 1 || s[0] < '0' || s[0] > '2');
                        sapxepdocgia = stoi(s);
                        switch (sapxepdocgia) {
                        case 1:
                        {
                            dsDocGia.Sap_Xep_Doc_Gia_Theo_Loai();
                            Xu_Ly_Tiep_Tuc(chucNangCon1, chucNangChinh);
                            break;
                        }
                        case 2:
                        {
                            dsDocGia.Sap_Xep_Doc_Gia_Theo_Ten();
                            Xu_Ly_Tiep_Tuc(chucNangCon1, chucNangChinh);
                            break;
                        }
                        default:
                            system("cls");
                            break;
                        }
                    } while (sapxepdocgia != 0);

                    break;
                }
                default:
                {
                    break;
                }
                }
            } while (chucNangCon1 != 0);
            system("cls");
            break;
        }
        case 2:
        {
            system("cls");
            int chucNangCon2;
            do {
                cout << "CHUC NANG QUAN LY SACH" << endl;
                cout << "====================================" << endl;
                cout << "|   [1] Hien thi danh sach sach.   |" << endl;
                cout << "|   [2] Them sach.                 |" << endl;
                cout << "|   [3] Chinh sua thong tin sach.  |" << endl;
                cout << "|   [4] Xoa thong tin sach.        |" << endl;
                cout << "|   [5] Tim kiem sach.             |" << endl;
                cout << "|   [6] Sap xep danh sach sach.    |" << endl;
                cout << "|   [0] Tro ve menu chinh.         |" << endl;
                cout << "====================================" << endl;
                cout << "-> Enter your choice [0 -> 6] : ";
                cin.seekg(0, ios::end);
                cin.clear();
                do {
                    getline(cin, s);
                    if (s.length() != 1 || s[0] < '0' || s[0] > '6') {
                        cout << "Error choice! Re-enter: ";
                    }
                } while (s.length() != 1 || s[0] < '0' || s[0] > '6');
                chucNangCon2 = stoi(s);
                switch (chucNangCon2) {
                case 1:
                {
                    system("cls");
                    dsSach.hienthiDSSach();
                    Xu_Ly_Tiep_Tuc(chucNangCon2, chucNangChinh);
                    break;
                }
                case 2:
                {
                    int themsach;
                    do
                    {
                        cout << "THEM SACH" << endl;
                        cout << "====================================" << endl;
                        cout << " [1] Ky nang song." << endl;
                        cout << " [2] Cong nghe thong tin." << endl;
                        cout << " [3] Truyen tranh." << endl;
                        cout << " [4] Van hoc Viet Nam." << endl;
                        cout << " [5] Am thuc - Nau an." << endl;
                        cout << " [6] Y hoc - Suc khoe." << endl;
                        cout << " [7] The thao - Nghe thuat." << endl;
                        cout << " [8] Hoc ngoai ngu." << endl;
                        cout << " [9] Triet hoc." << endl;
                        cout << " [10] Marketing - Ban hang." << endl;
                        cout << " [0] Tro ve." << endl;
                        cout << "====================================" << endl;
                        cout << "-> Enter your choice [0 -> 10]: ";
                        cin.seekg(0, ios::end);
                        cin.clear();
                        do {
                            getline(cin, s);
                            if (s != "0" && s != "1" && s != "2" && s != "3" && s != "4" && s != "5" && s != "6" && s != "7" && s != "8" && s != "9" && s != "10") {
                                cout << "Error choice! Re-enter: ";
                            } 
                        } while (s != "0" && s != "1" && s != "2" && s != "3" && s != "4"&& s != "5"&& s != "6"&& s != "7"&& s != "8"&& s != "9"&& s != "10");
                        themsach = stoi(s);
                        switch (themsach)
                        {
                        case 1:
                        {
                            cout << "Nhap thong tin sach: " << endl;
                            cin.seekg(0, ios::end);
                            cin.clear();
                            Nhap_Thong_Tin_Sach("KN", "Ky Nang Song", dsSach);
                            Xu_Ly_Tiep_Tuc_3(themsach, chucNangCon2, chucNangChinh);
                            break;
                        }
                        case 2:
                        {
                            cout << "Nhap thong tin sach: " << endl;
                            cin.seekg(0, ios::end);
                            cin.clear();
                            Nhap_Thong_Tin_Sach("IT", "Cong Nghe Thong Tin", dsSach);
                            Xu_Ly_Tiep_Tuc_3(themsach, chucNangCon2, chucNangChinh);
                            break;
                        }
                        case 3:
                        {
                            cout << "Nhap thong tin sach: " << endl;
                            cin.seekg(0, ios::end);
                            cin.clear();
                            Nhap_Thong_Tin_Sach("TT", "Truyen Tranh", dsSach);
                            Xu_Ly_Tiep_Tuc_3(themsach, chucNangCon2, chucNangChinh);
                            break;
                        }
                        case 4:
                        {
                            cout << "Nhap thong tin sach: " << endl;
                            cin.seekg(0, ios::end);
                            cin.clear();
                            Nhap_Thong_Tin_Sach("VH", "Van Hoc Viet Nam", dsSach);
                            Xu_Ly_Tiep_Tuc_3(themsach, chucNangCon2, chucNangChinh);
                            break;
                        }
                        case 5:
                        {
                            cout << "Nhap thong tin sach: " << endl;
                            cin.seekg(0, ios::end);
                            cin.clear();
                            Nhap_Thong_Tin_Sach("AN", "Am thuc - Nau an", dsSach);
                            Xu_Ly_Tiep_Tuc_3(themsach, chucNangCon2, chucNangChinh);
                            break;
                        }
                        case 6:
                        {
                            cout << "Nhap thong tin sach: " << endl;
                            cin.seekg(0, ios::end);
                            cin.clear();
                            Nhap_Thong_Tin_Sach("YS", "Y hoc - Suc khoe", dsSach);
                            Xu_Ly_Tiep_Tuc_3(themsach, chucNangCon2, chucNangChinh);
                            break;
                        }
                        case 7:
                        {
                            cout << "Nhap thong tin sach: " << endl;
                            cin.seekg(0, ios::end);
                            cin.clear();
                            Nhap_Thong_Tin_Sach("TN", "The thao - Nghe thuat", dsSach);
                            Xu_Ly_Tiep_Tuc_3(themsach, chucNangCon2, chucNangChinh);
                            break;
                        }
                        case 8:
                        {
                            cout << "Nhap thong tin sach: " << endl;
                            cin.seekg(0, ios::end);
                            cin.clear();
                            Nhap_Thong_Tin_Sach("NN", "Hoc Ngoai Ngu", dsSach);
                            Xu_Ly_Tiep_Tuc_3(themsach, chucNangCon2, chucNangChinh);
                            break;
                        }
                        case 9:
                        {
                            cout << "Nhap thong tin sach: " << endl;
                            cin.seekg(0, ios::end);
                            cin.clear();
                            Nhap_Thong_Tin_Sach("TH", "Triet Hoc", dsSach);
                            Xu_Ly_Tiep_Tuc_3(themsach, chucNangCon2, chucNangChinh);
                            break;
                        }
                        case 10:
                        {
                            cout << "Nhap thong tin sach: " << endl;
                            cin.seekg(0, ios::end);
                            cin.clear();
                            Nhap_Thong_Tin_Sach("MK", "Marketing - Ban hang", dsSach);
                            Xu_Ly_Tiep_Tuc_3(themsach, chucNangCon2, chucNangChinh);
                            break;
                        }
                        default:
                        {
                            system("cls");
                            break;
                        }
                        }
                    } while (themsach != 0);
                    break;
                }
                case 3:
                {
                    int suasach;
                    do
                    {
                        cout << "SUA SACH" << endl;
                        cout << "====================================" << endl;
                        cout << " [1] Ky nang song." << endl;
                        cout << " [2] Cong nghe thong tin." << endl;
                        cout << " [3] Truyen tranh." << endl;
                        cout << " [4] Van hoc Viet Nam." << endl;
                        cout << " [5] Am thuc - Nau an." << endl;
                        cout << " [6] Y hoc - Suc khoe." << endl;
                        cout << " [7] The thao - Nghe thuat." << endl;
                        cout << " [8] Hoc ngoai ngu." << endl;
                        cout << " [9] Triet hoc." << endl;
                        cout << " [10] Marketing - Ban hang." << endl;
                        cout << " [0] Tro ve." << endl;
                        cout << "====================================" << endl;
                        cout << "-> Enter your choice [0 -> 10]: ";
                        cin.seekg(0, ios::end);
                        cin.clear();
                        do {
                            getline(cin, s);
                            if (s != "0" && s != "1" && s != "2" && s != "3" && s != "4" && s != "5" && s != "6" && s != "7" && s != "8" && s != "9" && s != "10") {
                                cout << "Error choice! Re-enter: ";
                            }
                        } while (s != "0" && s != "1" && s != "2" && s != "3" && s != "4" && s != "5" && s != "6" && s != "7" && s != "8" && s != "9" && s != "10");
                        suasach = stoi(s);
                        switch (suasach)
                        {
                        case 1:
                        {
                            cout << "Nhap thong tin sach: " << endl;
                            cin.seekg(0, ios::end);
                            cin.clear();
                            dsSach.suaTTSach("Ky Nang Song");
                            Xu_Ly_Tiep_Tuc_3(suasach, chucNangCon2, chucNangChinh);
                            break;
                        }
                        case 2:
                        {
                            cout << "Nhap thong tin sach: " << endl;
                            cin.seekg(0, ios::end);
                            cin.clear();
                            dsSach.suaTTSach("Cong Nghe Thong Tin");
                            Xu_Ly_Tiep_Tuc_3(suasach, chucNangCon2, chucNangChinh);
                            break;
                        }
                        case 3:
                        {
                            cout << "Nhap thong tin sach: " << endl;
                            cin.seekg(0, ios::end);
                            cin.clear();
                            dsSach.suaTTSach("Truyen Tranh");
                            Xu_Ly_Tiep_Tuc_3(suasach, chucNangCon2, chucNangChinh);
                            break;
                        }
                        case 4:
                        {
                            cout << "Nhap thong tin sach: " << endl;
                            cin.seekg(0, ios::end);
                            cin.clear();
                            dsSach.suaTTSach("Van Hoc Viet Nam");
                            Xu_Ly_Tiep_Tuc_3(suasach, chucNangCon2, chucNangChinh);
                            break;
                        }
                        case 5:
                        {
                            cout << "Nhap thong tin sach: " << endl;
                            cin.seekg(0, ios::end);
                            cin.clear();
                            dsSach.suaTTSach("Am thuc - Nau an");
                            Xu_Ly_Tiep_Tuc_3(suasach, chucNangCon2, chucNangChinh);
                            break;
                        }
                        case 6:
                        {
                            cout << "Nhap thong tin sach: " << endl;
                            cin.seekg(0, ios::end);
                            cin.clear();
                            dsSach.suaTTSach("Y hoc - Suc khoe");
                            Xu_Ly_Tiep_Tuc_3(suasach, chucNangCon2, chucNangChinh);
                            break;
                        }
                        case 7:
                        {
                            cout << "Nhap thong tin sach: " << endl;
                            cin.seekg(0, ios::end);
                            cin.clear();
                            dsSach.suaTTSach("The thao - Nghe thuat");
                            Xu_Ly_Tiep_Tuc_3(suasach, chucNangCon2, chucNangChinh);
                            break;
                        }
                        case 8:
                        {
                            cout << "Nhap thong tin sach: " << endl;
                            cin.seekg(0, ios::end);
                            cin.clear();
                            dsSach.suaTTSach("Hoc Ngoai Ngu");
                            Xu_Ly_Tiep_Tuc_3(suasach, chucNangCon2, chucNangChinh);
                            break;
                        }
                        case 9:
                        {
                            cout << "Nhap thong tin sach: " << endl;
                            cin.seekg(0, ios::end);
                            cin.clear();
                            dsSach.suaTTSach("Triet Hoc");
                            Xu_Ly_Tiep_Tuc_3(suasach, chucNangCon2, chucNangChinh);
                            break;
                        }
                        case 10:
                        {
                            cout << "Nhap thong tin sach: " << endl;
                            cin.seekg(0, ios::end);
                            cin.clear();
                            dsSach.suaTTSach("Marketing - Ban hang");
                            Xu_Ly_Tiep_Tuc_3(suasach, chucNangCon2, chucNangChinh);
                            break;
                        }
                        default:
                        {
                            system("cls");
                            break;
                        }
                        }
                    } while (suasach != 0);
                    break;
                }
                case 4:
                {
                    dsSach.xoaSach();
                    Xu_Ly_Tiep_Tuc(chucNangCon2, chucNangChinh);
                    break;
                }
                case 5:
                {
                    system("cls");
                    int timkiemsach;
                    do
                    {
                        cout << "   -------------- TIM KIEM SACH --------------" << endl;
                        cout << "   | [1] Tim kiem sach theo ten.             |" << endl;
                        cout << "   | [2] Tim kiem sach theo ma sach.         |" << endl;
                        cout << "   | [3] Tim kiem sach theo tac gia.         |" << endl;
                        cout << "   | [0] Tro ve.                             |" << endl;
                        cout << "   -------------------------------------------" << endl;
                        cout << "   Enter your choice [0 -> 3]: ";
                        cin.seekg(0, ios::end);
                        cin.clear();
                        do {
                            getline(cin, s);
                            if (s.length() != 1 || s[0] < '0' || s[0] > '3') {
                                cout << "Error choice! Re-enter: ";
                            }
                        } while (s.length() != 1 || s[0] < '0' || s[0] > '3');
                        timkiemsach = stoi(s);
                        switch (timkiemsach) {
                        case 1:
                        {
                            dsSach.Tim_Kiem_Sach_Theo_Ten();
                            Xu_Ly_Tiep_Tuc(chucNangCon2, chucNangChinh);
                            break;
                        }
                        case 2:
                        {
                            dsSach.Tim_Kiem_Sach_Theo_Ma();
                            Xu_Ly_Tiep_Tuc(chucNangCon2, chucNangChinh);
                            break;
                        }
                        case 3:
                        {
                            dsSach.Tim_Kiem_Sach_Theo_TacGia();
                            Xu_Ly_Tiep_Tuc(chucNangCon2, chucNangChinh);
                            break;
                        }
                        default:
                        {
                            system("cls");
                            break;
                        }
                        }
                    } while (timkiemsach != 0);

                    break;
                }
                case 6:
                {
                    system("cls");
                    int sapxepsach;
                    do
                    {
                        cout << "   --------------- SAP XEP SACH ---------------" << endl;
                        cout << "   | [1] Sap xep theo the loai sach.          |" << endl;
                        cout << "   | [2] Sap xep theo ten tac gia.            |" << endl;
                        cout << "   | [0] Tro ve.                              |" << endl;
                        cout << "   --------------------------------------------" << endl;
                        cout << "   Enter your choice [0 -> 2]: ";
                        cin.seekg(0, ios::end);
                        cin.clear();
                        do {
                            getline(cin, s);
                            if (s.length() != 1 || s[0] < '0' || s[0] > '2') {
                                cout << "Error choice! Re-enter: ";
                            }
                        } while (s.length() != 1 || s[0] < '0' || s[0] > '2');
                        sapxepsach = stoi(s);
                        switch (sapxepsach) {
                        case 1:
                        {
                            dsSach.Sap_Xep_Sach_Theo_TheLoai();
                            Xu_Ly_Tiep_Tuc(chucNangCon2, chucNangChinh);
                            break;
                        }
                        case 2:
                        {
                            dsSach.Sap_Xep_Sach_Theo_TenTacGia();
                            Xu_Ly_Tiep_Tuc(chucNangCon2, chucNangChinh);
                            break;
                        }
                        default:
                            system("cls");
                            break;
                        }
                    } while (sapxepsach != 0);
                    break;
                }
                default:
                {
                    system("cls");
                    break;
                }
                }
            } while (chucNangCon2 != 0);
            break;
        }
        case 3:
        {
            system("cls");
            int chucNangCon3;
            do {
                cout << "CHUC NANG LAP PHIEU MUON" << endl;
                cout << "========================================" << endl;
                cout << "|   [1] Lap phieu muon.                |" << endl;
                cout << "|   [2] Hien thi danh sach phieu muon. |" << endl;
                cout << "|   [0] Tro ve menu chinh.             |" << endl;
                cout << "========================================" << endl;
                cout << "-> Enter your choice [0 -> 2] : ";
                cin.seekg(0, ios::end);
                cin.clear();
                do {
                    getline(cin, s);
                    if (s.length() != 1 || s[0] < '0' || s[0] > '2') {
                        cout << "Error choice! Re-enter: ";
                    }
                } while (s.length() != 1 || s[0] < '0' || s[0] > '2');
                chucNangCon3 = stoi(s);
                switch (chucNangCon3) {
                case 1:
                {
                    DocGia* docgiaMuon;
                    string maDocGia;

                    cin.seekg(0, ios::end);
                    cin.clear();
                    cout << "Nhap ma doc gia: ";
                    getline(cin, maDocGia);
                    if (!dsDocGia.laMaDG(maDocGia)) {
                        cout << "Ma doc gia khong ton tai!" << endl;
                    }
                    else if (dsPhieuMuon.Kiem_Tra_Muon_Sach(maDocGia)) {
                        cout << "Doc gia phai tra sach truoc khi muon!" << endl;
                    }
                    else {

                        if (maDocGia[0] == 'T' && maDocGia[1] == 'E') {
                            docgiaMuon = new DocGiaTreEm;
                        }
                        else {
                            docgiaMuon = new DocGiaNguoiLon;
                        }

                        cout << "THONG TIN DOC GIA MUON SACH" << endl;
                        cout << left << setw(10) << "Ma DG" << setw(20) << "Ho Ten" << setw(15);
                        cout << "Ngay sinh" << setw(12) << "Gioi tinh" << setw(11) << "Dia chi" << setw(15) << "So DT" << setw(15);
                        cout << "Ngay lap the" << setw(18) << "Thang hieu luc" << setw(20) << "Nguoi dai dien" << setw(15) << "CMND" << setw(20) << "Tien lam the" << endl;
                        cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
                        for (int i = 0; i < dsDocGia.getSize(); i++) {
                            if (maDocGia == dsDocGia.getDocGia(i)->getMaDG()) {
                                docgiaMuon = dsDocGia.getDocGia(i);
                                break;
                            }
                        }

                        docgiaMuon->display();

                        cout << "Nhap ngay muon: " << endl;
                        Date ngayMuon;
                        ngayMuon.input();

                        cout << "Nhap ngay tra du kien: " << endl;
                        Date ngayTraDuKien;
                        ngayTraDuKien.input();

                        cout << "Nhap so sach ban muon muon ( toi da 4 cuon ): ";
                        int soSach = 0;
                        cin >> soSach;

                        cin.seekg(0, ios::end);
                        cin.clear();

                        Sach* sach = new Sach[soSach];

                        for (int i = 0; i < soSach; i++) {
                            string maSachArr;
                            cout << "Nhap ma sach thu " << i + 1 << ": ";
                            do {
                                getline(cin, maSachArr);
                                if (!dsSach.laMaSach(maSachArr)) {
                                    cout << "Ma sach khong ton tai! Moi nhap lai: ";
                                }
                                else if (!dsSach.conSach(maSachArr)) {
                                    cout << "Sach da het! Moi ban nhap ma sach khac: ";
                                }

                            } while (!dsSach.laMaSach(maSachArr) || !dsSach.conSach(maSachArr));

                            for (int j = 0; j < dsSach.getSize(); j++) {
                                if (maSachArr == dsSach.getSach(j)->getMaSach()) {
                                    dsSach.getSach(j)->setSoLuong(dsSach.getSach(j)->getSoLuong() - 1);
                                    sach[i] = *(dsSach.getSach(j));
                                    break;
                                }
                            }

                        }
                        PhieuMuon phieumuon(docgiaMuon, sach, soSach, ngayMuon, ngayTraDuKien);

                        phieumuon.displayVertical();
                        phieumuon.inPhieuMuon();
                        remove("QUAN_LY_SACH.txt");
                        for (int i = 0; i < dsSach.getSize(); i++) {
                            dsSach.getSach(i)->ghiFile();
                        }


                        dsPhieuMuon.themPhieuMuon(phieumuon);
                        
                        
                    }
                    Xu_Ly_Tiep_Tuc(chucNangCon3, chucNangChinh);
                    break;
                }
                case 2:
                {
                    system("cls");
                    dsPhieuMuon.hienthiDanhSach();
                    Xu_Ly_Tiep_Tuc(chucNangCon3, chucNangChinh);
                    break;
                }
                default:
                {
                    system("cls");
                    break;
                }
                }
            } while (chucNangCon3 != 0);
            break;
        }
        case 4:
        {
            int chucNangCon4 = 0;
            int tienphat = 0;
            // xử lý độc giả
            DocGia* docgiaTra;
            string maDocGia;
            cin.seekg(0, ios::end);
            cin.clear();
            cout << "Nhap ma doc gia: ";
            getline(cin, maDocGia);
            if (!dsDocGia.laMaDG(maDocGia)) {
                cout << "Ma doc gia khong ton tai!";
            }else if (!dsPhieuMuon.Kiem_Tra_Muon_Sach(maDocGia)) {
                cout << "Doc gia chua muon sach!" << endl;
            }else {
                if (maDocGia[0] == 'T' && maDocGia[1] == 'E') {
                    docgiaTra = new DocGiaTreEm;
                }
                else {
                    docgiaTra = new DocGiaNguoiLon;
                }

                for (int i = 0; i < dsDocGia.getSize(); i++) {
                    if (maDocGia == dsDocGia.getDocGia(i)->getMaDG()) {
                        docgiaTra = dsDocGia.getDocGia(i);
                        break;
                    }
                }

                // in thông tin phiếu mượn của độc giả

                int tmp = 0;
                for (int i = 0; i < dsPhieuMuon.getSize(); i++) {
                    if (dsPhieuMuon.getPhieuMuon(i).getMaDocGia() == maDocGia) {
                        dsPhieuMuon.getPhieuMuon(i).displayVertical();
                        tmp = i;
                        break;
                    }
                }

                // nhập ngày trả thực tế
                cout << "Nhap ngay tra thuc te: " << endl;
                Date ngayTraThucTe;
                ngayTraThucTe.input();

                cin.seekg(0, ios::end);
                cin.clear();

                // xử lý khi bị mất sách
                cout << "Nhap so sach bi mat: ";
                int sachMat = 0;
                cin >> sachMat;

                Sach* sach = new Sach[sachMat];

                for (int i = 0; i < sachMat; i++) {
                    string maSachMat;
                    cout << "Nhap ma sach thu " << i + 1 << ": ";
                    do {
                        getline(cin, maSachMat);
                        if (!dsPhieuMuon.La_Sach_Da_Muon(docgiaTra, maSachMat)) {
                            cout << "Ban khong muon sach nay! Moi nhap lai: ";
                        }
                    } while (!dsPhieuMuon.La_Sach_Da_Muon(docgiaTra, maSachMat));
                    sach[i].setMaSach(maSachMat);
                    //phạt: sách(mã sách).giá sách() * 200 %;
                    for (int j = 0; j < dsSach.getSize(); j++) {
                        if (dsSach.getSach(j)->getMaSach() == maSachMat) {
                            tienphat = tienphat + dsSach.getSach(j)->getGiaSach() * 2;
                        }
                    }
                }

                // tìm những mã sách chưa bị mất
                int soluongsach = dsPhieuMuon.getPhieuMuon(tmp).getSoLuongSach();
                int sachChuaMat = soluongsach - sachMat;
                string* maSachChuaMat = new string[sachChuaMat];
                int k = 0;
                for (int i = 0; i < soluongsach; i++) {
                    int dem = 0;
                    for (int j = 0; j < sachMat; j++) {
                        if (dsPhieuMuon.getPhieuMuon(tmp).getMaSach(i) != sach[j].getMaSach()) {
                            dem++;
                        }
                    }
                    if (dem == sachMat) {
                        *(maSachChuaMat + k) = dsPhieuMuon.getPhieuMuon(tmp).getMaSach(i);
                        k++;
                    }
                }

                // tăng số lượng cho những sách chưa bị mất
                for (int i = 0; i < sachChuaMat; i++) {
                    for (int j = 0; j < dsSach.getSize(); j++) {
                        if (*(maSachChuaMat + i) == dsSach.getSach(j)->getMaSach()) {
                            dsSach.getSach(j)->setSoLuong(dsSach.getSach(j)->getSoLuong() + 1);
                        }
                    }
                }

                // ghi lại vào file
                remove("QUAN_LY_SACH.txt");
                for (int i = 0; i < dsSach.getSize(); i++) {
                    dsSach.getSach(i)->ghiFile();
                }

                // tính tiền phạt
                /*
                tính ngày trễ: (ngày trả thực tế - ngày mượn) = x > 0.
                phạt x*5000;
                */
                int ngaytre = ngayTraThucTe.differentDays(dsPhieuMuon.getPhieuMuon(tmp).getNgayMuon()) - 20;
                if (ngaytre > 0) {
                    tienphat = tienphat + ngaytre * 5000;
                    cout << "Ngay tre: " << ngaytre << " ngay" << endl;
                }

                cout << "Tien Phat: " << tienphat << endl;
                //xoa phieu muon sau khi tra sach
                dsPhieuMuon.Xoa_Phieu_Muon(docgiaTra);

            }
            Xu_Ly_Tiep_Tuc(chucNangCon4, chucNangChinh);
            break;
        } 
        case 5:
        {
            system("cls");
            int chucnangcon5;
            do {
                cout << "===================== CAC THONG KE CO BAN ====================" << endl;
                cout << "|    [1] Thong ke so luong sach trong thu vien.              |" << endl;
                cout << "|    [2] Thong ke so luong sach theo the loai.               |" << endl;
                cout << "|    [3] Thong ke so luong doc gia.                          |" << endl;
                cout << "|    [4] Thong ke so luong doc gia theo gioi tinh.           |" << endl;
                cout << "|    [5] Thong ke so luong doc gia theo loai doc gia.        |" << endl;
                cout << "|    [6] Thong ke danh sach doc gia bi tre han.              |" << endl;
                cout << "|    [0] Thoat chuong trinh.                                 |" << endl;
                cout << "==============================================================" << endl;
                cout << "-> Enter your choice: ";
                cin.seekg(0, ios::end);
                cin.clear();
                do {
                    getline(cin, s);
                    if (s.length() != 1 || s[0] < '0' || s[0] > '6') {
                        cout << "Error choice! Re-enter: ";
                    }
                } while (s.length() != 1 || s[0] < '0' || s[0] > '6');
                chucnangcon5 = stoi(s);
                switch (chucnangcon5)
                {
                case 1:
                {
                    int soluong1 = 0;

                    for (int i = 0; i < dsSach.getSize(); i++) {
                        soluong1 += dsSach.getSach(i)->getSoLuong();
                    }

                    int soluong2 = 0;
                    for (int i = 0; i < dsPhieuMuon.getSize(); i++) {
                        soluong2 += dsPhieuMuon.getPhieuMuon(i).getSoLuongSach();
                    }
                    cout << endl;
                    cout << "-------------Tong so luong sach trong thu vien--------------" << endl;
                    cout << endl;
                    cout << "            So luong sach trong thu vien: " << soluong1 << endl;
                    cout << "                                         +" << endl;
                    cout << "            So luong sach dang duoc muon: " << soluong2 << endl;
                    cout << "                                         ----------" << endl;
                    cout << " => Tong so luong sach trong thu vien la: " << soluong1 + soluong2 << endl;
                    cout << "------------------------------------------------------------" << endl;
                    cout << endl;
                    Xu_Ly_Tiep_Tuc(chucnangcon5, chucNangChinh);
                    break;
                }
                case 2:
                {
                    string s;
                    int t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, t8 = 0, t9 = 0, t10 = 0;
                    for (int i = 0; i < dsSach.getSize(); i++) {
                        s = dsSach.getSach(i)->getTheLoai();
                        if (s == "Ky Nang Song") {
                            t1 += dsSach.getSach(i)->getSoLuong();
                        }
                        else if (s == "Cong Nghe Thong Tin") {
                            t2 += dsSach.getSach(i)->getSoLuong();
                        }
                        else if (s == "Truyen Tranh") {
                            t3 += dsSach.getSach(i)->getSoLuong();
                        }
                        else if (s == "Van Hoc Viet Nam") {
                            t4 += dsSach.getSach(i)->getSoLuong();
                        }
                        else if (s == "Am thuc - Nau an") {
                            t5 += dsSach.getSach(i)->getSoLuong();
                        }
                        else if (s == "Y hoc - Suc khoe") {
                            t6 += dsSach.getSach(i)->getSoLuong();
                        }
                        else if (s == "The thao - Nghe thuat") {
                            t7 += dsSach.getSach(i)->getSoLuong();
                        }
                        else if (s == "Hoc Ngoai Ngu") {
                            t8 += dsSach.getSach(i)->getSoLuong();
                        }
                        else if (s == "Triet Hoc") {
                            t9 += dsSach.getSach(i)->getSoLuong();
                        }
                        else {
                            t10 += dsSach.getSach(i)->getSoLuong();
                        }
                    }
                    cout << "So luong sach theo the loai: " << endl;
                    cout << "\t - Ky Nang Song:          " << t1 << " cuon." << endl;
                    cout << "\t - Cong Nghe Thong Tin:   " << t2 << " cuon." << endl;
                    cout << "\t - Truyen Tranh:          " << t3 << " cuon." << endl;
                    cout << "\t - Van Hoc Viet Nam:      " << t4 << " cuon." << endl;
                    cout << "\t - Am thuc - Nau an:      " << t5 << " cuon." << endl;
                    cout << "\t - Y hoc - Suc khoe:      " << t6 << " cuon." << endl;
                    cout << "\t - The thao - Nghe thuat: " << t7 << " cuon." << endl;
                    cout << "\t - Hoc Ngoai Ngu:         " << t8 << " cuon." << endl;
                    cout << "\t - Triet Hoc:             " << t9 << " cuon." << endl;
                    cout << "\t - Marketing - Ban hang:  " << t10 << " cuon." << endl;
                    Xu_Ly_Tiep_Tuc(chucnangcon5, chucNangChinh);
                    break;
                }
                case 3:
                {
                    cout << "Tong so luong doc gia trong thu vien la: " << dsDocGia.getSize() << endl;
                    Xu_Ly_Tiep_Tuc(chucnangcon5, chucNangChinh);
                    break;
                }
                case 4:
                {
                    int nam = 0;
                    int nu = 0;
                    int khac = 0;
                    for (int i = 0; i < dsDocGia.getSize(); i++) {
                        if (dsDocGia.getDocGia(i)->getGioiTinh() == "Nam") {
                            nam += 1;
                        }
                        else if (dsDocGia.getDocGia(i)->getGioiTinh() == "Nu") {
                            nu += 1;
                        }
                        else {
                            khac += 1;
                        }
                    }
                    cout << "---- So luong doc gia theo gioi tinh ----" << endl;
                    cout << "+ Nam:   " << nam << endl;
                    cout << "+ Nu:    " << nu << endl;
                    cout << "+ Khac:  " << khac << endl;
                    Xu_Ly_Tiep_Tuc(chucnangcon5, chucNangChinh);
                    break;
                }
                case 5:
                {
                    int treem = 0;
                    int nguoilon = 0;
                    for (int i = 0; i < dsDocGia.getSize(); i++) {
                        if (dsDocGia.getDocGia(i)->getFirstCharMaDG() == 'T') {
                            treem += 1;
                        }
                        else {
                            nguoilon += 1;
                        }
                    }
                    cout << "---- So luong doc gia theo loai doc gia ----" << endl;
                    cout << "+ Doc gia tre em:      " << treem << endl;
                    cout << "+ Doc gia nguoi lon:   " << nguoilon << endl;
                    Xu_Ly_Tiep_Tuc(chucnangcon5, chucNangChinh);
                    break;
                }
                case 6:
                {
                    time_t now = time(0);
                    tm* ltm = localtime(&now);
                    Date currentDay(ltm->tm_mday, 1 + ltm->tm_mon, 1900 + ltm->tm_year);
                    int dem = 0;
                    for (int i = 0; i < dsPhieuMuon.getSize(); i++) {
                        if (dsPhieuMuon.getPhieuMuon(i).getNgayMuon().differentDays(currentDay) > 20) {
                            dem++;
                        }
                    }
                    cout << "So luong doc gia tre han la: " << dem << endl;
                    Xu_Ly_Tiep_Tuc(chucnangcon5, chucNangChinh);
                    break;
                }
                default:
                {
                    system("cls");
                    break;
                }
                }
            } while (chucnangcon5 != 0);
            break;
        }
        default: 
        {
            break;
        }         
        }
    } while (chucNangChinh != 0);
    return 0;
}

vector<DocGia*> Doc_Tu_File_DocGia() {
    vector<DocGia*> list;
    ifstream ifs;
    ifs.open("QUAN_LY_DOC_GIA.txt", ios_base::in);
    while(true)
    {
        char c = '\0';
        ifs >> c;
        if (c == '\0') {
            break;
        }
        ifs.seekg(-1, 1);
        if (c == 'T')
        {
            DocGia* x = new DocGiaTreEm;
            x->docDG(ifs);
            list.push_back(x);
        }
        else if (c == 'N')
        {
            DocGia* y = new DocGiaNguoiLon;
            y->docDG(ifs);
            list.push_back(y);
        }
    }
    ifs.close();
    return list;
}

vector<Sach*> Doc_Tu_File_Sach() {
    vector<Sach*> dsSach;
    ifstream fi("QUAN_LY_SACH.txt", ios::in);

    while (true) {
        char c = '\0';
        fi >> c;
        if (c == '\0') {
            break;
        }
        fi.seekg(-1, 1);
        Sach* x = new Sach;
        x->docFile(fi);
        dsSach.push_back(x);
    }

    fi.close();
    return dsSach;
}

vector<PhieuMuon> Doc_Tu_File_PhieuMuon(DanhSachDocGia &dsDocGia) {
    vector<PhieuMuon> dsPhieuMuon;
    ifstream fi("QUAN_LY_PHIEU_MUON.txt", ios::in);

    while (true) {
        char c = '\0';
        fi >> c;
        if (c == '\0') {
            break;
        }
        fi.seekg(-1, 1);
        PhieuMuon x;
        x.docFile(fi, dsDocGia);
        dsPhieuMuon.push_back(x);
    }

    fi.close();
    return dsPhieuMuon;
}

void Nhap_Thong_Tin_Sach(string maStr, string theloaiStr, DanhSach_Sach& dsSach) {
    cout << "Nhap ma sach (5 ki tu bat dau bang " << maStr << "): ";
    string ma;
    do {
        getline(cin, ma);
        if (ma.substr(0, 2) != maStr || ma.length() != 5) {
            cout << "Nhap sai! Moi ban nhap lai: ";
        }
    } while (ma.substr(0, 2) != maStr || ma.length() != 5);
    dsSach.themSach(ma, theloaiStr);
}