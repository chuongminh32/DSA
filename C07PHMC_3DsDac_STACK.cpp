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
    if (KiemTraDay_CIT07()) // Kiểm tra ngăn xếp có đầy không
    {
        cout << "Stack đầy!" << endl;
        return false;
    }
    else
    {
        SoPTKhaoSat_CIT07++; // Tăng số lượng phần tử trong stack
        BOOKS_STACK_CIT07[SoPTKhaoSat_CIT07] = books_STACK_CIT07; // Thêm phần tử vào stack
        return true;
    }
}


// 5 lấy ra phần tử và xóa nó 
BKPHMC_CIT07 Pop_CIT07()
{
    BKPHMC_CIT07 temp_book;
    if (KiemTraRong_CIT07()) // Kiểm tra ngăn xếp có rỗng không
    {
        cout << "Stack rỗng!" << endl;
        temp_book.Ma_Sach_CIT07 = "-1"; // Trả về mã sách "-1" để kiểm tra
        return temp_book;
    }
    else
    {
        temp_book = BOOKS_STACK_CIT07[SoPTKhaoSat_CIT07]; // Lấy phần tử ở đỉnh
        SoPTKhaoSat_CIT07--; // Giảm số lượng phần tử trong stack
        return temp_book;
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
void NhapNoiDungPT_CIT07(BKPHMC_CIT07 &book_CIT07)
{
    cout << "Nhập mã sách: ";
    cin >> book_CIT07.Ma_Sach_CIT07;
    cout << "Nhập tên sách: ";
    cin.ignore(); // Xóa bộ nhớ đệm
    getline(cin, book_CIT07.Ten_Sach_CIT07);
    cout << "Nhập loại sách: ";
    getline(cin, book_CIT07.Loai_Sach_CIT07);
    cout << "Nhập số lần mượn sách: ";
    cin >> book_CIT07.So_Lan_Muon_Sach_CIT07;
}

// 2. Nạp nhiều phần tử vào Stack
void NapNhieuPT_Stack_CIT07()
{
    int cnt_CIT07;
    cout << "Bạn muốn nhập bao nhiêu phần tử vào Stack? : ";
    cin >> cnt_CIT07;

    cout << "Nhập thông tin cho các phần tử" << endl;
    for (int i = 0; i < cnt_CIT07; i++)
    {
        BKPHMC_CIT07 newBook_CIT07;
        cout << "Phần tử " << i + 1 << ":\n";
        NhapNoiDungPT_CIT07(newBook_CIT07);
        Push_CIT07(newBook_CIT07);
    }
}

// 2.2 Nạp 1 phần tử vào Stack
void Push_Stack_CIT07()
{
    BKPHMC_CIT07 newBook_CIT07;
    cout << "Nhập thông tin cho phần tử" << endl;
    NhapNoiDungPT_CIT07(newBook_CIT07);
    Push_CIT07(newBook_CIT07);
}

// 2.3 Lấy nhiều phần tử ra khỏi Stack
void LayNhieuPT_Stack_CIT07()
{
    int cnt_CIT07;
    cout << "Bạn muốn lấy bao nhiêu phần tử ra khỏi Stack? : ";
    cin >> cnt_CIT07;

    cout << "Lấy thông tin cho các phần tử" << endl;
    for (int i = 0; i < cnt_CIT07; i++)
    {
        BKPHMC_CIT07 temp_book = Pop_CIT07();
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
}

// 3. Lấy một phần tử khỏi Stack
void Pop_07()
{
    BKPHMC_CIT07 temp_book = Pop_CIT07();
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

// 4. In Stack ngược từ đỉnh đến đáy
void Inds_Stack_CIT07()
{
    cout << "Danh sách các phần tử trong Stack:\n";
    for (int i = SoPTKhaoSat_CIT07; i >= 0; i--)
    {
        cout << "Phần tử " << i + 1 << ":\n";
        InNoiDung_CIT07(BOOKS_STACK_CIT07[i]);
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
        cout << "3. Xem sách ở đầu ngăn xếp và xóa\n";
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
            Pop_07();
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
