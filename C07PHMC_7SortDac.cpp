/*****************************/
/**KHAI BAO THU VIEN SU DUNG */
/*****************************/
using namespace std;
#include <iostream> // Thư viện cho các luồng vào/ra

/******************************/
/**KHAI BAO DANH SACH DAC */
/******************************/

struct BKPHMC_CIT07 // cấu trúc 1 quyển sách trong danh sách thư viện
{
	string Ten_Sach_CIT07;		// tên sách
	string Ma_Sach_CIT07;		// mã sách
	string Loai_Sach_CIT07;		// loại sách
	int So_Lan_Muon_Sach_CIT07; // số lần mượn sách
};

const int PhanTuToiDa_CIT07 = 100;			 // số lượng phần tử tối đa trong mảng
BKPHMC_CIT07 BOOKS_CIT07[PhanTuToiDa_CIT07]; // DANH SÁCH CÁC PHẦN TỬ (DS ĐẶC)
int TongSoPhanTuKhaoSat_CIT07;				 // số lượng phần tử (thực có) trong mảng [n <= max]

/*************************************************************/
/**CÁC PHÉP THAO TÁC (TOÁN) CƠ BẢN TRÊN DANH SÁCH ĐẶC: SÁCH*/
/*************************************************************/

// 1. Khởi tạo
void KhoiTao_CIT07()
{
	TongSoPhanTuKhaoSat_CIT07 = 0;
}

// 2. Xác định độ dài
int DoDaiDS_CIT07()
{
	return TongSoPhanTuKhaoSat_CIT07;
}

// 3. Kiểm tra rỗng
bool KiemTraRong_CIT07()
{
	return (TongSoPhanTuKhaoSat_CIT07 == 0);
}

// 4. Kiểm tra đầy
bool KiemTraDay_CIT07()
{
	return (TongSoPhanTuKhaoSat_CIT07 == PhanTuToiDa_CIT07);
}

/*************************************************/
// CÁC PHÉP TOÁN XỬ LÝ TRÊN DANH SÁCH ĐẶC: SÁCH //
/***********************************************/

// 5. Nhập danh sách sách
void Nhapds_CIT07()
{
	cout << "Nhập số phần tử trong danh sách: ";
	cin >> TongSoPhanTuKhaoSat_CIT07;

	for (int i = 0; i < TongSoPhanTuKhaoSat_CIT07; i++)
	{
		cout << "Nhập thông tin phần tử thứ " << i + 1 << ":\n";

		cout << "Nhập mã sách: ";
		cin >> BOOKS_CIT07[i].Ma_Sach_CIT07;
		cin.ignore(); // Loại bỏ ký tự newline sau khi nhập mã sách

		cout << "Nhập tên sách: ";
		getline(cin, BOOKS_CIT07[i].Ten_Sach_CIT07); // Nhập cả dòng

		cout << "Nhập loại sách: ";
		getline(cin, BOOKS_CIT07[i].Loai_Sach_CIT07); // Nhập cả dòng

		cout << "Nhập số lần mượn sách: ";
		cin >> BOOKS_CIT07[i].So_Lan_Muon_Sach_CIT07;
		cin.ignore(); // Loại bỏ ký tự newline sau khi nhập số lần mượn sách
	}
}

// 6. In danh sách sách
void Inds_CIT07()
{
	cout << "\n_____________________________________\n";
	cout << "\nDANH SÁCH CÁC PHẦN TỬ TRONG DANH SÁCH:\n";
	for (int i = 0; i < TongSoPhanTuKhaoSat_CIT07; i++)
	{
		cout << "Phần tử " << i + 1 << ":\n";
		cout << "Mã sách: " << BOOKS_CIT07[i].Ma_Sach_CIT07 << "\n";
		cout << "Tên sách: " << BOOKS_CIT07[i].Ten_Sach_CIT07 << "\n";
		cout << "Loại sách: " << BOOKS_CIT07[i].Loai_Sach_CIT07 << "\n";
		cout << "Số lần mượn sách: " << BOOKS_CIT07[i].So_Lan_Muon_Sach_CIT07 << "\n";
		cout << "\n";
	}
	cout << "Danh sách có " << TongSoPhanTuKhaoSat_CIT07 << " phần tử \n";
}

// 7. Hàm hoán đổi nội dung hai phần tử
void HoanDoi_CIT07(BKPHMC_CIT07 &a, BKPHMC_CIT07 &b)
{
	BKPHMC_CIT07 temp = a;
	a = b;
	b = temp;
}

// CÁC GIẢI THUẬT SẮP XẾP TRÊN DANH SÁCH ĐẶC: SÁCH  - SẮP XẾP THEO SỐ LẦN MƯỢN SÁCH
/* [1] Interchange Sort
Bước 1: Khởi tạo mảng dữ liệu ban đầu là [5, 2, 8, 1, 3]: số lần mượn sách
Bước 2: Chạy thuật toán Interchange Sort
Vòng lặp ngoài i = 0:
So sánh arr[0] (5) với arr[1] (2) → Hoán đổi
So sánh arr[0] (2) với arr[2] (8) → Không đổi
So sánh arr[0] (2) với arr[3] (1) → Hoán đổi
So sánh arr[0] (1) với arr[4] (3) → Không đổi
Vòng lặp ngoài i = 1:
So sánh arr[1] (5) với arr[2] (8) → Không đổi
So sánh arr[1] (5) với arr[3] (2) → Hoán đổi
So sánh arr[1] (2) với arr[4] (3) → Không đổi
Vòng lặp ngoài i = 2:
So sánh arr[2] (8) với arr[3] (5) → Hoán đổi
So sánh arr[2] (5) với arr[4] (3) → Hoán đổi
Vòng lặp ngoài i = 3:
So sánh arr[3] (8) với arr[4] (5) → Hoán đổi
Kết quả cuối cùng: [1, 2, 3, 5, 8]
*/
void InterchangeSort_CIT07()
{
	for (int i = 0; i < TongSoPhanTuKhaoSat_CIT07 - 1; i++)
	{
		for (int j = i + 1; j < TongSoPhanTuKhaoSat_CIT07; j++)
		{
			if (BOOKS_CIT07[j].So_Lan_Muon_Sach_CIT07 < BOOKS_CIT07[i].So_Lan_Muon_Sach_CIT07)
			{
				HoanDoi_CIT07(BOOKS_CIT07[j], BOOKS_CIT07[i]);
			}
		}
	}
	cout << "\n Danh sách đã được sắp xếp theo số lần mượn sách bằng pp InterchangeSort:";
}

// [2] Buble Sort
void BubleSort_CIT07()
{
	for (int i = 0; i < TongSoPhanTuKhaoSat_CIT07; i++)
	{
		for (int j = 0; j < TongSoPhanTuKhaoSat_CIT07 - i - 1; j++)
		{
			if (BOOKS_CIT07[j].So_Lan_Muon_Sach_CIT07 > BOOKS_CIT07[j + 1].So_Lan_Muon_Sach_CIT07)
			{
				HoanDoi_CIT07(BOOKS_CIT07[j], BOOKS_CIT07[j + 1]);
			}
		}
	}
	cout << "\n Danh sách đã được sắp xếp theo số lần mượn sách bằng pp BubleSort:";
}

