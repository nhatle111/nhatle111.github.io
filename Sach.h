#include "Date.h"
#include <string>
#pragma once
using namespace std;
class Sach
{
private:
	string maSach, tieuDe, tacGia, nhaXuatBan;
	float giaBan;
	int namPhatHanh, soTrang;
	Date ngayNhapKho;
	int tinhTrang;
public:
	/*friend PHIEUMUON;*/
	Sach()
	{
		this->maSach = "";
		this->tieuDe = "";
		this->tacGia = "";
		this->nhaXuatBan = "";
		this->giaBan = 0;
		this->namPhatHanh = 0;
		this->soTrang = 0;
		this->tinhTrang = 0;
	}
	Sach(string maSach) :ngayNhapKho()
	{
		this->maSach = maSach;
		this->tieuDe = "";
		this->tacGia = "";
		this->nhaXuatBan = "";
		this->giaBan = 0;
		this->namPhatHanh = 0;
		this->soTrang = 0;
		this->tinhTrang = 0;
	}
	Sach(string maSach, string tieuDe, string tacGia, string nhaXuatBan, float giaBan, int namPhatHanh, int soTrang, int Ngay, int Thang, int Nam, int tinhTrang)
		:ngayNhapKho(Ngay, Thang, Nam)
	{
		this->maSach = maSach;
		this->tieuDe = tieuDe;
		this->tacGia = tacGia;
		this->nhaXuatBan = nhaXuatBan;
		this->giaBan = giaBan;
		this->namPhatHanh = namPhatHanh;
		this->soTrang = soTrang;
		this->tinhTrang = 0;
	}
	Sach(string maSach, string tieuDe, string tacGia, string nhaXuatBan, float giaBan, int namPhatHanh, int soTrang, int tinhTrang)
	{
		this->maSach = maSach;
		this->tieuDe = tieuDe;
		this->tacGia = tacGia;
		this->nhaXuatBan = nhaXuatBan;
		this->giaBan = giaBan;
		this->namPhatHanh = namPhatHanh;
		this->soTrang = soTrang;
		this->tinhTrang = 0;
	}
	string getMaSach()
	{
		return this->maSach;
	}
	string getTieuDe()
	{
		return this->tieuDe;
	}
	string getTacGia()
	{
		return this->tacGia;
	}
	string getNXB()
	{
		return this->nhaXuatBan;
	}
	float getGiaBan()
	{
		return this->giaBan;
	}
	int getNamPhatHanh()
	{
		return this->namPhatHanh;
	}
	int getSoTrang()
	{
		return this->soTrang;
	}
	Date getNgayNhapKho()
	{
		return this->ngayNhapKho;
	}
	int getTinhTrang()
	{
		return this->tinhTrang;
	}
	void setTinhTrangSach(int tinhTrang)
	{
		this->tinhTrang = tinhTrang;
	}
	friend ostream& operator<<(ostream& out, Sach& sach);
	void outputSach();
	void writeSach(ofstream& file);
	void readSach(ifstream& file);
	void nhapSachMoi();
	~Sach() {};
};




