

class Cd
{
private:
    char performers[50];
    char label[20];
    int selections;  //  number of selections 选择的数目
    double playtime; //

public:
    Cd(const char *s1 = "None Performers", const char *s2 = "none label", int n = 0, double x = 0.0);
    Cd(const Cd &d);
    virtual void Report() const;
    Cd &operator=(const Cd &d);
};

class Classic : public Cd
{
private:
    char *works;

public:
    Classic(const char *w1, char *s1, char *s2, int n, double x);
    Classic(const char *w1 = "no work", const Cd &cd = Cd());
    Classic(const Classic &c);
    virtual void Report() const;
    Classic &operator=(const Classic &c);
    ~Classic();
};