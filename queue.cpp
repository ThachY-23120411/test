#include<iostream>
using namespace std;
struct Node {
	int data;
	Node* pNext;
};
struct queue {
	Node* pHead;
	Node* pTail;
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
//.Khoi tao queue:
void KhoiTaoQueue(queue &q) {
	q.pHead = NULL;
	q.pTail = NULL;
}
//.Kiem tra queue co rong hay khong
bool IsEmpty(queue q) {
	if (q.pHead == NULL) {
		return true;
	}
	return false;

}
//.Them 1 phan tu vao queue (Tu hieu la them vao cuoi theo FIFO)
bool Push(queue& q, Node* p) {
	if (p == NULL) {
		return false;
	}
	if (IsEmpty(q) == true) {
		q.pHead = p;
		q.pTail = p;
	}
	else {
		q.pTail->pNext = p;
		q.pTail = p;
	}
	return true;
}
//.Lay 1 phan tu ra khoi stack va huy no di (tu hieu la lay phan tu dau va huy no di)
bool Pop(queue &q, int& x) {
	//.x de luu gia tri '.data' cua node ta lay ra.
	if (IsEmpty(q) == true) {
		return false;
	}
	else {
		Node* p = q.pHead;
		x = p->data;
		q.pHead = q.pHead->pNext;
		delete p;
	}
	return true;//.Lay phan tu dau stack thanh cong!
}
//.Xem thong tin phan tu dau stack va khong huy no di:( muon xem thong tin phan tu sau thi buoc phai xoa phan tu dau nay di ms xem dc-->pop)
bool Top(queue q, int& x) {
	if (IsEmpty(q) == true) {
		return false;
	}
	x = q.pHead->data;
	return true;
}
void XuatQueue(queue &q) {//.Xuat stack--> xuat toan bo phan tu --> xuat tu phan tu dau tien den cuoi --> pop --> cx dong nghia vs viec sau khi xuat ra ht thi stack se rong!
	if (IsEmpty(q) == true) {
		cout << "QUEUE RONG !" << endl;
	}
	while (IsEmpty(q) == false) {
		int x;
		Pop(q, x);
		cout << x << " ";
	}
	cout << endl;
}
void XemThongTinPhanTuDauQueue(queue q, int& x) {
	Top(q, x);
	cout << "Phan tu dau queue la: " << x;
}
void Menu(queue& q) {
	int chon;
	do {
		system("cls");
		cout << "========MENU========" << endl;
		cout << "1.Them phan tu vao queue - Push " << endl;
		cout << "2.Xuat danh sach queue ra man hinh - Pop" << endl;
		cout << "3.Xem thong tin phan tu dau queue - Top" << endl;
		cout << "0.Thoat chuong trinh" << endl;
		cout << "========END========" << endl;
		cout << "Lua chon cua ban la: ";
		cin >> chon;
		if (chon == 1) {
			int x;
			cout << "Nhap phan tu can them: " << endl;
			cin >> x;
			Node*p=KhoiTaoNode(x);
			Push(q, p);
		}
		else if (chon == 2) {
			XuatQueue(q);
			system("pause");
		}
		else if (chon == 3) {
			int x;
			XemThongTinPhanTuDauQueue(q, x);
			system("pause");
		}
	} while (chon != 0);
}
int main() {
	queue q;
	KhoiTaoQueue(q);
	Menu(q);

}