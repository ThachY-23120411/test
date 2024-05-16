#include<iostream>
using namespace std;
struct Node {
	int data;
	Node* pNext;
};
struct stack {
	Node* pTop;
};
//.Khoi tao Node:
Node* KhoiTaoNode(int data) {
	Node* p = new Node;
	if (p == NULL) {
		cout << "Khong du bo nho de cap phat! " << endl;
		return NULL;
	}
	p->data = data;
	p->pNext = NULL;
	return p;
}
//.Khoi tao stack:
void KhoiTaoStack(stack& s) {
	s.pTop = NULL;
}
//.Kiem tra stack co rong hay khong
bool IsEmpty(stack s) {
	if (s.pTop == NULL) {
		return true;
	}
	return false;

}
//.Them 1 phan tu vao stack (Tu hieu la them vao dau theo LIFO)
bool Push(stack& s,Node*p) {
	if (p == NULL) {
		return false;
	}
	if (IsEmpty(s)==true) {
		s.pTop = p;
	}
	else {
		p->pNext = s.pTop;
		s.pTop = p;
	}
	return true;
}
//.Lay 1 phan tu ra khoi stack va huy no di (tu hieu la lay phan tu dau va huy no di)
bool Pop(stack& s, int& x) {
	//.x de luu gia tri '.data' cua node ta lay ra.
	if (IsEmpty(s) == true) {
		return false;
	}
	else {
		Node* p = s.pTop;
		x = p->data;
		s.pTop = s.pTop->pNext;
		delete p;
	}
	return true;//.Lay phan tu dau stack thanh cong!
}
//.Xem thong tin phan tu dau stack va khong huy no di:( muon xem thong tin phan tu sau thi buoc phai xoa phan tu dau nay di ms xem dc-->pop)
bool Top(stack s, int& x) {
	if (IsEmpty(s) == true) {
		return false;
	}
	x = s.pTop->data;
	return true;
}
void XuatStack(stack& s) {//.Xuat stack--> xuat toan bo phan tu --> xuat tu phan tu dau tien den cuoi --> pop --> cx dong nghia vs viec sau khi xuat ra ht thi stack se rong!
	if (IsEmpty(s) == true) {
		cout << "STACK RONG !" << endl;
	}
	while (IsEmpty(s)==false) {
		int x;
		Pop(s, x);
		cout << x << " ";
	}
	cout << endl;
}
void XemThongTinPhanTuDauStack(stack s, int& x) {
	Top(s, x);
	cout << "Phan tu dau stack la: " << x;
}
void Menu(stack&s) {
	int chon;
	do {
		system("cls");
		cout << "========MENU========" << endl;
		cout << "1.Them phan tu vao stack - Push " << endl;
		cout << "2.Xuat danh sach stack ra man hinh - Pop" << endl;
		cout << "3.Xem thong tin phan tu dau stack - Top" << endl;
		cout << "0.Thoat chuong trinh" << endl;
		cout << "========END========" << endl;
		cout << "Lua chon cua ban la: ";
		cin >> chon;
		if (chon == 1) {
			int x;
			cout << "Nhap phan tu can them: " << endl;
			cin >> x;
			Node* p = KhoiTaoNode(x);
			Push(s, p);
		}
		else if (chon == 2) {
			XuatStack(s);
			system("pause");
		}
		else if (chon == 3) {
			int x;
			XemThongTinPhanTuDauStack(s, x);//.hihi hả
			system("pause");
		}
	} while (chon != 0);
}
int main() {
	stack s;
	KhoiTaoStack(s);
	Menu(s);

}