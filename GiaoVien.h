#pragma once
#include "BanDoc.h"
class GiaoVien :public BanDoc
{
private:
	string diaChi, soDT;
public:
	GiaoVien()
	{
		diaChi = "";
		soDT = 1;
	}
	GiaoVien(string maBanDoc, string hoTen, string khoa, string diaChi, string soDT, int Ngay, int Thang, int Nam) :BanDoc(maBanDoc, hoTen, khoa, Ngay, Thang, Nam)
	{
		this->diaChi = diaChi;
		this->soDT = soDT;
	}
	string getDiachi();
	string getSoDT();
	void setDiaChi(string diaChi);
	void setSoDT(string soDT);
	void setGiaoVien(string diaChi, string soDT);
	/*void inputBanDoc();*/
	void XuatBanDoc();
	friend ostream& operator<<(ostream& out, GiaoVien& gv);
	void nhapGiaoVienMoi();
	void readBanDoc(ifstream& ifs);
	void writeBanDoc(ofstream& ifs);
	~GiaoVien() {};
};

