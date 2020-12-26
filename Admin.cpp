#include "Admin.h"
string Admin::getTaiKhoan()
{
	return this->TaiKhoan;
}
string Admin::getMatKhau()
{
	return this->MatKhau;
}
void Admin::setTaiKhoan(string TaiKhoan)
{
	this->TaiKhoan = TaiKhoan;
}
void Admin::setMatKhau(string MatKhau)
{
	this->MatKhau = MatKhau;
}
void Admin::setDangNhap(string TaiKhoan, string MatKhau)
{
	this->TaiKhoan = TaiKhoan;
	this->MatKhau = MatKhau;
}
void Admin::docAd(ifstream& file)
{
	string TaiKhoan;
	string MatKhau;
	fflush(stdin);
	getline(file, TaiKhoan);
	fflush(stdin);
	getline(file, MatKhau);
	this->setTaiKhoan(TaiKhoan);
	this->setMatKhau(MatKhau);
}

ostream& operator << (ostream& out, Admin& Ad)
{
	out << "Tai Khoan: " << Ad.TaiKhoan << endl;
	out << "Mat Khau: " << Ad.MatKhau << endl;
	return out;
}
void Doc_file(Admin Ad[])
{
	ifstream ifs("D://Admin.txt", ios::in);
	int n = 0;
	//Khai bao cac bien:
	ifs >> n;
	ifs.ignore(1);
	for (int i = 0; i < n; i++)
		Ad[i].docAd(ifs);
	cout << "Thong tin cac Admin  " << endl;
	for (int i = 0; i < n; i++) {
		cout << "Thong tin admin thu " << i + 1 << " la : " << endl;
		cout << Ad[i];
	}
	//Ad.push_back(Admin);

	ifs.close();
}
