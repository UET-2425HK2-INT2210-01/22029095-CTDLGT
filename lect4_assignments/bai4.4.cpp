#include <iostream>
using namespace std;

struct Student {
    int id;
    string name, cls;
    Student* next;
};

Student* head = nullptr;

void addStudent(int id, string name, string cls) {
    head = new Student{id, name, cls, head};
}

void removeStudent(int id) {
    Student *cur = head, *prev = nullptr;
    while (cur && cur->id != id) {
        prev = cur;
        cur = cur->next;
    }
    if (cur) {
        if (prev) prev->next = cur->next;
        else head = cur->next;
        delete cur;
    }
}

void showInfo(int id) {
    for (Student* cur = head; cur; cur = cur->next) {
        if (cur->id == id) {
            cout << cur->name << "," << cur->cls << endl;
            return;
        }
    }
    cout << "NA,NA" << endl;
}

void handleCommand(string cmd) {
    if (cmd.find("Insert") == 0) {
        int id = stoi(cmd.substr(cmd.find('(') + 1));
        string name = cmd.substr(cmd.find(',') + 1, cmd.rfind(',') - cmd.find(',') - 1);
        string cls = cmd.substr(cmd.rfind(',') + 1, cmd.find(')') - cmd.rfind(',') - 1);
        addStudent(id, name, cls);
    } else if (cmd.find("Delete") == 0) {
        removeStudent(stoi(cmd.substr(7)));
    } else if (cmd.find("Infor") == 0) {
        showInfo(stoi(cmd.substr(6)));
    }
}

int main() {
    string cmd;
    while (getline(cin, cmd)) handleCommand(cmd);
    return 0;
}

