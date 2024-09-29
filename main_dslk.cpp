/*************************************/
// CAU TRUC DAT TEN: TenThuocTinh_CIT07
/************************************/

/******************************/
/**KHAI BAO THU VIEN SU DUNG */
/******************************/

using namespace std;
#include <iostream> // thư viện object(input/ output stream)
#include <conio.h>  // console input and output
#include <stdio.h>  // standard input output
#include <string>   // chuỗi ký tự
#include <cstring>  // các hàm xử lý chuỗi
#include <cctype>   // ký tự
#include <vector>

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

struct Node
{
    BKPHMC_CIT07 data;
    Node *next;

    // constructor
    Node(BKPHMC_CIT07 newData)
    {
        data = newData;
        next = nullptr;
    }
};

Node *head_CIT07 = nullptr;        // đầu danh sách
Node *tail_CIT07 = nullptr;        // cuối danh sách
int TongSoPhanTuKhaoSat_CIT07 = 0; // số lượng phần tử (thực có) trong danh sách

/*************************************************************/
/**CÁC PHÉP THAO TÁC (TOÁN) CƠ BẢN TRÊN DANH SÁCH LIÊN KẾT: SÁCH*/
/*************************************************************/

// 1. Khởi tạo
void KhoiTao_CIT07()
{
    head_CIT07 = nullptr;
    tail_CIT07 = nullptr;
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
    Node *newBook = new Node(books_CIT07);

    if (KiemTraRong_CIT07())
    {
        head_CIT07 = newBook; // Nếu danh sách rỗng, phần tử mới trở thành đầu danh sách
        tail_CIT07 = newBook; // Phần tử mới cũng là cuối danh sách
    }
    else
    {
        tail_CIT07->next = newBook; // Gán phần tử mới vào cuối danh sách
        tail_CIT07 = newBook;       // Cập nhật lại tail
    }
    TongSoPhanTuKhaoSat_CIT07++;
    return true;
}

// 4.2 Thêm phần tử vào đầu danh sách
bool ThemPhanTuVaoDau_CIT07(BKPHMC_CIT07 books_CIT07)
{
    Node *newBook = new Node(books_CIT07);

    if (KiemTraRong_CIT07())
    {
        head_CIT07 = newBook;
        tail_CIT07 = newBook;
    }
    else
    {
        newBook->next = head_CIT07;
        head_CIT07 = newBook;
    }
    TongSoPhanTuKhaoSat_CIT07++;
    return true;
}

// 5. Xóa một phần tử tại vị trí i (Delete)
bool XoaMotPhanTu_CIT07(int ViTri_CIT07)
{
    if (ViTri_CIT07 < 0 || ViTri_CIT07 >= TongSoPhanTuKhaoSat_CIT07 || KiemTraRong_CIT07())
        return false;

    Node *temp = head_CIT07;

    if (ViTri_CIT07 == 0) // Nếu xóa phần tử đầu tiên
    {
        head_CIT07 = temp->next;   // Đưa đầu danh sách đến phần tử tiếp theo
        if (head_CIT07 == nullptr) // Nếu danh sách trở nên rỗng
            tail_CIT07 = nullptr;  // Cập nhật tail thành null
        delete temp;               // Giải phóng bộ nhớ
    }
    else
    {
        for (int i = 0; i < ViTri_CIT07 - 1; i++)
        {
            temp = temp->next; // D i chuyển đến phần tử trước phần tử cần xóa
        }
        // temp : node ke truoc phan tu can xoa
        Node *toDelete = temp->next; // Lưu phần tử cần xóa
        temp->next = toDelete->next; // Bỏ qua phần tử cần xóa
        if (toDelete == tail_CIT07)  // Nếu xóa phần tử cuối cùng
            tail_CIT07 = temp;       // Cập nhật lại tail
        delete toDelete;             // Giải phóng bộ nhớ
    }
    TongSoPhanTuKhaoSat_CIT07--;
    return true;
}

// 6. Thêm một phần tử tại vị trí i
bool ThemMotPT_CIT07(BKPHMC_CIT07 newBook_CIT07, int ViTri_CIT07)
{
    Node *newNodeBook = new Node(newBook_CIT07);

    // Danh sách rỗng
    if (KiemTraRong_CIT07())
    {
        if (ViTri_CIT07 == 0) // Nếu vị trí là 0, thêm vào đầu
        {
            head_CIT07 = newNodeBook;
            tail_CIT07 = newNodeBook; // Nếu là phần tử đầu tiên thì head và tail cùng trỏ đến phần tử này
            return true;
        }
        else // Nếu vị trí không hợp lệ
        {
            cout << "Vi tri khong hop le!" << endl;
            delete newNodeBook; // Giải phóng bộ nhớ
            return false;
        }
    }

    // Nếu thêm vào đầu
    if (ViTri_CIT07 == 0)
    {
        ThemPhanTuVaoDau_CIT07(newBook_CIT07);
        return true;
    }

    Node *tmp = head_CIT07;
    // Duyệt danh sách đến vị trí trước vị trí cần thêm
    for (int i = 0; i < ViTri_CIT07 - 1 && tmp->next != nullptr; i++)
    {
        tmp = tmp->next;
    }

    // Nếu tmp đã đến cuối danh sách, thêm vào cuối
    if (tmp->next == nullptr)
    {
        ThemPhanTuVaoCuoi_CIT07(newBook_CIT07);
        return true;
    }
    else
    {
        // them vao vi tri bat ki
        newNodeBook->next = tmp->next;
        tmp->next = newNodeBook;
        return true;
    }
}

