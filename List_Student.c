/*
Chương trình quản lý sinh viên:
  Cho phép nhập vào danh sách sinh viên gồm các thông tin: mã số, tên, tuổi, điểm toán, điểm lý, điểm hóa.
  Hiển thị danh sách sinh viên ra màn hình.
  Tính điểm trung bình cho mỗi sinh viên và xếp loại học lực: Giỏi (đtb >= 8), Khá (đtb >= 6.5), Trung bình (đtb >= 5), Yếu (đtb < 5).
  Sắp xếp danh sách theo thứ tự điểm trung bình từ cao đến thấp.
  Tìm kiếm sinh viên theo tên hoặc mã số.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

// Cấu trúc lưu thông tin sinh viên
struct SinhVien
{
  int maSo;
  char hoTen[30];
  int tuoi;
  float diemToan;
  float diemLy;
  float diemHoa;
  float dtb;
};

float tinhDiemTrungBinh(struct SinhVien sv);

// Nhập thông tin cho 1 sinh viên
// kiểu void  không trả về giá trị
void nhapThongTin(struct SinhVien *sv)
{
  printf("\nNhap ma so: ");
  scanf("%d", &sv->maSo);
  fflush(stdin); //Hàm fflush() dùng để xóa bộ đệm đầu vào stdin sau khi nhập xong, 
  //               nhằm tránh các ký tự nhập thừa còn đọng lại trong bộ đệm gây lỗi cho các lệnh nhập tiếp theo.

  printf("Nhap ho ten: ");
  gets(sv->hoTen); // Hàm gets không an toàn và đã bị loại bỏ trong C11 vì vấn đề liên quan đến tràn bộ đệm.
  /*fgets(sv->hoTen, sizeof(sv->hoTen), stdin);
  sv->hoTen[strcspn(sv->hoTen, "\n")] = '\0'; // Xóa ký tự newline từ fgets
  */

  printf("Nhap tuoi: ");
  scanf("%d", &sv->tuoi);

  printf("Nhap diem Toan, Ly, Hoa: ");
  scanf("%f%f%f", &sv->diemToan, &sv->diemLy, &sv->diemHoa);

  sv->dtb = tinhDiemTrungBinh(*sv);
}

// Tính điểm trung bình
float tinhDiemTrungBinh(struct SinhVien sv)
{
  return (sv.diemToan + sv.diemLy + sv.diemHoa) / 3;
}

// So sánh theo điểm trung bình
int soSanhTheoDTB(const void *a, const void *b) //các tham số của hàm so sánh được truyền vào qsort() phải có kiểu là con trỏ void*.
{
  struct SinhVien *svA = (struct SinhVien *)a;  // ép kiểu (...)
  struct SinhVien *svB = (struct SinhVien *)b;

  if (svA->dtb > svB->dtb)
    return -1;
  else if (svA->dtb < svB->dtb)
    return 1;
  else
    return 0;
}

// Tìm kiếm sinh viên theo mã số
int timKiemTheoMaSo(int maSo, struct SinhVien *dssv, int n)
{
  int i;

  for (i = 0; i < n; i++)
  {
    if (dssv[i].maSo == maSo)
    {
      return i;
    }
  }
  return -1; // Không tìm thấy
}

int main()
{
  struct SinhVien dssv[MAX];
  int n, maTim, vitri, i;

  // Nhập danh sách sinh viên
  do
  {
    printf("Nhap so luong sinh vien: ");
    scanf("%d", &n);
  } while (n <= 0 || n > MAX);

  for (i = 0; i < n; i++)
  {
    printf("\nNhap thong tin cho sinh vien thu %d:\n", i + 1);
    nhapThongTin(&dssv[i]);
    dssv[i].dtb = tinhDiemTrungBinh(dssv[i]);
  }

  // Sắp xếp giảm dần theo điểm trung bình
  qsort(dssv, n, sizeof(struct SinhVien), soSanhTheoDTB);
  
  // In danh sách sinh viên
  printf("\nDanh sach sinh vien sau sap xep:\n");

  for (i = 0; i < n; i++)
  {
    printf("%5d | %20s | %2d | %5.2f\n",
           dssv[i].maSo, dssv[i].hoTen, dssv[i].tuoi, dssv[i].dtb);
  }

  // Nhập mã số cần tìm
  printf("\nNhap ma so can tim: ");
  scanf("%d", &maTim);

  // Tìm sinh viên theo mã số
  vitri = timKiemTheoMaSo(maTim, dssv, n);

  if (vitri == -1)
  {
    printf("\nKhong tim thay sinh vien co ma so %d.\n", maTim);
  }
  else
  {
    printf("\nThong tin sinh vien co ma so %d:\n", maTim);
    printf("%5d | %20s | %2d | %5.2f\n",
           dssv[vitri].maSo, dssv[vitri].hoTen, dssv[vitri].tuoi, dssv[vitri].dtb);
  }

  return 0;
}
