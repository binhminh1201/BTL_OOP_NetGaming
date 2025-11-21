#include "MayTinh.h"
#include <vector>
#include <fstream>

class QuanLyMayTinh {
private:
    vector<MayTinh*> ds;
    string tenFile;      

public:
    QuanLyMayTinh(const string &file = "data.txt");
    ~QuanLyMayTinh();

    void nhap();            
    void xuat() const;       
    void ghiFile() const;   
    void docFile();          
    void themMay(MayTinh *m);
    void xoaMay(const string &ma);
    void thongKe() const;  
};

