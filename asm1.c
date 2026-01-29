/******************************************************************************
 * Họ và tên: [Trân Văn Huy]
 * MSSV:      [PS48688]
 * Lớp:       [COM108-CS21302]
 *****************************************************************************/

// Danh sách các chức năng trong ASM1:
// 1. Chức năng số 1: Kiểm tra số nguyên
// 2. Chức năng số 2. Tìm Ước số chung và bội số chung của 2 số 
// 3. Chức năng số 3: Chương trình tính tiền cho quán Karaoke
// 4. Chức năng số 4: Tính tiền điện 
// 5. Chức năng số 5: Chức năng đổi tiền 
// 6. Chức năng số 6: Xây dựng chức năng tính lãi suất vay ngân hàng vay trả góp 
// 7. Chức năng số 7: Xây dựng chương trình vay tiền mua xe
// 8. Chức năng số 8: Sắp xếp thông tin sinh viên
// 9. Chức năng số 9: Xây dựng game FPOLY-LOTT
// 10. Chức năng số 10: Xây dựng chương trình tính toán phân số 
// Viết chương trình C thực hiện các chức năng trên

#include <stdio.h>
#include <math.h>

int main() {
    int chonChucNang;

    do {
        printf("\nChon chuc nang:\n");
        printf("1. Kiem tra so nguyen\n");
        printf("2. Tim Uoc so chung va boi so chung cua 2 so\n");
        printf("3. Tinh tien cho quan Karaoke\n");
        printf("4. Tinh tien dien\n");
        printf("5. Chuc nang doi tien\n");
        printf("6. Tinh lai suat vay ngan hang vay tra gop\n");
        printf("7. Vay tien mua xe\n");
        printf("8. Sap xep thong tin sinh vien\n");
        printf("9. Game FPOLY-LOTT\n");
        printf("10. Tinh toan phan so\n");
        printf("0. Thoat\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &chonChucNang);

        switch (chonChucNang) {

        /* ===== CASE 1 ===== */
        case 1: {
            // Gọi hàm kiểm tra số nguyên
            printf("DA CHON CHUC NANG 1: KIEM TRA SO NGUYEN\n");
            int x, i, nguyenTo = 1;
            printf("Nhập số nguyên x: ");
            scanf("%d", &x);

            if (x < 2) nguyenTo = 0;
            for (i = 2; i <= sqrt(x); i++) {
                if (x % i == 0) {
                    nguyenTo = 0;
                    break;
                }
            }

            if (nguyenTo)
                printf("%d là số nguyên tố\n", x);
            else
                printf("%d không phải là số nguyên tố\n", x);

            int sq = sqrt(x);
            if (sq * sq == x)
                printf("%d là số chính phương\n", x);
            else
                printf("%d không phải là số chính phương\n", x);
            break;
        }

        /* ===== CASE 2 ===== */
        case 2: {
            // Gọi hàm tìm Ước số chung và bội số chung
            printf("DA CHON CHUC NANG 2: TIM UOC SO CHUNG VA BOI SO CHUNG CUA 2 SO\n");
            int a, b, i, ucln = 1;
            printf("Nhập 2 số a b: ");
            scanf("%d%d", &a, &b);

            for (i = 1; i <= a && i <= b; i++) {
                if (a % i == 0 && b % i == 0)
                    ucln = i;
            }

            printf("UCLN = %d\n", ucln);
            printf("BCNN = %d\n", (a * b) / ucln);
            break;
        }

        /* ===== CASE 3 ===== */
        case 3: {
            // Gọi hàm tính tiền cho quán Karaoke
            printf("DA CHON CHUC NANG 3: TINH TIEN CHO QUAN KARAOKE\n");
            int gioVao, gioRa;
            float tien = 150000;
            printf("Nhập giờ vào và giờ ra: ");
            scanf("%d%d", &gioVao, &gioRa);

            int soGio = gioRa - gioVao;
            if (soGio > 3)
                tien += (soGio - 3) * 150000 * 0.7;

            if (gioVao >= 14 && gioVao <= 17)
                tien *= 0.9;

            printf("Tiền karaoke: %.0f VND\n", tien);
            break;
        }

        /* ===== CASE 4 ===== */
        case 4: {
             // Gọi hàm tính tiền điện
            printf("DA CHON CHUC NANG 4: TINH TIEN DIEN\n");
            int kwh;
            float tien;
            printf("Nhập số kWh: ");
            scanf("%d", &kwh);

            if (kwh <= 50)
                tien = kwh * 1678;
            else if (kwh <= 100)
                tien = 50 * 1678 + (kwh - 50) * 1734;
            else if (kwh <= 200)
                tien = 50 * 1678 + 50 * 1734 + (kwh - 100) * 2014;
            else if (kwh <= 300)
                tien = 50 * 1678 + 50 * 1734 + 100 * 2014 + (kwh - 200) * 2536;
            else if (kwh <= 400)
                tien = 50 * 1678 + 50 * 1734 + 100 * 2014 + 100 * 2536 + (kwh - 300) * 2834;
            else
                tien = 50 * 1678 + 50 * 1734 + 100 * 2014 + 100 * 2536 + 100 * 2834 + (kwh - 400) * 2998;

            printf("Tiền điện: %.0f VND\n", tien);
            break;
        }

        /* ===== CASE 5 ===== */
        case 5: {
            // Gọi hàm đổi tiền
            printf("DA CHON CHUC NANG 5: DOI TIEN\n");
            int tien, menhGia[] = {200,100,50,20,10,5,2,1};
            printf("Nhập số tiền cần đổi: ");
            scanf("%d", &tien);

            for (int i = 0; i < 9; i++) {
                if (tien >= menhGia[i]) {
                    printf("%d to %d\n", tien / menhGia[i], menhGia[i]);
                    tien %= menhGia[i];
                }
            }
            break;
        }

        /* ===== CASE 6 ===== */
        case 6: {
            // Gọi hàm tính lãi suất vay ngân hàng
            printf("DA CHON CHUC NANG 6: TINH LAI SUAT VAY NGAN HANG VAY TRA GOP\n");
            float vay;
            printf("Nhập số tiền vay: ");
            scanf("%f", &vay);

            float goc = vay / 12;
            float conLai = vay;

            for (int i = 1; i <= 12; i++) {
                float lai = conLai * 0.05;
                float tong = goc + lai;
                conLai -= goc;
                printf("Tháng %d: Trả %.0f | Còn lại %.0f\n", i, tong, conLai);
            }
            break;
        }

        /* ===== CASE 7 ===== */
        case 7: {
            printf("DA CHON CHUC NANG 7: VAY TIEN MUA XE\n");
            float giaXe = 500000000; 
            float phanTramVay;
            float soTienVay, tienTraTruoc;
            int thoiHan = 24; 
            float laiSuatNam = 7.2;
            float laiSuatThang = laiSuatNam / 12 / 100;
            float tienTraHangThang;
            printf("Nhập phần trăm vay: ");
            scanf("%f", &phanTramVay);
            soTienVay = giaXe * phanTramVay / 100;
            tienTraTruoc = giaXe - soTienVay;
            tienTraHangThang = (soTienVay * laiSuatThang * (1 + laiSuatThang) * thoiHan) / ((1 + laiSuatThang) * thoiHan - 1);
            printf("\nGiá xe: %.0f VND\n", giaXe);
            printf("Số tiền trả trước: %.0f VND\n", tienTraTruoc);
            printf("Số tiền vay: %.0f VND\n", soTienVay);
            printf("Thời hạn vay: %d tháng\n", thoiHan);
            printf("Tiền trả hàng tháng: %.0f VND\n", tienTraHangThang);

            break;
        }


        /* ===== CASE 8 ===== */
        case 8: {
    printf("DA CHON CHUC NANG 8: SAP XEP THONG TIN SINH VIEN\n");

    int n;
    printf("Nhập số lượng sinh viên: ");
    scanf("%d", &n);

    char ten[n][50];
    float diem[n];

    // Nhap du lieu
    for (int i = 0; i < n; i++) {
        printf("\nNhập họ và tên sinh viên %d: ", i + 1);
        scanf(" %[^\n]", ten[i]);   // Co dau cach truoc %

        printf("Nhập điểm sinh viên %d: ", i + 1);
        scanf("%f", &diem[i]);
    }

    // Sap xep theo diem giam dan
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (diem[i] < diem[j]) {
                float tempDiem = diem[i];
                diem[i] = diem[j];
                diem[j] = tempDiem;

                char tempTen[50];
                for (int k = 0; k < 50; k++) {
                    tempTen[k] = ten[i][k];
                    ten[i][k] = ten[j][k];
                    ten[j][k] = tempTen[k];
                }
            }
        }
    }

    // Xuat ket qua
    printf("\n===== DANH SACH SINH VIEN SAU KHI SAP XEP =====\n");
    for (int i = 0; i < n; i++) {
        printf("\nSinh viên %d:", i + 1);
        printf("\nHọ tên: %s", ten[i]);
        printf("\nDiem: %.2f", diem[i]);
        printf("\nHoc luc: ");

        if (diem[i] >= 9.0)
            printf("Xuất sắc");
        else if (diem[i] >= 8.0)
            printf("Giỏi");
        else if (diem[i] >= 6.5)
            printf("Khá");
        else if (diem[i] >= 5.0)
            printf("Trung bình");
        else
            printf("Yếu");
    }

    break;
}



        /* ===== CASE 9 ===== */
        case 9: {
            // Gọi hàm game FPOLY-LOTT
            printf("DA CHON CHUC NANG 9: GAME FPOLY-LOTT\n");
            int a, b, x1, x2, trung = 0;
            printf("Nhập 2 số bản thân chọn (1-15): ");
            scanf("%d%d", &a, &b);
            if (a < 1 || a > 15 || b < 1 || b > 15 || a == b) {
                printf("Số không hợp lệ. Vui lòng chọn lại.\n");
                break;
            }
            printf("Nhập 2 số hệ thống chọn (1-15): ");
            scanf("%d%d", &x1, &x2);
             if (a < 1 || a > 15 || b < 1 || b > 15 || a == b) {
                printf("Số không hợp lệ.\n");
                break;
            }

            if (a == x1 || a == x2) trung++;
            if (b == x1 || b == x2) trung++;

            if (trung == 2) printf("Trung giai nhat\n");
            else if (trung == 1) printf("Trung giai nhi\n");
            else printf("Khong trung\n");
            break;
        }

        /* ===== CASE 10 ===== */
        case 10: {
            // Gọi hàm tính toán phân số
            printf("DA CHON CHUC NANG 10: TINH TOAN PHAN SO\n");
            int a, b, c, d;
            printf("Nhap phan so a/b va c/d: ");
            scanf("%d%d%d%d", &a, &b, &c, &d);

            printf("Tổng = %d/%d\n", a*d + c*b, b*d);
            printf("Hiệu = %d/%d\n", a*d - c*b, b*d);
            printf("ích = %d/%d\n", a*c, b*d);
            printf("Thương = %d/%d\n", a*d, b*c);
            break;
        }

        case 0:
            printf("Thoat chuong trinh\n");
            break;

        default:
            printf("Lua chon khong hop le. Vui long chon lai.\n");
        }

    } while (chonChucNang != 0);

    return 0;
}



