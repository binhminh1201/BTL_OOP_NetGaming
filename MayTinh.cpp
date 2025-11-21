#include "MayTinh.h"
#include <iomanip>
#include <sstream>
#include <vector>
using namespace std;

// ===================== MayTinh =====================
MayTinh::MayTinh() {}

MayTinh::MayTinh(const string &ma_, const string &ten_, double gia_)
    : ma(ma_), ten(ten_), gia(gia_) {}

string MayTinh::toLine() const {
    return ma + "|" + ten + "|" + to_string(gia) + "|MAYTINH";
}

MayTinh MayTinh::fromLine(const string &line) {
    stringstream ss(line);
    string token;
    vector<string> parts;
    while (getline(ss, token, '|')) parts.push_back(token);

    MayTinh m;
    if (parts.size() >= 3) {
        m.ma = parts[0];
        m.ten = parts[1];
        m.gia = stod(parts[2]);
    }
    return m;
}

void MayTinh::print() const {
    cout << left << setw(10) << ma
         << setw(25) << ten
         << right << setw(10) << fixed << setprecision(2) << gia
         << "   " << setw(15) << "" << '\n'; 
}

MayTinh::~MayTinh() {}


// ===================== MayVip =====================
MayVip::MayVip() {}

MayVip::MayVip(const string &ma_, const string &ten_, double gia_, const string &loaiVip_)
    : MayTinh(ma_, ten_, gia_), loaiVip(loaiVip_) {}

string MayVip::toLine() const {
    return ma + "|" + ten + "|" + to_string(gia) + "|MAYVIP|" + loaiVip;
}

MayVip MayVip::fromLine(const string &line) {
    stringstream ss(line);
    string token;
    vector<string> parts;
    while (getline(ss, token, '|')) parts.push_back(token);

    MayVip m;
    if (parts.size() >= 5) {
        m.ma = parts[0];
        m.ten = parts[1];
        m.gia = stod(parts[2]);
        m.loaiVip = parts[4];
    }
    return m;
}

void MayVip::print() const {
    cout << left << setw(10) << ma
         << setw(25) << ten
         << right << setw(10) << fixed << setprecision(2) << gia
         << "   " << left << setw(15) << loaiVip << '\n';
}


