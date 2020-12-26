#ifndef BANDOC_H
#define BANDOC_H
#include <string>
#include <iostream>
using namespace std;
#include <fstream>
#include <windows.h>
#include "Date.h"
//class PHIEUMUON;
class BanDoc
{
protected:
	string hoTen, khoa, maBanDoc;
	Date ngayThamGia;
public:
	/*friend PHIEUMUON;*/
	BanDoc()
	{
		this->hoTen = "";
		this->khoa = "";
		this->maBanDoc = "";
	}
	BanDoc(string maBanDoc) {
		this->hoTen = "";
		this->khoa = "";
		this->maBanDoc = maBanDoc;
	}
	BanDoc(string maBanDoc, string hoTen, string khoa, int Ngay, int Thang, int Nam) : ngayThamGia(Ngay, Thang, Nam)
	{
		this->hoTen = hoTen;
		this->khoa = khoa;
		this->maBanDoc = maBanDoc;
	}
	string getHoTen();
	string getKhoa();
	string getMaBanDoc();
	void setHoTen(string hoTen);
	void setKhoa(string khoa);
	void setMaBanDoc(string maBanDoc);
	void setBanDoc(string hoTen, string khoa, string maBanDoc);

	virtual void NhapBanDoc() {}
	virtual void XuatBanDoc() {};
	virtual void DocBanDoc(ifstream& ifs) {};
	virtual void GhiBanDoc(ofstream& ifs) {};
	/*void xuatBanDoc();*/
	virtual ~BanDoc() {};
};
#endif 
