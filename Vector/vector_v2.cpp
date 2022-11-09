//cai dat vector bang mang dong
#include<bits/stdc++.h>
using namespace std;
#ifndef __myvector__cpp__
#define __myvector__cpp__
template<class T>
class vt_re_it  //bo lap nguoc
{
	T*curr; 
	public:
		vt_re_it(T *c=NULL) {curr=c;} //
		T*&getcur() {return curr;}
		vt_re_it &operator=(vt_re_it itt)
		{
			this->curr=itt.getcur();
			return *this;
		}
		bool operator!=(vt_re_it itt) {return curr!=itt.getcur();}
		T &operator*() {return *curr;}
		vt_re_it operator++(int)  //it++
		{
			curr--;
			return curr;
		}
		vt_re_it operator++() //++it
		{
			T*c=curr;
			curr--;
			return c;
		}
		
};
template<class T>
class Vector
{
	int n,cap;  //n=size; cap=capacity
	T *buf;
	private: void recap(int k)
		{
			if(k<=cap) return;
			cap=k;
			T *tem=new T[k]; for(int i=0;i<n;i++) tem[i]=buf[i];
			if(buf) delete []buf;
			buf=tem;
		}
	public:
		Vector() {n=cap=0; buf=NULL;}
		Vector(int k,T x)
		{
			n=cap=k;
			buf=new T[n]; 
			for(int i=0;i<n;i++) buf[i]=x;
		}
		Vector<T> (Vector<T> &V) 	//"toan tu copy";
		{
			this->n=V.n;
			this->cap=V.cap;
			if(this->n==0) this->buf=NULL;
			else
			{
				this->buf=new T[this->cap];
				for(int i=0;i<this->n;i++) this->buf[i]=V.buf[i];
			}
		}
		Vector<T> &operator=(Vector<T> &V) 	//"toan tu assignment A=B";
		{
			//cout<<"phep gan";
			this->n=V.n;
			this->cap=V.cap;
			if(this->n==0) this->buf=NULL;
			else
			{
				this->buf=new T[this->cap];
				for(int i=0;i<this->n;i++) this->buf[i]=V.buf[i];
			}
			return *this;
		}
		~Vector() {if(buf) delete[]buf;}
		int size(){return n;}
		bool empty() {return n==0;}
		int capacity() {return cap;}
		T &front() {return buf[0];}
		T &back() {return buf[n-1];}
		void push_back(T x)
		{
			if(n==cap) recap(cap?cap*2:1);
			buf[n++]=x;
		}
		void pop_back() {n--;}
		T &operator[](int k) {return buf[k];}
		void resize(int k,T x)
		{
			if(cap<k) recap(k);
			for(int i=n;i<k;i++) buf[i]=x;
			n=k;
		}
		typedef T*iterator;
		iterator begin() {return buf;}
		iterator end() {return buf+n;}
		void insert(iterator &it,T x)
		{
			if(n==cap)
			{
				int k=it-buf;
				recap(cap?cap*2:1);
				it=buf+k;
			}
			for(iterator it1=buf+n-1;it1>=it;it1--) *(it1+1)=*it1;
			*it=x;
			n++;
		}
		void erase(iterator it)
		{
			for(iterator it1=it+1;it1<buf+n;it1++) *(it1-1)=*it1;
			n--;
		}
		typedef vt_re_it<int> reverse_iterator;
		reverse_iterator rbegin() {return buf+n-1;}
		reverse_iterator rend() {return buf-1;}
		
};
#endif
//int main()
//{
//	Vector<int> A(5,3);
//	A.resize(7,10);
//	for(int i=0;i<A.size();i++) cout<<A[i]<<" ";
//	cout<<"\nA : "; for(Vector<int>::iterator it=A.begin();it!=A.end();it++) cout<<*it<<" ";
//	cout<<"\nA : "; for(auto x:A) cout<<x<<" ";
//	reverse(A.begin(),A.end());
//	cout<<"\nA : "; for(auto x:A) cout<<x<<" ";
//	cout<<"\nDuyet nguoc : ";
//	for(Vector<int>::reverse_iterator it=A.rbegin();it!=A.rend();++it)
//	cout<<*it<<" ";
//	sort(A.begin(),A.end());
//	cout<<"\nA: sau sx "; for(int x:A) cout<<x<<" ";
//
//}