// [3] Straight Selection Sort
/*
Vòng lặp ngoài i = 0:
Tìm phần tử nhỏ nhất từ arr[0] đến arr[4]
min_idx = 3 (giá trị 1)
Hoán đổi arr[0] với arr[3]
Vòng lặp ngoài i = 1:
Tìm phần tử nhỏ nhất từ arr[1] đến arr[4]
min_idx = 1 (giá trị 2)
Hoán đổi arr[1] với arr[1] (không đổi)
Vòng lặp ngoài i = 2:
Tìm phần tử nhỏ nhất từ arr[2] đến arr[4]
min_idx = 4 (giá trị 3)
Hoán đổi arr[2] với arr[4]
Vòng lặp ngoài i = 3:
Tìm phần tử nhỏ nhất từ arr[3] đến arr[4]
min_idx = 3 (giá trị 5)
Hoán đổi arr[3] với arr[3] (không đổi)
Vòng lặp ngoài i = 4:
Không cần so sánh.
Kết quả cuối cùng: [1, 2, 3, 5, 8]
*/
void StraightSlectionSort_CIT07()
{
	for (int i = 0; i < TongSoPhanTuKhaoSat_CIT07 - 1; i++)
	{
		int min_pos = i;
		for (int j = i + 1; j < TongSoPhanTuKhaoSat_CIT07; j++)
		{
			if (BOOKS_CIT07[j].So_Lan_Muon_Sach_CIT07 < BOOKS_CIT07[min_pos].So_Lan_Muon_Sach_CIT07)
			{
				min_pos = j;
			}
		}
		if (min_pos != i)
		{
			HoanDoi_CIT07(BOOKS_CIT07[i], BOOKS_CIT07[min_pos]);
		}
	}
	cout << "\n Danh sách đã được sắp xếp theo số lần mượn sách bằng pp StraightSlectioSort:";
}

// [4] Straight Insertion Sort
/*

Vòng lặp ngoài i = 1:
x = BOOKS_CIT07[1] (2)
So sánh 5 với 2 → Di chuyển 5 về sau
Chèn 2 vào vị trí đúng
Vòng lặp ngoài i = 2:
x = BOOKS_CIT07[2] (8)
So sánh 5 với 8 → Không đổi
Vòng lặp ngoài i = 3:
x = BOOKS_CIT07[3] (1)
So sánh 8 với 1 → Di chuyển 8 về sau
So sánh 5 với 1 → Di chuyển 5 về sau
So sánh 2 với 1 → Di chuyển 2 về sau
Chèn 1 vào vị trí đúng
Vòng lặp ngoài i = 4:
x = BOOKS_CIT07[4] (3)
So sánh 8 với 3 → Di chuyển 8 về sau
So sánh 5 với 3 → Di chuyển 5 về sau
So sánh 2 với 3 → Không đổi
Chèn 3 vào vị trí đúng
Kết quả cuối cùng: [1, 2, 3, 5, 8]
*/
void StraightInsertionSort_CIT07()
{
	for (int i = 1; i < TongSoPhanTuKhaoSat_CIT07; i++)
	{
		BKPHMC_CIT07 x = BOOKS_CIT07[i]; // phần tử cần chèn (key)
		int j = i - 1;					 // vị trí phần tử trước key
		while (j >= 0 && BOOKS_CIT07[j].So_Lan_Muon_Sach_CIT07 > x.So_Lan_Muon_Sach_CIT07)
		{
			BOOKS_CIT07[j + 1] = BOOKS_CIT07[j]; // dịch chuyển phần tử lớn hơn key 1 vị trí
			j--;								 // giảm vị trí để xét tiếp
		}
		BOOKS_CIT07[j + 1] = x; // chèn key vào vị trí thích hợp
	}
	cout << "\n Danh sách đã được sắp xếp theo số lần mượn sách bằng pp StraightInsertinSort:";
}

// [5] Binary Insertion Sort
/*[5, 2, 8, 1, 3].
Vòng lặp ngoài i = 1:
x = BOOKS_CIT07[1] (2)
left = 0, right = 0

Tìm vị trí chèn cho 2:
mid = (0 + 0) / 2 = 0
2 < 5 → right = mid - 1 = -1
Chèn 2 vào vị trí left = 0:
Dịch chuyển 5 về sau: [5, 5, 8, 1, 3]
Chèn 2 vào vị trí 0: [2, 5, 8, 1, 3]

Vòng lặp ngoài i = 2:
x = BOOKS_CIT07[2] (8)
left = 0, right = 1
Tìm vị trí chèn cho 8:
mid = (0 + 1) / 2 = 0
8 > 2 → left = mid + 1 = 1
mid = (1 + 1) / 2 = 1
8 > 5 → left = mid + 1 = 2
Chèn 8 vào vị trí left = 2:
Không cần di chuyển: [2, 5, 8, 1, 3]


Vòng lặp ngoài i = 3:
x = BOOKS_CIT07[3] (1)
left = 0, right = 2
Tìm vị trí chèn cho 1:
mid = (0 + 2) / 2 = 1
1 < 5 → right = mid - 1 = 0
mid = (0 + 0) / 2 = 0
1 < 2 → right = mid - 1 = -1

Chèn 1 vào vị trí left = 0:
Dịch chuyển 8, 5, 2 về sau
[2, 5, 8, 8, 3]
[2, 5, 5, 8, 3]
[2, 2, 5, 8, 3]

Chèn 1 vào vị trí 0
[1, 2, 5, 8, 3]

Vòng lặp ngoài i = 4:
x = BOOKS_CIT07[4] (3)
left = 0, right = 3
Tìm vị trí chèn cho 3:
mid = (0 + 3) / 2 = 1
3 > 2 → left = mid + 1 = 2	
mid = (2 + 3) / 2 = 2
3 < 5 → right = mid - 1 = 1
Chèn 3 vào vị trí left = 2:
Dịch chuyển 8, 5 về sau
[1, 2, 5, 8, 8]
[1, 2, 5, 5, 8]

Chèn 3 vào vị trí 2: [1, 2, 3, 5, 8]
Kết quả cuối cùng: [1, 2, 3, 5, 8]
*/
// Thuật toán Binary Insertion Sort là một cải tiến của thuật toán Insertion Sort truyền thống, sử dụng tìm kiếm nhị phân (binary search)
//  để xác định vị trí chính xác mà phần tử cần chèn vào trong dãy đã được sắp xếp, thay vì duyệt qua từng phần tử để tìm vị trí chèn
void BinaryInsertionSort_CIT07()
{
	for (int i = 1; i < TongSoPhanTuKhaoSat_CIT07; i++)
	{
		BKPHMC_CIT07 x = BOOKS_CIT07[i]; // phần tử cần chèn (key)
		int left = 0;					 // vị trí bắt đầu của dãy con cần xét
		int right = i - 1;				 // vị trí cuối của dãy con cần xét
		while (left <= right)
		{
			int mid = (left + right) / 2; // vị trí giữa của dãy con cần xét
			if (x.So_Lan_Muon_Sach_CIT07 < BOOKS_CIT07[mid].So_Lan_Muon_Sach_CIT07)
			{
				right = mid - 1; // dịch chuyển vị trí cuối của dãy con cần xét
			}
			else
			{
				left = mid + 1; // dịch chuyển vị trí bắt đầu của dãy con cần xét
			}
		}
		for (int j = i - 1; j >= left; j--)
		{
			BOOKS_CIT07[j + 1] = BOOKS_CIT07[j]; // dịch chuyển phần tử lớn hơn key 1 vị trí
		}
		BOOKS_CIT07[left] = x; // chèn key vào vị trí thích hợp
	}
	cout << "\n Danh sách đã được sắp xếp theo số lần mượn sách bằng pp BinaryInsertionSort:";
}

