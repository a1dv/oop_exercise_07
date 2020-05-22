#include <iostream>
#include "factory.h"
#include "editor.h"

void create(editor& edit) {
    std::string tmp;
    std::cout << "Enter name of new document\n";
    std::cin >> tmp;
    edit.CreateDocument(tmp);
    std::cout << "Document create\n";
}

void load(editor& edit) {
    std::string tmp;
    std::cout << "Enter path to the file\n";
    std::cin >> tmp;
    try {
        edit.LoadDocument(tmp);
        std::cout << "Document loaded\n";

    } catch (std::runtime_error& e) {
        std::cout << e.what();
    }
}

void save(editor& edit) {
    std::string tmp;
    try {
        edit.SaveDocument();
        std::cout << "save document\n";
    } catch (std::runtime_error& e) {
        std::cout << e.what();
    }
}

void add(editor& edit) {
    factory fac;
    try {
        std::shared_ptr<figure> newElem = fac.fig(std::cin);
        edit.InsertInDocument(newElem);
    } catch (std::logic_error& e) {
        std::cout << e.what() << '\n';
    }
    std::cout << "Ok\n";
}

void remove(editor& edit) {
    uint32_t index;
    std::cout << "Enter index\n";
    std::cin >> index;
    try {
        edit.DeleteInDocument(index);
        std::cout << "Ok\n";
    } catch (std::logic_error& err) {
        std::cout << err.what() << "\n";
    }
}

int main() {
    editor edit;
    char action;
    while (true) {
        std::cout << "Enter letter:\n"
                     "a)create\n"
                     "b)load\n"
                     "c)save\n"
                     "d)add\n"
                     "e)remove\n"
                     "f)print\n"
                     "g)undo\n"
                     "h)exit\n";
        std::cin >> action;
        if (action == 'a') {
            std::string tmp;
            std::cout << "Enter name of new document\n";
            std::cin >> tmp;
            edit.CreateDocument(tmp);
            std::cout << "Document created\n";
        } else if (action == 'b') {
            std::string tmp;
            std::cout << "Enter path to the file\n";
            std::cin >> tmp;
            try {
                edit.LoadDocument(tmp);
                std::cout << "Document loaded\n";

            } catch (std::runtime_error& e) {
                std::cout << e.what();
            }
        } else if (action == 'c') {
            std::string tmp;
            try {
                edit.SaveDocument();
                std::cout << "Document saved\n";
            } catch (std::runtime_error& e) {
                std::cout << e.what();
            }
        } else if (action == 'd') {
            factory fac;
            try {
                std::shared_ptr<figure> newElem = fac.fig(std::cin);
                edit.InsertInDocument(newElem);
            } catch (std::logic_error& e) {
                std::cout << e.what() << '\n';
            }
            std::cout << "Ok\n";
        } else if (action == 'e') {
            uint32_t index;
            std::cout << "Enter index\n";
            std::cin >> index;
            try {
                edit.DeleteInDocument(index);
                std::cout << "Ok\n";
            } catch (std::logic_error& err) {
                std::cout << err.what() << "\n";
            }
        } else if (action == 'f') {
            edit.PrintDocument();
        } else if (action == 'g') {
            try {
                edit.Undo();
            } catch (std::logic_error& e) {
                std::cout << e.what();
            }
        }  else if (action == 'h') {
                break;
        }
         else {
            std::cout << "Unknown command\n";
        }
    }
    return 0;
}
