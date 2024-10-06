
/*************************************/
// CAU TRUC DAT TEN: TenThuocTinh_CIT07
/************************************/

/******************************/
/**KHAI BAO THU VIEN SU DUNG */
/******************************/
using namespace std;
#include <iostream> // Thư viện cho các luồng vào/ra
#include <conio.h>  // Thư viện cho nhập/xuất từ bàn phím trong consol
#include <string>   // Thư viện cho xử lý chuỗi ký tự kiểu string trong C++
#include <cctype>   // Thư viện cho các hàm xử lý ký tự
#include <vector>   // Thư viện cho cấu trúc dữ liệu vector

/******************************/
/**KHAI BAO DANH SACH LIEN KET*/
/******************************/

struct BKPHMC_CIT07 // cấu trúc 1 quyển sách trong danh sách thư viện
{
    string Ten_Sach_CIT07;      // tên sách
    string Ma_Sach_CIT07;       // mã sách
    string Loai_Sach_CIT07;     // loại sách
    int So_Lan_Muon_Sach_CIT07; // số lần mượn sách
};

struct Node_CIT07
{
    BKPHMC_CIT07 data_CIT07;
    Node_CIT07 *next_CIT07;

    // constructor
    Node_CIT07(BKPHMC_CIT07 newData_CIT07)
    {
        data_CIT07 = newData_CIT07;
        next_CIT07 = nullptr;
    }
};

Node_CIT07 *head_CIT07 = nullptr;  // đầu danh sách
int TongSoPhanTuKhaoSat_CIT07 = 0; // số lượng phần tử (thực có) trong danh sách

/*************************************************************/
/**CÁC PHÉP THAO TÁC (TOÁN) CƠ BẢN TRÊN DANH SÁCH LIÊN KẾT: SÁCH*/
/*************************************************************/

// 1. Khởi tạo
void KhoiTao_CIT07()
{
    head_CIT07 = nullptr;
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
    return (head_CIT07 == nullptr);
}

/*************************************************/
// CÁC PHÉP TOÁN XỬ LÝ TRÊN DANH SÁCH ĐẶC: SÁCH //
/***********************************************/

// 4.1 Thêm phần tử mới vào cuối danh sách (Create)
bool ThemPhanTuVaoCuoi_CIT07(BKPHMC_CIT07 books_CIT07)
{
    Node_CIT07 *newBook = new Node_CIT07(books_CIT07);

    if (KiemTraRong_CIT07())
    {
        head_CIT07 = newBook; // Nếu danh sách rỗng, phần tử mới trở thành đầu danh sách
    }
    else
    {
        Node_CIT07 *i = head_CIT07;
        while (i->next_CIT07 != nullptr)
        {
            i = i->next_CIT07; // Duyệt qua danh sách đến phần tử cuối cùng
        }
        i->next_CIT07 = newBook; // Gán phần tử mới vào cuối danh sách
    }
    TongSoPhanTuKhaoSat_CIT07++;
    return true;
}

bool ThemPhanTuVaoDau_CIT07(BKPHMC_CIT07 books_CIT07)
{
    Node_CIT07 *newBook = new Node_CIT07(books_CIT07); // cap phat vung nho cho phan tu moi

    if (KiemTraRong_CIT07())
    {
        head_CIT07 = newBook;
    }
    else
    {
        newBook->next_CIT07 = head_CIT07;
        head_CIT07 = newBook;
    }
    TongSoPhanTuKhaoSat_CIT07++;
    return true;
}

// 5. Xóa một phần tử tại vị trí i (Delete)
bool XoaMotPhanTu_CIT07(int ViTri_CIT07)
{
    // Kiểm tra điều kiện không hợp lệ
    if (ViTri_CIT07 < 0 || ViTri_CIT07 >= TongSoPhanTuKhaoSat_CIT07 || KiemTraRong_CIT07())
        return false;

    Node_CIT07 *deleteNode_CIT07 = head_CIT07; // Khởi tạo node cần xóa

    // Nếu xóa phần tử đầu tiên
    if (ViTri_CIT07 == 0) 
    {
        head_CIT07 = deleteNode_CIT07->next_CIT07; // Đưa đầu danh sách đến phần tử tiếp theo
    }
    else
    {
        Node_CIT07 *tmp = head_CIT07;
        // Duyệt đến phần tử trước phần tử cần xóa
        for (int i = 0; i < ViTri_CIT07 - 1; i++) 
        {
            tmp = tmp->next_CIT07; 
        }
        // Cập nhật con trỏ để bỏ qua phần tử cần xóa
        deleteNode_CIT07 = tmp->next_CIT07;
        tmp->next_CIT07 = deleteNode_CIT07->next_CIT07; // Kết nối phần tử trước với phần tử sau
    }

    delete deleteNode_CIT07; // Giải phóng bộ nhớ
    TongSoPhanTuKhaoSat_CIT07--; // Giảm số lượng phần tử

    return true; // Trả về true nếu xóa thành công
}



