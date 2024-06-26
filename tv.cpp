#include "Tv.h"

Serial::Serial() : name(" "), am(0), len(0.0), rating(0.0) {}

Serial::Serial(const Serial& s) : name(s.name), am(s.am), len(s.len), rating(s.rating) {}

Serial::Serial(string name, int am, float len, float rating) : name(name), am(am), len(len), rating(rating) {}

void Serial::print() const
{
	cout << name << ":  " << " amount of episodes = " << am << " lenght of episode = " << len << " rating " << rating << endl;
}

float Serial::lenght() const
{
	return am*len;
}

string Serial::get_name() const
{
	return name;
}

int Serial::get_am() const
{
	return am;
}

float Serial::get_lenght() const
{
	return len;
}

float Serial::get_rating() const
{
	return rating;
}

void Serial::add2rat(float n)
{
	rating += n;
}

void Serial::comp_l(Serial& s)
{
	if (len < s.len) cout << name << " is longer than " << s.name << endl;
	else if (len > s.len) cout << s.name << " is longer than " << name << endl;
	else cout  << name << " and " << s.name << "have the same lenght" << endl;
}

void Serial::enter()
{
	cout << "name: ";
	cin >> name;
	cout << " amount of episodes = ";
	cin >> am;
	cout << " lenght of episode = ";
	cin >> len;
	cout << " rating ";
	cin >> rating;
		cout << endl;
}

int Serial::get_s() const
{
	return 1;
}

void Serial::set_am(int n)
{
	am = n;
}

istream& operator>>(istream& is, Serial& s)
{
	is >> s.name >> s.am >> s.len >> s.rating;
	return is;
}

istream& operator>>(istream& is, Season& s)
{
	is >> s.name >> s.number >> s.am >> s.len >> s.rating;
	return is; 
}

Season::Season() : Serial(), number(0) {}

Season::Season(const Season& s) : Serial(s), number(s.number) {}

Season::Season(string name, int am, float lenght, float rating, int number) :
	Serial(name,  am,  lenght,  rating ), number(number) {}

void Season::change_am(int n)
{
	am = n;
}

void Season::print() const
{
	cout << name << " season " << number << " amount of episodes = " << am << " lenght of episode = " << len << " rating " << rating << endl;

}

float Season::get_rating() const
{
	return rating + (rating*0.1*number);
}

void Season::enter()
{

	cout << "name: ";
	cin >> name;
	cout << "season: ";
	cin >> number;
	cout << " amount of episodes = ";
	cin >> am;
	cout << " lenght of episode = ";
	cin >> len;
	cout << " rating ";
	cin >> rating;
	cout << endl;
}

int Season::get_s() const
{
	return number;
}
