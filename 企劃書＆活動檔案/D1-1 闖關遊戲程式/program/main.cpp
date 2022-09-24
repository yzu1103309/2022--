#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>
using namespace std;

struct Team
{
public:
//private:
    char ID[9];
    int tries;
};

void Login();
void choose(string IN);
void auth(size_t pos);
void createDatabase();
void writeBack();
void story();
vector<Team> teams;

int main()
{
    createDatabase();

    while(true)
    {
        Login();
    }
}

void Login()
{
    string IN;
    size_t pos = -1;
    cout << "\n\e[0;34m\"未解開的的機密調查資料\"\e[1;37m" << endl;
    cout << "please enter Team ID: ";
    cin >> IN;
    for(size_t t = 0; t < teams.size(); t++)
    {
        if(IN == teams[t].ID)
        {
            pos = t;
        }
    }

    if(pos != -1)
    {
        system("clear");
        cout << endl << "Basic Info:" << endl << "登入身份: 第" << pos+1 << "小隊" << endl;
        cout << "剩餘次數: " << teams[pos].tries << "次" << endl << endl;
        if(teams[pos].tries == 0)
        {
            system("read -p \"\e[0;31m[嘗試次數已用盡，Enter結束]\e[1;37m\" continue");
            system("clear");
        }
        else
        {
            system("read -p \"\e[1;33m[Enter確認進入]\e[1;37m\" continue");
            system("clear");
            cout << "\n我是徐大西，目前只有我知道調查的線索，在調查完成之前還沒有打算公開。"
                 << endl  << "請輸入與我相關的八位數字密碼解密此檔案 (Input 0 to cancel): ";
            auth(pos);
        }
    }
    else
    {
        system("clear");
        cout << "\n\e[0;31m查無此小隊任何資料！\n請確認輸入是否正確。\n（大小寫也要注意）\n" << endl;
        system("read -p \"\e[1;33m[Enter返回主頁]\e[1;37m\" continue");
        system("clear");
    }
}

void auth(size_t pos)
{
    string pass;
    cin >> pass;
    if(pass == "0")
    {
        system("clear");
        cout << "\n已取消這次嘗試，將不會累計次數" << endl << endl;
        system("read -p \"\e[1;33m[Enter返回主頁]\e[1;37m\" continue");
        system("clear");
    }
    else if(pass == "19790916")
    {
        story();
    }
    else
    {
        teams[pos].tries --;
        system("clear");
        cout << "\n\e[0;31m解密失敗！\n小組剩餘嘗試次數：" << teams[pos].tries << endl << endl;
        writeBack();
        system("read -p \"\e[1;33m[Enter返回主頁]\e[1;37m\" continue");
        system("clear");
    }
}

void createDatabase() {
    ifstream inFile("/home/User1/P/team.dat", ios::in);

    if (!inFile)
    {
        cerr << "存取檔案失敗" << endl;
        system("read -p \"\e[1;33m[Enter結束程序]\e[1;37m\" continue");
        exit(1);
    }
    else {
        Team tmp;
        while(inFile.read(reinterpret_cast<char*>(&tmp), sizeof(Team)))
        {
            teams.push_back(tmp);
        };
    }
};

void writeBack()
{
    ofstream outFile("/home/User1/P/team.dat", ios::out);

    if(!outFile)
    {
        cerr << "資料儲存失敗" << endl;
        system("read -p \"\e[1;33m[Enter結束程序]\e[1;37m\" continue");
        exit(1);
    }
    else
    {
        for(size_t t = 0; t < teams.size(); t++)
        {
            outFile.write(reinterpret_cast<char*>(&teams[t]), sizeof(Team));
        }
    }

}

void story()
{
    system("clear");
    cout << endl;
    cout << "\e[1;33m已成功解密檔案。" << endl;

    string IN;

    do {
        cout << "\n\e[0;34m\"調查資料內容\"\e[1;37m" << endl;

        cout << "[1] About Me.\n";
        cout << "[2] Journal.\n";
        cout << "[3] Suspects.\n";
        cout << "[4] Exit.\n\n";

        cout << "\e[1;35mPlease Enter Your Choice: \e[1;37m";
        cin >> IN;
        choose(IN);
    }while(IN != "4");

    system("clear");
}

