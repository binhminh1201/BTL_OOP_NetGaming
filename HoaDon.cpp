#include "HoaDon.h"
#include <iomanip>
using namespace std;

HoaDon::HoaDon() {
    maHD = maKH = maMay = "";
    gio = donGia = 0;
}

HoaDon::HoaDon(const string &ma_, const string &maKhach_, const string &maMay_, double gio_, double donGia_) {
    maHD = ma_;
    maKH = maKhach_;
    maMay = maMay_;
    gio = gio_;
    donGia = donGia_;
}

double HoaDon::tinhTien() const {
    return gio * donGia;
}

void HoaDon::print() const {
    cout << left
         << setw(10) << maHD
         << setw(10) << maKH
         << setw(10) << maMay
         << right << setw(8) << gio
         << setw(12) << donGia
         << setw(12) << tinhTien() << '\n';
}

string HoaDon::toLine() const {
    return maHD + "|" + maKH + "|" + maMay + "|" + to_string(gio) + "|" + to_string(donGia);
}

HoaDon HoaDon::fromLine(const string &line) {
    stringstream ss(line);
    string token;
    vector<string> parts;
    while (getline(ss, token, '|')) parts.push_back(token);

    HoaDon hd;
    if (parts.size() >= 5) {
        hd.maHD = parts[0];
        hd.maKH = parts[1];
        hd.maMay = parts[2];
        hd.gio = stod(parts[3]);
        hd.donGia = stod(parts[4]);
    }
    return hd;
}

