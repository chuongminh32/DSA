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

/*************************************************/
/* CÁC PHÉP TOÁN XỬ LÝ TRÊN DANH SÁCH ĐẶC: SÁCH */
/***********************************************/

// 1. Khởi tạo
void KhoiTao_CIT07()
{
	TongSoPhanTuKhaoSat_CIT07 = 0;
}

// 2. Nhập danh sách sách
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

// 3. In thông tin sách
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

// 4 in danh sách phần tử
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

// 5. Hàm hoán đổi nội dung hai phần tử
void HoanDoi_CIT07(BKPHMC_CIT07 &a, BKPHMC_CIT07 &b)
{
	BKPHMC_CIT07 temp = a;
	a = b;
	b = temp;
}

// CÁC GIẢI THUẬT TÌM KIẾM TRÊN DANH SÁCH ĐẶC: SÁCH - TÌM KIẾM THEO MÃ SÁCH

// [0] Sắp xếp danh sách sách theo mã sách (để thực hiện thuật toán tìm kiếm yêu cầu dữ liệu đã sắp xếp)
void SapXep_CIT07()
{
	for (int i = 0; i < TongSoPhanTuKhaoSat_CIT07 - 1; i++)
	{
		for (int j = i + 1; j < TongSoPhanTuKhaoSat_CIT07; j++)
		{
			if (BOOKS_CIT07[i].Ma_Sach_CIT07 > BOOKS_CIT07[j].Ma_Sach_CIT07)
			{
				HoanDoi_CIT07(BOOKS_CIT07[i], BOOKS_CIT07[j]);
			}
		}
	}
}

// [1] Tìm kiếm tuyến tính (Linear Search)
/*
Mảng ban đầu:
BOOKS_CIT07 = [{"A123"}, {"B456"}, {"C789"}, {"D012"}, {"E345"}]

Tìm kiếm "C789":

Bắt đầu từ chỉ số 0: BOOKS_CIT07[0].Ma_Sach_CIT07 là "A123" (không khớp).
Chuyển đến chỉ số 1: BOOKS_CIT07[1].Ma_Sach_CIT07 là "B456" (không khớp).
Chuyển đến chỉ số 2: BOOKS_CIT07[2].Ma_Sach_CIT07 là "C789" (tìm thấy).
Kết quả:

Hàm trả về chỉ số 2.
Kết quả: Tìm thấy C789 tại vị trí 2
*/
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
/*
Giả sử danh sách BOOKS_CIT07 như sau:
struct Book {
	string Ma_Sach_CIT07;
	// các thuộc tính khác
};

Book BOOKS_CIT07[] = {
	{"A001"}, {"A002"}, {"A003"}, {"A004"}, {"A005"}, {"A006"}, {"A007"}, {"A008"}, {"A009"}, {"A010"}
};

int TongSoPhanTuKhaoSat_CIT07 = 10;
Chúng ta sẽ tìm kiếm mã sách "A007" trong danh sách này.

Bước 1:
left = 0
right = 9
mid = (0 + 9) / 2 = 4
BOOKS_CIT07[4].Ma_Sach_CIT07 = "A005"
So sánh x với BOOKS_CIT07[mid].Ma_Sach_CIT07:

"A005" == "A005" -> tìm thấy mã sách tại vị trí mid = 4.
Kết quả trả về là 4.

Bước 2:
Giả sử chúng ta tìm kiếm mã sách "A007".

left = 0
right = 9
mid = (0 + 9) / 2 = 4
BOOKS_CIT07[4].Ma_Sach_CIT07 = "A005"
So sánh x với BOOKS_CIT07[mid].Ma_Sach_CIT07:

"A007" > "A005" -> left = mid + 1 = 5
Bước 3:
left = 5
right = 9
mid = (5 + 9) / 2 = 7
BOOKS_CIT07[7].Ma_Sach_CIT07 = "A008"
So sánh x với BOOKS_CIT07[mid].Ma_Sach_CIT07:

"A007" < "A008" -> right = mid - 1 = 6
Bước 4:
left = 5
right = 6
mid = (5 + 6) / 2 = 5
BOOKS_CIT07[5].Ma_Sach_CIT07 = "A006"
So sánh x với BOOKS_CIT07[mid].Ma_Sach_CIT07:

"A007" > "A006" -> left = mid + 1 = 6
Bước 5:
left = 6
right = 6
mid = (6 + 6) / 2 = 6
BOOKS_CIT07[6].Ma_Sach_CIT07 = "A007"
So sánh x với BOOKS_CIT07[mid].Ma_Sach_CIT07:

"A007" == "A007" -> tìm thấy mã sách tại vị trí mid = 6.
Kết quả trả về là 6.
*/
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
/*
giả sử chúng ta có một danh sách các sách với mã sách đã được sắp xếp theo thứ tự tăng dần. Ví dụ:
Book BOOKS_CIT07[] = {
	{"A001"}, {"A002"}, {"A003"}, {"A004"}, {"A005"},
	{"A006"}, {"A007"}, {"A008"}, {"A009"}, {"A010"}
};

Giả sử chúng ta muốn tìm mã sách "A007". Thuật toán sẽ hoạt động như sau:

Khởi tạo:

left = 0
right = 9 (vì có 10 phần tử, chỉ số cuối là 9)
Vòng lặp đầu tiên:

Tính mid:
int mid = left + (right - left) * (x.compare(BOOKS_CIT07[left].Ma_Sach_CIT07))
		  / (BOOKS_CIT07[right].Ma_Sach_CIT07.compare(BOOKS_CIT07[left].Ma_Sach_CIT07));
// mid = 0 + (9 - 0) * ("A007".compare("A001")) / ("A010".compare("A001"));
// mid = 0 + 9 * (6) / (9);
// mid = 6

Kiểm tra mid:
mid nằm trong phạm vi hợp lệ (0 <= 6 <= 9)
So sánh x với BOOKS_CIT07[mid].Ma_Sach_CIT07:
"A007" == "A007" => Tìm thấy tại vị trí mid = 6
Kết quả là mã sách "A007" được tìm thấy tại vị trí 6 trong danh sách.
*/
int TimKiemNoiSuy_CIT07(string x)
{
	int left = 0;							   // Vị trí bắt đầu của dãy con cần xét
	int right = TongSoPhanTuKhaoSat_CIT07 - 1; // Vị trí cuối của dãy con cần xét

	while (left <= right)
	{
		// Tính toán vị trí giữa (mid) bằng cách sử dụng công thức nội suy
		// Sử dụng phép so sánh chuỗi thay vì chuyển chuỗi thành số
		int mid = left + (right - left) * (x.compare(BOOKS_CIT07[left].Ma_Sach_CIT07)) / (BOOKS_CIT07[right].Ma_Sach_CIT07.compare(BOOKS_CIT07[left].Ma_Sach_CIT07));

		// Kiểm tra nếu mid nằm trong phạm vi hợp lệ
		if (mid < left || mid > right)
		{
			return -1; // Không tìm thấy
		}

		// So sánh chuỗi tại vị trí mid
		if (x == BOOKS_CIT07[mid].Ma_Sach_CIT07)
		{
			return mid; // Tìm thấy x tại vị trí mid
		}
		else if (x < BOOKS_CIT07[mid].Ma_Sach_CIT07)
		{
			right = mid - 1; // Dịch chuyển vị trí cuối của dãy con cần xét
		}
		else
		{
			left = mid + 1; // Dịch chuyển vị trí bắt đầu của dãy con cần xét
		}
	}
	return -1; // Không tìm thấy x trong danh sách
}

