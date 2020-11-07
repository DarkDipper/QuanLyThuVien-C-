#include <iostream>
#include <bits/stdc++.h>
#include <ctime>
#include <windows.h>
#include <conio.h>
#include <stdexcept>
#include <winuser.h>
#include <ctime>
using namespace std;
//
//      Gọi Hàm Trước
//
void formMenu();
void formMenuBook();
bool form_LogOut();
void form_LogIn();
void formMenuPhieuMuon();
bool formXacNhan();
void formXoaSach();
void formThongBaoXoaThanhCong();
void formThemSach();
void LuuSach();
void formThemPhieuMuon();
void formTraSach();
//
//        Class và struct
//
class Sach{
public:
    string strMaSach,strTenSach,strTacGia,strNhaXuatBan;
    int iGiaBan,iNamPhatHanh,iSoTrang,iTinhTrangSach;
    string strNgayNhapKho;
    Sach(string strMaSach,string strTenSach,string strTacGia,string strNhaXuatBan,int iGiaBan,int iNamPhatHanh,int iSoTrang,int iTinhTrangSach,string strNgayNhapKho){
        this->strMaSach=strMaSach;
        this->strTenSach=strTenSach;
        this->strTacGia=strTacGia;
        this->strNhaXuatBan=strNhaXuatBan;
        this->iGiaBan=iGiaBan;
        this->iNamPhatHanh=iNamPhatHanh;
        this->iSoTrang=iSoTrang;
        this->iTinhTrangSach=iTinhTrangSach;
        this->strNgayNhapKho=strNgayNhapKho;
    }
    void operator = (int i){
        this->strMaSach="L.000";
        this->strTenSach=" ";
        this->strTacGia=" ";
        this->strNhaXuatBan=" ";
        this->iGiaBan=0;
        this->iNamPhatHanh=0;
        this->iSoTrang=0;
        this->iTinhTrangSach=0;
    }
    Sach(){
        this->strMaSach="L.000";
        this->strTenSach=" ";
        this->strTacGia=" ";
        this->strNhaXuatBan=" ";
        this->iGiaBan=0;
        this->iNamPhatHanh=0;
        this->iSoTrang=0;
        this->iTinhTrangSach=0;
    }
    bool operator <(Sach X){
        if(strMaSach<X.strMaSach){
            return true;
        }
        return false;
    }
    bool operator <(string X){
        if(strMaSach<X){
            return true;
        }
        return false;
    }
    bool operator ==(Sach X){
        if(strMaSach==X.strMaSach){
            return true;
        }
        return false;
    }
    bool operator ==(string X){
        if(strMaSach==X){
            return true;
        }
        return false;
    }
    void operator =(Sach X){
        this->strMaSach=X.strMaSach;
        this->strTenSach=X.strTenSach;
        this->strTacGia=X.strTacGia;
        this->strNhaXuatBan=X.strNhaXuatBan;
        this->iGiaBan=X.iGiaBan;
        this->iNamPhatHanh=X.iNamPhatHanh;
        this->iSoTrang=X.iSoTrang;
        this->iTinhTrangSach=X.iTinhTrangSach;
        this->strNgayNhapKho=X.strNgayNhapKho;
    }
};
class BanDoc {
public:
    string strMaBanDoc,strHoTen;
    string strNgayDangKy;
    BanDoc(string strMaBanDoc,string strHoTen,string strNgayDangKy){
        this->strMaBanDoc=strMaBanDoc;
        this->strHoTen=strHoTen;
        this->strNgayDangKy=strNgayDangKy;
    }
    bool operator <(BanDoc X){
        if(strMaBanDoc<X.strMaBanDoc){
            return true;
        }
        return false;
    }
    void operator =(int i){
        this->strHoTen=" ";
        this->strMaBanDoc="M.000";
        this->strNgayDangKy=" ";
    }
    BanDoc(){
        this->strHoTen=" ";
        this->strMaBanDoc="M.000";
        this->strNgayDangKy=" ";
    }
    void operator =(BanDoc X){
        this->strMaBanDoc=X.strMaBanDoc;
        this->strHoTen=X.strHoTen;
        this->strNgayDangKy=X.strNgayDangKy;
    }
    bool operator <(string X){
        if(strMaBanDoc<X){
            return true;
        }
        return false;
    }
    bool operator ==(string X){
        if(strMaBanDoc==X){
            return true;
        }
        return false;
    }
    bool operator ==(BanDoc X){
        if(strMaBanDoc==X.strMaBanDoc){
            return true;
        }
        return false;
    }
};
class PhieuMuonSach{
    public:
    int iTinhTrangPhieuMuon,iSoSachMuon;
    vector<string>strMaSach;
    string strMaBanDoc;
    string strSoPhieuMuon,strNgayMuon,strNgayTra;
    PhieuMuonSach(string strSoPhieuMuon,string strNgayMuon,string strNgayTra,string strMaBanDoc,vector<string> strMaSach,int iTinhTrangPhieuMuon){
        this->iTinhTrangPhieuMuon=iTinhTrangPhieuMuon;
        this->strMaSach=strMaSach;
        this->strMaBanDoc=strMaBanDoc;
        this->strSoPhieuMuon=strSoPhieuMuon;
        this->strNgayMuon=strNgayMuon;
        this->strNgayTra=strNgayTra;
    }
    PhieuMuonSach(){
        this->iTinhTrangPhieuMuon=NULL;
        this->strMaBanDoc=" ";
        this->strSoPhieuMuon="G.000";
        this->strNgayMuon=" ";
        this->strNgayTra=" ";
    }
    void operator =(int i){
        this->iTinhTrangPhieuMuon=NULL;
        this->strMaBanDoc=" ";
        this->strSoPhieuMuon="G.000";
        this->strNgayMuon=" ";
        this->strNgayTra=" ";
    }
    void operator =(PhieuMuonSach X){
        this->iTinhTrangPhieuMuon=X.iTinhTrangPhieuMuon;
        this->strMaSach=X.strMaSach;
        this->strMaBanDoc=X.strMaBanDoc;
        this->strSoPhieuMuon=X.strSoPhieuMuon;
        this->strNgayMuon=X.strNgayMuon;
        this->strNgayTra=X.strNgayTra;
    }
    bool operator <(string X){
        if(strSoPhieuMuon<X){
            return true;
        }
        return false;
    }
    bool operator <(PhieuMuonSach X){
        if(strSoPhieuMuon<X.strSoPhieuMuon){
            return true;
        }
        return false;
    }
    bool operator ==(PhieuMuonSach X){
        if(strSoPhieuMuon==X.strSoPhieuMuon){
            return true;
        }
        return false;
    }
    bool operator ==(string X){
        if(strSoPhieuMuon==X){
            return true;
        }
        return false;
    }
};
struct Admin{
	string strId;
	string strPass;
};
//
//        Nút(Node) và Skip list
//
template <class type>
struct Node{
    type key;
    Node **forward;
    Node(type key,int level){
        this->key=key;
        forward=new Node*[level+1];
        memset(forward,0,sizeof(Node*)*(level+1));
    }
    Node(int key,int level){
        this->key=0;
        forward=new Node*[level+1];
        memset(forward,0,sizeof(Node*)*(level+1));
    }
};
template <class TYPE>
class SkipList{
    int iLevelMax;
    int iLevel,iSoLuong;
    Node<TYPE>* header;
public:
    SkipList(int iLevelMax){
        this->iLevelMax=iLevelMax;
        iLevel=0;
        header=new Node<TYPE>(-1,iLevelMax);
        iSoLuong=0;
    }
    int GetSoLuong(){
        return iSoLuong;
    }
    TYPE operator[](int i){
        int x=-1;
        Node<TYPE>* y=header;
        while(x!=i){
            y=y->forward[0];
            x++;
        }
        return y->key;
    }
    int RandomLevel(){
        float dem=(float)rand()/RAND_MAX;
        int level=0;
        while(dem<0.5&&level<iLevelMax){
            level++;
            dem=(float)rand()/RAND_MAX;
        }
        return level;
    }
    Node<TYPE>* CreateNode(TYPE x,int level){
        Node<TYPE>*n=new Node<TYPE>(x,level);
        return n;
    }
    void insertNode(TYPE x){
        Node<TYPE> *hien_tai=header;
        Node<TYPE> *cap_nhat[iLevelMax+1];
        memset(cap_nhat,NULL,sizeof(Node<TYPE>*)*(iLevelMax+1));
        for(int i=iLevel;i>=0;i--){
            while(hien_tai->forward[i]!=NULL&&hien_tai->forward[i]->key<x){
                hien_tai=hien_tai->forward[i];
            }
            cap_nhat[i]=hien_tai;
        }
        hien_tai=hien_tai->forward[0];
        if(hien_tai==NULL||!(hien_tai->key==x)){
            int iRlevel=RandomLevel();
            if(iRlevel>iLevel){
                for(int i=iLevel+1;i<=iRlevel;i++){
                    cap_nhat[i]=header;
                }
                iLevel=iRlevel;
            }
            Node<TYPE>* moi=CreateNode(x,iRlevel);
            for(int i=0;i<=iRlevel;i++){
                moi->forward[i]=cap_nhat[i]->forward[i];
                cap_nhat[i]->forward[i]=moi;
            }
            iSoLuong++;
        }
    }
    TYPE SearchNode(string x){
        Node<TYPE>* hien_tai=header;
        for(int i=0;i<iSoLuong;i++){
            if(hien_tai->forward[0]->key==x){
                hien_tai=hien_tai->forward[0];
                break;
            }
            hien_tai=hien_tai->forward[0];

        }
        return hien_tai->key;
    }
    void DeleteNode(TYPE x){
        Node<TYPE>* hien_tai=header;
        Node<TYPE>* cap_nhat[iLevelMax];
        memset(cap_nhat,NULL,sizeof(Node<TYPE>*)*(iLevelMax+1));
        for(int i=iLevel;i>=0;i--){
            while(hien_tai->forward[i]!=NULL&&hien_tai->forward[i]->key<x){
                hien_tai=hien_tai->forward[i];
            }
            cap_nhat[i]=hien_tai;
        }
        hien_tai=hien_tai->forward[0];
        if(hien_tai!=NULL&&hien_tai->key==x){
            for(int i=0;i<=iLevel;i++){
                cap_nhat[i]->forward[i]=hien_tai->forward[i];
            }
            hien_tai=NULL;
            delete hien_tai;
            while(iLevel>0&&header->forward[iLevel]==NULL){
                iLevel--;
            }
            iSoLuong--;
        }
    }
};
//
//        Giao diện và chức năng
//
void goTo(SHORT posX,SHORT posY,int color){
    SetConsoleOutputCP(65001);
    HANDLE hStdout=GetStdHandle(STD_OUTPUT_HANDLE);
    HANDLE  hConsole,Aconsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
    COORD Position;
    Position.X=posX;
    Position.Y=posY;
    SetConsoleCursorPosition(hStdout,Position);
}
void outPut(int x,int y,int color,string text){
    goTo(x,y,color);
    cout<<""+text;
}
string layNgay(int x){
    time_t hien_tai;
    tm* tm;
    char date[100];
    time(&hien_tai);
    hien_tai += 60 * 60 * 24 * x;
    tm=localtime(&hien_tai);
    strftime(date,sizeof(date),"%d/%m/%Y",tm);
    string ngay=date;
    return ngay;
}
bool is_number(const std::string &s){
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it))
        ++it;
    return !s.empty() && it == s.end();
}
bool kiemTraTiengViet(string x){
    for(int i=0;i<x.size();i++){
        if(!(97<=(int)x[i]&&(int)x[i]<=122)){
            return true;
        }
    }
    return false;
}
bool kiemTraNamPhatHanh(string x){
    int y=stoi(x);
    string a=layNgay(0),b="";
    for(int i=a.size()-1;i>=a.size()-4;i--){
        b = a[i] + b;
    }
    int z = stoi(b);
    return (y<z);
}
bool KiemTraAdmin(string strTenDangNhap,string strMatKhau){
    Admin admin;
    bool check=false;
    ifstream inp;
	 inp.open("Admin.txt");
	 if(inp.is_open()){
	 	inp>>admin.strId>>admin.strPass;
        if(strTenDangNhap==admin.strId&&strMatKhau==admin.strPass){
            check=true;
        }
	 }
	 inp.close();
	 return check;
}
string TinhKhoangCach(string strChuoi){
    string strSum="";
    for(int i=0;i<strChuoi.size();i++){
        strSum+=" ";
    }
    return strSum;
}
bool nhap_du_lieu(string& strUserName,string& strPassWord){
    bool ok=false;
    while(!ok){
        ok=true;
        goTo(48,6,7);
        char e;
        strUserName.clear();
        while (true){
            e =_getch();
            if (e == 27){
                if (form_LogOut()){
                    exit(0);
                }
                else{
                    system("cls");
                    form_LogIn();
                }
            }else if (e == '\b' && strUserName.size() != 0){
                cout << "\b \b";
                strUserName.erase(strUserName.end() - 1);
            }else if (e == '\r'){
                break;
            }else if (e != '\b'){
                cout << e;
                strUserName.push_back(e);
            }
        }
        strPassWord.clear();
        goTo(52,8,7);
        while (true){
            e =_getch();
            if (e == 27){
                if (form_LogOut()){
                    exit(0);
                }
                else{
                    system("cls");
                    form_LogIn();
                }
            }else if (e == '\b' && strPassWord.size() != 0){
                cout << "\b \b";
                strPassWord.erase(strPassWord.end() - 1);
            }else if (e == '\r'){
                break;
            }else if (e != '\b'){
                cout << "*";
                strPassWord.push_back(e);
            }
        }
        for(int i=0;i<strPassWord.size();i++){
            if(!(strPassWord[i]>='!'&&strPassWord[i]<='~')){
                outPut(42,10,4,"Sai tên đăng nhập hoặc mật khẩu");
                ok=false;
            }
        }
        if(!KiemTraAdmin(strUserName,strPassWord)){
            outPut(42,10,4,"Sai tên đăng nhập hoặc mật khẩu");
            ok=false;
        }
        if(ok){
            continue;
        }
        goTo(48,6,7);
        cout<<"\b "+TinhKhoangCach(strUserName)+"\b";
        goTo(52,8,7);
        cout<<"\b "+TinhKhoangCach(strPassWord)+"\b";
    }
    return true;
}
void layBanDoc(SkipList<BanDoc>& DS){
    BanDoc X;
    ifstream inp;
    inp.open("DocGia.txt");
    if(inp.is_open()){
        while(inp>>X.strMaBanDoc){
            inp.ignore();
            getline(inp,X.strHoTen);
            getline(inp,X.strNgayDangKy);
            DS.insertNode(X);
        }
    }
    inp.close();
}
void layPhieuMuon(SkipList<PhieuMuonSach>& DS){
    ifstream inp;
    inp.open("PhieuMuon.txt");
    if(inp.is_open()){
        string MaSach;
        while(inp>>MaSach){
            PhieuMuonSach X;
            X.strSoPhieuMuon=MaSach;
            inp>>X.iSoSachMuon;
            for(int i=0;i<X.iSoSachMuon;i++){
                string y;
                inp>>y;
                X.strMaSach.push_back(y);
            }
            inp>>X.strMaBanDoc;
            inp>>X.strNgayMuon;
            inp>>X.strNgayTra;
            inp>>X.iTinhTrangPhieuMuon;
            DS.insertNode(X);
        }
    }
    inp.close();
}
//
//  Hàm lấy sách và form hiển thị thông tin sách
//
void LaySach(SkipList<Sach>& X){
    string strMa,strTen,strTacGia,strNXB,strGia,strTrang,strNAMPH,strTrangThai,strNhapKho;
	ifstream inp;
	inp.open("TenSach.txt");
	if(inp.is_open()){
	 	while(inp>>strMa){
	 			inp.ignore();
	 			getline(inp,strTen);
	 			getline(inp,strTacGia);
	 			getline(inp,strNXB);
	 			inp>>strGia;
	 			inp>>strNAMPH;
	 			inp>>strTrang;
	 			inp>>strTrangThai;
	 			inp>>strNhapKho;
	 		Sach Y(strMa,strTen,strTacGia,strNXB,stoi(strGia),stoi(strNAMPH),stoi(strTrang),stoi(strTrangThai),strNhapKho);
	 		X.insertNode(Y);
	 	}
	 }
	 inp.close();
}
void xuatDong(string strMa,string strTen, string strTacGia,string strNXB,string strGia,string strTrang,string strNamPH,string strTinhTrang,string strNhapKho,int dem){
	outPut(0,dem,7,"|");
	outPut(1,dem,12,strMa);
	outPut(6,dem,7,"|");
	outPut(8,dem,10,strTen);
	outPut(43,dem,7,"|");
	outPut(45,dem,2,strTacGia);
	outPut(64,dem,7,"|");
	outPut(66,dem,11,strNXB);
	outPut(81,dem,7,"|");
	outPut(83,dem,6,strGia);
	outPut(93,dem,7,"|");
	outPut(95,dem,13,strNamPH);
	outPut(99,dem,7,"|");
	outPut(101,dem,14,strTrang);
	outPut(106,dem,7,"|");
	outPut(108,dem,12,strTinhTrang);
	outPut(109,dem,7,"|");
	outPut(110,dem,14,strNhapKho);
	outPut(121,dem,7,"|");
}
void HienThiThongTinSach(SkipList<Sach> DSSach){
	 outPut(0,0,3,"                                                  DANH SÁCH SÁCH                                                       ");
	 outPut(0,1,7,"| Mã  |             Tên sách               |       Tác giả      |  Nhà xuất bản  |    Giá    |Trang|NamPH |TT| Nhập kho|");
	 outPut(0,2,7,"########################################################################################################################");
	 Sach Y;
	 int dem=3;
	 for(int i=0;i<DSSach.GetSoLuong();i++){
        Y=DSSach[i];
        xuatDong(Y.strMaSach,Y.strTenSach,Y.strTacGia,Y.strNhaXuatBan,to_string(Y.iGiaBan),to_string(Y.iSoTrang),to_string(Y.iNamPhatHanh),to_string(Y.iTinhTrangSach),Y.strNgayNhapKho,dem);
        dem++;
	 }
	 outPut(0,0,0," ");
	 char key;
	 while(true){
        key=_getch();
        if(key=='\b'){
            system("cls");
            formMenuBook();
        }
	 }

}
void CapNhatSach(SkipList<Sach> DS){
    remove("TenSach.txt");
    ofstream opn;
    opn.open("TenSach.txt");
    for(int i=0;i<DS.GetSoLuong();i++){
        opn<<DS[i].strMaSach<<"\n";
        opn<<DS[i].strTenSach<<"\n";
        opn<<DS[i].strTacGia<<"\n";
        opn<<DS[i].strNhaXuatBan<<"\n";
        opn<<to_string(DS[i].iGiaBan)<<"\n";
        opn<<to_string(DS[i].iSoTrang)<<"\n";
        opn<<to_string(DS[i].iNamPhatHanh)<<"\n";
        opn<<to_string(DS[i].iTinhTrangSach)<<"\n";
        opn<<DS[i].strNgayNhapKho<<"\n";
    }
    opn.close();
    return;
}
void LuuSach(SkipList<Sach> DS){
	remove("TenSach.txt");
    ofstream opn;
    opn.open("TenSach.txt");
    for(int i=0;i<DS.GetSoLuong();i++){
        opn<<DS[i].strMaSach<<"\n";
        opn<<DS[i].strTenSach<<"\n";
        opn<<DS[i].strTacGia<<"\n";
        opn<<DS[i].strNhaXuatBan<<"\n";
        opn<<to_string(DS[i].iGiaBan)<<"\n";
        opn<<to_string(DS[i].iSoTrang)<<"\n";
        opn<<to_string(DS[i].iNamPhatHanh)<<"\n";
        opn<<to_string(DS[i].iTinhTrangSach)<<"\n";
        opn<<DS[i].strNgayNhapKho<<"\n";
    }
    opn.close();
    return;
}
void ThayDoiTinhTrangSach(string strMaSach,int y){
    SkipList<Sach> DS(20);
    LaySach(DS);
    Sach X=DS.SearchNode(strMaSach);
    DS.DeleteNode(X);
    CapNhatSach(DS);
    SkipList<Sach> DS2(20);
    LaySach(DS2);
    X.iTinhTrangSach = y;
    DS2.insertNode(X);
    CapNhatSach(DS2);
}
bool KiemTraTinhTrangSach(string strMa){
    SkipList<Sach> DS(20);
    LaySach(DS);
    Sach X=DS.SearchNode(strMa);
    if(X.iTinhTrangSach==0){
        return true;
    }
    return false;
}
bool kiemTraMaSach(string x){
    if(x.size()!=5){
        return false;
    }else if(x[0]!='L'||x[1]!='.'){
        return false;
    }
    for(int i=2;i<x.size();i++){
        if(!is_number(string(1,x[i]))){
            return false;
        }
    }
    return true;
}
//
//  Hàm Lấy phiếu mượn và form hiển thị thông tin phiếu mượn
//
bool kiemTraMaPhieuMuon(string x){
    if (x.size() != 5){
        return false;
    }else if (x[0] != 'G' || x[1] != '.'){
        return false;
    }
    for (int i = 2; i < x.size(); i++){
        if (!is_number(string(1,x[i]))){
            return false;
        }
    }
    return true;
}
void TachMaSach(vector<string>& vDanhSachMaSachMuon,string strDanhSachMaSachMuon){
	string strMaSach="";
	for(int i=0;i<strDanhSachMaSachMuon.size();i++){
		if(strDanhSachMaSachMuon[i]!=',')  strMaSach+=strDanhSachMaSachMuon[i];
		else{
			vDanhSachMaSachMuon.push_back(strMaSach);
			strMaSach="";
		}
	}
	if(strMaSach!="") vDanhSachMaSachMuon.push_back(strMaSach);
}
void hienThiPhieuMuon(string strMaPhieuMuon,vector<string>vDanhSachMaSachMuon,string strMaBanDoc,string strNgayMuon,string strNgayTra,int iTrangThaiPhieuMuon,int& iDem,int iSoSachMuon){
	outPut(25,iDem,7,"|");
	outPut(26,iDem,10,strMaPhieuMuon);
	for(int i=0;i<vDanhSachMaSachMuon.size();i++){
		outPut(36,iDem+i,7,"|");
		outPut(25,iDem+i,7,"|");
		outPut(38,iDem+i,14,vDanhSachMaSachMuon[i]);
		outPut(46,iDem+i,7,"|");
		outPut(59,iDem+i,7,"|");
		outPut(71,iDem+i,7,"|");
		outPut(84,iDem+i,7,"|");
		outPut(95,iDem+i,7,"|");
	}
	outPut(25,iDem+iSoSachMuon,7,"-----------------------------------------------------------------------");
	outPut(48,iDem,11,strMaBanDoc);
	outPut(61,iDem,7,strNgayMuon);
	outPut(73,iDem,14,strNgayTra);
	char buffer [2];
	outPut(87,iDem,9,itoa(iTrangThaiPhieuMuon,buffer,10));
	iDem+=iSoSachMuon;
}
void CapNhatPhieuMuon(SkipList<PhieuMuonSach> DS){
    remove("PhieuMuon.txt");
    ofstream MyFile;
    MyFile.open("PhieuMuon.txt");
    for (int i = 0; i < DS.GetSoLuong(); i++)
    {
        MyFile << DS[i].strSoPhieuMuon << endl;
        MyFile <<DS[i].strMaSach.size() << endl;
        for (int j = 0; j < DS[i].strMaSach.size(); j++)
        {
            MyFile << DS[i].strMaSach[j] << endl;
        }
        MyFile << DS[i].strMaBanDoc << endl;
        MyFile << DS[i].strNgayMuon << endl;
        MyFile << DS[i].strNgayTra << endl;
        MyFile << DS[i].iTinhTrangPhieuMuon << endl;
    }
    MyFile.close();
}
void LuuPhieuMuon(PhieuMuonSach X){
		// Create and open a text file
	ofstream MyFile;
	MyFile.open("PhieuMuon.txt",ios::out|ios::app);
	// Write to the file
	MyFile <<X.strSoPhieuMuon<<endl;
	MyFile<<X.strMaSach.size()<<endl;
	for(int i=0;i<X.strMaSach.size();i++){
		MyFile <<X.strMaSach[i]<<endl;
	}
	MyFile <<X.strMaBanDoc<<endl;
	MyFile <<X.strNgayMuon<<endl;
	MyFile <<X.strNgayTra<<endl;
	MyFile <<X.iTinhTrangPhieuMuon<<endl;
	MyFile.close();
}
void ThayDoiTinhTrangPhieuMuon(string strPhieuMuon){
    SkipList<PhieuMuonSach> DS(20);
    layPhieuMuon(DS);
    vector<PhieuMuonSach> DS2;
    for(int i=0;i<DS.GetSoLuong();i++){
        DS2.push_back(DS[i]);
    }
    SkipList<PhieuMuonSach> DS3(20);
    for(int i=0;i<DS2.size();i++){
        if(DS2[i].strSoPhieuMuon==strPhieuMuon){
            DS2[i].iTinhTrangPhieuMuon=0;
        }
        DS3.insertNode(DS2[i]);
    }
    CapNhatPhieuMuon(DS3);
}
void LayThongTinPhieuMuon(){
    outPut(25, 0, 2, "                         DANH SÁCH PHIẾU MƯỢN");
    outPut(25, 1, 7, "| Mã phiếu | Mã sách | Mã bạn đọc | Ngày mượn | Ngày trả   |Trạng thái|");
    outPut(25, 2, 7, "#######################################################################");
    string strMaSach,strMaPhieuMuon;
	int iDem=3;
	ifstream inp;
	inp.open("PhieuMuon.txt");
	while(inp>>strMaPhieuMuon){
        PhieuMuonSach Y;
        Y.strSoPhieuMuon=strMaPhieuMuon;
		inp>>Y.iSoSachMuon;
		for(int i=0;i<Y.iSoSachMuon;i++){
			inp>>strMaSach;
			Y.strMaSach.push_back(strMaSach);
		}
		inp>>Y.strMaBanDoc;
		inp>>Y.strNgayMuon;
		inp>>Y.strNgayTra;
		inp>>Y.iTinhTrangPhieuMuon;
		hienThiPhieuMuon(Y.strSoPhieuMuon,Y.strMaSach,Y.strMaBanDoc,Y.strNgayMuon,Y.strNgayTra,Y.iTinhTrangPhieuMuon,iDem,Y.iSoSachMuon);

		iDem++;
	}
	outPut(0,0,0," ");
	 char key;
	 while(true){
        key=_getch();
        if(key=='\b'){
            system("cls");
            formMenuPhieuMuon();
        }
	 }
}
//
// Hàm liên quan tới form
//

