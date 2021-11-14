#include <string> 
#include <algorithm> //xóa khoảng trắng trong chuỗi
#include <stdio.h>
#include <fstream>
#include <iostream>
#include <iomanip> //sử dụng setw
#include <Windows.h>//sử dụng font tiếng việt
using namespace std;

struct nodeGiaiThuong
{
    string data;
    nodeGiaiThuong *pointer;
};

struct bophim
{
    string tenphim, theloai, daodien,
     namchinh, nuchinh,hangSX;
    nodeGiaiThuong *giaithuong;
    int namSX;
};

struct node
{
    bophim data;
    node *pointer;
};

int w=15, luachon ; node *dx;
int flagC6=0; // cờ của câu 6 và câu 9

void taoNodeGiaiThuong(nodeGiaiThuong *&L)
{
    L=NULL;
    nodeGiaiThuong* p;
    int i=0,n;
    string x;
    cout<<"Nhap vao so giai thuong: ";
    cin>>n;
    cin.ignore();
    while(i<n)
    {
        cout<<"Nhap vao ten giai thuong thu "<<i+1<<": ";
        getline(cin,x);
        p = new nodeGiaiThuong;
        p->data=x;
        p->pointer=L;
        L=p;
        i++;
    }
}

void xuatNodeGiaiThuong(nodeGiaiThuong *L)
{
    nodeGiaiThuong *p;
    p=L;
    while(p!=NULL)
    {
        cout<<p->data<<endl;
        p=p->pointer;
    }
}

void xuat1node(node *L)
{
    cout
    <<setw(16)<<left<< L->data.tenphim<<"\t"
    <<setw(w)<< L->data.theloai<<"\t"
    <<setw(w)<< L->data.daodien<<"\t"
    <<setw(w)<< L->data.namchinh<<"\t"
    <<setw(w)<< L->data.nuchinh<<"\t"
    <<setw(w)<< L->data.hangSX<<"\t"
    <<setw(w)<< L->data.namSX <<"\t"<<endl;
}

void xuatCaiKhung()
{
    cout
    <<setw(7)<<left<< "STT"<<"\t"
    <<setw(16)<< "Ten phim"<<"\t"
    <<setw(w)<< "The loai"<<"\t"
    <<setw(w)<< "Dao dien"<<"\t"
    <<setw(w)<< "Nam chinh"<<"\t"
    <<setw(w)<< "Nu chinh"<<"\t"
    <<setw(w)<< "Hang san xuat"<<"\t"
    <<setw(w)<< "Nam san xuat" <<"\t"<<endl;
}

void duyetDS(node *L)
{
    int stt = 1;
    xuatCaiKhung();
    while (L != NULL)
    {
        cout<<setw(7)<<left<<stt<<"\t";
        xuat1node(L);
        L = L->pointer;
        stt++;
    }
}

string removeSpaces(string str)
{
    str.erase(remove(str.begin(), str.end(), ' '), str.end());
    return str;
}

bool timkiem(string a, string b)
{
    a = removeSpaces(a);
    b = removeSpaces(b);
    for (int i = 0; i <= a.size(); i++)
    {
        if ((a[i] >= 65 && a[i] <= 90))
        {
            a[i] = a[i] + 32;
        }
    }
    for (int i = 0; i <= b.size(); i++)
    {
        if (b[i] >= 65 && b[i] <= 90)
            b[i] = b[i] + 32;
    }
    if (a == b)
        return true;
    return false;
}

