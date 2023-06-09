#ifndef __FOLDER_H__
#define __FOLDER_H__

#include <string>
#include <set>

using namespace std;

class Folder
{
    friend class Message;
    public:
        Folder() {}
        Folder(const Folder &f);
        Folder &operator=(const Folder &);
        ~Folder();

        void addMsg(Message *msg) { msgs.insert(msg); }
        void remMsg(Message *msg) { msgs.erase(msg); }
        void add_to_Messages(const Folder &f);
        void remove_from_Msgs();
    private:
        set<Message *> msgs;

        

};

#endif 