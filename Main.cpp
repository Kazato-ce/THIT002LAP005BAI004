#include <iostream>
#include "CDate.h"

int main() {
    CDate ngayGui, ngayRut;
    double soTien, laiSuat;

    std::cout << "Nhập ngày gửi:\n";
    std::cin >> ngayGui;

    std::cout << "Nhập ngày rút:\n";
    std::cin >> ngayRut;

    std::cout << "Nhập số tiền gửi (VND): ";
    std::cin >> soTien;

    std::cout << "Nhập lãi suất (%/năm): ";
    std::cin >> laiSuat;

    int soNgay = ngayRut - ngayGui;

    if (soNgay < 0) {
        std::cout << "Lỗi: Ngày rút phải sau ngày gửi.\n";
        return 1;
    }

    double tienLai = soTien * laiSuat / 100 * soNgay / 365;

    std::cout << "\n== KẾT QUẢ ==\n";
    std::cout << "Số ngày gửi: " << soNgay << " ngày\n";
    std::cout << "Tiền lãi tạm tính: " << tienLai << " VND\n";

    return 0;
}
