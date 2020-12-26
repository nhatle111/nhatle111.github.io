
#include "Admin.h"
#include "Date.h"
#include "Sach.h"
#include "GiaoVien.h"
#include "SinhVien.h"
#include "PhieuMuon.h"
#include <vector>
#include <conio.h>
#include <windows.h>
#include<iomanip>
#pragma once
//Lo?i b? l?i c?nh b�o khi ch?y chuong tr�nh
#pragma warning(disable: 4996)
#define _CRT_SECURE_NO_WARNINGS

//Khai bao nguyen mau ham con:
//Set mau:
void SetColor(int ForgC);

//Admin:
void docTKvaMK();
bool kiemTraDN(string taikhoan, string matkhau);
void login();
string maHoaMK(unsigned int maxLength);

//Menu:
void menuChinh();
void menu();

//SACH :
void docDSSach(vector<Sach> &S);
void xuatDSSach(vector<Sach> S);
void ghiDSSach(vector<Sach> S);
void themSachfile();
int kTraSach(string tuaDe);
void timSach();
bool tinhTrangSach(string masach);
void xoaSach();

//BAN DOC:
void docDSPhieuMuon(vector<PhieuMuon> &Pm);
void ghiDSPhieu(vector<PhieuMuon> Pm);
void xuatDSPhieuMuon( vector <PhieuMuon> Pm);
void xoaPhieuMuon();
void themphieufile();
bool tinhTrangPhieu(string maphieu);

void docDSSV(vector <SinhVien> &Sv);
void xuatDSSV(vector <SinhVien> Sv);
void ghiDSSV(vector<SinhVien> Sv);
void themDSSVfile();
void docDSGV(vector <GiaoVien> &Gv);
void ghiDSGV(vector<GiaoVien> Gv);
void themDSGVfile();
void xuatDSGV(vector <GiaoVien> Gv);
int kTraBanDocGV(vector<GiaoVien> Gv, string maBanDoc);
void timBanDocGV();
int kTraBanDocSV(string maBanDoc);
void timBanDocSV();
void timBanDoc();

//CHUC NANG:
void timKiemThongtin();

//QUAN LY:
void quanLyThuVien();
void quanLyBanDoc();
void quanLySach();
void quanLyPhieuMuon();

//Thong Ke
void tongSachMuon();
void tongSachChuaMuon();
void thongKe();

//KHAI BAO BIEN:
vector <Admin> Ad;
vector <Sach> S;
vector <GiaoVien> Gv;
vector <SinhVien> Sv;
vector <PhieuMuon> Pm;

//CHUONG TRINH CHINH:
void main()
{
	docDSSach(S);
	docTKvaMK();
	docDSGV(Gv);
	docDSSV(Sv);
	docDSPhieuMuon(Pm);
	menuChinh();
	//ghiDSSach(S);
	system("pause");
}

