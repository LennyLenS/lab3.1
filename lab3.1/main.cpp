#include <iostream>
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
	static const regex r("^(help|((sort|test){1}-(as|ls)-(qs|bs|ch|is)[ ]+(-range(\\d+)(\\d+))?[ ]+(-step(\\d+))?)|quit)$");
	smatch mat;
	
	if (regex_search(s, mat, r)) {
		cout << mat[2];
		if (s.find("help") != -1) {
			buf.help = true;
		}
		if (s.find("sort") != -1) {
			buf.sort = true;
		}
		if (s.find("test") != -1) {
			buf.test = true;
			if (mat.size() == 3) {
				buf.start = stoi(mat[1].str());
				buf.end = stoi(mat[2].str());
				buf.step = stoi(mat[3].str());
			}
			else if (mat.size() == 1) {
				buf.step = stoi(mat[1].str());
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

void sort(parametrs buf) {
	if (buf.sort) {
		if (buf.arr_seq) {
			auto seq = new ArraySequence<int>();
			for (int i = 0; i < buf.vec.size(); ++i) {
				seq->Append(buf.vec[i]);
			}

			if (buf.choosensort) {
				auto ChSort = new ChoosenSort<int>();
				auto seq2 = ChSort->SortSequence(seq, cmp);
				for (int i = 0; i < seq2->GetLength(); ++i) {
					cout << seq2->Get(i) << " ";
				}
				cout << '\n';
			}

			if (buf.qsort) {
				auto QuickSort = new Qsort<int>();
				auto seq2 = QuickSort->SortSequence(seq, cmp);
				for (int i = 0; i < seq2->GetLength(); ++i) {
					cout << seq2->Get(i) << " ";
				}
				cout << '\n';
			}

			if (buf.insersort) {
				auto InsSort = new InsertionSort<int>();
				auto seq2 = InsSort->SortSequence(seq, cmp);
				for (int i = 0; i < seq2->GetLength(); ++i) {
					cout << seq2->Get(i) << " ";
				}
				cout << '\n';
			}

			if (buf.bubblesort) {
				auto BubSort = new BubbleSort<int>();
				auto seq2 = BubSort->SortSequence(seq, cmp);
				for (int i = 0; i < seq2->GetLength(); ++i) {
					cout << seq2->Get(i) << " ";
				}
				cout << '\n';
			}

		}else{
			auto seq = new ListSequence<int>();
			for (int i = 0; i < buf.vec.size(); ++i) {
				seq->Append(buf.vec[i]);
			}

			if (buf.choosensort) {
				auto ChSort = new ChoosenSort<int>();
				auto seq2 = ChSort->SortSequence(seq, cmp);
				for (int i = 0; i < seq2->GetLength(); ++i) {
					cout << seq2->Get(i) << " ";
				}
				cout << '\n';
			}

			if (buf.qsort) {
				auto QuickSort = new Qsort<int>();
				auto seq2 = QuickSort->SortSequence(seq, cmp);
				for (int i = 0; i < seq2->GetLength(); ++i) {
					cout << seq2->Get(i) << " ";
				}
				cout << '\n';
			}

			if (buf.insersort) {
				auto InsSort = new InsertionSort<int>();
				auto seq2 = InsSort->SortSequence(seq, cmp);
				for (int i = 0; i < seq2->GetLength(); ++i) {
					cout << seq2->Get(i) << " ";
				}
				cout << '\n';
			}

			if (buf.bubblesort) {
				auto BubSort = new BubbleSort<int>();
				auto seq2 = BubSort->SortSequence(seq, cmp);
				for (int i = 0; i < seq2->GetLength(); ++i) {
					cout << seq2->Get(i) << " ";
				}
				cout << '\n';
			}
		}
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

	}
}


int main() {
	queue<parametrs> requests;
	std::mutex requests_mutex;
	thread input([&]()
		{
			bool quit = false;
			do{
				parametrs buf;
				string s; 
				getline(cin, s);
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
					cout << buf.step;
					sort(buf);
				}
				quit = buf.quit;
			} while (!quit);
		});
	input.join();
	sorting.join();
}