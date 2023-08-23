/*
@Author: mrxhar
@Date:   2023-08-23 19:54:51
@Email:  1337904145@qq.com
@Blog:
*/

#ifndef __TV__H__
#define __TV__H__

class Tv
{
private:
    int state;
    int volume;
    int maxchannel;
    int channel;
    int mode;
    int input;

public:
    friend class Remote;
    enum
    {
        Off,
        On
    };
    enum
    {
        MinVal,
        MaxVal = 20
    };
    enum
    {
        Antenna,
        Cable
    };
    enum
    {
        TV,
        DVD
    };
    Tv(int s = Off, int mc = 125) : state(s), volume(5), maxchannel(mc), channel(2), mode(Cable), input(TV){};
    void onoff() { state = (state == On) ? Off : On; };
    bool ison() const { return state == On; };
    bool volup();
    bool voldown();
    void chanup();
    void chandown();
    void set_mode() { mode = (mode == Cable) ? Antenna : Cable; };
    void set_input() { input = (input == TV) ? DVD : TV; };
    void settings() const;
};

class Remote
{
private:
    int mode;

public:
    Remote(int m = Tv::TV) : mode(m){};
    bool volup(Tv &t) { return t.volup(); };
    bool voldown(Tv &t) { return t.voldown(); };
    void onoff(Tv &t) { t.onoff(); };
    void chanup(Tv &t) { t.chanup(); };
    void chandown(Tv &t) { t.chandown(); };
    void set_mode(Tv &t) { t.set_mode(); };
    void set_chan(Tv &t, int c) { t.channel = c; }; // 直接跳频道
    void set_input(Tv &t) { t.set_input(); };
};

#endif /*__TV__H__*/