//*******************************************************MENU QUAN LY PHIEU MUON***************************************************************************************************/
void quanLyPhieuMuon()
{
	PhieuMuon p;
	//p.docThongtin();
	ofstream fcout;
	ifstream fcin;
	int n = 0;
	fcin.open("PhieuMuon.txt");
	fcin >> n;
	fcin.ignore(1);
	int quanly = 0;
	do {
		SetColor(9);
		cout << "\t\t\t________________QUAN LY PHIEU MUON______________\n";
		cout << "\t\t\t **********************************************\n";
		SetColor(11);
		cout << "\t\t\t 1. XEM DANH SACH PHIEU MUON \t\n";
		cout << "\t\t\t 2. TAO PHIEU MUON MOI \t\n";
		cout << "\t\t\t 3. TRA SACH \t\n";
		cout << "\t\t\t 4. THOAT \t\n";
		SetColor(9);
		cout << "\t\t\t***********************************************\n";
		SetColor(11);
		cout << "\t\t\tBan hay chon chuc nang can quan ly: ";
		cin >> quanly;
		switch (quanly)
		{
		case 1:
			system("cls");
			xuatDSPhieuMuon(Pm);
			system("pause");
			system("cls");
			break;
		case 2:
			system("cls");
			SetColor(14);
			themphieufile();
			//p.nhapPhieuMuonMoi();
			SetColor(18);
			cout << "\t\t\tTAO PHIEU MUON THANH CONG!";
			system("pause");
			system("cls");
			break;
		case 3:
			xoaPhieuMuon();

		default:
			SetColor(20);
			cout << "\t\t\tBAN CHON THOAT QUAN LY PHIEU MUON!\n";
			Sleep(1000);
			system("cls");
			quanLyThuVien();
			break;
		}
	} while (quanly >= 1 && quanly <= 3);
}
///////////******************************************HAM KIEM TRA TINH TRANG SACH**************************************************************************
bool tinhTrangSach(string masach)
{
	for (int i = 0; i < S.size(); i++)
	{
		if (S[i].getMaSach() == masach && S[i].getTinhTrang() == 0)
		{
			return true;
		}
	}
	return false;
}
/////**************************************************HAM KIEM TRA TINH TRANG PHIEU********************************************************************* 
bool tinhTrangPhieu(string maphieu)
{
	for (int i = 0; i < Pm.size(); i++)
	{
		if (Pm[i].getMaPhieu() == maphieu&& Pm[i].tinhtrang == 1)
		{
			return true;
		}
	}
	return false;
}
///**********************************************************HAM XOA SACH*****************************************************************************************
void xoaSach()
{
	string masach = "";
	do
	{
		SetColor(14);
		cout << "\t\t\tNhap ma sach: ";
		rewind(stdin);
		getline(cin, masach);
	} while (tinhTrangSach(masach) == 0);
	for (int i = 0; i < S.size(); i++)
	{
		if (masach == S[i].getMaSach())
		{
			S.erase(S.begin() + i);
			ghiDSSach(S); 
			break;
		}
	}
	SetColor(18);
	cout << "\t\t\tXoa thanh cong." << endl;
}
//*********************************************HAM XOA PHIEU MUON(ham tra sach )*************************************************************************************************
 void xoaPhieuMuon()
{
	string maphieu = "";
	do
	{
		SetColor(14);
		cout << "\t\t\tNhap ma phieu: ";
		rewind(stdin);
		getline(cin, maphieu);
	} while (tinhTrangPhieu(maphieu) == 0);
	for (int i = 0; i < Pm.size(); i++)
	{
		if (maphieu ==Pm[i].getMaPhieu() )
		{
			Pm.erase(Pm.begin() + i);
			ghiDSPhieu(Pm);
			break;
		}
	}
	SetColor(10);
	cout << "\t\t\tXoa thanh cong" << endl;
}
//***************************************************************************MENU QUAN LY SACH***********************************************************************************************
void quanLySach()
{
	Sach s;
	ofstream fcout;
	ifstream fcin;
	int n = 0;
	fcin.open("Sach.txt");
	fcin >> n;
	fcin.ignore(1);
	int quanly = 0;
	do {
		SetColor(9);
		cout << "\t\t\t__________________QUAN LY SACH_______________\n";
		cout << "\t\t\t*********************************************\n";
		SetColor(11);
		cout << "\t\t\t 1. XEM DANH SACH SACH \t\n";
		cout << "\t\t\t 2. THEM SACH MOI \t\n";
		cout << "\t\t\t 3. XOA SACH \t\n";
		cout << "\t\t\t 4. THOAT \t\n";
		SetColor(9);
		cout << "\t\t\t*********************************************\n";
		SetColor(14);
		cout << "\t\t\tBan hay chon chuc nang can quan ly: ";
		cin >> quanly;
		switch (quanly)
		{
		case 1:
			system("cls");
			xuatDSSach(S);
			system("pause");
			system("cls");
			break;
		case 2:
			system("cls");
			//s.nhapSachMoi();
			themSachfile();
			SetColor(18);
			cout << "\t\t\tTHEM GIAO VIEN THANH CONG!";
			system("pause");
			system("cls");
			break;
		case 3:
			xoaSach();
			break;
		default:
			SetColor(20);
			cout << "\t\t\tBAN CHON THOAT QUAN LY SACH!\n";
			Sleep(1000);
			system("cls");
			quanLyThuVien();
			break;
		}
	} while (quanly >= 1 && quanly <= 3);
}
//***********************************************************************MENU QUAN LY BAN DOC*************************************************************************************************
void quanLyBanDoc()
{
	GiaoVien giaovien;
	SinhVien sinhvien;
	ofstream fcout;
	ifstream fcin;
	int n = 0;
	fcin.open("SVien.txt");
	fcin >> n;
	fcin.ignore(1);
	string maBD, hotenBD, khoaHocBD, ngay, thang, nam, diaChi;
	int soDT, soluong;
	int quanly = 0;
	do {
		SetColor(9);
		cout << "\t\t\t________________QUAN LY BAN DOC______________\n";
		cout << "\t\t\t*********************************************\n";
		SetColor(11);
		cout << "\t\t\t 1. XEM BAN DOC GIAO VIEN \t\n";
		cout << "\t\t\t 2. XEM BAN DOC SINH VIEN \t\n";
		cout << "\t\t\t 3. THEM BAN DOC GIAO VIEN \t\n";
		cout << "\t\t\t 4. THEM BAN DOC SINH VIEN \t\n";
		cout << "\t\t\t 5. THOAT \t\n";
		SetColor(9);
		cout << "\t\t\t*********************************************\n";
		SetColor(11);
		cout << "\t\t\tBan hay chon chuc nang can quan ly: ";
		cin >> quanly;
		switch (quanly)
		{
		case 1:
			system("cls");
			xuatDSGV(Gv);
			system("pause");
			system("cls");
			break;
		case 2:
			system("cls");
			xuatDSSV(Sv);
			system("pause");
			system("cls");
			break;
		case 3:
			SetColor(14);
			//giaovien.nhapGiaoVienMoi();
			themDSGVfile();
			SetColor(18);
			cout << "\t\t\tTHEM GIAO VIEN THANH CONG!";
			system("pause");
			system("cls");
			break;
		case 4:
			SetColor(14);
			//sinhvien.nhapSinhVienMoi();
			themDSSVfile();
			SetColor(18);
			cout << "\t\t\tTHEM SINH VIEN THANH CONG!";
			system("pause");
			system("cls");
			break;
		default:
			SetColor(20);
			cout << "\t\t\tBAN CHON THOAT QUAN LY BAN DOC!\n";
			Sleep(1000);
			system("cls");
			quanLyThuVien();
			break;
		}
	} while (quanly >= 1 && quanly <= 4);
}
//************************************************************MENU QUAN LY THU VIEN SAU KHI DANG NHAP********************************************************************************************
void quanLyThuVien()
{
	int quanly = 0;
	do
	{
		system("cls");
		SetColor(9);
		cout << "\t\t\t_______________QUAN LY THU VIEN______________\n";
		cout << "\t\t\t*********************************************\n";
		SetColor(11);
		cout << "\t\t\t 1. QUAN LY PHIEU MUON \t\n"; 
		cout << "\t\t\t 2. QUAN LY SACH \t\n"; 
		cout << "\t\t\t 3. QUAN LY BAN DOC \t\n"; 
		cout << "\t\t\t 4. THONG KE \t\n";
		cout << "\t\t\t 5. THOAT \t\n";
		SetColor(9);
		cout << "\t\t\t*********************************************\n";
		SetColor(14);
		cout << "\t\t\tBan hay chon chuc nang can quan ly: ";
		cin >> quanly;
		switch (quanly)
		{
		case 1:
			system("cls");
			quanLyPhieuMuon();	
			system("cls");
			break;
		case 2:
			system("cls");
			quanLySach(); 
			system("cls");
			break;
		case 3:
			system("cls");
			quanLyBanDoc();
			system("cls");
			break;
		case 4:
			thongKe();
			break;
		default:
			SetColor(20);
			cout << "\t\t\tBAN CHON THOAT QUAN LY!\n";
			Sleep(1000);
			system("cls");
			menu();
			menuChinh();
			break;
		}
	} while (quanly >= 1 && quanly <= 4);
}
//**************************************************************************HAM TINH TONG CAC SACH DA DUOC MUON*******************************************************************************************
void tongSachMuon()
{
	int tong = 0;
	for (int i = 0; i < S.size(); i++)
	{
		if (S[i].getTinhTrang() == 1)
		{
			tong += 1;
		}
	}
	SetColor(18);
	cout << "\t\t\tTong so luong sach da muon la: " << tong << endl;
	SetColor(11);
	cout << left << setw(10) << "Ma Sach" << setw(25) << "Tieu De" << setw(25) << "Tac Gia" << setw(25) << "Nha Xuat Ban" << setw(15) << "Gia Ban" << setw(15) << "Nam Phat Hanh" << setw(15) << "So Trang" << setw(15)
		<< "Ngay Nhap Kho" << setw(20) << "Tinh Trang" << endl;
	for (int i = 0; i < S.size(); i++)
	{
		if (S[i].getTinhTrang() == 1)
		{
			SetColor(14);
			cout << S[i];
		}
	}
}
//**********************************************************************************HAM TINH TONG SACH CHUA DUOC MUON***************************************************************************************
void tongSachChuaMuon()
{
	int tong = 0;
	for (int i = 0; i < S.size(); i++)
	{
		if (S[i].getTinhTrang() == 0)
		{
			tong += 1;
		}
	}
	SetColor(18);
	cout << "\t\t\tTong so luong sach chua muon la: " << tong << endl<<endl;
	SetColor(11);
	cout << left << setw(10) << "Ma Sach" << setw(25) << "Tieu De" << setw(25) << "Tac Gia" << setw(25) << "Nha Xuat Ban" << setw(15) << "Gia Ban" << setw(15) << "Nam Phat Hanh" << setw(15) << "So Trang" << setw(15)
		<< "Ngay Nhap Kho" << setw(20) << "Tinh Trang" << endl;
	for (int i = 0; i < S.size(); i++)
	{
		if (S[i].getTinhTrang() == 0)
		{
			SetColor(14);
			cout << S[i];
		}
	}
}
//*************************************************************************MENU THONG KE SACH*************************************************************************************************
void thongKe() {
	int quanly = 0;
	do {
		system("cls");
		SetColor(9);
		cout << "\t\t\t__________________THONG KE_______________\n";
		cout << "\t\t\t*********************************************\n";
		SetColor(11);
		cout << "\t\t\t 1. TONG SACH DA MUON \t\n";
		cout << "\t\t\t 2. TONG SACH CHUA MUON \t\n";
		cout << "\t\t\t 3. THOAT \t\n";
		SetColor(11);
		cout << "\t\t\t*********************************************\n";
		SetColor(14);
		cout << "\t\t\tBan hay chon chuc nang can quan ly: ";
		cin >> quanly;
		switch (quanly)
		{
		case 1:
			system("cls");
			SetColor(18);
			tongSachMuon();
			system("pause");
			system("cls");
			break;
		case 2:
			system("cls");
			SetColor(18);
			tongSachChuaMuon();
			system("pause");
			system("cls");
			break;
		default:
			SetColor(20);
			cout << "\t\t\tBAN CHON THOAT THONG KE!\n";
			Sleep(1000);
			system("cls");
			quanLyThuVien();
			break;
		}
	} while (quanly >= 1 && quanly <= 3);
}
//*****************************************************************************************HAM MENU CHINH***********************************************************************************
void menuChinh()
{
	int chon = 0;
	do {
		system("cls");
		menu();
		SetColor(14);
		cout << "\t\t\tBan hay chon chuc nang: ";
		cin >> chon;
		switch (chon)
		{
		case 1:
			system("cls");
			xuatDSSach(S);
			system("pause");
			break;
		case 2:
			system("cls");
			xuatDSGV(Gv);
			cout << endl;
			xuatDSSV(Sv);
			cout << endl;
			system("pause");
			break;
		case 3:
			system("cls");
			timKiemThongtin();
			break;
		case 4:
			system("cls");
			login();
			break;
		default:
			SetColor(20);
			cout << "\t\t\tBAN DA CHON THOAT CHUONG TRINH!\n";
			Sleep(1000);
			exit(0);
		}
	} while (chon >= 1 && chon <= 4);
}
//**************************************************************************************GIAO DIEN MENU CHINH********************************************************************************
void menu()
{
	SetColor(9);
	cout << "\t\t\t______________________MENU___________________\n";
	cout << "\t\t\t*********************************************\n";
	SetColor(11);
	cout << "\t\t\t 1. HIEN THI THONG TIN SACH \t\n";
	cout << "\t\t\t 2. HIEN THI THONG TIN BAN DOC \t\n";
	cout << "\t\t\t 3. TIM KIEM THONG TIN \t\n";
	cout << "\t\t\t 4. QUAN LY \t\n";
	cout << "\t\t\t 5. THOAT! \t\n";
	SetColor(9);
	cout << "\t\t\t*********************************************\n";
}
//********************************************************************MENU TIM KIEM THONG TIN SACH VA BAN DOC**************************************************************************************
void timKiemThongtin()
{
	int timKiem = 0;
	do {
		SetColor(9);
		cout << "\t\t\t___________________TIM KIEM__________________\n";
		cout << "\t\t\t ********************************************\n";
		SetColor(11);
		cout << "\t\t\t 1. TIM KIEM SACH \t\n";
		cout << "\t\t\t 2. TIM KIEM BAN DOC \t\n";
		cout << "\t\t\t 3. THOAT! \t\n";
		SetColor(9);
		cout << "\t\t\t*********************************************\n";
		SetColor(14);
		cout << "\t\t\tChon chuc nang can tim: ";
		cin >> timKiem;
		switch (timKiem)
		{
		case 1:
			timSach();
		case 2:
			system("cls");
			timBanDoc();
		default:
			SetColor(20);
			cout << "\t\t\tBAN CHON THOAT TIM KIEM!\n";
			Sleep(1000);
			system("cls");
			menu();
			menuChinh();
			break;
		}
	} while (timKiem >= 1 && timKiem >= 3);
}
//************************************************************************************MENU HAM TIM BAN DOC*****************************************************************************************************
void timBanDoc()
{
	int timKiem = 0;
	SetColor(9);
	cout << "\t\t\t_______________TIM KIEM BAN DOC______________\n";
	cout << "\t\t\t ********************************************\n";
	SetColor(11);
	cout << "\t\t\t 1. BAN DOC GIAO VIEN \t\n";
	cout << "\t\t\t 2. BAN DOC SINH VIEN \t\n";
	cout << "\t\t\t 3. THOAT \t\n";
	SetColor(9);
	cout << "\t\t\t*********************************************\n";
	SetColor(14);
	cout << "\t\t\tChon ban doc can tim: ";
	cin >> timKiem;
	switch (timKiem)
	{
	case 1:
		timBanDocGV();
	case 2:
		timBanDocSV();
	case 3:
		SetColor(20);
		cout << "\t\t\tBAN CHON THOAT TIM KIEM BAN DOC\n";
		Sleep(1000);
		system("cls");
		timKiemThongtin();
		break;
	default:
		system("cls");
		timBanDoc();
	}
}
//*********************************************************************************HAM TIM KIEM BAN DOC SINH VIEN*******************************************************************************************
void timBanDocSV()
{
	string maBanDoc = "";
	SetColor(14);
	cout << "\t\t\tNHAP MA BAN DOC SINH VIEN: ";
	rewind(stdin);
	getline(cin, maBanDoc);
	SetColor(11);
	cout << left << setw(20) << "Ma Ban Doc" << setw(25) << "Ho Ten" << setw(25) << "Khoa" << setw(25) << "Khoa Hoc" << setw(25) << "Ngay Tham Gia" << endl;
	for (int i = 0; i < Sv.size(); i++)
	{
		if (Sv[i].getMaBanDoc() == maBanDoc)
		{
			SetColor(14);
			cout << Sv[i];
			cout << endl;
			break;
		}
	}
	if (kTraBanDocSV(maBanDoc) == -1)
	{
		SetColor(20);
		cout << "\t\t\tMA BAN DOC NHAP SAI HOAC BAN DOC KHONG TON TAI TRONG HE THONG !!!\nNHAN ENTER DE QUAY LAI MAN HINH TIM KIEM THONG TIN\n";
	}
	system("pause");
	system("cls");
	timBanDoc();
}
//********************************************************************KIEM TRA BAN DOC TRUOC KHI TIM KIEM***************************************************************************************************
int kTraBanDocSV(string maBanDoc)
{
	for (int i = 0; i < Sv.size(); i++)
	{
		if (Sv[i].getMaBanDoc() == maBanDoc)
		{
			return i;
		}
	}
	return -1;
}
//****************************************************************HAM TIM KIEM BAN DOC GIAO VIEN************************************************************************************
void timBanDocGV()
{
	string maBanDoc = "";
	SetColor(14);
	cout << "\t\t\tNHAP MA BAN DOC GIAO VIEN: ";
	rewind(stdin);
	getline(cin, maBanDoc);
	SetColor(11);
	cout << left << setw(20) << "Ma Ban Doc" << setw(25) << "Ho Ten" << setw(25) << "Khoa" << setw(25) << "Dia Chi" << setw(25)
		<< "So DT" << setw(25) << " Ngay Tham Gia" << endl;
	for (int i = 0; i < Gv.size(); i++)
	{
		if (Gv[i].getMaBanDoc() == maBanDoc)
		{
			SetColor(14);
			cout << Gv[i];
			cout << endl;
			break;
		}
	}
	if (kTraBanDocGV(Gv, maBanDoc) == -1)
	{
		SetColor(20);
		cout << "\t\t\tMA BAN DOC NHAP SAI HOAC BAN DOC KHONG TON TAI TRONG HE THONG !!!\nNHAN ENTER DE QUAY LAI MAN HINH TIM KIEM THONG TIN\n";
	}
	system("pause");
	system("cls");
	timBanDoc();
}
//***************************************************KIEM TRA BAN DOC GIAO VIEN TRUOC KHI TIM KIEM****************************************************************************************************
int kTraBanDocGV(vector<GiaoVien> Gv, string maBanDoc)
{
	for (int i = 0; i < Gv.size(); i++)
	{
		if (Gv[i].getMaBanDoc() == maBanDoc)
		{
			return i;
		}
	}
	return -1;
}
//********************************************************************TIM KIEM SACH********************************************************************************************
void timSach()
{
	string tuaDe = "";
	SetColor(14);
	cout << "\t\t\tNHAP TUA DE SACH: ";
	rewind(stdin);
	getline(cin, tuaDe);
	SetColor(11);
	cout << left << setw(10) << "Ma Sach" << setw(25) << "Tieu De" << setw(25) << "Tac Gia" << setw(25) << "Nha Xuat Ban" << setw(15) << "Gia Ban" << setw(15) << "Nam Phat Hanh" << setw(15) << "So Trang" << setw(15)
		<< "Ngay Nhap Kho" << setw(20) << "Tinh Trang" << endl;
	for (int i = 0; i < S.size(); i++)
	{
		if (S[i].getTieuDe() == tuaDe)
		{
			SetColor(14);
			cout << S[i];
			cout << endl;
			break;
		}
	}
	if (kTraSach(tuaDe) == -1)
	{
		SetColor(20);
		cout << "\t\t\tTUA DE SACH NHAP SAI HOAC SACH KHONG TON TAI TRONG HE THONG !!!\nNHAN ENTER DE QUAY LAI MAN HINH TIM KIEM THONG TIN\n";
	}
	system("pause");
	system("cls");
	timKiemThongtin();
}
//*************************************************************************HAM KIEM TRA SACH TRUOC KHI TIM KIEM**********************************************************************************
int kTraSach(string tuaDe)
{
	for (int i = 0; i < S.size(); i++)
	{
		if (S[i].getTieuDe() == tuaDe)
		{
			return i;
		}
	}
	return -1;
}
//***************************************************************************HAM XUAT DANH SACH BAN DOC SINH VIEN*******************************************************************************
void xuatDSSV(vector <SinhVien> Sv)
{
	SinhVien sv;
	SetColor(9);
	cout << "\t\t\t----------DANH SACH BAN DOC LA SINH VIEN----------\n";
	SetColor(11);
	cout << left << setw(20) << "Ma Ban Doc" << setw(25) <<"Ho Ten" << setw(25) << "Khoa" << setw(25) << "Khoa Hoc" <<setw(25)<< "Ngay Tham Gia" << endl;
	for (int i = 0; i < Sv.size(); i++)
	{
		SetColor(14);
		cout << Sv[i];
	}
}
//********************************************************************DOC FILE PHIEU MUON**********************************************************************************/////////////
void docDSPhieuMuon(vector <PhieuMuon> &Pm)
{
	ifstream fcin;
	int stt ;
	fcin.open("PhieuMuon.txt");
	fcin >>stt;
	fcin.ignore(1);
	PhieuMuon pm;
	for (int i = 0; i < stt; i++)
	{
		pm.readPhieuMuon(fcin);
		Pm.push_back(pm);
	}
}
//***ghi de file phieu muon***************
void themphieufile() 
{
	PhieuMuon pm;
	pm.nhapPhieuMuonMoi();
	Pm.insert(Pm.end() ,pm);
	ghiDSPhieu(Pm);
}
//**********************************************************************XUAT PHIEU MUON******************************************************************************************************************* 
void xuatDSPhieuMuon(vector<PhieuMuon> Pm)
{
	PhieuMuon pm;
	SetColor(9);
	cout<<"\t\t\t----------DANH SACH PHIEU MUON----------\n";
	SetColor(11);
	cout << left << setw(20) << "STT" << setw(15) << "Ma Sach" << setw(15) <<"Ma Ban Doc"
		<< setw(22) << "Ngay Muon"<< setw(20)<<"Ngay Tra" << setw(25) << "Tinh Trang" << endl;
	for (int i = 0; i < Pm.size(); i++) 
	{
		SetColor(14);
		cout << Pm[i];
	}
}
//*********************************************GHI DANH SACH PHIEU MUON*****************************************
void ghiDSPhieu(vector<PhieuMuon> Pm)
{
	ofstream fcout;
	fcout.open("PhieuMuon.txt");
	fcout << Pm.size() << endl;
	for (int i = 0; i < Pm.size(); i++)
	{
		Pm[i].writePhieuMuon(fcout);
	}
	fcout.close();
}

