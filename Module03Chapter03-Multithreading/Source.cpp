/*
Author: Abigail Miller
*/

#include <iostream>
#include <thread>

static int HeapInt = 0;

bool DidQuit = false;

int ThreadA = 0;
int ThreadB = 0;

void ThreadCounter(int* thread) {
	while (!DidQuit) {
		(*thread)++;
		if ((*thread) >= 1000) {
			(*thread) = 0;
		}
	}
}

int main() {
	HeapInt = 5;
	std::cout << "Hello World\n";
	char UserInput;
	std::thread threadA(ThreadCounter, &ThreadA);
	std::thread threadB(ThreadCounter, &ThreadB);

	

	while (!DidQuit) {
		std::cout << "Press any key to display counter" << "\n";
		std::cout << "q to quit" << "\n";
		std::cin >> UserInput;
		DidQuit = (UserInput == 'q');
		std::cout << "Thread A: " << ThreadA << "\n";
		std::cout << "Thread B: " << ThreadB << "\n";

	}
	

	threadA.join();
	threadB.join();
	return 0;
}