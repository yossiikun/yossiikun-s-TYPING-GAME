// yossiikun's TYPING GAME V1 //
// By yossiikun //






    //ライブラリ読み込み
    //lib load

#include <iostream>
#include <string>

    // 短縮用
    // 正確にはstd::countかstd::stringではなく
    // cout stringみたいに簡単に入力できる

using namespace std;

int main() {
    cout << "Press ENTER to start (or type anything and press ENTER)...\n";

    string dummy;
    getline(cin, dummy);  // ここで入力待ち、何でもOK

    cout << "Game starts!\n";
}
