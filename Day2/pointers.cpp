#include <iostream>

using namespace std;

void printArray1(int* p, int size) {
	for(int x=0;x<size;++x) {
		cout << *p << ",";
		++p;
	}
	cout << endl;
}

void printArray2(int p[], int size) {
	for(int x=0;x<size;++x) {
		cout << p[x] << ",";
	}
	cout << endl;
}

void printArray3(int* p, int size) {

	for(int x=0;x<size;++x) {
		cout << p[x] << ",";
	}
	cout << endl;

}

void printArray4(int p[], int size) {
	for(int x=0;x<size;++x) {
		cout << *p << ",";
		++p;
	}
	cout << endl;
}

void swapTwo(int * x) {

}

void swap(int* x, int* y) {

	int i = x[0];
	x[0] = y[0];
	y[0] = i;

	/*
	int i = *x;
	int j = *y;
	*x = j;
	*y = i;
	*/
	
	/*
	int i = *x;
	*x = *y;
	*y = i;
	*/
}


int main() {

	int d_one[4];
	int d_two[4] = {1,2,3,4};
	int* d_three = new int[4];

	cout << d_one << " " << d_two << " " << d_three << endl;
		
	int a=1;
	int b=2;

	cout << a << " " << b << endl;
	swap(&a, &b);
	cout << a << " " << b << endl;
	
	int myData[20] = {3,2,5,7,8,6,5,2,4,5,1,1,1,7,6,5,3,6,4,2};

	printArray1(&myData[0],20);
	printArray2(&myData[0],20);
	printArray3(&myData[0],20);
	printArray4(&myData[0],20);

	printArray1(&myData[2],10);

	printArray1(myData,20);

}