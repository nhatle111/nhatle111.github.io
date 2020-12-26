#include "Sach.h"
#include<iomanip>
void Sach::outputSach()
{
	cout << left << setw(10) << this->maSach << setw(25) << this->tieuDe << setw(25) << this->tacGia << setw(25) << this->nhaXuatBan << setw(15) << this->giaBan << setw(15) << this->namPhatHanh << setw(15) << this->soTrang << this->ngayNhapKho.Ngay << "/" << this->ngayNhapKho.Thang << "/" <<setw(10)<< this->ngayNhapKho.Nam << setw(20) << this->tinhTrang << endl;

}

void Sach::writeSach(ofstream& file)
{
	file << this->getMaSach() << endl;
	file << this->getTieuDe() << endl;
	file << this->getTacGia() << endl;
	file << this->getNXB() << endl;
	file << this->getGiaBan() << endl;
	file << this->getNamPhatHanh() << endl;
	file << this->getSoTrang() << endl;
	file << this->getNgayNhapKho().getNgay() << "/" << this->getNgayNhapKho().getThang() << "/" << this->getNgayNhapKho().getNam() << endl;
	file << this->getTinhTrang() << endl;
}

void Sach::readSach(ifstream& file)
{
	fflush(stdin);
	getline(file, maSach);
	fflush(stdin);
	getline(file, tieuDe);
	fflush(stdin);
	getline(file, tacGia);
	fflush(stdin);
	getline(file, nhaXuatBan);
	file >> giaBan;
	file.ignore(1);
	file >> namPhatHanh;
	file.ignore(1);
	file >> soTrang;
	file.ignore(1);
	file >> ngayNhapKho.Ngay;
	file.ignore(1);
	file >> ngayNhapKho.Thang;
	file.ignore(1);
	file >> ngayNhapKho.Nam;
	file.ignore(1);
	file >> tinhTrang;
	file.ignore(1);
}

ostream& operator<<(ostream& out, Sach& sach)
{
	out << left << setw(10) << sach.maSach << setw(25) << sach.tieuDe << setw(25) << sach.tacGia << setw(25) << sach.nhaXuatBan << setw(15) << sach.giaBan << setw(15) << sach.namPhatHanh << setw(15) << sach.soTrang
		<< sach.ngayNhapKho.getNgay() << "/" << sach.ngayNhapKho.getThang() << "/" <<setw(10)<< sach.ngayNhapKho.getNam() << setw(20) << sach.tinhTrang << endl;
	return out;
}

void Sach::nhapSachMoi()
{
	rewind(stdin);
	cout << "\t\t\tNhap ma sach:(MSSXXX) ";
	rewind(stdin);
	getline(cin, maSach);
	cout << "\t\t\tNhap Tieu de sach: ";
	fflush(stdin);
	getline(cin, tieuDe);
	cout << "\t\t\tNhap tac gia: ";
	fflush(stdin);
	getline(cin, tacGia);
	cout << "\t\t\tNhap nha xuat ban: ";
	fflush(stdin);
	getline(cin, nhaXuatBan);
	cout << "\t\t\tNhap gia ban: ";
	cin >> giaBan;
	cout << "\t\t\tNhap nam phat hanh: ";
	cin >> namPhatHanh;
	cout << "\t\t\tNhap so trang: ";
	cin >> soTrang;
	cout << "\t\t\tNhap ngay nhap kho: ";
	cin >> ngayNhapKho.Ngay;
	cout << "\t\t\tNhap thang nhap kho: ";
	cin >> ngayNhapKho.Thang;
	cout << "\t\t\tNhap nam nhap kho: ";
	cin >> ngayNhapKho.Nam;
	cout << "\t\t\tNhap tinh trang (0,1): ";
	cin >> tinhTrang;
	ofstream ifs;
	ifs.open("Sach.txt", ios::app);
	ifs << maSach << endl;
	ifs << tieuDe << endl;
	ifs << tacGia << endl;
	ifs << nhaXuatBan << endl;
	ifs << giaBan << endl;
	ifs << namPhatHanh << endl;
	ifs << soTrang << endl;
	ifs << ngayNhapKho.Ngay << "/" << ngayNhapKho.Thang << "/" << ngayNhapKho.Nam << endl;
	ifs << tinhTrang << endl;
	ifs.close();
}
