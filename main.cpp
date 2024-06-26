#include <list>
#include <set>
#include  <vector>
#include "Tv.h"
 /*
    Serial s("housewives", 20, 30.5, 3.4);
    Serial s1("dream", 80, 20, 4.5);
    s.print();
    s.add2rat(3.0);
    s.print();
    cout << "full lenght in "<< s.get_name()<< " is " << s.lenght()<< endl;
    s1.print();
    cout << "full lenght in " << s1.get_name() << " is " << s1.lenght() << endl;
    s1.comp_l(s);

    Season a("friends", 35, 45.5, 4.8, 4);
    a.print();
    a.change_am(32);
    cout << "rating is " << a.get_rating() << endl;
    */

    /*
    3.  Введіть з клавіатури декілька телесеріалів (розмір задано цілим числом у хв.), помістіть їх у список
    , виведіть його на екран. Надрукуйте без повторень рейтинги,
    що є у списку. Знайдіть найбільший серіал, обчисліть загальну кількість серій у всіх серіалів. (7 балів)
    4.  За допомогою алгоритмів STL прочитайте з текстового файлу декілька серіалів та декілька кількасезонних серіалів
    (тривалість серії задано дійсним числом у год.), об’єднайте їх в одному контейнері, виведіть на екран.
    Визначте, скільки є серіалів, тривалість серії яких не перевищує години. Впорядкуйте серіали за спаданням рейтингу.
    Для кожного серіалу третього сезону додайте одну серію, надрукуйте отриману колекцію. (10 балів)
    */
set<float> rating;
int totals;
void add(list<Serial*> list, int a) {
    for (int i(0); i < a; i++) {
        cout << "1-serial, 2-season searial ";
        int b;
        cin >> b;
        switch (b) {
        case 1: {
            Serial* s = new Serial;
            s->enter();
            rating.insert(s->get_rating());
            totals += s->get_am();
            list.push_back(s);
            break;
        }case 2: {
            Season* s = new Season;
            s->enter();
            rating.insert(s->get_rating());
            totals += s->get_am();
            list.push_back(s);
            break;
        }
        }
    }
    for (const auto& i : list) {
        i->print();
    }
}
bool byR(const Serial* s, const Serial* s1) {
    return s->get_rating() > s1->get_rating(); // Sort by descending rating
}
bool durationLess(Serial* s) {
    return s->lenght() < 60;
}
void addEpisode(Serial* s) {
    if (s->get_s() == 3) {
        s->set_am(s->get_am() + 1);
    }
}
int main()
{
    list<Serial*> list;
    /*cout << "enter number ";
    int a;
    cin >> a;
    add(list, a);
    
    cout << "ratings are ";
    for (const auto& i : rating) {
        cout << i << " ";
    }
    cout << endl<<"total amount of episodes = " << totals<< endl;
   */ 
    ifstream file("file.txt");
    char x;
    while (file >> x) {
        switch(x) {
        case '1': {
            Serial* s = new Serial;
            file >> *s;
            list.push_back(s);
            break;
        }case '2': {
            Season* s = new Season;
            file >> *s;
            list.push_back(s);
            break;
        }
        }
    }
    file.close();
    for (const auto& i : list) {
        i->print();
    }
    
    int count = std::count_if(list.begin(), list.end(), durationLess);
    std::cout << "Number of serials with duration <= 1 hour: " << count << std::endl;
   
    // Sort the list by descending rating
    list.sort(byR);

    std::cout << "Sorted list by rating (descending): " << std::endl;
    for (const auto& i : list) {
        i->print();
    }
    for_each(list.begin(), list.end(), addEpisode);
    for (const auto& i : list) {
        i->print();
    }
    return 0;
}
