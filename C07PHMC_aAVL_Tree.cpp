/*******************************/
/** KHAI BÁO THƯ VIỆN SỬ DỤNG **/
/*******************************/
using namespace std;
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>

/*********************************/
/** KHAI BÁO CÂY CÂN BẰNG [AVL] **/
/*********************************/

// Cấu trúc 1 quyển sách
struct BKPHMC_CIT07
{
    string Ten_Sach_CIT07;
    string Ma_Sach_CIT07;
    string Loai_Sach_CIT07;
    int So_Lan_Muon_Sach_CIT07;
};

// Cấu trúc 1 nút
struct Node_CIT07
{
    BKPHMC_CIT07 data_CIT07; // Dữ liệu của nút
    Node_CIT07 *left_CIT07;
    Node_CIT07 *right_CIT07;
    int height_CIT07; // Chiều cao của nút

    // Constructor khởi tạo dữ liệu mới
    Node_CIT07(BKPHMC_CIT07 newData_CIT07)
    {
        data_CIT07 = newData_CIT07;
        left_CIT07 = nullptr;
        right_CIT07 = nullptr;
        height_CIT07 = 0;
    }
};

Node_CIT07 *root_CIT07 = nullptr; // Gốc của cây
int soPhanTu_CIT07 = 0;           // Số phần tử trong cây

/*****************************************/
/** CÁC PHÉP THAO TÁC TRÊN CÂY CÂN BẰNG **/
/*****************************************/

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

