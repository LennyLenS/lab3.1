#include <iostream>
#include "array_sequence.hpp"
#include "list_sequence.hpp"
using namespace std;

int main() {
	int a[5] = {100, 6, 5, 1, 7};
	ArraySequence<int>* seq = new ArraySequence<int>(a, 5);
	cout << seq->Get(0);
	seq->Swap(0, 2);
	cout << seq->Get(0);
	ArraySequence<int>* seq2 = seq->GetCopy();
	cout << " " << seq2->Get(2);
	seq2->Set(-1, 1);
	cout << " " << seq->Get(1);
}