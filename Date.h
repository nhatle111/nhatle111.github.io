#ifndef DATE_H
#define DATE_H
#include <iostream>
#include <iomanip>
#include <vector>
#pragma warning(disable : 4996)
#define _CRT_SECURE_NO_WARNING
#include <ctime>
#include <time.h>
#include <fstream>
#include <conio.h>
#include <stdio.h>
#include <dos.h>
using namespace std;
class Sach;
class BanDoc;
class SinhVien;
class GiaoVien;
class Date
{
protected:
	int Ngay, Thang, Nam;
public:
	friend Sach;
	friend BanDoc;
	friend SinhVien;
	friend GiaoVien;

	Date()
	{
		time_t rawtime;
		struct tm* info;
		char buffer[80];
		time(&rawtime);
		info = localtime(&rawtime);
		this->Ngay = (info->tm_mday);
		this->Thang = (info->tm_mon + 1);
		this->Nam = (info->tm_year + 1900);
	}
	Date(int Ngay, int Thang, int Nam)
	{
		this->Ngay = Ngay;
		this->Thang = Thang;
		this->Nam = Nam;
	}
	int getNgay();
	int getThang();
	int getNam();
	void setNgay(int Ngay);
	void setThang(int Thang);
	void setNam(int Nam);
	void setDate(int Ngay, int Thang, int Nam);
	void outputNgay();
	friend istream& operator >> (istream& in, Date& d);
	friend ostream& operator << (ostream& out, Date& d);
	virtual ~Date() {};
};

#endif 
