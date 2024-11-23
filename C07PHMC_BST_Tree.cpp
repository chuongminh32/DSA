/*******************************/
/** KHAI BÁO THƯ VIỆN SỬ DỤNG **/
/*******************************/
using namespace std;
#include <iostream> // Thư viện cho các luồng vào/ra
#include <vector>   // Thư viện cho cấu trúc dữ liệu vector
#include <queue>    // Thư viện cho cấu trúc dữ liệu hàng đợi
#include <stack>    // Thư viện cho
#include <limits>   // Thư viện này cung cấp các thông tin về các giới hạn của kiểu dữ liệu

/***************************/
/** KHAI BÁO CÂY NHỊ PHÂN **/
/******************** ******/

// Cấu trúc một quyển sách
struct BKPHMC_CIT07
{
    string Ten_Sach_CIT07;      // tên sách
    string Ma_Sach_CIT07;       // mã sách
    string Loai_Sach_CIT07;     // loại sách
    int So_Lan_Muon_Sach_CIT07; // số lần mượn sách
};

// Cấu trúc một cây
struct Node_CIT07
{
    BKPHMC_CIT07 data_CIT07;
    Node_CIT07 *left_CIT07;
    Node_CIT07 *right_CIT07;

    // constructor khởi tạo dữ liệu mới
    Node_CIT07(BKPHMC_CIT07 newData_CIT07)
    {
        data_CIT07 = newData_CIT07; // gán dữ liệu mới cho nút
        left_CIT07 = nullptr;       // khởi tạo con trỏ trái là null
        right_CIT07 = nullptr;      // khởi tạo con trỏ phải là null
    }
};

Node_CIT07 *root_CIT07 = nullptr; // gốc của cây
int soPhanTu_CIT07 = 0;           // số phần tử trong cây
/*************************************************************/
/** CÁC PHÉP THAO TÁC (TOÁN) CƠ BẢN TRÊN CÂY NHỊ PHÂN: SÁCH **/
/*************************************************************/

// 1. Khởi tạo cây
void KhoiTao_CIT07()
{
    root_CIT07 = nullptr;
    soPhanTu_CIT07 = 0; // Khởi tạo số phần tử trong cây là 0
}

// 2. Kiểm tra cây rỗng
bool KiemTraCayRong_CIT07()
{
    return (root_CIT07 == nullptr);
}

/*************************************************/
// CÁC PHÉP TOÁN XỬ LÝ TRÊN CÂY NHỊ PHÂN: SÁCH //
/***********************************************/
// [1]. Nhập nội dung 1 phần tử tại vị trí thứ i trong cây để chuẩn bị thêm vào (chưa thêm)
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

// [2] Thêm phần tử mới
/**
 * @brief Thêm một phần tử vào cây nhị phân tìm kiếm.
 *
 * Hàm này thêm một phần tử mới vào cây nhị phân tìm kiếm dựa trên số lần mượn sách.
 * Nếu cây rỗng, nó sẽ tạo một nút mới và trả về nút đó. Nếu không, nó sẽ so sánh
 * số lần mượn sách của phần tử mới với số lần mượn sách của nút hiện tại và thêm
 * phần tử mới vào cây con trái hoặc cây con phải tương ứng.
 *
 * @param node Con trỏ đến nút gốc của cây nhị phân tìm kiếm.
 * @param books_CIT07 Dữ liệu của phần tử mới cần thêm vào cây.
 * @return Node_CIT07* Con trỏ đến nút gốc của cây sau khi thêm phần tử mới.
 *
 ví dụ:
BKPHMC_CIT07 books1 = {"Book1", "003", "TypeA", 5};
BKPHMC_CIT07 books2 = {"Book2", "001", "TypeB", 3};
BKPHMC_CIT07 books3 = {"Book3", "004", "TypeC", 7};
BKPHMC_CIT07 books4 = {"Book4", "002", "TypeD", 2};
BKPHMC_CIT07 books5 = {"Book5", "005", "TypeE", 4};

root = ThemPhanTu_CIT07(root, books1);
root = ThemPhanTu_CIT07(root, books2);
root = ThemPhanTu_CIT07(root, books3);
root = ThemPhanTu_CIT07(root, books4);
root = ThemPhanTu_CIT07(root, books5);

Thêm Book1: "003"
Cây rỗng, tạo nút mới với mã sách "003":
    003 

Thêm Book2: "001"
"001" < "003", thêm vào cây con trái của "003":
    003
   /
 001

 Thêm Book3: "004"
"004" > "003", thêm vào cây con phải của "003":
    003
   /   \
 001   004

 Thêm Book4: "002"
"002" < "003", đi đến cây con trái của "003".
"002" > "001", thêm vào cây con phải của "001":
    003
   /   \
 001   004
   \
   002

Thêm Book5: "005"
"005" > "003", đi đến cây con phải của "003".
"005" > "004", thêm vào cây con phải của "004":
    003
   /   \
 001   004
   \     \
   002   005

   Kết quả cuối cùng
Cây nhị phân tìm kiếm sau khi thêm các phần tử:
    003
   /   \
 001   004
   \     \
   002   005
 */


