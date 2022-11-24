#include <iostream>
#include <fstream>
#include <random>
#include <ctime>
#include <chrono>
#include <thread>
#include <mutex>
#include <queue>
#include <regex>
#include "array_sequence.hpp"
#include "list_sequence.hpp"
#include "BubbleSort.hpp"
#include "ChoosenSort.hpp"
#include "InsertionSort.hpp"
#include "Qsort.hpp"

using namespace std;
using std::cout;
using std::remove;

typedef struct parametrs {
	bool help = false;
	bool quit = false;
	bool sort = false;
	bool test = false;
	bool arr_seq = false, list_seq = false;
	bool qsort = false, bubblesort = false, choosensort = false, insersort = false;
	bool error = false;
	int start = 1000, end = 10000;
	int step = 100;
	vector<int> vec;
}parametrs;

int cmp(int a, int b) {
	return a < b;
}

parametrs parsing(string s) {
	parametrs buf;
	static const regex r("^(help|((sort|test){1}\\s*-(as|ls)\\s*(-qs|-bs|-ch|-is|\\s)*\\s*(-range\\s*(\\d+)\\s*(\\d+))?\\s*(-step\\s*(\\d+))?)|quit)$");
	smatch mat;
	
	if (regex_search(s, mat, r)) {
		if (s.find("help") != -1) {
			buf.help = true;
		}
		if (s.find("sort") != -1) {
			buf.sort = true;
		}
		if (s.find("test") != -1) {
			buf.test = true;
			if (mat[7].str() != "") {
				buf.start = stoi(mat[7].str());
			}
			if (mat[8].str() != "") {
				buf.end = stoi(mat[8].str());
			}
			if (mat[10].str() != "") {
				buf.step = stoi(mat[10].str());
			}
		}

		if (s.find("as") != -1) {
			buf.arr_seq = true;
		}
		if (s.find("ls") != -1) {
			buf.list_seq = true;
		}

		if (s.find("qs") != -1) {
			buf.qsort = true;
		}
		if (s.find("bs") != -1) {
			buf.bubblesort = true;
		}
		if (s.find("ch") != -1) {
			buf.choosensort = true;
		}
		if (s.find("is") != -1) {
			buf.insersort = true;
		}

		if (s.find("quit") != -1) {
			buf.quit = true;
		}
	} else {
		buf.error = true;
	}
	
	return buf;
}

auto sorter(ISorter<int>* ex_sort, Sequence<int>* seq, std::chrono::duration<double, std::milli> &elapsed_seconds) {
	auto start = std::chrono::high_resolution_clock::now();
	auto seq2 = ex_sort->SortSequence(seq, cmp);
	auto end = std::chrono::high_resolution_clock::now();
	elapsed_seconds = end - start;
	return seq2;
}

