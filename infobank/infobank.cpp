#include <iostream>
#include <string>


using namespace std;



class ChannelBase {//부모 클래스
public:
    int channelId;
    string chanelName;
    string broadCastName;
};



class RadioChanel : public ChannelBase {//상속
public:
    // chanelId;  // 클래스 멤버 변수
    //string chanelName;
    //string broadCastName;
    int freqency;

    void inputRadioChanelInfo() {
        std::cout << "Enter channelId: ";
        std::cin >> channelId;
        std::cout << "Enter broadCastName: ";
        std::cin >> broadCastName;
        std::cout << "Enter freqency: ";
        std::cin >> freqency;
    }

    void outputRadioChanelInfo() {
        std::cout << "channelId: ";
        std::cout << channelId;
        std::cout << "chanelName: ";
        std::cout << chanelName;
        std::cout << "broadCastName: ";
        std::cout << broadCastName;
        std::cout << "freqency: ";
        std::cout << freqency;
    }

};

class TvChanel : public ChannelBase {//상속
public:
    //int chanelId;  // 클래스 멤버 변수
    //string chanelName;
    //string broadCastName;
    int freqency;
    int chanelNumber;
    string broadCastType;

    void inputTvChanelInfo() {
        std::cout << "Enter chanelName: ";
        std::cin >> chanelName;
        std::cout << "Enter broadCastName: ";
        std::cin >> broadCastName;
        std::cout << "Enter freqency: ";
        std::cin >> freqency;
        std::cout << "Enter broadCastType: ";
        std::cin >> broadCastType;
    }


    void outputTvChanelInfo() {
        std::cout << "chanelName: ";
        std::cout << chanelName;
        std::cout << "broadCastName: ";
        std::cout << broadCastName;
        std::cout << "freqency: ";
        std::cout << freqency;
        std::cout << "broadCastType: ";
        std::cout << broadCastType;
    }

};



class TVRadioChanel : public ChannelBase {//상속
public:
    //int chanelId;  // 클래스 멤버 변수
    //string chanelName;
    //string broadCastName;

    void inputRadioChanelInfo() {
        std::cout << "Enter channelId: ";
        std::cin >> channelId;
        std::cout << "Enter chanelName: ";
        std::cin >> chanelName;
        std::cout << "Enter broadCastName: ";
        std::cin >> broadCastName;
    }


    void outputRadioChanelInfo() {
        std::cout << "channelId: ";
        std::cout << channelId;
        std::cout << "chanelName: ";
        std::cout << chanelName;
        std::cout << "broadCastName: ";
        std::cout << broadCastName;
     }


};

class ChannelManager {
public:

    template <typename T>
    static void bubbleSortChannels(T channels[], int size) {//소트
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if (channels[j].channelId > channels[j + 1].channelId) {
                    swap(channels[j], channels[j + 1]);
                }
            }
        }
    }

    template <typename T>
    static void displayChannels(T channels[], int size) {//출력
        for (int i = 0; i < size; i++) {
            cout << "객체 " << i + 1 << " - channel ID: " << channels[i].channelId << " - Channel Name: " << channels[i].chanelName << " - Broadcast Name: " << channels[i].broadCastName << endl;
        }
    }


    template <typename T>//이름으로 소트한다
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

    TvChanel tvChannels[4];

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

    TVRadioChanel tvRadioChannels[2];

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

    cout << "요구사항 1 끝 " << endl;


    cout << "요구사항 2 " << endl;
 
    //배열에 부모클래스 전부 넣기
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

    //채널 번호로 소트
    ChannelManager::bubbleSortChannels(allChannels, 9);
    //디스플레이
    cout << "Sorted Channels:" << endl;
    ChannelManager::displayChannels(allChannels, 9);

    

    //채널이름으로 소트
    ChannelManager::bubbleSortChannelsByName(allChannels, 9);
    //디스플레이
    cout << "Sorted Channels by Name:" << endl;
    ChannelManager::displayChannels(allChannels, 9);

    cout << "요구사항 2 끝" << endl;





    return 0;
}


