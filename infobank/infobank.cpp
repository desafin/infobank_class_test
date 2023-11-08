#include <iostream>
#include <string>

using namespace std;

class ChannelBase {
public:
    int channelId;
    string chanelName;
    string broadCastName;

    ChannelBase() {
        channelId = 0;
        chanelName = "";
        broadCastName = "";
        cout << "ChannelBase 생성자 " << endl ;
    }
    ~ChannelBase() {
        cout << "ChannelBase 소멸자 " << endl;
    }

    virtual void inputChannelInfo() {
        cout << "Enter channelId: ";
        cin >> channelId;
        cout << "Enter chanelName: ";
        cin >> chanelName;
        cout << "Enter broadCastName: ";
        cin >> broadCastName;
    }

    virtual void outputChannelInfo() {
        cout << "channelId: " << channelId << " - chanelName: " << chanelName << " - broadCastName: " << broadCastName << endl;
    }
};

class RadioChanel : public ChannelBase {
public:
    int freqency;

    RadioChanel() {
        freqency = 0;
        cout << "RadioChanel 생성자 " << endl;
    }
    ~RadioChanel() {
        cout << "RadioChanel 소멸자 " << endl;
    }

    void inputChannelInfo() override {
        ChannelBase::inputChannelInfo();
        cout << "Enter freqency: ";
        cin >> freqency;
    }

    void outputChannelInfo() override {
        ChannelBase::outputChannelInfo();
        cout << "freqency: " << freqency << endl;
    }
};

class TvChanel : public ChannelBase {
public:
    int freqency;
    int chanelNumber;
    string broadCastType;


    TvChanel() {
        freqency = 0;
        chanelNumber=0;
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

class ChannelManager {
public:





    ChannelManager() {

        cout << "ChannelManager 생성자 " << endl;
    }
    ~ChannelManager() {
        cout << "ChannelManager 소멸자 " << endl;
    }






    template <typename T>
    static void bubbleSortChannels(T channels[], int size) {
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if (channels[j].channelId > channels[j + 1].channelId) {
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
};

int main() {
    RadioChanel radioChannels[3];
    TvChanel tvChannels[4];
    TVRadioChanel tvRadioChannels[2];


    radioChannels[0].channelId = 3;
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


    cout << "요구사항 1시작" << endl;
    ChannelManager::bubbleSortChannels(radioChannels, 3);
    cout << "Sorted Radio Channels:" << endl;
    ChannelManager::displayChannels(radioChannels, 3);

    ChannelManager::bubbleSortChannels(tvChannels, 4);
    cout << "Sorted TV Channels:" << endl;
    ChannelManager::displayChannels(tvChannels, 4);

    ChannelManager::bubbleSortChannels(tvRadioChannels, 2);
    cout << "Sorted TVRadio Channels:" << endl;
    ChannelManager::displayChannels(tvRadioChannels, 2);


    cout << "요구사항 1시작" << endl;

   

    ChannelManager::bubbleSortChannels(radioChannels, 3);
    cout << "Sorted Radio Channels:" << endl;
    ChannelManager::displayChannels(radioChannels, 3);

  

    ChannelManager::bubbleSortChannels(tvChannels, 4);
    cout << "Sorted TV Channels:" << endl;
    ChannelManager::displayChannels(tvChannels, 4);


    ChannelManager::bubbleSortChannels(tvRadioChannels, 2);
    cout << "Sorted TVRadio Channels:" << endl;
    ChannelManager::displayChannels(tvRadioChannels, 2);

    cout << "요구사항 1 끝 " << endl;

    cout << "요구사항 2 " << endl;

    ChannelBase allChannels[9];

    for (int i = 0; i < 3; i++) {
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

    return 0;
}