// [6] Bubble Sort with flag
/* Ví dụ minh họa chạy tay:
Cho dãy số: [5, 2, 8, 1, 3] là số lần mượn sách

Vòng lặp i = 0:
- j = 0: So sánh [5] với [2] -> Hoán đổi -> [2, 5, 8, 1, 3], flag = true
- j = 1: So sánh [5] với [8] -> Không đổi
- j = 2: So sánh [8] với [1] -> Hoán đổi -> [2, 5, 1, 8, 3], flag = true
- j = 3: So sánh [8] với [3] -> Hoán đổi -> [2, 5, 1, 3, 8], flag = true

Vòng lặp i = 1:
- j = 0: So sánh [2] với [5] -> Không đổi
- j = 1: So sánh [5] với [1] -> Hoán đổi -> [2, 1, 5, 3, 8], flag = true
- j = 2: So sánh [5] với [3] -> Hoán đổi -> [2, 1, 3, 5, 8], flag = true

Vòng lặp i = 2:
- j = 0: So sánh [2] với [1] -> Hoán đổi -> [1, 2, 3, 5, 8], flag = true
- j = 1: So sánh [2] với [3] -> Không đổi

Vòng lặp i = 3:
- j = 0: So sánh [1] với [2] -> Không đổi
flag = false -> Dừng thuật toán

Kết quả: [1, 2, 3, 5, 8]
*/
void BubbleSortWithFlag_CIT07()
{
	bool flag = true;
	for (int i = 0; i < TongSoPhanTuKhaoSat_CIT07; i++)
	{
		flag = false;
		for (int j = 0; j < TongSoPhanTuKhaoSat_CIT07 - i - 1; j++)
		{
			if (BOOKS_CIT07[j].So_Lan_Muon_Sach_CIT07 > BOOKS_CIT07[j + 1].So_Lan_Muon_Sach_CIT07)
			{
				HoanDoi_CIT07(BOOKS_CIT07[j], BOOKS_CIT07[j + 1]);
				flag = true;
			}
		}
		if (!flag)
		{
			break;
		}
	}
	cout << "\n Danh sách đã được sắp xếp theo số lần mượn sách bằng pp BubbleSortWithFag:";
}

// [7] Shaker Sort
/* Ví dụ minh họa chạy tay:
Cho dãy số lần mượn sách: [5, 2, 8, 1, 3]

Vòng lắp 1:
left = 0, right = 4
Quét từ trái sang phải (i = 0 -> 3):
So sánh 5 > 2 -> Hoán đổi -> [2, 5, 8, 1, 3]
So sánh 5 < 8 -> Không đổi
So sánh 8 > 1 -> Hoán đổi -> [2, 5, 1, 8, 3]
So sánh 8 > 3 -> Hoán đổi -> [2, 5, 1, 3, 8]
k = 3(vị trí hoán đổi cuói cùng), right = 3 = k
Quét từ phải sang trái (i = 3 -> 1):
So sánh 3 > 1 -> Hoán đổi -> [2, 5, 3, 1, 8]
So sánh 5 > 3 -> Hoán đổi -> [2, 3, 5, 1, 8]
k = 2, left = 2

Vòng lắp 2:
left = 2, right = 3
Quét từ trái sang phải:
So sánh 5 > 1 -> Hoán đổi -> [2, 3, 1, 5, 8]
k = 2, right = 2
Quét từ phải sang trái:
So sánh 1 < 3 -> Hoán đổi -> [2, 1, 3, 5, 8]
k = 1, left = 1

Vòng lắp 3:
left = 1, right = 2
Quét từ trái sang phải:
So sánh 1 < 3 -> Không đổi
k = 1, right = 1

Quét từ phải sang trái:
So sánh 1 < 2 -> Hoán đổi -> [1, 2, 3, 5, 8]
k = 1, left = 1
left = right -> Kết thúc

Kết quả: [1, 2, 3, 5, 8]
*/
void ShakerSort_CIT07()
{
	int left = 0;
	int right = TongSoPhanTuKhaoSat_CIT07 - 1;
	int k = 0;
	while (left < right)
	{
		// i = 0 -> n-2
		for (int i = left; i < right; i++)
		{
			if (BOOKS_CIT07[i].So_Lan_Muon_Sach_CIT07 > BOOKS_CIT07[i + 1].So_Lan_Muon_Sach_CIT07)
			{
				HoanDoi_CIT07(BOOKS_CIT07[i], BOOKS_CIT07[i + 1]);
				k = i; // lưu vị trí cuối cùng hoán đổi
			}
		}
		right = k;

		for (int i = right; i > left; i--)
		{
			if (BOOKS_CIT07[i].So_Lan_Muon_Sach_CIT07 < BOOKS_CIT07[i - 1].So_Lan_Muon_Sach_CIT07)
			{
				HoanDoi_CIT07(BOOKS_CIT07[i], BOOKS_CIT07[i - 1]);
				k = i;
			}
		}
		left = k;
	}
	cout << "\n Danh sách đã được sắp xếp theo số lần mượn sách bằng pp ShakerSort:";
}

// [8] Heap Sort
/*
Minh họa từng bước của Heap Sort
Cho mảng số lần mượn sách: [5, 2, 8, 1, 3]

Bước 1: Xây dựng Heap
	    5
	   / \
	  2   8
	 / \
	1   3

Heapify cây con gốc tại Index 1:
largest07 = 1  
l07 = 3
r07 = 4
So sánh a[l07] (1) với a[largest07] (2): không đổi
So sánh a[r07] (3) với a[largest07] (2): cập nhật largest07 = 4
Hoán đổi a[1] (2) với a[4] (3)
Mảng sau hoán đổi: [5, 3, 8, 1, 2]
	    5
	   / \
	  3   8
	 / \
	1   2

Heapify cây con gốc tại Index 0:
largest07 = 0
l07 = 1 
r07 = 2
So sánh a[l07] (3) với a[largest07] (5): không đổi
So sánh a[r07] (8) với a[largest07] (5): cập nhật largest07 = 2
Hoán đổi a[0] (5) với a[2] (8)
Mảng sau hoán đổi: [8, 3, 5, 1, 2] 
	    8
	   / \
	  3   5
	 / \
	1   2
-> xây dựng Heap hoàn chỉnh


Bước 2: Trích xuất phần tử từ Heap
Di chuyển gốc xuống cuối và Heapify:
Hoán đổi a[0] (8) với a[4] (2)
Mảng sau hoán đổi: [2, 3, 5, 1, 8]
	    2
	   / \
	  3   5
	 /
	1     8

Heapify cây con gốc tại index 0:
largest07 = 0
l07 = 1
r07 = 2
So sánh a[l07] (3) với a[largest07] (2): cập nhật largest07 = 1
So sánh a[r07] (5) với a[largest07] (3): cập nhật largest07 = 2
Hoán đổi a[0] (2) với a[2] (5)
Mảng sau hoán đổi: [5, 3, 2, 1, 8]
	    5
	   / \
	  3   2
	 /
	1     8

Di chuyển gốc xuống cuối và Heapify:
Hoán đổi a[0] (5) với a[3] (1)
Mảng sau hoán đổi: [1, 3, 2, 5, 8]
	    1
	   / \
	  3   2    5   8

Heapify cây con gốc tại index 0:
largest07 = 0
l07 = 1
r07 = 2
So sánh a[l07] (3) với a[largest07] (1): cập nhật largest07 = 1
So sánh a[r07] (2) với a[largest07] (3): không đổi
Hoán đổi a[0] (1) với a[1] (3)
Mảng sau hoán đổi: [3, 1, 2, 5, 8]
	    3
	   / \
	  1   2   5   8

Di chuyển gốc xuống cuối và Heapify:
Hoán đổi a[0] (3) với a[2] (2)
Mảng sau hoán đổi: [2, 1, 3, 5, 8]
	    2
	   /
	  1     3   5   8

Heapify cây con gốc tại index 0:
largest07 = 0
l07 = 1
r07 = 2
So sánh a[l07] (1) với a[largest07] (2): không đổi
Không cần hoán đổi

Di chuyển gốc xuống cuối:
Hoán đổi a[0] (2) với a[1] (1)
Mảng cuối cùng: [1, 2, 3, 5, 8]
	1
		  2   3   5   8

Kết quả sắp xếp cuối cùng: [1, 2, 3, 5, 8]
*/

