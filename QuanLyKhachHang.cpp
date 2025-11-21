#include "QuanLyKhachHang.h"
#include <iostream>
#include <iomanip>
using namespace std;

QuanLyKhachHang::QuanLyKhachHang(const string &file) : tenFile(file) {
    docFile();
}

void QuanLyKhachHang::nhap() {
    string ma, ten, gt;
    cout << "Nhap ma KH: "; getline(cin, ma);
    cout << "Nhap ho ten: "; getline(cin, ten);
    cout << "Nhap gioi tinh: "; getline(cin, gt);

    ds.push_back(KhachHang(ma, ten, gt));
    ghiFile();
    cout<<"Da luu du lieu vao file " <<tenFile<<endl;
}

void QuanLyKhachHang::xuat() const {
    cout << left << setw(10) << "Ma KH"
         << setw(25) << "Ho ten"
         << setw(10) << "Gioi tinh" << '\n';
    cout << string(50, '-') << '\n';
    for (auto &kh : ds) kh.print();
}

void QuanLyKhachHang::ghiFile() const {
    ofstream f(tenFile);
    for (auto &kh : ds)
        f << kh.toLine() << '\n';
    f.close();
}

void QuanLyKhachHang::docFile() {
    ifstream f(tenFile);
    if (!f.is_open()) return;
    string line;
    while (getline(f, line))
        ds.push_back(KhachHang::fromLine(line));
    f.close();
}

void QuanLyKhachHang::xoaKH(const string &ma) {
    for (auto it = ds.begin(); it != ds.end(); ++it) {
        if (it->ma == ma) {
            ds.erase(it);
            cout << "Da xoa KH co ma " << ma << '\n';
            return;
        }
    }
    cout << "Khong tim thay KH co ma " << ma << '\n';
}

