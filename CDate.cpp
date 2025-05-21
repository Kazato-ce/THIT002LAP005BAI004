#include "CDate.h"

CDate::CDate(int d, int m, int y) : ngay(d), thang(m), nam(y) {}

bool CDate::namNhuan(int y) const {
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

int CDate::soNgayTrongThang(int m, int y) const {
    static int ngayThang[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    if (m == 2 && namNhuan(y)) return 29;
    return ngayThang[m - 1];
}

int CDate::tongSoNgay() const {
    int dem = ngay;
    for (int y = 1; y < nam; ++y)
        dem += namNhuan(y) ? 366 : 365;
    for (int m = 1; m < thang; ++m)
        dem += soNgayTrongThang(m, nam);
    return dem;
}

void CDate::tuSoNgay(int tongNgay) {
    nam = 1;
    while (true) {
        int songaynam = namNhuan(nam) ? 366 : 365;
        if (tongNgay > songaynam) {
            tongNgay -= songaynam;
            ++nam;
        } else break;
    }

    thang = 1;
    while (true) {
        int songaythang = soNgayTrongThang(thang, nam);
        if (tongNgay > songaythang) {
            tongNgay -= songaythang;
            ++thang;
        } else break;
    }

    ngay = tongNgay;
}

CDate CDate::operator+(int songay) const {
    int tong = tongSoNgay() + songay;
    CDate kq;
    kq.tuSoNgay(tong);
    return kq;
}

CDate CDate::operator-(int songay) const {
    return (*this) + (-songay);
}

int CDate::operator-(const CDate& d) const {
    return this->tongSoNgay() - d.tongSoNgay();
}

CDate& CDate::operator++() {
    *this = *this + 1;
    return *this;
}

CDate CDate::operator++(int) {
    CDate tam = *this;
    ++(*this);
    return tam;
}

CDate& CDate::operator--() {
    *this = *this - 1;
    return *this;
}

CDate CDate::operator--(int) {
    CDate tam = *this;
    --(*this);
    return tam;
}

std::ostream& operator<<(std::ostream& out, const CDate& d) {
    out << (d.ngay < 10 ? "0" : "") << d.ngay << "/"
        << (d.thang < 10 ? "0" : "") << d.thang << "/"
        << d.nam;
    return out;
}

std::istream& operator>>(std::istream& in, CDate& d) {
    std::cout << "Nhập ngày: ";
    in >> d.ngay;
    std::cout << "Nhập tháng: ";
    in >> d.thang;
    std::cout << "Nhập năm: ";
    in >> d.nam;
    return in;
}
