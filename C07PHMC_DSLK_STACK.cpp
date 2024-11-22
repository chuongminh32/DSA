/*************************************/
// CAU TRUC DAT TEN: TenThuocTinh_CIT07
/************************************/

#include <iostream> // Thư viện cho các luồng vào/ra
#include <conio.h>  // Thư viện cho nhập/xuất từ bàn phím trong consol
#include <string>   // Thư viện cho xử lý chuỗi ký tự kiểu string trong C++

using namespace std;

/******************************/
/**KHAI BAO DANH SACH LIEN KET STACK */
/******************************/

struct BKPHMC_CIT07 // Cấu trúc 1 quyển sách trong danh sách thư viện
{
    string Ten_Sach_CIT07;      // Tên sách
    string Ma_Sach_CIT07;       // Mã sách
    string Loai_Sach_CIT07;     // Loại sách
    int So_Lan_Muon_Sach_CIT07; // Số lần mượn sách
};

struct Node_CIT07
{
    BKPHMC_CIT07 data_CIT07;
    Node_CIT07 *next_CIT07;

    // constructor
    Node_CIT07(BKPHMC_CIT07 newData)
    {
        data_CIT07 = newData;
        next_CIT07 = nullptr;
    }
};

Node_CIT07 *TOP_CIT07; // con trỏ quản lí toàn bộ STACK

/*************************************************************/
/**CÁC PHÉP THAO TÁC (TOÁN) CƠ BẢN TRÊN STACK DSLK: ***********/
/*************************************************************/

// 1. Khởi tạo
void KhoiTao_CIT07()
{
    TOP_CIT07 = NULL;
}

// 2. Kiểm tra rỗng
bool KiemTraRong_CIT07()
{
    return (TOP_CIT07 == NULL);
}

/*************************************************/
// CÁC PHÉP THAO TÁC CƠ BẢN TRÊN 1 PHẦN TỬ: ****/
/***********************************************/

// 3. Thêm phần tử mới vào đỉnh ngăn xếp  (Push)
void Push_CIT07(BKPHMC_CIT07 Newbook_CIT07)
{
    // tương tự thêm phần tử vào đầu dslk
    Node_CIT07 *newBook = new Node_CIT07(Newbook_CIT07); // khởi tạo phần tử mới
    newBook->next_CIT07 = TOP_CIT07;                     // Trỏ con trỏ next của phần tử mới đến phần tử hiện tại ở đỉnh (top)
    TOP_CIT07 = newBook;                                 // Đặt top trỏ đến phần tử mới, tức là cập nhật đỉnh của ngăn xếp
}

// 4.Lấy phần tử ở đỉnh STack và xóa nó (Pop)
bool Pop_CIT07()
{
    if (KiemTraRong_CIT07())
    {
        cout << "Stack rỗng, không còn phần tử nào để lấy !";
        return false;
    }
    else
    {
        Node_CIT07 *deleteBook = TOP_CIT07;
        TOP_CIT07 = TOP_CIT07->next_CIT07;
        delete deleteBook;
        return true;
    }
}

// 5. Lấy một phần tử ở đỉnh ngăn xếp không xóa (Top)
BKPHMC_CIT07 Top_CIT07()
{
    if (KiemTraRong_CIT07()) // Kiểm tra xem ngăn xếp có rỗng không
    {
        cout << "Danh sách rỗng !" << endl;
        BKPHMC_CIT07 PT_Rong;
        PT_Rong.Ma_Sach_CIT07 = "-1"; // Đánh dấu phần tử rỗng
        return PT_Rong;               // Trả về phần tử rỗng
    }
    else
    {
        return TOP_CIT07->data_CIT07; // Trả về phần tử ở đỉnh mà không xóa
    }
}

// 6. Hàm để lấy và xóa phần tử ở đầu ngăn xếp
BKPHMC_CIT07 PopAndGetTop_CIT07()
{
    BKPHMC_CIT07 PTCanLay = Top_CIT07(); // Lấy phần tử ở đỉnh
    Pop_CIT07();                         // xoá phần tử ở đỉnh stack
    return PTCanLay;                     // Trả về phần tử đã lấy
}

/****************************************************************************/
// CÁC HÀM THỰC NGHIỆM CÁC THAO TÁC XỬ LÝ TRÊN STACK DANH SÁCH LIÊN KẾT: Sách
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
void NhapNoiDungPT_CIT07(BKPHMC_CIT07 &books_STACK_CIT07)
{
    cin.ignore(); // ignore ở đây sau khi nhập số, để xóa ký tự xuống dòng

    cout << "Nhập mã sách: ";
    getline(cin, books_STACK_CIT07.Ma_Sach_CIT07); // Không cần ignore ở đây

    cout << "Nhập tên sách: ";
    getline(cin, books_STACK_CIT07.Ten_Sach_CIT07);

    cout << "Nhập loại sách: ";
    getline(cin, books_STACK_CIT07.Loai_Sach_CIT07);

    cout << "Nhập số lần mượn sách: ";
    cin >> books_STACK_CIT07.So_Lan_Muon_Sach_CIT07;
    cout << endl;
}

// 2. Nạp nhiều phần tử vào Stack
void NapNhieuPT_Stack_CIT07()
{
    while (1)
    {
        int nPhanTu_CIT07;
        string input;
        cout << "Nhập số lượng phần tử cần nạp vào Stack [q - Exit]: ";
        cin >> input;
        if (input == "q")
            return;

        bool isValidNum = true;
        for (char c : input)
        {
            if (!isdigit(c))
            {
                isValidNum = true;
                break;
            }
        }

        if (!isValidNum)
        {
            cout << "Vui lòng nhập đúng định dạng số!\n";
            continue;
        }

        nPhanTu_CIT07 = stoi(input);
        for (int i = 0; i < nPhanTu_CIT07; i++)
        {
            BKPHMC_CIT07 books_STACK_CIT07; // Khai báo biến mới cho mỗi phần tử
            cout << "Nhập phần tử thứ " << i + 1 << ":" << endl;
            NhapNoiDungPT_CIT07(books_STACK_CIT07);
            Push_CIT07(books_STACK_CIT07); // Gọi Push sau khi đã nhập dữ liệu
        }
    }
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
        BKPHMC_CIT07 temp_book_CIT07 = Top_CIT07(); // Lấy phần tử ở đỉnh
        if (temp_book_CIT07.Ma_Sach_CIT07 == "-1")
        {
            cout << "Không còn phần tử nào để lấy.\n";
            break;
        }
        else
        {
            InNoiDung_CIT07(temp_book_CIT07);
            Pop_CIT07(); // Xóa phần tử đã lấy ra khỏi Stack
        }
    }
}

// 3. Lấy một phần tử khỏi Stack
void Top_Stack_CIT07()
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
            BKPHMC_CIT07 temp_book_CIT07 = Top_CIT07();
            if (temp_book_CIT07.Ma_Sach_CIT07 != "-1")
            {
                cout << "Lấy thành công phần tử khỏi Stack:\n ";
                InNoiDung_CIT07(temp_book_CIT07);
            }
            break;
        }
        case '2':
        {
            BKPHMC_CIT07 temp_book_CIT07 = PopAndGetTop_CIT07();
            if (temp_book_CIT07.Ma_Sach_CIT07 != "-1")
            {
                cout << "Lấy thành công phần tử khỏi Stack:\n ";
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
        for (Node_CIT07 *i = TOP_CIT07; i != nullptr; i = i->next_CIT07) // Duyệt ngược để in ra danh sách
        {
            InNoiDung_CIT07(i->data_CIT07);
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
