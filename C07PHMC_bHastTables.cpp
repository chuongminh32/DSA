/*******************************/
/** KHAI BÁO THƯ VIỆN SỬ DỤNG **/
/*******************************/
using namespace std;
#include <iostream>
#include <string>
#include <vector>

/******************************************************************/
/** KHAI BÁO CẤU TRÚC DỮ LIỆU HAST TABLE DÙNG DANH SÁCH LIÊN KẾT **/
/******************************************************************/

// Định nghĩa cấu trúc sách
struct BKPHMC_CIT07
{
    string M07a_Sach_CIT07;
    string Ten_Sach_CIT07;
    string Loai_Sach_CIT07;
    int So_Lan_M07uon_Sach_CIT07;
};

// Cấu trúc cho m07ột node trong chain
struct HashNode07
{
    BKPHMC_CIT07 data07;
    HashNode07 *next;
    // Constructor
    HashNode07(BKPHMC_CIT07 book07) : data07(book07), next(nullptr) {}
};

#define M07 100
typedef HashNode07 *HashTable07[M07]; // Cấu trúc của Hash Table, mỗi phần tử là m07ột con trỏ đến m07ột danh sách liên kết

/****************************/
/** CÁC PHÉP TOÁN THAO TÁC **/
/****************************/

/***************************/
/** CÁC PHÉP TOÁN BAN ĐẦU **/
/***************************/

// 1. Khởi tạo Hash Table
void InitHashTable07(HashTable07 &HT07)
{
    for (int i = 0; i < M07; i++)
        HT07[i] = NULL;
}

// 2. Hàm băm: Tính chỉ số băm từ sô lần mượn sách
int Hash(int count07)
{
    return count07 % M07;
}

/*******************************************/
/** CÁC PHÉP TOÁN CƠ BẢN TRÊN MỘT PHẦN TỬ **/
/*******************************************/
// 3. Thêm vào cuối
void AddTail07(HashNode07 *&l07, BKPHMC_CIT07 &book07)
{
    // Tạo node mới từ sách
    HashNode07 *newNode = new HashNode07(book07);
    
    // Nếu danh sách l07 trống
    if (l07 == NULL)
    {
        l07 = newNode;
    }
    else
    {
        // Tìm đến cuối danh sách liên kết
        HashNode07 *p = l07;
        while (p->next != NULL)
            p = p->next;
        
        // Gắn node mới vào cuối
        p->next = newNode;
    }
}

// 4. Thêm phần tử mới
void InsertNode07(HashTable07 &HT, BKPHMC_CIT07 book07)
{
    int i = Hash(book07.So_Lan_M07uon_Sach_CIT07);
    AddTail07(HT[i], book07);
}

// 5. Tìm kiếm return hashtable node (count)
HashNode07 *SearchNode07(HashTable07 HT07, int count07)
{
    int i = Hash(count07);
    HashNode07 *p = HT07[i];
    while (p != NULL && p->data07.So_Lan_M07uon_Sach_CIT07 != count07)
        p = p->next;
    if (p == NULL)
        return NULL;
    return p;
}

// 6. Xóa đầu
void DeleteHead(HashNode07 *&l07)
{
    if (l07 != NULL)
    {
        HashNode07 *p = l07;
        l07 = l07->next;
        delete p;
    }
}

// 7. Xóa kế sau
void DeleteAfter(HashNode07 *&q07)
{
    HashNode07 *p07 = q07->next;
    if (p07 != NULL)
    {
        q07->next = p07->next;
        delete p07;
    }
}

// 8. Xóa
void DeleteNode07(HashTable07 &HT07,  int count07)
{
    int i = Hash(count07);
    HashNode07 *p = HT07[i];
    HashNode07 *q = p;
    while (p != NULL && p->data07.So_Lan_M07uon_Sach_CIT07 != count07)
    {
        q = p; // Luu dia chi phan tu ke truoc
        p = p->next;
    }
    if (p == NULL)
        cout << count07 << " -> không thấy!" << endl;
    else if (p == HT07[i])
        DeleteHead(HT07[i]); // Nút can xóa là phan tu dau DSLK
    else
        DeleteAfter(q); // Xóa nút sau nút q
}

// 9. In node
void Traverse(HashNode07 *p07) // duyệt DSLK
{
    while (p07 != NULL)
    {
        cout << "___________________________________________________\n";
        cout << "Mã sách: " << p07->data07.M07a_Sach_CIT07 << endl;
        cout << "Tên sách: " << p07->data07.Ten_Sach_CIT07 << endl;
        cout << "Loại sách: " << p07->data07.Loai_Sach_CIT07 << endl;
        cout << "Số lần mượn sách: " << p07->data07.So_Lan_M07uon_Sach_CIT07 << endl;
        cout << "___________________________________________________\n";
        p07 = p07->next;
    }
    cout << endl;
}


