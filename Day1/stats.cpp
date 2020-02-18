#include <iostream>
#include <time.h>

using namespace std;

// These all go to separate files ... combined here for brevity
namespace min {
	void process(int value);
	void report();
}
namespace max {
	void process(int value);
	void report();
}
namespace even {
	void process(int value);
	void report();
}
namespace odd {
	void process(int value);
	void report();
}
namespace fortyTwo {
	void process(int value);
	void report();
}
namespace sum {
	void process(int value);
	void report();
}
namespace average {
	void process(int value);
	void report();
}


// These all go to separate files ... combined here for brevity
namespace min {
	int min = INT_MAX;
	void process(int value) {
		if(value<min) {
			min = value;
		}
	}
	void report() {
		cout << "Minimum value is " << min << endl;
	}
}
namespace max {
	int max = INT_MIN;
	void process(int value) {
		if(value>max) {
			max = value;
		}
	}
	void report() {
		cout << "Maximum value is " << max << endl;
	}
}
namespace even {
	int count = 0;
	void process(int value) {
		if( (value%2) == 0) {
			count = count + 1;
		}
	}
	void report() {
		cout << "Number of even values " << count << endl;
	}
}
namespace odd {
	int count = 0;
	void process(int value) {
		if( (value%2) == 1) {
			count = count + 1;
		}
	}
	void report() {
		cout << "Number of odd values " << count << endl;
	}
}
namespace fortyTwo {
	int count = 0;
	void process(int value) {
		if(value == 42) {
			count = count + 1;
		}
	}
	void report() {
		cout << "Number of 42s " << count << endl;
	}
}
namespace sum {
	int sum = 0;
	void process(int value) {
		sum = sum + value;
	}
	void report() {
		cout << "Sum of all values " << sum << endl;
	}
}
namespace average {
	int count = 0;
	int sum = 0;
	void process(int value) {
		count = count + 1;
		sum = sum + value;
	}
	void report() {
		float a = sum;
		float b = count;
		cout << "Average of all values " << a/b << endl;
	}
}



int main() {

	while(true) {
		cout << "Value (0 to end): ";
		int value = 0;
		cin >> value;

		if(value==0) {

			min::report();
			max::report();
			even::report();
			odd::report();
			fortyTwo::report();
			sum::report();
			average::report();

			return 0;

		} else {

			min::process(value);
			max::process(value);
			even::process(value);
			odd::process(value);
			fortyTwo::process(value);
			sum::process(value);
			average::process(value);

		}

	}

}