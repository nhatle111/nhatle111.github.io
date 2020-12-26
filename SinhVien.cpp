#include "SinhVien.h"
string SinhVien::getKhoaHoc()
{
	return this->khoaHoc;
}
void SinhVien::setKhoaHoc(string khoaHoc)
{
	this->khoaHoc = khoaHoc;
}
void SinhVien::XuatBanDoc()
{
	
	cout << left << setw(20) << this->maBanDoc << setw(25) << this->hoTen << setw(25) <<
		this->khoa << setw(25) << this->khoaHoc << this->ngayThamGia.Ngay << "," << this->ngayThamGia.Thang << ","
		<< this->ngayThamGia.Nam << endl;
}
ostream& operator<<(ostream& out, SinhVien& sv)
{
	out <<left<<setw(20)<< sv.maBanDoc << setw(25) << sv.hoTen << setw(25) << sv.khoa << setw(25) << sv.khoaHoc << sv.ngayThamGia.getNgay() << "/" << sv.ngayThamGia.getThang() << "/" << sv.ngayThamGia.getNam() <<endl;
	return out;
}
void SinhVien::nhapSinhVienMoi()
{
	cout << "\t\t\tNhap ma sinh vien:(MSVXXX) ";
	rewind(stdin);
	getline(cin, maBanDoc);
	cout << "\t\t\tNhap ho va ten sinh vien: ";
	rewind(stdin);
	getline(cin, hoTen);
	cout << "\t\t\tNhap khoa sinh vien: ";
	rewind(stdin);
	getline(cin, khoa);
	cout << "\t\t\tNhap Khoa hoc sinh vien: ";
	rewind(stdin);
	getline(cin, khoaHoc);
	cout << "\t\t\tNhap ngay tham gia thu vien : " << endl;
	cout << "\t\t\tNhap ngay: ";
	cin >> ngayThamGia.Ngay;
	cout << "\t\t\tNhap thang: ";
	cin >> ngayThamGia.Thang;
	cout << "\t\t\tNhap nam: ";
	cin >> ngayThamGia.Nam;
	cout << endl;
	ofstream ifs;
	ifs.open("SVien.txt", ios::app);
	ifs << maBanDoc << endl;
	ifs << hoTen << endl;
	ifs << khoa << endl;
	ifs << ngayThamGia.Ngay << "/" << ngayThamGia.Thang << "/" << ngayThamGia.Nam << endl;
	ifs.close();
}
void SinhVien::readBanDoc(ifstream& ifs)
{
	fflush(stdin);
	getline(ifs, this->maBanDoc);
	fflush(stdin);
	getline(ifs, this->hoTen);
	fflush(stdin);
	getline(ifs, this->khoa);
	fflush(stdin);
	getline(ifs, this->khoaHoc);
	ifs >> ngayThamGia.Ngay;
	ifs.ignore(1);
	ifs >> ngayThamGia.Thang;
	ifs.ignore(1);
	ifs >> ngayThamGia.Nam;
	ifs.ignore(1);
}
void SinhVien::writeBanDoc(ofstream& ifs)
{
	ifs << this->maBanDoc << endl;
	ifs << this->hoTen << endl;
	ifs << this->khoa << endl;
	ifs << this->khoaHoc << endl;
	ifs	<< this->ngayThamGia.Ngay << "/" << this->ngayThamGia.Thang << "/"<< this->ngayThamGia.Nam<<endl;
}
