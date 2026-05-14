#include<iostream>
#include<string>
using namespace std;
int main() {
	char str[20];
	cout << "Enter string: ";
	cin >> str;
	cout << "\nLength of string: " << strlen(str);
	cout << "\nReversed string: ";	
	for(int i=strlen(str)-1; i>=0; i--) {
		cout << str[i];
	}
	cout << "\nNumber of vowels: ";
	int count = 0;
	for(int i=0; str[i] != '\0'; i++) {
		if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' ||
		   str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U') {
			count++;
		}
	}
	cout << count;
	cout << "\nNumber of consonants: " << (strlen(str) - count);
	cout << "\nString Palindrome: ";
	bool isPalindrome = true;
	for(int i=0; i<strlen(str)/2; i++) {
		if(tolower(str[i]) != tolower(str[strlen(str)-1-i])) {
			isPalindrome = false;
			break;
		}
	}
	cout << (isPalindrome ? "Yes" : "No");
	cout << endl;
}