Node_CIT07 *ThemPhanTu_CIT07(Node_CIT07 *node, BKPHMC_CIT07 books_CIT07)
{
    // Nếu cây rỗng thì tạo nút mới và trả về
    if (node == nullptr)
    {
        node = new Node_CIT07(books_CIT07);
        soPhanTu_CIT07++; // Tăng số phần tử trong cây
        return node;
    }

    // Nếu mã sách nhỏ hơn mã sách của nút hiện tại thì thêm vào cây con trái
    if (books_CIT07.Ma_Sach_CIT07 < node->data_CIT07.Ma_Sach_CIT07)
    {
        node->left_CIT07 = ThemPhanTu_CIT07(node->left_CIT07, books_CIT07);
    }
    // Nếu mã sách lớn hơn mã sách của nút hiện tại thì thêm vào cây con phải
    else
    {
        node->right_CIT07 = ThemPhanTu_CIT07(node->right_CIT07, books_CIT07);
    }
    return node;
}

// [3] Thêm một phần tử vào cây
void ThemPhanTuVaoCay_CIT07(BKPHMC_CIT07 books_CIT07)
{
    root_CIT07 = ThemPhanTu_CIT07(root_CIT07, books_CIT07);
}

// [4] Thêm nhiều phần tử vào cây
void ThemNhieuPhanTuVaoCay_CIT07()
{
    int n;
    cout << "Nhập số lượng sách cần thêm: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        BKPHMC_CIT07 books_CIT07;
        cout << "Nhập thông tin sách thứ " << i + 1 << ":\n";
        NhapNoiDungPhanTu_CIT07(books_CIT07);
        ThemPhanTuVaoCay_CIT07(books_CIT07);
    }
}

// [5] Tìm nút có mã sách x trên cây
/**
 * @brief Tìm một nút trong cây nhị phân tìm kiếm dựa trên mã sách.
 *
 * Hàm này tìm một nút trong cây nhị phân tìm kiếm có mã sách trùng với mã sách được cung cấp.
 *
 * @param node Con trỏ đến nút gốc của cây nhị phân tìm kiếm.
 * @param maSach Số lần mượn sách cần tìm.
 * @return Node_CIT07* Con trỏ đến nút chứa mã sách cần tìm hoặc nullptr nếu không tìm thấy.
 */
Node_CIT07 *TimNodeTheoMaSach_CIT07(Node_CIT07 *node, const string &maSach)
{
    if (node == nullptr || node->data_CIT07.Ma_Sach_CIT07 == maSach)
    {
        return node;
    }

    // Nếu mã sách nhỏ hơn mã sách của nút hiện tại thì tìm ở cây con trái
    if (maSach < node->data_CIT07.Ma_Sach_CIT07)
    {
        return TimNodeTheoMaSach_CIT07(node->left_CIT07, maSach);
    }

    return TimNodeTheoMaSach_CIT07(node->right_CIT07, maSach);
}

// Tìm node nhỏ nhất trong cây
Node_CIT07 *TimNodeMin(Node_CIT07 *node)
{
    while (node->left_CIT07 != nullptr)
    {
        node = node->left_CIT07;
    }
    return node;
}

// [6] Xóa nút có mã sách x trên cây
/**
 * @brief Xóa một nút trong cây nhị phân tìm kiếm dựa trên mã sách.
 *
 * Hàm này tìm và xóa một nút trong cây nhị phân tìm kiếm có mã sách trùng với mã sách được cung cấp.
 * Nếu nút cần xóa có hai con, giá trị của nút sẽ được thay thế bằng giá trị của nút nhỏ nhất trong cây con bên phải,
 * sau đó nút nhỏ nhất này sẽ bị xóa.
 *
 * @param node Con trỏ đến nút gốc của cây nhị phân tìm kiếm.
 * @param maSach Mã sách của phần tử cần xóa.
 * @return Node_CIT07* Con trỏ đến nút gốc của cây nhị phân tìm kiếm sau khi xóa phần tử.
 */
Node_CIT07 *XoaNodeTheoMaSach_CIT07(Node_CIT07 *node07, const string &maSach)
{
    // Nếu cây rỗng thì trả về nullptr
    if (node07 == nullptr)
    {
        return node07;
    }

    if (maSach < node07->data_CIT07.Ma_Sach_CIT07)
    {
        node07->left_CIT07 = XoaNodeTheoMaSach_CIT07(node07->left_CIT07, maSach);
    }
    else if (maSach > node07->data_CIT07.Ma_Sach_CIT07)
    {
        node07->right_CIT07 = XoaNodeTheoMaSach_CIT07(node07->right_CIT07, maSach);
    }
    else
    {
        // node07 cần xóa được tìm thấy, node07 có một con phải
        if (node07->left_CIT07 == nullptr)
        {
            // Lưu con phải và xóa node07
            Node_CIT07 *temp = node07->right_CIT07;
            delete node07;
            soPhanTu_CIT07--; // Giảm số phần tử trong cây
            return temp;
        }

        else if (node07->right_CIT07 == nullptr)
        {
            Node_CIT07 *temp = node07->left_CIT07;
            delete node07;
            soPhanTu_CIT07--; // Giảm số phần tử trong cây
            return temp;
        }

        // node07 có hai con, lấy node07 nhỏ nhất từ cây con phải
        Node_CIT07 *temp = TimNodeMin(node07->right_CIT07);
        // Copy dữ liệu từ node07 nhỏ nhất sang node07 cần xóa
        node07->data_CIT07 = temp->data_CIT07;
        // Xóa node07 nhỏ nhất
        node07->right_CIT07 = XoaNodeTheoMaSach_CIT07(node07->right_CIT07, temp->data_CIT07.Ma_Sach_CIT07);
    }

    return node07;
}

// [7] Xóa một phần tử theo mã sách
bool XoaMotPhanTuMaSach_CIT07(const string &maSach)
{
    if (KiemTraCayRong_CIT07())
    {
        cout << "Cây rỗng, không thể xóa!" << endl;
        return false;
    }

    root_CIT07 = XoaNodeTheoMaSach_CIT07(root_CIT07, maSach);
    if (root_CIT07 == nullptr)
    {
        cout << "Không tìm thấy sách có mã '" << maSach << "'!" << endl;
        return false;
    }

    cout << "Đã xóa sách có mã '" << maSach << "' thành công!" << endl;
    return true;
}

