#include "QuanLyMayTinh.h"
#include <iostream>
#include <iomanip>
using namespace std;

QuanLyMayTinh::QuanLyMayTinh(const string &file) : tenFile(file) {
    docFile();
}

QuanLyMayTinh::~QuanLyMayTinh() {
    for (auto m : ds) delete m;
}


void QuanLyMayTinh::nhap() {
    int chon;
    cout << "1. May thuong\n2. May VIP\nChon loai may: ";
    cin >> chon;
    cin.ignore();

    string ma, ten;
    double gia;
    cout << "Nhap ma may: "; getline(cin, ma);
    cout << "Nhap ten may: "; getline(cin, ten);
    cout << "Nhap gia: "; cin >> gia; cin.ignore();

    if (chon == 1) {
        ds.push_back(new MayTinh(ma, ten, gia));
    } else {
        string loai;
        cout << "Nhap loai VIP: "; getline(cin, loai);
        ds.push_back(new MayVip(ma, ten, gia, loai));
    }
    
    ghiFile();
    cout<<"Da luu du lieu vao file " <<tenFile<<endl; 
}


void QuanLyMayTinh::xuat() const {
    cout << left
         << setw(10) << "Ma"
         << setw(25) << "Ten may"
         << right << setw(10) << "Gia"
         << "   "
         << left << setw(15) << "Loai VIP" << '\n';
    cout << string(70, '-') << '\n';
    for (auto m : ds) m->print();
}




void QuanLyMayTinh::ghiFile() const {
    ofstream f(tenFile);
    for (auto m : ds) {
        f << m->toLine() << '\n';
    }
    f.close();
}


void QuanLyMayTinh::docFile() {
    ifstream f(tenFile);
    if (!f.is_open()) return;
    string line;
    while (getline(f, line)) {
        if (line.find("MAYVIP") != string::npos)
            ds.push_back(new MayVip(MayVip::fromLine(line)));
        else
            ds.push_back(new MayTinh(MayTinh::fromLine(line)));
    }
    f.close();
}


void QuanLyMayTinh::themMay(MayTinh *m) {
    ds.push_back(m);
}


void QuanLyMayTinh::xoaMay(const string &ma) {
    for (auto it = ds.begin(); it != ds.end(); ++it) {
        if ((*it)->ma == ma) {
            delete *it;
            ds.erase(it);
            cout << "Da xoa may co ma: " << ma << '\n';
            return;
        }
    }
    cout << "Khong tim thay may co ma: " << ma << '\n';
}


void QuanLyMayTinh::thongKe() const {
    int thuong = 0, vip = 0;
    for (auto m : ds) {
        if (dynamic_cast<MayVip*>(m))
            vip++;
        else
            thuong++;
    }
    cout << "So may thuong: " << thuong << "\n";
    cout << "So may VIP: " << vip << "\n";
}