//****************************************************************DOC FILE  svien.txt***************************************************************************************************
void docDSSV(vector <SinhVien> &Sv)
{
	ifstream fcin;
	int n = 0;
	fcin.open("SVien.txt");
	fcin >> n;
	fcin.ignore(1);
	SinhVien sv;
	for (int i = 0; i < n; i++)
	{
		sv.readBanDoc(fcin);
		Sv.push_back(sv);
	}
}
//************************************************************HAM GHI DSSV svien.txt****************************************************************************
void ghiDSSV(vector<SinhVien> Sv)
{
	ofstream fcout;
	fcout.open("SVien.txt");
	fcout << Sv.size() << endl;
	for (int i = 0; i < Sv.size(); i++)
	{
		Sv[i].writeBanDoc(fcout);
	}
	fcout.close();
}
//***************************************************************HAM GHI LAI FILE svien.txt********************************************************************
void themDSSVfile()
{
	SinhVien sv;
	sv.nhapSinhVienMoi();
	Sv.insert(Sv.end(), sv);
	ghiDSSV(Sv);
}
//********************************************************************XUAT DANH SACH BAN DOC GIAO VIEN*******************************************************************
void xuatDSGV(vector <GiaoVien> Gv)
{
	SinhVien sv;
	SetColor(9);
	cout << "\t\t\t----------DANH SACH BAN DOC LA GIAO VIEN----------\n";
	SetColor(11);
	cout << left << setw(20) << "Ma Ban Doc" << setw(25) << "Ho Ten" << setw(25) << "Khoa" << setw(25) <<"Dia Chi" << setw(25)
		<< "So DT" << setw(25)<<" Ngay Tham Gia" << endl;
	for (int i = 0; i < Gv.size(); i++)
	{
		SetColor(14);
		cout << Gv[i];
	}
}
//*************************************************************************DOC FILE  giaovien.txt*********************************************************************************************
void docDSGV(vector <GiaoVien> &Gv)
{
	ifstream fcin;
	int n = 0;
	fcin.open("GiaoVien.txt");
	fcin >> n;
	fcin.ignore(1);
	GiaoVien gv;
	for (int i = 0; i < n; i++)
	{
		gv.readBanDoc(fcin);
		Gv.push_back(gv);
	}
}//////////////////////////////////////////////////56045=656054=-605-6045
void themDSGVfile()
{
	GiaoVien gv;
	gv.nhapGiaoVienMoi();
	Gv.insert(Gv.end(), gv);
	ghiDSGV(Gv);
}
void ghiDSGV(vector<GiaoVien> GV)
{
	ofstream fcout;
	fcout.open("GiaoVien.txt");
	fcout << Gv.size() << endl;
	for (int i = 0; i < Gv.size(); i++)
	{
		Gv[i].writeBanDoc(fcout);
	}
	fcout.close();
}
//***************************************************************************************GHI DANH SACH SACH***********************************************************************************
void ghiDSSach(vector<Sach> S)
{
	ofstream fcout;
	fcout.open("Sach.txt");
	fcout << S.size() << endl;
	for (int i = 0; i < S.size(); i++)
	{
		S[i].writeSach(fcout);
	}
	fcout.close();
}
//***************************************************************HAM GHI LAI FILE  sach.txt****************************************
void themSachfile()
{
	Sach s;
	s.nhapSachMoi();
	S.insert(S.end(), s);
	ghiDSSach(S);
}
//**********************************************************************************XUAT SACH**************************************************************************************************************
void xuatDSSach(vector<Sach> S)
{
	SetColor(9);
	cout << "\t\t\t----------DANH SACH CAC LOAI SACH CO TRONG THU VIEN----------\n";
	SetColor(11);
	cout << left << setw(10) << "Ma Sach" << setw(25) << "Tieu De" << setw(25) << "Tac Gia" << setw(25) << "Nha Xuat Ban" << setw(15) << "Gia Ban" << setw(15) << "Nam Phat Hanh" << setw(15) << "So Trang"<<setw(15)
		<< "Ngay Nhap Kho" << setw(20) << "Tinh Trang" << endl;
	for (int i = 0; i < S.size(); i++)
	{
		SetColor(14);
		cout << S[i];
	}
	

}
//******************************************************************************HAM DOC THONG TIN SACH********************************************************************************************
void docDSSach(vector<Sach> &S)
{
	ifstream fcin;
	int n = 0;
	fcin.open("Sach.txt");
	//Khai bao cac bien:
	Sach s;
	fcin >> n;
	fcin.ignore(1);
	for (int i = 0; i < n; i++)
	{
		s.readSach(fcin);
		S.push_back(s);
	}
	fcin.close();
}
//**********************************************************************************HAM DANG NHAP**********************************************************************************************
void login()
{
	int dem = 0;
	while (dem < 3)
	{
		string taiKhoan = "", matKhau = "";
		SetColor(9);
		cout << "\t\t\t*********************************\n";
		SetColor(9);
		cout << "\t\t\t*";
		SetColor(11);
		cout << "\tDANG NHAP QUAN LY\t";
		SetColor(9);
		cout << "*\n";
		SetColor(9);
		cout << "\t\t\t\*********************************\n";
		SetColor(14);
		cout << "\t\t\tNhap tai khoan: ";
		rewind(stdin);
		getline(cin, taiKhoan);
		//Ma hoa mat khau:
		cout << "\t\t\tNhap mat khau: ";
		matKhau = maHoaMK(6);
		if (kiemTraDN(taiKhoan, matKhau) == true)
		{    
			SetColor(11);
			cout << "\n\t\t\tDANG NHAP THANH CONG!\n";
			Sleep(1000);
			quanLyThuVien();
		}
		else
		{
			SetColor(20);
			cout << "\n\t\t\tBAN DA NHAP SAI! VUI LONG NHAP LAI!!\n";
			dem++;
			if (dem == 3)
			{
				SetColor(20);
				cout << "\n\t\t\tBAN DA NHAP SAI QUA 3 LAN! XIN VUI LONG THU LAI SAU!\n" << endl;
				Sleep(1000);
				system("cls");
				menu();
				menuChinh();
			}
			system("pause");
			system("cls");
		}
	}
}
//*********************************************************************************HAM MA HOA MAT KHAU**************************************************************************************
string maHoaMK(unsigned int maxLength)
{
	string pw = "";
	for (char c; (c = _getch()); )
	{
		if (c == '\n' || c == '\r')
		{
			cout << "\n";
			break;
		}
		else if (c == '\b')
		{
			cout << "\b \b";
			if (!pw.empty())
				pw.erase(pw.size() - 1);
		}
		else if (c == -32)
		{
			_getch();
		}
		else if (isprint(c) && pw.size() < maxLength)
		{
			cout << '*';
			pw += c;
		}
	}
	return pw;
}
//*********************************************************************HAM KIEM TRA THONG TIN TRUOC KHI DANG NHAP**************************************************************************************
bool kiemTraDN(string taikhoan, string matkhau)
{
	for (int i = 0; i < Ad.size(); i++)
	{
		if (Ad[i].getTaiKhoan() == taikhoan && Ad[i].getMatKhau() == matkhau)
		{
			return true;
		}
	}
	return false;
}
//*************************************************************DOC FILE admin.txt****************************************************************************************************************
void docTKvaMK()
{
	ifstream fcin;
	int n = 0;
	fcin.open("Admin.txt");
	//Khai bao cac bien:
	Admin Admin;
	fcin >> n;
	fcin.ignore(1);
	for (int i = 0; i < n; i++)
	{
		Admin.docAd(fcin);
		Ad.push_back(Admin);
	}
	fcin.close();
}
//*********************************************************************************HAM TAO MAU****************************************************************************************************
void SetColor(int ForgC)
{
	WORD wColor;

	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;

	//We use csbi for the wAttributes word.
	if (GetConsoleScreenBufferInfo(hStdOut, &csbi))
	{
		//Mask out all but the background attribute, and add in the forgournd color
		wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
		SetConsoleTextAttribute(hStdOut, wColor);
	}
	return;
}

