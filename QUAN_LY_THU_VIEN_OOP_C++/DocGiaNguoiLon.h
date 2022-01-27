#pragma once
#include "DocGia.h"

class DocGiaNguoiLon :
    public DocGia
{
private:
    string soCMND;
public:
    DocGiaNguoiLon();
    
    string getMaDG();
    void setMaDG(string ma);

    void input();
    void display();
    void displayVertical();

    int Tien_Lam_The();

    void ghiDG();
    void inPDF(ofstream& fo);
    void docDG(ifstream &ifs);

    ~DocGiaNguoiLon();
};

