#include "menu_item.h"
#include "main.h"

menu_item::menu_item(const std::string& msg, const std::string& pmt, std::function<void()>* cb) : prompt(pmt),
    message(msg), callback(cb) {

    submenu_items = new std::vector<menu_item>();

}

menu_item::menu_item(const std::string& msg, const std::string& pmt) {
    *this = menu_item(msg, pmt, nullptr);
}

menu_item::menu_item(const std::string& msg, std::function<void()>* cb) {
    *this = menu_item(msg, "", cb);
}

void menu_item::allocate(int items) {

    submenu_items->reserve((unsigned long)items);

}

void menu_item::setCallback(std::function<void()>* cb) { callback = cb; }
std::string menu_item::getMessage() const { return message; }

void menu_item::open() const {

    if (callback != nullptr) {
        (*callback)();
        return;
    }

    bool valid = false;
    int option = 0;
    while (!valid) {
        int count = 0;
        for (auto &item : *submenu_items) {

            print_sync(std::to_string(++count) + ". " + item.getMessage());

        }

        option = parse_int(get_input(prompt));

        if (option <= 0) {
            print_sync("Please enter a valid option!");
        } else {
            valid = true;
        }
    }

    (*submenu_items)[option - 1].open();

}

void menu_item::addSubItem(std::string msg, std::string pmt, std::function<void()>* cb) {
    submenu_items->emplace_back(msg, pmt, cb);
}

menu_item& menu_item::operator[](int index) {

    return (*submenu_items)[index];

}