void taoTuKeyboard(node *&L) //Câu 1
{
    L = NULL;
    node *p;
    int i = 1, n;
    bophim x;
    cout << "Nhập vào số lượng bộ phim: ";
    cin >> n;
    while (i <= n)
    {
        cout << "----Vui lòng nhập thông tin bộ phim số " << i << endl;
        cin.ignore();
        cout << "Ten phim     : ";
        getline(cin, x.tenphim);
        cout << "The loai     : ";
        getline(cin, x.theloai);
        cout << "Dao dien     : ";
        getline(cin, x.daodien);
        cout << "Nam chinh    : ";
        getline(cin, x.namchinh);
        cout << "Nu chinh     : ";
        getline(cin, x.nuchinh);
        cout << "Hang san xuat: ";
        getline(cin, x.hangSX);
        cout << "Nam san xuat : ";
        cin >> x.namSX;
        p = new node;
        p->data = x;
        p->pointer = L;
        L = p;
        i++;
    }
}

void timTheLoai(node *L) //Cau 2
{
    int stt = 1,flag=0;
    bophim x;
    cout << "Nhập vào thể loại phim cần tìm: ";
    getline(cin, x.theloai);
    xuatCaiKhung();
    node *p=L;
    while (p != NULL)
    {
        if (timkiem(p->data.theloai, x.theloai))
        {
            cout<<setw(7)<<left<<stt<<"\t";
            xuat1node(p);
            stt++;
            flag++;
        }
        p = p->pointer;
    }
    if(flag==0)
        cout<<"\t\tKHÔNG TỒN TẠI THỂ LOẠI"<<endl;
}

void timNamChinh(node *L) //Cau 3
{
    int stt = 1,flag=0;
    bophim x;
    cout << "Nhập vào tên nam diễn viên chính cần tìm: ";
    getline(cin, x.namchinh);
    xuatCaiKhung();
    node *p=L;
    while (p != NULL)
    {
        if (timkiem(p->data.namchinh, x.namchinh))
        {
            cout<<setw(7)<<left<<stt<<"\t";
            xuat1node(p);
            stt++;
            flag++;
        }
        p = p->pointer;
    }
    if(flag==0)
        cout<<"\t\tKHÔNG TÌM THẤY TÊN NAM CHÍNH"<<endl;
}

void timDaoDien(node *L) //Cau 4
{
    int stt = 1,flag=0;
    bophim x;
    cout << "Nhập vào tên đạo diễn cần tìm: ";
    getline(cin, x.daodien);
    xuatCaiKhung();
    node *p=L;
    while (p != NULL)
    {
        if (timkiem(p->data.daodien, x.daodien))
        {
            cout<<setw(7)<<left<<stt<<"\t";
            xuat1node(p);
            stt++;
            flag++;
        }
        p = p->pointer;
    }
    if(flag==0)
        cout<<"\t\tKHÔNG TÌM THẤY PHIM HOẶC ĐẠO DIỄN"<<endl;
}

void timDaoDienVaNamSX(node *L) //Cau 5
{
    int stt = 1,flag=0;
    bophim x;
    cout << "Nhập vào tên đạo diễn cần tìm: ";
    getline(cin, x.daodien);
    cout << "Nhập vào năm sản xuất: ";
    cin>>x.namSX; 
    if(cin.fail()) { cout << "Hãy nhập một con số "<<endl;cin.clear(); return;}
    xuatCaiKhung();
    node *p=L;
    while (p != NULL)
    {
        if (timkiem(p->data.daodien, x.daodien)&&(p->data.namSX==x.namSX))
        {
            cout<<setw(7)<<left<<stt<<"\t";
            xuat1node(p);
            stt++;
            flag++;
        }
        p = p->pointer;
    }
    if(flag==0)
        cout<<"\t\tKhông tìm thấy phim hoặc đạo diễn, năm sản xuất"<<endl;
}

void nhapGiaiThuong(node *L) //Cau 6
{
    flagC6=1; // đã chạy Cau 6
    int flag=0;
    bophim x;
    cout << "Nhập vào tên phim cần trao giải thưởng: ";
    getline(cin, x.tenphim);
    node *p=L;
    while (p != NULL)
    {
        if (timkiem(p->data.tenphim, x.tenphim))
        {
            taoNodeGiaiThuong(p->data.giaithuong);
            flag=1;
        }
        p = p->pointer;
    }
    if(flag==0) cout<<"Không tìm thấy phim"<<endl;
}

