#ifndef CDATE_H
#define CDATE_H

#include <iostream>

class CDate {
private:
    int ngay, thang, nam;

    bool namNhuan(int y) const;
    int soNgayTrongThang(int m, int y) const;
    int tongSoNgay() const;
    void tuSoNgay(int tongNgay);

public:
    CDate(int d = 1, int m = 1, int y = 2000);

    // Toán tử cộng/trừ với số nguyên ngày
    CDate operator+(int songay) const;
    CDate operator-(int songay) const;

    // Toán tử trừ giữa hai ngày
    int operator-(const CDate& d) const;

    // Tiền tố và hậu tố ++ --
    CDate& operator++();     // ++d
    CDate operator++(int);   // d++
    CDate& operator--();     // --d
    CDate operator--(int);   // d--

    // Nhập / xuất
    friend std::ostream& operator<<(std::ostream& out, const CDate& d);
    friend std::istream& operator>>(std::istream& in, CDate& d);
};

#endif
