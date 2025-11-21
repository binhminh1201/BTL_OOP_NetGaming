#include "HoaDon.h"
#include <vector>
#include <fstream>
using namespace std;

class QuanLyHoaDon {
private:
    string tenFile;
    vector<HoaDon> ds;

public:
    QuanLyHoaDon(const string &file);
    void nhap();
    void xuat() const;
    void ghiFile() const;
    void docFile();
};

