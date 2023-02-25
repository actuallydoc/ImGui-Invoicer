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

    struct partner {
        char name[128];
        char address[128];
        char postal_code[128];
        char vat[128];
    };
    struct provider {
        char name[128];
        char address[128];
        char postal_code[128];
        char vat[128];
        char iban[128];
        char swift[128];
        char registration_number[128];
        char phone[128];
    };
    struct invoice {
        char name[128];
        char address[128];
        char city[128];
        char state[128];
        char zip[128];
        char phone[128];
        char email[128];
        char date[128];
        char service_date[128];
        char due_date[128];
        char invoice_number[128];
        char description[128];
        char quantity[128];
        char price[128];
        char total[128];
        partner partner;
        provider provider;
    };
    std::vector<invoice> invoices;
    //Existing Partners and Providers
    std::vector<partner> partners;
    std::vector<provider> providers;
    gui();
    ~gui();
    void stop();
    void show();
    void show_header();
    invoice generate_invoice();
    enum TableColumns {
        Column_InvoiceNumber,
        Column_InvoiceDate,
        Column_ServiceDate,
        Column_Partner,
        Column_Provider,
        Column_Status,
        Column_Total,
        Column_Tax,
        Column_Action
    };
private:
    bool running;
    ImGuiTableFlags flags;
    bool *edit_mode = false;
    char name [128];
    bool show_demo_window;
    invoice *current_invoice;
    void render_table();

    void render_parent_header();

    void edit_invoice();

};


#endif //IMGUI_CMAKE_STARTER_GUI_H