void formMenu(){
    int iMau[]{144,7};
    int iDem=1;
    char key;
    outPut(40,10,11,"* * * * * * * * * * * * * * * * * * * *");
    outPut(40,11,11,"*");outPut(78,11,11,"*");
    outPut(40,12,11,"*                                     *");
    outPut(40,13,11,"*");outPut(78,13,11,"*");
    outPut(40,14,11,"*                                     *");
    outPut(40,15,11,"*");outPut(78,15,11,"*");
    outPut(40,16,11,"*                                     *");
    outPut(40,17,11,"* * * * * * * * * * * * * * * * * * * *");
    outPut(59,11,6,"MENU");
    while(true){
        outPut(55,13,iMau[0],"Quản Lý Sách");
        outPut(52,15,iMau[1],"Quản Lý Phiếu Mượn");
        key=_getch();
        if(key=='\r'){
            if(iDem==1){
                outPut(0,0,0," ");
                system("cls");
                formMenuBook();
                break;
            }else if(iDem==2){
                outPut(0,0,0," ");
                system("cls");
                formMenuPhieuMuon();
                break;
            }
        }else if(key=='\b'){
            outPut(0,0,0," ");
            system("cls");
            if(!form_LogOut()){
                outPut(0,0,0," ");
                system("cls");
                formMenu();
            }else{
                exit(0);
            }
        }
        if(key==72&&iDem==2){
            iDem--;
        }
        if(key==80&&iDem==1){
            iDem++;
        }
        iMau[0]=7;iMau[1]=7;
        if(iDem==1){
            iMau[0]=144;
        }
        if(iDem==2){
            iMau[1]=144;
        }
    }
}
void formMenuBook(){
    SkipList<Sach> DSSach(20);
    LaySach(DSSach);
    outPut(40,10,11,"* * * * * * * * * * * * * * * * * * * *");
    outPut(40,11,11,"*");outPut(78,11,11,"*");
    outPut(40,12,11,"*                                     *");
    outPut(40,13,11,"*");outPut(78,13,11,"*");
    outPut(40,14,11,"*                                     *");
    outPut(40,15,11,"*");outPut(78,15,11,"*");
    outPut(40,16,11,"*                                     *");
    outPut(40,17,11,"*");outPut(78,17,11,"*");
    outPut(40,18,11,"*                                     *");
    outPut(40,19,11,"* * * * * * * * * * * * * * * * * * * *");
    outPut(55,11,6,"QUẢN LÝ SÁCH");
    int iMau[]={144,7,7};
    int iDem=1;
    char key;
    while(true){
        outPut(50,13,iMau[0],"Hiển thị thông tin sách");
        outPut(50,15,iMau[1],"Thêm Sách");
        outPut(50,17,iMau[2],"Xóa Sách");
        key=_getch();
        if(key==72&&(iDem>=2&&iDem<=3)){
            iDem--;
        }
        if(key==80&&(iDem>=1&&iDem<=2)){
            iDem++;
        }
        if(key=='\r'){
            if(iDem==1){
                system("cls");
                HienThiThongTinSach(DSSach);
                break;
            }else if(iDem==3){
                goTo(0,0,0);
                system("cls");
                formXoaSach();
                break;
            }else if(iDem==2){
                outPut(0,0,0," ");
                system("cls");
                formThemSach();
            }
        }else if(key=='\b'){
            outPut(0,0,0," ");
            system("cls");
            formMenu();
        }
        iMau[0]=7;iMau[1]=7;iMau[2]=7;
        if(iDem==1){
            iMau[0]=144;
        }else if(iDem==2){
            iMau[1]=144;
        }else if(iDem==3){
            iMau[2]=144;
        }
    }
}
void form_LogIn(){
    string strUserName,strPassWord;
    outPut(40,1,14,"* * * * * * * * * * * * * * * * * * * * *");
    outPut(40,3,14,"*");
    outPut(42,3,2,"          ĐĂNG NHẬP HỆ THỐNG           ");
    outPut(80,3,14,"*");
    outPut(40,5,14,"* * * * * * * * * * * * * * * * * * * * *");
    outPut(42,6,10,"User:");
    outPut(42,8,10,"Password:");
    if(nhap_du_lieu(strUserName,strPassWord)){
        system("cls");
        formMenu();
    }
}
bool form_LogOut(){
    outPut(42,10,15,"╔═══════════════════════════════════╗");
    outPut(42,11,15,"║");outPut(78,11,15,"║");
    outPut(42,12,15,"║");outPut(78,12,15,"║");
    outPut(42,13,15,"║");outPut(78,13,15,"║");
    outPut(42,14,15,"║");outPut(78,14,15,"║");
    outPut(42,15,15,"║");outPut(78,15,15,"║");
    outPut(42,16,15,"║");outPut(78,16,15,"║");
    outPut(42,17,15,"║");outPut(78,17,15,"║");
    outPut(42,18,15,"╚═══════════════════════════════════╝");
    outPut(53,12,12,"Bạn có muốn thoát ?");
    int iMau[]={244,4};
    int iDem=1;
    char key;
    while(true){
        outPut(55,15,iMau[0],"YES");
        outPut(65,15,iMau[1],"NO");
        key=_getch();
        if(key==77&&iDem==1){
            iDem++;
        }else if(key==75&&iDem==2){
            iDem--;
        }else if(key=='\r'){
            if(iDem==1){
                exit(0);
            }else{
                outPut(0,0,0," ");
                return false;
            }
        }
        iMau[0]=4;iMau[1]=4;
        if(iDem==1){
            iMau[0]=244;
        }else if(iDem==2){
            iMau[1]=244;
        }
    }
}
void formMenuPhieuMuon(){
    outPut(40,10,11,"* * * * * * * * * * * * * * * * * * * *");
    outPut(40,11,11,"*");outPut(78,11,11,"*");
    outPut(40,12,11,"*");outPut(78,12,11,"*");
    outPut(40,13,11,"*");outPut(78,13,11,"*");
    outPut(40,14,11,"*");outPut(78,14,11,"*");
    outPut(40,15,11,"*");outPut(78,15,11,"*");
    outPut(40,16,11,"*");outPut(78,16,11,"*");
    outPut(40,17,11,"*");outPut(78,17,11,"*");
    outPut(40,18,11,"*");outPut(78,18,11,"*");
    outPut(40,19,11,"*");outPut(78,19,11,"*");
    outPut(40,20,11,"* * * * * * * * * * * * * * * * * * * *");
    outPut(52,12,6,"Quản Lý Phiếu Mượn");
    int iMau[]={144,7,7};
    int iDem=1;
    char key;
    while(true){
        outPut(55,14,iMau[0],"Mượn Sách");
        outPut(55,16,iMau[1],"Trả Sách");
        outPut(43,18,iMau[2],"Hiển thị thông tin các phiếu mượn");
        key=_getch();
        if(key==80&&(iDem>=1&&iDem<=2)){
            iDem++;
        }else if(key==72&&(iDem>=2&&iDem<=3)){
            iDem--;
        }else if(key=='\b'){
            outPut(0,0,0," ");
            system("cls");
            formMenu();
        }else if(key=='\r'){
            if(iDem==1){
                goTo(0,0,0);
                system("cls");
                formThemPhieuMuon();
            }else if(iDem==3){
                goTo(0,0,0);
                system("cls");
                LayThongTinPhieuMuon();
            }else if(iDem==2){
                goTo(0,0,0);
                system("cls");
                formTraSach();
            }
            break;
        }
        iMau[0]=7;iMau[1]=7;iMau[2]=7;
        if(iDem==1){
            iMau[0]=144;
        }else if(iDem==2){
            iMau[1]=144;
        }else if(iDem==3){
            iMau[2]=144;
        }
    }
}
void formThongTinSach(Sach X){
    Sach Y=X;
    for(int i=3;i<27;i++){
        outPut(67,i,12,"\b                                                    \b");
    }
    outPut(67,3,12,"╔═══════════════════════════════════════════════╗");
    for(int i=4;i<=25;i++){
        outPut(67,i,12,"║");outPut(115,i,12,"║");
    }
    outPut(67,26,12,"╚═══════════════════════════════════════════════╝");
    outPut(85,4,7,"THÔNG TIN SÁCH");
    outPut(72,6,7,"Mã Sách:");outPut(81,6,7,Y.strMaSach);
    outPut(72,8,7,"Tên Sách:");outPut(81,8,7,Y.strTenSach);
    outPut(72,10,7,"Tên Tác Giả:");outPut(85,10,7,Y.strTacGia);
    outPut(72,12,7,"Nhà Xuất Bản:");outPut(86,12,7,Y.strNhaXuatBan);
    outPut(72,14,7,"Giá Bán:");outPut(81,14,7,to_string(Y.iGiaBan)+" VNĐ");
    outPut(72,16,7,"Số Trang:");outPut(81,16,7,to_string(Y.iSoTrang));
    outPut(72,18,7,"Ngày Nhập Kho:");outPut(88,18,7,Y.strNgayNhapKho);
    outPut(72,20,7,"Tình Trạng:");outPut(85,20,7,to_string(Y.iTinhTrangSach));
}
void formXoaSach(){
    SkipList<Sach> X(20);
    LaySach(X);
    string strMaSach,strThu;
    char key;
    outPut(5,3,14,"╔═══════════════════════════════════════╗");
    for(int i=4;i<=9;i++){
        outPut(5,i,14,"║");outPut(45,i,14,"║");
    }
    outPut(5,10,14,"╚═══════════════════════════════════════╝");
    outPut(22,5,11,"XÓA SÁCH");
    outPut(10,7,15,"Mã Sách:");
    while(true){
        goTo(19,7,7);
        key=_getch();
        if(key=='L'){
            cout<<key;
            cin>>strThu;
            strMaSach=key+strThu;
            Sach Y=X.SearchNode(strMaSach);
            if(Y.strMaSach==strMaSach&&Y.iTinhTrangSach==0){
                formThongTinSach(Y);
                outPut(10,12,0,"\b                                 \b");
                if(formXacNhan()){
                    X.DeleteNode(Y);
                    CapNhatSach(X);
                    formThongBaoXoaThanhCong();
                }else{
                    goTo(0,0,0);
                    system("cls");
                    formXoaSach();
                    break;
                }
            }else if(Y.strMaSach==strMaSach&&Y.iTinhTrangSach!=0){
                formThongTinSach(Y);
                outPut(10,12,12,"Cuốn sách này không thể xóa");
            }else{
                outPut(10,12,12,"Cuốn sách này không có trong kho ");
            }

        }else if(key=='\b'){
            outPut(0,0,0," ");
            system("cls");
            formMenuBook();
            break;
        }
        goTo(19,7,7);
        cout<<"\b           \b";
    }
}
bool formXacNhan(){
    outPut(10,15,15,"╔════════════════════════════╗");
    for(int i=16;i<=20;i++){
        outPut(10,i,15,"║");outPut(39,i,15,"║");
    }
    outPut(10,21,15,"╚════════════════════════════╝");
    outPut(21,16,12,"XÁC NHẬN");
    int iMau[]={244,7},iDem=1;
    char key;
    while(true){
        outPut(15,18,iMau[0],"Có");
        outPut(30,18,iMau[1],"Không");
        key=_getch();
        if(key==77&&iDem==1){
            iDem++;
        }else if(key==75&&iDem==2){
            iDem--;
        }else if(key=='\r'){
            if(iDem==1){
                return true;
            }else{
                return false;
            }
            break;
        }
        iMau[0]=7;iMau[1]=7;
        if(iDem==1){
            iMau[0]=244;
        }else if(iDem==2){
            iMau[1]=244;
        }
    }
}
void formThongBaoXoaThanhCong(){
    outPut(10,15,14,"╔════════════════════════════╗");
    for(int i=16;i<=20;i++){
        outPut(10,i,14,"║");outPut(39,i,14,"║");
    }
    outPut(10,21,14,"╚════════════════════════════╝");
    outPut(21,16,0,"             ");
    outPut(15,18,0,"  ");
    outPut(30,18,0,"     ");
    outPut(18,18,12,"XÓA THÀNH CÔNG");
    //outPut()
}
void formThemSach(){
    SkipList<Sach> DS(20);
    LaySach(DS);
    Sach X;
	outPut(40,1,12,"* * * * * * * * * * * * * * * * * * * * *");
    outPut(40,3,12,"*");
    outPut(42,3,2,"             THÊM SÁCH           ");
    outPut(80,3,12,"*");
    outPut(40,5,12,"* * * * * * * * * * * * * * * * * * * * *");
    outPut(42,6,3,"Mã sách:");
    outPut(42,8,3,"Tên sách:");
    outPut(42,10,3,"Tác giả:");
    outPut(42,12,3,"Nhà xuất bản:");
    outPut(42,14,3,"Số trang:");
    outPut(42,16, 3, "Ngày nhập:");
    outPut(42,18,3,"Tình trạng:");
    outPut(42,20,3,"Năm phát hành:");
    outPut(42, 22, 3, "Giá:");
    outPut(40,24,12,"════════════════════════════════════════════");
    char key;
    string strMaSach="",strTenSach="",strTacGia="",strNhaXuatBan="",strGiaBan="",strSoTrang="",strTinhTrangSach="",strNamPhatHanh="",strNgayNhapKho="";
    while(true){
        goTo(51,6,7);
        key=_getch();
        if (key == '\r'){
            outPut(50, 27, 14, "\b                                          \b");
            outPut(50, 27, 14, "Không được để trống!!!");
        }else if(key!='\b'){
            goTo(51,6,7);cout<<key;getline(cin,strMaSach);strMaSach=key+strMaSach;
            goTo(52,8,7);getline(cin,strTenSach);
            goTo(51,10,7);getline(cin,strTacGia);
            goTo(56,12,7);getline(cin,strNhaXuatBan);
            goTo(52,14,7);getline(cin,strSoTrang);
            goTo(53, 16, 7);strNgayNhapKho = layNgay(0);cout << strNgayNhapKho;
            goTo(54,18,7);strTinhTrangSach="0";cout<<strTinhTrangSach;
            goTo(57,20,7);getline(cin,strNamPhatHanh);
            goTo(47,22,7);getline(cin,strGiaBan);
            if (strMaSach == "" || strTenSach == "" || strTacGia == "" || strNhaXuatBan == "" || strGiaBan == "" || strSoTrang == "" || strTinhTrangSach == "" || strNamPhatHanh == "" || strNgayNhapKho == ""){
                outPut(50, 27, 14, "\b                               \b");
                outPut(50, 27, 14, "Không được để trống!!!");
            }else if(DS.SearchNode(strMaSach)==strMaSach){
                outPut(50, 27, 14, "\b                                          \b");
                outPut(50,27,14,"Mã sách bị trùng!!!");
            }else if(!kiemTraMaSach(strMaSach)){
                outPut(50, 27, 14, "\b                                          \b");
                outPut(50, 27, 14, "Mã sách không hợp lệ");
            }else if(kiemTraTiengViet(strTenSach)||kiemTraTiengViet(strTacGia)||kiemTraTiengViet(strNhaXuatBan)){
                outPut(50, 27, 14, "\b                               \b");
                outPut(50, 27, 14, "Chỉ nhận sách tiếng anh nhập khẩu");
            }else if(!is_number(strGiaBan)){
                outPut(50, 27, 14, "\b                               \b");
                outPut(50, 27, 14, "Giá sách không hợp lệ");
            }else if(!is_number(strSoTrang)){
                outPut(50, 27, 14, "\b                               \b");
                outPut(50, 27, 14, "Số trang không hợp lệ");
            }else if((!is_number(strNamPhatHanh))||(!kiemTraNamPhatHanh(strNamPhatHanh))){
                outPut(50, 27, 14, "\b                               \b");
                outPut(50, 27, 14, "Năm phát hành không hợp lệ");
            }else{
                X.strMaSach=strMaSach;
                X.strTenSach=strTenSach;
                X.strTacGia=strTacGia;
                X.strNhaXuatBan=strNhaXuatBan;
                X.iSoTrang=stoi(strSoTrang);
                X.strNgayNhapKho=strNgayNhapKho;
                X.iTinhTrangSach=stoi(strTinhTrangSach);
                X.iNamPhatHanh=stoi(strNamPhatHanh);
                X.iGiaBan=stoi(strGiaBan);
                DS.insertNode(X);
                LuuSach(DS);
                goTo(0,0,0);
                system("cls");
                formThemSach();
            }
            outPut(51,6,7,"\b                                      \b");
            outPut(52,8,7,"\b                                      \b");
            outPut(51,10,7,"\b                                      \b");
            outPut(56,12,7,"\b                                      \b");
            outPut(52,14,7,"\b                                      \b");
            outPut(53,16,7,"\b                                      \b");
            outPut(54,18,7,"\b                                      \b");
            outPut(57,20,7,"\b                                      \b");
            outPut(47,22,7,"\b                                      \b");
        }else if(key=='\b'){
            goTo(0,0,0);
            system("cls");
            formMenuBook();
        }
    }
}
void formThemPhieuMuon(){
    SkipList<PhieuMuonSach> DS(20);
    SkipList<BanDoc> DSBanDoc(20);
    layBanDoc(DSBanDoc);
    layPhieuMuon(DS);
    PhieuMuonSach X;
    string strSoPhieuMuon="",strMaBanDoc="",strNgayMuon="",strNgayTra="",strDanhSachMaSachMuon="";
	outPut(40,1,12,"╔═══════════════════════════════════════════════════╗");
    outPut(40,3,12,"║");outPut(40,4,12,"║");outPut(40,2,12,"║");
    outPut(42,3,2,"                 THÊM PHIẾU MƯỢN");
    outPut(92,3,12,"║");outPut(92,4,12,"║");outPut(92,2,12,"║");
    outPut(40,5,12,"╠═══════════════════════════════════════════════════╣");
    outPut(42,6,6,"Mã phiếu mượn:");
	outPut(42,8,6,"Mã bạn đọc:");
    outPut(42,10,6,"Ngày mượn:");
    outPut(42,12,6,"Ngày trả:");
    outPut(42,14,6,"Danh sách mã sách:");
    outPut(40,16,12,"╚═══════════════════════════════════════════════════╝");
    outPut(40,6,12,"║");
    outPut(40,8,12,"║");
    outPut(40,10,12,"║");
    outPut(40,12,12,"║");
    outPut(40,14,12,"║");
    outPut(40,7,12,"║");
    outPut(40,9,12,"║");
    outPut(40,11,12,"║");
    outPut(40,13,12,"║");
    outPut(40,15,12,"║");
    outPut(92,6,12,"║");
    outPut(92,8,12,"║");
    outPut(92,10,12,"║");
    outPut(92,12,12,"║");
    outPut(92,14,12,"║");
    outPut(92,7,12,"║");
    outPut(92,9,12,"║");
    outPut(92,11,12,"║");
    outPut(92,13,12,"║");
    outPut(92,15,12,"║");
    char key;
    while(true){
        X.strMaSach.clear();
        goTo(57,6,7);
        key=_getch();
        if(key=='\r'){
            outPut(34, 18, 9, "\b                                                                        \b");
            outPut(60,17,9,"\b                                                                           \b");
            outPut(48, 18, 9, "Không được để trống!!!");
            outPut(61, 14, 7, "\b                 \b");
            outPut(52, 12, 7, "\b                 \b");
            outPut(53, 10, 7, "\b                 \b");
            outPut(54, 8, 7, "\b                 \b");
            outPut(57, 6, 7, "\b                 \b");
            goTo(57, 6, 7);
            continue;
        }else if(key!='\b'){
            goTo(57,6,7);cout<<key; cin>>strSoPhieuMuon;strSoPhieuMuon=key+strSoPhieuMuon;cin.ignore();
            goTo(54,8,7); getline(cin,strMaBanDoc);
            goTo(53,10,7); strNgayMuon=layNgay(0);cout<<strNgayMuon;
            goTo(52,12,7); strNgayTra=layNgay(7);cout<<strNgayTra;
            goTo(61,14,7); getline(cin,strDanhSachMaSachMuon);
            TachMaSach(X.strMaSach,strDanhSachMaSachMuon);
            X.iSoSachMuon=X.strMaSach.size();
            X.iTinhTrangPhieuMuon=1;
            BanDoc Z=DSBanDoc.SearchNode(strMaBanDoc);
            if(strSoPhieuMuon==""||strMaBanDoc==""||strNgayMuon==""||strNgayTra==""||strDanhSachMaSachMuon==""){
                outPut(34, 18, 9, "\b                                                                        \b");
                outPut(60, 17, 9, "\b                                                                           \b");
                outPut(48, 18, 9, "Không được để trống!!!");
                outPut(61, 14, 7, "\b                 \b");
                outPut(52, 12, 7, "\b                 \b");
                outPut(53, 10, 7, "\b                 \b");
                outPut(54, 8, 7, "\b                 \b");
                outPut(57, 6, 7, "\b                 \b");
                goTo(57, 6, 7);
                continue;
            }else if(!(kiemTraMaPhieuMuon(strSoPhieuMuon))){
                outPut(34, 18, 9, "\b                                                                         \b");
                outPut(60,17,9,"\b                                                                           \b");
                outPut(48, 18, 9, "Mã phiếu mượn không hợp lệ");
                outPut(61, 14, 7, "\b                 \b");
                outPut(52, 12, 7, "\b                 \b");
                outPut(53, 10, 7, "\b                 \b");
                outPut(54, 8, 7, "\b                 \b");
                outPut(57, 6, 7, "\b                 \b");
                goTo(57, 6, 7);
                continue;
            }else if(!(DS.SearchNode(strSoPhieuMuon).strSoPhieuMuon=="G.000")){
                bool check=true;
                for(int i=0;i<DS.GetSoLuong();i++){
                    if(DS[i].strSoPhieuMuon==strSoPhieuMuon){
                        check=false;
                    }
                }
                if(!check){
                    outPut(34, 18, 9, "\b                                                                         \b");
                    outPut(60,17,9,"\b                                                                           \b");
                    outPut(48, 18, 9, "Mã phiếu mượn bị trùng");
                    outPut(61, 14, 7, "\b                 \b");
                    outPut(52, 12, 7, "\b                 \b");
                    outPut(53, 10, 7, "\b                 \b");
                    outPut(54, 8, 7, "\b                 \b");
                    outPut(57, 6, 7, "\b                 \b");
                    goTo(57, 6, 7);
                    continue;
                }
            }
            if(Z.strMaBanDoc=="M.000"||Z.strMaBanDoc!=strMaBanDoc){
                outPut(34, 18, 9, "\b                                                                       \b");
                outPut(60,17,9,"\b                                                                           \b");
                outPut(48, 18, 9, "Không Có Mã Bạn Đọc này trong thư viện");
                outPut(61, 14, 7, "\b                 \b");
                outPut(52, 12, 7, "\b                 \b");
                outPut(53, 10, 7, "\b                 \b");
                outPut(54, 8, 7, "\b                 \b");
                outPut(57, 6, 7, "\b                 \b");
                goTo(57, 6, 7);
                continue;
            }
            bool check=true;
            for(int i=0;i<X.strMaSach.size();i++){
                if(!KiemTraTinhTrangSach(X.strMaSach[i])){
                    outPut(34, 18, 9, "\b                                                                       \b");
                    outPut(60,17,9,"\b                                                                           \b");
                    outPut(48,18,9,"Sách có mã "+X.strMaSach[i]+" đã được mượn trước");
                    outPut(61,14,7,"\b                      \b");
                    outPut(52,12,7,"\b                      \b");
                    outPut(53,10,7,"\b                      \b");
                    outPut(54,8,7,"\b                       \b");
                    outPut(57,6,7,"\b                       \b");
                    goTo(57,6,7);
                    check=false;
                    break;
                }
            }
            if(check){
                X.strSoPhieuMuon=strSoPhieuMuon;
                X.strMaBanDoc=strMaBanDoc;
                X.strNgayMuon=strNgayMuon;
                X.strNgayTra=strNgayTra;
                for(int i=0;i<X.strMaSach.size();i++){
                    ThayDoiTinhTrangSach(X.strMaSach[i],1);
                }
                DS.insertNode(X);
                LuuPhieuMuon(X);
                outPut(34, 18, 9, "\b                                                                       \b");
                outPut(60,17,9,"\b                                                                           \b");
                outPut(60,17,14,"Mượn Sách Thành Công");
                outPut(34, 18, 14, "LƯU Ý:Sách phải được trả trong vòng 7 ngày tính từ ngày "+strNgayMuon+" !!!");
            }
            outPut(61,14,7,"\b                      \b");
            outPut(52,12,7,"\b                      \b");
            outPut(53,10,7,"\b                      \b");
            outPut(54,8,7,"\b                       \b");
            outPut(57,6,7,"\b                       \b");

        }else if(key=='\b'){
            goTo(0,0,0);
            system("cls");
            formMenuPhieuMuon();
        }
    }
}
void formTraSach(){
	string strMaPhieuMuon;
	SkipList<PhieuMuonSach> DS(20);
    layPhieuMuon(DS);
	outPut(40,1,2,"+ - - - - - - - - - - - - - - - - - - - +");
    outPut(40,3,2,"|");
    outPut(42,3,3,"               TRẢ SÁCH          ");
    outPut(80,3,2,"|");
    outPut(40,5,2,"+ - - - - - - - - - - - - - - - - - - - +");
    outPut(42,6,4,"Mã Phiếu Mượn :");
    char key;
    while(true){
        goTo(58,6,7);
        key=_getch();
        if(key!='\b'){
            cout<<key;
            cin>>strMaPhieuMuon;
            strMaPhieuMuon=key+strMaPhieuMuon;
            PhieuMuonSach X=DS.SearchNode(strMaPhieuMuon);
            if(X.strSoPhieuMuon=="G.000"){
                outPut(42,11,9,"\b                                                                                 \b");
                outPut(42,11,9,"Không tồn tại mã phiếu mượn này");
                outPut(58,6,7,"\b      \b");
                goTo(58,6,7);
            }else if(X.iTinhTrangPhieuMuon==0){
                outPut(45,8,9,"\b                                                                 \b");
                outPut(35,11,9,"Sách trong phiếu này đã được trả và phiếu mượn này đã hết hiệu lực");
                outPut(58,6,7,"\b      \b");
                goTo(58,6,7);
            }else{
                for(int i=0;i<X.strMaSach.size();i++){
                    ThayDoiTinhTrangSach(X.strMaSach[i],0);
                }
                ThayDoiTinhTrangPhieuMuon(X.strSoPhieuMuon);
                outPut(53,8,9,"\b                                                                 \b");
                    outPut(53,8,9,"Thành Công");
                    outPut(58,6,7,"\b      \b");
                    goTo(58,6,7);
            }
        }else if(key=='\b'){
            goTo(0,0,0);
            system("cls");
            formMenuPhieuMuon();
        }
    }

}
//
//      Hàm main
//
int main(){
    system("cls");
    form_LogIn();
    return 0;
}
