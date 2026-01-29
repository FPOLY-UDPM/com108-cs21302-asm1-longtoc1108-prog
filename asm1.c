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
        printf("Chon chuc nang:\n");
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
            printf("Nhap so nguyen x: ");
            scanf("%d", &x);

            if (x < 2) nguyenTo = 0;
            for (i = 2; i <= sqrt(x); i++) {
                if (x % i == 0) {
                    nguyenTo = 0;
                    break;
                }
            }

            if (nguyenTo)
                printf("%d la so nguyen to\n", x);
            else
                printf("%d khong phai so nguyen to\n", x);

            int sq = sqrt(x);
            if (sq * sq == x)
                printf("%d la so chinh phuong\n", x);
            else
                printf("%d khong phai so chinh phuong\n", x);
            break;
        }

        /* ===== CASE 2 ===== */
        case 2: {
            // Gọi hàm tìm Ước số chung và bội số chung
            printf("DA CHON CHUC NANG 2: TIM UOC SO CHUNG VA BOI SO CHUNG CUA 2 SO\n");
            int a, b, i, ucln = 1;
            printf("Nhap 2 so a b: ");
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
            printf("Nhap gio vao va gio ra: ");
            scanf("%d%d", &gioVao, &gioRa);

            int soGio = gioRa - gioVao;
            if (soGio > 3)
                tien += (soGio - 3) * 150000 * 0.7;

            if (gioVao >= 14 && gioVao <= 17)
                tien *= 0.9;

            printf("Tien karaoke: %.0f VND\n", tien);
            break;
        }

        /* ===== CASE 4 ===== */
        case 4: {
             // Gọi hàm tính tiền điện
            printf("DA CHON CHUC NANG 4: TINH TIEN DIEN\n");
            int kwh;
            float tien;
            printf("Nhap so kWh: ");
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

            printf("Tien dien: %.0f VND\n", tien);
            break;
        }

        /* ===== CASE 5 ===== */
        case 5: {
            // Gọi hàm đổi tiền
            printf("DA CHON CHUC NANG 5: DOI TIEN\n");
            int tien, menhGia[] = {500,200,100,50,20,10,5,2,1};
            printf("Nhap so tien can doi: ");
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
            printf("Nhap so tien vay: ");
            scanf("%f", &vay);

            float goc = vay / 12;
            float conLai = vay;

            for (int i = 1; i <= 12; i++) {
                float lai = conLai * 0.05;
                float tong = goc + lai;
                conLai -= goc;
                printf("Thang %d: Tra %.0f | Con lai %.0f\n", i, tong, conLai);
            }
            break;
        }

        /* ===== CASE 7 ===== */
        case 7: {
            // Gọi hàm vay tiền mua xe
            printf("DA CHON CHUC NANG 7: VAY TIEN MUA XE\n");
            float phanTram;
            printf("Nhap %% vay: ");
            scanf("%f", &phanTram);

            float giaXe = 500000000;
            float vay = giaXe * phanTram / 100;
            float traTruoc = giaXe - vay;
            float traThang = vay / (24 * 12);

            printf("Tra truoc: %.0f\n", traTruoc);
            printf("Tra moi thang: %.0f\n", traThang);
            break;
        }

        /* ===== CASE 8 ===== */
        case 8: {
            // Gọi hàm sắp xếp thông tin sinh viên
            printf("DA CHON CHUC NANG 8: SAP XEP THONG TIN SINH VIEN\n");
            int n;
            float diem[100];
            printf("Nhap so sinh vien: ");
            scanf("%d", &n);

            for (int i = 0; i < n; i++) {
                printf("Nhap diem sv %d: ", i+1);
                scanf("%f", &diem[i]);
            }

            for (int i = 0; i < n-1; i++)
                for (int j = i+1; j < n; j++)
                    if (diem[i] < diem[j]) {
                        float tmp = diem[i];
                        diem[i] = diem[j];
                        diem[j] = tmp;
                    }

            for (int i = 0; i < n; i++) {
                printf("SV %d: %.1f - ", i+1, diem[i]);
                if (diem[i] >= 9) printf("Xuat sac\n");
                else if (diem[i] >= 8) printf("Gioi\n");
                else if (diem[i] >= 6.5) printf("Kha\n");
                else if (diem[i] >= 5) printf("Trung binh\n");
                else printf("Yeu\n");
            }
            break;
        }

        /* ===== CASE 9 ===== */
        case 9: {
            // Gọi hàm game FPOLY-LOTT
            printf("DA CHON CHUC NANG 9: GAME FPOLY-LOTT\n");
            int a, b, x1, x2, trung = 0;
            printf("Nhap 2 so (1-15): ");
            scanf("%d%d", &a, &b);
            printf("Nhap 2 so he thong (1-15): ");
            scanf("%d%d", &x1, &x2);

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

            printf("Tong = %d/%d\n", a*d + c*b, b*d);
            printf("Hieu = %d/%d\n", a*d - c*b, b*d);
            printf("Tich = %d/%d\n", a*c, b*d);
            printf("Thuong = %d/%d\n", a*d, b*c);
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



