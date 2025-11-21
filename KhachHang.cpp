#include "KhachHang.h"

KhachHang::KhachHang() {}

KhachHang::KhachHang(const string &ma_, const string &hoTen_, const string &gioiTinh_)
    : ma(ma_), hoTen(hoTen_), gioiTinh(gioiTinh_) {}

string KhachHang::toLine() const {
    return ma + "|" + hoTen + "|" + gioiTinh;
}

KhachHang KhachHang::fromLine(const string &line) {
    stringstream ss(line);
    string token;
    vector<string> parts;
    while (getline(ss, token, '|')) parts.push_back(token);

    KhachHang k;
    if (parts.size() >= 3) {
        k.ma = parts[0];
        k.hoTen = parts[1];
        k.gioiTinh = parts[2];
    }
    return k;
}

void KhachHang::print() const {
    cout << left << setw(10) << ma
         << setw(25) << hoTen
         << setw(8)  << gioiTinh << '\n';
}

