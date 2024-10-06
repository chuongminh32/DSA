/*************************************/
// CAU TRUC DAT TEN: TenThuocTinh_CIT07
/************************************/

#include <iostream> // Thư viện cho các luồng vào/ra
#include <conio.h>  // Thư viện cho nhập/xuất từ bàn phím trong consol
#include <string>   // Thư viện cho xử lý chuỗi ký tự kiểu string trong C++

using namespace std;

/******************************/
/**KHAI BAO DANH SACH DAC QUEUE */
/******************************/

struct BKPHMC_CIT07 // Cấu trúc 1 quyển sách trong Hàng đợi thư viện
{
    string Ten_Sach_CIT07;      // Tên sách
    string Ma_Sach_CIT07;       // Mã sách
    string Loai_Sach_CIT07;     // Loại sách
    int So_Lan_Muon_Sach_CIT07; // Số lần mượn sách
};

const int PhanTuToiDa_CIT07 = 100;                 // Số lượng phần tử tối đa trong QUEUE
BKPHMC_CIT07 BOOKS_QUEUE_CIT07[PhanTuToiDa_CIT07]; // Hàng đợi CÁC PHẦN TỬ (DS ĐẶC) QUEUE
int SoPTKhaoSat_CIT07;                             // Số lượng phần tử (thực có) trong mảng [n <= max]

/*************************************************************/
/**CÁC PHÉP THAO TÁC (TOÁN) CƠ BẢN TRÊN QUEUE ĐẶC: ***********/
/*************************************************************/

// 1. Khởi tạo
void KhoiTao_CIT07()
{
    SoPTKhaoSat_CIT07 = 0;
}

// 2. Kiểm tra rỗng
bool KiemTraRong_CIT07()
{
    return (SoPTKhaoSat_CIT07 == 0);
}

// 3. Kiểm tra đầy
bool KiemTraDay_CIT07()
{
    return (SoPTKhaoSat_CIT07 == PhanTuToiDa_CIT07 - 1);
}

/*************************************************/
// CÁC PHÉP THAO TÁC CƠ BẢN TRÊN 1 PHẦN TỬ: ****/
/***********************************************/

// 4. Thêm phần tử mới vào cuối hàng đợi  (Enqueue)
bool Enqueue_CIT07(BKPHMC_CIT07 book_QUEUE_CIT07)
{
    if (KiemTraDay_CIT07())
    {
        cout << "QUEUE đầy không thể chứa thêm phần tử mới !" << endl;
        return false;
    }
    else
    {
        BOOKS_QUEUE_CIT07[++SoPTKhaoSat_CIT07] = book_QUEUE_CIT07;
        return true;
    }
}

// 5. Lấy và Xóa phần tử ở đầu hàng đợi sách (PeekAndPOP)
BKPHMC_CIT07 PeekAndPop_CIT07()
{
    if (KiemTraRong_CIT07())
    {
        cout << "Hàng đợi rỗng !" << endl;
        BKPHMC_CIT07 PT_Rong;
        PT_Rong.Ma_Sach_CIT07 = "-1";
        return PT_Rong;
    }
    else
    {
        BKPHMC_CIT07 FirstBook_CIT07 = BOOKS_QUEUE_CIT07[0];
        for (int i = 0; i < SoPTKhaoSat_CIT07 - 1; i++)
        {
            BOOKS_QUEUE_CIT07[i] = BOOKS_QUEUE_CIT07[i + 1];
        }
        SoPTKhaoSat_CIT07--;
        cout << "Đã lấy phần tử đầu ra khỏi hàng đợi!" << endl;
        return FirstBook_CIT07;
    }
}

// 6. Xem phần tử ở đầu mà không xóa
BKPHMC_CIT07 OnlyPeek_CIT07()
{
    if (KiemTraRong_CIT07()) // Kiểm tra xem hàng đợi có rỗng không
    {
        cout << "Hàng đợi rỗng !" << endl;
        BKPHMC_CIT07 PT_Rong;
        PT_Rong.Ma_Sach_CIT07 = "-1"; // Đánh dấu phần tử rỗng
        return PT_Rong;
    }
    else
    {
        return BOOKS_QUEUE_CIT07[0]; // Trả về phần tử ở đầu hàng đợi và xóa
    }
}

