#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <istream>
#include <algorithm>
using namespace std;

class Serial {
protected:
	string name;
	int am;
	float len;
	float rating;
public:
	Serial();
	Serial(const Serial& s);
	Serial(string name, int am, float leng, float rating);
	virtual void print() const;
	float lenght() const;
	string get_name() const;
	int get_am() const;
	float get_lenght() const;
	virtual float get_rating() const;
	void add2rat(float n);
	void comp_l(Serial& s);
	friend istream& operator>>(istream& is, Serial& s);
	virtual void enter();
	virtual int get_s() const;
	void set_am(int n);
};

class Season : public Serial {
private:
	int number;
public:
	Season();
	Season(const Season& s);
	Season(string name, int am, float lenght, float rating, int number);
	void change_am(int n);
	void print() const override;
	float get_rating() const override;
	friend istream& operator>>(istream& is, Season& s);
	void enter() override;
	int get_s() const override;
};