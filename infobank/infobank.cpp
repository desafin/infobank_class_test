#include <iostream>
#include <string>

using namespace std;

class ChannelBase {//공통점을 묶어서 부모클래스를 만들었다
public:
	int channelId;
	string chanelName;
	string broadCastName;

	ChannelBase() {//생성자와 소멸자 생성자 나올때 변수를 초기화하도록 하여 오류를 제거했다
		channelId = 0;
		chanelName = "";
		broadCastName = "";
		cout << "ChannelBase 생성자 " << endl;
	}
	~ChannelBase() {
		cout << "ChannelBase 소멸자 " << endl;
	}

	virtual void inputChannelInfo() {//가상함수 객체에 데이터를 집어넣기위해 만들었음 상속받은 클래스에서 같은이름의 함수를 쓰게될것이다
		cout << "Enter channelId: ";
		cin >> channelId;
		cout << "Enter chanelName: ";
		cin >> chanelName;
		cout << "Enter broadCastName: ";
		cin >> broadCastName;
	}

	virtual void outputChannelInfo() {//데이터를 출력하기 위한 용도의 함수다 가상함수
		cout << "channelId: " << channelId << " - chanelName: " << chanelName << " - broadCastName: " << broadCastName << endl;
	}
};

class RadioChanel : public ChannelBase {//부모클래스로 부터 상속받음 자식 클래스의 기능이 더해지고 함수는 오버라이딩된다
public:
	int freqency;

	RadioChanel() {//생성자와 동시에 초기화된다
		freqency = 0;
		cout << "RadioChanel 생성자 " << endl;
	}
	~RadioChanel() {
		cout << "RadioChanel 소멸자 " << endl;
	}

	void inputChannelInfo() override {//데이터를 집어넣기 위해서 만든함수 오버라이딩된다 부모의 함수가 실행되고 자식의 함수가 실행되는거 맞겠죠?
		ChannelBase::inputChannelInfo();
		cout << "Enter freqency: ";
		cin >> freqency;
	}

	void outputChannelInfo() override {//데이터를 출력하는 함수 오버라이딩된다
		ChannelBase::outputChannelInfo();
		cout << "freqency: " << freqency << endl;
	}
};

class TvChanel : public ChannelBase {//부모클래스로 부터 상속받음
public:
	int freqency;
	int chanelNumber;
	string broadCastType;


	TvChanel() {
		freqency = 0;
		chanelNumber = 0;
		broadCastType = "";
		cout << "TvChanel 생성자 " << endl;
	}
	~TvChanel() {
		cout << "TvChanel 소멸자 " << endl;
	}

	void inputChannelInfo() override {
		ChannelBase::inputChannelInfo();
		cout << "Enter freqency: ";
		cin >> freqency;
		cout << "Enter chanelNumber: ";
		cin >> chanelNumber;
		cout << "Enter broadCastType: ";
		cin >> broadCastType;
	}

	void outputChannelInfo() override {
		ChannelBase::outputChannelInfo();
		cout << "freqency: " << freqency << " - chanelNumber: " << chanelNumber << " - broadCastType: " << broadCastType << endl;
	}
};

class TVRadioChanel : public ChannelBase {
	//추가할것이 없다
public:
	TVRadioChanel() {

		cout << "TVRadioChanel 생성자 " << endl;
	}
	~TVRadioChanel() {
		cout << "TVRadioChanel 소멸자 " << endl;
	}
};

class ChannelManager {//채널을 관리하는 클래스
public:





	ChannelManager() {

		cout << "ChannelManager 생성자 " << endl;
	}
	~ChannelManager() {
		cout << "ChannelManager 소멸자 " << endl;
	}






	template <typename T>
	static void bubbleSortChannels(T channels[], int size) {//객체와 어레이사이즈를 매개변수로 받는다
		for (int i = 0; i < size - 1; i++) {
			for (int j = 0; j < size - i - 1; j++) {
				if (channels[j].channelId > channels[j + 1].channelId) {
					swap(channels[j], channels[j + 1]);
				}
			}
		}
	}



	template <typename T>
	static void bubbleSortChannelsByName(T channels[], int size) {
		for (int i = 0; i < size - 1; i++) {
			for (int j = 0; j < size - i - 1; j++) {
				if (channels[j].chanelName > channels[j + 1].chanelName) {
					swap(channels[j], channels[j + 1]);
				}
			}
		}
	}