// 7. Truy cập phần tử cuối cùng (back())
BKPHMC_CIT07 Back_CIT07()
{
    if (KiemTraRong_CIT07())
    {
        cout << "Hàng đợi rỗng !" << endl;
        BKPHMC_CIT07 PT_Rong;
        PT_Rong.Ma_Sach_CIT07 = "-1";
        return PT_Rong;
    }
    else
    {
        return BOOKS_QUEUE_CIT07[SoPTKhaoSat_CIT07 - 1]; // Trả về phần tử cuối cùng
    }
}

/****************************************************************************/
// CÁC HÀM THỰC NGHIỆM CÁC PHÉP THAO TÁC (TOÁN) XỬ LÝ TRÊN QUEUE HÀNG ĐỢI ĐẶC: Sách
/****************************************************************************/

// 0. Nhập nội dung cho một phần tử
void InNoiDung_CIT07(BKPHMC_CIT07 book_CIT07)
{
    cout << "Mã sách: " << book_CIT07.Ma_Sach_CIT07 << "\n";
    cout << "Tên sách: " << book_CIT07.Ten_Sach_CIT07 << "\n";
    cout << "Loại sách: " << book_CIT07.Loai_Sach_CIT07 << "\n";
    cout << "Số lần mượn sách: " << book_CIT07.So_Lan_Muon_Sach_CIT07 << "\n";
    cout << "\n";
}

// 1. Nhập nội dung 1 phần tử
void NhapNoiDungPT_CIT07(BKPHMC_CIT07 &books_QUEUE_CIT07) // Sử dụng tham chiếu để thay đổi biến bên ngoài
{
    cout << "Nhập mã sách: ";
    cin >> books_QUEUE_CIT07.Ma_Sach_CIT07;
    cin.ignore(); // Loại bỏ ký tự newline sau khi nhập mã sách

    cout << "Nhập tên sách: ";
    getline(cin, books_QUEUE_CIT07.Ten_Sach_CIT07); // Nhập cả dòng

    cout << "Nhập loại sách: ";
    getline(cin, books_QUEUE_CIT07.Loai_Sach_CIT07); // Nhập cả dòng

    cout << "Nhập số lần mượn sách: ";
    cin >> books_QUEUE_CIT07.So_Lan_Muon_Sach_CIT07;
    cout << endl;
    cin.ignore(); // Loại bỏ ký tự newline sau khi nhập số lần mượn sách
}

// 2. Nạp nhiều phần tử vào QUEUE
void NapNhieuPT_QUEUE_CIT07()
{
    while (1)
    {
        int nPhanTu_CIT07;
        string input;
        cout << "Nhập số lượng phần tử cần nạp vào QUEUE [press q - Exit]: ";
        cin >> input;
        if (input == "q") return;

        bool isValidNum = true;

        for (char c : input)
        {
            if (!isdigit(c))
            {
                isValidNum = false;
                break;
            }
        }
        if(!isValidNum)
        {
            cout << "Vui lòng nhập đúng định dạng số ! \n ";
            continue;
        }

        nPhanTu_CIT07 = stoi(input);

        for (int i = 0; i < nPhanTu_CIT07; i++)
        {
            BKPHMC_CIT07 books_QUEUE_CIT07; // Khai báo biến mới cho mỗi phần tử
            cout << "Nhập phần tử thứ " << i + 1 << ":" << endl;
            NhapNoiDungPT_CIT07(books_QUEUE_CIT07);
            if (!Enqueue_CIT07(books_QUEUE_CIT07)) // Gọi Push sau khi đã nhập dữ liệu
            {
                cout << "Không thể thêm phần tử vào QUEUE! QUEUE đã đầy.\n";
                break;
            }
        }
    }

    cout << "Tổng số phần tử trong Hàng đợi: " << SoPTKhaoSat_CIT07 + 1 << " \n"; // Thêm 1 vì SoPTKhaoSat_CIT07 bắt đầu từ -1
}

// 2.2 Nạp thêm 1 phần tử vào QUEUE
void Push_QUEUE_CIT07()
{
    BKPHMC_CIT07 newBook_CIT07;
    NhapNoiDungPT_CIT07(newBook_CIT07);
    Enqueue_CIT07(newBook_CIT07);
}

