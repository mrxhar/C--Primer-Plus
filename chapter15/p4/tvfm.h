/*
@Author: mrxhar
@Date:   2023-08-23 20:41:05
@Email:  1337904145@qq.com
@Blog:
*/

#ifndef __TVFM__H__
#define __TVFM__H__

class Tv; // 让编译器先知道有一个 Tv 类

class Remote
{
private:
    int mode;

public:
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
    Remote(int m = TV) : mode(m){};
    bool volup(Tv &t);
    bool voldown(Tv &t);
    void onoff(Tv &t);
    void chanup(Tv &t);
    void chandown(Tv &t);
    void set_mode(Tv &t);
    void set_chan(Tv &t, int c); // 直接跳频道
    void set_input(Tv &t);
};

class Tv // 不在包含一个friend Remote 类 而是包含一个友元方法
{
private:
    int state;
    int volume;
    int maxchannel;
    int channel;
    int mode;
    int input;

public:
    friend void Remote::set_chan(Tv &t, int c); // 不是成员函数

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

inline bool Remote::volup(Tv &t) { return t.volup(); };
inline bool Remote::voldown(Tv &t) { return t.voldown(); };
inline void Remote::onoff(Tv &t) { t.onoff(); };
inline void Remote::chanup(Tv &t) { t.chanup(); };
inline void Remote::chandown(Tv &t) { t.chandown(); };
inline void Remote::set_mode(Tv &t) { t.set_mode(); };
inline void Remote::set_input(Tv &t) { t.set_input(); };
inline void Remote::set_chan(Tv &t, int c) { t.channel = c; };
#endif /*__TVFM__H__*/