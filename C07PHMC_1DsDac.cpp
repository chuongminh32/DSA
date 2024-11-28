/*************************************/
// CAU TRUC DAT TEN: TenThuocTinh_CIT07
/************************************/

/******************************/
/**KHAI BAO THU VIEN SU DUNG */
/******************************/
using namespace std;
#include <iostream> // Thư viện cho các luồng vào/ra
#include <conio.h>	// Thư viện cho nhập/xuất từ bàn phím trong consol
#include <string>	// Thư viện cho xử lý chuỗi ký tự kiểu string trong C++
#include <cctype>	// Thư viện cho các hàm xử lý ký tự
#include <vector>	// Thư viện cho cấu trúc dữ liệu vector

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

// 5. Thêm phần tử mới vào cuối danh sách
bool ThemPhanTuVaoCuoi_CIT07(BKPHMC_CIT07 v07)
{
	if (KiemTraDay_CIT07())
		return false; // Nếu danh sách đầy thì không thêm được

	BOOKS_CIT07[TongSoPhanTuKhaoSat_CIT07++] = v07; // Thêm vào cuối danh sách
	return true;
}

// 6. Xóa một phần tử tại vị trí chỉ định
bool XoaMotPhanTu_CIT07(int ViTri_CIT07)
{
	if (ViTri_CIT07 < 0 || ViTri_CIT07 >= TongSoPhanTuKhaoSat_CIT07 || KiemTraRong_CIT07()) // Kiểm tra chỉ số hợp lệ và danh sách rỗng
		return false;

	// Di chuyển các phần tử từ vị trí ViTri_CIT07 trở đi một bước về phía trước
	for (int i = ViTri_CIT07; i < TongSoPhanTuKhaoSat_CIT07 - 1; i++)
	{
		BOOKS_CIT07[i] = BOOKS_CIT07[i + 1];
	}
	TongSoPhanTuKhaoSat_CIT07--; // Giảm số lượng phần tử
	return true;
}


// 7. Thêm một phần tử vào vị trí i của danh sách  (Add)
bool ThemPhanTu_CIT07(BKPHMC_CIT07 v07, int ViTri_CIT07)
{
	if (ViTri_CIT07 < 0 || ViTri_CIT07 > TongSoPhanTuKhaoSat_CIT07 || KiemTraDay_CIT07()) // Kiểm tra chỉ số hợp lệ và danh sách đầy
		return false;

	if (KiemTraRong_CIT07() || ViTri_CIT07 == TongSoPhanTuKhaoSat_CIT07) // Nếu danh sách rỗng hoặc chèn vào cuối danh sách
	{
		return ThemPhanTuVaoCuoi_CIT07(v07);
	}
	else
	{
		// Di chuyển các phần tử từ vị trí ViTri_CIT07 trở đi một bước về phía sau
		for (int i = TongSoPhanTuKhaoSat_CIT07 - 1; i >= ViTri_CIT07; i--)
		{
			BOOKS_CIT07[i + 1] = BOOKS_CIT07[i];
		}
		BOOKS_CIT07[ViTri_CIT07] = v07; // Chèn phần tử vào vị trí ViTri_CIT07
		TongSoPhanTuKhaoSat_CIT07++;	// Tăng số lượng phần tử
		return true;
	}
}

