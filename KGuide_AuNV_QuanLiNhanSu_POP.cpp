// KGuide_AuNV_QuanLiNhanSu_POP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include "QuanLiNhanVien.h"
#include <string>

#using <System.xml.dll>
using namespace System;
using namespace System::Xml;
using namespace std;

#define  NamHienTai 2023

// lib for Microsoft
//https://github.com/MicrosoftDocs/cpp-docs/blob/main/docs/dotnet/how-to-convert-system-string-to-standard-string.md
void MarshalString(String^ s, std::string& os) {
    using namespace Runtime::InteropServices;
    const char* chars =
        (const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
    os = chars;
    Marshal::FreeHGlobal(IntPtr((void*)chars));
}

//lib function for DEV
//Nam nhuan la nam %4 ==0 , nhung nam % 100 != 0
bool LaNamNhuan(int nam)
{
    if (nam % 4 == 0)
    {
        if (nam % 100 == 0)
        {
            return false;
        }
        return true;
    }
    return false;
}

bool KiemTraNgayThangNamHopLe(int ngay, int thang, int nam)
{
    bool Ngay = false;
    bool Thang = false;
    //Kiem tra ngay thang nam hop le
    if (thang > 0 && thang < 13)
    {
        Thang = true;
    }
    else
    {
        Thang = false;
    }
    //Ngay hop le
    if (ngay < 32 && ngay >0)
    {
        //Thang 2 toi da 29 ngay
        if (thang == 2)
        {
            if (LaNamNhuan(nam))
            {
                if (ngay < 30)
                {
                    Ngay = true;
                }
                else
                {
                    Ngay = false;
                }
            }
            else
            {
                if (ngay < 29)
                {
                    Ngay = true;
                }
                else
                {
                    Ngay = false;
                }
            }

        }
        else if (thang == 4 || thang == 6 || thang == 9 || thang == 11)
        {
            if (thang < 31)
            {
                Ngay = true;
            }
            else
            {
                Ngay = false;
            }
        }
        else if (thang == 1 || thang == 3 || thang == 5 || thang == 7 || thang == 8 || thang == 10 || thang == 12)
        {
            if (ngay < 32)
            {
                Ngay = true;
            }
            else
            {
                Ngay = false;
            }
        }
        else
        {
            Ngay = false;
        }

    }
    else
    {
        Ngay = false;
    }
    return Ngay && Thang;
}


NgayThangNamSinh DocNgayThangNamSinh(std::string ChuoiNam)
{
    //Xem ngay co kha thi
    //1. Nhan vien phai la nguoi tren 18 tuoi va khong qua 60
    //2. Kiem tra cac nam nhuan (thang 2 co 29 ngay) 
    //3. Cac thang co 31 ngay  1,3,5,7,8,10,12
    //4. cac thang co 30 ngay 4,6,9,11
    //quy tac 2 so dau la ngay, 2 so sau la thang, 4 so cuoi la nam
    int ngay = 0;
    int thang = 0;
    int nam = 0;
    int temp = std::stoi(ChuoiNam);
    //lay ngay;
    ngay = temp / 1000000;
    temp = temp % 1000000;
    //Laythang
    if (temp / 100000 < 0)
    {
        ngay = temp / 10000;
    }
    else
    {
        ngay = temp / 10000;
    }
    //Lay nam
    temp = temp % 10000;
    nam = temp;

    NgayThangNamSinh _ngayThangNamSinh{0,0,0};

    if ((nam < (NamHienTai - 18)) && (nam > (NamHienTai - 60)))
    {
        _ngayThangNamSinh._nam = nam;
        if (KiemTraNgayThangNamHopLe(ngay, thang, nam))
        {
            _ngayThangNamSinh._ngay = ngay;
            _ngayThangNamSinh._thang = thang;
        }
        else
        {
            //do thing vi ngay thang nam loi
        }
    }

    return _ngayThangNamSinh;
}

NamVaoCongTy DocNgayThangNamVaoCongTy(std::string ChuoiNam)
{
    //Xem ngay co kha thi
    //1. Nhan vien phai la nguoi tren 18 tuoi va khong qua 60
    //2. Kiem tra cac nam nhuan (thang 2 co 29 ngay) 
    //3. Cac thang co 31 ngay  1,3,5,7,8,10,12
    //4. cac thang co 30 ngay 4,6,9,11
    //quy tac 2 so dau la ngay, 2 so sau la thang, 4 so cuoi la nam
    int ngay = 0;
    int thang = 0;
    int nam = 0;
    int temp = std::stoi(ChuoiNam);
    //lay ngay;
    ngay = temp / 1000000;
    temp = temp % 1000000;
    //Laythang
    if (temp / 100000 < 0)
    {
        ngay = temp / 10000;
    }
    else
    {
        ngay = temp / 10000;
    }
    //Lay nam
    temp = temp % 10000;
    nam = temp;

    NamVaoCongTy _namVaoCongTy{ 0,0};

    if ((nam < (NamHienTai - 18)) && (nam > (NamHienTai - 60)))
    {
        _namVaoCongTy._nam = nam;
        if (KiemTraNgayThangNamHopLe(ngay, thang, nam))
        {
            _namVaoCongTy._thang = thang;
            _namVaoCongTy._nam = nam;
        }
        else
        {
            //do thing vi ngay thang nam loi
        }
    }

    return _namVaoCongTy;
}



//Functional
void InDanhSachRaManHinh(int TongSo);
// Bai Tap lam them //
void ThemNhanSu();
void XoaNhanSu();
void ChinhSuaThongTinNhanSu();
void KhoiTaoDanhSach(int& TongSo);



int main()
{
    int TongSoNhanVien = 0;
    KhoiTaoDanhSach(TongSoNhanVien);
    InDanhSachRaManHinh(TongSoNhanVien);
    return 0;
}


void KhoiTaoDanhSach(int &TongSo)
{
    XmlTextReader^ reader = gcnew XmlTextReader("DuLieuNhanVien.xml");
    int32_t i{ 0 };
    while (reader->Read())
    {
        NhanVien _Temp_NhanVien;

        switch (reader->NodeType)
        {
        case XmlNodeType::Element:
            while (reader->MoveToNextAttribute())
            {
                std::string ThuocTinh;
                std::string GiaTri;
                MarshalString(reader->Name->ToString(), ThuocTinh);
                //MaSoNhanVien
                if (ThuocTinh == "MaSoNhanVien")
                {
                    MarshalString(reader->Value->ToString(), GiaTri);
                    _Temp_NhanVien._maSoNhanVien = GiaTri;
                }
                //TenNhanVien
                else if (ThuocTinh == "TenNhanVien")
                {
                    MarshalString(reader->Value->ToString(), GiaTri);
                    _Temp_NhanVien._hoVaTenNhanVien = GiaTri;
                }
                //ChucVu
                else if(ThuocTinh == "ChucVu")
                {
                    MarshalString(reader->Value->ToString(), GiaTri);
                    //Nhan Vien
                    if (GiaTri == "Nhan Vien")
                    {
                        _Temp_NhanVien._chucVuNhanVien = ChucVu::_nhanVien;
                    }
                    //Quan li
                    else if (GiaTri ==  "Quan li")
                    {
                        _Temp_NhanVien._chucVuNhanVien = ChucVu::_quanLy;
                    }
                    //Truong Nhom
                    else if (GiaTri == "Truong Nhom")
                    {
                        _Temp_NhanVien._chucVuNhanVien = ChucVu::_quanLy;
                    }
                    //Khong dung dinh dang
                    else
                    {
                       cout << "Khong dung dinh dang: " << GiaTri << endl;
                    }
                }
                //NgayThangNamSinh
                else if (ThuocTinh == "NgayThangNamSinh")
                {
                    MarshalString(reader->Value->ToString(), GiaTri);
                    _Temp_NhanVien._ngayThangNamSinh = DocNgayThangNamSinh(GiaTri);
                }
                //NgayThangNamVaoCty
                else if (ThuocTinh == "NgayThangNamVaoCty")
                {
                    MarshalString(reader->Value->ToString(), GiaTri);
                    _Temp_NhanVien._namVaoCongTy = DocNgayThangNamVaoCongTy(GiaTri);
                }
                //LuongCanBan
                else if (ThuocTinh == "LuongCanBan")
                {
                    MarshalString(reader->Value->ToString(), GiaTri);
                    _Temp_NhanVien._LuongNhanVien = std::stoi(GiaTri);
                }
                //SoNgayLamViec
                else if (ThuocTinh == "SoNgayLamViec")
                {
                    MarshalString(reader->Value->ToString(), GiaTri);
                    _Temp_NhanVien._soNgayLamViec = std::stoi(GiaTri);
                }
                //Thuong
                else if (ThuocTinh == "Thuong")
                {
                    MarshalString(reader->Value->ToString(), GiaTri);
                    _Temp_NhanVien._thuong = std::stoi(GiaTri);
                }
                else
                {
                    //do nothing
                    cout << "Khong dung dinh dang: " << GiaTri << endl;
                }
            }
            _danhSachNhanVien[i] = _Temp_NhanVien;
            i++;
            break;
        }
    }
    TongSo = i;
}

void InDanhSachRaManHinh(int TongSo)
{
    cout << "\r\n\t Danh sach nhan vien \r\n\t\t" << endl;
    cout << "----------------------------------------------------------------------------" << endl;
    for (int i{ 1 }; i < TongSo; i++)
    {
        cout << "Nhan vien thu:" << i << endl;
        // Ma so nhan vien  - ho va tien
        cout << "Ma so nhan vien: " << _danhSachNhanVien[i]._maSoNhanVien << " Ho va ten: " << _danhSachNhanVien[i]._hoVaTenNhanVien << endl;
        //Chuc vu
        std::string chucVuNhanVien;
        switch (_danhSachNhanVien[i]._chucVuNhanVien)
        {
        case ChucVu::_nhanVien:
            chucVuNhanVien = "Nhan vien";
            break;
        case ChucVu::_quanLy:
            chucVuNhanVien = "Quan li";
            break;
        case ChucVu::_truongNhom:
            chucVuNhanVien = "Truong nhom";
            break;
        default:
            chucVuNhanVien = "Loi truy xuat du lieu";
            break;
        }
        // Chuc vu - Gioi tinh
        std::string GioiTinhNhanVien;
        if (_danhSachNhanVien[i]._gioiTinhNhanVien == GioiTinh::_nam)
        {
            GioiTinhNhanVien = "Nam";
        }
        else
        {
            GioiTinhNhanVien = "Nu";
        }

        cout << "Chuc vu: " << chucVuNhanVien << " Gioi tinh: " << GioiTinhNhanVien << endl;
        // Tuoi - Tham nien
        int TuoiNhanvien = 0;
        TuoiNhanvien = NamHienTai - _danhSachNhanVien[i]._ngayThangNamSinh._nam;
        int ThamNien = NamHienTai - _danhSachNhanVien[i]._namVaoCongTy._nam;
        cout << "Tuoi: " << TuoiNhanvien << " Tham nien: " << ThamNien << endl;
        // Luong Can ban - So Ngay Lam Viec - Thuong
        //Tong luong = Luong can ban *(So Ngay Lam Viec/20) + thuong
        cout << "Luong Can ban: " << _danhSachNhanVien[i]._LuongNhanVien << " So ngay lam vien: " << _danhSachNhanVien[i]._soNgayLamViec << endl;
        double Tongthunhap = _danhSachNhanVien[i]._LuongNhanVien * (double)(_danhSachNhanVien[i]._soNgayLamViec / 20) + _danhSachNhanVien[i]._thuong;
        cout << "Tong luong: "  << (int)Tongthunhap << endl;
        cout << "----------------------------------------------------------------------------" << endl;
    }
}

void ThemNhanSu(int &TongSo)
{
    //Them nhan su se phai them vao cuoi danh danh
    NhanVien NhanVienTemp;

}
