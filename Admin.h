#ifndef ADMIN_H
#define ADMIN_H
#include <iostream>
using namespace std;
#include <string>
#include <fstream>
#pragma once
class Admin
{
private:
	string TaiKhoan;
	string MatKhau;
public:
	Admin()
	{
		TaiKhoan = "";
		MatKhau = "";
	}
	Admin(string TaiKhoan, string MatKhau)
	{
		this->TaiKhoan = TaiKhoan;
		this->MatKhau = MatKhau;
	}
	string getTaiKhoan();
	string getMatKhau();
	void setTaiKhoan(string TaiKhoan);
	void setMatKhau(string MatKhau);
	void setDangNhap(string TaiKhoan, string MatKhau);
	void docAd(ifstream& file);
	friend ostream& operator << (ostream& out, Admin& Ad);
	~Admin() {};
};
#endif // 
