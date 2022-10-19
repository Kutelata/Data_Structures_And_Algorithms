#include <iostream>

using namespace std;

class NhanVien
{
private:
    int ma;
    string hoTen;
    int namSinh;
    float luong;

public:
    NhanVien()
    {
    }

    NhanVien(int ma, string hoTen, int namSinh, float luong)
    {
        this->ma = ma;
        this->hoTen = hoTen;
        this->namSinh = namSinh;
        this->luong = luong;
    }

    ~NhanVien()
    {
    }

    friend istream &operator>>(istream &is, NhanVien &nv)
    {
        cout << "Nhap ma: " << endl;
        is >> nv.ma;
        cout << "Nhap ho ten: " << endl;
        cin.ignore();
        getline(is, nv.hoTen);
        cout << "Nhap nam sinh: " << endl;
        is >> nv.namSinh;
        cout << "Nhap luong " << endl;
        is >> nv.luong;
        return is;
    }

    friend ostream &operator<<(ostream &os, NhanVien &nv)
    {
        os << "Ma nhan vien: " << nv.ma << endl;
        os << "Ho ten: " << nv.hoTen << endl;
        os << "Nam sinh: " << nv.namSinh << endl;
        os << "Luong: " << nv.luong << endl;
        return os;
    }

    int getMa()
    {
        return ma;
    }

    int setMa(int ma)
    {
        this->ma = ma;
    }
};