// [8] Cập nhật thuộc tính cho phần tử (Update)
void CapNhatThuocTinh_CIT07(Node_CIT07 *node, string &maSach_07)
{
    if (node == nullptr)
    {
        cout << "Không tìm thấy sách có mã '" << maSach_07 << "'!" << endl;
        return;
    }

    if (node->data_CIT07.Ma_Sach_CIT07 == maSach_07)
    {
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
                cin.ignore();
                getline(cin, newName);
                node->data_CIT07.Ten_Sach_CIT07 = newName;
                cout << "Đã cập nhật thông tin sách thành công!" << endl;
                break;
            }
            case '2':
            {
                string newType;
                cout << "Nhập loại mới cho sách: ";
                cin.ignore();
                getline(cin, newType);
                node->data_CIT07.Loai_Sach_CIT07 = newType;
                cout << "Đã cập nhật thông tin sách thành công!" << endl;
                break;
            }
            case '3':
            {
                int newCnt;
                cout << "Nhập số lần mượn sách mới cho sách: ";
                cin >> newCnt;
                node->data_CIT07.So_Lan_Muon_Sach_CIT07 = newCnt;
                cout << "Đã cập nhật thông tin sách thành công!" << endl;
                break;
            }
            case 'e':
                cout << "Thoát khỏi chương trình.\n";
                return;
            default:
                cout << "Lựa chọn không hợp lệ, chọn lại: \n";
            }
        }
    }
    else if (maSach_07 < node->data_CIT07.Ma_Sach_CIT07)
    {
        CapNhatThuocTinh_CIT07(node->left_CIT07, maSach_07);
    }
    else
    {
        CapNhatThuocTinh_CIT07(node->right_CIT07, maSach_07);
    }
}

// [9] Tìm sách theo tên
/**
 * @brief Tìm kiếm sách trong cây nhị phân theo tiêu đề.
 *
 * Hàm này duyệt qua cây nhị phân tìm kiếm và in ra thông tin của các sách có tiêu đề chứa chuỗi tìm kiếm.
 *
 * @param node Con trỏ đến nút gốc của cây nhị phân.
 * @param title Tiêu đề sách cần tìm kiếm.
 */
void TimSach_CIT07(Node_CIT07 *node, const string &title)
{
    if (node == nullptr)
    {
        return;
    }

    if (node->data_CIT07.Ten_Sach_CIT07 == title)
    {
        cout << "Mã sách: " << node->data_CIT07.Ma_Sach_CIT07 << "\n";
        cout << "Tên sách: " << node->data_CIT07.Ten_Sach_CIT07 << "\n";
        cout << "Loại sách: " << node->data_CIT07.Loai_Sach_CIT07 << "\n";
        cout << "Số lần mượn sách: " << node->data_CIT07.So_Lan_Muon_Sach_CIT07 << "\n";
        return;
    }

    TimSach_CIT07(node->left_CIT07, title);
    TimSach_CIT07(node->right_CIT07, title);
}

// [10] Danh sách các phần tử cùng loại
/**
 * @brief Traverses a binary search tree and collects books of a specified type.
 *
 * This function performs an in-order traversal of a binary search tree starting from the given node.
 * It collects all books that match the specified type and stores them in the provided vector.
 *
 * @param node Pointer to the root node of the binary search tree.
 * @param typeBook The type of book to search for.
 * @param books Vector to store the books that match the specified type.
 */
void DanhSachCungLoai_CIT07(Node_CIT07 *node, const string &typeBook, vector<BKPHMC_CIT07> &books)
{
    if (node == nullptr)
    {
        return;
    }

    DanhSachCungLoai_CIT07(node->left_CIT07, typeBook, books);

    if (node->data_CIT07.Loai_Sach_CIT07 == typeBook)
    {
        books.push_back(node->data_CIT07);
    }

    DanhSachCungLoai_CIT07(node->right_CIT07, typeBook, books);
}

/****************************************************************************/
// CÁC HÀM THỰC NGHIỆM CÁC PHÉP THAO TÁC (TOÁN) XỬ LÝ TRÊN CÂY NHỊ PHÂN: Sách
/****************************************************************************/

// 1. Nhập cây
void NhapCay_07()
{
    BKPHMC_CIT07 books_CIT07;
    cout << "Nhập mã sách: ";
    cin >> books_CIT07.Ma_Sach_CIT07;
    cout << "Nhập tên sách: ";
    cin.ignore();
    getline(cin, books_CIT07.Ten_Sach_CIT07);
    cout << "Nhập loại sách: ";
    getline(cin, books_CIT07.Loai_Sach_CIT07);
    cout << "Nhập số lần mượn: ";
    cin >> books_CIT07.So_Lan_Muon_Sach_CIT07;

    ThemPhanTuVaoCay_CIT07(books_CIT07);
    cout << "Đã thêm sách thành công!\n";
}

// 2. Xóa phần tử theo mã sách
void XoaPhanTuTheoMaSach_07()
{
    string maSach_07;
    cout << "Nhập mã sách cần xóa: ";
    cin >> maSach_07;
    XoaMotPhanTuMaSach_CIT07(maSach_07);
}

// 3. Cập nhật
void CapNhatThuocTinh_07()
{
    string maSach_07;
    cout << "Nhập mã sách cần cập nhật: ";
    cin >> maSach_07;
    CapNhatThuocTinh_CIT07(root_CIT07, maSach_07);
}

