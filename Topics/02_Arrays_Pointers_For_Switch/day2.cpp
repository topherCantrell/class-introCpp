#include <iostream>

using namespace std;

int mydata[20];
float a;
long long b;

void doWork(int x, int y) {
	int w;
	int q;

	cout << "x:" << (int)&x << ", y:" << (int)&y 
		 << ", w:" << (int)&w << ", q:"
		 << (int)&q << endl;
}

void other() {
	short r;
	float s[20];

	cout << "r: "<< (int)&r << ", s[0]:" 
		 << (int)&s[0] << ", s[1]:" << (int)&s[19]
	     << endl;
}

int main() {	
	char p;

	cout << "int is "<< sizeof(int) << endl;
	cout << "short is "<< sizeof(short) << endl;
	cout << "float is "<< sizeof(float) << endl;
	cout << "long long is "<< sizeof(long long) << endl;
	cout << "char is " << sizeof(char) << endl;

	cout << "mydata[0]:" << (int)&mydata[0] 
	     << ", mydata[19]:" << (int)&mydata[19]
	     << ", a:" << (int)&a << ", b:" << (int)&b 
		 << ", p:" << (int)&p << endl;

	doWork(1,2);
	other();
}