void Heapify_CIT07(BKPHMC_CIT07 a[], int n, int i)
{
	int largest07 = i;   // khởi tạo largest07 là root
	int l07 = 2 * i + 1; // left = 2*i + 1
	int r07 = 2 * i + 2; // right = 2*i + 2

	// nếu left lớn hơn root
	if (l07 < n && a[l07].So_Lan_Muon_Sach_CIT07 > a[largest07].So_Lan_Muon_Sach_CIT07)
	{
		largest07 = l07;
	}

	// nếu right lớn hơn root
	if (r07 < n && a[r07].So_Lan_Muon_Sach_CIT07 > a[largest07].So_Lan_Muon_Sach_CIT07)
	{
		largest07 = r07;
	}

	// nếu largest07 không phải là root
	if (largest07 != i)
	{
		HoanDoi_CIT07(a[i], a[largest07]);

		// đệ quy heapify the subtree
		Heapify_CIT07(a, n, largest07);
	}
}

void Heap_Sort_CIT07()
{
	// xây dựng heap (rearrange array)
	for (int i = TongSoPhanTuKhaoSat_CIT07 / 2 - 1; i >= 0; i--)
	{
		Heapify_CIT07(BOOKS_CIT07, TongSoPhanTuKhaoSat_CIT07, i);
	}

	// trích xuất từng phần tử từ heap
	for (int i = TongSoPhanTuKhaoSat_CIT07 - 1; i > 0; i--)
	{
		// di chuyển root hiện tại đến cuối mảng
		HoanDoi_CIT07(BOOKS_CIT07[0], BOOKS_CIT07[i]);

		// gọi max heapify trên heap giảm dần
		Heapify_CIT07(BOOKS_CIT07, i, 0);
	}
	cout << "\n Danh sách đã được sắp xếp theo số lần mượn sách bằng pp HeapSort:";
}

// [9] Shell Sort
/*
Mảng Ban đầu
Index:  0  1  2  3  4
Array: [5, 2, 8, 1, 3]
Bước 1: Tính khoảng cách ban đầu 
Khoảng cách ban đầu = TongSoPhanTuKhaoSat_CIT07 / 2 = 5 / 2 = 2.

Bước 2: Lần duyệt đầu tiên với khoảng cách 2
Mảng con bắt đầu từ chỉ số 2:
temp = 8
So sánh 8 với 5 (không cần đổi chỗ).

Mảng con bắt đầu từ chỉ số 3:
temp = 1
So sánh 1 với 2 (cần đổi chỗ).
Mảng sau khi đổi chỗ: [5, 2, 8, 2, 3]
Đặt 1 tại vị trí 1.
Mảng sau khi đặt: [5, 1, 8, 2, 3]

Mảng con bắt đầu từ chỉ số 4:
temp = 3
So sánh 3 với 8 (cần đổi chỗ).
Mảng sau khi đổi chỗ: [5, 1, 8, 2, 8]
Đặt 3 tại vị trí 2.
Mảng sau khi đặt: [5, 1, 3, 2, 8]

Mảng Sau Lần Duyệt Đầu Tiên
Index:  0  1  2  3  4
Array: [5, 1, 3, 2, 8]
Bước 3: Lần duyệt thứ hai với khoảng cách 1 
Khoảng cách = 2 / 2 = 1.

Mảng con bắt đầu từ chỉ số 1:
temp = 1
So sánh 1 với 5 (cần đổi chỗ).
Mảng sau khi đổi chỗ: [5, 5, 3, 2, 8]
Đặt 1 tại vị trí 0.
Mảng sau khi đặt: [1, 5, 3, 2, 8]

Mảng con bắt đầu từ chỉ số 2:
temp = 3
So sánh 3 với 5 (cần đổi chỗ).
Mảng sau khi đổi chỗ: [1, 5, 5, 2, 8]
Đặt 3 tại vị trí 1.
Mảng sau khi đặt: [1, 3, 5, 2, 8]

Mảng con bắt đầu từ chỉ số 3:
temp = 2
So sánh 2 với 5 (cần đổi chỗ).
Mảng sau khi đổi chỗ: [1, 3, 5, 5, 8]
So sánh 2 với 3 (cần đổi chỗ).
Mảng sau khi đổi chỗ: [1, 3, 3, 5, 8]
Đặt 2 tại vị trí 1.
Mảng sau khi đặt: [1, 2, 3, 5, 8]

Mảng con bắt đầu từ chỉ số 4:
temp = 8
So sánh 8 với 5 (không cần đổi chỗ).

Mảng Sau Lần Duyệt Thứ Hai
Index:  0  1  2  3  4
Array: [1, 2, 3, 5, 8]
Mảng Đã Sắp Xếp Cuối Cùng
Index:  0  1  2  3  4
Array: [1, 2, 3, 5, 8]
*/
void ShellSort_CIT07()
{
	// bắt đầu với khoảng cách lớn, sau đó dần dần giảm khoảng cách
	for (int gap = TongSoPhanTuKhaoSat_CIT07 / 2; gap > 0; gap /= 2)
	{
		 // thực hiện insertion sort cho từng khoảng cách
		 // (a[i], a[i+gap], a[i+2*gap],...)
		 // đến khi gap = 1, thực hiện insertion sort cho toàn bộ mảng
		for (int i = gap; i < TongSoPhanTuKhaoSat_CIT07; i += 1)
		{
			// lưu a[i] trong temp và tạo một lỗ tại vị trí i
			// để a[i] có thể di chuyển đến vị trí đúng
			BKPHMC_CIT07 temp = BOOKS_CIT07[i];

			// di chuyển các phần tử của sub-array đã sắp xếp
			int j;
			for (j = i; j >= gap && BOOKS_CIT07[j - gap].So_Lan_Muon_Sach_CIT07 > temp.So_Lan_Muon_Sach_CIT07; j -= gap)
			{
				BOOKS_CIT07[j] = BOOKS_CIT07[j - gap];
			}

			// đặt temp (phần tử tạm thời) vào vị trí đúng
			BOOKS_CIT07[j] = temp;
		}
	}
	cout << "\n Danh sách đã được sắp xếp theo số lần mượn sách bằng pp ShellSort:";
}

