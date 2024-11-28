#include <iostream>
#include <string>

using namespace std;

/******************************/
/**KHAI BAO DANH SACH LIEN KET QUEUE */
/******************************/

struct BKPHMC_CIT07 // Cấu trúc 1 quyển sách trong Hàng đợi thư viện
{
    string Ten_Sach_CIT07;      // Tên sách
    string Ma_Sach_CIT07;       // Mã sách
    string Loai_Sach_CIT07;     // Loại sách
    int So_Lan_Muon_Sach_CIT07; // Số lần mượn sách
    BKPHMC_CIT07* next;         // Con trỏ tới phần tử tiếp theo
};

struct Queue_CIT07
{
    BKPHMC_CIT07* front; // Con trỏ tới phần tử đầu tiên
    BKPHMC_CIT07* rear;  // Con trỏ tới phần tử cuối cùng
};

// 1. Khởi tạo
void KhoiTao_CIT07(Queue_CIT07 &queue)
{
    queue.front = nullptr;
    queue.rear = nullptr;
}

// 2. Kiểm tra rỗng
bool KiemTraRong_CIT07(Queue_CIT07 &queue)
{
    return (queue.front == nullptr);
}

// 3. Thêm phần tử mới vào cuối hàng đợi (Enqueue)
void Push_CIT07(Queue_CIT07 &queue, BKPHMC_CIT07* book_QUEUE_CIT07)
{
    if (queue.rear == nullptr)
    {
        queue.front = queue.rear = book_QUEUE_CIT07;
    }
    else
    {
        queue.rear->next = book_QUEUE_CIT07;
        queue.rear = book_QUEUE_CIT07;
    }
}

// 4. Lấy và Xóa phần tử ở đầu hàng đợi sách (Dequeue)
BKPHMC_CIT07* Pop_CIT07(Queue_CIT07 &queue)
{
    if (KiemTraRong_CIT07(queue))
    {
        cout << "Hàng đợi rỗng !" << endl;
        return nullptr;
    }
    else
    {
        BKPHMC_CIT07* temp = queue.front;
        queue.front = queue.front->next;
        if (queue.front == nullptr)
        {
            queue.rear = nullptr;
        }
        return temp;
    }
}

// 5. Xem phần tử ở đầu mà không xóa
BKPHMC_CIT07* layPTDau_CIT07(Queue_CIT07 &queue)
{
    if (KiemTraRong_CIT07(queue))
    {
        cout << "Hàng đợi rỗng !" << endl;
        return nullptr;
    }
    else
    {
        return queue.front;
    }
}

// 6. Truy cập phần tử cuối cùng (back())
BKPHMC_CIT07* layPTCuoi_CIT07(Queue_CIT07 &queue)
{
    if (KiemTraRong_CIT07(queue))
    {
        cout << "Hàng đợi rỗng !" << endl;
        return nullptr;
    }
    else
    {
        return queue.rear;
    }
}

// 7. In nội dung một phần tử
void InNoiDung_CIT07(BKPHMC_CIT07* book_CIT07)
{
    if (book_CIT07 != nullptr)
    {
        cout << "Mã sách: " << book_CIT07->Ma_Sach_CIT07 << "\n";
        cout << "Tên sách: " << book_CIT07->Ten_Sach_CIT07 << "\n";
        cout << "Loại sách: " << book_CIT07->Loai_Sach_CIT07 << "\n";
        cout << "Số lần mượn sách: " << book_CIT07->So_Lan_Muon_Sach_CIT07 << "\n";
        cout << "\n";
    }
}

// 8. Nhập nội dung một phần tử
void NhapNoiDungPT_CIT07(BKPHMC_CIT07* book_CIT07)
{
    cout << "Nhập mã sách: ";
    cin >> book_CIT07->Ma_Sach_CIT07;
    cin.ignore(); // Loại bỏ ký tự newline sau khi nhập mã sách

    cout << "Nhập tên sách: ";
    getline(cin, book_CIT07->Ten_Sach_CIT07); // Nhập cả dòng

    cout << "Nhập loại sách: ";
    getline(cin, book_CIT07->Loai_Sach_CIT07); // Nhập cả dòng

    cout << "Nhập số lần mượn sách: ";
    cin >> book_CIT07->So_Lan_Muon_Sach_CIT07;
    cout << endl;
    cin.ignore(); // Loại bỏ ký tự newline sau khi nhập số lần mượn sách

    book_CIT07->next = nullptr; // Khởi tạo con trỏ next là nullptr
}

