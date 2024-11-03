/*******************************/
/** KHAI BAO THU VIEN SU DUNG **/
/*******************************/
using namespace std;
#include <iostream> // Thư viện cho các luồng vào/ra
#include <math.h>	// Thư viện cho các hàm toán học

/****************************/
/** KHAI BAO DANH SACH DAC **/
/****************************/

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

/**************************************************************/
/** CÁC PHÉP THAO TÁC (TOÁN) CƠ BẢN TRÊN DANH SÁCH ĐẶC: SÁCH **/
/**************************************************************/

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
/* CÁC PHÉP TOÁN XỬ LÝ TRÊN DANH SÁCH ĐẶC: SÁCH */
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

// 6. In thông tin sách
void InPT_CIT07(BKPHMC_CIT07 sach_CIT07, int vitri_CIT07)
{
	    cout << "\nTHÔNG TIN SÁCH TÌM ĐƯỢC:\n";
		cout << "Phần tử " << vitri_CIT07 + 1 << ":\n";
		cout << "Mã sách: " << sach_CIT07.Ma_Sach_CIT07 << "\n";
		cout << "Tên sách: " << sach_CIT07.Ten_Sach_CIT07 << "\n";
		cout << "Loại sách: " << sach_CIT07.Loai_Sach_CIT07 << "\n";
		cout << "Số lần mượn sách: " << sach_CIT07.So_Lan_Muon_Sach_CIT07 << "\n";
		cout << "\n";
}

// 6.2 in danh sách phần tử 
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

// CÁC GIẢI THUẬT TÌM KIẾM TRÊN DANH SÁCH ĐẶC: SÁCH - TÌM KIẾM THEO MÃ SÁCH
// [1] Tìm kiếm tuyến tính (Linear Search)
int TimKiemTuyenTinh_CIT07(string x)
{
	for (int i = 0; i < TongSoPhanTuKhaoSat_CIT07; i++)
	{
		if (BOOKS_CIT07[i].Ma_Sach_CIT07 == x)
		{
			return i;
		}
	}
	return -1;
}

// [2] Tìm kiếm nhị phân (Binary Search)
int TimKiemNhiPhan_CIT07(string x)
{
	int left = 0;							   // vị trí bắt đầu của dãy con cần xét
	int right = TongSoPhanTuKhaoSat_CIT07 - 1; // vị trí cuối của dãy con cần xét
	while (left <= right)
	{
		int mid = (left + right) / 2; // vị trí giữa của dãy con cần xét
		if (x == BOOKS_CIT07[mid].Ma_Sach_CIT07)
		{
			return mid; // tìm thấy x tại vị trí mid
		}
		else if (x < BOOKS_CIT07[mid].Ma_Sach_CIT07)
		{
			right = mid - 1; // dịch chuyển vị trí cuối của dãy con cần xét
		}
		else
		{
			left = mid + 1; // dịch chuyển vị trí bắt đầu của dãy con cần xét
		}
	}
	return -1; // không tìm thấy x trong danh sách
}

// [3] Tìm kiếm nội suy (Interpolation Search)
int TimKiemNoiSuy_CIT07(string x)
{
	int left = 0;							   // vị trí bắt đầu của dãy con cần xét
	int right = TongSoPhanTuKhaoSat_CIT07 - 1; // vị trí cuối của dãy con cần xét
	while (left <= right)
	{
		int mid = left + (right - left) * (stoi(x) - stoi(BOOKS_CIT07[left].Ma_Sach_CIT07)) / (stoi(BOOKS_CIT07[right].Ma_Sach_CIT07) - stoi(BOOKS_CIT07[left].Ma_Sach_CIT07)); // vị trí giữa của dãy con cần xét
		if (x == BOOKS_CIT07[mid].Ma_Sach_CIT07)
		{
			return mid; // tìm thấy x tại vị trí mid
		}
		else if (x < BOOKS_CIT07[mid].Ma_Sach_CIT07)
		{
			right = mid - 1; // dịch chuyển vị trí cuối của dãy con cần xét
		}
		else
		{
			left = mid + 1; // dịch chuyển vị trí bắt đầu của dãy con cần xét
		}
	}
	return -1; // không tìm thấy x trong danh sách
}

