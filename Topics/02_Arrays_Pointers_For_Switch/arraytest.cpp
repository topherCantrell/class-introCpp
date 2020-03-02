
#include <iostream>

int * data = new int[100];
int maxDataSize = 100;
int currentDataSize = 0;

void sort(int arr[], int size) {

	bool changed=true;

	while(changed) {
		int x=0;
		int y=1;
		changed = false;
		while(y<size) {
			if(arr[y]<arr[x]) {
				int tmp = arr[x];
				arr[x] = arr[y];
				arr[y] = tmp;
				changed = true;
			}
			y=y+1;
			x=x+1;
		}
	}

}

void removeFromData(int index) {
}

int getData(int index) {
	return 0;
}

void setData(int index, int value) {
}


using namespace std;

int main() {

	int data[] = {3,4,5,3,2,1};

	sort(data,3);

	int x=0;
	while(x<6) {
		cout << data[x] << ",";
		x=x+1;
	}
		
}