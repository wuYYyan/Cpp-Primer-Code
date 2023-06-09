#ifndef __MESSAGE_H__
#define __MESSAGE_H__

#include <string>
#include <set>
#include <algorithm>

using namespace std;

class Folder; //前置声明

class Message
{
    friend class Folder; //友元类声明
    friend void swap(Message &lhs, Message &rhs);
    public:
        explicit Message(const string &str = string()) : contents(str) { }
        Message(const Message &);
        Message &operator=(const Message &);
        ~Message();

        void save(Folder &);
        void remove(Folder &);
        void addFldr(Folder *f) { folders.insert(f); }
        void remFldr(Folder *f) { folders.erase(f); }
    private:
        string contents;
        set<Folder *> folders;
        void add_to_Folders(const Message &);
        void remove_from_Folders();
};

#endif