	template <typename T>
	static void displayChannels(T channels[], int size) {
		for (int i = 0; i < size; i++) {
			cout << "객체 " << i + 1 << " - ";
			channels[i].outputChannelInfo();
		}
	}
};

int main() {


	RadioChanel radioChannels[3];//왜 인덱스가 0부터 시작하지않고 객체어레이는 1부터 시작할까요? radioChannels[2]로하면 사이즈 오류가 나요 ...
	TvChanel tvChannels[4];
	TVRadioChanel tvRadioChannels[2];


	radioChannels[0].channelId = 3;//객체에 모든데이터 집어넣기
	radioChannels[0].chanelName = "A";
	radioChannels[0].broadCastName = "KBS";
	radioChannels[0].freqency = 100;

	radioChannels[1].channelId = 2;
	radioChannels[1].chanelName = "B";
	radioChannels[1].broadCastName = "SBS";
	radioChannels[1].freqency = 101;

	radioChannels[2].channelId = 1;
	radioChannels[2].chanelName = "C";
	radioChannels[2].broadCastName = "MBC";
	radioChannels[2].freqency = 102;


	tvChannels[0].channelId = 5;
	tvChannels[0].chanelName = "E";
	tvChannels[0].broadCastName = "KBS";
	tvChannels[0].chanelNumber = 7;
	tvChannels[0].broadCastType = "지상파";

	tvChannels[1].channelId = 8;
	tvChannels[1].chanelName = "F";
	tvChannels[1].broadCastName = "SBS";
	tvChannels[1].chanelNumber = 5;
	tvChannels[1].broadCastType = "지상파";

	tvChannels[2].channelId = 7;
	tvChannels[2].chanelName = "G";
	tvChannels[2].broadCastName = "MBC";
	tvChannels[2].chanelNumber = 11;
	tvChannels[2].broadCastType = "지상파";

	tvChannels[3].channelId = 6;
	tvChannels[3].chanelName = "H";
	tvChannels[3].broadCastName = "JTBC";
	tvChannels[3].chanelNumber = 15;
	tvChannels[3].broadCastType = "케이블";


	tvRadioChannels[0].channelId = 3;
	tvRadioChannels[0].chanelName = "I";
	tvRadioChannels[0].broadCastName = "MBC";

	tvRadioChannels[1].channelId = 7;
	tvRadioChannels[1].chanelName = "J";
	tvRadioChannels[1].broadCastName = "MBC";


	//객체별로 소트하기
	cout << "요구사항 1시작" << endl;
	ChannelManager::bubbleSortChannels(radioChannels, 3);//채널숫자로 소트하기
	cout << "Sorted Radio Channels:" << endl;
	ChannelManager::displayChannels(radioChannels, 3);

	ChannelManager::bubbleSortChannels(tvChannels, 4);//채널숫자로 소트하기
	cout << "Sorted TV Channels:" << endl;
	ChannelManager::displayChannels(tvChannels, 4);

	ChannelManager::bubbleSortChannels(tvRadioChannels, 2); //채널숫자로 소트하기
	cout << "Sorted TVRadio Channels:" << endl;
	ChannelManager::displayChannels(tvRadioChannels, 2);


	cout << "요구사항 1끝" << endl;


	cout << "요구사항 2 " << endl;

	ChannelBase* allChannels = new ChannelBase[9];//동적배열

	for (int i = 0; i < 3; i++) {//배열에 모든 객체를 집어넣는다
		allChannels[i] = radioChannels[i];
	}
	for (int i = 0; i < 4; i++) {
		allChannels[3 + i] = tvChannels[i];
	}
	for (int i = 0; i < 2; i++) {
		allChannels[7 + i] = tvRadioChannels[i];
	}

	ChannelManager::bubbleSortChannels(allChannels, 9);
	cout << "Sorted Channels:" << endl;
	ChannelManager::displayChannels(allChannels, 9);

	ChannelManager::bubbleSortChannelsByName(allChannels, 9);
	cout << "Sorted Channels by Name:" << endl;
	ChannelManager::displayChannels(allChannels, 9);

	cout << "요구사항 2 끝" << endl;

	delete[] allChannels;//메모리에서 제거

	return 0;


}
