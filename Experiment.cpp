
// // #include <iostream>
// // #include <queue>
// // #include <stack>

// // using namespace std;

// // struct BKPHMC_CIT07 {
// //     string Ten_Sach_CIT07;
// //     string Ma_Sach_CIT07;
// //     string Loai_Sach_CIT07;
// //     int So_Lan_Muon_Sach_CIT07;
// // };

// // struct Node_CIT07 {
// //     BKPHMC_CIT07 data_CIT07;
// //     Node_CIT07 *left_CIT07;
// //     Node_CIT07 *right_CIT07;

// //     Node_CIT07(BKPHMC_CIT07 newData_CIT07) {
// //         data_CIT07 = newData_CIT07;
// //         left_CIT07 = nullptr;
// //         right_CIT07 = nullptr;
// //     }
// // };

// // Node_CIT07* root_CIT07 = nullptr;

// // // Hàm chung để in thông tin sách
// // void inThongTinSach(Node_CIT07* node) {
// //     if (node == nullptr) return;
// //     cout << "Mã sách: " << node->data_CIT07.Ma_Sach_CIT07 << "\n";
// //     cout << "Tên sách: " << node->data_CIT07.Ten_Sach_CIT07 << "\n";
// //     cout << "Loại sách: " << node->data_CIT07.Loai_Sach_CIT07 << "\n";
// //     cout << "Số lần mượn sách: " << node->data_CIT07.So_Lan_Muon_Sach_CIT07 << "\n\n";
// // }

// // // Duyệt theo thứ tự trung vị (In-order traversal)
// // void DuyetCayLNR(Node_CIT07* node) {
// //     if (node == nullptr) return;
// //     DuyetCayLNR(node->left_CIT07);
// //     inThongTinSach(node);
// //     DuyetCayLNR(node->right_CIT07);
// // }

// // // Duyệt theo tiền vị (Pre-order traversal)
// // void DuyetCayPR(Node_CIT07* node) {
// //     if (node == nullptr) return;
// //     inThongTinSach(node);
// //     DuyetCayPR(node->left_CIT07);
// //     DuyetCayPR(node->right_CIT07);
// // }

// // // Duyệt theo hậu vị (Post-order traversal)
// // void DuyetCayLR(Node_CIT07* node) {
// //     if (node == nullptr) return;
// //     DuyetCayLR(node->left_CIT07);
// //     DuyetCayLR(node->right_CIT07);
// //     inThongTinSach(node);
// // }

// // // Duyệt theo cấp độ (Level-order traversal) - sử dụng hàng đợi
// // void DuyetCayLevelOrder(Node_CIT07* root) {
// //     if (root == nullptr) return;

// //     queue<Node_CIT07*> q;
// //     q.push(root);

// //     while (!q.empty()) {
// //         Node_CIT07* node = q.front();
// //         q.pop();

// //         inThongTinSach(node);

// //         if (node->left_CIT07 != nullptr) q.push(node->left_CIT07);
// //         if (node->right_CIT07 != nullptr) q.push(node->right_CIT07);
// //     }
// // }

// // // Duyệt trung vị không đệ quy (In-order, non-recursive)
// // void DuyetCayLNRNonRecursive(Node_CIT07* root) {
// //     stack<Node_CIT07*> s;
// //     Node_CIT07* current = root;

// //     while (current != nullptr || !s.empty()) {
// //         while (current != nullptr) {
// //             s.push(current);
// //             current = current->left_CIT07;
// //         }

// //         current = s.top();
// //         s.pop();

// //         inThongTinSach(current);

// //         current = current->right_CIT07;
// //     }
// // }

// // // Duyệt tiền vị không đệ quy (Pre-order, non-recursive)
// // void DuyetCayPRNonRecursive(Node_CIT07* root) {
// //     if (root == nullptr) return;

// //     stack<Node_CIT07*> s;
// //     s.push(root);

// //     while (!s.empty()) {
// //         Node_CIT07* node = s.top();
// //         s.pop();

// //         inThongTinSach(node);

