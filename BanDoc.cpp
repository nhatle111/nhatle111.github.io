#include "BanDoc.h"
string BanDoc::getHoTen()
{
	return this->hoTen;
}
string BanDoc::getKhoa()
{
	return this->khoa;
}
string BanDoc::getMaBanDoc()
{
	return this->maBanDoc;
}
void BanDoc::setHoTen(string hoTen)
{
	this->hoTen = hoTen;
}
void BanDoc::setKhoa(string khoa)
{
	this->khoa = khoa;
}
void BanDoc::setMaBanDoc(string maBanDoc)
{
	this->maBanDoc = maBanDoc;
}
void BanDoc::setBanDoc(string hoTen, string khoa, string maBanDoc)
{
	this->hoTen = hoTen;
	this->khoa = khoa;
	this->maBanDoc = maBanDoc;
}