// 3. Tính chiều cao của nút
int height_CIT07(Node_CIT07 *node07)
{
    if (node07 == nullptr)
        return 0;
    return 1 + max(height_CIT07(node07->left_CIT07), height_CIT07(node07->right_CIT07));
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

// 4. Tính độ cân bằng
int getBalance07(Node_CIT07 *N)
{
    if (N == nullptr)
        return 0;
    return height_CIT07(N->left_CIT07) - height_CIT07(N->right_CIT07);
}

// 5. Xoay cây sang phải
Node_CIT07 *rightRotate(Node_CIT07 *root07)
{
    Node_CIT07 *nleft07 = root07->left_CIT07;
    Node_CIT07 *nright07 = nleft07->right_CIT07;

    nleft07->right_CIT07 = root07;
    root07->left_CIT07 = nright07;

    return nleft07;
}

// 6. Xoay cây sang trái
Node_CIT07 *leftRotate(Node_CIT07 *root07)
{
    Node_CIT07 *nright07 = root07->right_CIT07;
    Node_CIT07 *nleft07 = nright07->left_CIT07;

    nright07->left_CIT07 = root07;
    root07->right_CIT07 = nleft07;

    return nright07;
}

// 7. Tìm nút có giá trị nhỏ nhất
Node_CIT07 *minValueNode(Node_CIT07 *node)
{
    Node_CIT07 *current = node;
    while (current->left_CIT07 != nullptr)
        current = current->left_CIT07;
    return current;
}

/*****************************************/
/** CÁC PHÉP TOÁN TRÊN CÂY CÂN BẰNG **/
/*****************************************/
/*
    10
   /  \
  5    20
   \
    7
    /
    6
Bước 1: Tính toán Hệ số Cân bằng (Balance Factor)
Tính hệ số cân bằng của node gốc (10).
Hệ số cân bằng = chiều cao cây con trái - chiều cao cây con phải.
Hệ số cân bằng của 10 = 2 (chiều cao cây con trái) - 1 (chiều cao cây con phải) = 1.
Vì hệ số cân bằng > 1, cây bị lệch trái.

Bước 2: Kiểm tra trường hợp Left-Right
Kiểm tra xem cây con trái của node 10 có bị lệch phải không.
Hệ số cân bằng của node 5 = chiều cao cây con trái - chiều cao cây con phải.
Hệ số cân bằng của 5 = 0 (chiều cao cây con trái) - 2 (chiều cao cây con phải) = -2.
Vì hệ số cân bằng của 5 < 0, đây là trường hợp Left-Right (Lệch Trái - Phải).

Bước 3: Thực hiện xoay trái tại node 5
Thực hiện một phép xoay trái tại node 5.

Cây sau khi xoay trái tại node 5 sẽ trở thành:
      10
     /  \
    7    20
   /
  5
   \
    6


Bước 4: Thực hiện xoay phải tại node 10
Thực hiện một phép xoay phải tại node gốc (10).

Sau khi xoay phải tại node 10, cây sẽ trở thành:
      7
     /  \
    5    10
     \     \
      6    20

Step 5: Cập nhật chiều cao:.
chiều cao node 5 = 1 + max(0, 1) = 2.
chiều cao node 10 = 1 + max(0, 1) = 2.
chiều cao node 7 = 1 + max(2, 2) = 3.
Cây cuối cùng sau khi cân bằng:
      7
     /  \
    5    10
     \     \
      6    20
*/
// 8. Thao tác cân bằng cây
void balance07(Node_CIT07 *&node)
{
    int b = getBalance07(node);
    if (b > 1)
    {
        if (getBalance07(node->left_CIT07) < 0)
        {
            node->left_CIT07 = leftRotate(node->left_CIT07);
        }
        node = rightRotate(node);
    }
    else if (b < -1)
    {
        if (getBalance07(node->right_CIT07) > 0)
        {
            node->right_CIT07 = rightRotate(node->right_CIT07);
        }
        node = leftRotate(node);
    }

    // Cập nhật lại chiều cao của node sau khi cân bằng
    node->height_CIT07 = 1 + max(height_CIT07(node->left_CIT07), height_CIT07(node->right_CIT07));
}

// 9. Thêm một nút mới
/*

Khởi tạo:
          30
         /  \
       20    40
Bước 1: Thêm nút với giá trị 10
Gọi hàm insert07 với nút gốc là 30 và giá trị mới là 10:

Vì 10 nhỏ hơn 30, di chuyển sang cây con bên trái.
Gọi insert07 với nút 20 và giá trị mới là 10:
Vì 10 nhỏ hơn 20, di chuyển sang cây con bên trái.
Gọi insert07 với nullptr (cây con trái của 20) và giá trị mới là 10:
Tạo một nút mới với giá trị 10 và trả về nút này
      30
     /  \
   20    40
  /
10

Bước 2: Cập nhật chiều cao
Cập nhật chiều cao của nút 20:
Chiều cao của 20 = 1 + max(chiều cao của 10, chiều cao của nullptr) = 1 + max(1, 0) = 2.

Cập nhật chiều cao của nút 30:
Chiều cao của 30 = 1 + max(chiều cao của 20, chiều cao của 40) = 1 + max(2, 1) = 3.

Bước 3: Cân bằng cây
Tính hệ số cân bằng của nút 30:
Hệ số cân bằng của 30 = chiều cao cây con trái - chiều cao cây con phải = 2 - 1 = 1.
Vì hệ số cân bằng nằm trong khoảng [-1, 1], không cần xoay.

Bước 4: Chèn nút có giá trị 25
Gọi insert07 với nút gốc 30 và giá trị mới 25:

Vì 25 nhỏ hơn 30, di chuyển sang cây con trái.
Gọi insert07 với nút 20 và giá trị mới 25:

Vì 25 lớn hơn 20, di chuyển sang cây con phải.
Gọi insert07 với nullptr (con phải của 20) và giá trị mới 25:

Tạo nút mới với giá trị 25 và trả về nút này.
Cây sau khi chèn 25:
      30
     /  \
   20    40
  /  \
10   25

Bước 5: Cập nhật chiều cao
Cập nhật chiều cao của nút 20:
Chiều cao của 20 = 1 + max(chiều cao của 10, chiều cao của 25) = 1 + max(1, 1) = 2.

Cập nhật chiều cao của nút 30:
Chiều cao của 30 = 1 + max(chiều cao của 20, chiều cao của 40) = 1 + max(2, 1) = 3.

Bước 6: Cân bằng cây
Tính hệ số cân bằng của nút 30:
Hệ số cân bằng của 30 = chiều cao cây con trái - chiều cao cây con phải = 2 - 1 = 1.
Vì hệ số cân bằng nằm trong khoảng [-1, 1], không cần xoay.

Cây cân bằng cuối cùng:
      30
     /  \
   20    40
  /  \
10   25

*/
Node_CIT07 *insert07(Node_CIT07 *node, const BKPHMC_CIT07 &sach07)
{
    // THÊM NODE
    if (node == nullptr)
    {
        soPhanTu_CIT07++; // Tăng số phần tử trong cây
        return new Node_CIT07(sach07);
    }
    else if (sach07.Ma_Sach_CIT07 < node->data_CIT07.Ma_Sach_CIT07)
    {
        node->left_CIT07 = insert07(node->left_CIT07, sach07);
    }
    else
    {
        node->right_CIT07 = insert07(node->right_CIT07, sach07);
    }

    // Cập nhật chiều cao của nút hiện tại
    node->height_CIT07 = 1 + max(height_CIT07(node->left_CIT07), height_CIT07(node->right_CIT07));

    // CÂN BẰNG CÂY
    balance07(node);

    return node;
}

// 10. Xóa một nút theo mã sách
// AVL
//     10
//    /  \
//   5    20
//  / \   / \
// 3   7 15  22
// 10 5 3 7 20 15 22 - NLR

// sau khi xóa node 20
// AVL
//     10
//    /  \
//   5    22
//  / \   / \
// 3   7 15  null
// 10 5 3 7 22 15 - NLR

/*
Cây ban đầu
    30
     /  \
   20    40
  /  \
10   25

Bước 1: Xóa Node có khóa 20
Gọi deleteNode07 với node gốc 30 và khóa 20:

Vì 20 nhỏ hơn 30, di chuyển sang cây con bên trái.
Gọi deleteNode07 với node 20 và khóa 20:

Đã tìm thấy Node 20.
Node 20 có hai node con:

Tìm node có giá trị nhỏ nhất trong cây con phải của 20 (là 25).
Thay thế giá trị của node 20 bằng 25:

Tiếp theo, xóa node 25.
Gọi deleteNode07 với node 25 và khóa 25:

Đã tìm thấy Node 25 và không có node con.
Xóa node 25.

Cây sau khi xóa 20 và thay thế bằng 25
    30
     /  \
   25    40
  /
10

Bước 2: Cập nhật chiều cao
Cập nhật chiều cao của node 25:
Chiều cao của 25 = 1 + max(chiều cao của 10, chiều cao của nullptr) = 1 + max(1, 0) = 2.

Cập nhật chiều cao của node 30:
Chiều cao của 30 = 1 + max(chiều cao của 25, chiều cao của 40) = 1 + max(2, 1) = 3.

Bước 3: Cân bằng cây
Tính hệ số cân bằng của node 30:
Hệ số cân bằng của 30 = chiều cao cây con trái - chiều cao cây con phải = 2 - 1 = 1.
Vì hệ số cân bằng nằm trong khoảng [-1, 1], không cần xoay.

Cây cân bằng cuối cùng
    30
     /  \
   25    40
  /
10

Sơ đồ minh họa
Cây ban đầu:
    30
     /  \
   20    40
  /  \
10   25

Sau khi xóa 20 và thay thế bằng 25:
    30
     /  \
   25    40
  /
10

Minh họa từng bước này cho thấy cách hàm deleteNode07 xóa một node khỏi cây AVL và duy trì cân bằng thông qua các phép xoay và cập nhật chiều cao.
*/
Node_CIT07 *deleteNode07(Node_CIT07 *root, string Ma_Sach_CIT07)
{
    if (root == nullptr)
        return root;

    // Tìm nút cần xóa
    if (Ma_Sach_CIT07 < root->data_CIT07.Ma_Sach_CIT07)
        root->left_CIT07 = deleteNode07(root->left_CIT07, Ma_Sach_CIT07);
    else if (Ma_Sach_CIT07 > root->data_CIT07.Ma_Sach_CIT07)
        root->right_CIT07 = deleteNode07(root->right_CIT07, Ma_Sach_CIT07);
    else
    {
        if ((root->left_CIT07 == nullptr) || (root->right_CIT07 == nullptr))
        {
            Node_CIT07 *temp = root->left_CIT07 ? root->left_CIT07 : root->right_CIT07;
            delete root;
            return temp;
        }

        Node_CIT07 *temp = minValueNode(root->right_CIT07);
        root->data_CIT07 = temp->data_CIT07;
        root->right_CIT07 = deleteNode07(root->right_CIT07, temp->data_CIT07.Ma_Sach_CIT07);
    }

    root->height_CIT07 = 1 + max(height_CIT07(root->left_CIT07), height_CIT07(root->right_CIT07));

    // CÂN BẰNG CÂY
    balance07(root);

    return root;
}

// 11. Xoá tất cả các node trên cây
void DeleteAllAVLNodes07(Node_CIT07 *root)
{
    if (root)
    {
        DeleteAllAVLNodes07(root->left_CIT07);
        DeleteAllAVLNodes07(root->right_CIT07);
        delete root;
    }
}

// 12. cập nhật thuộc tính cho phần tử (Update)
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
                cout << "Nhập loại sách mới: ";
                cin.ignore();
                getline(cin, newType);
                node->data_CIT07.Loai_Sach_CIT07 = newType;
                cout << "Đã cập nhật thông tin sách thành công!" << endl;
                break;
            }
            case '3':
            {
                int newCount;
                cout << "Nhập số lần mượn sách mới: ";
                cin >> newCount;
                node->data_CIT07.So_Lan_Muon_Sach_CIT07 = newCount;
                cout << "Đã cập nhật thông tin sách thành công!" << endl;
                break;
            }
            case 'e':
                return;
            default:
                cout << "Lựa chọn không hợp lệ!" << endl;
                break;
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