// //         if (node->right_CIT07 != nullptr) s.push(node->right_CIT07);
// //         if (node->left_CIT07 != nullptr) s.push(node->left_CIT07);
// //     }
// // }

// // int main() {
// //     // Ví dụ tạo cây nhị phân
// //     Node_CIT07* root = new Node_CIT07({"Book1", "001", "Fiction", 10});
// //     root->left_CIT07 = new Node_CIT07({"Book2", "002", "Non-fiction", 5});
// //     root->right_CIT07 = new Node_CIT07({"Book3", "003", "Science", 7});
// //     root->left_CIT07->left_CIT07 = new Node_CIT07({"Book4", "004", "History", 3});
// //     root->left_CIT07->right_CIT07 = new Node_CIT07({"Book5", "005", "Literature", 12});

// //     cout << "Duyệt theo thứ tự trung vị (In-order): \n";
// //     DuyetCayLNR(root);
// //     cout << "--------------------------------------\n";

// //     cout << "Duyệt theo thứ tự tiền vị (Pre-order): \n";
// //     DuyetCayPR(root);
// //     cout << "--------------------------------------\n";

// //     cout << "Duyệt theo thứ tự hậu vị (Post-order): \n";
// //     DuyetCayLR(root);
// //     cout << "--------------------------------------\n";

// //     cout << "Duyệt theo cấp độ (Level-order): \n";
// //     DuyetCayLevelOrder(root);
// //     cout << "--------------------------------------\n";

// //     cout << "Duyệt trung vị không đệ quy (In-order, non-recursive): \n";
// //     DuyetCayLNRNonRecursive(root);
// //     cout << "--------------------------------------\n";

// //     cout << "Duyệt tiền vị không đệ quy (Pre-order, non-recursive): \n";
// //     DuyetCayPRNonRecursive(root);
// //     cout << "--------------------------------------\n";

// //     return 0;
// // }

// ////////////////////////
// // KHAI BAO CAC THU VIEN SD
// //////////////////////
// using namespace std;
// #include <stdio.h>  // thu vien xuat nhap chuan (standard input/output)
// #include <conio.h>  // thu vien giao tiep man hinh/ban phim (console input/output)
// #include <iostream> // thu vien objects (input/output stream)
// #include <string>   // thu vien thao tác trên chuoi ký tu
// #include <ctype.h>  // thu vien thao tác trên ký tu: character type

// ////////////////////////
// // KHAI BAO CAU TRUC DL BST BINARY SEARCH TREE = CAY NHI PHAN TIM KIEM
// //////////////////////

// struct phim // Cấu trúc một phần tử 
// {
//     string name;    // tên phim
//     int doanhthu;   // doanh thu
//     string daodien; // đạo diễn
//     int view;       // số lượt xem
//     struct phim *left, *right; // con trỏ đến nhánh trái và phải của nút
// };

// struct phim *root; // Nút gốc của cây nhị phân tìm kiếm (BST)

// ////////////////////////
// // CAC PHEP TOAN (THAO TAC) TRÊN CÂY NHỊ PHÂN TÌM KIẾM
// //////////////////////

// // 1. Khởi tạo BST
// void Init()
// {
//     root = NULL;
// } // Chưa có nút nào, nên nút gốc trỏ vào NULL

// // 2. Kiểm tra rỗng
// int Empty() // int = true [rỗng] / false [không rỗng = có Node]
// {
//     return (root == NULL);
// }

// // 3. Thêm nút vào cây nhị phân tìm kiếm (BST)
// void InsertNodeBST(struct phim *x, struct phim *&r)
// {
//     if (r == NULL)
//     {
//         r = x;
//     }
//     else if (x->name > r->name)
//         InsertNodeBST(x, r->right);
//     else
//         InsertNodeBST(x, r->left);
// }

// // 4. Duyệt cây nhị phân tìm kiếm (BST)
// void NLR(struct phim *r) // Duyệt Node-Left-Right
// {
//     if (r != NULL)
//     {
//         cout << "Phim: " << r->name << ", Doanh thu: " << r->doanhthu << ", Dao dien: " << r->daodien << ", Luot xem: " << r->view << endl;
//         NLR(r->left);
//         NLR(r->right);
//     }
// }

