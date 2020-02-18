#include <stdio.h>

void doMoreWork();
void doWork(int a, int b);

int main() {

	printf("main starts\n");

	doWork(1,2);
	doMoreWork();

	printf("main ends\n");
	return 0;
}

void doMoreWork() {
	printf("doMoreWork starts\n");

	printf("doMoreWork ends\n");
}

void doWork(int a, int b) {
	printf("doWork starts\n");

	doMoreWork();

	printf("doWork ends\n");
}