/***************************************************/
// CÁC HÀM THỰC NGHIỆM TRÊN CÂY CÂN BẰNG [AVL]: SÁCH
/***************************************************/

// Hàm in thông tin sách
void inThongTinSach07(Node_CIT07 *node07)
{
    cout << "___________________________________________________\n";
    cout << "Mã sách: " << node07->data_CIT07.Ma_Sach_CIT07 << endl;
    cout << "Tên sách: " << node07->data_CIT07.Ten_Sach_CIT07 << endl;
    cout << "Loại sách: " << node07->data_CIT07.Loai_Sach_CIT07 << endl;
    cout << "Số lần mượn sách: " << node07->data_CIT07.So_Lan_Muon_Sach_CIT07 << endl;
    cout << "Chiều cao: " << node07->height_CIT07 << endl;
    cout << "___________________________________________________\n";
}

// Duyệt cây theo thứ tự : 10 5 15 3 7 20 22
// BST
//     10
//    /  \
//   5    15
//  / \   / \
// 3   7     20
//             \ 
//              22
// AVL
//     10
//    /  \
//   5    20
//  / \   / \
// 3   7 15  22
// 10 5 3 7 20 15 22 - NLR
void inThongTinSach_07(Node_CIT07 *root07)
{
    if (root07 == nullptr)
        return;

    // Sử dụng stack để duyệt cây theo NLR
    stack<Node_CIT07 *> s;
    s.push(root07);

    while (!s.empty())
    {
        Node_CIT07 *node = s.top(); // Lấy node đầu tiên trong stack
        s.pop();

        inThongTinSach07(node); // In thông tin node

        // Thêm node con phải vào stack trước để duyệt sau
        if (node->right_CIT07 != nullptr)
            s.push(node->right_CIT07);

        // Thêm node con trái vào stack sau để duyệt trước
        if (node->left_CIT07 != nullptr)
            s.push(node->left_CIT07);
    }
}

