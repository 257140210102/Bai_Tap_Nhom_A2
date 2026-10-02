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
			Ma_Mon = ma;
			Ten_Mon = ten;
			So_Tin = tc;	        
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
		void nhap(); // thuoc tinh nhap
		void xuat(); // thuoc tinh xuat
		friend int so_sanh_theo_ngay(const MonHoc &a, const MonHoc &b);	
};
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
void MonHoc::nhap(){
	cout << "Nhap ma mon hoc: ";
	cin >> Ma_Mon;
	cout << "Nhap ten mon hoc: ";
	cin.ignore(); // dùng để xóa ký tự xuống dòng còn lại trong bộ đệm trước khi đọc chuỗi tiếp theo
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
void MonHoc::xuat(){
	cout<<left<<"|"<<setw(10)<<Ma_Mon<<"|"<<setw(25)<<Ten_Mon<<"|"<<setw(10)<<So_Tin<<"|"<<setw(10)<<Ngay_Thi<<"|"<<setw(7)<<Ca_Thi<<"|"<<setw(10)<<Phong_Thi<<"|"<<setw(13)<<So_Sinh_Vien<<"|"<<endl;
	cout <<"---------------------------------------------------------------------------------------" << endl;
}
int so_sanh_theo_ngay(const MonHoc &a, const MonHoc &b){
	string nam_thang_ngay_a, nam_thang_ngay_b;
	nam_thang_ngay_a = a.getNgayThi().substr(6,4) + a.getNgayThi().substr(3,2) + a.getNgayThi().substr(0,2);
	nam_thang_ngay_b = b.getNgayThi().substr(6,4) + b.getNgayThi().substr(3,2) + b.getNgayThi().substr(0,2);
	if(nam_thang_ngay_a < nam_thang_ngay_b) 
		return -1;
	else 
		if(nam_thang_ngay_a > nam_thang_ngay_b) 
			return 1;
		else 
			return 0;
}
void QuanLyDanhSach::nhap_ds(){
	cout << "Nhap so luong mon hoc: ";
	cin >> n;
	for(int i=0; i<n; i++){
		cout << "Nhap thong tin mon hoc thu " << i+1 << endl;
		ds[i].nhap();
	}
}
void QuanLyDanhSach::xuat_ds(){
	cout <<"---------------------------------------------------------------------------------------" << endl;
	cout << left <<"|"<< setw(10) << "Ma MH" <<"|"<< setw(25) << "Ten MH" <<"|"<< setw(10) << "So TC" <<"|"<< setw(10) << "Ngay Thi" <<"|"<< setw(7) << "Ca Thi" <<"|"<< setw(10) << "Phong Thi" <<"|"<< setw(13) << "So Sinh Vien" <<"|"<< endl;
	cout <<"---------------------------------------------------------------------------------------" << endl;
	for(int i=0; i<n; i++)
		ds[i].xuat();
}
void QuanLyDanhSach::sap_xep(){
	for(int i=0; i<n-1; i++){
		for(int j=i+1; j<n; j++){
			if(so_sanh_theo_ngay(ds[i], ds[j]) > 0){
				MonHoc temp = ds[i];
				ds[i] = ds[j];
				ds[j] = temp;
			}
		}
	}
}
void QuanLyDanhSach::tim_ten_mon(){
	string ten_mon;
	cout << "Nhap ten mon hoc can tim: ";
	cin.ignore();
	getline(cin, ten_mon);
	bool found = false;
	int c=0;
	for(int i=0; i<n; i++){
		if(ds[i].getTenMon() == ten_mon){
			if((++c)==1){
				cout <<"---------------------------------------------------------------------------------------" << endl;
				cout << left <<"|"<< setw(10) << "Ma MH" <<"|"<< setw(25) << "Ten MH" <<"|"<< setw(10) << "So TC" <<"|"<< setw(10) << "Ngay Thi" <<"|"<< setw(7) << "Ca Thi" <<"|"<< setw(10) << "Phong Thi" <<"|"<< setw(13) << "So Sinh Vien" <<"|"<< endl;
				cout <<"---------------------------------------------------------------------------------------" << endl;
			}
			ds[i].xuat();
			found = true;
		}
	}
	if(!found){
		cout << "Khong tim thay mon hoc voi ten: " << ten_mon << endl;
	}
}
void QuanLyDanhSach::tim_ma_mon(){
	string ma_mon;
	cout << "Nhap ma mon hoc can tim: ";
	cin >> ma_mon;
	bool found = false;
	int c=0;
	for(int i=0; i<n; i++){
		if(ds[i].getMaMon() == ma_mon){
			if((++c)==1){
				cout <<"---------------------------------------------------------------------------------------" << endl;
				cout << left <<"|"<< setw(10) << "Ma MH" <<"|"<< setw(25) << "Ten MH" <<"|"<< setw(10) << "So TC" <<"|"<< setw(10) << "Ngay Thi" <<"|"<< setw(7) << "Ca Thi" <<"|"<< setw(10) << "Phong Thi" <<"|"<< setw(13) << "So Sinh Vien" <<"|"<< endl;
				cout <<"---------------------------------------------------------------------------------------" << endl;
			}
			ds[i].xuat();
			found = true;
		}
	}
	if(!found){
		cout << "Khong tim thay mon hoc voi ma: " << ma_mon << endl;
	}
}
void QuanLyDanhSach::bo_sung(int vi_tri, MonHoc a){
	if(vi_tri < 0 || vi_tri > n){
		cout << "Vi tri khong hop le!" << endl;
		return;
	}
	for(int i=n; i>vi_tri; i--){
		ds[i] = ds[i-1];
	}
	ds[vi_tri] = a;
	n++;
}
void QuanLyDanhSach::xoa(int vi_tri){
	if(vi_tri < 0 || vi_tri >= n){
		cout << "Vi tri khong hop le!" << endl;
		return;
	}
	for(int i=vi_tri; i<n-1; i++){
		ds[i] = ds[i+1];
	}
	n--;
}
int main(){
	QuanLyDanhSach ql;
	ql.nhap_ds();
	while(true){
		cout << "1. Xuat danh sach mon hoc" << endl;
		cout << "2. Sap xep danh sach theo ngay thi" << endl;
		cout << "3. Tim mon hoc theo ten" << endl;
		cout << "4. Tim mon hoc theo ma" << endl;
		cout << "5. Bo sung mon hoc vao danh sach" << endl;
		cout << "6. Xoa mon hoc khoi danh sach" << endl;
		cout << "0. Thoat" << endl;
		int choice;
		cout << "Nhap lua chon: ";
		cin >> choice; cout<<choice<<endl;
		switch(choice){
			case 1:
				ql.xuat_ds();
				break;
			case 2:
				ql.sap_xep();
				cout << "Danh sach da duoc sap xep theo ngay thi." << endl;
				ql.xuat_ds();
				break;
			case 3:
				ql.tim_ten_mon();
				break;
			case 4:
				ql.tim_ma_mon();
				break;
			case 5:{
				int vi_tri;
				cout << "Nhap vi tri can bo sung: ";
				cin >> vi_tri;
				MonHoc a;
				a.nhap();
				ql.bo_sung(vi_tri, a);
				ql.xuat_ds();
				break;
			}
			case 6:{
				int vi_tri;
				cout << "Nhap vi tri can xoa: ";
				cin >> vi_tri;
				ql.xoa(vi_tri);
				ql.xuat_ds();
				break;
			}
			case 0:
				return 0;
			default:
				cout << "Lua chon khong hop le!" << endl;
		}
	}
	return 0;		
} 
