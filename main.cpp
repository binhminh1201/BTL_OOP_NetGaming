#include "QuanLyMayTinh.h"
#include "QuanLyKhachHang.h"
#include "QuanLyHoaDon.h"
#include <iostream>
using namespace std;

int main() {
    QuanLyMayTinh qlMay("data/may.txt");
    QuanLyKhachHang qlKH("data/khach.txt");
    QuanLyHoaDon qlHD("data/hoadon.txt");

    int chon;
    do {
        cout << "\n========== MENU QUAN LY QUAN NET ==========\n";
        cout << "1. Quan ly may tinh\n";
        cout << "2. Quan ly khach hang\n";
        cout << "3. Quan ly hoa don\n";
        cout << "0. Thoat\n";
        cout << "===========================================\n";
        cout << "Chon: ";
        cin >> chon;
        cin.ignore();

        switch (chon) {
            case 1: {
                int c;
                do {
                    cout << "\n--- Quan ly may ---\n";
                    cout << "1. Nhap may\n2. Xuat danh sach\n3. Xoa may\n4. Thong ke\n0. Quay lai\n";
                    cout << "Chon: "; cin >> c; cin.ignore();
                    if (c == 1) qlMay.nhap();
                    else if (c == 2) qlMay.xuat();
                    else if (c == 3) {
                        string ma; 
						cout << "Nhap ma may can xoa: "; 
						getline(cin, ma);
                        qlMay.xoaMay(ma);
                    } else if (c == 4) qlMay.thongKe();
                } while (c != 0);
                break;
            }
            case 2: {
                int c;
                do {
                    cout << "\n--- Quan ly khach hang ---\n";
                    cout << "1. Nhap KH\n2. Xuat danh sach\n3. Xoa KH\n0. Quay lai\n";
                    cout << "Chon: "; cin >> c; cin.ignore();
                    if (c == 1) qlKH.nhap();
                    else if (c == 2) qlKH.xuat();
                    else if (c == 3) {
                        string ma; cout << "Nhap ma KH can xoa: "; getline(cin, ma);
                        qlKH.xoaKH(ma);
                    }
                } while (c != 0);
                break;
            }
            case 3: {
                int c;
                do {
                    cout << "\n--- Quan ly hoa don ---\n";
                    cout << "1. Nhap hoa don\n2. Xuat danh sach\n0. Quay lai\n";
                    cout << "Chon: "; cin >> c; cin.ignore();
                    if (c == 1) qlHD.nhap();
                    else if (c == 2) qlHD.xuat();
                } while (c != 0);
                break;
            }
            case 0:
                qlMay.ghiFile();
                qlKH.ghiFile();
                qlHD.ghiFile();
                cout << "Da luu du lieu va thoat.\n";
                break;
            default:
                cout << "Lua chon khong hop le!\n";
        }
    } while (chon != 0);

    return 0;
}