void sort(parametrs buf, int flag, int n) {
	ofstream fout;
	std::chrono::duration<double, std::milli> elapsed_seconds;
	if (flag == 2) {
		fout.open("result.csv", ios::app);
	}

	Sequence<int> *seq = nullptr;
	if (buf.arr_seq) {
		seq = new ArraySequence<int>();
	}
	else if (buf.list_seq) {
		seq = new ListSequence<int>();
	}

	if (flag == 1) {
		for (int i = 0; i < buf.vec.size(); ++i) {
			seq->Append(buf.vec[i]);
		}
	} else if (flag == 2) {
		for (int i = 0; i < n; ++i) {
			seq->Append(rand());
		}
	}


	if (buf.choosensort) {
		auto ChSort = new ChoosenSort<int>();
		auto seq2 = sorter(ChSort, seq, elapsed_seconds);
		if (flag == 1) {
			cout << "Choosen Sort " << elapsed_seconds.count() << "\n";
			for (int i = 0; i < seq2->GetLength(); ++i) {
				cout << seq2->Get(i) << " ";
			}
			cout << '\n';
		}
		else {
			fout << elapsed_seconds.count() << " ";
		}
		delete seq2;
	}

	if (buf.qsort) {
		auto QuickSort = new Qsort<int>();
		auto seq2 = sorter(QuickSort, seq, elapsed_seconds);
		if (flag == 1) {
			cout << "Quick Sort " << elapsed_seconds.count() << "\n";
			for (int i = 0; i < seq2->GetLength(); ++i) {
				cout << seq2->Get(i) << " ";
			}
			cout << '\n';
		}
		else {
			fout << elapsed_seconds.count() << " ";
		}
		delete seq2;
	}

	if (buf.insersort) {
		auto InsSort = new InsertionSort<int>();
		auto seq2 = sorter(InsSort, seq, elapsed_seconds);
		if (flag == 1) {
			cout << "Insertion Sort " << elapsed_seconds.count() << "\n";
			for (int i = 0; i < seq2->GetLength(); ++i) {
				cout << seq2->Get(i) << " ";
			}
			cout << '\n';
		}
		else {
			fout << elapsed_seconds.count() << " ";
		}
		delete seq2;
	}

	if (buf.bubblesort) {
		auto BubSort = new BubbleSort<int>();

		auto seq2 = sorter(BubSort, seq, elapsed_seconds);
		if (flag == 1) {
			cout << "Bubble Sort " << elapsed_seconds.count() << "\n";
			for (int i = 0; i < seq2->GetLength(); ++i) {
				cout << seq2->Get(i) << " ";
			}
			cout << '\n';
		}
		else {
			fout << elapsed_seconds.count() << " ";
		}
		delete seq2;
	}

	delete seq;
	if (flag == 2) {
		fout << n << '\n';
		fout.close();
	}
}

void update(parametrs buf) {
	if (buf.sort) {
		sort(buf, 1, 0);
	}
	else if (buf.help) {
		cout << "	sort - command for sorting sequence. Possible flags: \n \
			-as for array sequense \n\
			-ls for list sequense \n\
			-qs for quick sort \n\
			-bs for bubble sort \n \
			-ch for choosen sort \n \
			-is for insertion sort \n \
	test for automatic test Possible flags: \n \
			-as for array sequense \n\
			-ls for list sequense \n\
			-qs for quick sort \n\
			-bs for bubble sort \n \
			-ch for choosen sort \n \
			-is for insertion sort \n \
			-range (int) (int) default 1000 and 10000 \n \
			-step (int) default 100 \n \
	quit for finish programme\n";
	} else if (buf.test) {
		ofstream fout;
		fout.open("result.csv");
		if (buf.choosensort) {
			fout << "choosen sort;";
		}
		if (buf.qsort) {
			fout << "qsort;";
		}
		if (buf.insersort) {
			fout << "insert sort;";
		}
		if (buf.bubblesort) {
			fout << "bubble sort;";
		}
		fout << "size\n";
		fout.close();
		for (int i = buf.start; i <= buf.end; i += buf.step) {
			sort(buf, 2, i);
		}
		cout << "Datasetes get!\n";
		system("plot.py");
		cout << "Graph complete!\n";
		remove("result.csv");
	}
}


int main() {
	srand(time(0));
	queue<parametrs> requests;
	std::mutex requests_mutex;
	thread input([&]()
		{
			bool quit = false;
			do{
				parametrs buf;
				string s; 
				std::getline(cin, s);
				buf = parsing(s);
				if (buf.error) {
					cout << "Error in the request: " << s << "\n";
				} else {
					if (buf.sort) {
						int n;
						cin >> n;
						vector<int> vec;
						for (int i = 0; i < n; ++i) {
							int x;
							cin >> x;
							vec.push_back(x);
						}
						buf.vec = vec;
						std::getline(cin, s);
					}
					requests_mutex.lock();
					requests.push(buf);
					requests_mutex.unlock();
				}
				quit = buf.quit;
				//getline(cin, s);
			} while (!quit);
		});
	thread sorting([&]()
		{
			bool quit = false;
			do {
				parametrs buf;
				requests_mutex.lock();
				if (!requests.empty()) {
					buf = requests.front();
					requests.pop();
				}
				requests_mutex.unlock();
				if (buf.sort || buf.test || buf.help) {
					update(buf);
				}
				quit = buf.quit;
			} while (!quit);
		});
	input.join();
	sorting.join();
}