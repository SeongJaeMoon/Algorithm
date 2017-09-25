#include <iostream>
#include <fstream>
using namespace std;

class FileCompare {
	ifstream src;
	ifstream dest;
public:
	FileCompare(char *fsrc, char* fdest);
	bool compare(); // src와 dest스트림에 열려진 파일이 같은지 검사
};

FileCompare::FileCompare(char *fsrc, char* fdest) {
	src.open(fsrc, ios::in | ios::binary); // 바이너리 I/O 모드로 열기
	if(!src) {
		cout <<fsrc << "열기 오류";
		exit(0); // 열기 실패하면 프로그램 종료
	}
	dest.open(fdest, ios::in | ios::binary); // 바이너리 I/O 모드로 열기
	if(!src) {
		cout <<fdest << "열기 오류";
		exit(0);  // 열기 실패하면 프로그램 종료
	}
}

bool FileCompare::compare() { // 두 파일 비교
	int s;
	while((s=src.get()) != EOF) { // 소스 파일에서 읽은 바이트는 s
		int t = dest.get(); // 목적 파일에서 읽는 바이트는 t
		// t와 s 비교
		if(t == EOF) return false; // 같지 않음
		else if(s != t) return false; // 같지 않음
	}

	// 소스 파일을 끝까지 읽었음
	// 목적 파일에 읽을 것이 남았는지 확인
	int t = dest.get(); 
	if(t != EOF) return false; // 목적 파일에서 읽은 것이 있다면 두 파일은 같지 않음

	// both EOF
	return true;
}

int main() {
	cout << "비교하는 두 파일은" << "a.jpg" << "와" << "b.jpg" << "입니다" << endl;
	cout << "이 두 파일은 소스 폴더에 있어야 합니다" << endl;
	FileCompare comp("a.jpg", "b.jpg"); // a.jpg와 b.jpg의 비교. 두 파일은 소스 폴더에 있어야 함
	if(comp.compare())
		cout << "두 파일은 같습니다." << endl;
	else
		cout << "두 파일은 같지 않습니다." << endl;
}