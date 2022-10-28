#include <iostream>
using namespace std;
class HCN{
	int a,b;
	public:
		friend istream& operator >>(istream& is, HCN &d){
			cout <<"Nhap chieu dai a = ";
 			is >> d.a;
 			cout <<"Nhap chieu rong b = ";
 			is >> d.b;
 			return is;
			}
		friend ostream& operator <<(ostream& os, HCN d){
			os <<"(" <<d.a<<","<<d.b<<")";
 			return os;
		}
		int getA(){
			return a;
		}
		int getB(){
			return b;
		}
		int tinhS(){
			return a*b;
		}
};
void swap(HCN &x , HCN &y){
	HCN temp;
	temp = x;
	x = y;
	y = temp;
}
class DAYHCN{
	HCN *hcn;
	public:
		DAYHCN();
		DAYHCN(int n){
			hcn = new HCN[n];
		}
		void nhap(int n){
			for(int i = 0 ; i < n ; i++)
				cin >> hcn[i];
		}
		void xuat(int n){
			for(int i = 0 ; i < n ; i++)
				cout << hcn[i];
		}
		void SelectionSort(int n){
			int max;
			for(int i = 0 ; i < n - 1 ; i++){
				max = i;
				for(int j = i + 1 ; j < n ; j++){
					if(hcn[j].tinhS() > hcn[max].tinhS())
						max = j;
				}
				swap(hcn[i],hcn[max]);
			}
		}
};
int main(){
	int n;	
	cout << "Nhap so hinh chu nhat n = ";
	cin >> n;
	DAYHCN hcn(n);
	hcn.nhap(n);
	hcn.SelectionSort(n);
	hcn.xuat(n);
	
}