// 7. Cập nhật thuộc tính cho phần tử (Update)
void CapNhatThuocTinh_CIT07(string &code_book)
{
    // Lấy phần tử
    bool found = false;
    Node *tempBook = nullptr;

    Node *temp = head_CIT07;
    while (temp != nullptr)
    {
        if (temp->data.Ma_Sach_CIT07 == code_book)
        {
            tempBook = temp;
            found = true;
            break;
        }
        temp = temp->next;
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
                cin.ignore();          //
                getline(cin, newName); // Use getline to allow spaces in the name
                tempBook->data.Ten_Sach_CIT07 = newName;
                cout << "Đã cập nhật thông tin sách thành công!" << endl;
                break;
            }
            case '2':
            {
                string newType;
                cout << "Nhập loại mới cho sách: ";
                cin.ignore();          // Clear input buffer
                getline(cin, newType); // Use getline to allow spaces in the type
                tempBook->data.Loai_Sach_CIT07 = newType;
                cout << "Đã cập nhật thông tin sách thành công!" << endl;
                break;
            }
            case '3':
            {
                int newCnt;
                cout << "Nhập số lần mượn sách mới cho sách: ";
                cin >> newCnt;
                tempBook->data.So_Lan_Muon_Sach_CIT07 = newCnt;
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

// 8. Sắp xếp danh sách theo số lần mượn sách (So_Lan_Muon_Sach_CIT07)
void SapXepDSTheoSoLanMuonSach_CIT07()
{
    for (Node *i = head_CIT07; i != nullptr; i = i->next)
    {
        for (Node *j = head_CIT07; j->next != nullptr; j = j->next)
        {
            if (j->data.So_Lan_Muon_Sach_CIT07 > j->next->data.So_Lan_Muon_Sach_CIT07) // Sắp xếp tăng dần
            {
                // Hoán đổi nếu phần tử hiện tại lớn hơn phần tử tiếp theo
                Node temp = *j;
                *j = *j->next;
                *j->next = temp; // Phần tử tiếp theo cũng cần hoán đổi
            }
        }
    }
    cout << "Danh sách đã được sắp xếp theo số lần mượn sách.\n";
}

// 9. Tìm sách theo tên
void TimSach_CIT07Sach_CIT07(const string &title)
{
    bool found = false;
    cout << "\nSách tìm thấy:\n";
    Node *temp = head_CIT07;
    for (int i = 0; temp != nullptr; i++, temp = temp->next)
    {
        if (temp->data.Ten_Sach_CIT07.find(title) != string::npos) // Tìm kiếm theo tên
        {
            cout << "Phần tử " << i + 1 << ":\n";
            cout << "Mã sách: " << temp->data.Ma_Sach_CIT07 << "\n";
            cout << "Tên sách: " << temp->data.Ten_Sach_CIT07 << "\n";
            cout << "Loại sách: " << temp->data.Loai_Sach_CIT07 << "\n";
            cout << "Số lần mượn sách: " << temp->data.So_Lan_Muon_Sach_CIT07 << "\n";
            cout << "\n";
            found = true;
        }
    }
    if (!found)
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

    for (Node *i = head_CIT07; i != nullptr; i = i->next)
    {
        // Kiểm tra xem mã sách có chứa loại sách được tìm kiếm không
        if (i->data.Loai_Sach_CIT07 == typeBook)
        {
            books.push_back(i->data);
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
    Node *temp = head_CIT07;
    int count = 0;
    while (temp != nullptr)
    {
        cout << "Phần tử " << ++count << ":\n";
        cout << "Mã sách: " << temp->data.Ma_Sach_CIT07 << "\n";
        cout << "Tên sách: " << temp->data.Ten_Sach_CIT07 << "\n";
        cout << "Loại sách: " << temp->data.Loai_Sach_CIT07 << "\n";
        cout << "Số lần mượn sách: " << temp->data.So_Lan_Muon_Sach_CIT07 << "\n";
        cout << "\n";
        temp = temp->next; // Di chuyển đến phần tử tiếp theo
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
        cout << "CHƯƠNG TRÌNH QUẢN LÝ THƯ VIỆN\n";
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