// 4. Tìm sách theo tên
void TimSachTheoTen_07()
{
    string title;
    cout << "Nhập tên sách cần tìm: ";
    getline(cin, title);
    TimSach_CIT07(root_CIT07, title);
}

// 5. Danh sách các phần tử cùng loại
void DanhSachCungLoai_07()
{
    string loaiSach07;
    cout << "Nhập loại sách cần tìm: ";
    getline(cin, loaiSach07);

    vector<BKPHMC_CIT07> books07;
    DanhSachCungLoai_CIT07(root_CIT07, loaiSach07, books07);

    if (root_CIT07 == nullptr)
    {
        cout << "Root chưa được khởi tạo.\n";
        return;
    }
    if (books07.empty())
    {
        cout << "Không tìm thấy sách cùng loại." << endl;
    }
    else
    {
        cout << "Danh sách sách cùng loại:\n";
        int stt = 0;
        for (const BKPHMC_CIT07 &book : books07)
        {
            cout << "STT " << ++stt << ":\n";
            cout << "Mã sách: " << book.Ma_Sach_CIT07 << "\n";
            cout << "Tên sách: " << book.Ten_Sach_CIT07 << "\n";
            cout << "Loại sách: " << book.Loai_Sach_CIT07 << "\n";
            cout << "Số lần mượn sách: " << book.So_Lan_Muon_Sach_CIT07 << "\n\n";
        }
    }
}

// 6.  Hàm chung để in thông tin sách
void inThongTinSach_07(Node_CIT07 *node_07)
{
    if (node_07 == nullptr)
        return;
    cout << "Mã sách: " << node_07->data_CIT07.Ma_Sach_CIT07 << "\n";
    cout << "Tên sách: " << node_07->data_CIT07.Ten_Sach_CIT07 << "\n";
    cout << "Loại sách: " << node_07->data_CIT07.Loai_Sach_CIT07 << "\n";
    cout << "Số lần mượn sách: " << node_07->data_CIT07.So_Lan_Muon_Sach_CIT07 << "\n\n";
}
 

/*
6.1 Node - Left - Right (NLR) (tiền tố)
         10
       /    \
      5      15
     / \    /  \
    3   7  20   22
10 5 3 7 15 20 22
Quá trình duyệt cây theo thứ tự NLR không đệ quy
Bắt đầu tại gốc cây (10):
Đẩy 10 vào stack.
Lấy 10 ra khỏi stack và in thông tin.
Đẩy 15 vào stack.
Đẩy 5 vào stack.
Stack: [15, 5]
Output07: 10
Duyệt cây con trái của 10 (5):
Lấy 5 ra khỏi stack và in thông tin.
Đẩy 7 vào stack.
Đẩy 3 vào stack.
Stack: [15, 7, 3]
Output07: 10 5
Duyệt cây con trái của 5 (3):
Lấy 3 ra khỏi stack và in thông tin.
3 không có con, tiếp tục.
Stack: [15, 7]
Output07: 10 5 3
Duyệt cây con phải của 5 (7):
Lấy 7 ra khỏi stack và in thông tin.
7 không có con, tiếp tục.
Stack: [15]
Output07: 10 5 3 7
Duyệt cây con phải của 10 (15):
Lấy 15 ra khỏi stack và in thông tin.
Đẩy 22 vào stack.
Đẩy 20 vào stack.
Stack: [22, 20]
Output07: 10 5 3 7 15
Duyệt cây con trái của 15 (20):
Lấy 20 ra khỏi stack và in thông tin.
20 không có con, tiếp tục.
Stack: [22]
Output07: 10 5 3 7 15 20
Duyệt cây con phải của 15 (22):
Lấy 22 ra khỏi stack và in thông tin.
22 không có con, kết thúc.
Stack: []
Output07: 10 5 3 7 15 20 22
Kết quả cuối cùng:10 5 3 7 15 20 22
*/
void duyetCayNLR(Node_CIT07 *node_07)
{
    if (node_07 == nullptr)
        return;
    inThongTinSach_07(node_07);
    duyetCayNLR(node_07->left_CIT07);
    duyetCayNLR(node_07->right_CIT07); 
}
void khuDeQuy_NLR(Node_CIT07 *node_07) 
{
    if (node_07 == nullptr)
        return;

    // Sử dụng stack để duyệt cây theo NLR
    stack<Node_CIT07 *> s;
    s.push(node_07);

    while (!s.empty())
    {
        Node_CIT07 *node = s.top(); // Lấy node đầu tiên trong stack
        s.pop();

        inThongTinSach_07(node); // In thông tin node

        // Thêm node con phải vào stack trước để duyệt sau
        if (node->right_CIT07 != nullptr)
            s.push(node->right_CIT07);

        // Thêm node con trái vào stack sau để duyệt trước
        if (node->left_CIT07 != nullptr) 
            s.push(node->left_CIT07);
    }
}


