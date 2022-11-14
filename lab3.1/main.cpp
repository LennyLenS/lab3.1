#include <iostream>
#include <random>
#include <ctime>
#include <chrono>
#include <thread>
#include <mutex>
#include <queue>
#include "array_sequence.hpp"
#include "list_sequence.hpp"
#include "BubbleSort.hpp"
#include "ChoosenSort.hpp"
#include "Qsort.hpp"
using namespace std;

typedef struct parametrs {
	bool quit = false;
	bool sort = false;
	bool test = false;
	bool arr_seq = false, list_seq = false;
	bool qsort = false, bubblesort = false, choossort = false, insersort = false;
	bool file = false, input = false;
	string filename = "";
}parametrs;

parametrs parsing(string s) {

}

int cmp(int a, int b) {
	return a < b;
}


int main() {
	queue<parametrs> requests;
	std::mutex requests_mutex;
	thread input([&]()
		{
			string s;
			cin >> s;
			parametrs buf = parsing(s);
			cout << s;
			requests_mutex.lock();
			requests.push(buf);
			requests_mutex.unlock();

		});
	thread sorting([&]()
		{

		});
	input.join();
	sorting.join();
	std::chrono::time_point<std::chrono::system_clock> start, end;
	std::chrono::duration<double> elapsed_seconds;
	srand(time(0));
	Sequence<int>* seq = nullptr;
	seq = new ArraySequence<int>();
	for (int i = 0; i < 10; ++i) {
		seq->Append(rand() % 100);
	}
	
	for (int i = 0; i < seq->GetLength(); ++i) {
		cout << seq->Get(i) << " ";
	}
	cout << "\n";

	auto SeSort = new ChoosenSort<int>();
	start = std::chrono::system_clock::now();
	auto seq2 = SeSort->SortSequence(seq, cmp);
	end = std::chrono::system_clock::now();
	elapsed_seconds = end - start;
	cout << "Selection Sort: " << elapsed_seconds.count() << "s\n";
	/*
	for (int i = 0; i < seq2->GetLength(); ++i) {
		cout << seq2->Get(i) << " ";
	}
	*/
	cout << "\n";


	auto BubSort = new ChoosenSort<int>();
	start = std::chrono::system_clock::now();
	auto seq3 = BubSort->SortSequence(seq, cmp);
	end = std::chrono::system_clock::now();
	elapsed_seconds = end - start;
	cout << "Bubble Sort: " << elapsed_seconds.count() << "s\n";
	/*
	for (int i =  0; i < seq3->GetLength(); ++i) {
		cout << seq3->Get(i) << " ";
	}
	*/
	cout << "\n";


	auto QuickSort = new Qsort<int>();
	start = std::chrono::system_clock::now();
	auto seq4 = QuickSort->SortSequence(seq, cmp);
	end = std::chrono::system_clock::now();
	elapsed_seconds = end - start;
	cout << "QSort: " << elapsed_seconds.count() << "s\n";
	/*
	for (int i = 0; i < seq4->GetLength(); ++i) {
		cout << seq4->Get(i) << " ";
	}
	*/
	cout << "\n";
}