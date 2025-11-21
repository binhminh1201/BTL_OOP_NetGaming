#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <iomanip>
using namespace std;

class KhachHang {
public:
    string ma;        
    string hoTen;   
    string gioiTinh;  

    KhachHang();
    KhachHang(const string &ma_, const string &hoTen_, const string &gioiTinh_);

    string toLine() const;                
    static KhachHang fromLine(const string &line);
    void print() const;                  
};

