#pragma once
#include <iostream>
#include <string>

#define Max_Lenght  1000

//Chuc vu nhan vien
enum ChucVu
{
	_nhanVien, //Nhan Vien
	_truongNhom, //Truong Nhom
	_quanLy,//Quan ly nhan su
};

//Gioi tinh nhan vien
enum GioiTinh
{
	_nam,//Nam
	_nu,//Nu
};

//Ngay thang nam sinh
typedef struct NgayThangNamSinh
{
	int _ngay = 0;
	int _thang = 0;
	int _nam = 0;
};

//Nam vao cong ty
typedef struct NamVaoCongTy
{
	int _thang = 0;
	int _nam = 0;
};

//Cau truc nhan vien
typedef struct NhanVien
{
	std::string _maSoNhanVien = "";
	std::string _hoVaTenNhanVien = "";
	ChucVu _chucVuNhanVien = ChucVu::_nhanVien;
	GioiTinh _gioiTinhNhanVien = GioiTinh::_nam;
	NgayThangNamSinh  _ngayThangNamSinh;
	NamVaoCongTy _namVaoCongTy;
	std::int32_t _thamNien = 0;
	std::int32_t _LuongNhanVien = 0;
	std::int32_t _soNgayLamViec = 0;
	std::int32_t _thuong = 0;
};


//Data cho chuong trinh
NgayThangNamSinh _ngayThanhNam_HienTai;
NhanVien _danhSachNhanVien[Max_Lenght];

//Thu nhap = Luong - Thue
enum ThueTNCN
{
	_duoi5Trieu, //5%
	_tu5TrieuDen10Trieu,//10%
	_tu10TrieuDen18Trieu,//15%
	_tu18TrieuDen35Trieu,//20%
	_tren35Trieu,//25%
};


//Functional