// 8. Cập nhật thuộc tính cho phần tử (Update)
void CapNhatThuocTinh_CIT07(string &code_book)
{
	// Lấy phần tử
	bool found = false;
	BKPHMC_CIT07 *tempBook = nullptr;

	for (int i = 0; i < TongSoPhanTuKhaoSat_CIT07; i++)
	{
		if (BOOKS_CIT07[i].Ma_Sach_CIT07 == code_book)
		{ // Use the correct variable name
			tempBook = &BOOKS_CIT07[i]; // Use the address of the element
			found = true;
			break;
		}
	}

	if (!found)
	{
		cout << "Không tìm thấy sách có mã '" << code_book << "'!" << endl;
		return; // Trở về nếu không tìm thấy
	}
	else
	{
		// Update
		while (true)
		{
			char LuaChon;
			cout << "\nCHỌN THUỘC TÍNH ĐỂ SỬA: \n";
			cout << "1. Tên sách\n";
			cout << "2. Loại sách\n";
			cout << "3. Số lần mượn sách\n";
			cout << "e. Thoát\n";
			cout << "Nhập lựa chọn của bạn: ";
			cin >> LuaChon;

			switch (LuaChon)
			{
			case '1':
			{
				string newName;
				cout << "Nhập tên mới cho sách: ";
				cin.ignore();		   // Clear input buffer before reading a line
				getline(cin, newName); // Use getline to allow spaces in the name
				tempBook->Ten_Sach_CIT07 = newName;
				cout << "Đã cập nhật thông tin sách thành công!" << endl;
				break;
			}
			case '2':
			{
				string newType;
				cout << "Nhập loại mới cho sách: ";
				cin.ignore();		   // Clear input buffer
				getline(cin, newType); // Use getline to allow spaces in the type
				tempBook->Loai_Sach_CIT07 = newType;
				cout << "Đã cập nhật thông tin sách thành công!" << endl;
				break;
			}
			case '3':
			{
				int newCnt;
				cout << "Nhập số lần mượn sách mới cho sách: ";
				cin >> newCnt;
				tempBook->So_Lan_Muon_Sach_CIT07 = newCnt;
				cout << "Đã cập nhật thông tin sách thành công!" << endl;
				break;
			}
			case 'e':
				cout << "Thoát khỏi chương trình.\n";
				return; // Correctly exit the function
			default:
				cout << "Lựa chọn không hợp lệ, chọn lại: \n";
			}
		}
	}
}

// 9. Sắp xếp danh sách theo số lần mượn sách (So_Lan_Muon_Sach_CIT07)
void SapXepDSTheoSoLanMuonSach_CIT07()
{
	for (int i = 0; i < TongSoPhanTuKhaoSat_CIT07 - 1; i++)
	{
		for (int j = 0; j < TongSoPhanTuKhaoSat_CIT07 - i - 1; j++)
		{
			if (BOOKS_CIT07[j].So_Lan_Muon_Sach_CIT07 > BOOKS_CIT07[j + 1].So_Lan_Muon_Sach_CIT07) // Sắp xếp tăng dần
			{
				// Hoán đổi nếu phần tử hiện tại lớn hơn phần tử tiếp theo
				BKPHMC_CIT07 temp = BOOKS_CIT07[j];
				BOOKS_CIT07[j] = BOOKS_CIT07[j + 1];
				BOOKS_CIT07[j + 1] = temp;
			}
		}
	}
	cout << "Danh sách đã được sắp xếp theo số lần mượn sách.\n";
}

// 10. Tìm sách theo tên
void TimSachTheoTenSach_CIT07(const string &title)
{
	bool found = false;
	cout << "\nSách tìm thấy:\n";
	for (int i = 0; i < TongSoPhanTuKhaoSat_CIT07; i++)
	{
		if (BOOKS_CIT07[i].Ten_Sach_CIT07 == title)
		{
			cout << "Phần tử " << i + 1 << ":\n";
			cout << "Mã sách: " << BOOKS_CIT07[i].Ma_Sach_CIT07 << "\n";
			cout << "Tên sách: " << BOOKS_CIT07[i].Ten_Sach_CIT07 << "\n";
			cout << "Loại sách: " << BOOKS_CIT07[i].Loai_Sach_CIT07 << "\n";
			cout << "Số lần mượn sách: " << BOOKS_CIT07[i].So_Lan_Muon_Sach_CIT07 << "\n";
			cout << "\n";
			found = true;
		}
	}
	if (!found)
	{
		cout << "Không tìm thấy sách có tên \"" << title << "\" trong danh sách.\n";
	}
}

