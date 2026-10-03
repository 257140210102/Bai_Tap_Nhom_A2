#include<bits/stdc++.h>
using namespace std;

class MonHoc{
	private:
		string Ma_Mon; // ma mon hoc
		string Ten_Mon; // ten mon hoc
		int So_Tin; // so tin chi
		string Ngay_Thi; // ngay thi
		int Ca_Thi; // ca thi
		string Phong_Thi; // phong thi
		int So_Sinh_Vien; // so luong sinh vien dang ky
	public:
	    string getTenMon() const{ // lay ten mon
        return Ten_Mon;
		}
		string getMaMon() const	{ // lay ma mon
			return Ma_Mon;
		}
		string getNgayThi() const { // lay ngay thi
			return Ngay_Thi;
		}
		MonHoc() {
			Ma_Mon = "";
			Ten_Mon = "";
			So_Tin = 0;
			Ngay_Thi = "";
			Ca_Thi = 0;
			Phong_Thi = "";
			So_Sinh_Vien = 0;
		}; // ham tao
		MonHoc(string ma, string ten, int tc, string ngay, int ca, string phong, int soluong){ // ham tao co tham so
			Ma_Mon = ma;Ten_Mon = ten; So_Tin = tc;
			Ngay_Thi = ngay;
			Ca_Thi = ca;
			Phong_Thi = phong;
			So_Sinh_Vien = soluong;
    	}
	    MonHoc(const MonHoc &mh) { // ham sao chep
	        Ma_Mon = mh.Ma_Mon;
			Ten_Mon = mh.Ten_Mon;
			So_Tin = mh.So_Tin;
			Ngay_Thi = mh.Ngay_Thi;
			Ca_Thi = mh.Ca_Thi;
			Phong_Thi = mh.Phong_Thi;
			So_Sinh_Vien = mh.So_Sinh_Vien;
	    }
		void nhap(); // phuong thuc nhap
		void xuat(); // phuong thuc xuat
		friend int so_sanh_theo_ngay(const MonHoc &a, const MonHoc &b);
};

// Nhap 1 mon hoc
void MonHoc::nhap(){
	cout << "Nhap ma mon hoc: ";
	cin >> Ma_Mon;
	cin.ignore();
	cout << "Nhap ten mon hoc: ";
	getline(cin, Ten_Mon);
	cout << "Nhap so tin chi: ";
	cin >> So_Tin;
	cout << "Nhap ngay thi: ";
	cin >> Ngay_Thi;
	cout << "Nhap ca thi: ";
	cin >> Ca_Thi;
	cout << "Nhap phong thi: ";
	cin >> Phong_Thi;
	cout << "Nhap so luong sinh vien dang ky: ";
	cin >> So_Sinh_Vien;
}

// Xuat 1 mon hoc
void MonHoc::xuat(){
           cout << left
                << setw(12) << Ma_Mon
                << setw(30) << Ten_Mon
                << setw(10) << So_Tin
                << setw(15) << Ngay_Thi
                << setw(10) << Ca_Thi
                << setw(15) << Phong_Thi
                << setw(12) << So_Sinh_Vien
                << endl;
}
// so sanh 2 ngay thi cua 2 mon hoc
int so_sanh_theo_ngay(const MonHoc &a, const MonHoc &b){
    string nam_thang_ngay_a, nam_thang_ngay_b;
    // Chuyen ngay thi sang dinh dang YYYYMMDD de so sanh
    nam_thang_ngay_a = a.getNgayThi().substr(6,4)
                        + a.getNgayThi().substr(3,2)+ a.getNgayThi().substr(0,2);
    nam_thang_ngay_b = b.getNgayThi().substr(6,4)
                        + b.getNgayThi().substr(3,2)+ b.getNgayThi().substr(0,2);
    if(nam_thang_ngay_a < nam_thang_ngay_b)
        return -1; // neu ngay thi cua mon a nho hon ngay thi cua mon b thi tra ve -1
    else if(nam_thang_ngay_a > nam_thang_ngay_b)
        return 1; // neu ngay thi cua mon a lon hon ngay thi cua mon b thi tra ve 1
    else
        return 0; // neu ngay thi cua mon a bang ngay thi cua mon b thi tra ve 0
}
// QuanLyDanhSach la lop quan ly danh sach mon hoc
class QuanLyDanhSach{
	private:
		MonHoc ds[200];
		int n;
	public:
		void nhap_ds();
		void xuat_ds();
		void sap_xep();
		void tim_ten_mon();
		void tim_ma_mon();
		void bo_sung(int vi_tri, MonHoc a);
		void xoa(int vi_tri);
};
// Nhap danh sach mon hoc
void QuanLyDanhSach::nhap_ds(){
	do{
		cout << "Nhap so luong mon hoc n (0 < n < 200): ";
		cin >> n;
	} while (n <= 0 || n >= 200);

	for (int i = 0; i < n; i++) {
		cout << "\nNhap mon hoc thu " << i + 1 << ":\n";
		ds[i].nhap();
	}
}
void xuat_tieu_de(){
    cout << left
         << setw(12) << "Ma mon"
         << setw(30) << "Ten mon"
         << setw(10) << "So TC"
         << setw(15) << "Ngay thi"
         << setw(10) << "Ca thi"
         << setw(15) << "Phong thi"
         << setw(12) << "So SV"
         << endl;
}
// Xuat danh sach mon hoc
void QuanLyDanhSach::xuat_ds(){
	cout << "\nDanh sach mon hoc \n";
	xuat_tieu_de();
    for(int i = 0; i < n; i++)
        ds[i].xuat();
}
// sap xep danh sach mon hoc theo ngay thi tang dan
void QuanLyDanhSach::sap_xep(){
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if(so_sanh_theo_ngay(ds[i], ds[j]) > 0){
                MonHoc temp = ds[i]; // hoan doi 2 mon hoc neu ngay thi cua mon i lon hon ngay thi cua mon j
                ds[i] = ds[j];
                ds[j] = temp;
            }
        }
    }
}
// Tim mon hoc theo ten
void QuanLyDanhSach::tim_ten_mon(){
	string ten_mon;
	cout << "Nhap ten mon hoc can tim: ";
	cin.ignore();
	getline(cin, ten_mon);
	int check=0;
	for(int i=0; i<n; i++){
		if(ds[i].getTenMon() == ten_mon){
			if((++check)==1) // neu tim thay mon hoc dau tien thi in ra tieu de
				xuat_tieu_de();
			ds[i].xuat(); // in ra mon hoc tim thay
		}
    }
	if(!check){ // kiem tra neu khong tim thay mon hoc thi in ra thong bao
		cout << "Khong tim thay mon hoc voi ten: " << ten_mon << endl;
	}
}
// Tim mon hoc theo ma mon
void QuanLyDanhSach::tim_ma_mon(){
	string ma_mon;
	cout << "Nhap ma mon hoc can tim: ";
	cin >> ma_mon;
	int check=0;
	for(int i=0; i<n; i++){
		if(ds[i].getMaMon() == ma_mon){
			if((++check)==1) // neu tim thay mon hoc dau tien thi in ra tieu de
				xuat_tieu_de();
			ds[i].xuat(); // in ra mon hoc tim thay
		}	}
	if(!check){ // kiem tra neu khong tim thay mon hoc thi in ra thong bao
		cout << "Khong tim thay mon hoc voi ma: " << ma_mon << endl;
	}}
