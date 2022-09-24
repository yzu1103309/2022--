#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

struct Team
{
    char ID[9];
    int chances;
};

//char IDs[12][9] = {
//            "ck6su04c",
//            "hl6m3vm0",
//            "xup6g6u4",
//            "xji6xu4w",
//            "54ru6au6",
//            "tp6qup3u",
//            "tp6vu4xx",
//            "xup6ru8j",
//            "xu6u4vmp",
//            "tp6qup3m",
//            "4mp3cj6y",
//            "4ru6xup6",
//    };

int main()
{
    size_t count = 12;
    Team teams[12] = {
            "ck6su04c",5,
            "hl6m3vm0",5,
            "xup6g6u4",5,
            "xji6xu4w",5,
            "54ru6au6",5,
            "tp6qup3u",5,
            "tp6vu4xx",5,
            "xup6ru8j",5,
            "xu6u4vmp",5,
            "tp6qup3m",5,
            "4mp3cj6y",5,
            "4ru6xup6",5
    };

    ofstream outFile("/home/User1/P/team.dat", ios::out);

    if(!outFile)
    {
        cerr << "存取檔案失敗" << endl;
        system("read -p \"\e[1;33m[Enter結束程序]\e[1;37m\" continue");
        exit(1);
    }
    else
    {
        for(size_t t = 0; t < count; t++)
        {
            outFile.write(reinterpret_cast<char*>(&teams[t]),sizeof(Team));
            cout << "已寫入第" << t+1 << "筆資料 ID: " << teams[t].ID << endl;
        }
        system("read -p \"\e[1;33m[Enter結束程序]\e[1;37m\" continue");
    }
}