// [4] Jump Search
/*

Giả sử:
BOOKS_CIT07 có 10 phần tử với các mã sách lần lượt là: ["A1", "A2", "A3", "A4", "A5", "A6", "A7", "A8", "A9", "A10"]
TongSoPhanTuKhaoSat_CIT07 = 10
Chúng ta cần tìm mã sách x = "A7"
BOOKS_CIT07 có 10 phần tử với các mã sách lần lượt là: ["A1", "A2", "A3", "A4", "A5", "A6", "A7", "A8", "A9", "A10"]
TongSoPhanTuKhaoSat_CIT07 = 10
Chúng ta cần tìm mã sách x = "A7"
Bước 1: Tính số bước nhảy
int step = sqrt(10); // step = 3
int prev = 0;

Bước 2: Thực hiện vòng lặp nhảy
while (BOOKS_CIT07[min(step, 10) - 1].Ma_Sach_CIT07 < "A7") {
	prev = step; // prev = 3
	step += sqrt(10); // step = 6
	if (prev >= 10) {
		return -1;
	}
}

Lần 1: BOOKS_CIT07[2].Ma_Sach_CIT07 = "A3" < "A7" -> prev = 3, step = 6
Lần 2: BOOKS_CIT07[5].Ma_Sach_CIT07 = "A6" < "A7" -> prev = 6, step = 9
Bước 3: Thực hiện tìm kiếm tuyến tính
while (BOOKS_CIT07[prev].Ma_Sach_CIT07 < "A7") {
	prev++; // prev = 7
	if (prev == min(step, 10)) {
		return -1;
	}
}

Lần 1: BOOKS_CIT07[6].Ma_Sach_CIT07 = "A7" == "A7" -> thoát vòng lặp
Bước 4: Kiểm tra kết quả
if (BOOKS_CIT07[prev].Ma_Sach_CIT07 == "A7") {
	return prev; // return 6
}
return -1;

Kết quả: Mã sách x = "A7" được tìm thấy tại vị trí 6.
*/
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
/*

Giả sử chúng ta có một mảng BOOKS_CIT07 với các giá trị Ma_Sach_CIT07 như sau:

Chúng ta sẽ tìm giá trị "A007" sử dụng hàm TimKiemExponential_CIT07.

Kiểm tra ban đầu:

Kiểm tra xem phần tử đầu tiên có phải là "A007" không.
BOOKS_CIT07[0].Ma_Sach_CIT07 là "A001", không bằng "A007".
Tìm kiếm lũy tiến:

Bắt đầu với i = 1.
Kiểm tra BOOKS_CIT07[1].Ma_Sach_CIT07 là "A002", và vì "A002" <= "A007", nhân đôi i lên 2.
Kiểm tra BOOKS_CIT07[2].Ma_Sach_CIT07 là "A003", và vì "A003" <= "A007", nhân đôi i lên 4.
Kiểm tra BOOKS_CIT07[4].Ma_Sach_CIT07 là "A005", và vì "A005" <= "A007", nhân đôi i lên 8.
Kiểm tra BOOKS_CIT07[8].Ma_Sach_CIT07 là "A009", và vì "A009" > "A007", dừng việc nhân đôi i.
Tìm kiếm nhị phân:

Đặt i07 = min(8, 10 - 1) = 8.
Thực hiện tìm kiếm nhị phân trong khoảng từ i / 2 = 4 đến i07 = 8.
Phần mảng con để tìm kiếm nhị phân là ["A005", "A006", "A007", "A008", "A009"].
Tìm kiếm nhị phân tìm thấy "A007" tại chỉ số 6.
Vì vậy, hàm TimKiemExponential_CIT07("A007") sẽ trả về 6.
*/
int TimKiemNhiPhan_CIT07(int l07, int r07, string x)
{
	while (l07 <= r07)
	{
		int mid = l07 + (r07 - l07) / 2; // Tính vị trí giữa của đoạn cần xét
		if (BOOKS_CIT07[mid].Ma_Sach_CIT07 == x)
		{
			return mid; // Tìm thấy x tại vị trí mid
		}
		if (BOOKS_CIT07[mid].Ma_Sach_CIT07 > x)
		{
			r07 = mid - 1; // Giới hạn tìm kiếm ở nửa trái
		}
		else
		{
			l07 = mid + 1; // Giới hạn tìm kiếm ở nửa phải
		}
	}
	return -1; // Không tìm thấy x trong danh sách
}