void choose(string IN)
{
    system("clear");
    if(IN == "1")
    {
        cout << "\n我是徐大西，我來自2022年。\n" << endl;
        system("read -p \"\e[1;35m[Enter繼續]\e[1;37m\" continue");
        system("clear");

        cout << "\n我是徐大西，我來自2022年。\n在某一天我回舊家整理東西時，\n" << endl;
        system("read -p \"\e[1;35m[Enter繼續]\e[1;37m\" continue");
        system("clear");

        cout << "\n我是徐大西，我來自2022年。\n在某一天我回舊家整理東西時，\n發現我以前練團錄的歌曲，\n" << endl;
        system("read -p \"\e[1;35m[Enter繼續]\e[1;37m\" continue");
        system("clear");

        cout << "\n我是徐大西，我來自2022年。\n在某一天我回舊家整理東西時，\n發現我以前練團錄的歌曲，\n聽著聽著...我就睡著了，\n" << endl;
        system("read -p \"\e[1;35m[Enter繼續]\e[1;37m\" continue");
        system("clear");

        cout << "\n我是徐大西，我來自2022年。\n在某一天我回舊家整理東西時，\n發現我以前練團錄的歌曲，\n聽著聽著...我就睡著了，\n醒來後發現自己回到了元智大學男一宿。\n" << endl;
    }
    else if(IN == "2")
    {
        cout << "\n1998.09.04 (五)日記：穿越後第一天\n" << endl;
        system("read -p \"\e[1;35m[Enter繼續]\e[1;37m\" continue");
        system("clear");

        cout << "\n1998.09.04 (五)日記：穿越後第一天\n"
                << "不知道為什麼我穿越回1998年了，但我來不及阻止他的死亡......\n" << endl;
        system("read -p \"\e[1;35m[Enter繼續]\e[1;37m\" continue");
        system("clear");

        cout << "\n1998.09.04 (五)日記：穿越後第一天\n"
             << "不知道為什麼我穿越回1998年了，但我來不及阻止他的死亡......\n"
             << endl << "這是我目前知道的一些事情......\n" << endl;
        system("read -p \"\e[1;35m[Enter繼續]\e[1;37m\" continue");
        system("clear");
        cout << "\n1998.09.04 (五)日記：穿越後第一天\n"
             << "不知道為什麼我穿越回1998年了，但我來不及阻止他的死亡......\n"
             << endl << "這是我目前知道的一些事情......\n"
             << "- 1998.07.06 入住宿舍\n" << endl;
        system("read -p \"\e[1;35m[Enter繼續]\e[1;37m\" continue");
        system("clear");

        cout << "\n1998.09.04 (五)日記：穿越後第一天\n"
             << "不知道為什麼我穿越回1998年了，但我來不及阻止他的死亡......\n"
             << endl << "這是我目前知道的一些事情......\n"
             << "- 1998.07.06 入住宿舍\n- 1998.07.07 他們遇見了教授\n" << endl;
        system("read -p \"\e[1;35m[Enter繼續]\e[1;37m\" continue");
        system("clear");

        cout << "\n1998.09.04 (五)日記：穿越後第一天\n"
             << "不知道為什麼我穿越回1998年了，但我來不及阻止他的死亡......\n"
             << endl << "這是我目前知道的一些事情......\n"
             << "- 1998.07.06 入住宿舍\n- 1998.07.07 他們遇見了教授\n"
             << "- 1998.07.24 奕辰和教授在一起了\n" << endl;
        system("read -p \"\e[1;35m[Enter繼續]\e[1;37m\" continue");
        system("clear");

        cout << "\n1998.09.04 (五)日記：穿越後第一天\n"
             << "不知道為什麼我穿越回1998年了，但我來不及阻止他的死亡......\n"
             << endl << "這是我目前知道的一些事情......\n"
             << "- 1998.07.06 入住宿舍\n- 1998.07.07 他們遇見了教授\n"
             << "- 1998.07.24 奕辰和教授在一起了\n- 1998.08.16 導火線\n" << endl;
        system("read -p \"\e[1;35m[Enter繼續]\e[1;37m\" continue");
        system("clear");

        cout << "\n1998.09.04 (五)日記：穿越後第一天\n"
             << "不知道為什麼我穿越回1998年了，但我來不及阻止他的死亡......\n"
             << endl << "這是我目前知道的一些事情......\n"
             << "- 1998.07.06 入住宿舍\n- 1998.07.07 他們遇見了教授\n"
             << "- 1998.07.24 奕辰和教授在一起了\n- 1998.08.16 導火線\n- 1998.08.29 家人生病\n" << endl;
        system("read -p \"\e[1;35m[Enter繼續]\e[1;37m\" continue");
        system("clear");

        cout << "\n1998.09.04 (五)日記：穿越後第一天\n"
             << "不知道為什麼我穿越回1998年了，但我來不及阻止他的死亡......\n"
             << endl << "這是我目前知道的一些事情......\n"
             << "- 1998.07.06 入住宿舍\n- 1998.07.07 他們遇見了教授\n"
             << "- 1998.07.24 奕辰和教授在一起了\n- 1998.08.16 導火線\n- 1998.08.29 家人生病\n"
             << "- 1998.09.01 被迫分手，他卻不知道\n" << endl;
        system("read -p \"\e[1;35m[Enter繼續]\e[1;37m\" continue");
        system("clear");

        cout << "\n1998.09.04 (五)日記：穿越後第一天\n"
             << "不知道為什麼我穿越回1998年了，但我來不及阻止他的死亡......\n"
             << endl << "這是我目前知道的一些事情......\n"
             << "- 1998.07.06 入住宿舍\n- 1998.07.07 他們遇見了教授\n"
             << "- 1998.07.24 奕辰和教授在一起了\n- 1998.08.16 導火線\n- 1998.08.29 家人生病\n"
             << "- 1998.09.01 被迫分手，他卻不知道\n"
             << "- 1998.09.03 阿忠擬好檢舉函，藏在圖書館當中，尚未寄出\n" << endl;
        system("read -p \"\e[1;35m[Enter繼續]\e[1;37m\" continue");
        system("clear");

        cout << "\n1998.09.04 (五)日記：穿越後第一天\n"
             << "不知道為什麼我穿越回1998年了，但我來不及阻止他的死亡......\n"
             << endl << "這是我目前知道的一些事情......\n"
             << "- 1998.07.06 入住宿舍\n- 1998.07.07 他們遇見了教授\n"
             << "- 1998.07.24 奕辰和教授在一起了\n- 1998.08.16 導火線\n- 1998.08.29 家人生病\n"
             << "- 1998.09.01 被迫分手，他卻不知道\n"
             << "- 1998.09.03 阿忠擬好檢舉函，藏在圖書館當中，尚未寄出\n- 1998.09.04 死亡\n" << endl;
        system("read -p \"\e[1;35m[Enter繼續]\e[1;37m\" continue");
        system("clear");

        cout << "\n1998.09.04 (五)日記：穿越後第一天\n"
             << "不知道為什麼我穿越回1998年了，但我來不及阻止他的死亡......\n"
             << endl << "這是我目前知道的一些事情......\n"
             << "- 1998.07.06 入住宿舍\n- 1998.07.07 他們遇見了教授\n"
             << "- 1998.07.24 奕辰和教授在一起了\n- 1998.08.16 導火線\n- 1998.08.29 家人生病\n"
             << "- 1998.09.01 被迫分手，他卻不知道\n"
             << "- 1998.09.03 阿忠擬好檢舉函，藏在圖書館當中，尚未寄出\n- 1998.09.04 死亡\n" << endl
             << "到底是誰......\n" << endl;
    }
    else if(IN == "3")
    {
        cout << "\n不是警衛，他沒辦法混入宿舍...太明顯了...\n" << endl;
        system("read -p \"\e[1;35m[Enter繼續]\e[1;37m\" continue");
        system("clear");

        cout << "\n不是警衛，他沒辦法混入宿舍...太明顯了...\n\n"
        << "也不是教授，他三天內還來不及計畫完殺害奕辰的計畫，更何況是執行\n" << endl;
        system("read -p \"\e[1;35m[Enter繼續]\e[1;37m\" continue");
        system("clear");

        cout << "\n不是警衛，他沒辦法混入宿舍...太明顯了...\n\n"
             << "也不是教授，他三天內還來不及計畫完殺害奕辰的計畫，更何況是執行\n\n"
             << "葉勳? 他也喜歡教授?\n" << endl;
        system("read -p \"\e[1;35m[Enter繼續]\e[1;37m\" continue");
        system("clear");

        cout << "\n不是警衛，他沒辦法混入宿舍...太明顯了...\n\n"
             << "也不是教授，他三天內還來不及計畫完殺害奕辰的計畫，更何況是執行\n\n"
             << "葉勳? 他也喜歡教授?\n\n阿忠? 他忌妒著第一名的位子。\n" << endl;
        system("read -p \"\e[1;35m[Enter繼續]\e[1;37m\" continue");
        system("clear");

        cout << "\n不是警衛，他沒辦法混入宿舍...太明顯了...\n\n"
             << "也不是教授，他三天內還來不及計畫完殺害奕辰的計畫，更何況是執行\n\n"
             << "葉勳? 他也喜歡教授?\n\n阿忠? 他忌妒著第一名的位子。\n\n"
             << "那個錄音機，我聽到音檔裡奕辰在和一個人對話，\n" << endl;
        system("read -p \"\e[1;35m[Enter繼續]\e[1;37m\" continue");
        system("clear");

        cout << "\n不是警衛，他沒辦法混入宿舍...太明顯了...\n\n"
             << "也不是教授，他三天內還來不及計畫完殺害奕辰的計畫，更何況是執行\n\n"
             << "葉勳? 他也喜歡教授?\n\n阿忠? 他忌妒著第一名的位子。\n\n"
             << "那個錄音機，我聽到音檔裡奕辰在和一個人對話，\n"
             << "聲音太模糊了，可是有聽到放下筆跟杯子的聲音，\n" << endl;
        system("read -p \"\e[1;35m[Enter繼續]\e[1;37m\" continue");
        system("clear");

        cout << "\n不是警衛，他沒辦法混入宿舍...太明顯了...\n\n"
             << "也不是教授，他三天內還來不及計畫完殺害奕辰的計畫，更何況是執行\n\n"
             << "葉勳? 他也喜歡教授?\n\n阿忠? 他忌妒著第一名的位子。\n\n"
             << "那個錄音機，我聽到音檔裡奕辰在和一個人對話，\n"
             << "聲音太模糊了，可是有聽到放下筆跟杯子的聲音。\n"
             << "不久後對話的聲音斷掉了，\n" << endl;
        system("read -p \"\e[1;35m[Enter繼續]\e[1;37m\" continue");
        system("clear");

        cout << "\n不是警衛，他沒辦法混入宿舍...太明顯了...\n\n"
             << "也不是教授，他三天內還來不及計畫完殺害奕辰的計畫，更何況是執行\n\n"
             << "葉勳? 他也喜歡教授?\n\n阿忠? 他忌妒著第一名的位子。\n\n"
             << "那個錄音機，我聽到音檔裡奕辰在和一個人對話，\n"
             << "聲音太模糊了，可是有聽到放下筆跟杯子的聲音。\n"
             << "不久後對話的聲音斷掉了，\n有人倒下的聲音，隨後傳來一絲微弱的開門聲，\n" << endl;
        system("read -p \"\e[1;35m[Enter繼續]\e[1;37m\" continue");
        system("clear");

        cout << "\n不是警衛，他沒辦法混入宿舍...太明顯了...\n\n"
             << "也不是教授，他三天內還來不及計畫完殺害奕辰的計畫，更何況是執行\n\n"
             << "葉勳? 他也喜歡教授?\n\n阿忠? 他忌妒著第一名的位子。\n\n"
             << "那個錄音機，我聽到音檔裡奕辰在和一個人對話，\n"
             << "聲音太模糊了，可是有聽到放下筆跟杯子的聲音。\n"
             << "不久後對話的聲音斷掉了，\n有人倒下的聲音，隨後傳來一絲微弱的開門聲，\n"
             << "還有一陣拖椅子的聲響。\n" << endl;
        system("read -p \"\e[1;35m[Enter繼續]\e[1;37m\" continue");
        system("clear");

        cout << "\n不是警衛，他沒辦法混入宿舍...太明顯了...\n\n"
             << "也不是教授，他三天內還來不及計畫完殺害奕辰的計畫，更何況是執行\n\n"
             << "葉勳? 他也喜歡教授?\n\n阿忠? 他忌妒著第一名的位子。\n\n"
             << "那個錄音機，我聽到音檔裡奕辰在和一個人對話，\n"
             << "聲音太模糊了，可是有聽到放下筆跟杯子的聲音。\n"
             << "不久後對話的聲音斷掉了，\n有人倒下的聲音，隨後傳來一絲微弱的開門聲，\n"
             << "還有一陣拖椅子的聲響。\n\n難不成他的水被下毒了嗎...?\n" << endl;
    }
    else if(IN == "4")
    {
        return;
    }
    else
    {
        cout << "\n無法辨識，請輸入可用選項\n" << endl;
    }
    system("read -p \"\e[1;33m[Enter返回選單]\e[1;37m\" continue");
    system("clear");
}