// [7] Quik Sort
// Bước 1: giả sử arr là mảng lưu số lần mượn sách các phần tử arr = [-4, 1, -9, 22, 3, 14, 8, -2, 4, 99]
// Bước 2: Chạy thuật toán Quick Sort
// Gọi hàm QuikSort_CIT07(arr, 0, n-1)
// Lần gọi đầu tiên: QuikSort_CIT07(arr, 0, 9)
// left = 0, right = 9
// pivot = arr[(0 + 9) / 2] = arr[4] = 3
// Khởi tạo i = 0, j = 9
// Phân hoạch mảng:

// arr[i] = -4 < pivot → tăng i → i = 1
// arr[j] = 99 > pivot → giảm j → j = 8
// arr[i] = 1 < pivot → tăng i → i = 2
// arr[j] = 4 > pivot → giảm j → j = 7
// arr[i] = -9 < pivot → tăng i → i = 3
// arr[j] = -2 < pivot → giảm j → j = 6
// arr[i] = 22 > pivot → i không tăng
// arr[j] = 8 > pivot → giảm j → j = 5
// arr[i] = 22 > pivot → i không tăng
// arr[j] = 14 > pivot → giảm j → j = 4
// Hoán đổi arr[i] và arr[j] → arr = [-4, 1, -9, -2, 3, 14, 8, 22, 4, 99]
// Tăng i → i = 4, giảm j → j = 3
// Kết thúc phân hoạch:

// i = 4, j = 3
// Gọi đệ quy QuikSort_CIT07(arr, 0, 3) và QuikSort_CIT07(arr, 4, 9)
// Lần gọi thứ hai: QuikSort_CIT07(arr, 0, 3)
// left = 0, right = 3
// pivot = arr[(0 + 3) / 2] = arr[1] = 1
// Khởi tạo i = 0, j = 3
// Phân hoạch mảng:

// arr[i] = -4 < pivot → tăng i → i = 1
// arr[j] = -2 < pivot → giảm j → j = 2
// arr[i] = 1 = pivot → tăng i → i = 2
// arr[j] = -9 < pivot → giảm j → j = 1
// Hoán đổi arr[i] và arr[j] → arr = [-4, -9, 1, -2, 3, 14, 8, 22, 4, 99]
// Tăng i → i = 3, giảm j → j = 0
// Kết thúc phân hoạch:

// i = 3, j = 0
// Gọi đệ quy QuikSort_CIT07(arr, 0, 0) và QuikSort_CIT07(arr, 2, 3)
// Lần gọi thứ ba: QuikSort_CIT07(arr, 2, 3)
// left = 2, right = 3
// pivot = arr[(2 + 3) / 2] = arr[2] = 1
// Khởi tạo i = 2, j = 3
// Phân hoạch mảng:

// arr[i] = 1 = pivot → tăng i → i = 3
// arr[j] = -2 < pivot → giảm j → j = 2
// Hoán đổi arr[i] và arr[j] → arr = [-4, -9, -2, 1, 3, 14, 8, 22, 4, 99]
// Tăng i → i = 4, giảm j → j = 1
// Kết thúc phân hoạch:

// i = 4, j = 1
// Gọi đệ quy QuikSort_CIT07(arr, 2, 1) và QuikSort_CIT07(arr, 3, 3)
// Lần gọi thứ tư: QuikSort_CIT07(arr, 4, 9)
// left = 4, right = 9
// pivot = arr[(4 + 9) / 2] = arr[6] = 8
// Khởi tạo i = 4, j = 9
// Phân hoạch mảng:

// arr[i] = 3 < pivot → tăng i → i = 5
// arr[j] = 99 > pivot → giảm j → j = 8
// arr[i] = 14 > pivot → i không tăng
// arr[j] = 4 < pivot → giảm j → j = 7
// arr[i] = 14 > pivot → i không tăng
// arr[j] = 22 > pivot → giảm j → j = 6
// Hoán đổi arr[i] và arr[j] → arr = [-4, -9, -2, 1, 3, 4, 8, 22, 14, 99]
// Tăng i → i = 6, giảm j → j = 5
// Kết thúc phân hoạch:

// i = 6, j = 5
// Gọi đệ quy QuikSort_CIT07(arr, 4, 5) và QuikSort_CIT07(arr, 7, 9)
// Lần gọi thứ năm: QuikSort_CIT07(arr, 4, 5)
// left = 4, right = 5
// pivot = arr[(4 + 5) / 2] = arr[4] = 3
// Khởi tạo i = 4, j = 5
// Phân hoạch mảng:

// arr[i] = 3 = pivot → tăng i → i = 5
// arr[j] = 4 > pivot → giảm j → j = 4
// Hoán đổi arr[i] và arr[j] → arr = [-4, -9, -2, 1, 3, 4, 8, 22, 14, 99]
// Tăng i → i = 6, giảm j → j = 3
// Kết thúc phân hoạch:

// i = 6, j = 3
// Gọi đệ quy QuikSort_CIT07(arr, 4, 3) và QuikSort_CIT07(arr, 5, 5)
// Lần gọi thứ sáu: QuikSort_CIT07(arr, 7, 9)
// left = 7, right = 9
// pivot = arr[(7 + 9) / 2] = arr[8] = 14
// Khởi tạo i = 7, j = 9
// Phân hoạch mảng:

// arr[i] = 22 > pivot → i không tăng
// arr[j] = 99 > pivot → giảm j → j = 8
// arr[i] = 22 > pivot → i không tăng
// arr[j] = 14 = pivot → giảm j → j = 7
// Hoán đổi arr[i] và arr[j] → arr = [-4, -9, -2, 1, 3, 4, 8, 14, 22, 99]
// Tăng i → i = 8, giảm j → j = 6
// Kết thúc phân hoạch:

// i = 8, j = 6
// Gọi đệ quy QuikSort_CIT07(arr, 7, 6) và QuikSort_CIT07(arr, 8, 9)
// Lần gọi thứ bảy: QuikSort_CIT07(arr, 8, 9)
// left = 8, right = 9
// pivot = arr[(8 + 9) / 2] = arr[8] = 22
// Khởi tạo i = 8, j = 9
// Phân hoạch mảng:

// arr[i] = 22 = pivot → tăng i → i = 9
// arr[j] = 99 > pivot → giảm j → j = 8
// Hoán đổi arr[i] và arr[j] → arr = [-4, -9, -2, 1, 3, 4, 8, 14, 22, 99]
// Tăng i → i = 10, giảm j → j = 7
// Kết thúc phân hoạch:

// i = 10, j = 7
// Gọi đệ quy QuikSort_CIT07(arr, 8, 7) và QuikSort_CIT07(arr, 9, 9)
// Kết quả cuối cùng: Mang da sap xep: -9 -4 -2 1 3 4 8 14 22 99