// void NRL(struct phim *r) // Duyệt Node-Right-Left
// {
//     if (r != NULL)
//     {
//         cout << "Phim: " << r->name << ", Doanh thu: " << r->doanhthu << ", Dao dien: " << r->daodien << ", Luot xem: " << r->view << endl;
//         NRL(r->right);
//         NRL(r->left);
//     }
// }

// void LNR(struct phim *r) // Duyệt Left-Node-Right
// {
//     if (r != NULL)
//     {
//         LNR(r->left);
//         cout << "Phim: " << r->name << ", Doanh thu: " << r->doanhthu << ", Dao dien: " << r->daodien << ", Luot xem: " << r->view << endl;
//         LNR(r->right);
//     }
// }

// void LRN(struct phim *r) // Duyệt Left-Right-Node
// {
//     if (r != NULL)
//     {
//         LRN(r->left);
//         LRN(r->right);
//         cout << "Phim: " << r->name << ", Doanh thu: " << r->doanhthu << ", Dao dien: " << r->daodien << ", Luot xem: " << r->view << endl;
//     }
// }

// void RNL(struct phim *r) // Duyệt Right-Node-Left
// {
//     if (r != NULL)
//     {
//         RNL(r->right);
//         cout << "Phim: " << r->name << ", Doanh thu: " << r->doanhthu << ", Dao dien: " << r->daodien << ", Luot xem: " << r->view << endl;
//         RNL(r->left);
//     }
// }

// void RLN(struct phim *r) // Duyệt Right-Left-Node
// {
//     if (r != NULL)

// {
//         RLN(r->right);
//         RLN(r->left);
//         cout << "Phim: " << r->name << ", Doanh thu: " << r->doanhthu << ", Dao dien: " << r->daodien << ", Luot xem: " << r->view << endl;
//     }
// }

// //////////////////////////////////////////////////////
// // III. CÁC THỦ TỤC SỬ DỤNG CÁC PHÉP TOÁN CƠ BẢN
// /////////////////////////////////////////////////////

// // 0. Nhập thông tin cho 1 phim thứ i để chuẩn bị thêm vào cây (chưa thêm)
// void nhap_phim(int i, struct phim *&x)
// {
//     x = new phim;
//     cout << "Nhap ten phim thu " << i << " = ";
//     cin.ignore(); // Clear buffer
//     getline(cin, x->name);
//     cout << "Nhap doanh thu: ";
//     cin >> x->doanhthu;
//     cout << "Nhap dao dien: ";
//     cin.ignore(); // Clear buffer again
//     getline(cin, x->daodien);
//     cout << "Nhap so luot xem: ";
//     cin >> x->view;
//     x->left = NULL;
//     x->right = NULL;
// }

// // 1. Nhập cây nhị phân tìm kiếm: BST
// void nhap_cay()
// {
//     int m; // Số lượng phim thực tế nhập vào cây
//     cout << "Nhap so luong phim can them vao CAY = ";
//     cin >> m;

//     struct phim *x;

//     Init(); // Khởi tạo cây
//     for (int i = 0; i < m; i++)
//     {
//         nhap_phim(i + 1, x);
//         InsertNodeBST(x, root);
//     }
//     cout << "DA NHAP phim vao CAY voi so luong phim = " << m << " " << endl;
// }

// // 2. Duyệt cây theo NLR
// void duyet_NLR()
// {
//     cout << "\n\nCAC PHIM TREN CAY hien tai theo NODE-LEFT-RIGHT: \n";
//     NLR(root);
//     cout << endl;
// }

// // 3. Duyệt cây theo NRL
// void duyet_NRL()
// {
//     cout << "\n\nCAC PHIM TREN CAY hien tai theo NODE-RIGHT-LEFT: \n";
//     NRL(root);
//     cout << endl;
// }

// // 4. Duyệt cây theo LNR
// void duyet_LNR()
// {
//     cout << "\n\nCAC PHIM TREN CAY hien tai theo LEFT-NODE-RIGHT: \n";
//     LNR(root);
//     cout << endl;
// }

