/*
@Author: mrxhar
@Date:   2023-08-23 20:22:15
@Email:  1337904145@qq.com
@Blog:   
*/

#include <iostream>
#include "v1.h"

int main(){

    using std::cout;
    Tv s42;
    cout << "initial settings for 42\" TV :\n";
    s42.settings();
    s42.onoff();
    s42.chanup();
    cout << "\nAdjusted settings for 42\" TV :\n";
    s42.chanup();
    cout << "\nAdjusted settings for 42\" TV :\n";
    s42.settings();

    Remote grey;

    grey.set_chan(s42, 10);
    grey.volup(s42);
    grey.volup(s42);
    cout << "\n42\" settings after using remote:\n";
    s42.settings();

    Tv s58(Tv::On);
    s58.set_mode();
    grey.set_chan(s58, 28);
    cout << "\n58\" settings:\n";
    s58.settings();

    // 遥控器显示
    cout << "\n===========\n";
    grey.show(s42);
    cout << "\n===========\n";
    s42.convert_R_state(grey);
    cout << "\n===========\n";

    return 0;
}