void QuikSort_CIT07(BKPHMC_CIT07 a[], int left, int right)
{
	int i = left, j = right;								  // khởi tạo i, j
	int pivot = a[(left + right) / 2].So_Lan_Muon_Sach_CIT07; // chọn pivot

	// phân hoạch mảng
	while (i <= j)
	{
		while (a[i].So_Lan_Muon_Sach_CIT07 < pivot)
		{
			i++; // tìm phần tử lớn hơn pivot
		}
		while (a[j].So_Lan_Muon_Sach_CIT07 > pivot)
		{
			j--; // tìm phần tử nhỏ hơn pivot
		}
		if (i <= j)
		{
			HoanDoi_CIT07(a[i], a[j]);
			i++;
			j--;
		}
	}

	// gọi đệ quy cho 2 phần: trước pivot và sau pivot
	if (left < j)
	{
		QuikSort_CIT07(a, left, j);
	}
	if (i < right)
	{
		QuikSort_CIT07(a, i, right);
	}
}

// [8] Straight Merge Sort
/*
Mảng Ban đầu 
Index:  0   1   2   3   4   5   6   7   8   9
Array: [-4, 1, -9, 22, 3, 14, 8, -2, 4, 99]
Bước 1: Chia mảng
Phân chia đầu tiên:
Trái: 0
Phải: 9 
Giữa: 4
Chia thành hai mảng con: [-4, 1, -9, 22, 3] và [14, 8, -2, 4, 99]

Phân chia thứ hai (Mảng con bên trái):
Trái: 0
Phải: 4
Giữa: 2 
Chia thành hai mảng con: [-4, 1, -9] và [22, 3]

Phân chia thứ ba (Mảng con bên trái của mảng con bên trái):
Trái: 0
Phải: 2
Giữa: 1
Chia thành hai mảng con: [-4, 1] và [-9]

Phân chia thứ tư (Mảng con bên trái của mảng con bên trái của mảng con bên trái):
Trái: 0
Phải: 1
Giữa: 0
Chia thành hai mảng con: [-4] và [1]

Bước 2: Trộn các mảng con
Trộn [-4] và [1]:

So sánh -4 và 1
Kết quả: [-4, 1]

Trộn [-4, 1] và [-9]:

So sánh -4 và -9
So sánh 1 và -9
Kết quả: [-9, -4, 1]

Trộn [22] và [3]:

So sánh 22 và 3
Kết quả: [3, 22]

Trộn [-9, -4, 1] và [3, 22]:
So sánh -9 và 3
So sánh -4 và 3
So sánh 1 và 3
So sánh 1 và 22
Kết quả: [-9, -4, 1, 3, 22]

Phân chia thứ hai (Mảng con bên phải):
Trái: 5
Phải: 9
Giữa: 7
Chia thành hai mảng con: [14, 8, -2] và [4, 99]
Phân chia thứ ba (Mảng con bên trái của mảng con bên phải):
Trái: 5
Phải: 7
Giữa: 6
Chia thành hai mảng con: [14, 8] và [-2]

Phân chia thứ tư (Mảng con bên trái của mảng con bên trái của mảng con bên phải):
Trái: 5
Phải: 6
Giữa: 5
Chia thành hai mảng con: [14] và [8]
Trộn [14] và [8]:

So sánh 14 và 8
Kết quả: [8, 14]

Trộn [8, 14] và [-2]:
So sánh 8 và -2
So sánh 14 và -2
Kết quả: [-2, 8, 14]

Trộn [4] và [99]:

So sánh 4 và 99
Kết quả: [4, 99]

Trộn [-2, 8, 14] và [4, 99]:

So sánh -2 và 4
So sánh 8 và 4
So sánh 8 và 99
So sánh 14 và 99
Kết quả: [-2, 4, 8, 14, 99]

Trộn [-9, -4, 1, 3, 22] và [-2, 4, 8, 14, 99]:

So sánh -9 và -2
So sánh -4 và -2
So sánh 1 và -2
So sánh 1 và 4
So sánh 3 và 4
So sánh 22 và 4
So sánh 22 và 8
So sánh 22 và 14
So sánh 22 và 99
Kết quả: [-9, -4, -2, 1, 3, 4, 8, 14, 22, 99]

*/

void StraightMergeSort_CIT07(BKPHMC_CIT07 a[], int left, int right)
{
	if (left < right)
	{
		int mid = left + (right - left) / 2;		// tìm điểm chia (luôn nằm giữa left và right)
		StraightMergeSort_CIT07(a, left, mid);		// sắp xếp nửa trái
		StraightMergeSort_CIT07(a, mid + 1, right); // sắp xếp nửa phải
		// gộp 2 nửa đã sắp xếp
		int i = left, j = mid + 1, k = 0;
		BKPHMC_CIT07 temp[right - left + 1]; // mảng tạm
		while (i <= mid && j <= right)
		{
			if (a[i].So_Lan_Muon_Sach_CIT07 < a[j].So_Lan_Muon_Sach_CIT07)
			{
				temp[k++] = a[i++];
			}
			else
			{
				temp[k++] = a[j++];
			}
		}
		while (i <= mid)
		{
			temp[k++] = a[i++]; // gộp phần còn lại của nửa trái
		}
		while (j <= right)
		{
			temp[k++] = a[j++]; // gộp phần còn lại của nửa phải
		}
		for (int i = left; i <= right; i++)
		{
			a[i] = temp[i - left]; // copy mảng tạm vào mảng chính
		}
	}
}

// [12] Natural Merge Sort
/*
Mảng Ban Đầu: [-4, 1, -9, 22, 3, 14, 8, -2, 4, 99]
112, 2231, 2321, 2241, 2314, 9211,2134, 2228, 2224, 2299
Lượt Đầu Tiên:
Xác định các mảng con:
[-4, 1] (tăng dần)
[-9] (giảm dần)
[22, 3] (tăng dần) 
[14, 8] (giảm dần)
[-2, 4, 99] (tăng dần)

Gộp các mảng con:
[-4, 1, -9] -> [-9, -4, 1]
[22, 3, 14, 8] -> [3, 8, 14, 22] 
[-2, 4, 99] giữ nguyên

Lượt Thứ Hai:
Xác định các mảng con:
[-9, -4, 1] (tăng dần)
[3, 8, 14, 22] (tăng dần)
[-2, 4, 99] (tăng dần)

Gộp các mảng con:
[-9, -4, 1, 3, 8, 14, 22]
[-2, 4, 99]

Lượt Cuối Cùng:
Gộp các mảng con còn lại:
[-9, -4, 1, 3, 8, 14, 22, -2, 4, 99] -> [-9, -4, -2, 1, 3, 4, 8, 14, 22, 99]

Mảng Đã Sắp Xếp Cuối Cùng:
[-9, -4, -2, 1, 3, 4, 8, 14, 22, 99]
*/

// Thuật toán sử dụng việc chia mảng thành các mảng con tự nhiên dựa trên sự tăng/giảm liên tiếp trong danh sách.
// Sau đó, các mảng con này được sắp xếp và gộp lại thành mảng hoàn chỉnh bằng thuật toán StraightMergeSort_CIT07.
void NaturalMergeSort_CIT07()
{
	
	int left = 0;  // vị trí bắt đầu của mảng con
	int right = 0; // vị trí cuối của mảng con
	int mid = 0;   // vị trí giữa của mảng con
	int i = 0;	   // vị trí hiện tại của mảng con
	while (i < TongSoPhanTuKhaoSat_CIT07 - 1)
	{
		left = i; // vị trí bắt đầu của mảng con
		while (i < TongSoPhanTuKhaoSat_CIT07 - 1 && BOOKS_CIT07[i].So_Lan_Muon_Sach_CIT07 <= BOOKS_CIT07[i + 1].So_Lan_Muon_Sach_CIT07)
		{
			i++; // tìm vị trí cuối của mảng con
		}
		mid = i; // vị trí giữa của mảng con
		while (i < TongSoPhanTuKhaoSat_CIT07 - 1 && BOOKS_CIT07[i].So_Lan_Muon_Sach_CIT07 >= BOOKS_CIT07[i + 1].So_Lan_Muon_Sach_CIT07)
		{
			i++; // tìm vị trí cuối của mảng con
		}
		right = i;										   // vị trí cuối của mảng con
		StraightMergeSort_CIT07(BOOKS_CIT07, left, right); // sắp xếp mảng con
	}
	cout << "\n Danh sách đã được sắp xếp theo số lần mượn sách bằng pp NaturalMergeSor:";
}

