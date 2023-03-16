#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cstdio>
#include <boost/lexical_cast.hpp>
using namespace std;
using namespace boost;

struct Journal
{
    string title;
    vector<string> entries;

    explicit Journal(const string& title):title(title){} //Constructor

    void add_entry(const string& entry);
    

    void save(const string& filename);
};

void Journal::add_entry(const string& entry)
{
    static int count = 1;
    entries.push_back(lexical_cast<string>(count++) + ": " + entry);
}

/*
Problem is below here, 
For each object writing same function is problematic as it is repitition
*/
void Journal::save(const string& filename)
{
    ofstream ofs(filename);
    for (auto& s : entries)
        ofs << s << endl;
}
//Avoid writing this above function

struct PersistenceManager
{
static void save(const Journal& j, const string& filename)
  {
    ofstream ofs(filename);
    for (auto& s : j.entries)
      ofs << s << endl;
  }
};

int main(int, char**) {
    std::cout << "Hello, world!\n"<<endl;
    Journal journal("Dear Diary");
    journal.add_entry("I ate a Watermelon and Mango");
    journal.add_entry("I had a fantastic day today");

    //journal.save("diary.txt");

    PersistenceManager pm;
    pm.save(journal, "./diary.txt");
}
