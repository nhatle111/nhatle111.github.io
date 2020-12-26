#include "GiaoVien.h"
#include<string>

string GiaoVien::getDiachi()
{
	return this->diaChi;
}
string GiaoVien::getSoDT()
{
	return this->soDT;
}
void GiaoVien::setDiaChi(string diaChi)
{
	this->diaChi = diaChi;
}
void GiaoVien::setSoDT(string soDT)
{
	this->soDT = soDT;
}
void GiaoVien::setGiaoVien(string diaChi, string soDT)
{
	this->diaChi = diaChi;
	this->soDT = soDT;
}
void GiaoVien::XuatBanDoc()
{
	cout << left << setw(20) << this->maBanDoc << setw(25) << this->hoTen << setw(25) <<
		this->khoa << setw(25) << this->diaChi << setw(25) << this->soDT << this->ngayThamGia.Ngay << "/" << this->ngayThamGia.Thang << "/"
		<< this->ngayThamGia.Nam << endl;
}
ostream& operator<<(ostream& out, GiaoVien& gv)
{
	out << left << setw(20) << gv.maBanDoc << setw(25) << gv.hoTen << setw(25) << gv.khoa << setw(25) << gv.diaChi << setw(25)
		<< gv.soDT << gv.ngayThamGia.getNgay()
		<< "/" << gv.ngayThamGia.getThang() << "/" << gv.ngayThamGia.getNam() << endl;
	return out;
}
void GiaoVien::readBanDoc(ifstream& ifs)
{
	rewind(stdin);
	getline(ifs, this->maBanDoc);
	rewind(stdin);
	getline(ifs, this->hoTen);
	rewind(stdin);
	getline(ifs, this->khoa);
	rewind(stdin);
	getline(ifs, this->diaChi);
	rewind(stdin);
	getline(ifs, this->soDT);
	ifs >> ngayThamGia.Ngay;
	ifs.ignore(1);
	ifs >> ngayThamGia.Thang;
	ifs.ignore(1);
	ifs >> ngayThamGia.Nam;
	ifs.ignore(1);
}
void GiaoVien::writeBanDoc(ofstream& ifs)
{
	
	ifs << this->maBanDoc << endl;
	ifs << this->hoTen << endl; 
	ifs << this->khoa << endl;
	ifs << this->diaChi << endl;
	ifs << this->soDT << endl;
	ifs << this->ngayThamGia.Ngay << "/" << this->ngayThamGia.Thang << "/"<< this->ngayThamGia.Nam<<endl;
}

void GiaoVien::nhapGiaoVienMoi()
{
	cout << "\t\t\tNhap ma giao vien(MGVXXX): ";
	rewind(stdin);
	getline(cin, maBanDoc);
	cout << "\t\t\tNhap ho ten giao vien: ";
	rewind(stdin);
	getline(cin, hoTen);
	cout << "\t\t\tNhap khoa giao vien: ";
	rewind(stdin);
	getline(cin, khoa);
	cout << "\t\t\tNhap dia chi: ";
	rewind(stdin);
	getline(cin, diaChi);
	cout << "\t\t\tNhap so dienthoai: ";
	cin >> soDT;
	cout << "\t\t\tnhap ngay tham gia: "<<endl;
	cout << "\t\t\tnhap ngay: ";
	cin >> ngayThamGia.Ngay;
	cout << "\t\t\tnhap thang: ";
	cin >> ngayThamGia.Thang;
	cout << "\t\t\tnhap nam: ";
	cin >> ngayThamGia.Nam;
	cout << endl;
	ofstream ifs;
	ifs.open("GiaoVien.txt", ios::app);
	ifs << maBanDoc << endl;
	ifs << hoTen << endl;
	ifs << khoa << endl;
	ifs << diaChi << endl;
	ifs << soDT << endl;
	ifs << ngayThamGia.Ngay << "/" << ngayThamGia.Thang<< "/" << ngayThamGia.Nam << endl; 
	ifs.close();
}
