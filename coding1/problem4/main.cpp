#include <iostream>
#include "KeyChar.h"
#include "Input.h"
using std::cout;
using std::endl;

int main() {
    cout << "输入整数(0-9):";
    unsigned long choice1 = Input::getInstance( ).getRangeULong( 0, 9 );
    cout << "\n输入的整数是=" << choice1 << endl << endl;

    cout << "输入整数(0-999):";
    unsigned long choice2 = Input::getInstance( ).getRangeULong( 0, 999 );
    cout << "\n输入的整数是=" << choice2 << endl << endl;

    cout << "输入整数(20-9999):";
    unsigned long choice3 = Input::getInstance( ).getRangeULong( 20, 9999 );
    cout << "\n输入的整数是=" << choice3 << endl << endl;

    using Keys = KeyChar::Value;
    Keys choice;

    cout << "选择指令(Yes/No):";
    choice = Input::getInstance( ).getKeyChar( Keys::KEY_YES | Keys::KEY_NO );
    cout << "\n输入的指令是=" << KeyChar::getName(choice ) << endl << endl;

    cout << "选择指令(Ok/Cancel):";
    choice = Input::getInstance( ).getKeyChar( Keys::KEY_OK | Keys::KEY_CANCEL );
    cout << "\n输入的指令是=" << KeyChar::getName( choice ) << endl << endl;

    cout << "选择指令(Ok/Cancel/Abort/Retry/Help):";
    choice = Input::getInstance( ).getKeyChar( Keys::KEY_OK | Keys::KEY_CANCEL | Keys::KEY_ABORT | Keys::KEY_RETRY | Keys::KEY_HELP );
    cout << "\n输入的指令是=" << KeyChar::getName( choice ) << endl << endl;

    std::cout << "Hello World!\n";
    system( "pause" );
}