// [9] Counting Sort
// Bước 1: Khởi tạo: giả sử ta có số lần mượn sách được cho vào 1 mảng arr =[2, 5, 3, 0, 2, 3, 0, 3].
// Bước 2: Tìm phần tử lớn nhất
// max = 5
// Bước 3: Khởi tạo mảng đếm
// count = [0, 0, 0, 0, 0, 0] (kích thước max + 1)
// Bước 4: Đếm số lần xuất hiện của mỗi phần tử
// count[2]++ → count = [0, 0, 1, 0, 0, 0]
// count[5]++ → count = [0, 0, 1, 0, 0, 1]
// count[3]++ → count = [0, 0, 1, 1, 0, 1]
// count[0]++ → count = [1, 0, 1, 1, 0, 1]
// count[2]++ → count = [1, 0, 2, 1, 0, 1]
// count[3]++ → count = [1, 0, 2, 2, 0, 1]
// count[0]++ → count = [2, 0, 2, 2, 0, 1]
// count[3]++ → count = [2, 0, 2, 3, 0, 1]
// Bước 5: Cập nhật mảng đếm
// count[1] += count[0] → count = [2, 2, 2, 3, 0, 1]
// count[2] += count[1] → count = [2, 2, 4, 3, 0, 1]
// count[3] += count[2] → count = [2, 2, 4, 7, 0, 1]
// count[4] += count[3] → count = [2, 2, 4, 7, 7, 1]
// count[5] += count[4] → count = [2, 2, 4, 7, 7, 8]
// Bước 6: Xếp phần tử vào mảng kết quả
// output[count[3] - 1] = 3 → output = [0, 0, 0, 0, 0, 0, 3, 0] → count = [2, 2, 4, 6, 7, 8]
// output[count[0] - 1] = 0 → output = [0, 0, 0, 0, 0, 0, 3, 0] → count = [1, 2, 4, 6, 7, 8]
// output[count[3] - 1] = 3 → output = [0, 0, 0, 0, 0, 3, 3, 0] → count = [1, 2, 4, 5, 7, 8]
// output[count[2] - 1] = 2 → output = [0, 0, 0, 2, 0, 3, 3, 0] → count = [1, 2, 3, 5, 7, 8]
// output[count[0] - 1] = 0 → output = [0, 0, 0, 2, 0, 3, 3, 0] → count = [0, 2, 3, 5, 7, 8]
// output[count[3] - 1] = 3 → output = [0, 0, 0, 2, 3, 3, 3, 0] → count = [0, 2, 3, 4, 7, 8]
// output[count[5] - 1] = 5 → output = [0, 0, 0, 2, 3, 3, 3, 5] → count = [0, 2, 3, 4, 7, 7]
// output[count[2] - 1] = 2 → output = [0, 0, 2, 2, 3, 3, 3, 5] → count = [0, 2, 2, 4, 7, 7]
// Bước 7: Sao chép mảng kết quả vào mảng chính
// arr = [0, 0, 2, 2, 3, 3, 3, 5]
void CountingSort_CIT07()
{
	int max = BOOKS_CIT07[0].So_Lan_Muon_Sach_CIT07;
	for (int i = 1; i < TongSoPhanTuKhaoSat_CIT07; i++)
	{
		if (BOOKS_CIT07[i].So_Lan_Muon_Sach_CIT07 > max)
		{
			max = BOOKS_CIT07[i].So_Lan_Muon_Sach_CIT07; // tìm phần tử lớn nhất
		}
	}
	int count[max + 1];								// mảng đếm
	BKPHMC_CIT07 output[TongSoPhanTuKhaoSat_CIT07]; // mảng kết quả
	for (int i = 0; i <= max; i++)
	{
		count[i] = 0; // khởi tạo mảng đếm
	}
	for (int i = 0; i < TongSoPhanTuKhaoSat_CIT07; i++)
	{
		count[BOOKS_CIT07[i].So_Lan_Muon_Sach_CIT07]++; // đếm số lần xuất hiện
	}
	for (int i = 1; i <= max; i++)
	{
		count[i] += count[i - 1]; // xác định vị trí chính xác của phần tử(thông qua số phần tử mà nó lớn hơn bằng cách cộng dồn)
	}
	for (int i = TongSoPhanTuKhaoSat_CIT07 - 1; i >= 0; i--)
	{
		output[count[BOOKS_CIT07[i].So_Lan_Muon_Sach_CIT07] - 1] = BOOKS_CIT07[i]; // xếp phần tử vào mảng kết quả
		count[BOOKS_CIT07[i].So_Lan_Muon_Sach_CIT07]--;							   // giảm số lần xuất hiện
	}
	for (int i = 0; i < TongSoPhanTuKhaoSat_CIT07; i++)
	{
		BOOKS_CIT07[i] = output[i]; // copy mảng kết quả vào mảng chính
	}
	cout << "Danh sách đã được sắp theo số lần mượn sách bằng pp Counting Sort.\n";
}