// Bo sung mon hoc a vao danh sach mon hoc tai vi tri vi_tri
void QuanLyDanhSach::bo_sung(int vi_tri, MonHoc a) {
    if (n >= 200) { // kiem tra danh sach da day hay chua
        cout << "Danh sach da day, khong the bo sung!\n";
        return;
    }
    if (vi_tri < 0 || vi_tri > n) {
            // kiem tra vi tri bo sung co hop le hay khong
        cout << "Vi tri khong hop le!\n";
        return;
    }
    // dich chuyen cac mon hoc tu vi tri vi_tri
    //tro ve sau 1 vi tri de tao cho mon hoc moi
    for (int i = n; i > vi_tri; i--)
        ds[i] = ds[i - 1];
    ds[vi_tri] = a; // bo sung mon hoc moi vao vi tri vi_tri
    n++;
    cout<< "danh sach sau khi bo sung tai vi tri " << vi_tri << ":\n";
    xuat_ds();
}
void QuanLyDanhSach::xoa(int vi_tri) {
     // xoa mon hoc tai vi tri vi_tri
    if (n == 0) { // kiem tra danh sach co rong hay khong
        cout << "Danh sach rong, khong the xoa!\n";
        return;
    }
    if (vi_tri < 0 || vi_tri >= n) {
            // kiem tra vi tri xoa co hop le hay khong
        cout << "Vi tri khong hop le!\n";
        return;
    }
    // dich chuyen cac mon hoc tu vi tri vi_tri+1
    // tro ve truoc 1 vi tri de xoa mon hoc tai vi tri vi_tri
    for (int i = vi_tri; i < n - 1; i++)
        ds[i] = ds[i + 1];
    n--; // giam so luong mon hoc trong danh sach
    cout<< "danh sach sau khi xoa tai vi tri "<< vi_tri << ":\n";
    xuat_ds();
}
// Ham main de chay chuong trinh
int main(){
	QuanLyDanhSach ql;
	ql.nhap_ds();
	while(true){ // vong lap vo han de hien thi menu chuc nang
		cout << "1. Xuat danh sach mon hoc" << endl;
		cout << "2. Sap xep danh sach theo ngay thi" << endl;
		cout << "3. Tim mon hoc theo ten" << endl;
		cout << "4. Tim mon hoc theo ma" << endl;
		cout << "5. Bo sung mon hoc vao danh sach" << endl;
		cout << "6. Xoa mon hoc khoi danh sach" << endl;
		cout << "0. Thoat" << endl;
		int choice; // khai bao bien choice de luu lua chon cua nguoi dung
		cout << "Nhap lua chon: ";
		cin >> choice;
		switch(choice){
			case 1: // xuat danh sach mon hoc
				ql.xuat_ds();
				break;
			case 2: // sap xep danh sach mon hoc theo ngay thi
				ql.sap_xep();
				cout << "Danh sach da duoc sap xep theo ngay thi." << endl;
				ql.xuat_ds();
				break;
			case 3: // tim mon hoc theo ten
				ql.tim_ten_mon();break;
			case 4: // tim mon hoc theo ma
				ql.tim_ma_mon();break;
			case 5:{ // bo sung mon hoc vao danh sach
				int vi_tri;
				cout << "Nhap vi tri can bo sung: ";cin >> vi_tri;
				MonHoc a;a.nhap(); ql.bo_sung(vi_tri, a);
				break;
			}
			case 6:{ // xoa mon hoc khoi danh sach
				int vi_tri;
				cout << "Nhap vi tri can xoa: ";cin >> vi_tri;
				ql.xoa(vi_tri);
				break;
			}
			case 0: // thoat chuong trinh
				return 0;
			default: // neu nguoi dung nhap sai lua chon thi in ra thong bao
				cout << "Lua chon khong hop le!" << endl;
		}
	}
	return 0;
}