void nhapPhimInDaoDien(node *L) //Cau 7
{
    int flag=0;
    bophim x;
    cout << "Nhập vào tên phim: ";
    getline(cin, x.tenphim);
    node *p=L;
    while (p != NULL)
    {
        if (timkiem(p->data.tenphim, x.tenphim))
        {
            cout<<p->data.daodien<<endl;
            flag++;
        }
        p = p->pointer;
    }
    if(flag==0)
    cout<<"\t\tKHÔNG TỒN TẠI"<<endl;
}

void nhapPhimInDVC(node *L) //Cau 8
{
    int flag=0;
    bophim x;
    cout << "Nhập vào tên phim: ";
    getline(cin, x.tenphim);
    node *p=L;
    while (L != NULL)
    {
        if (timkiem(p->data.tenphim, x.tenphim))
        {
            cout<<p->data.namchinh<<", "<<p->data.nuchinh<<endl;
            flag++;
            break;
        }
        p = p->pointer;
    }
    if(flag==0)
    cout<<"\t\tKHÔNG TỒN TẠI"<<endl;
}

void nhapPhimInGiaiThuong(node *L) //Cau 9
{
    int flag=0;
    if(flagC6==0) L->data.giaithuong=NULL; // chưa nhập giải thưởng
    bophim x;
    cout << "Nhập vào tên phim cần tìm giải thưởng: ";
    getline(cin, x.tenphim);
    node *p=L;
    while (p != NULL)
    {
        if (timkiem(p->data.tenphim, x.tenphim))
        {
            if (flagC6==0)
            {
                cout << "\t\tKHÔNG CÓ GIẢI THƯỞNG" << endl;
            }
            else
            {
                xuatNodeGiaiThuong(p->data.giaithuong);
            }
                flag++;
        }
        p = p->pointer;
    }
    if(flag==0) cout << "\t\tKHÔNG TỒN TẠI PHIM HOẶC GIẢI THƯỞNG" << endl;
}

void sortedInsert(struct node **head_ref, struct node *new_node)
{
    struct node *current;
    if (*head_ref == NULL || (*head_ref)->data.tenphim >= new_node->data.tenphim)
    {
        new_node->pointer = *head_ref;
        *head_ref = new_node;
    }
    else
    {

        current = *head_ref;
        while (current->pointer != NULL &&
               current->pointer->data.tenphim < new_node->data.tenphim)
        {
            current = current->pointer;
        }
        new_node->pointer = current->pointer;
        current->pointer = new_node;
    }
}

void sortTenPhim(struct node **head_ref) //Cau 10
{
    struct node *sorted = NULL;
    struct node *current = *head_ref;
    while (current != NULL)
    {
        struct node *next = current->pointer;
        sortedInsert(&sorted, current);
        current = next;
    }
    *head_ref = sorted;
}

void xuatRaFile(node *L) //Cau 11
{
    ofstream fileout;
    fileout.open("D:\\DATACTDL\\phimOUT.txt");
    int stt = 1;
    fileout
    <<setw(7)<<left<< "STT"<<"\t"
    <<setw(16)<< "Ten phim"<<"\t"
    <<setw(w)<< "The loai"<<"\t"
    <<setw(w)<< "Dao dien"<<"\t"
    <<setw(w)<< "Nam chinh"<<"\t"
    <<setw(w)<< "Nu chinh"<<"\t"
    <<setw(w)<< "Hang san xuat"<<"\t"
    <<setw(w)<< "Nam san xuat" << endl;
    while (L != NULL)
    {
    fileout<<setw(7)<<left<<stt<<"\t";
    fileout
    <<setw(16)<<left<< L->data.tenphim<<"\t"
    <<setw(w)<< L->data.theloai<<"\t"
    <<setw(w)<< L->data.daodien<<"\t"
    <<setw(w)<< L->data.namchinh<<"\t"
    <<setw(w)<< L->data.nuchinh<<"\t"
    <<setw(w)<< L->data.hangSX<<"\t"
    <<setw(w)<< L->data.namSX << endl;
        L = L->pointer;
        stt++;
    }
    fileout.close();
}

