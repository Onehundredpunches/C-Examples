#include <stdio.h>
#include <stdarg.h>  // Thư viện hỗ trợ tham số không xác định trong C

double average(int num,...) {

   va_list valist;   // Khai báo biến valist kiểu va_list để lưu danh sách các tham số.
   double sum = 0.0;
   int i;

   /* initialize valist for num number of arguments */
   va_start(valist, num);   //khởi tạo valist từ tham số num.

   /* access all the arguments assigned to valist */
   for (i = 0; i < num; i++) {
      sum += va_arg(valist, int); // Va_arg trả về kiểu int tại vị trí i.
   }
	
   /* clean memory reserved for valist */
   va_end(valist);  // Giải phóng valist sau khi sử dụng xong.

   return sum/num;
}

int main() {
   printf("Average of 2, 3, 4, 5 = %f\n", average(4, 2,3,4,5));
   
}