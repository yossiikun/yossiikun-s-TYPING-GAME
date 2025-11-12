// yossiikun's TYPING GAME V1 //
// By yossiikun //
// https://github.com/yossiikun/yossiikun-s-TYPING-GAME //

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <termios.h>
#include <unistd.h>

using namespace std;

    // 変数を宣言（ループ外で使えるように）
    string dummy;
    string target;
    string gameOver;

char getch() {
    char buf = 0;
    struct termios old = {0};
    if(tcgetattr(0, &old) < 0) perror("tcgetattr()");
    old.c_lflag &= ~ICANON; // 改行を待たずに取得
    old.c_lflag &= ~ECHO;   // 入力文字を表示しない
    if(tcsetattr(0, TCSANOW, &old) < 0) perror("tcsetattr ICANON");
    if(read(0, &buf, 1) < 0) perror("read()");
    old.c_lflag |= ICANON;
    old.c_lflag |= ECHO;
    if(tcsetattr(0, TCSADRAIN, &old) < 0) perror("tcsetattr ~ICANON");
    return buf;
}

// ランダムに1文字生成する関数
char randomChar() {
    int r = rand() % 62;  // 0~61の乱数
    char c;
    if(r < 26) c = 'A' + r;          // A-Z
    else if(r < 52) c = 'a' + (r-26); // a-z
    else c = '0' + (r-52);           // 0-9
    return c;
}

int main() {
    bool gameOver = false; // 初期値は false

    // 文字出力
    cout << "Press ENTER to start (or type anything and press ENTER)...\n";

    // 入力待機　いずれかのキーで続行
    getline(cin, dummy);

    // 文字出力
    cout << "Game starts!\n";

    srand(time(0)); // 乱数の種を初期化

    // タイマー開始（50回ループ全体）
    auto start = chrono::high_resolution_clock::now();

    for(int i=0; i<50; i++) {
        
        // 変数targetをリセット（再宣言ではなく代入）
        target = "";  
        
        // ランダムな文字を1文字生成
        for(int j = 0; j < 1; j++) {
            char c = randomChar(); // ランダム文字生成
            target += c;           // 変数targetに追加
        }

        // 生成した文字列を表示
        cout << target << "\n";

        // ループ内で1文字入力を待つ
        char inputChar = getch(); // Enter不要で1文字取得


        // 入力と target を比較
        if(inputChar == target[0]) {
        cout << "Correct!\n";
      } else {
         cout << "Mistyped! Game Over!\n";
          gameOver = true;
          break; // ミスしたらループ終了
      }

    }

    // タイマー終了
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = end - start;
    double Time = elapsed.count(); // 50回ループの合計秒数

    if(gameOver) {
       cout << "\nYou failed!\n";
    } else {
        cout << "\nAll rounds completed!\n";
    }
    cout << "Total time: " << Time << " seconds\n";

    
    //いずれかのキーで続行
    getline(cin, dummy);

}