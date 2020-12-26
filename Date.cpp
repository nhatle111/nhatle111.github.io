#include "Date.h"
int Date::getNgay()
{
	return this->Ngay;
}
int Date::getThang()
{
	return this->Thang;
}
int Date::getNam()
{
	return this->Nam;
}
void Date::setNgay(int Ngay)
{
	this->Ngay = Ngay;
}
void Date::setThang(int Thang)
{
	this->Thang = Thang;
}
void Date::setNam(int Nam)
{
	this->Nam = Nam;
}
void Date::setDate(int Ngay, int Thang, int Nam)
{
	this->Ngay = Ngay;
	this->Thang = Thang;
	this->Nam = Nam;
}
void Date::outputNgay()
{
	cout << this->Ngay << "/" << this->Thang << "/" << this->Nam << endl;
}
istream& operator >> (istream& in, Date& d)
{
	cout << "Nhap ngay: ";
	in >> d.Ngay;
	cout << "Nhap thang: ";
	in >> d.Thang;
	cout << "Nhap nam: ";
	in >> d.Nam;
	return in;
}
ostream& operator << (ostream& out, Date& d)
{
	out << d.Ngay << "," << d.Thang << "," << d.Nam << endl;
	return out;
}