// [10] Radix Sort
/*
Thực thi từng bước:
Mảng ban đầu: [170, 45, 75, 90, 802, 24, 2, 66]

Lượt thứ nhất (exp = 1):

Đếm số lần xuất hiện của mỗi chữ số ở vị trí đơn vị:
count = [2, 0, 2, 0, 1, 2, 1, 0, 0, 0]
Cập nhật mảng đếm:
count = [2, 2, 4, 4, 5, 7, 8, 8, 8, 8]
Xây dựng mảng kết quả:
output = [170, 90, 802, 2, 24, 45, 75, 66] 
Sao chép mảng kết quả vào mảng gốc:
arr = [170, 90, 802, 2, 24, 45, 75, 66]

Lượt thứ hai (exp = 10):

Đếm số lần xuất hiện của mỗi chữ số ở vị trí chục:
count = [2, 0, 1, 0, 1, 0, 1, 2, 0, 1]
Cập nhật mảng đếm:
count = [2, 2, 3, 3, 4, 4, 5, 7, 7, 8]
Xây dựng mảng kết quả:
output = [802, 2, 24, 45, 66, 170, 75, 90]
Sao chép mảng kết quả vào mảng gốc:
arr = [802, 2, 24, 45, 66, 170, 75, 90]

Lượt thứ ba (exp = 100):

Đếm số lần xuất hiện của mỗi chữ số ở vị trí trăm:
count = [6, 1, 0, 0, 0, 0, 0, 0, 1, 0]
Cập nhật mảng đếm:
count = [6, 7, 7, 7, 7, 7, 7, 7, 8, 8]
Xây dựng mảng kết quả:
output = [2, 24, 45, 66, 75, 90, 170, 802]
Sao chép mảng kết quả vào mảng gốc:
arr = [2, 24, 45, 66, 75, 90, 170, 802]

Mảng đã sắp xếp cuối cùng:
[2, 24, 45, 66, 75, 90, 170, 802]
*/
void RadixSort_CIT07()
{
	int max = BOOKS_CIT07[0].So_Lan_Muon_Sach_CIT07;
	for (int i = 1; i < TongSoPhanTuKhaoSat_CIT07; i++)
	{
		if (BOOKS_CIT07[i].So_Lan_Muon_Sach_CIT07 > max)
		{
			max = BOOKS_CIT07[i].So_Lan_Muon_Sach_CIT07; // tìm phần tử lớn nhất
		}
	}
	for (int exp = 1; max / exp > 0; exp *= 10)
	{
		BKPHMC_CIT07 output[TongSoPhanTuKhaoSat_CIT07]; // mảng kết quả
		int count[10] = {0}; // mảng đếm
		for (int i = 0; i < TongSoPhanTuKhaoSat_CIT07; i++)
		{
			count[(BOOKS_CIT07[i].So_Lan_Muon_Sach_CIT07 / exp) % 10]++; // đếm số lần xuất hiện
		}
		for (int i = 1; i < 10; i++)
		{
			count[i] += count[i - 1]; // cập nhật mảng đếm
		}
		for (int i = TongSoPhanTuKhaoSat_CIT07 - 1; i >= 0; i--)
		{
			output[count[(BOOKS_CIT07[i].So_Lan_Muon_Sach_CIT07 / exp) % 10] - 1] = BOOKS_CIT07[i]; // xếp phần tử vào mảng kết quả
			count[(BOOKS_CIT07[i].So_Lan_Muon_Sach_CIT07 / exp) % 10]--; // giảm số lần xuất hiện
		}
		for (int i = 0; i < TongSoPhanTuKhaoSat_CIT07; i++)
		{
			BOOKS_CIT07[i] = output[i]; // copy mảng kết quả vào mảng chính
		}
	}
	cout << "Danh sách đã được sắp theo số lần mượn sách bằng pp Radix Sort.\n";
}

/**********************************************/
// CHƯƠNG TRÌNH CHÍNH
/**********************************************/

int main()
{
	cout << "Bạn muốn tự khởi tạo(N) hay lấy dữ liệu mẫu(Y): ";
	char choose;
	cin >> choose;

	if (choose == 'N')
	{
		KhoiTao_CIT07();
		Nhapds_CIT07();
		Inds_CIT07();
	}
	else
	{
		// Dữ liệu mãu
		BKPHMC_CIT07 sampleBooks[4];
		string Name[4] = {"Toan Hoc", "CTDL & GT", "Kinh Te Hoc", "OOP"};
		string Type[4] = {"KHTN", "IT", "ECO", "IT"};
		string Code[4] = {"KHTN_01_23", "IT_08_23", "ECO_02_23", "IT_04_23"};
		int Count[4] = {192, 221, 187, 321};

		for (int i = 0; i < 4; i++)
		{
			sampleBooks[i].Ten_Sach_CIT07 = Name[i];
			sampleBooks[i].Loai_Sach_CIT07 = Type[i];
			sampleBooks[i].Ma_Sach_CIT07 = Code[i];
			sampleBooks[i].So_Lan_Muon_Sach_CIT07 = Count[i];
			BOOKS_CIT07[TongSoPhanTuKhaoSat_CIT07++] = sampleBooks[i]; // Thêm vào danh sách toàn cục
		}
		Inds_CIT07();
	}

	cout << "Nhấn phím bất kỳ để tiếp tục: ";
	cin.ignore(); // xóa các kí tự trươc đó
	cin.get();	  // Nhập phím bất kì

	char LuaChon;
	while (true)
	{
		cout << "CÁC GIẢI THUẬT SẮP XẾP NỘI TRÊN DANH SÁCH SÁCH [ĐẶC]\n";
		cout << "1. Sắp xếp theo giải thuật ĐỔI CHỖ trực tiếp [Straight Interchange Sort]\n";
		cout << "2. Sắp xếp theo giải thuật NỔI BỌT BONG BÓNG [Bubble Sort]\n";
		cout << "3. Sắp xếp theo giải thuật CHỌN trực tiếp [Straight Selection Sort]\n";
		cout << "4. Sắp xếp theo giải thuật CHÈN trực tiếp [Straight Insertion Sort]\n";
		cout << "5. Sắp xếp theo giải thuật CHÈN NHỊ PHÂN  [Binary Insertion Sort]\n";
		cout << "6. Sắp xếp theo giải thuật NỔI BỌT CÓ CỜ [Bubble Sort With Flag]\n";
		cout << "7. Sắp xếp theo giải thuật NHANH [Quick Sort]\n";
		cout << "8. Sắp xếp theo giải thuật TRỘN trực tiếp [Straight Merge Sort]\n";
		cout << "9. Sắp xếp theo giải thuật ĐẾM [Counting Sort]\n";
		cout << "q. Thoát\n";
		cout << "Nhập lựa chọn của bạn: ";
		cin >> LuaChon;

		switch (LuaChon)
		{
		case '1':
			cout << "Danh sách trước khi sắp xếp theo số lần mượn sách:";
			Inds_CIT07();
			InterchangeSort_CIT07();
			Inds_CIT07();
			break;
		case '2':
			cout << "Danh sách trước khi sắp xếp theo số lần mượn sách:";
			Inds_CIT07();
			BubleSort_CIT07();
			Inds_CIT07();
			break;
		case '3':
			cout << "Danh sách trước khi sắp xếp theo số lần mượn sách:";
			Inds_CIT07();
			StraightSlectionSort_CIT07();
			Inds_CIT07();
			break;
		case '4':
			cout << "Danh sách trước khi sắp xếp theo số lần mượn sách:";
			Inds_CIT07();
			StraightInsertionSort_CIT07();
			Inds_CIT07();
			break;
		case '5':
			cout << "Danh sách trước khi sắp xếp theo số lần mượn sách:";
			Inds_CIT07();
			BinaryInsertionSort_CIT07();
			Inds_CIT07();
			break;
		case '6':
			cout << "Danh sách trước khi sắp xếp theo số lần mượn sách:";
			Inds_CIT07();
			BubbleSortWithFlag_CIT07();
			Inds_CIT07();
			break;
		case '7':
			cout << "Danh sách trước khi sắp xếp theo số lần mượn sách:";
			Inds_CIT07();
			QuikSort_CIT07(BOOKS_CIT07, 0, TongSoPhanTuKhaoSat_CIT07 - 1);
			cout << "\n Danh sách đã được sắp xếp theo số lần mượn sách bằng pp StraightMergeSort:";
			Inds_CIT07();
			break;
		case '8':
			cout << "Danh sách trước khi sắp xếp theo số lần mượn sách:";
			Inds_CIT07();
			StraightMergeSort_CIT07(BOOKS_CIT07, 0, TongSoPhanTuKhaoSat_CIT07 - 1);
			cout << "\n Danh sách đã được sắp xếp theo số lần mượn sách bằng pp StraightMergeSort:";
			Inds_CIT07();
			break;
		case '9':
			cout << "Danh sách trước khi sắp xếp theo số lần mượn sách:";
			Inds_CIT07();
			CountingSort_CIT07();
			Inds_CIT07();
			break;
		}
	}
}
