#include "KhachHang.h"
#include <vector>
#include <fstream>
using namespace std;

class QuanLyKhachHang {
private:
    string tenFile;
    vector<KhachHang> ds;

public:
    QuanLyKhachHang(const string &file);
    void nhap();
    void xuat() const;
    void ghiFile() const;
    void docFile();
    void xoaKH(const string &ma);
};

