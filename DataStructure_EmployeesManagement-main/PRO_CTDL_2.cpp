#include<iostream>
#include<string>
#include<fstream>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
#include<Windows.h>
using namespace std;

//Ham bo tro
void TextColor(int x) {
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau, x);
} 

void gotoxy(int x, int y)
{
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
/////USER
class User{
protected:
    string Username;
    string Password;

    string Name;
    string Address;
    string Phone;
    string Email;
public:
    string getUsername(){return Username;}
    string getPassword(){return Password;}
    string getName(){return Name;}
    string getAddress(){return Address;}
    string getPhone(){return Phone;}
    string getEmail(){return Email;}
    
    void setUsername(string _Username){Username = _Username;}
    void setPassword(string _Password){Password = _Password;}
    void setName(string _Name){Name = _Name;}
    void setAddress(string _Address){Address = _Address;}
    void setPhone(string _Phone){Name = _Phone;}
    void setEmail(string _Email){Name = _Email;}

    User(string _Username = "", string _Password = "111111", string _Name = "", string _Address = "", string _Phone = "", string _Email = ""){
        Username = _Username;
        Password = _Password;
        Name = _Name;
        Address = _Address;
        Phone =_Phone;
        Email = _Email;
    }
    User(const User &u){
        Username = u.Username;
        Password = u.Password;
        Name = u.Name;
        Address = u.Address;
        Phone = u.Phone;
        Email = u.Email;
    }
    ~User(){}
    virtual void ReadFile(ifstream &FileIn){
        getline(FileIn, Username, ',');
        getline(FileIn, Password);
 	}
    virtual void CreateFile(ofstream &FileOut, char* &FileName){
        string str = (string)FileName;
        string FilePath = str + ".txt";
        FileName = new char [FilePath.length()+1];
        strcpy (FileName, FilePath.c_str());
        if (FileName != NULL){
            FileOut.open(FileName, ios_base::out);
        }
        delete[] FileName;
    }
    virtual void OpenFile(ifstream &FileIn, char* &FileName){
        string str = (string)FileName;
        string FilePath = str + ".txt";
        FileName = new char [FilePath.length()+1];
        strcpy (FileName, FilePath.c_str());
        if (FileName != NULL)
        {
            FileIn.open(FileName, ios_base::in);
        }
        delete[] FileName;
    }
    virtual void ReadInfomation(ifstream &FileIn){
        getline(FileIn, Name);
        getline(FileIn, Address);
        getline(FileIn, Phone);
        getline(FileIn, Email);
    }
    virtual void DeleteFile(string FileName){
        string FilePath = "\"del " + FileName + ".txt\"";
        char* strDelete = new char[FilePath.length() + 1];
        strcpy(strDelete, FilePath.c_str()); //chuyen string thanh char
        system(strDelete);
    }
    virtual void Input(){
        cin.ignore();
        TextColor(3);
        cout << "Nhap thong tin ca nhan " << endl;
        cout << "Ho ten: ";
        TextColor(15);
        getline(cin, Name);
        TextColor(3);
        cout <<"Dia chi: ";
        TextColor(15);
        getline(cin, Address);
        TextColor(3);
        cout <<"So dien thoai: ";
        TextColor(15);
        getline(cin, Phone);
        TextColor(3);
        cout <<"Email: ";
        TextColor(15);
        getline(cin, Email);
    }
};
/////Admin
class Administrators : public User{
public:
    void ReadFile(ifstream &FileIn){
        User::ReadFile(FileIn);
    }
    void CreateFile(ofstream &FileOut, char *FileName){
        User::CreateFile(FileOut, FileName);
    }
    bool operator == (Administrators a){
        return a.getUsername() + a.getPassword() == getUsername() + getPassword();
    }
    Administrators(string _Username = "", string _Password = "111111", string _Name = "", string _Address = "", string _Phone = "", string _Email = "")
    :User(_Username, _Password, _Name, _Address, _Phone, _Password){}
};
/////Employess
class Employees : public User{
public:
    void ReadFile(ifstream &FileIn){
        User::ReadFile(FileIn);
    }
    void Input() {
        User::Input();
    }
    void CreateFile(ofstream &FileOut, char *FileName){
        User::CreateFile(FileOut, FileName);
    }
    void ReadInformation(ifstream &FileIn){
        User::ReadInfomation(FileIn);
    }
    bool operator ==(Employees a){
        return a.getUsername() + a.getPassword() == getUsername() + getPassword();
    }
    Employees(string _Username = "", string _Password = "111111", string _Name = "", string _Address = "", string _Phone = "", string _Email = "")
    :User(_Username, _Password, _Name, _Address, _Phone, _Password){}
};
void DangNhapAdmin(){
    TextColor(14);
	gotoxy(40, 2);  cout << "* * * * * * * * * * * * * * * * * * * * *\n";
	gotoxy(40, 3);  cout << "*             DANG NHAP ADMIN           *\n";
	gotoxy(40, 4);  cout << "* * * * * * * * * * * * * * * * * * * * *\n";
}
void DangNhapEmployees(){
    TextColor(14);
    gotoxy(40, 2);  cout << "* * * * * * * * * * * * * * * * * * * * *\n";
	gotoxy(40, 3);  cout << "*            DANG NHAP EMPLOYEE         *\n";
	gotoxy(40, 4);  cout << "* * * * * * * * * * * * * * * * * * * * *\n";
}
void MenuAdmin(){
    TextColor(14);
    cout << "\t\t\t\t\t****************MENU****************" << endl;
    cout << "\t\t\t\t\t    1. Them Employee                " << endl;
    cout << "\t\t\t\t\t    2. Xoa Employee                 " << endl;
    cout << "\t\t\t\t\t    3. Tim Employee                 " << endl;
    cout << "\t\t\t\t\t    4. Cap nhat Employee            " << endl; 
    cout << "\t\t\t\t\t    5. Hien thi thong tin Employee  " << endl;
    cout << "\t\t\t\t\t    6. Thoat                        " << endl;
    cout << "\t\t\t\t\t************************************" << endl;
}
void MenuEmployee(){
    TextColor(14);
    cout << "\t\t\t\t\t***********MENU EMPLOYEE***********" << endl;
    cout << "\t\t\t\t\t     1. Xem thong tin tai khoan    " << endl;
    cout << "\t\t\t\t\t     2. Doi password               " << endl;
    cout << "\t\t\t\t\t     3. Thoat                      " << endl;
    cout << "\t\t\t\t\t***********************************" << endl;
}
//Ma hoa mat khau
void MaHoaPassword(char* &MatKhau, char x, int size){
    x = 'a';
    size = 0;
    while(x != 13) 
    {
        x = getch(); 
                    
        if(x == 13)
        {
            break;
        }
        if(MatKhau[0] == '\0')
        {
            while(true)
            {
                x = getch();
                if(x != 8) { break; }
            }
        }
        if(x == 8) 
        {
            if(size != 0) 
            {
                MatKhau[size] = '\0';
                size--;
                cout << "\b \b";
            }
        }
        else
        {
            cout << x;
            MatKhau[size] = x;
            size++;
            Sleep(100);
            cout << "\b \b*";
        }
    }
    MatKhau[size] = '\0';
}

void Login(string &TaiKhoan, char* &MatKhau){
    TextColor(3);
    cout << "\t\t\t\t\tUser:     " << endl;
    cout << "\t\t\t\t\tPin:     ";
    TextColor(15);
    gotoxy(46, 5);
    cin >> TaiKhoan;   
    char x = 'l';
    int size = 0;
    cout << endl;
    TextColor(3);
    gotoxy(46, 6);
    TextColor(15);
    MaHoaPassword(MatKhau, x, size);
    cout << endl;
}

//kiem tra username
bool KiemTraUsernameEmployee(User* x, string Username){
    ifstream FileIn;
    FileIn.open("Employees.txt", ios_base::in);
    while (!FileIn.eof())
    {
        x = new Employees();
        x->ReadFile(FileIn);  
        if(Username == x->getUsername())
            return false;
    }
    FileIn.close();
    return true; 
}

bool DangNhapThanhCong(User* x, char* FilePath, string &SaveUsername){
    ifstream FileIn;
    FileIn.open(FilePath, ios_base::in);
    string TaiKhoan;
    char* MatKhau;
    Login(TaiKhoan, MatKhau);
    while(!FileIn.eof())
    {
        x = new User();
        x->ReadFile(FileIn);
        if(x->getUsername() + x->getPassword() == TaiKhoan + " " + MatKhau)
        {
            SaveUsername = TaiKhoan;
            return true;
        }
    }
    FileIn.close();
    return false;
}
//Them employee(Chuc nang cua Admin)
void ThemEmployee(User* x){
    string Username;
    TextColor(3);
    cout << "Nhap Username muon them: ";
    TextColor(15);
    cin >> Username;
    if(KiemTraUsernameEmployee(x, Username))
    { 
        TextColor(3);
        TextColor(15);
        string passDefault = "111111";
        char* FilePath = new char[Username.length() +1];
        strcpy(FilePath, Username.c_str());
        ofstream FileOut;
        Employees* Emp = new Employees();
        FileOut.open("Employees.txt", ios_base::app);
        FileOut << Username << ", " << passDefault;
        FileOut<<"\n";	 
        FileOut.close();
        Emp->CreateFile(FileOut, FilePath);
        Emp->Input();
        FileOut << Emp->getName() << endl << Emp->getAddress() << endl << Emp->getPhone() << endl << Emp->getEmail();
        FileOut.close();
        TextColor(12);
        cout << "Them thanh cong !" << endl;
    }
    else{
        cout << "Username da ton tai !" << "\n";
    }
}

//xoa(Chuc nang cua Admin)
void XoaEmployee(User* x, string Username){
    ifstream FileIn;
    FileIn.open("Employees.txt", ios_base::in);
    ofstream FileOut;
    FileOut.open("EmployeesCopy.txt", ios_base::out);
    int count = 0; 
    while(!FileIn.eof())
    {
        x = new Employees();
        x->ReadFile(FileIn);
        if(x->getUsername() != Username)
        {
        	if(FileIn.eof()) break;
            FileOut << x->getUsername() << "," << x->getPassword() << endl;
        }
        
        count++;
       
    }
    FileIn.close();
    FileOut.close();
    system("del Employees.txt");
    char* c = (char *)"Employees";
    x->CreateFile(FileOut, c);
    FileOut.close();
    FileIn.open("EmployeesCopy.txt", ios_base::in);
    FileOut.open("Employees.txt", ios_base::out);

	while(!FileIn.eof()){
		x= new Employees();
		x->ReadFile(FileIn);
		if(FileIn.eof()) break;
		FileOut << x->getUsername() << "," << x->getPassword() << endl;
	}
	FileIn.close();
    FileOut.close();
    x->DeleteFile(Username);
    TextColor(12);
    cout << "Xoa thanh cong !" << endl;
    system("del EmployeesCopy.txt");
}

//Tim employee(Chuc nang cua Admin)
void TimEmployee(User* x, string Username){
    ifstream FileIn;
    char* FileName = new char[Username.length() + 1];
    strcpy(FileName, Username.c_str());
    x = new Employees();
    x->OpenFile(FileIn, FileName);
    x->ReadInfomation(FileIn);
    TextColor(12);
    cout << "Thong tin Employee can tim: " << endl;
    TextColor(11);
    cout << "Ho ten: " << x->getName() << endl;
    cout << "Dia chi: " << x->getAddress() << endl;
    cout << "So dien thoai: " << x->getPhone() << endl;
    cout << "Email: " << x->getEmail(); 
    FileIn.close();  
    
}

//Xem thong tin EMPLOYEES(Chuc nang cua employee)
void XemThongTinTaiKhoan(User* x, string Username){

    ifstream FileIn;
    char* FileName = new char[Username.length() + 1];
    strcpy(FileName, Username.c_str());
    x = new Employees();
    x->OpenFile(FileIn, FileName);
    x->ReadInfomation(FileIn);
    TextColor(12);
    cout << "Thong tin tai khoan" << endl;
    TextColor(11);
    cout << "Ho ten: " << x->getName() << endl;
    cout << "Dia chi: " << x->getAddress() << endl;
    cout << "So dien thoai: " << x->getPhone() << endl;
    cout << "Email: " << x->getEmail(); 
    FileIn.close();  
}

//cap nhat employee(Chuc nang cua Admin)
void CapNhatEmployee(User *x){
    ifstream FileIn;
    ofstream FileOut;
    TextColor(3);
    cout << "Nhap Username muon cap nhat: ";
    string Username;
    TextColor(15);
    cin >> Username;
    if(!KiemTraUsernameEmployee(x, Username))
    {
        while (true)
        {
            TextColor(14);
            system("cls");
            cout << "Chon muc ban muon cap nhat: " << endl;
            cout << "1. Ho ten " << endl;
            cout << "2. Dia chi " << endl;
            cout << "3. So dien thoai " << endl;
            cout << "4. Email " << endl;
            TextColor(3);
			cout << "Lua chon: ";
            int LuaChon;
            TextColor(15);
            cin >> LuaChon;  
            char* FileName = new char[Username.length() + 1];
            strcpy(FileName, Username.c_str());
            x = new Employees();
            string Edit;
            switch(LuaChon){
				case 1:
            	{
	                TextColor(3);
	                cout << "Nhap ho ten thay doi: ";
	                cin.ignore();
	                TextColor(15);
	                getline(cin, Edit);
	                x->OpenFile(FileIn, FileName);
	                x->ReadInfomation(FileIn);   
	                FileOut.open("NoName.txt", ios_base::out);
	                FileOut << Edit << endl << x->getAddress() << endl << x->getPhone() << endl << x->getEmail();
	                FileIn.close();
	                FileOut.close();
	                x->DeleteFile(Username);
	
	                char* fileName = new char[Username.length() + 1];
	                strcpy(fileName, Username.c_str());
	                FileIn.open("NoName.txt", ios_base::in);
	                x = new Employees();
	                x->ReadInfomation(FileIn);
	                x->CreateFile(FileOut, fileName);
	                FileOut << x->getName() << endl << x->getAddress() << endl << x->getPhone() << endl << x->getEmail();
	                FileIn.close();
	                FileOut.close();
	                TextColor(12);
	                cout << "Cap nhat ho ten Employee thanh cong !" << endl;
	                x->DeleteFile("NoName");
	                break;
            	}
            	case 2:
            	{
	                TextColor(13);
	                cout << "Nhap dia chi thay doi: ";
	                cin.ignore();
	                TextColor(15);
	                getline(cin, Edit);
	                x->OpenFile(FileIn, FileName);
	                x->ReadInfomation(FileIn);   
	                FileOut.open("NoName.txt", ios_base::out);
	                FileOut << x->getName() << endl << Edit << endl << x->getPhone() << endl << x->getEmail();
	                FileIn.close();
	                FileOut.close();
	                x->DeleteFile(Username);
	
	                char *fileName = new char[Username.length() + 1];
	                strcpy(fileName, Username.c_str());
	                FileIn.open("NoName.txt", ios_base::in);
	                x = new Employees();
	                x->ReadInfomation(FileIn);
	                x->CreateFile(FileOut, fileName);
	                FileOut << x->getName() << endl << x->getAddress() << endl << x->getPhone() << endl << x->getEmail();
	                FileIn.close();
	                FileOut.close();
	                TextColor(12);
	                cout << "Cap nhat dia chi Employee thanh cong !" << endl;
	                x->DeleteFile("NoName");
	                break;
            	}
            	case 3:
            	{
	                TextColor(3);
	                cout << "Nhap so dien thoai thay doi: ";
	                cin.ignore();
	                TextColor(15);
	                getline(cin, Edit);
	                x->OpenFile(FileIn, FileName);
	                x->ReadInfomation(FileIn);   
	                FileOut.open("NoName.txt", ios_base::out);
	                FileOut << x->getName() << endl << x->getAddress() << endl << Edit << endl << x->getEmail();
	                FileIn.close();
	                FileOut.close();
	                x->DeleteFile(Username);
	
	                char* fileName = new char[Username.length() + 1];
	                strcpy(fileName, Username.c_str());
	                FileIn.open("NoName.txt", ios_base::in);
	                x = new Employees();
	                x->ReadInfomation(FileIn);
	                x->CreateFile(FileOut, fileName);
	                FileOut << x->getName() << endl << x->getAddress() << endl << x->getPhone() << endl << x->getEmail();
	                FileIn.close();
	                FileOut.close();
	                TextColor(12);
	                cout << "Cap nhat so dien thoai Employee thanh cong !" << endl;
	                x->DeleteFile("NoName");
	                break;
            	}
            	case 4:
            	{
	                TextColor(3);
	                cout << "Nhap email thay doi: ";
	                cin.ignore();
	                TextColor(15);
	                getline(cin, Edit);
	                x->OpenFile(FileIn, FileName);
	                x->ReadInfomation(FileIn);  
	                FileOut.open("NoName.txt", ios_base::out);
	                FileOut << x->getName() << endl << x->getAddress() << endl << x->getPhone() << endl << Edit;
	                FileIn.close();
	                FileOut.close();
	                x->DeleteFile(Username);
	
	                char* fileName = new char[Username.length() + 1];
	                strcpy(fileName, Username.c_str());
	                FileIn.open("NoName.txt", ios_base::in);
	                x = new Employees();
	                x->ReadInfomation(FileIn);
	                x->CreateFile(FileOut, fileName);
	                FileOut << x->getName() << endl << x->getAddress() << endl << x->getPhone() << endl << x->getEmail();
	                FileIn.close();
	                FileOut.close();
	                TextColor(12);
	                cout << "Cap nhat email Employee thanh cong !" << endl;
	                x->DeleteFile("NoName");
	                break;
            	}
			
			}
            
            TextColor(12);
            cout << "Ban co muon tiep tuc cap nhat khong ? (c/k)" << endl;
            char c;
            TextColor(15);
            cin >> c;
            if(c == 'k') 
                break;
            else
                system("cls");
        
        }
    }
    else
    {
        TextColor(12);
        cout << "Username khong ton tai! " << endl;
    }
}

//Hien thi employee(Chuc nang cua A)
void HienThiThongTinEmployee(User* x){
    ifstream FileIn;
    x = new Employees();
    FileIn.open("Employees.txt", ios_base::in);
    string strUser[100];
    int n = 0;
    while (!FileIn.eof())
    {
        x->ReadFile(FileIn);
        strUser[n] = x->getUsername();
        if(FileIn.eof()) break;
        n++;
    }
    FileIn.close();
    if(n==0){
    	cout << "Khong co thong tin!!";
    }
    else{
	    for(int i = 0; i < n; i++){
	        TextColor(12);
	        cout << "Thong tin:" << strUser[i] << endl;
	        string s = strUser[i];
	        char* FileName = new char[s.length() + 1];
	        strcpy(FileName, s.c_str());
	        x->OpenFile(FileIn, FileName);
	        x->ReadInfomation(FileIn);
	        TextColor(11);
	        cout << "Ho ten: " << x->getName() << endl;
	        cout << "Dia chi: " << x->getAddress() << endl;
	        cout << "So dien thoai: " << x->getPhone() << endl;
	        cout << "Email: " << x->getEmail() << endl;
	        FileIn.close();
	    }
	}
}
// doi password
void ThucHienDoiMatKhau(User* x, string CurrentPass, string NewPass, string SaveUsername){
    ifstream FileIn;
    ofstream FileOut;
    string s = "NoName";
    User users[100] ;
    FileIn.open("Employees.txt", ios_base::in);
    int count = 0;
    while (!FileIn.eof())
    {
        users[count].ReadFile(FileIn);
        count++;
        if(FileIn.eof()) break;
    }
    FileIn.close();
    for(int i = 0; i < count; i++) {
    	if(users[i].getUsername() == x->getUsername() &&  users[i].getPassword() ==x->getPassword()){
    		users[i].setPassword(" " + NewPass);
    		break;
		}
	}
    FileOut.open("Employees.txt", ios_base::out);
     for(int i = 0; i < count; i++) {
     	if(users[i].getUsername() == "") break;
    	FileOut << users[i].getUsername() << "," << users[i].getPassword() << endl;
	};
    TextColor(12);
    cout << "\nDoi mat khau thanh cong !";
    FileOut.close();
}

void DoiMatKhau(User *x){
    ifstream FileIn;
    ofstream FileOut;
    char* CurrentPass = new char[50]; //mật khẩu cũ
    char* NewPass = new char[50];     //mật khẩu mới
    char* ConfirmPass = new char[50]; //xác nhận mật khẩu mới
    char c;
    int size = 0;
    string Username;
    TextColor(3);
    cout << "Nhap username hien tai: ";
    TextColor(15);
    cin >> Username;
    TextColor(3);
    TextColor(3);
    cout << "Nhap password hien tai: ";
    TextColor(15);
    MaHoaPassword(CurrentPass, c, size);
    cout << "\nNhap password moi: ";
    TextColor(15);
    MaHoaPassword(NewPass, c, size);
    TextColor(3);
    cout << "\nNhap lai password moi: ";
    TextColor(15);
    MaHoaPassword(ConfirmPass, c, size);
    FileIn.open("Employees.txt", ios_base::in);
    bool XacNhan = false; 
    while(!FileIn.eof())
    {
        x = new Employees();
        x->ReadFile(FileIn);
        if(" " + (string)CurrentPass == x->getPassword() && (string)NewPass == (string)ConfirmPass)
        {   
            XacNhan = true;
            break;
        }
    }
    FileIn.close();
    if(XacNhan == false)
    {
        TextColor(12);
        cout << "\nThong tin ban nhap khong chinh xac, ban vui long kiem tra lai !" << endl;
    }
    else
    {
        ThucHienDoiMatKhau(x, CurrentPass, NewPass, Username);
    }
}

int main(){
    while (true)
	{	
        int ChucNang, choiseAccess;
		system("cls");
		TextColor(14);
		gotoxy(40, 2);  cout << "* * * * * * * * * * * * * * * * * * * * *\n";
		gotoxy(40, 3);  cout << "*           LUA CHON PHAN QUYEN         *\n";
		gotoxy(40, 4);  cout << "* * * * * * * * * * * * * * * * * * * * *\n";
		TextColor(10);
		gotoxy(48, 5);  cout << "|1| Administrators";
		gotoxy(48, 6);  cout << "|2| Employee";
		gotoxy(48, 7);  cout << "|3| Exit";
	    TextColor(3);
	    gotoxy(41, 8);  cout << "Lua Chon:";
		gotoxy(51,8);	
		TextColor(15); cin >> choiseAccess;
        string SaveUsername;
        switch(choiseAccess){
        	case 1:{
	            while (true)
	            {
	                system("cls");
	                DangNhapAdmin();
	                ifstream FileIn;
	                ofstream FileOut;
	                User* x = NULL;
	                bool Exit = false;
	                if(DangNhapThanhCong(x, (char *)"Administrators.txt", SaveUsername))
	                {
	                    while (true)
	                    {
	                        system("cls");
	                        MenuAdmin();
	                        TextColor(3);
	                        cout << "Moi ban chon chuc nang: ";
	                        TextColor(15);
	                        cin >> ChucNang;
	                        if(ChucNang == 1)
	                        {
	                            ThemEmployee(x);
	                            getch();
	                        }
	                        else if(ChucNang== 2)
	                        {
	                            string Username;
	                            TextColor(3);
	                            system("cls");
	                            cout << "Nhap Username muon xoa: ";
	                            TextColor(15);
	                            cin >> Username;
	                            FileIn.open("Employees.txt", ios_base::in);
	                            bool TimThay = false; // check user nhap vao co trong file.txt
	                            while (!FileIn.eof())
	                            {
	                                x = new Employees();
	                                x->ReadFile(FileIn);
	                                if(x->getUsername() == Username)
	                                {
	                                    TimThay = true;
	                                    break;
	                                }               
	                            }
	                            FileIn.close();
	                            if(TimThay == false)
	                            {
	                                TextColor(12);
	                                cout << "Khong tim thay " << Username << " de xoa !" << endl;
	                                getch();
	                            }
	                            else
	                            {
	                                XoaEmployee(x, Username);
	                                getch();
	                            }
	                            FileOut.close();
	                        }
	                        else if(ChucNang == 3)
	                        {
	                            string Username;
	                            TextColor(3);
	                            cout << "Nhap Username muon tim: ";
	                            TextColor(15);
	                            cin >> Username;
	                            FileIn.open("Employees.txt", ios_base::in);
	                            bool TimThay = false;
	                            while (!FileIn.eof())
	                            {
	                                x = new Employees();
	                                x->ReadFile(FileIn);
	                                if(x->getUsername() == Username)
	                                {
	                                    TimThay = true;
	                                    break;
	                                }               
	                            }
	                            FileIn.close();
	                            if(TimThay == false)
	                            {
	                                TextColor(12);
	                                cout << "Khong tim thay Employee !"<< endl;
	                                getch();
	                            }
	                            else
	                            {
	                                TimEmployee(x, Username);
	                                getch();
	                            }
	                        }
	                        else if(ChucNang == 4)
	                        {
	                            CapNhatEmployee(x);
	                            getch();
	                        }
	                        else if(ChucNang == 5)
	                        {
	                            HienThiThongTinEmployee(x);
	                            getch();
	                        }
	                        else if(ChucNang == 6)
	                        {
	                            Exit = true;
	                            break;
	                        }
	                        else
	                        {
	                            TextColor(12);
	                            cout << "Lua chon khong hop le ! Ban vui long chon lai !!!" << endl;
	                            getch();
	                        }
	                    }
	                    if(Exit == true) break;
	                }
	                else
	                {
	                    TextColor(12);
	                    cout << "Sai tai khoan hoac mat khau!" << endl;
	                    getch();
	                }
	            }      
				break;  
        	}
        	case 2:
        	{
	            int count = 0; // dem so luong, neu count > 3 break
	            bool Exit = false;
	            while(true)
	            {
	                system("cls");
	                DangNhapEmployees();
	                ifstream FileIn;
	                User* x = NULL;
	                int n = 0;
	                if(DangNhapThanhCong(x, (char *)"Employees.txt", SaveUsername))
	                {
	                    TextColor(12);
	                    cout << "Dang nhap thanh cong !" << endl;
	                    char* CurrentPass = new char[50];
	                    char* NewPass = new char[50];
	                    char c = 'a';
	                    int size = 0;
	                    bool XacNhan = false; //kiem tra mat khau nhap ve hop le hay ko??
	                    ifstream FileIn;
	                    ofstream FileOut;
	                    TextColor(3);
	                    cout << "Ban vui long doi mat khau truoc khi su dung chuong trinh !" << endl;
	                    getch();
	                    while(true)
	                    {
	                        system("cls");
	                        TextColor(3);
	                        cout << "Nhap mat khau hien tai: ";
	                        TextColor(15);
	                        MaHoaPassword(CurrentPass, c, size);
	                        FileIn.open("Employees.txt", ios_base::in);
	                        while(!FileIn.eof())
	                        {
	                            x = new Employees();
	                            x->ReadFile(FileIn);
	                            if((SaveUsername == x->getUsername()) && (" " + (string)CurrentPass == x->getPassword())) 
	                            {   
	                                XacNhan = true;
	                                break;
	                            }
	                        }
	                        FileIn.close();
	                        if(XacNhan == false)
	                        {
	                            TextColor(12);
	                            cout << "\nMat khau hien tai khong chinh xac! " << endl;
	                            getch();
	                        }
	                        else if(XacNhan==true)
	                        {
	                            TextColor(3);
	                            cout << "\nNhap mat khau moi: ";
	                            TextColor(15);
	                            MaHoaPassword(NewPass, c, size);
	                            if((string)CurrentPass == (string)NewPass)
	                            {
	                                TextColor(12);
	                                cout << "\nTrung mat khau roi ! Ban vui long nhap lai !!!" << endl;
	                                getch();
	                            }
	                            else
	                            {
	                                ThucHienDoiMatKhau(x, (string)CurrentPass, (string)NewPass, SaveUsername);
	                                getch();
	                                break;
	                            }
	                        }          
	                    }
	                    while (true)
	                    {
	                        system("cls");
	                        MenuEmployee();
	                        TextColor(3);
	                        cout << "Moi ban chon chuc nang: ";
	                        TextColor(15);
	                        cin >> ChucNang;
	                        if(ChucNang==1){
	                            XemThongTinTaiKhoan(x, SaveUsername);
	                            getch();
	                        }
		                    else if(ChucNang==2){
	                            DoiMatKhau(x);
	                            getch();
	                        }
		                    else if(ChucNang==3){
	                            Exit = true;
	                            break;
	                        }
		                    else{
	                            TextColor(12);
	                            cout << "Lua chon khong hop le ! Ban vui long chon lai !!!" << endl;
	                            getch();
							}
	                    }
	                }
	                else
	                {
	                    count++;
	                    TextColor(12);
	                    cout << "Sai tai khoan hoac mat khau!" << endl;
	                }
	                if(count == 3) exit(0);
	                if(Exit == true) break;
	                getch();
	            }
	            break;
	        }	        
	        case 3:{
				exit(0);
				break;
			}
        	default:
        	{
	            TextColor(12);
	            cout << "Lua chon khong hop le!" << endl;
	            getch();
	            break;
        	}
    	}   
    }
	system("pause");
}