// Nhập nội dung phần tử
void NhapNoiDungPhanTu_CIT07(BKPHMC_CIT07 &books_CIT07)
{
    cout << "Nhập mã sách: ";
    cin >> books_CIT07.Ma_Sach_CIT07;
    cin.ignore();

    cout << "Nhập tên sách: ";
    getline(cin, books_CIT07.Ten_Sach_CIT07);

    cout << "Nhập loại sách: ";
    getline(cin, books_CIT07.Loai_Sach_CIT07);

    cout << "Nhập số lần mượn sách: ";
    cin >> books_CIT07.So_Lan_Muon_Sach_CIT07;
}

// Thêm sách vào cây
void ThemSach_CIT07()
{
    BKPHMC_CIT07 books_CIT07;
    NhapNoiDungPhanTu_CIT07(books_CIT07);
    root_CIT07 = insert07(root_CIT07, books_CIT07);
}

// In danh sách sách theo thứ tự NLR
void XuatDS_CIT07()
{
    if (root_CIT07 == nullptr)
    {
        cout << "Cây rỗng!" << endl;
        return;
    }
    inThongTinSach_07(root_CIT07);
}

// hàm thêm dữ liệu mẫu
void ThemDuLieuMau_CIT07()
{
    // Tạo mảng dữ liệu mẫu
    BKPHMC_CIT07 books[] = {
        {"CTDL & GT", "10", "Engineer", 10},
        {"OOP", "05", "Tech", 5},
        {"Python", "15", "IT", 7},
        {"Computer Architecture", "03", "IT", 3},
        {"Basic Network", "07", "Net", 12},
        {"CA", "20", "WW", 32},
        {"DSA", "22", "WW", 82}};

    // Duyệt mảng và thêm vào cây
    for (const auto &book : books)
    {
        root_CIT07 = insert07(root_CIT07, book); // Sử dụng hàm insert07 để thêm sách vào cây
    }
    soPhanTu_CIT07 = 7; // Cập nhật số lượng phần tử trong cây
    cout << "Đã thêm dữ liệu mẫu thành công!\n";
}