// 9. Nạp nhiều phần tử vào QUEUE
void NapNhieuPT_QUEUE_CIT07(Queue_CIT07 &queue)
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
            BKPHMC_CIT07* books_QUEUE_CIT07 = new BKPHMC_CIT07; // Khai báo biến mới cho mỗi phần tử
            cout << "Nhập phần tử thứ " << i + 1 << ":" << endl;
            NhapNoiDungPT_CIT07(books_QUEUE_CIT07);
            Push_CIT07(queue, books_QUEUE_CIT07); // Gọi Push sau khi đã nhập dữ liệu
        }
    }
}

// 10. Nạp thêm một phần tử vào QUEUE
void Push_QUEUE_CIT07(Queue_CIT07 &queue)
{
    BKPHMC_CIT07* newBook_CIT07 = new BKPHMC_CIT07;
    NhapNoiDungPT_CIT07(newBook_CIT07);
    Push_CIT07(queue, newBook_CIT07);
}

// 11. Lấy nhiều phần tử ra khỏi QUEUE
void LayNhieuPT_QUEUE_CIT07(Queue_CIT07 &queue)
{
    int cnt_CIT07;
    cout << "Bạn muốn lấy bao nhiêu phần tử ra khỏi QUEUE? : ";
    cin >> cnt_CIT07;

    cout << "Các phần tử lấy được" << endl;
    for (int i = 0; i < cnt_CIT07; i++)
    {
        BKPHMC_CIT07* temp_book = Pop_CIT07(queue); // Lấy phần tử ở đầu hàng đợi
        if (temp_book == nullptr)
        {
            cout << "Không còn phần tử nào để lấy.\n";
            break;
        }
        else
        {
            cout << "Phần tử " << i + 1 << ":\n";
            InNoiDung_CIT07(temp_book);
            delete temp_book; // Giải phóng bộ nhớ
        }
    }
}

// 12. Lấy một phần tử khỏi QUEUE (dequeue)
void Dequeue_QUEUE_CIT07(Queue_CIT07 &queue)
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
            BKPHMC_CIT07* temp_book_CIT07 = layPTDau_CIT07(queue);
            if (temp_book_CIT07 != nullptr)
            {
                cout << "Lấy thành công phần tử khỏi Queue:\n ";
                InNoiDung_CIT07(temp_book_CIT07);
            }
            break;
        }
        case '2':
        {
            BKPHMC_CIT07* temp_book_CIT07 = Pop_CIT07(queue);
            if (temp_book_CIT07 != nullptr)
            {
                cout << "Lấy thành công phần tử khỏi Queue:\n ";
                InNoiDung_CIT07(temp_book_CIT07);
                delete temp_book_CIT07; // Giải phóng bộ nhớ
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

// 13. In QUEUE [FIFO]
void Inds_QUEUE_CIT07(Queue_CIT07 &queue)
{
    if (KiemTraRong_CIT07(queue))
    {
        cout << "\nHàng đợi CÁC PHẦN TỬ TRONG QUEUE:";
        cout << "  QUEUE RỖNG !\n";
    }
    else
    {
        cout << "\n_____________________________________\n";
        cout << "\nHàng đợi CÁC PHẦN TỬ TRONG QUEUE:\n";
        BKPHMC_CIT07* current = queue.front;
        int i = 1;
        while (current != nullptr)
        {
            cout << "Phần tử " << i++ << ":\n";
            cout << "Mã sách: " << current->Ma_Sach_CIT07 << "\n";
            cout << "Tên sách: " << current->Ten_Sach_CIT07 << "\n";
            cout << "Loại sách: " << current->Loai_Sach_CIT07 << "\n";
            cout << "Số lần mượn sách: " << current->So_Lan_Muon_Sach_CIT07 << "\n";
            cout << "\n";
            current = current->next;
        }
        cout << "\n_____________________________________\n";
    }
}

/****************************************************/
/** CHƯƠNG TRÌNH CHÍNH (MAIN) ***/
/****************************************************/
int main()
{
    Queue_CIT07 queue;
    KhoiTao_CIT07(queue); // Khởi tạo hàng đợi
    char luaChon;    // Khai báo biến lựa chọn menu

    do
    {
        // Hiển thị menu
        cout << "CHƯƠNG TRÌNH QUẢN LÝ THƯ VIỆN [Hàng đợi LIÊN KẾT - QUEUE]\n";
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
            NapNhieuPT_QUEUE_CIT07(queue);
            break;
        case '2':
            Push_QUEUE_CIT07(queue);
            break;
        case '3':
            Dequeue_QUEUE_CIT07(queue);
            break;
        case '4':
            LayNhieuPT_QUEUE_CIT07(queue);
            break;
        case '5':
            Inds_QUEUE_CIT07(queue);
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
