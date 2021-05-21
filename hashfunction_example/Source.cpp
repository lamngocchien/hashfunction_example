#define _CRT_SECURE_NO_DEPRECATE
#include<iostream>
#include <cstring>
using namespace std;
#define hashTableSize 30

string hashTable[hashTableSize];
unsigned char char_array[10];

unsigned long stringhashfunct(string text) {
	strcpy((char*)char_array, text.c_str());
	char* str = (char*)char_array;
	unsigned long hash = 5381;
	int c;
	while (c = *str++)
	{
		hash = ((hash << 5) + hash) + c;
	}
	return hash;
}


unsigned long charhashfunct(unsigned char* str) {
	unsigned long hash = 5381;
	int c;
	while (c = *str++)
	{
		hash = ((hash << 5) + hash) + c;
	}
	return hash;
}


void insert(string text) {
	strcpy((char*)char_array, text.c_str());
	//unsigned long idx = charhashfunct(char_array)% hashTableSize;
	unsigned long idx = stringhashfunct(text)% hashTableSize;

	while (hashTable[idx] != "") { 
		idx++; 
		if (idx > hashTableSize)
			idx = 0;
	}
	hashTable[idx] = text;
	cout << "text = " << text <<" idx = "<< idx << endl;
}

int search(string text) {
	//strcpy((char*)char_array, text.c_str());
	//unsigned long idx = charhashfunct(char_array) % hashTableSize;
	unsigned long idx = stringhashfunct(text) % hashTableSize;
	while (hashTable[idx] != "" && hashTable[idx] != text){
		idx++;
		if (idx > hashTableSize)
			idx = 0;
	}
	if (hashTable[idx] == text) return idx;
	return -1;
}


void init() {
	for (int i = 0; i <= hashTableSize; i++) {
		hashTable[i] = "";
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	string list[100] = {"public","domain","created","found","device" , "have", "name", "now", "time" };
	
	for (int i = 0; i <= 8; i++){
		cout << "===================================" << endl;
		//strcpy((char *)char_array, list[i].c_str());
		//unsigned long temp = charhashfunct(char_array) % hashTableSize;
		cout << list[i] << endl;
		insert(list[i]);
		//hashTable[i] = list[i];
		//cout <<"hash = "<< temp << endl;
	}

	for (int i = 0; i <= hashTableSize; i++) {
		cout << "index"<<i<<" = "<< hashTable[i] << endl;
	}
	
	for (int i = 0; i <= 8; i++) {
		string text = list[i];
		cout << "Search " << text << " is " << search(text) << endl;;
	}
	//int temp, temp2;
	//cin >> temp >> temp2;
	//cout << temp << " " << temp2 << endl;
	return 0;
}