/*
6.2 Node - Right - Left (NRL) (tiền tố)
         10
       /    \
      5      15
     / \    /  \
    3   7  20   22
10, 15, 22, 20, 5, 7, 3
Quá trình duyệt cây theo thứ tự NRL không đệ quy
Bắt đầu tại gốc cây (10):
Đẩy 10 vào stack.
Lấy 10 ra khỏi stack và in thông tin.
Đẩy 5 vào stack.
Đẩy 15 vào stack.
Stack: [5, 15]
Output: 10

Duyệt cây con phải của 10 (15):
Lấy 15 ra khỏi stack và in thông tin.
Đẩy 20 vào stack.
Đẩy 22 vào stack.
Stack: [5, 20, 22]
Output: 10 15

Duyệt cây con phải của 15 (22):
Lấy 22 ra khỏi stack và in thông tin.
22 không có con, tiếp tục.
Stack: [5, 20]
Output: 10 15 22

Duyệt cây con trái của 15 (20):
Lấy 20 ra khỏi stack và in thông tin.
20 không có con, tiếp tục.
Stack: [5]
Output: 10 15 22 20

Duyệt cây con trái của 10 (5):
Lấy 5 ra khỏi stack và in thông tin.
Đẩy 3 vào stack.
Đẩy 7 vào stack.
Stack: [3, 7]
Output: 10 15 22 20 5

Duyệt cây con phải của 5 (7):
Lấy 7 ra khỏi stack và in thông tin.
7 không có con, tiếp tục.
Stack: [3]
Output: 10 15 22 20 5 7

Duyệt cây con trái của 5 (3):
Lấy 3 ra khỏi stack và in thông tin.
3 không có con, kết thúc.
Stack: []
Output: 10 15 22 20 5 7 3
Kết quả cuối cùng:10 15 22 20 5 7 3

*/
void duyetCayNRL(Node_CIT07 *node_07) 
{
    if (node_07 == nullptr) return;
    inThongTinSach_07(node_07);
    duyetCayNRL(node_07->right_CIT07);
    duyetCayNRL(node_07->left_CIT07);
}

void khuDeQuy_NRL(Node_CIT07 *node_07) 
{
    if (node_07 == nullptr)
        return;

    // Sử dụng stack để duyệt cây theo NRL
    stack<Node_CIT07 *> s;
    s.push(node_07);

    while (!s.empty())
    {
        Node_CIT07 *node = s.top(); // Lấy node đầu tiên trong stack
        s.pop();

        inThongTinSach_07(node); // In thông tin node

        // Thêm node con trái vào stack trước để duyệt sau
        if (node->left_CIT07 != nullptr)
            s.push(node->left_CIT07);

        // Thêm node con phải vào stack sau để duyệt trước
        if (node->right_CIT07 != nullptr)
            s.push(node->right_CIT07);
    }
}


/*
6.3 Right - Node - Left (RNL) (trung tố)
         10
       /    \
      5      15
     / \    /  \
    3   7  20   22

22 15 20 10 7 5 3
Quá trình duyệt cây theo thứ tự RNL không đệ quy
Bắt đầu tại gốc cây (10):
Đẩy 10 vào stack.
Di chuyển đến cây con phải của 10 (15).
Stack: [10]
Current: 15
Duyệt cây con phải của 10 (15):
Đẩy 15 vào stack.
Di chuyển đến cây con phải của 15 (22).
Stack: [10, 15]
Current: 22
Duyệt cây con phải của 15 (22):
Đẩy 22 vào stack.
22 không có con phải, lấy 22 ra khỏi stack và in thông tin.
Stack: [10, 15]
Output07: 22
Current: nullptr
Trở lại nút 15:
Lấy 15 ra khỏi stack và in thông tin.
Di chuyển đến cây con trái của 15 (20).
Stack: [10]
Output07: 22 15
Current: 20
Duyệt cây con trái của 15 (20):
Đẩy 20 vào stack.
20 không có con phải, lấy 20 ra khỏi stack và in thông tin.
Stack: [10]
Output07: 22 15 20
Current: nullptr
Trở lại nút 10:
Lấy 10 ra khỏi stack và in thông tin.
Di chuyển đến cây con trái của 10 (5).
Stack: []
Output07: 22 15 20 10
Current: 5
Duyệt cây con trái của 10 (5):
Đẩy 5 vào stack.
Di chuyển đến cây con phải của 5 (7).
Stack: [5]
Current: 7
Duyệt cây con phải của 5 (7):
Đẩy 7 vào stack.
7 không có con phải, lấy 7 ra khỏi stack và in thông tin.
Stack: [5]
Output07: 22 15 20 10 7
Current: nullptr
Trở lại nút 5:
Lấy 5 ra khỏi stack và in thông tin.
Di chuyển đến cây con trái của 5 (3).
Stack: []
Output07: 22 15 20 10 7 5
Current: 3
Duyệt cây con trái của 5 (3):
Đẩy 3 vào stack.
3 không có con phải, lấy 3 ra khỏi stack và in thông tin.
Stack: []
Output07: 22 15 20 10 7 5 3
Current: nullptr
Kết quả cuối cùng: 22 15 20 10 7 5 3
*/
void duyetCayRNL(Node_CIT07 *node_07)
{
    if (node_07 == nullptr)
        return;
    duyetCayRNL(node_07->right_CIT07);
    inThongTinSach_07(node_07);
    duyetCayRNL(node_07->left_CIT07);
}
void khuDeQuy_RNL(Node_CIT07 *node_07) 
{
    if (node_07 == nullptr)
        return;

    // Sử dụng stack để duyệt cây theo RNL
    stack<Node_CIT07 *> s;
    Node_CIT07 *current = node_07;

    while (current != nullptr || !s.empty())
    {
        while (current != nullptr)
        {
            s.push(current);
            current = current->right_CIT07;
        }

        current = s.top();
        s.pop();

        inThongTinSach_07(current);

        current = current->left_CIT07;
    }
}