// Xóa phần tử theo mã sách
void XoaPhanTu_CIT07()
{
    string maSach;
    cout << "Nhập mã sách cần xóa: ";
    cin >> maSach;
    root_CIT07 = deleteNode07(root_CIT07, maSach);
    cout << "Đã xóa sách thành công!\n";
}

// Cập nhật thông tin sách
void CapNhatThuocTinh_CIT07()
{
    string maSach;
    cout << "Nhập mã sách cần cập nhật: ";
    cin >> maSach;
    CapNhatThuocTinh_CIT07(root_CIT07, maSach);
}
/*********************/
/** CHỨC NĂNG MENU **/
/*********************/

void menu_CIT07()
{
    cout << "\nQUẢN LÝ THƯ VIỆN" << endl;
    cout << "0. Thêm dữ liệu mẫu" << endl;
    cout << "1. Thêm sách" << endl;
    cout << "2. Xóa sách" << endl;
    cout << "3. Xuất danh sách sách" << endl;
    cout << "4. Cập nhật thông tin sách" << endl;
    cout << "5. Thoát" << endl;
}

int main()
{
    KhoiTao_CIT07();
    char choice;
    do
    {
        menu_CIT07();
        cout << "Chọn chức năng: ";
        cin >> choice;

        switch (choice)
        {
        case '0':
            ThemDuLieuMau_CIT07();
            break;
        case '1':
            ThemSach_CIT07();
            break;
        case '2':
            XoaPhanTu_CIT07();
            break;
        case '3':
            XuatDS_CIT07();
            break;
        case '4':
            CapNhatThuocTinh_CIT07();
            break;
        case '5':
            cout << "Thoát chương trình." << endl;
            break;
        default:
            cout << "Lựa chọn không hợp lệ!" << endl;
            break;
        }
    } while (choice != '5');

    DeleteAllAVLNodes07(root_CIT07); // Giải phóng bộ nhớ khi kết thúc chương trình
    return 0;
}
