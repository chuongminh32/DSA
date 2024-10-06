/*************************************/
// CAU TRUC DAT TEN: TenThuocTinh_CIT07
/************************************/

#include <iostream> // Thư viện cho các luồng vào/ra
#include <conio.h>  // Thư viện cho nhập/xuất từ bàn phím trong consol
#include <string>   // Thư viện cho xử lý chuỗi ký tự kiểu string trong C++

using namespace std;

/******************************/
/**KHAI BAO DANH SACH DAC STACK */
/******************************/

struct BKPHMC_CIT07 // Cấu trúc 1 quyển sách trong danh sách thư viện
{
    string Ten_Sach_CIT07;      // Tên sách
    string Ma_Sach_CIT07;       // Mã sách
    string Loai_Sach_CIT07;     // Loại sách
    int So_Lan_Muon_Sach_CIT07; // Số lần mượn sách
};

const int PhanTuToiDa_CIT07 = 100;                 // Số lượng phần tử tối đa trong STACK
BKPHMC_CIT07 BOOKS_STACK_CIT07[PhanTuToiDa_CIT07]; // DANH SÁCH CÁC PHẦN TỬ (DS ĐẶC) STACK
int SoPTKhaoSat_CIT07;                             // Số lượng phần tử (thực có) trong mảng [n <= max]

/*************************************************************/
/**CÁC PHÉP THAO TÁC (TOÁN) CƠ BẢN TRÊN STACK ĐẶC: ***********/
/*************************************************************/

// 1. Khởi tạo
void KhoiTao_CIT07()
{
    SoPTKhaoSat_CIT07 = -1;
}

// 2. Kiểm tra rỗng
bool KiemTraRong_CIT07()
{
    return (SoPTKhaoSat_CIT07 == -1);
}

// 3. Kiểm tra đầy
bool KiemTraDay_CIT07()
{
    return (SoPTKhaoSat_CIT07 == PhanTuToiDa_CIT07 - 1);
}

/*************************************************/
// CÁC PHÉP THAO TÁC CƠ BẢN TRÊN 1 PHẦN TỬ: ****/
/***********************************************/

// 4. Thêm phần tử mới vào đỉnh ngăn xếp  (Push)
bool Push_CIT07(BKPHMC_CIT07 books_STACK_CIT07)
{
    if (KiemTraDay_CIT07())
    {
        cout << "Stack đầy không thể chứa thêm phần tử mới !" << endl;
        return false;
    }
    else
    {
        BOOKS_STACK_CIT07[++SoPTKhaoSat_CIT07] = books_STACK_CIT07;
        return true;
    }
}

// 5. Xóa phần tử ở đỉnh ngăn xếp sách (Pop)
bool Pop_CIT07()
{
    if (KiemTraRong_CIT07())
    {
        cout << "Stack rỗng không thể xóa !" << endl;
        return false;
    }
    else
    {
        SoPTKhaoSat_CIT07--;
        return true;
    }
}

// 6. Lấy một phần tử ở đầu ngăn xếp (Top)
BKPHMC_CIT07 Top_CIT07()
{
    if (KiemTraRong_CIT07()) // Kiểm tra xem ngăn xếp có rỗng không
    {
        cout << "Danh sách rỗng !" << endl;
        BKPHMC_CIT07 PT_Rong;
        PT_Rong.Ma_Sach_CIT07 = "-1"; // Đánh dấu phần tử rỗng
        return PT_Rong;
    }
    else
    {
        return BOOKS_STACK_CIT07[SoPTKhaoSat_CIT07]; // Trả về phần tử ở đỉnh mà không xóa
    }
}

/****************************************************************************/
// CÁC HÀM THỰC NGHIỆM CÁC PHÉP THAO TÁC (TOÁN) XỬ LÝ TRÊN STACK DANH SÁCH ĐẶC: Sách
/****************************************************************************/

// 0. In nội dung cho 1 phần tử
void InNoiDung_CIT07(BKPHMC_CIT07 book_CIT07)
{
    cout << "Mã sách: " << book_CIT07.Ma_Sach_CIT07 << "\n";
    cout << "Tên sách: " << book_CIT07.Ten_Sach_CIT07 << "\n";
    cout << "Loại sách: " << book_CIT07.Loai_Sach_CIT07 << "\n";
    cout << "Số lần mượn sách: " << book_CIT07.So_Lan_Muon_Sach_CIT07 << "\n";
    cout << "\n";
}

// 1. Nhập nội dung 1 phần tử
void NhapNoiDungPT_CIT07(BKPHMC_CIT07 &books_STACK_CIT07) // Sử dụng tham chiếu để thay đổi biến bên ngoài
{
    cout << "Nhập mã sách: ";
    cin >> books_STACK_CIT07.Ma_Sach_CIT07;
    cin.ignore(); // Loại bỏ ký tự newline sau khi nhập mã sách

    cout << "Nhập tên sách: ";
    getline(cin, books_STACK_CIT07.Ten_Sach_CIT07); // Nhập cả dòng

    cout << "Nhập loại sách: ";
    getline(cin, books_STACK_CIT07.Loai_Sach_CIT07); // Nhập cả dòng

    cout << "Nhập số lần mượn sách: ";
    cin >> books_STACK_CIT07.So_Lan_Muon_Sach_CIT07;
    cout << endl;
    cin.ignore(); // Loại bỏ ký tự newline sau khi nhập số lần mượn sách
}