// // 5. Duyệt cây theo LRN
// void duyet_LRN()
// {
//     cout << "\n\nCAC PHIM TREN CAY hien tai theo LEFT-RIGHT-NODE: \n";
//     LRN(root);
//     cout << endl;
// }

// // 6. Duyệt cây theo RNL
// void duyet_RNL()
// {
//     cout << "\n\nCAC PHIM TREN CAY hien tai theo RIGHT-NODE-LEFT: \n";
//     RNL(root);
//     cout << endl;
// }

// // 7. Duyệt cây theo RLN
// void duyet_RLN()
// {
//     cout << "\n\nCAC PHIM TREN CAY hien tai theo RIGHT-LEFT-NODE: \n";
//     RLN(root);
//     cout << endl;
// }

// //////////////////////////////////////////////////////
// // IV. MAIN
// /////////////////////////////////////////////////////
// int main()
// {
//     nhap_cay();

//     cout << "Nhan phim bat ky de tiep tuc ";
//     getch();

//     char chon;

//     while (1)
//     {
//         cout << "\nCAY NHI PHAN TIM KIEM = BINARY SEARCH TREE = BST\n";
//         cout << "\n 1. Duyet cay NLR ";
//         cout << "\n 2. Duyet cay NRL ";
//         cout << "\n 3. Duyet cay LNR ";
//         cout << "\n 4. Duyet cay LRN ";
//         cout << "\n 5. Duyet cay RNL ";
//         cout << "\n 6. Duyet cay RLN ";
//         cout << "\n 7. Them MOT phim moi vao BST";
//         cout << "\n 8. Them NHIEU phim moi vao BST";
//         cout << "\n 9. Tim phim co ten x tren CAY";
//         cout << "\n a. Xoa phim co ten x tren CAY";
//         cout << "\n b. Thay doi gia tri cua phim tren CAY";
//         cout << "\n c. So phim tren CAY";
//         cout << "\n d. Kiem tra CAY rong";
//         cout << "\n z. Thoat\n";

//         chon = getch();
//         chon = toupper(chon);
//         if (chon == 'Z')
//             break;

//         switch (chon)
//         {
//         case '1':
//             duyet_NLR();
//             break;
//         case '2':
//             duyet_NRL();
//             break;
//         case '3':
//             duyet_LNR();
//             break;
//         case '4':
//             duyet_LRN();
//             break;
//         case '5':
//             duyet_RNL();
//             break;
//         case '6':
//             duyet_RLN();
//             break;
//         case '7':
//             // Code để thêm một phim mới vào BST
//             break;
//         case '8':
//             nhap_cay();
//             break;
//         case 'D':
//             if (Empty())
//                 cout << "CAY DANG RONG ! \n";
//             else
//                 cout << "CAY DANG CO NUT \n";
//             break;
//         default:
//             cout << "CHON SAI, DE NGHI CHON LAI !\n";
//             break;
//         }
//         cout << "Nhan phim bat ky de tiep tuc ";
//         getch();
//     }
// }

cout<<"\nCAY NHI PHAN TIM KIEM = BINARY SEARCH TREE = BST\n";
	cout<<"\n 1. Duyet cay NLR ";
	cout<<"\n 2. Duyet cay NRL ";
	cout<<"\n 3. Duyet cay LNR ";
    cout<<"\n 4. Duyet cay LRN ";
	cout<<"\n 5. Duyet cay RNL ";
	cout<<"\n 6. Duyet cay RLN ";
	cout<<"\n 7. Them MOT NUT moi vao BST";
	cout<<"\n 8. Them NHIEU NUT moi vao BST";
	cout<<"\n 9. Tim NUT co gia tri x tren CAY";
	cout<<"\n a. Xoa NUT co gia tri x tren CAY";
	cout<<"\n b. Thay doi gia tri cua NUT tren CAY";
	cout<<"\n c  So NUT tren CAY";
	cout<<"\n d. Kiem tra CAY rong";
	cout<<"\n z. Thoat\n";
