# Hệ Thống Quản Lý Quán Net Gaming (C++ Console App)

> **Bài tập lớn môn Lập trình Hướng đối tượng (OOP)** > **Trường Đại học Giao thông Vận tải (UTC)** > **Giảng viên hướng dẫn:** Cao Thị Luyên

##  Giới thiệu

Dự án **Quản lý Quán Net Gaming** là một ứng dụng Console được viết bằng ngôn ngữ C++. Hệ thống mô phỏng quy trình quản lý thực tế tại một phòng máy, bao gồm việc quản lý các loại máy tính (Thường/VIP), quản lý khách hàng và tự động tính toán hóa đơn.

Mục tiêu chính của dự án là áp dụng triệt để 3 trụ cột của Lập trình hướng đối tượng: **Đóng gói**, **Kế thừa** và **Đa hình**, đồng thời thực hiện lưu trữ dữ liệu bền vững qua file.

##  Thành viên Nhóm 14 (Lớp N05)

| STT | Mã Sinh Viên | Họ và Tên | Vai trò |
| :--- | :--- | :--- | :--- |
| 1 | 241230779 | **Nguyễn Xuân Long** | Dev |
| 2 | 241224481 | **Nguyễn Bình Minh** | Dev |

##  Tính năng chính

### 1. Quản lý Máy tính (Computer Management)
* Phân loại máy: Máy Thường và Máy VIP (có cấu hình riêng như Card màn hình).
* Thêm mới, Xóa máy khỏi danh sách.
* Xem danh sách máy (Hiển thị đa hình).
* Thống kê số lượng máy VIP.

### 2. Quản lý Khách hàng (Customer Management)
* Thêm, Xóa khách hàng.
* Tra cứu và xem danh sách khách hàng.

### 3. Quản lý Hóa đơn (Invoice Management)
* Lập hóa đơn mới dựa trên Mã Máy và Mã Khách Hàng.
* **Tính tiền tự động:** Hệ thống tự tính `Thành tiền = Giờ chơi * Đơn giá`.
* Xuất danh sách hóa đơn.

### 4. Lưu trữ dữ liệu (Data Persistence)
* Tự động **Lưu** dữ liệu ra file `.txt` khi thoát hoặc thay đổi.
* Tự động **Nạp** (Load) dữ liệu khi khởi động chương trình.

## 🛠 Kỹ thuật OOP Áp dụng

Dự án tập trung vào các kỹ thuật lập trình C++ hiện đại:

* **Tính Đóng gói (Encapsulation):** * Dữ liệu nhạy cảm (như trong `HoaDon`) được đặt `private`.
    * Truy cập và xử lý thông qua các phương thức `public`.
* **Tính Kế thừa (Inheritance):**
    * `class MayVip` kế thừa từ `class MayTinh`.
    * Tái sử dụng mã nguồn tối đa.
* **Tính Đa hình (Polymorphism):**
    * Sử dụng `virtual function` cho hàm `print()` và `toLine()`.
    * Quản lý danh sách qua `vector<MayTinh*>` (Con trỏ lớp cha).
    * Sử dụng `dynamic_cast` để lọc và thống kê loại máy.
* **Quản lý bộ nhớ:**
    * Sử dụng `virtual destructor` để tránh rò rỉ bộ nhớ (memory leak).

##  Cấu trúc thư mục

```text
.
├── data/                  # Chứa file dữ liệu (.txt)
│   ├── may.txt
│   ├── khach.txt
│   └── hoadon.txt
├── main.cpp               # File điều khiển chính (Menu)
├── MayTinh.h/cpp          # Lớp cha MayTinh & lớp con MayVip
├── KhachHang.h/cpp        # Lớp đối tượng KhachHang
├── HoaDon.h/cpp           # Lớp đối tượng HoaDon
├── QuanLyMayTinh.h/cpp    # Lớp quản lý (Vector<MayTinh*>)
├── QuanLyKhachHang.h/cpp  # Lớp quản lý (Vector<KhachHang>)
└── QuanLyHoaDon.h/cpp     # Lớp quản lý (Vector<HoaDon>)