// 11. In danh sách cùng loại
void InSachCungLoai_CIT07(const string &TypeBook)
{
	bool found = false;
	int cnt = 0;
	vector<BKPHMC_CIT07> books;
	for (int i = 0; i < TongSoPhanTuKhaoSat_CIT07; i++)
	{
		if (BOOKS_CIT07[i].Loai_Sach_CIT07 == TypeBook)
		{
			++cnt;
			books.push_back(BOOKS_CIT07[i]);
			found = true;
		}
	}

	if (!found)
		cout << "Không tìm thấy sách loại: " << TypeBook << "\n";

	cout << "\nDanh sách các cuốn sách cùng loại " << TypeBook << " : \n";
	cout << "\n";
	for (BKPHMC_CIT07 book : books)
	{
		cout << "Mã sách: " << book.Ma_Sach_CIT07 << "\n";
		cout << "Tên sách: " << book.Ten_Sach_CIT07 << "\n";
		cout << "Loại sách: " << book.Loai_Sach_CIT07 << "\n";
		cout << "Số lần mượn sách: " << book.So_Lan_Muon_Sach_CIT07 << "\n";
		cout << "\n";
	}
	cout << "Có " << cnt << " cuốn sách cùng loại " << TypeBook << " \n";
}

/****************************************************************************/
// CÁC HÀM THỰC NGHIỆM CÁC PHÉP THAO TÁC (TOÁN) XỬ LÝ TRÊN DANH SÁCH ĐẶC: Sách
/****************************************************************************/

// 1. Nhập nội dung 1 phần tử tại vị trí thứ i trong danh sách để chuẩn bị thêm vào (chưa thêm)
void NhapNoiDungPhanTu_CIT07(int i, BKPHMC_CIT07 &books_CIT07)
{
	cout << "Nhập thông tin phần tử thứ " << i + 1 << ":\n";

	cout << "Nhập mã sách: ";
	cin >> books_CIT07.Ma_Sach_CIT07;
	cin.ignore(); // Loại bỏ ký tự newline sau khi nhập mã sách

	cout << "Nhập tên sách: ";
	getline(cin, books_CIT07.Ten_Sach_CIT07); // Nhập cả dòng

	cout << "Nhập loại sách: ";
	getline(cin, books_CIT07.Loai_Sach_CIT07); // Nhập cả dòng

	cout << "Nhập số lần mượn sách: ";
	cin >> books_CIT07.So_Lan_Muon_Sach_CIT07;
	cin.ignore(); // Loại bỏ ký tự newline sau khi nhập số lần mượn sách
}
// 2. Nhập danh sách
void Nhapds_CIT07()
{
	int soLuongPhanTu;
	cout << "Nhập số lượng phần tử: ";
	cin >> soLuongPhanTu;

	// Kiểm tra nếu số lượng phần tử vượt quá giới hạn
	if (soLuongPhanTu > PhanTuToiDa_CIT07)
	{
		cout << "Số lượng phần tử vượt quá giới hạn cho phép (" << PhanTuToiDa_CIT07 << ").\n";
		return;
	}

	TongSoPhanTuKhaoSat_CIT07 = 0; // Đặt lại số lượng phần tử hiện tại

	BKPHMC_CIT07 books_CIT07;
	for (int i = 0; i < soLuongPhanTu; i++)
	{
		NhapNoiDungPhanTu_CIT07(i, books_CIT07);
		// tang T
		ThemPhanTuVaoCuoi_CIT07(books_CIT07);
	}

	cout << "Tổng số phần tử trong danh sách: " << TongSoPhanTuKhaoSat_CIT07 << " \n";
}

