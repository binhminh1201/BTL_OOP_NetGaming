#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <iomanip>
using namespace std;


class MayTinh {
public:
    string ma;    
    string ten;    
    double gia;    

    MayTinh();
    MayTinh(const string &ma_, const string &ten_, double gia_);

    virtual string toLine() const;          
    static MayTinh fromLine(const string &line);
    virtual void print() const;            
    virtual ~MayTinh();
};


class MayVip : public MayTinh {
public:
    string loaiVip; 

    MayVip();
    MayVip(const string &ma_, const string &ten_, double gia_, const string &loaiVip_);

    string toLine() const override;         
    static MayVip fromLine(const string &line);
    void print() const override;
};