// [4] Jump Search
int TimKiemNhay_CIT07(string x)
{
	int step = sqrt(TongSoPhanTuKhaoSat_CIT07);										// số bước nhảy
	int prev = 0;																	// vị trí trước đó
	while (BOOKS_CIT07[min(step, TongSoPhanTuKhaoSat_CIT07) - 1].Ma_Sach_CIT07 < x) // nếu phần tử tại vị trí step - 1 nhỏ hơn x
	{
		prev = step;							 // cập nhật vị trí trước đó
		step += sqrt(TongSoPhanTuKhaoSat_CIT07); // tăng số bước nhảy lên căn bậc 2 của n
		if (prev >= TongSoPhanTuKhaoSat_CIT07)	 // nếu vị trí trước đó lớn hơn hoặc bằng n
		{
			return -1; // không tìm thấy x trong danh sách
		}
	}
	while (BOOKS_CIT07[prev].Ma_Sach_CIT07 < x) // nếu phần tử tại vị trí prev nhỏ hơn x
	{
		prev++; // tìm kiếm tuyến tính từ vị trí trước đó
		if (prev == min(step, TongSoPhanTuKhaoSat_CIT07))
		{
			return -1; // không tìm thấy x trong danh sách
		}
	}
	if (BOOKS_CIT07[prev].Ma_Sach_CIT07 == x) // nếu phần tử tại vị trí prev bằng x
	{
		return prev; // tìm thấy x tại vị trí prev
	}
	return -1; // không tìm thấy x trong danh sách
}

// [5] Exponential Search
int TimKiemExponential_CIT07(string x)
{
	if (BOOKS_CIT07[0].Ma_Sach_CIT07 == x) // nếu phần tử đầu tiên trong danh sách bằng x
	{
		return 0; // tìm thấy x tại vị trí 0
	}
	int i = 1;																   // vị trí bắt đầu
	while (i < TongSoPhanTuKhaoSat_CIT07 && BOOKS_CIT07[i].Ma_Sach_CIT07 <= x) // nếu vị trí i nhỏ hơn n và phần tử tại vị trí i nhỏ hơn hoặc bằng x
	{
		i *= 2; // tăng i lên gấp đôi
	}
	return TimKiemNhiPhan_CIT07(x); // tìm kiếm nhị phân x trong đoạn từ i/2 đến i
}

// [6] Fibonacci Search
int TimKiemFibonacci_CIT07(string x)
{
	int fib2 = 0;							// số Fibonacci thứ 2
	int fib1 = 1;							// số Fibonacci thứ 1
	int fib = fib2 + fib1;					// số Fibonacci hiện tại
	while (fib < TongSoPhanTuKhaoSat_CIT07) // nếu số Fibonacci hiện tại nhỏ hơn n
	{
		fib2 = fib1;	   // cập nhật số Fibonacci thứ 2
		fib1 = fib;		   // cập nhật số Fibonacci thứ 1
		fib = fib2 + fib1; // cập nhật số Fibonacci hiện tại
	}
	int offset = -1; // vị trí bắt đầu
	while (fib > 1)	 // nếu số Fibonacci hiện tại lớn hơn 1
	{
		int i = min(offset + fib2, TongSoPhanTuKhaoSat_CIT07 - 1); // vị trí i
		if (BOOKS_CIT07[i].Ma_Sach_CIT07 < x)					   // nếu phần tử tại vị trí i nhỏ hơn x
		{
			fib = fib1;		   // cập nhật số Fibonacci hiện tại
			fib1 = fib2;	   // cập nhật số Fibonacci thứ 1
			fib2 = fib - fib1; // cập nhật số Fibonacci thứ 2
			offset = i;		   // cập nhật vị trí bắt đầu
		}
		else if (BOOKS_CIT07[i].Ma_Sach_CIT07 > x) // nếu phần tử tại vị trí i lớn hơn x
		{
			fib = fib2;		   // cập nhật số Fibonacci hiện tại
			fib1 -= fib2;	   // cập nhật số Fibonacci thứ 1
			fib2 = fib - fib1; // cập nhật số Fibonacci thứ 2
		}
		else
		{
			return i; // tìm thấy x tại vị trí i
		}
	}
	if (fib1 && BOOKS_CIT07[offset + 1].Ma_Sach_CIT07 == x)
	{
		return offset + 1; // tìm thấy x tại vị trí offset + 1
	}
	return -1; // không tìm thấy x trong danh sách
}

