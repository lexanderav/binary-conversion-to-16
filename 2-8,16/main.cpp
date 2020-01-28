//binary conversion to 16
#include <iostream>
#include <string>
using namespace std;

void int_bin(string bin_num);
string align(string int_bin_num);
string prov_int(string int_bin_num);

int main()
{
	string bin_num = "";
	cout << "Enter binary number : ";
	cin >> bin_num;
	int_bin(bin_num);
}

void int_bin(string bin_num)
{
	string six_num = "";
	int point;
	string int_bin_num = "";
	string res_six_int = "";
	string pen = "";
	string res_six_frac = "";
	string frac_bin_num = "";
	string num = "";
	string frac_num = "";
	point = bin_num.find(".");
	if (point == -1) {
		num = bin_num;
		int_bin_num = prov_int(num);
		res_six_int = align(int_bin_num);
	}
	else {
		pen = ".";
		for (int i = 0; i < point; i++) {
			num = num + bin_num[i];
		}
		for (int i = bin_num.length() - 1; i > point; i--) {
			frac_num = frac_num + bin_num[i];
		}
		int_bin_num = prov_int(num);
		frac_bin_num = prov_int(frac_num);
		reverse(frac_bin_num.begin(), frac_bin_num.end());
		res_six_int = align(int_bin_num);
		res_six_frac = align(frac_bin_num);
	}
	cout << "number in 16 system: " << res_six_int << pen << res_six_frac << endl;
}

string align(string int_bin_num)//convert binary to 16
{
	int i = 0;
	string str_int_octal = "";
	while (i < int_bin_num.length()) {
		string new_bin;
		int int_bin = 0;
		new_bin.assign(int_bin_num, i, 4);
		int_bin = atoi(new_bin.c_str());
		switch (int_bin)
		{
		case 0: str_int_octal = str_int_octal + "0";
			break;
		case 1: str_int_octal = str_int_octal + "1";
			break;
		case 10: str_int_octal = str_int_octal + "2";
			break;
		case 11: str_int_octal = str_int_octal + "3";
			break;
		case 100: str_int_octal = str_int_octal + "4";
			break;
		case 101: str_int_octal = str_int_octal + "5";
			break;
		case 110: str_int_octal = str_int_octal + "6";
			break;
		case 111: str_int_octal = str_int_octal + "7";
			break;
		case 1000: str_int_octal = str_int_octal + "8";
			break;
		case 1001: str_int_octal = str_int_octal + "9";
			break;
		case 1010: str_int_octal = str_int_octal + "A";
			break;
		case 1011: str_int_octal = str_int_octal + "B";
			break;
		case 1100: str_int_octal = str_int_octal + "C";
			break;
		case 1101: str_int_octal = str_int_octal + "D";
			break;
		case 1110: str_int_octal = str_int_octal + "E";
			break;
		case 1111: str_int_octal = str_int_octal + "F";
			break;
		}
		i = i + 4;
	}
	return str_int_octal;
}

string prov_int(string num) // check in the 16 system number of signs
{
	int num_len = 0;
	num_len = num.length();
	if (num_len % 4 == 0) {
		return num;
	}
	else
	{
		int x = 0;
		x = 4 - (num_len % 4);
		for (int i = 1; i <= x; i++) {
			num = "0" + num;
		}
		return num;
	}
}