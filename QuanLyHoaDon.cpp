#include "QuanLyHoaDon.h"
#include <iostream>
#include <iomanip>
using namespace std;

QuanLyHoaDon::QuanLyHoaDon(const string &file) : tenFile(file) {
    docFile();
}

void QuanLyHoaDon::nhap() {
    string maHD, maKH, maMay;
    double gio, donGia;

    cout << "Nhap ma hoa don: "; getline(cin, maHD);
    cout << "Nhap ma KH: "; getline(cin, maKH);
    cout << "Nhap ma may: "; getline(cin, maMay);
    cout << "Nhap so gio su dung: "; cin >> gio;
    cout << "Nhap don gia (VND/gio): "; cin >> donGia;
    cin.ignore();

    ds.push_back(HoaDon(maHD, maKH, maMay, gio, donGia));
    ghiFile();
    cout<<"Da luu du lieu vao file " <<tenFile<<endl;
}

void QuanLyHoaDon::xuat() const {
    cout << left
         << setw(10) << "MaHD"
         << setw(10) << "MaKH"
         << setw(10) << "MaMay"
         << right << setw(8) << "Gio"
         << setw(12) << "Don gia"
         << setw(12) << "Thanh tien" << '\n';
    cout << string(65, '-') << '\n';
    for (auto &h : ds) h.print();
}


void QuanLyHoaDon::ghiFile() const {
    ofstream f(tenFile);
    for (auto &hd : ds)
        f << hd.toLine() << '\n';
    f.close();
}

void QuanLyHoaDon::docFile() {
    ifstream f(tenFile);
    if (!f.is_open()) return;
    string line;
    while (getline(f, line))
        ds.push_back(HoaDon::fromLine(line));
    f.close();
}

