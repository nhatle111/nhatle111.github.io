
#include "BanDoc.h"
#pragma once
class SinhVien : public BanDoc
{
private:
	string khoaHoc;
public:
	SinhVien()
	{
		khoaHoc = "";
	}
	SinhVien(string khoaHoc)
	{
		this->khoaHoc = khoaHoc;
	}
	SinhVien(string maBanDoc, string hoTen, string khoa, string khoaHoc, int Ngay, int Thang, int Nam) :BanDoc(maBanDoc, hoTen, khoa, Ngay, Thang, Nam)
	{
		this->khoaHoc = khoaHoc;
	}
	string getKhoaHoc();
	void setKhoaHoc(string khoaHoc);
	/*void inputBanDoc();*/
	void XuatBanDoc();
	friend ostream& operator<<(ostream& out, SinhVien& sv);
	void nhapSinhVienMoi();
	void readBanDoc(ifstream& ifs);
	void writeBanDoc(ofstream& ifs);
	~SinhVien() {};
};

