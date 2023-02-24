//
// Created by Maj on 2/24/2023.
//

#ifndef IMGUI_CMAKE_STARTER_GUI_H
#define IMGUI_CMAKE_STARTER_GUI_H

#include <vector>
#include "string"
#include "imgui.h"

class gui {
public:
    struct invoice {
        char name[128];
        char address[128];
        char city[128];
        char state[128];
        char zip[128];
        char phone[128];
        char email[128];
        char date[128];
        char due_date[128];
        char invoice_number[128];
        char description[128];
        char quantity[128];
        char price[128];
        char total[128];
    };
    std::vector<invoice> invoices;
    gui();
    ~gui();
    void stop();
    void show();
    void show_header();
    invoice generate_invoice();
private:
    bool running;
    ImGuiTableFlags flags;
    char name [128];
    bool show_demo_window;

    void render_table();

    void render_parent_header();
};


#endif //IMGUI_CMAKE_STARTER_GUI_H