// 2.3 Lấy nhiều phần tử ra khỏi QUEUE
void LayNhieuPT_QUEUE_CIT07()
{
    int cnt_CIT07;
    cout << "Bạn muốn lấy bao nhiêu phần tử ra khỏi QUEUE? : ";
    cin >> cnt_CIT07;

    cout << "Các phần tử lấy được" << endl;
    for (int i = 0; i < cnt_CIT07; i++)
    {
        BKPHMC_CIT07 temp_book = PeekAndPop_CIT07(); // Lấy phần tử ở đầu hàng đợi
        if (temp_book.Ma_Sach_CIT07 == "-1")
        {
            cout << "Không còn phần tử nào để lấy.\n";
            break;
        }
        else
        {
            cout << "Phần tử " << i + 1 << ":\n";
            InNoiDung_CIT07(temp_book);
        }
    }
}

// 3. Lấy một phần tử khỏi QUEUE (deque)
void Dequeue_QUEUE_CIT07()
{
    while (1)
    {
        char choose;
        cout << "1. Chỉ lấy ra phần tử.\n";
        cout << "2. Lấy ra phần tử và xóa nó.\n";
        cout << "e. Thoát.\n";
        cout << "Lựa chọn của bạn: ";
        cin >> choose;
        switch (choose)
        {
        case '1':
        {
            BKPHMC_CIT07 temp_book_CIT07 = OnlyPeek_CIT07();
            if (temp_book_CIT07.Ma_Sach_CIT07 != "-1")
            {
                cout << "Lấy thành công phần tử khỏi Queue:\n ";
                InNoiDung_CIT07(temp_book_CIT07);
            }
            break;
        }
        case '2':
        {
            BKPHMC_CIT07 temp_book_CIT07 = PeekAndPop_CIT07();
            if (temp_book_CIT07.Ma_Sach_CIT07 != "-1")
            {
                cout << "Lấy thành công phần tử khỏi Queue:\n ";
                InNoiDung_CIT07(temp_book_CIT07);
            }
            break;
        }
        case 'e':
        {
            cout << "Exit [3] !\n";
            return;
        }
        default:
        {
            cout << "Nhập sai, vui lòng nhập '1' hoặc '2' ! \n";
        }
        }
    }
}

// 4. In QUEUE [FIFO]
void Inds_QUEUE_CIT07()
{
    if (KiemTraRong_CIT07())
    {
        cout << "\nHàng đợi CÁC PHẦN TỬ TRONG QUEUE:";
        cout << "  QUEUE RỖNG !\n";
    }
    else
    {
        cout << "\n_____________________________________\n";
        cout << "\nHàng đợi CÁC PHẦN TỬ TRONG QUEUE:\n";
        for (int i = 0; i < SoPTKhaoSat_CIT07; i++) // Duyệt ngược để in ra Hàng đợi
        {
            cout << "Phần tử " << i + 1 << ":\n";
            cout << "Mã sách: " << BOOKS_QUEUE_CIT07[i].Ma_Sach_CIT07 << "\n";
            cout << "Tên sách: " << BOOKS_QUEUE_CIT07[i].Ten_Sach_CIT07 << "\n";
            cout << "Loại sách: " << BOOKS_QUEUE_CIT07[i].Loai_Sach_CIT07 << "\n";
            cout << "Số lần mượn sách: " << BOOKS_QUEUE_CIT07[i].So_Lan_Muon_Sach_CIT07 << "\n";
            cout << "\n";
        }
        cout << "\n_____________________________________\n";
    }
}

/****************************************************/
/** CHƯƠNG TRÌNH CHÍNH (MAIN) ***/
/****************************************************/
int main()
{
    KhoiTao_CIT07(); // Khởi tạo hàng đợi
    char luaChon;    // Khai báo biến lựa chọn menu

    do
    {
        // Hiển thị menu
        cout << "CHƯƠNG TRÌNH QUẢN LÝ THƯ VIỆN [Hàng đợi ĐẶC - QUEUE]\n";
        cout << "1. Nhập nhiều cuốn sách\n";
        cout << "2. Thêm một sách\n";
        cout << "3. Xem sách ở đầu hàng đợi\n";
        cout << "4. Lấy nhiều cuốn sách ra khỏi hàng đợi\n";
        cout << "5. In toàn bộ sách có trong hàng đợi\n";
        cout << "0. Thoát\n";
        cout << "Nhập lựa chọn của bạn: ";
        cin >> luaChon;

        switch (luaChon)
        {
        case '1':
            NapNhieuPT_QUEUE_CIT07();
            break;
        case '2':
            Push_QUEUE_CIT07();
            break;
        case '3':
            Dequeue_QUEUE_CIT07();
            break;
        case '4':
            LayNhieuPT_QUEUE_CIT07();
            break;
        case '5':
            Inds_QUEUE_CIT07();
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
