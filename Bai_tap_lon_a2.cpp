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
	    // ham tao
		MonHoc() {
			Ma_Mon = "";
			Ten_Mon = "";
			So_Tin = 0;
			Ngay_Thi = "";
			Ca_Thi = 0;
			Phong_Thi = "";
			So_Sinh_Vien = 0;
		};
		//ham sao chep
	    MonHoc(const MonHoc &mh) {
	        Ma_Mon = mh.Ma_Mon;
			Ten_Mon = mh.Ten_Mon;
			So_Tin = mh.So_Tin;
			Ngay_Thi = mh.Ngay_Thi;
			Ca_Thi = mh.Ca_Thi;
			Phong_Thi = mh.Phong_Thi;
			So_Sinh_Vien = mh.So_Sinh_Vien;
	    }
		void nhap(); // phuong thuc nhap
		void xuat() const; // phuong thuc xuat
		friend void nhap_ds(MonHoc ds[], int &n); // ham ban nhap danh sach
        friend void xuat_ds(const MonHoc ds[], int n); //ham ban in danh sach
        friend int so_sanh_theo_ngay(const MonHoc &a, const MonHoc &b); // so sanh theo ngay
        friend void sap_xep(MonHoc ds[], int n); // ham ban sap xep
        friend void tim_ten_mon(const MonHoc ds[], int n, string ten_mon); // ham ban tim theo ten mon
        friend void tim_ma_mon(const MonHoc ds[], int n, string ma_mon); // ham ban tim theo ma mon
        friend void bo_sung(MonHoc ds[], int &n, int vi_tri,const MonHoc &a); // ham bo sung
        friend void xoa(MonHoc ds[], int &n, int vi_tri);// ham xoa
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
void MonHoc::xuat() const{
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
// ham ban nhap danh sach
void nhap_ds(MonHoc ds[], int &n){
	do{
		cout << "Nhap so luong mon hoc n (0 < n < 200): ";
		cin >> n;
	} while (n <= 0 || n >= 200);

	for (int i = 0; i < n; i++) {
		cout << "\nNhap mon hoc thu " << i + 1 << ":\n";
		ds[i].nhap();
	}
}
// ham in tieu de
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
void xuat_ds(const MonHoc ds[], int n){
	cout << "\nDanh sach mon hoc \n";
	xuat_tieu_de();
    for(int i = 0; i < n; i++)
        ds[i].xuat();
}
// so sanh 2 ngay thi cua 2 mon hoc
int so_sanh_theo_ngay(const MonHoc &a, const MonHoc &b){
    string nam_thang_ngay_a, nam_thang_ngay_b;// Chuyen ngay thi sang dinh dang YYYYMMDD de so sanh
    nam_thang_ngay_a = a.Ngay_Thi.substr(6, 4) + a.Ngay_Thi.substr(3, 2) + a.Ngay_Thi.substr(0, 2);
    nam_thang_ngay_b = b.Ngay_Thi.substr(6, 4) + b.Ngay_Thi.substr(3, 2) + b.Ngay_Thi.substr(0, 2);
    if(nam_thang_ngay_a < nam_thang_ngay_b)
        return -1; // neu ngay thi cua mon a nho hon ngay thi cua mon b thi tra ve -1
    if(nam_thang_ngay_a > nam_thang_ngay_b)
        return 1; // neu ngay thi cua mon a lon hon ngay thi cua mon b thi tra ve 1
    return 0; // neu ngay thi cua mon a bang ngay thi cua mon b thi tra ve 0
}
// sap xep danh sach mon hoc theo ngay thi tang dan
void sap_xep(MonHoc ds[], int n){
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if(so_sanh_theo_ngay(ds[i], ds[j]) > 0){
                MonHoc temp = ds[i]; // hoan doi 2 mon hoc neu ngay thi cua mon i lon hon ngay thi cua mon j
                ds[i] = ds[j];
                ds[j] = temp;
            }
        }
    }
    cout << "Danh sach da duoc sap xep theo ngay thi.\n";
    xuat_ds(ds,n);
}
// Tim mon hoc theo ten
void tim_ten_mon(const MonHoc ds[], int n, string ten_mon){
	int check=0;
	for(int i=0; i<n; i++){
		if(ds[i].Ten_Mon == ten_mon){
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
void tim_ma_mon(const MonHoc ds[], int n, string ma_mon){
	int check=0;
	for(int i=0; i<n; i++){
		if(ds[i].Ma_Mon == ma_mon){
			if((++check)==1) // neu tim thay mon hoc dau tien thi in ra tieu de
				xuat_tieu_de();
			ds[i].xuat(); // in ra mon hoc tim thay
		}	}
	if(!check){ // kiem tra neu khong tim thay mon hoc thi in ra thong bao
		cout << "Khong tim thay mon hoc voi ma: " << ma_mon << endl;
	}}
// Bo sung mon hoc a vao danh sach mon hoc tai vi tri vi_tri
void bo_sung(MonHoc ds[], int &n, int vi_tri, const MonHoc &a) {
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
    xuat_ds(ds, n);
}
// xoa mon hoc tai vi tri
void xoa(MonHoc ds[], int &n, int vi_tri) {
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
    // dich chuyen cac mon hoc tu vi tri vi_tri+1 tro ve truoc 1 vi tri de xoa mon hoc tai vi tri vi_tri
    for (int i = vi_tri; i < n - 1; i++)
        ds[i] = ds[i + 1];
    n--; // giam so luong mon hoc trong danh sach
    cout<< "danh sach sau khi xoa tai vi tri "<< vi_tri << ":\n";
    xuat_ds(ds, n);
}
// Ham main de chay chuong trinh
int main(){
	MonHoc ds[200];
	int n;
	nhap_ds(ds,n);
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
				xuat_ds(ds,n);
				break;
			case 2: // sap xep danh sach mon hoc theo ngay thi
				sap_xep(ds,n);
				break;
			case 3:{ // tim mon hoc theo ten
			    string ten_mon;
                cout << "Nhap ten mon hoc can tim: ";
                cin.ignore();
                getline(cin, ten_mon);
				tim_ten_mon(ds, n, ten_mon);
				break;}
			case 4:{ // tim mon hoc theo ma
			    string ma_mon;
                cout << "Nhap ma mon hoc can tim: ";
                cin.ignore();
                cin>>ma_mon;
				tim_ma_mon(ds,n, ma_mon);
				break;}
			case 5:{ // bo sung mon hoc vao danh sach
				int vi_tri;
				cout << "Nhap vi tri can bo sung: ";
				cin >> vi_tri;
				MonHoc a;
				a.nhap();
				bo_sung(ds, n, vi_tri, a);
				break;
			}
			case 6:{ // xoa mon hoc khoi danh sach
				int vi_tri;
				cout << "Nhap vi tri can xoa: ";
				cin >> vi_tri;
				xoa(ds, n, vi_tri);
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
