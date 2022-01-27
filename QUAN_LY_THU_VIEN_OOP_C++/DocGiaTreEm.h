#pragma once
#include "DocGia.h"
#include<fstream>

class DocGiaTreEm :
    public DocGia
{
private:
    string nguoiDaiDien;
public:

    DocGiaTreEm();
   
    string getMaDG();
    void setMaDG(string ma);

    int Tien_Lam_The();

    void input();
    void display();
    void displayVertical();

    void ghiDG();
    void inPDF(ofstream& fo);
    void docDG(ifstream& ifs);

    ~DocGiaTreEm();
};

