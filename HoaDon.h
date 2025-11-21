#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

class HoaDon {
private:
    string maHD, maKH, maMay;
    double gio;
    double donGia;

public:
    HoaDon();
    HoaDon(const string &ma_, const string &maKhach_, const string &maMay_, double gio_, double donGia_);

   
    string toLine() const;
    static HoaDon fromLine(const string &line);

  
    void print() const;

 
    double tinhTien() const;
};