// 3. Xóa phần tử khỏi danh sách
void XoaMotPT_CIT07()
{
	int ViTri_CIT07;
	cout << "Nhập vị trí phần tử cần xóa: ";
	cin >> ViTri_CIT07;

	if (XoaMotPhanTu_CIT07(ViTri_CIT07))
	{
		cout << "Xóa được\n";
	}
	else
	{
		cout << "Không xóa được\n";
	}
}

// 4. In danh sách
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

// 5. Thêm phần tử vào vị trí đã chọn
void ThemPT_CIT07()
{
	cout << "Nhập thông tin phần tử mới:\n";
	BKPHMC_CIT07 newBook;
	NhapNoiDungPhanTu_CIT07(TongSoPhanTuKhaoSat_CIT07, newBook);
	int vitri;
	cout << "Nhập vị trí cần thêm phần tử: ";
	cin >> vitri;
	ThemPhanTu_CIT07(newBook, vitri);
}

// 6. Tìm sách theo tên
void TimSach_CIT07()
{
	string title;
	cout << "Nhập tên sách cần tìm: ";
	cin.ignore(); // Clear newline
	getline(cin, title);
	TimSachTheoTenSach_CIT07(title);
}

// 7. In sách cùng loại
void DanhSachCungLoai_CIT07()
{
	string typeBook;
	cout << "Nhập loại sách cần in: ";
	cin.ignore(); // Clear newline
	getline(cin, typeBook);
	InSachCungLoai_CIT07(typeBook);
}

// 8. Cập nhật thuộc tính cho sách
void CapNhat_CIT07()
{
	string codeBook;
	cout << "\nNhập mã sách để UPDATE: ";
	cin >> codeBook;
	CapNhatThuocTinh_CIT07(codeBook);
}

/**********************************************/
// CHƯƠNG TRÌNH CHÍNH XỬ LÝ TRÊN DS ĐẶC : Sách
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
		cout << "\nCHƯƠNG TRÌNH QUẢN LÝ THƯ VIỆN [DANH SÁCH ĐẶC]\n";
		cout << "1. In danh sách\n";
		cout << "2. Thêm một phần tử vào vị trí đã chọn\n";
		cout << "3. Xóa phần tử ở vị trí đã chọn\n";
		cout << "4. Số phần tử trong danh sách\n";
		cout << "5. Kiểm tra danh sách RỖNG\n";
		cout << "6. Kiểm tra danh sách ĐẦY\n";
		cout << "7. Sắp xếp danh sách theo số lần mượn sách\n";
		cout << "8. Tìm sách theo tên sách\n";
		cout << "9. In danh sách cùng loại\n";
		cout << "0. Cập nhật thuộc tính cho sách\n";
		cout << "a. Thêm vào cuối\n";
		cout << "q. Thoát\n";
		cout << "Nhập lựa chọn của bạn: ";
		cin >> LuaChon;

		switch (LuaChon)
		{
		case '1':
			Inds_CIT07();
			break;
		case '2':
		{
			ThemPT_CIT07();
			break;
		}
		case '3':
			XoaMotPT_CIT07();
			break;
		case '4':
			cout << "Số lượng phần tử trong danh sách là: " << DoDaiDS_CIT07() << "\n";
			break;
		case '5':
			cout << (KiemTraRong_CIT07() ? "Danh sách rỗng.\n" : "Danh sách không rỗng.\n");
			break;
		case '6':
			cout << (KiemTraDay_CIT07() ? "Danh sách đầy.\n" : "Danh sách không đầy.\n");
			break;
		case '7':
			SapXepDSTheoSoLanMuonSach_CIT07();
			break;
		case '8':
		{
			TimSach_CIT07();
			break;
		}
		case '9':
		{
			DanhSachCungLoai_CIT07();
			break;
		}
		case '0':
		{
			CapNhat_CIT07();
			break;
		}
	
		    
		case 'q':
			cout << "Thoát khỏi chương trình.\n";
			return 0;
		default:
			cout << "Lựa chọn không hợp lệ.\n";
		}
	}
}