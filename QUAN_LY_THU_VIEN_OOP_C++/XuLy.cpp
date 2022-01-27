#include "XuLy.h"

string format_Chuoi(string str)
{
	while (str[0] == ' ') {
		str.erase(str.begin() + 0);
	}

	while (str[str.length() - 1] == ' ') {
		str.erase(str.begin() + str.length() - 1);
	}

	for (int i = 0; i < str.length() - 1; i++) {
		if (str[i] == ' ' && str[i + 1] == ' ') {
			str.erase(str.begin() + i + 1);
			i--;
		}
	}

	for (int i = 0; i < str.length(); i++) {
		if (str[i] >= 'A' && str[i] <= 'Z') {
			str[i] = str[i] + 32;
		}
	}

	str[0] = str[0] - 32;
	for (int i = 1; i < str.length() - 1; i++) {
		if (str[i] == ' ' && str[i + 1] != ' ') {
			str[i + 1] = str[i + 1] - 32;
		}
	}
	return str;
}

bool La_Gioi_Tinh(string s) {
	s = format_Chuoi(s);
	if (s == "Nam" || s == "Nu" || s == "Khac") {
		return true;
	}
	return false;
}

bool La_Chuoi_Chuan_Khong_Chua_So(string s) {
	int dem = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == ' ' || s[i] == '\t') {
			dem++;
		}
	}

	if (dem == s.length()) {
		return false;
	}

	for (int i = 0; i < s.length(); i++) {
		if (s.at(i) != ' ' && s.at(i) != '\t' && (tolower(s.at(i)) < 'a' || tolower(s.at(i)) > 'z')) {
			return false;
		}
	}

	return true;
}

bool La_Chuoi_Chuan_Chua_So(string s) {
	int dem = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == ' ' || s[i] == '\t') {
			dem++;
		}
	}

	if (dem == s.length()) {
		return false;
	}

	return true;
}

bool La_So_Dien_Thoai(string num) {
	if (num.length() != 10) {
		return false;
	}

	for (int i = 0; i < num.length(); i++) {
		if (tolower(num.at(i)) < '0' || tolower(num.at(i)) > '9') {
			return false;
		}
	}
	return true;
}

bool La_So_Nguyen(string s) {

	if (s.length() == 0) {
		return false;
	}

	if (s[0] == '-') {
		for (int i = 1; i < s.length(); i++) {
			if (s[i] < '0' || s[i] > '9') {
				return false;
			}
		}
	}

	for (int i = 0; i < s.length(); i++) {
		if (s[i] < '0' || s[i] > '9') {
			return false;
		}
	}

	return true;
}

bool La_CMND(string num) {
	if (num.length() != 9) {
		return false;
	}

	for (int i = 0; i < num.length(); i++) {
		if (tolower(num.at(i)) < '0' || tolower(num.at(i)) > '9') {
			return false;
		}
	}
	return true;
}

bool laChuoiCon(string str1, string str2) {
	str2 = format_Chuoi(str2);

	// chuyen string ve char[]
	int len1 = str1.length();
	char* s1 = new char[len1 + 1];
	for (int i = 0; i < len1; i++) {
		s1[i] = str1[i];
	}
	s1[len1] = '\0';

	int len2 = str2.length();
	char* s2 = new char[len2 + 1];
	for (int i = 0; i < len2; i++) {
		s2[i] = str2[i];
	}
	s2[len2] = '\0';

	int n = 0;
	int m = 0;
	int dem = 0;

	while (*(s1 + n) != '\0') {

		if (*(s1 + n) == *(s2 + m)) {    // neu ky tu dau tien la giong nhau

		   // tiep tuc tim kiem
			while (*(s1 + n) == *(s2 + m) && *(s1 + n) != '\0') {
				n++;
				m++; // cái mà ta đếm số ký tự bằng nhau giữa hai chuỗi
			}

			// Neu day ky tu nay co do dai bang chuoi tim kiem
			if (m == len2) { // nếu m = len của string con thì true
				dem = 1;
				break;
			}
		}
		else {   // Neu ky tu dau tien khong giong nhau
			while (*(s1 + n) != ' ') {    //bo qua, tiep tuc tim kiem tu tiep theo
				n++;
				if (*(s1 + n) == '\0') {
					break;
				}
			}
		}

		n++;
		m = 0;  // reset bien dem.
	}

	if (dem > 0) {
		return true;
	}
	return false;
}

void Xu_Ly_Tiep_Tuc(int &chucnangcon, int &chucnangchinh) {
	cin.seekg(0, ios::end);
	cin.clear();
	string s;
	
	cout << "Nhap ky tu bat ky de tiep tuc, nhap 'm' de tro ve menu chinh, nhap 'n' de thoat chuong trinh: ";
	do {
		getline(cin, s);
		if (s.length() != 1) {
			cout << "Error choice! Re-enter: ";
		}
	} while (s.length() != 1);
	char c = s[0];

	if (c == 'm') {
		chucnangcon = 0;
	}
	else if( c == 'n'){
		chucnangcon = 0;
		chucnangchinh = 0;
	}else {
		system("cls");
	}
}

void Xu_Ly_Tiep_Tuc_3(int& chucnang, int& chucnangcon, int& chucnangchinh) {
	cin.seekg(0, ios::end);
	cin.clear();
	string s;

	cout << "Nhap ky tu bat ky de tiep tuc, nhap 'm' de tro ve menu chinh, nhap 'n' de thoat chuong trinh: ";
	do {
		getline(cin, s);
		if (s.length() != 1) {
			cout << "Error choice! Re-enter: ";
		}
	} while (s.length() != 1);
	char c = s[0];

	if (c == 'm') {
		chucnang = 0;
		chucnangcon = 0;
	}
	else if(c == 'n'){
		chucnang = 0;
		chucnangcon = 0;
		chucnangchinh = 0;
	}else {
		system("cls");
	}
}

string get_Ten(string ten) {
	string s = "";
	int dem = 0;

	for (int i = 0; i < ten.length(); i++) {
		if (ten[i] == ' ') {
			dem++;
		}
	}
	// tran anh quan
	int temp = 0;
	int i = 0;
	while (dem != 0) {
		if (ten[i] == ' ') {
			dem--;
		}
		i++;
		temp = i;
	}

	for (int i = temp; i < ten.length(); i++) {
		s = s + ten[i];
	}
	return s;
}

string get_Ho(string ten) {
	string s = "";
	int dem = 0;

	for (int i = 0; i < ten.length(); i++) {
		if (ten[i] == ' ') {
			dem++;
		}
	}
	// tran anh quan
	int temp = 0;
	int i = 0;
	while (dem != 0) {
		if (ten[i] == ' ') {
			dem--;
		}
		i++;
		temp = i;
	}

	for (int i = 0; i < temp; i++) {
		s = s + ten[i];
	}
	return s;
}

int So_Sanh_Chuoi(string name1, string name2) {
	if (get_Ten(name1).compare(get_Ten(name2)) > 0) {
		return 1;
	}
	else if (get_Ten(name1).compare(get_Ten(name2)) < 0) {
		return -1;
	}
	else {
		if (get_Ho(name1).compare(get_Ho(name2)) > 0) {
			return 1;
		}
		else if (get_Ten(name1).compare(get_Ten(name2)) < 0) {
			return -1;
		}
		else {
			return 0;
		}
	}
}