// 6. Thêm một phần tử tại vị trí i
bool ThemMotPT_CIT07(BKPHMC_CIT07 newBook_CIT07, int ViTri_CIT07)
{
    Node_CIT07 *newNode_CIT07Book = new Node_CIT07(newBook_CIT07);

    // Danh sách rỗng
    if (KiemTraRong_CIT07())
    {
        if (ViTri_CIT07 == 0) // Nếu vị trí là 0, thêm vào đầu
        {
            head_CIT07 = newNode_CIT07Book;
            TongSoPhanTuKhaoSat_CIT07++; // Cập nhật số lượng phần tử
            return true;
        }
        else // Nếu vị trí không hợp lệ
        {
            cout << "Vi tri khong hop le!" << endl;
            delete newNode_CIT07Book; // Giải phóng bộ nhớ
            return false;
        }
    }

    // Nếu thêm vào đầu
    if (ViTri_CIT07 == 0)
    {
        newNode_CIT07Book->next_CIT07 = head_CIT07; // Cập nhật con trỏ
        head_CIT07 = newNode_CIT07Book; // Cập nhật head
        TongSoPhanTuKhaoSat_CIT07++; // Cập nhật số lượng phần tử
        return true;
    }

    Node_CIT07 *tmp = head_CIT07;
    // Duyệt danh sách đến vị trí trước vị trí cần thêm
    for (int i = 0; i < ViTri_CIT07 - 1 && tmp->next_CIT07 != nullptr; i++)
    {
        tmp = tmp->next_CIT07;
    }

    // Nếu tmp đã đến cuối danh sách
    if (tmp->next_CIT07 == nullptr && ViTri_CIT07 == TongSoPhanTuKhaoSat_CIT07) 
    {
        // Thêm vào cuối
        tmp->next_CIT07 = newNode_CIT07Book; 
        TongSoPhanTuKhaoSat_CIT07++; // Cập nhật số lượng phần tử
        return true;
    }
    else if (ViTri_CIT07 < TongSoPhanTuKhaoSat_CIT07)
    {
        // Thêm vào vị trí bất kỳ
        newNode_CIT07Book->next_CIT07 = tmp->next_CIT07;
        tmp->next_CIT07 = newNode_CIT07Book;
        TongSoPhanTuKhaoSat_CIT07++; // Cập nhật số lượng phần tử
        return true;
    }
    else
    {
        // Vị trí không hợp lệ
        cout << "Vi tri khong hop le!" << endl;
        delete newNode_CIT07Book; // Giải phóng bộ nhớ
        return false;
    }
}