/*
6.4 Right - Left - Node (RLN) (hau tố)
         10
       /    \
      5      15
     / \    /  \
    3   7  20   22

22 20 15 7 3 5 10
Quá trình duyệt cây theo thứ tự RLN không đệ quy
- Bắt đầu tại gốc cây (10):
Đẩy 10 vào stackNode07.StackNode07: [10]
Output07: []
StackNode07: [10]

Lấy 10 ra khỏi stackNode07 và đẩy vào output07:
Đẩy 15 vào stackNode07.
Đẩy 5 vào stackNode07.
StackNode07: [15, 5]
Output07: [10]

Lấy 5 ra khỏi stackNode07 và đẩy vào output07:
Đẩy 7 vào stackNode07.
Đẩy 3 vào stackNode07.
StackNode07: [15, 7, 3]
Output07: [10, 5]
 
Lấy 3 ra khỏi stackNode07 và đẩy vào output07:
3 không có con, tiếp tục.
StackNode07: [15, 7]
Output07: [10, 5, 3]

Lấy 7 ra khỏi stackNode07 và đẩy vào output07:
7 không có con, tiếp tục.
StackNode07: [15]
Output07: [10, 5, 3, 7]

Lấy 15 ra khỏi stackNode07 và đẩy vào output07:
Đẩy 22 vào stackNode07.
Đẩy 20 vào stackNode07.
StackNode07: [22, 20]
Output07: [10, 5, 3, 7, 15]

Lấy 20 ra khỏi stackNode07 và đẩy vào output07:
20 không có con, tiếp tục.
StackNode07: [22]
Output07: [10, 5, 3, 7, 15, 20]

Lấy 22 ra khỏi stackNode07 và đẩy vào output07:
22 không có con, tiếp tục.
StackNode07: []
Output07: [10, 5, 3, 7, 15, 20, 22]

Duyệt ngăn xếp output07 để in theo thứ tự RLN:
Lấy 22 ra khỏi output07 và in thông tin.
Lấy 20 ra khỏi output07 và in thông tin.
Lấy 15 ra khỏi output07 và in thông tin.
Lấy 7 ra khỏi output07 và in thông tin.
Lấy 3 ra khỏi output07 và in thông tin.
Lấy 5 ra khỏi output07 và in thông tin.
Lấy 10 ra khỏi output07 và in thông tin.
GitHub Copilot
Chắc chắn rồi! Dưới đây là ví dụ minh họa từng bước của hàm khuDeQuy_RLN để duyệt cây theo thứ tự RLN (Right-Left-Node, hậu tố) không đệ quy cho cây nhị phân sau:

Mã nguồn hàm khuDeQuy_RLN
Quá trình duyệt cây theo thứ tự RLN không đệ quy
Bắt đầu tại gốc cây (10):
Đẩy 10 vào stackNode07.
Lấy 10 ra khỏi stackNode07 và đẩy vào output07:
Đẩy 15 vào stackNode07.
Đẩy 5 vào stackNode07.
Lấy 5 ra khỏi stackNode07 và đẩy vào output07:
Đẩy 7 vào stackNode07.
Đẩy 3 vào stackNode07.
Lấy 3 ra khỏi stackNode07 và đẩy vào output07:
3 không có con, tiếp tục.
Lấy 7 ra khỏi stackNode07 và đẩy vào output07:
7 không có con, tiếp tục.
Lấy 15 ra khỏi stackNode07 và đẩy vào output07:
Đẩy 22 vào stackNode07.
Đẩy 20 vào stackNode07.
Lấy 20 ra khỏi stackNode07 và đẩy vào output07:
20 không có con, tiếp tục.
Lấy 22 ra khỏi stackNode07 và đẩy vào output07:
22 không có con, tiếp tục.
Duyệt ngăn xếp output07 để in theo thứ tự RLN:
Lấy 22 ra khỏi output07 và in thông tin.
Lấy 20 ra khỏi output07 và in thông tin.
Lấy 15 ra khỏi output07 và in thông tin.
Lấy 7 ra khỏi output07 và in thông tin.
Lấy 3 ra khỏi output07 và in thông tin.
Lấy 5 ra khỏi output07 và in thông tin.
Lấy 10 ra khỏi output07 và in thông tin.
Kết quả cuối cùng: 22 20 15 7 3 5 10
*/
void duyetCayRLN(Node_CIT07* node_07) {
    if (node_07 == nullptr)
        return;

    // Duyệt cây con bên phải
    duyetCayRLN(node_07->right_CIT07);

    // Duyệt cây con bên trái
    duyetCayRLN(node_07->left_CIT07);

    // Xử lý thông tin của node hiện tại
    inThongTinSach_07(node_07);
}
void khuDeQuy_RLN(Node_CIT07 *node_07)
{
     if (node_07 == nullptr)
        return;

    stack<Node_CIT07*> stackNode07; // Ngăn xếp để lưu các node
    stack<Node_CIT07*> output07;   // Ngăn xếp trung gian để đảm bảo thứ tự RLN

    // Đẩy root vào ngăn xếp đầu tiên
    stackNode07.push(node_07);

    while (!stackNode07.empty()) {
        // Lấy phần tử trên cùng của ngăn xếp
        Node_CIT07* current = stackNode07.top();
        stackNode07.pop();

        // Đưa node hiện tại vào ngăn xếp output07
        output07.push(current);

        // Đẩy vào sau -> duyệt trước
        if (current->right_CIT07 != nullptr)
            stackNode07.push(current->right_CIT07);

        // Đẩy các node con vào ngăn xếp để duyệt
        if (current->left_CIT07 != nullptr)
            stackNode07.push(current->left_CIT07);  
        
    }

    // Duyệt ngăn xếp output07 để in theo thứ tự RLN
    while (!output07.empty()) {
        inThongTinSach_07(output07.top());
        output07.pop();
    }
    
}


