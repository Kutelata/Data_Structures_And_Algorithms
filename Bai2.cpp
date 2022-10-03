#include<iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

class DoanThang{
	int x;
	int y;
public:
	DoanThang(){
		this->x = 0;
		this->y = 0;
	}

	void Input(){
		cout<<"nhap x: ";cin>>x;
		cout<<"nhap y: ";cin>>y;
	}

	void Output(){
		cout<<"x = "<<x<<endl;
		cout<<"y = "<<y<<endl;
	}

	~DoanThang(){
		delete x;
		delete y;
	}
	
};

int main(){
	DoanThang a;
	a.Input();
	a.Output();
	
}