void taoTuFile(node *&L) //Cau 12
{
    ifstream cin("D:\\DATACTDL\\phim.dat");
    L = NULL;
    node *p;
    int i = 1, n;
    bophim x;
    cin >> n;
    while (i <= n)
    {
        cin.ignore();
        getline(cin, x.tenphim);
        getline(cin, x.theloai);
        getline(cin, x.daodien);
        getline(cin, x.namchinh);
        getline(cin, x.nuchinh);
        getline(cin, x.hangSX);
        cin >> x.namSX;
        p = new node;
        p->data = x;
        p->pointer = L;
        L = p;
        i++;
    }
    cin.close();
}

void menu()
{

    switch (luachon)
    {
        case 1:
        taoTuKeyboard(dx);
        duyetDS(dx);
            break;
        case 2:
        timTheLoai(dx);
            break;
        case 3:
        timNamChinh(dx);
            break;
        case 4:
        timDaoDien(dx);
            break;
        case 5:
        timDaoDienVaNamSX(dx);
            break;
        case 6:
        nhapGiaiThuong(dx);
            break;
        case 7:
        nhapPhimInDaoDien(dx);
            break;
        case 8:
        nhapPhimInDVC(dx);
            break;
        case 9:
        nhapPhimInGiaiThuong(dx);
            break;
        case 10:
            sortTenPhim(&dx);
            duyetDS(dx);
        break;
        case 11:
        xuatRaFile(dx);
        cout<<"Xuất ra file thành công!!"<<endl;
            break;
        case 12:
        taoTuFile(dx);
        duyetDS(dx);
            break;
    }
}

int main()
{
    SetConsoleOutputCP(65001);
    cout
    <<"|                           Danh sách menu                                 |\n"
    <<"|1.Nhập vào bộ phim mới và các thông tin liên quan                         |\n"
    <<"|2.Nhập vào một thể loại. In ra danh sách các bộ phim                      |\n"
    <<"|3.Nhập vào một tên nam diễn viên. In ra các bộ phim có diễn viên này đóng |\n"
    <<"|4.Nhập tên đạo diễn. In ra danh sách các bộ phim do đạo diễn dàn dựng     |\n"
    <<"|5.Nhập tên đạo diễn và năm sản xuất. In ra các phim của đạo diễn trong năm|\n"
    <<"|6.Nhập tên phim, nhập giải thương cho phim                                |\n"
    <<"|7.Nhập tên phim, in ra tên đạo diễn                                       |\n"
    <<"|8.Nhập tên phim, in ra tên các diễn viên chính                            |\n"
    <<"|9.Nhập tên phim, in ra các giải thưởng                                    |\n"
    <<"|10. Sắp xếp và in ra tên phim theo thứ tự tăng dần                        |\n"
    <<"|11. Lưu danh sách vào file                                                |\n"
    <<"|12. Mở file, tạo dữ liệu từ file đã có                                    |\n"
    <<"|0. Thoát                                                                  |\n";
    int flag=0; // cờ tạo data nếu người dùng không tự tạo data

    while (true)
    {
        cout << "Nhập vào lựa chọn của bạn: ";
        cin >> luachon;
        if (luachon == 0)
        {
            cout<<"\t\t KÍNH CHÀO TẠM BIỆT VÀ HẸN GẶP LẠI";
            break;
        }
        if (flag == 0)
        {
            if (luachon >= 2 && luachon <= 9)
            {
                taoTuFile(dx);//tạo data
                duyetDS(dx);//xuat ra
                cin.ignore();
                menu();
                flag = 1; //đã tạo data rồi
            }
            else
            {
                menu();
                flag=1; //đã tạo data base
            }
        }
        else
        {
            cin.ignore();
            menu();
        }
    }
}