/*
6.5 Duyệt cây theo thứ tự LNR (trung tố) không đệ quy
         10
       /    \
      5      15
     / \    /  \
    3   7  20   22
Quá trình duyệt cây theo thứ tự LNR không đệ quy
Bắt đầu tại gốc cây (10):
Đẩy 10 vào stack.
Di chuyển đến cây con trái của 10 (5).
Stack: [10]
Current: 5

Duyệt cây con trái của 10 (5):
Đẩy 5 vào stack.
Di chuyển đến cây con trái của 5 (3).
Stack: [10, 5]
Current: 3

Duyệt cây con trái của 5 (3):
Đẩy 3 vào stack.
3 không có con trái, lấy 3 ra khỏi stack và in thông tin.
Stack: [10, 5]
Output: 3
Current: nullptr

Trở lại nút 5:
Lấy 5 ra khỏi stack và in thông tin.
Di chuyển đến cây con phải của 5 (7).
Stack: [10]
Output: 3 5
Current: 7

Duyệt cây con phải của 5 (7):
Đẩy 7 vào stack.
7 không có con trái, lấy 7 ra khỏi stack và in thông tin.
Stack: [10]
Output: 3 5 7
Current: nullptr

Trở lại nút 10:
Lấy 10 ra khỏi stack và in thông tin.
Di chuyển đến cây con phải của 10 (15).
Stack: []
Output: 3 5 7 10
Current: 15

Duyệt cây con phải của 10 (15):
Đẩy 15 vào stack.
Di chuyển đến cây con trái của 15 (20).
Stack: [15]
Current: 20

Duyệt cây con trái của 15 (20):
Đẩy 20 vào stack.
20 không có con trái, lấy 20 ra khỏi stack và in thông tin.
Stack: [15]
Output: 3 5 7 10 20
Current: nullptr

Trở lại nút 15:
Lấy 15 ra khỏi stack và in thông tin.
Di chuyển đến cây con phải của 15 (22).
Stack: []
Output: 3 5 7 10 20 15
Current: 22

Duyệt cây con phải của 15 (22):
Đẩy 22 vào stack.
22 không có con trái, lấy 22 ra khỏi stack và in thông tin.
Stack: []
Output: 3 5 7 10 20 15 22
Current: nullptr
Kết quả cuối cùng là: 3 5 7 10 20 15 22
*/
void duyetCayLNR(Node_CIT07 *node_07)
{
    if (node_07 == nullptr)
    {
        return;
    }
    duyetCayLNR(node_07->left_CIT07);
    inThongTinSach_07(node_07);
    duyetCayLNR(node_07->right_CIT07);
}
void khuDeQuy_LNR(Node_CIT07 *root)
{
    stack<Node_CIT07 *> s;
    Node_CIT07 *current = root;

    while (current != nullptr || !s.empty())
    {
        while (current != nullptr)
        {
            s.push(current);
            current = current->left_CIT07;
        }

        current = s.top();
        s.pop();

        inThongTinSach_07(current);

        current = current->right_CIT07;
    }
}


/*
6.6 Left - Right - Node (LRN) (hậu tố)
         10
       /    \
      5      15
     / \    /  \
    3   7  20   22

3, 7, 5, 20, 22, 15, 10
Quá trình duyệt cây theo thứ tự LRN không đệ quy
Bắt đầu tại gốc cây (10):
Đẩy 10 vào stackNode07.
StackNode07: [10]
Output07: []

Lấy 10 ra khỏi stackNode07 và đẩy vào output07:
Đẩy 5 vào stackNode07.
Đẩy 15 vào stackNode07.
StackNode07: [5, 15]
Output07: [10]

Lấy 15 ra khỏi stackNode07 và đẩy vào output07:
Đẩy 20 vào stackNode07.
Đẩy 22 vào stackNode07.
StackNode07: [5, 20, 22]
Output07: [10, 15]

Lấy 22 ra khỏi stackNode07 và đẩy vào output07:
22 không có con, tiếp tục.
StackNode07: [5, 20]
Output07: [10, 15, 22]

Lấy 20 ra khỏi stackNode07 và đẩy vào output07:
20 không có con, tiếp tục.
StackNode07: [5]
Output07: [10, 15, 22, 20]

Lấy 5 ra khỏi stackNode07 và đẩy vào output07:
Đẩy 3 vào stackNode07.
Đẩy 7 vào stackNode07.
StackNode07: [3, 7]
Output07: [10, 15, 22, 20, 5]

Lấy 7 ra khỏi stackNode07 và đẩy vào output07:
7 không có con, tiếp tục.
StackNode07: [3]
Output07: [10, 15, 22, 20, 5, 7]

Lấy 3 ra khỏi stackNode07 và đẩy vào output07:
3 không có con, tiếp tục.
StackNode07: []
Output07: [10, 15, 22, 20, 5, 7, 3]
Duyệt ngăn xếp output07 để in theo thứ tự LRN:
Lấy 3 ra khỏi output07 và in thông tin.
Lấy 7 ra khỏi output07 và in thông tin.
Lấy 5 ra khỏi output07 và in thông tin.
Lấy 20 ra khỏi output07 và in thông tin.
Lấy 22 ra khỏi output07 và in thông tin.
Lấy 15 ra khỏi output07 và in thông tin.
Lấy 10 ra khỏi output07 và in thông tin
Kết quả cuối cùng: 3 7 5 20 22 15 10

*/
void duyetCayLRN(Node_CIT07 *node_07)
{
    if (node_07 == nullptr)
    {
        return;
    }
    duyetCayLRN(node_07->left_CIT07);
    duyetCayLRN(node_07->right_CIT07);
    inThongTinSach_07(node_07);
}
void khuDeQuy_LRN(Node_CIT07 *node_07)
{
     if (node_07 == nullptr)
        return;

    stack<Node_CIT07*> stackNode07; // Ngăn xếp để lưu các node
    stack<Node_CIT07*> output07;   // Ngăn xếp trung gian để đảm bảo thứ tự RLN

    // Đẩy root vào ngăn xếp đầu tiên
    stackNode07.push(node_07);

    while (!stackNode07.empty()) {
        // Lấy phần tử trên cùng của ngăn xếp
        Node_CIT07* current = stackNode07.top();
        stackNode07.pop();

        // Đưa node hiện tại vào ngăn xếp output07
        output07.push(current);

        // Đẩy các node con vào ngăn xếp để duyệt
        if (current->left_CIT07 != nullptr)
            stackNode07.push(current->left_CIT07);
            
        // Đẩy vào sau -> duyệt trước
        if (current->right_CIT07 != nullptr)
            stackNode07.push(current->right_CIT07);
    }

    // Duyệt ngăn xếp output07 để in theo thứ tự RLN
    while (!output07.empty()) {
        inThongTinSach_07(output07.top());
        output07.pop();
    }
}