int TimKiemExponential_CIT07(string x)
{
	if (BOOKS_CIT07[0].Ma_Sach_CIT07 == x)
	{
		return 0; // Tìm thấy x tại vị trí đầu tiên
	}

	int i = 1; // Bắt đầu từ phần tử thứ 2
	// Mở rộng phạm vi theo lũy thừa 2, đảm bảo không vượt quá số phần tử
	while (i < TongSoPhanTuKhaoSat_CIT07 && BOOKS_CIT07[i].Ma_Sach_CIT07 < x)
	{
		i *= 2;
	}

	// Tìm đoạn cần xét, giới hạn vị trí tối đa là cuối danh sách
	int right07 = min(i, TongSoPhanTuKhaoSat_CIT07 - 1);
	return TimKiemNhiPhan_CIT07(i / 2, right07, x); // Tìm kiếm nhị phân trong đoạn xác định
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
		SapXep_CIT07();
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
		SapXep_CIT07();
		Inds_CIT07();
	}

	cout << "Nhấn phím bất kỳ để tiếp tục: ";
	cin.ignore(); // xóa các kí tự trươc đó
	cin.get();	  // Nhập phím bất kì

	char LuaChon;
	while (true)
	{
		cout << "CÁC GIẢI THUẬT TÌM KIẾM TRÊN DANH SÁCH SÁCH [ĐẶC]\n";
		cout << "___________________________________________\n";
		cout << "1. Tìm kiếm tuyến tính [Linear Search]\n";
		cout << "2. Tìm kiếm nhị phân [Binary Search]\n";
		cout << "3. Tìm kiếm nội suy [Interpolation Search]\n";
		cout << "4. Tìm kiếm nhảy [Jump Search]\n";
		cout << "5. Tìm kiếm lũy tiến [Exponential Search]\n";
		cout << "q. Thoát\n";
		cout << "___________________________________________\n";
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
