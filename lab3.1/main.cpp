#include <iostream>
#include <random>
#include <ctime>
#include "array_sequence.hpp"
#include "list_sequence.hpp"
#include "BubbleSort.hpp"
#include "ChoosenSort.hpp"
#include "Qsort.hpp"
using namespace std;

int cmp(int a, int b) {
	return a < b;
}

int main() {
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
	auto ChSort = new ChoosenSort<int>();
	auto seq2 = ChSort->SortSequence(seq, cmp);
	for (int i = 0; i < seq2->GetLength(); ++i) {
		cout << seq2->Get(i) << " ";
	}
	cout << "\n";
	auto BubSort = new ChoosenSort<int>();
	auto seq3 = BubSort->SortSequence(seq, cmp);
	for (int i = 0; i < seq3->GetLength(); ++i) {
		cout << seq3->Get(i) << " ";
	}
	cout << "\n";
	auto QuickSort = new Qsort<int>();
	auto seq4 = QuickSort->SortSequence(seq, cmp);
	for (int i = 0; i < seq4->GetLength(); ++i) {
		cout << seq4->Get(i) << " ";
	}
	cout << "\n";
}