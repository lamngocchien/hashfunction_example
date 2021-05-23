#define _CRT_SECURE_NO_DEPRECATE
#include<iostream>
using namespace std;
#define hashTableSize 35

struct Node {
	char text[50];
	int cnt;
};
struct Node hashTable[hashTableSize];

unsigned long charhashfunct( char* str) {
	unsigned long hash = 5381;
	int c;
	while (c = *str++)
	{
		hash = ((hash << 5) + hash) + c;
	}
	return hash;
}


void insert(char* str) {
	unsigned long idx = charhashfunct(str)% hashTableSize;
	cout << "text = " << str <<" cal_idx = "<< idx << endl;
	while (hashTable[idx].text[0] != '\0') { 
		idx++; 
		if (idx > hashTableSize)
			idx = 0;
	}
	cout << "text = " << str <<" final_idx = "<< idx << endl;

	int len = 0;
	while (str[len] != '\0')
	{
		hashTable[idx].text[len] = str[len];
		len++;
	}
	hashTable[idx].text[len] = str[len];
	hashTable[idx].cnt = 1;
}

int search(char* str) {
	char char_array[10];
	//strcpy((char*)char_array, text.c_str());
	//unsigned long idx = charhashfunct(char_array) % hashTableSize;
	unsigned long idx = charhashfunct(str) % hashTableSize;
	while (hashTable[idx].text[0] != '\0' && strcmp(hashTable[idx].text, str) != 0 ){
		idx++;
		if (idx > hashTableSize)
			idx = 0;
	}
	if (strcmp(hashTable[idx].text, str) == 0) return idx;
	return -1;
}


void printHashTable(){
	cout<<"=================================================="<<endl;
	for(int i = 0; i<= hashTableSize; i++){
		cout << "idx = " << i <<" value = "<< hashTable[i].text <<" // cnt = "<<hashTable[i].cnt<< endl;
	}
	cout<<"=================================================="<<endl;

}

void init() {
	for (int i = 0; i <= hashTableSize; i++) {
		hashTable[i].text[0] = '\0';
		hashTable[i].cnt = 0;
	}
}


int main() {  
	//init();
	//freopen("input.txt", "r", stdin);
	//char list[10][100] = {"public","domain","created","found","device" , "have", "name", "now", "time" };
	freopen("output.txt", "w", stdout);
	string text = "the explosion of violence between Israeli Arabs and Jews who had lived in mixed communities for years was one of the most shocking results of the conflict between Israel and Palestinian militants";


	int len = 0;
	//cout <<"text:";
	int temp_len = 0;
	char temp[15];
	//insert("domain");
	printHashTable();
	while(text[len] != '\0'){
		//cout <<text[len];
		if (text[len] == ' '){
			temp[temp_len] = '\0';
			cout<<"=================================================="<<endl;
			cout <<"str = "<< temp << endl;
			
			int found = search(temp);
			cout<<"search :"<<found<<endl;
			if (found == -1)
				insert(temp);
			else
				hashTable[found].cnt += 1;
			temp_len = -1;
			
		}
		else
			temp[temp_len] = text[len];
		temp_len++;
		len++;
	}
	cout <<endl;
	printHashTable();

	cout <<"between found: "<<search ("Jews")<<endl;
	cout <<"of found: "<<search ("of")<<endl;

	return 0;
}
