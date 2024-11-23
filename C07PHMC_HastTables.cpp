using namespace std;
#include <iostream>
#include <string>
#include <vector>

// Define the book structure
struct BKPHMC_CIT07
{
    string Ma_Sach_CIT07;
    string Ten_Sach_CIT07;
    string Loai_Sach_CIT07;
    int So_Lan_Muon_Sach_CIT07;
};

/*********************************/
/** KHAI BÁO BẢNG BĂM [HASH TABLE] **/
/*********************************/

const int TABLE_SIZE = 100;

// Cấu trúc cho một node trong chain
struct HashNode
{
    BKPHMC_CIT07 data;
    HashNode *next;

    HashNode(BKPHMC_CIT07 book) : data(book), next(nullptr) {}
};

// Cấu trúc bảng băm
class HashTable07
{
private:
    HashNode *table[TABLE_SIZE];
    int size;

    // Hàm băm
    int hashFunction(string key)
    {
        int hash = 0;
        for (char c : key)
        {
            hash = (hash * 31 + c) % TABLE_SIZE;
        }
        return hash;
    }

public:
    HashTable07()
    {
        for (int i = 0; i < TABLE_SIZE; i++)
        {
            table[i] = nullptr;
        }
        size = 0;
    }

    // Thêm sách vào bảng băm
    void insert07(BKPHMC_CIT07 book)
    {
        int index = hashFunction(book.Ma_Sach_CIT07);
        HashNode *newNode = new HashNode(book);

        if (table[index] == nullptr)
        {
            table[index] = newNode;
        }
        else
        {
            newNode->next = table[index];
            table[index] = newNode;
        }
        size++;
    }

    // Xóa sách theo mã
    bool remove07(string maSach)
    {
        int index = hashFunction(maSach);
        HashNode *current = table[index];
        HashNode *prev = nullptr;

        while (current != nullptr)
        {
            if (current->data.Ma_Sach_CIT07 == maSach)
            {
                if (prev == nullptr)
                {
                    table[index] = current->next;
                }
                else
                {
                    prev->next = current->next;
                }
                delete current;
                size--;
                return true;
            }
            prev = current;
            current = current->next;
        }
        return false;
    }

    // Cập nhật thông tin sách
    void update07(string maSach)
    {
        int index = hashFunction(maSach);
        HashNode *current = table[index];

        while (current != nullptr)
        {
            if (current->data.Ma_Sach_CIT07 == maSach)
            {
                while (true)
                {
                    char choice;
                    cout << "\nCHỌN THUỘC TÍNH ĐỂ SỬA: \n";
                    cout << "1. Tên sách\n";
                    cout << "2. Loại sách\n";
                    cout << "3. Số lần mượn sách\n";
                    cout << "e. Thoát\n";
                    cout << "Nhập lựa chọn của bạn: ";
                    cin >> choice;

                    switch (choice)
                    {
                    case '1':
                        cout << "Nhập tên mới: ";
                        cin.ignore();
                        getline(cin, current->data.Ten_Sach_CIT07);
                        break;
                    case '2':
                        cout << "Nhập loại mới: ";
                        cin.ignore();
                        getline(cin, current->data.Loai_Sach_CIT07);
                        break;
                    case '3':
                        cout << "Nhập số lần mượn mới: ";
                        cin >> current->data.So_Lan_Muon_Sach_CIT07;
                        break;
                    case 'e':
                        return;
                    default:
                        cout << "Lựa chọn không hợp lệ!\n";
                    }
                }
            }
            current = current->next;
        }
        cout << "Không tìm thấy sách!\n";
    }

    // In danh sách sách
    void display07()
    {
        for (int i = 0; i < TABLE_SIZE; i++)
        {
            HashNode *current = table[i];
            while (current != nullptr)
            {
                cout << "___________________________________________________\n";
                cout << "Mã sách: " << current->data.Ma_Sach_CIT07 << endl;
                cout << "Tên sách: " << current->data.Ten_Sach_CIT07 << endl;
                cout << "Loại sách: " << current->data.Loai_Sach_CIT07 << endl;
                cout << "Số lần mượn sách: " << current->data.So_Lan_Muon_Sach_CIT07 << endl;
                cout << "___________________________________________________\n";
                current = current->next;
            }
        }
    }

    // Thêm dữ liệu mẫu
    void addSampleData07(HashTable07 &hashTable07)
    {
        BKPHMC_CIT07 book1 = {"B001", "Lập trình C++", "Giáo trình", 5};
        BKPHMC_CIT07 book2 = {"B002", "Cấu trúc dữ liệu", "Giáo trình", 8};
        BKPHMC_CIT07 book3 = {"B003", "Java cơ bản", "Sách tham khảo", 3};
        BKPHMC_CIT07 book4 = {"B004", "Python cho người mới bắt đầu", "Sách tham khảo", 6};
        BKPHMC_CIT07 book5 = {"B005", "Mạng máy tính", "Giáo trình", 4};

        hashTable07.insert07(book1);
        hashTable07.insert07(book2);
        hashTable07.insert07(book3);
        hashTable07.insert07(book4);
        hashTable07.insert07(book5);
    }

    // Hủy bảng băm
    ~HashTable07()
    {
        for (int i = 0; i < TABLE_SIZE; i++)
        {
            HashNode *current = table[i];
            while (current != nullptr)
            {
                HashNode *temp = current;
                current = current->next;
                delete temp;
            }
        }
    }
};

int main()
{
    HashTable07 hashTable07;
    char choice;

    do
    {
        cout << "\n=== QUẢN LÝ SÁCH [HAST TABLE] ===" << endl;
        cout << "1. Thêm sách mới" << endl;
        cout << "2. Xóa sách" << endl;
        cout << "3. Cập nhật thông tin sách" << endl;
        cout << "4. Hiển thị danh sách sách" << endl;
        cout << "5. Thêm dữ liệu mẫu" << endl;
        cout << "0. Thoát" << endl;
        cout << "Nhập lựa chọn của bạn: ";
        cin >> choice;

        switch (choice)
        {
        case '1':
        {
            BKPHMC_CIT07 book;
            cout << "Nhập mã sách: ";
            cin.ignore();
            getline(cin, book.Ma_Sach_CIT07);
            cout << "Nhập tên sách: ";
            getline(cin, book.Ten_Sach_CIT07);
            cout << "Nhập loại sách: ";
            getline(cin, book.Loai_Sach_CIT07);
            cout << "Nhập số lần mượn sách: ";
            cin >> book.So_Lan_Muon_Sach_CIT07;
            hashTable07.insert07(book);
            break;
        }
        case '2':
        {
            string maSach;
            cout << "Nhập mã sách cần xóa: ";
            cin.ignore();
            getline(cin, maSach);
            if (hashTable07.remove07(maSach))
            {
                cout << "Đã xóa sách thành công!" << endl;
            }
            else
            {
                cout << "Không tìm thấy sách!" << endl;
            }
            break;
        }
        case '3':
        {
            string maSach;
            cout << "Nhập mã sách cần cập nhật: ";
            cin.ignore();
            getline(cin, maSach);
            hashTable07.update07(maSach);
            break;
        }
        case '4':
            hashTable07.display07();
            break;
        case '5':
            hashTable07.addSampleData07(hashTable07);
            cout << "Đã thêm dữ liệu mẫu thành công!" << endl;
            break;
        case '0':
            cout << "Tạm biệt!" << endl;
            break;
        default:
            cout << "Lựa chọn không hợp lệ!" << endl;
        }
    } while (choice != '0');

    return 0;
}