/************************/
/** CHƯƠNG TRÌNH CHÍNH **/
/************************/

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
		cout << "CÁC GIẢI THUẬT TÌM KIẾM TRÊN DANH SÁCH SÁCH [ĐẶC]\n";
		cout << "1. Tìm kiếm tuyến tính [Linear Search]\n";
		cout << "2. Tìm kiếm nhị phân [Binary Search]\n";
		cout << "3. Tìm kiếm nội suy [Interpolation Search]\n";
		cout << "4. Tìm kiếm nhảy [Jump Search]\n";
		cout << "5. Tìm kiếm lũy tiến [Exponential Search]\n";
		cout << "6. Tìm kiếm Fibonacci [Fibonacci Search]\n";
		cout << "q. Thoát\n";
		cout << "Nhập lựa chọn của bạn: ";
		cin >> LuaChon;

		string x;
		int result;

		switch (LuaChon)
		{
		case '1':
			cout << "Nhập mã sách cần tìm: ";
			cin >> x;
			result = TimKiemTuyenTinh_CIT07(x);
			if (result == -1)
			{
				cout << "Không tìm thấy mã sách " << x << " trong danh sách\n";
			}
			else
			{
				cout << "Tìm thấy mã sách " << x << " tại vị trí " << result << "\n";
				InPT_CIT07(BOOKS_CIT07[result], result);
			}
			break;
		case '2':
			cout << "Nhập mã sách cần tìm: ";
			cin >> x;
			result = TimKiemNhiPhan_CIT07(x);
			if (result == -1)
			{
				cout << "Không tìm thấy mã sách " << x << " trong danh sách\n";
			}
			else
			{
				cout << "Tìm thấy mã sách " << x << " tại vị trí " << result << "\n";
				InPT_CIT07(BOOKS_CIT07[result], result);
			}
			break;
		case '3':
			cout << "Nhập mã sách cần tìm: ";
			cin >> x;
			result = TimKiemNoiSuy_CIT07(x);
			if (result == -1)
			{
				cout << "Không tìm thấy mã sách " << x << " trong danh sách\n";
			}
			else
			{
				cout << "Tìm thấy mã sách " << x << " tại vị trí " << result << "\n";
				InPT_CIT07(BOOKS_CIT07[result], result);
			}
			break;
		case '4':
			cout << "Nhập mã sách cần tìm: ";
			cin >> x;
			result = TimKiemNhay_CIT07(x);
			if (result == -1)
			{
				cout << "Không tìm thấy mã sách " << x << " trong danh sách\n";
			}
			else
			{
				cout << "Tìm thấy mã sách " << x << " tại vị trí " << result << "\n";
				InPT_CIT07(BOOKS_CIT07[result], result);
			}
			break;
		case '5':
			cout << "Nhập mã sách cần tìm: ";
			cin >> x;
			result = TimKiemExponential_CIT07(x);
			if (result == -1)
			{
				cout << "Không tìm thấy mã sách " << x << " trong danh sách\n";
			}
			else
			{
				cout << "Tìm thấy mã sách " << x << " tại vị trí " << result << "\n";
				InPT_CIT07(BOOKS_CIT07[result], result);
			}
			break;
		case '6':
			cout << "Nhập mã sách cần tìm: ";
			cin >> x;
			result = TimKiemFibonacci_CIT07(x);
			if (result == -1)
			{
				cout << "Không tìm thấy mã sách " << x << " trong danh sách\n";
			}
			else
			{
				cout << "Tìm thấy mã sách " << x << " tại vị trí " << result << "\n";
				InPT_CIT07(BOOKS_CIT07[result], result);
			}
			break;
		case 'q':
			cout << "Thoát chương trình\n";
			return 0;
		default:
			cout << "Lựa chọn không hợp lệ\n";
			break;
		}
	}
	return 0;
}
