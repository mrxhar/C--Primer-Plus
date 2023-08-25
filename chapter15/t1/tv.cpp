/*
@Author: mrxhar
@Date:   2023-08-23 20:10:40
@Email:  1337904145@qq.com
@Blog:
*/

#include <iostream>
#include "v1.h"

bool Tv::volup()
{
    if (volume < MaxVal)
    {
        volume++;
        return true;
    }
    else
    {
        return false;
    }
}

bool Tv::voldown()
{
    if (volume > MinVal)
    {
        volume--;
        return true;
    }
    else
    {
        return false;
    }
}

void Tv::chanup()
{
    if (channel < maxchannel)
    {
        channel++;
    }
    else
    {
        channel = 0;
    }
}

void Tv::chandown()
{
    if (channel > 1)
    {
        channel--;
    }
    else
    {
        channel = maxchannel; // 循环设置 channel
    }
}

void Tv::settings() const
{
    using std::cin;
    using std::cout;

    using std::endl;

    cout << "Tv is " << (state == Off ? "OFF" : "ON") << endl;

    if (state == On)
    {
        cout << "volume settings = " << volume << endl;
        cout << "Channel settings = " << channel << endl;
        cout << "Mode = " << (mode == Antenna ? "Antenna" : "Cable") << endl;
        cout << "Input = " << (input == TV ? "TV" : "DVD");
    }
}

void Tv::convert_R_state(Remote &r)
{
    if (ison())
    {
        r.convert();
    }
    r.show(*this);
}



void Remote::show(Tv &t) const
{
    using std::cin;
    using std::cout;

    using std::endl;
    cout << "Remote is " << (r_mode == general ? "general" : "interactions")
         << endl;
    if (r_mode == interactions)
    {
        cout << "interactions Tv settings: " << endl;
        t.settings();
    }
}