// 7. Cập nhật thuộc tính cho phần tử (Update)
void CapNhatThuocTinh_CIT07(string &code_book)
{
    // Lấy phần tử
    bool found_CIT07 = false; // đánh dấu tìm thấy sách
    Node_CIT07 *tempBook_CIT07 = nullptr;

    Node_CIT07 *temp = head_CIT07;
    while (temp != nullptr)
    {
        if (temp->data_CIT07.Ma_Sach_CIT07 == code_book)
        {
            tempBook_CIT07 = temp;
            found_CIT07 = true;
            break;
        }
        temp = temp->next_CIT07;
    }

    if (!found_CIT07)
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
                cin.ignore();          //
                getline(cin, newName); // Use getline to allow spaces in the name
                tempBook_CIT07->data_CIT07.Ten_Sach_CIT07 = newName;
                cout << "Đã cập nhật thông tin sách thành công!" << endl;
                break;
            }
            case '2':
            {
                string newType;
                cout << "Nhập loại mới cho sách: ";
                cin.ignore();          // Clear input buffer
                getline(cin, newType); // Use getline to allow spaces in the type
                tempBook_CIT07->data_CIT07.Loai_Sach_CIT07 = newType;
                cout << "Đã cập nhật thông tin sách thành công!" << endl;
                break;
            }
            case '3':
            {
                int newCnt;
                cout << "Nhập số lần mượn sách mới cho sách: ";
                cin >> newCnt;
                tempBook_CIT07->data_CIT07.So_Lan_Muon_Sach_CIT07 = newCnt;
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

// 8.1 Sắp xếp danh sách theo số lần mượn sách (So_Lan_Muon_Sach_CIT07) - BB
void SapXepDSTheoSoLanMuonSach_CIT07()
{
    for (Node_CIT07 *i = head_CIT07; i != nullptr; i = i->next_CIT07)
    {
        for (Node_CIT07 *j = head_CIT07; j->next_CIT07 != nullptr; j = j->next_CIT07)
        {
            if (j->data_CIT07.So_Lan_Muon_Sach_CIT07 > j->next_CIT07->data_CIT07.So_Lan_Muon_Sach_CIT07) // Sắp xếp tăng dần
            {
                // Hoán đổi nếu phần tử hiện tại lớn hơn phần tử tiếp theo
                Node_CIT07 temp = *j;
                *j = *j->next_CIT07;
                *j->next_CIT07 = temp; // Phần tử tiếp theo cũng cần hoán đổi
            }
        }
    }
    cout << "Danh sách đã được sắp xếp theo số lần mượn sách.\n";
}

// 8.2 Sắp xếp danh sách theo số lần mượn sách (So_Lan_Muon_Sach_CIT07) - Quiksort

void Partition(Node_CIT07* head, Node_CIT07* end, Node_CIT07** newHead, Node_CIT07** newEnd)
{
    Node_CIT07* pivot = end; // Chọn phần tử cuối làm pivot
    Node_CIT07* prev = nullptr;
    Node_CIT07* curr = head;
    Node_CIT07* tail = pivot; // Thiết lập tail cho danh sách

    // Duyệt qua danh sách và phân loại các phần tử
    while (curr != pivot)
    {
        if (curr->data_CIT07.So_Lan_Muon_Sach_CIT07 < pivot->data_CIT07.So_Lan_Muon_Sach_CIT07)
        {
            if (*newHead == nullptr)
                *newHead = curr; // Thiết lập phần đầu cho danh sách mới

            prev = curr; // Cập nhật prev
            curr = curr->next_CIT07;
        }
        else
        {
            // Di chuyển phần tử ra ngoài
            if (prev)
                prev->next_CIT07 = curr->next_CIT07;
            Node_CIT07* temp = curr; // Lưu giữ phần tử cần di chuyển
            curr = curr->next_CIT07; // Di chuyển curr
            temp->next_CIT07 = nullptr; // Cắt đứt liên kết
            tail->next_CIT07 = temp; // Thêm phần tử vào cuối danh sách
            tail = temp; // Cập nhật tail
        }
    }

    if (*newHead == nullptr)
        *newHead = pivot; // Nếu không có phần tử nhỏ hơn pivot
    *newEnd = tail; // Cập nhật newEnd
}

Node_CIT07* QuickSortRec(Node_CIT07* head, Node_CIT07* end)
{
    if (!head || head == end)
        return head;

    Node_CIT07* newHead = nullptr;
    Node_CIT07* newEnd = nullptr;

    // Phân vùng danh sách
    Partition(head, end, &newHead, &newEnd);

    // Nếu head không phải là pivot
    if (newHead != end)
    {
        // Sắp xếp phần bên trái
        Node_CIT07* temp = newHead;
        while (temp->next_CIT07 != end)
            temp = temp->next_CIT07;

        temp->next_CIT07 = nullptr; // Cắt danh sách ở phần cuối
        newHead = QuickSortRec(newHead, temp); // Gọi đệ quy cho phần bên trái

        // Kết nối với pivot
        temp = newHead;
        while (temp->next_CIT07)
            temp = temp->next_CIT07;

        temp->next_CIT07 = end; // Kết nối pivot với danh sách đã sắp xếp
    }

    // Sắp xếp phần bên phải
    newEnd->next_CIT07 = QuickSortRec(end->next_CIT07, newEnd);

    return newHead; // Trả về đầu danh sách đã sắp xếp
}

void SapXepDSTheoSoLanMuonSach_CIT07()
{
    // Tìm phần tử cuối cùng của danh sách
    Node_CIT07* last = head_CIT07;
    while (last && last->next_CIT07 != nullptr)
    {
        last = last->next_CIT07;
    }

    // Gọi hàm QuickSort
    head_CIT07 = QuickSortRec(head_CIT07, last);
    cout << "Danh sách đã được sắp xếp theo số lần mượn sách.\n";
}

// 9. Tìm sách theo tên
void TimSach_CIT07Sach_CIT07(const string &title)
{
    bool found_CIT07 = false;
    cout << "\nSách tìm thấy:\n";
    Node_CIT07 *temp = head_CIT07;
    for (int i = 0; temp != nullptr; i++, temp = temp->next_CIT07)
    {
        if (temp->data_CIT07.Ten_Sach_CIT07.find(title) != string::npos) // Tìm kiếm theo tên
        {
            cout << "Phần tử " << i + 1 << ":\n";
            cout << "Mã sách: " << temp->data_CIT07.Ma_Sach_CIT07 << "\n";
            cout << "Tên sách: " << temp->data_CIT07.Ten_Sach_CIT07 << "\n";
            cout << "Loại sách: " << temp->data_CIT07.Loai_Sach_CIT07 << "\n";
            cout << "Số lần mượn sách: " << temp->data_CIT07.So_Lan_Muon_Sach_CIT07 << "\n";
            cout << "\n";
            found_CIT07 = true;
        }
    }
    if (!found_CIT07)
    {
        cout << "Không tìm thấy sách nào với tên '" << title << "'!" << endl;
    }
}

// 10. Danh sách các phần tử cùng loại
void DanhSachCungLoai(string &typeBook)
{
    vector<BKPHMC_CIT07> books;
    bool isSuccess = false;
    int cnt = 0;

    for (Node_CIT07 *i = head_CIT07; i != nullptr; i = i->next_CIT07)
    {
        // Kiểm tra xem mã sách có chứa loại sách được tìm kiếm không
        if (i->data_CIT07.Loai_Sach_CIT07 == typeBook)
        {
            books.push_back(i->data_CIT07);
            cnt++;
            isSuccess = true;
        }
    }

    if (!isSuccess)
    {
        cout << "Không tìm thấy sách loại " << typeBook << " \n";
    }
    else
    {
        cout << "Có " << cnt << " cuốn sách cùng loại\n";
        cout << "Danh sách các cuốn sách cùng loại:\n";
        for (const BKPHMC_CIT07 &book : books)
        {
            cout << "Mã sách: " << book.Ma_Sach_CIT07 << endl;
            cout << "Tên sách: " << book.Ten_Sach_CIT07 << endl;
            cout << "Loại sách: " << book.Loai_Sach_CIT07 << endl;
            cout << "Số lần mượn sách: " << book.So_Lan_Muon_Sach_CIT07 << endl;
            cout << "---------------------------------\n"; // Thêm dấu phân cách giữa các sách
        }
    }
}

/****************************************************************************/
// CÁC HÀM THỰC NGHIỆM CÁC PHÉP THAO TÁC (TOÁN) XỬ LÝ TRÊN DANH SÁCH ĐẶC: Sách
/****************************************************************************/

// 1. Nhập nội dung 1 phần tử tại vị trí thứ i trong danh sách để chuẩn bị thêm vào (chưa thêm)
void NhapNoiDungPhanTu_CIT07(BKPHMC_CIT07 &books_CIT07)
{

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
    BKPHMC_CIT07 books_CIT07;
    cout << "Nhập mã sách: ";
    cin >> books_CIT07.Ma_Sach_CIT07;
    cout << "Nhập tên sách: ";
    cin.ignore();                             // Clear input buffer
    getline(cin, books_CIT07.Ten_Sach_CIT07); // Read entire line including spaces
    cout << "Nhập loại sách: ";
    getline(cin, books_CIT07.Loai_Sach_CIT07); // Read entire line including spaces
    cout << "Nhập số lần mượn: ";
    cin >> books_CIT07.So_Lan_Muon_Sach_CIT07;

    ThemPhanTuVaoCuoi_CIT07(books_CIT07);
    cout << "Đã thêm sách thành công!\n";
}

// 3. Xóa phần tử khỏi danh sách
void XoaPhanTu_CIT07()
{
    int viTri;
    cout << "Nhập vị trí sách cần xóa: ";
    cin >> viTri;
    if (XoaMotPhanTu_CIT07(viTri))
    {
        cout << "Đã xóa sách thành công!\n";
    }
    else
    {
        cout << "Xóa sách không thành công!\n";
    }
}

// 4. Thêm nột phần tử vào vị trí bất kì
void ThemPhanTu_CIT07()
{

    BKPHMC_CIT07 book;
    NhapNoiDungPhanTu_CIT07(book);

    int viTri;
    cout << "Nhập vị trí sách cần thêm: ";
    cin >> viTri;
    if (ThemMotPT_CIT07(book, viTri))
    {
        cout << "Đã xóa sách thành công!\n";
    }
    else
    {
        cout << "Xóa sách không thành công!\n";
    }
}

// 5. Xuất thông tin sách
void XuatDS_CIT07()
{
    cout << "DANH SÁCH SÁCH HIỆN CÓ:\n";
    Node_CIT07 *temp = head_CIT07;
    int count = 0;
    while (temp != nullptr)
    {
        cout << "Phần tử " << ++count << ":\n";
        cout << "Mã sách: " << temp->data_CIT07.Ma_Sach_CIT07 << "\n";
        cout << "Tên sách: " << temp->data_CIT07.Ten_Sach_CIT07 << "\n";
        cout << "Loại sách: " << temp->data_CIT07.Loai_Sach_CIT07 << "\n";
        cout << "Số lần mượn sách: " << temp->data_CIT07.So_Lan_Muon_Sach_CIT07 << "\n";
        cout << "\n";
        temp = temp->next_CIT07; // Di chuyển đến phần tử tiếp theo
    }
}

// 6. Cập nhật thông tin sách
void CapNhat_CIT07()
{
    string maSach;
    cout << "Nhập mã sách để cập nhật: ";
    cin >> maSach;
    CapNhatThuocTinh_CIT07(maSach);
}

// 7. Tìm sách theo tên
void TimSach_CIT07()
{
    string tenSach;
    cout << "Nhập tên sách cần tìm: ";
    cin.ignore(); // Clear input buffer
    getline(cin, tenSach);
    TimSach_CIT07Sach_CIT07(tenSach);
}

// 8. In sách cùng loại
void InSachCungLoai_CIT07()
{
    string type;
    cout << "Nhập loại sách: ";
    cin.ignore();
    getline(cin, type);
    DanhSachCungLoai(type);
}

/********************************************/
/**CHƯƠNG TRÌNH CHÍNH VÀ MENU ĐIỀU KHIỂN*/
/********************************************/

int main()
{
    KhoiTao_CIT07();
    int LuaChon;
    while (true)
    {
        cout << "CHƯƠNG TRÌNH QUẢN LÝ THƯ VIỆN [DSLK]\n";
        cout << "1. Thêm sách\n";
        cout << "2. Cập nhật thông tin sách\n";
        cout << "3. Xóa sách ở vị trí đã chọn\n";
        cout << "4. Thêm sách ở vị trí đã chọn\n";
        cout << "5. Sắp xếp danh sách theo số lần mượn\n";
        cout << "6. Tìm sách theo tên\n";
        cout << "7. Xuất danh sách sách\n";
        cout << "8. Xuất danh sách cùng loại sách\n";
        cout << "0. Thoát\n";
        cout << "Nhập lựa chọn: ";
        cin >> LuaChon;

        switch (LuaChon)
        {
        case 1:
        {
            Nhapds_CIT07();
            break;
        }
        case 2:
        {
            CapNhat_CIT07();
            break;
        }
        case 3:
        {
            XoaPhanTu_CIT07();
            break;
        }
        case 4:
        {
            ThemPhanTu_CIT07();
            break;
        }
        case 5:
        {
            SapXepDSTheoSoLanMuonSach_CIT07();
            break;
        }
        case 6:
        {
            TimSach_CIT07();
            break;
        }
        case 7:
        {
            XuatDS_CIT07();
            break;
        }
        case 8:
        {
            InSachCungLoai_CIT07();
            break;
        }
        case 0:
        {
            cout << "Tạm biệt!\n";
            return 0; // Kết thúc chương trình
        }
        default:
        {
            cout << "Lựa chọn không hợp lệ!\n";
            break;
        }
        }
    }

    return 0; // Kết thúc chương trình
}