void XuatSach_07()
{

    cout << "1.Duyệt cây NLR\n";
    cout << "2.Duyệt cây NRL\n";
    cout << "3.Duyệt cây RNL\n";
    cout << "4.Duyệt cây RLN\n";
    cout << "5.Duyệt cây LNR\n";
    cout << "6.Duyệt cây LRN\n";
    int choose;
    cout << "Nhập lựa chọn: ";
    cin >> choose;
    switch (choose)
    {
    case 1:
        // duyetCayNLR(root_CIT07);
        khuDeQuy_NLR(root_CIT07);
        break;
    case 2:
        // duyetCayNRL(root_CIT07);
        khuDeQuy_NRL(root_CIT07);
        break;
    case 3:
        // duyetCayRNL(root_CIT07);
        khuDeQuy_RNL(root_CIT07);
        break;
    case 4:
        // duyetCayRLN(root_CIT07);
        khuDeQuy_RLN(root_CIT07);
        break;
    case 5:
        // duyetCayLNR(root_CIT07);
        khuDeQuy_LNR(root_CIT07);
        break;
    case 6:
        // duyetCayLRN(root_CIT07);
        khuDeQuy_LRN(root_CIT07);
        break;
    default:
        break;
    }
}

/*
         10
       /    \
      5      15
     / \    /  \
    3   7  22   20
*/

void ThemDuLieuMau_07()
{
    root_CIT07 = new Node_CIT07({"CTDL & GT", "10", "Engineer", 10});
    root_CIT07->left_CIT07 = new Node_CIT07({"OOP", "5", "Tech", 5});
    root_CIT07->right_CIT07 = new Node_CIT07({"Python", "15", "IT", 7});
    root_CIT07->left_CIT07->left_CIT07 = new Node_CIT07({"Computer Architecture", "3", "IT", 3});
    root_CIT07->left_CIT07->right_CIT07 = new Node_CIT07({"Basic Network", "7", "Net", 12});
    root_CIT07->right_CIT07->left_CIT07 = new Node_CIT07({"CA", "20", "WW", 32});
    root_CIT07->right_CIT07->right_CIT07 = new Node_CIT07({"DSA", "22", "WW", 82});
    soPhanTu_CIT07 = 7;
    cout << "Đã thêm dữ liệu mẫu thành công!\n";
}

/********************************************/
/**CHƯƠNG TRÌNH CHÍNH VÀ MENU ĐIỀU KHIỂN ****/
/********************************************/

int main()
{
    KhoiTao_CIT07();
    char LuaChon;

    while (true)
    {
        cout << "____________________________________________\n";
        cout << "CHƯƠNG TRÌNH QUẢN LÝ THƯ VIỆN [CÂY NHỊ PHÂN]\n";
        cout << "1. Thêm sách\n";
        cout << "2. Cập nhật thông tin sách\n";
        cout << "3. Xóa sách\n";
        cout << "4. Tìm sách theo tên\n";
        cout << "5. Xuất danh sách sách\n";
        cout << "6. Xuất danh sách cùng loại sách\n";
        cout << "7. Thêm dữ liệu mẫu\n";
        cout << "8. Số sách hiện có \n";
        cout << "9. Kiểm tra cây rỗng\n";
        cout << "e. Thoát\n";
        cout << "____________________________________________\n";
        cout << "Nhập lựa chọn: ";

        cin >> LuaChon;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Xóa bộ đệm

        switch (LuaChon)
        {
        case '1':
            NhapCay_07();
            break;
        case '2':
            CapNhatThuocTinh_07();
            break;
        case '3':
            XoaPhanTuTheoMaSach_07();
            break;
        case '4':
            TimSachTheoTen_07();
            break;
        case '5':
            XuatSach_07();
            break;
        case '6':
            DanhSachCungLoai_07();
            break;
        case '7':
            ThemDuLieuMau_07();
            break;
        case '8':
            cout << "Số sách hiện có: " << soPhanTu_CIT07 << endl;
            break;
        case '9':
            if (KiemTraCayRong_CIT07())
            {
                cout << "Cây rỗng.\n";
            }
            else
            {
                cout << "Cây không rỗng.\n";
            }
            break;
        case 'e':
            cout << "Thoát khỏi chương trình.\n";
            return 0;
        default:
            cout << "Lựa chọn không hợp lệ! Vui lòng thử lại.\n";
        }
    }
}