// 2. Nạp nhiều phần tử vào Stack
void NapNhieuPT_Stack_CIT07()
{
    int nPhanTu_CIT07;
    cout << "Nhập số lượng phần tử cần nạp vào Stack: ";
    cin >> nPhanTu_CIT07;

    for (int i = 0; i < nPhanTu_CIT07; i++)
    {
        BKPHMC_CIT07 books_STACK_CIT07; // Khai báo biến mới cho mỗi phần tử
        cout << "Nhập phần tử thứ " << i + 1 << ":" << endl;
        NhapNoiDungPT_CIT07(books_STACK_CIT07);
        if (!Push_CIT07(books_STACK_CIT07)) // Gọi Push sau khi đã nhập dữ liệu
        {
            cout << "Không thể thêm phần tử vào Stack! Stack đã đầy.\n";
            break;
        }
    }

    cout << "Tổng số phần tử trong danh sách: " << SoPTKhaoSat_CIT07 + 1 << " \n"; // Thêm 1 vì SoPTKhaoSat_CIT07 bắt đầu từ -1
}

// 2.2 Nạp thêm 1 phần tử vào Stack
void Push_Stack_CIT07()
{
    BKPHMC_CIT07 newBook_CIT07;
    NhapNoiDungPT_CIT07(newBook_CIT07);
    Push_CIT07(newBook_CIT07);
}

// 2.3 Lấy nhiều phần tử ra khỏi Stack
void LayNhieuPT_Stack_CIT07()
{
    int cnt_CIT07;
    cout << "Bạn muốn lấy bao nhiêu phần tử ra khỏi Stack? : ";
    cin >> cnt_CIT07;

    cout << "Các phần tử lấy được" << endl;
    for (int i = 0; i < cnt_CIT07; i++)
    {
        BKPHMC_CIT07 temp_book = Top_CIT07(); // Lấy phần tử ở đỉnh
        if (temp_book.Ma_Sach_CIT07 == "-1")
        {
            cout << "Không còn phần tử nào để lấy.\n";
            break;
        }
        else
        {
            cout << "Phần tử " << i + 1 << ":\n";
            InNoiDung_CIT07(temp_book);
            Pop_CIT07(); // Xóa phần tử đã lấy ra khỏi Stack
        }
    }
}

// 3. Lấy một phần tử khỏi Stack
void Top_Stack_CIT07()
{
    BKPHMC_CIT07 temp_book = Top_CIT07();
    if (temp_book.Ma_Sach_CIT07 != "-1")
    {
        cout << "Lấy thành công phần tử khỏi Stack:\n ";
        InNoiDung_CIT07(temp_book);
    }
    else
    {
        cout << "Không có phần tử nào ở đỉnh Stack để lấy.\n";
    }
}

// 4. In Stack ngược
void Inds_Stack_CIT07()
{
    if (KiemTraRong_CIT07())
    {
        cout << "\nDANH SÁCH CÁC PHẦN TỬ TRONG STACK:";
        cout << "  STACK RỖNG !\n";
    }
    else
    {
        cout << "\n_____________________________________\n";
        cout << "\nDANH SÁCH CÁC PHẦN TỬ TRONG STACK:\n";
        for (int i = SoPTKhaoSat_CIT07; i >= 0; i--) // Duyệt ngược để in ra danh sách
        {
            cout << "Phần tử " << i + 1 << ":\n";
            InNoiDung_CIT07(BOOKS_STACK_CIT07[i]);
        }
        cout << "\n_____________________________________\n";
    }
}

/****************************************************/
/** CHƯƠNG TRÌNH CHÍNH (MAIN) ***/
/****************************************************/
int main()
{
    KhoiTao_CIT07(); // Khởi tạo ngăn xếp
    char luaChon;    // Khai báo biến lựa chọn menu

    do
    {
        // Hiển thị menu
        cout << "CHƯƠNG TRÌNH QUẢN LÝ THƯ VIỆN [DANH SÁCH ĐẶC - STACK]\n";
        cout << "1. Nhập nhiều cuốn sách\n";
        cout << "2. Thêm một sách\n";
        cout << "3. Xem sách ở đầu ngăn xếp\n";
        cout << "4. Lấy nhiều cuốn sách ra khỏi ngăn xếp\n";
        cout << "5. In toàn bộ sách có trong ngăn xếp\n";
        cout << "0. Thoát\n";
        cout << "Nhập lựa chọn của bạn: ";
        cin >> luaChon;

        switch (luaChon)
        {
        case '1':
            NapNhieuPT_Stack_CIT07();
            break;
        case '2':
            Push_Stack_CIT07();
            break;
        case '3':
            Top_Stack_CIT07();
            break;
        case '4':
            LayNhieuPT_Stack_CIT07();
            break;
        case '5':
            Inds_Stack_CIT07();
            break;
        case '0':
            cout << "Cảm ơn bạn đã sử dụng chương trình.\n";
            return 0;
        default:
            cout << "Lựa chọn không hợp lệ! Vui lòng chọn lại.\n";
            break;
        }
        cout << endl; // Dòng trống giữa các lượt chọn
    } while (luaChon != 0);

    return 0;
}