/******************************************************************/
/* CÁC HÀM THỰC NGHIỆM TRÊN CÁC PHÉP TOÁN CƠ BẢN TRÊN MỘT PHẦN TỬ */
/******************************************************************/
// hàm nhập thông tin sách
BKPHMC_CIT07 InputBook07()
{
    BKPHMC_CIT07 book;
    cout << "Nhập mã sách: ";
    cin >> book.M07a_Sach_CIT07;
    cout << "Nhập tên sách: ";
    cin.ignore();
    getline(cin, book.Ten_Sach_CIT07);
    cout << "Nhập loại sách: ";
    getline(cin, book.Loai_Sach_CIT07);
    cout << "Nhập số lần mượn sách: ";
    cin >> book.So_Lan_M07uon_Sach_CIT07;
    return book;
}

// [0] Hàm thêm dữ liệu mẫu
void addSampleData07(HashTable07 &HT07)
{
    BKPHMC_CIT07 book1 = {"B001", "Lập trình C++", "Giáo trình", 5};
    BKPHMC_CIT07 book2 = {"B002", "Cấu trúc dữ liệu", "Giáo trình", 8};
    BKPHMC_CIT07 book3 = {"B003", "Java cơ bản", "Sách tham khảo", 3};
    BKPHMC_CIT07 book4 = {"B004", "Python cho người mới bắt đầu", "Sách tham khảo", 6};
    BKPHMC_CIT07 book5 = {"B005", "Mạng máy tính", "Giáo trình", 4};

    InsertNode07(HT07, book1);
    InsertNode07(HT07, book2);
    InsertNode07(HT07, book3);
    InsertNode07(HT07, book4);
    InsertNode07(HT07, book5);

    cout << "Thêm dữ liệu mẫu thành công!\n";
}

// [1] Hàm thêm sách vào hash table
void InsertBook07(HashTable07 &HT)
{
    BKPHMC_CIT07 book07 = InputBook07();
    InsertNode07(HT, book07);
}

// [2] Hàm xóa sách theo số lần mượn sách
void DeleteBook07(HashTable07 &HT)
{
    int count07;
    cout << "Nhập sách có số lần mượn sách muốn xóa: ";
    cin >> count07;
    DeleteNode07(HT, count07);
}


//[3] Hàm tìm kiếm sách theo số lần mượn sách
void SearchBook07(HashTable07 HT)
{
    int count07;
    cout << "Nhập số lần mượn sách để search: ";
    cin >> count07;
    HashNode07 *result = SearchNode07(HT, count07);
    if (result == NULL)
        cout << "Không tìm thấy sách!\n";
    else
    {
        cout << "Đã tìm thấy sách:\n";
        cout << "Id: " << result->data07.M07a_Sach_CIT07 << endl;
        cout << "Tên sách: " << result->data07.Ten_Sach_CIT07 << endl;
        cout << "Loại sách: " << result->data07.Loai_Sach_CIT07 << endl;
        cout << "Số lần mượn sách: " << result->data07.So_Lan_M07uon_Sach_CIT07 << endl;
    }
}

// [4] In toàn bộ hash table
void TraverseHashTable07(HashTable07 HT)
{
    for (int i = 0; i < M07; i++)
    {
        cout << "Bucket " << i << ": ";
        Traverse(HT[i]);
    }
}


// Hàm hiển thị menu
void DisplayMenu07()
{
    cout << "____________________________________________\n";
    cout << "CHƯƠNG TRÌNH QUẢN LÝ THƯ VIỆN [HAST TABLE]\n";
    cout << "0. Thêm dữ liệu mẫu\n";
    cout << "1. Thêm sách\n";
    cout << "2. Xóa sách theo số lần mượn sách\n";
    cout << "3. Tìm sách\n";
    cout << "4. Hiển thị danh sách\n";
    cout << "5. Exit\n";
    cout << "____________________________________________\n";
    cout << "Nhập lựa chọn: ";
}

/*****************************************/
/* CHƯƠNG TRÌNH CHÍNH VÀ MENU ĐIỀU KHIỂN */
/*****************************************/

int main()
{
    HashTable07 m07HashTable;
    InitHashTable07(m07HashTable);

    int choice;
    do
    {
        DisplayMenu07();
        cin >> choice;
        switch (choice)
        {
        case 0:
            addSampleData07(m07HashTable);
            break;
        case 1:
            InsertBook07(m07HashTable);
            break;
        case 2:
            DeleteBook07(m07HashTable);
            break;
        case 3:
            SearchBook07(m07HashTable);
            break;
        case 4:
            TraverseHashTable07(m07HashTable);
            break;
        case 5:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Lựa chọn không hợp lệ! \n";
        }
    } while (choice != 5);

    return 0;
}
