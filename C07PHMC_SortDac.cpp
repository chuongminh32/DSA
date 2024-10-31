/******************************/
/**KHAI BAO THU VIEN SU DUNG */
/******************************/
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

	for (int i=0; i<TongSoPhanTuKhaoSat_CIT07; i++) {
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
void Inds_CIT07() {
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


// [1] Sắp xếp danh sách theo số lần mượn sách (So_Lan_Muon_Sach_CIT07) bằng Interchange Sort 
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

// [2] Sắp xếp danh sách theo số lần mượn sách (So_Lan_Muon_Sach_CIT07) bằng Buble Sort 
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

// [3] Sắp xếp danh sách theo số lần mượn sách (So_Lan_Muon_Sach_CIT07) bằng Straight Selection Sort 
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

// [4] Sắp xếp danh sách theo số lần mượn sách (So_Lan_Muon_Sach_CIT07) bằng Straight Insertion Sort 
void StraightInsertionSort_CIT07()
{
	for (int i = 1; i < TongSoPhanTuKhaoSat_CIT07; i++)
	{
		BKPHMC_CIT07 x = BOOKS_CIT07[i]; // phần tử cần chèn (key)
		int j = i - 1; // vị trí phần tử trước key
		while (j >= 0 && BOOKS_CIT07[j].So_Lan_Muon_Sach_CIT07 > x.So_Lan_Muon_Sach_CIT07)
		{
			BOOKS_CIT07[j + 1] = BOOKS_CIT07[j]; // dịch chuyển phần tử lớn hơn key 1 vị trí
			j--; // giảm vị trí để xét tiếp
		}
		BOOKS_CIT07[j + 1] = x; // chèn key vào vị trí thích hợp
	}
	cout << "\n Danh sách đã được sắp xếp theo số lần mượn sách bằng pp StraightInsertinSort:";
}

// [5] Sắp xếp danh sách theo số lần mượn sách (So_Lan_Muon_Sach_CIT07) bằng Binary Insertion Sort
void BinaryInsertionSort_CIT07()
{
	for (int i = 1; i < TongSoPhanTuKhaoSat_CIT07; i++)
	{
		BKPHMC_CIT07 x = BOOKS_CIT07[i]; // phần tử cần chèn (key)
		int left = 0; // vị trí bắt đầu của dãy con cần xét
		int right = i - 1; // vị trí cuối của dãy con cần xét
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

// // [7] Shaker Sort 
// void ShakerSort_CIT07()
// {
// 	int left = 0; // vị trí bắt đầu
// 	int right = TongSoPhanTuKhaoSat_CIT07 - 1; // vị trí cuối
// 	int k = 0; // vị trí cuối của phần tử đã sắp xếp
// 	while (left < right) 
// 	{
// 		// đẩy phần tử lớn nhất về cuối -> cập nhật vị trí cuối
// 		for (int i = left; i < right; i++)
// 		{
// 			if (BOOKS_CIT07[i].So_Lan_Muon_Sach_CIT07 > BOOKS_CIT07[i + 1].So_Lan_Muon_Sach_CIT07)
// 			{
// 				HoanDoi_CIT07(BOOKS_CIT07[i], BOOKS_CIT07[i + 1]); 
// 				k = i; // cập nhật vị trí cuối của phần tử đã sắp xếp
// 			}
// 		}
// 		right = k; // cập nhật vị trí cuối

// 		// đẩy phần tử nhỏ nhất về đầu -> cập nhật vị trí bắt đầu
// 		for (int i = right; i > left; i--) 
// 		{ 
// 			if (BOOKS_CIT07[i].So_Lan_Muon_Sach_CIT07 < BOOKS_CIT07[i - 1].So_Lan_Muon_Sach_CIT07)
// 			{
// 				HoanDoi_CIT07(BOOKS_CIT07[i], BOOKS_CIT07[i - 1]);
// 				k = i; // cập nhật vị trí cuối của phần tử đã sắp xếp
// 			}
// 		}
// 		left = k; // cập nhật vị trí bắt đầu 
// 	}
// 	cout << "\n Danh sách đã được sắp xếp theo số lần mượn sách bằng pp ShakerSort:";
// }
// [8] Heap Sort

// void Heapify_CIT07(BKPHMC_CIT07 a[], int n, int i)
// {
// 	int largest = i; // khởi tạo largest là root
// 	int l = 2 * i + 1; // left = 2*i + 1
// 	int r = 2 * i + 2; // right = 2*i + 2

// 	// nếu left lớn hơn root
// 	if (l < n && a[l].So_Lan_Muon_Sach_CIT07 > a[largest].So_Lan_Muon_Sach_CIT07)
// 	{
// 		largest = l;
// 	}

// 	// nếu right lớn hơn root
// 	if (r < n && a[r].So_Lan_Muon_Sach_CIT07 > a[largest].So_Lan_Muon_Sach_CIT07)
// 	{
// 		largest = r;
// 	}

// 	// nếu largest không phải là root
// 	if (largest != i)
// 	{
// 		HoanDoi_CIT07(a[i], a[largest]);

// 		// đệ quy heapify the subtree
// 		Heapify_CIT07(a, n, largest);
// 	}
// }


// // [9] Shell Sort
// void ShellSort_CIT07()
// {
// 	// bắt đầu với khoảng cách lớn, sau đó dần dần giảm khoảng cách
// 	for (int gap = TongSoPhanTuKhaoSat_CIT07 / 2; gap > 0; gap /= 2)
// 	{
// 		 // thực hiện insertion sort cho từng khoảng cách
// 		 // (a[i], a[i+gap], a[i+2*gap],...)
// 		 // đến khi gap = 1, thực hiện insertion sort cho toàn bộ mảng
// 		for (int i = gap; i < TongSoPhanTuKhaoSat_CIT07; i += 1)
// 		{
// 			// lưu a[i] trong temp và tạo một lỗ tại vị trí i
// 			// để a[i] có thể di chuyển đến vị trí đúng
// 			BKPHMC_CIT07 temp = BOOKS_CIT07[i];

// 			// di chuyển các phần tử của sub-array đã sắp xếp
// 			int j;
// 			for (j = i; j >= gap && BOOKS_CIT07[j - gap].So_Lan_Muon_Sach_CIT07 > temp.So_Lan_Muon_Sach_CIT07; j -= gap)
// 			{
// 				BOOKS_CIT07[j] = BOOKS_CIT07[j - gap];
// 			}

// 			// đặt temp (phần tử tạm thời) vào vị trí đúng
// 			BOOKS_CIT07[j] = temp;
// 		}
// 	}
// 	cout << "\n Danh sách đã được sắp xếp theo số lần mượn sách bằng pp ShellSort:";
// }

// [7] Quik Sort
void QuikSort_CIT07(BKPHMC_CIT07 a[], int left, int right)
{
	int i = left, j = right; // khởi tạo i, j
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
void StraightMergeSort_CIT07(BKPHMC_CIT07 a[], int left, int right)
{
	if (left < right)
	{
		int mid = left + (right - left) / 2; // tìm điểm chia (luôn nằm giữa left và right)
		StraightMergeSort_CIT07(a, left, mid); // sắp xếp nửa trái
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

// // [12] Natural Merge Sort 
// void NaturalMergeSort_CIT07()
// {
// 	int left = 0; // vị trí bắt đầu của mảng con
// 	int right = 0; // vị trí cuối của mảng con
// 	int mid = 0; // vị trí giữa của mảng con
// 	int i = 0; // vị trí hiện tại của mảng con
// 	while (i < TongSoPhanTuKhaoSat_CIT07 - 1)
// 	{
// 		left = i; // vị trí bắt đầu của mảng con
// 		while (i < TongSoPhanTuKhaoSat_CIT07 - 1 && BOOKS_CIT07[i].So_Lan_Muon_Sach_CIT07 <= BOOKS_CIT07[i + 1].So_Lan_Muon_Sach_CIT07)
// 		{
// 			i++; // tìm vị trí cuối của mảng con
// 		}
// 		mid = i; // vị trí giữa của mảng con
// 		while (i < TongSoPhanTuKhaoSat_CIT07 - 1 && BOOKS_CIT07[i].So_Lan_Muon_Sach_CIT07 >= BOOKS_CIT07[i + 1].So_Lan_Muon_Sach_CIT07)
// 		{
// 			i++; // tìm vị trí cuối của mảng con
// 		}
// 		right = i; // vị trí cuối của mảng con
// 		StraightMergeSort_CIT07(BOOKS_CIT07, left, right); // sắp xếp mảng con
// 	}
// 	cout << "\n Danh sách đã được sắp xếp theo số lần mượn sách bằng pp NaturalMergeSor:";
// }

// [9] Counting Sort 
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
	int count[max + 1]; // mảng đếm
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
		count[i] += count[i - 1]; // cập nhật mảng đếm
	}
	for (int i = TongSoPhanTuKhaoSat_CIT07 - 1; i >= 0; i--)
	{
		output[count[BOOKS_CIT07[i].So_Lan_Muon_Sach_CIT07] - 1] = BOOKS_CIT07[i]; // xếp phần tử vào mảng kết quả
		count[BOOKS_CIT07[i].So_Lan_Muon_Sach_CIT07]--; // giảm số lần xuất hiện
	}
	for (int i = 0; i < TongSoPhanTuKhaoSat_CIT07; i++)
	{
		BOOKS_CIT07[i] = output[i]; // copy mảng kết quả vào mảng chính
	}
	cout << "Danh sách đã được sắp theo số lần mượn sách bằng pp Counting Sort.\n";
}

// [0] Distribution Sort 
void DistributionSort_CIT07()
{
	int max = BOOKS_CIT07[0].So_Lan_Muon_Sach_CIT07;
	for (int i = 1; i < TongSoPhanTuKhaoSat_CIT07; i++)
	{
		if (BOOKS_CIT07[i].So_Lan_Muon_Sach_CIT07 > max)
		{
			max = BOOKS_CIT07[i].So_Lan_Muon_Sach_CIT07; // tìm phần tử lớn nhất
		}
	}
	int count[max + 1]; // mảng đếm
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
		count[i] += count[i - 1]; // cập nhật mảng đếm
	}
	for (int i = TongSoPhanTuKhaoSat_CIT07 - 1; i >= 0; i--)
	{
		output[count[BOOKS_CIT07[i].So_Lan_Muon_Sach_CIT07] - 1] = BOOKS_CIT07[i]; // xếp phần tử vào mảng kết quả
		count[BOOKS_CIT07[i].So_Lan_Muon_Sach_CIT07]--; // giảm số lần xuất hiện
	}
	for (int i = 0; i < TongSoPhanTuKhaoSat_CIT07; i++)
	{
		BOOKS_CIT07[i] = output[i]; // copy mảng kết quả vào mảng chính
	}
	cout << "Danh sách đã được sắp theo số lần mượn sách bằng pp Distribution Sort.\n";
}

// // [15] Radix Sort 
// void RadixSort_CIT07()
// {
// 	int max = BOOKS_CIT07[0].So_Lan_Muon_Sach_CIT07;
// 	for (int i = 1; i < TongSoPhanTuKhaoSat_CIT07; i++)
// 	{
// 		if (BOOKS_CIT07[i].So_Lan_Muon_Sach_CIT07 > max)
// 		{
// 			max = BOOKS_CIT07[i].So_Lan_Muon_Sach_CIT07; // tìm phần tử lớn nhất
// 		}
// 	}
// 	for (int exp = 1; max / exp > 0; exp *= 10)
// 	{
// 		BKPHMC_CIT07 output[TongSoPhanTuKhaoSat_CIT07]; // mảng kết quả
// 		int count[10] = {0}; // mảng đếm
// 		for (int i = 0; i < TongSoPhanTuKhaoSat_CIT07; i++)
// 		{
// 			count[(BOOKS_CIT07[i].So_Lan_Muon_Sach_CIT07 / exp) % 10]++; // đếm số lần xuất hiện
// 		}
// 		for (int i = 1; i < 10; i++)
// 		{
// 			count[i] += count[i - 1]; // cập nhật mảng đếm
// 		}
// 		for (int i = TongSoPhanTuKhaoSat_CIT07 - 1; i >= 0; i--)
// 		{
// 			output[count[(BOOKS_CIT07[i].So_Lan_Muon_Sach_CIT07 / exp) % 10] - 1] = BOOKS_CIT07[i]; // xếp phần tử vào mảng kết quả
// 			count[(BOOKS_CIT07[i].So_Lan_Muon_Sach_CIT07 / exp) % 10]--; // giảm số lần xuất hiện
// 		}
// 		for (int i = 0; i < TongSoPhanTuKhaoSat_CIT07; i++)
// 		{
// 			BOOKS_CIT07[i] = output[i]; // copy mảng kết quả vào mảng chính
// 		}
// 	}
// 	cout << "Danh sách đã được sắp theo số lần mượn sách bằng pp Radix Sort.\n";
// }

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
		cout << "0. Sắp xếp theo giải thuật PHÂN PHỐI [Distribution Sort]\n";
		cout << "q. Thoát\n";
		cout << "Nhập lựa chọn của bạn: ";
		cin >> LuaChon;

		switch (LuaChon) {
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
			case '0':
				cout << "Danh sách trước khi sắp xếp theo số lần mượn sách:";
				Inds_CIT07();
				DistributionSort_CIT07();
				Inds_CIT07();
				break;			
		}
	}
}
