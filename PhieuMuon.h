#ifndef _PhieuMuon_
#define _PhieuMuon_
#include "SinhVien.h"
#include "Sach.h"
#include "GiaoVien.h"
class PhieuMuon
{
private:
	string maPhieu;
	Date xDate;
	BanDoc xBandoc;
	Sach xSach;
	//int tinhtrang = 1;
	string mabandoc;
	//string masach;
	int ngaymuon = 0;
	int thangmuon = 0;
	int nammuon = 0;
	int ngaytra = 0;
	int thangtra = 0;
	int namtra = 0;
public:
	friend BanDoc;
	friend Sach;
	string masach;
	int tinhtrang = 1;
	PhieuMuon() = default;
	PhieuMuon( string maPhieu,string maBanDoc, string maSach, int ngay, int thang, int nam)
		:xDate(ngay, thang, nam), xBandoc(maBanDoc), xSach(maSach)
	{
		tinhtrang = 1;
	}
	string getMaPhieu();
	void setMaPhieu(string maPhieu);
	int trangay(int thang, int nam);
	void setNgayMuon(int& ngay, int& thang, int& nam);
	void setNgayTra(int& ngay, int& thang, int& nam, int& ngayt, int& thangt, int& namt);
	//bool searchMaSach(string s);
	void nhapPhieuMuonMoi()
	{
		rewind(stdin);
		cout << "\t\t\tDang ki phieu muon :"  << endl;
		cout << "\t\t\tNhap ma phieu muon (MPMxxx): ";
		getline(cin, maPhieu);
		rewind(stdin);
		cout << "\t\t\tNhap ma sach:(MSSXXX) ";
		getline(cin, masach);
		rewind(stdin);
		cout << "\t\t\tNhap ma ban doc:(MSVXXX/MGVXXX) ";
		getline(cin, mabandoc);
		setNgayMuon(ngaymuon, thangmuon, nammuon);
		setNgayTra(ngaymuon, thangmuon, nammuon, ngaytra, thangtra, namtra);
		cout <<"\t\t\t"<< ngaytra << "," << thangtra << "," << namtra << endl;
		ofstream ifs;
		ifs.open("PhieuMuon.txt", ios::app);
		ifs << maPhieu << endl;
		ifs << masach << endl;
		ifs << mabandoc << endl;
		ifs << ngaymuon << "/" << thangmuon << "/" << nammuon << endl;
		ifs << ngaytra << "/" << thangtra << "/" << namtra << "/" << endl;
		ifs << tinhtrang << endl;
		ifs.close();
	}
	friend ostream& operator<<(ostream& out, PhieuMuon& Pm);
	void writePhieuMuon(ofstream& in);
	/*void docThongtin()
	{
		int STT = 0;

		ifstream ifs;
		ifs.open("PhieuMuon.txt");

		ifs >> STT;
		ifs.ignore(1);
		getline(ifs, masach, '#');
		getline(ifs, mabandoc, '#');
		ifs.ignore(1);
		ifs >> ngaymuon;
		ifs.close();
	}*/
	void readPhieuMuon(ifstream& in)
	{
		rewind(stdin);
		getline(in,maPhieu);
		rewind(stdin);
		getline(in, masach);
		rewind(stdin);
		getline(in, mabandoc);
		in >> ngaymuon;
		in.ignore(1);
		in >> thangmuon;
		in.ignore(1);
		in >> nammuon;
		in.ignore(1);
		in >> ngaytra;
		in.ignore(1);
		in >> thangtra;
		in.ignore(1);
		in >> namtra;
		in.ignore(1);
		in >> tinhtrang;
		in.ignore(1);
	}
	~PhieuMuon();
};

#endif
