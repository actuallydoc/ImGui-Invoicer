//
// Created by Maj on 2/24/2023.
//

#include "gui.h"
#include "imgui.h"
#include  <cstdlib>
#include <iostream>
#include "../utils/generators.h"
#include "../json/json_utils.h"
gui::gui() {
    json_utils* json = new json_utils();
    //Setup window
    running = true;
    show_demo_window = false;
    static ImGuiTableFlags flags = ImGuiTableFlags_SizingFixedFit | ImGuiTableFlags_RowBg | ImGuiTableFlags_Borders | ImGuiTableFlags_Resizable | ImGuiTableFlags_Reorderable | ImGuiTableFlags_Hideable;
    //Load json files and apply the invoices to the gui buffer
    //TODO load json files
    //TODO apply invoices to gui buffer

    for (int i = 0; i < 10; i++) {
        invoices.push_back(generate_invoice());
    }

    //Fetch existing partners and providers from json files
    providers.push_back(generators::generate_provider("Maj", "Kranjska cesta 1", "1000", "123456789", "123456789", "123456789", "123456789", "123456789"));
    providers.push_back(generators::generate_provider("test4", "Kranjska cesta 5", "4444", "12345112", "aodmaspd12312", "asdada", "1231asdas", "fasfafas"));
    providers.push_back(generators::generate_provider("test5", "Kranjska cesta 6", "5555", "12345112", "aodmaspd12312", "asdada", "1231asdas", "fasfafas"));
    providers.push_back(generators::generate_provider("test6", "Kranjska cesta 7", "6666", "12345112", "aodmaspd12312", "asdada", "1231asdas", "fasfafas"));
    providers.push_back(generators::generate_provider("test7", "Kranjska cesta 8", "7777", "12345112", "aodmaspd12312", "asdada", "1231asdas", "fasfafas"));

    strcpy_s(name, "Uporabnik");

}

gui::invoice gui::generate_invoice(){
    gui::invoice new_invoice;
    new_invoice.id = rand() % 10000;
    new_invoice.tax_active = true;
    strcpy_s(new_invoice.name, "Maj");
    strcpy_s(new_invoice.address, "Kranjska cesta 1");
    strcpy_s(new_invoice.city, "Ljubljana");
    strcpy_s(new_invoice.state, "Ljubljana");
    strcpy_s(new_invoice.zip, "1000");
    strcpy_s(new_invoice.phone, "031 123 456");
    strcpy_s(new_invoice.email, "asda@gmail.com");
    strcpy_s(new_invoice.date, "12.12.2021");
    strcpy_s(new_invoice.due_date, "12.12.2021");
    strcpy_s(new_invoice.service_date, "12.12.2021");
    strcpy_s(new_invoice.invoice_number, "123");
    strcpy_s(new_invoice.description, "Storitev");
    strcpy_s(new_invoice.quantity, "1");
    strcpy_s(new_invoice.price, "100");
    strcpy_s(new_invoice.total, "100");
    strcpy_s(new_invoice.partner.name, "Maj");
    strcpy_s(new_invoice.partner.address, "Kranjska cesta 1");
    strcpy_s(new_invoice.partner.postal_code, "1000");
    strcpy_s(new_invoice.partner.vat, "123456789");
    strcpy_s(new_invoice.provider.name, "Maj");
    strcpy_s(new_invoice.provider.address, "Kranjska cesta 1");
    strcpy_s(new_invoice.provider.postal_code, "1000");
    strcpy_s(new_invoice.provider.vat, "123456789");
    strcpy_s(new_invoice.provider.iban, "123456789");
    strcpy_s(new_invoice.provider.swift, "123456789");
    strcpy_s(new_invoice.provider.registration_number, "123456789");
    strcpy_s(new_invoice.provider.phone, "123456789");
    gui::service new_service;
    strcpy_s(new_service.description, "Storitev");
    strcpy_s(new_service.quantity, "1");
    strcpy_s(new_service.price, "100");
    strcpy_s(new_service.total, "100");

    new_invoice.services.push_back(new_service);
    return new_invoice;
}


void gui::render_table(){
    if (ImGui::BeginTable("table1", 9, flags))
    {
        ImGui::TableSetupColumn("St racuna", ImGuiTableColumnFlags_WidthFixed,0.0,Column_InvoiceNumber);
        ImGui::TableSetupColumn("Datum racuna", ImGuiTableColumnFlags_WidthFixed,0.0, Column_InvoiceDate);
        ImGui::TableSetupColumn("Datum storitve", ImGuiTableColumnFlags_WidthStretch,0.0, Column_ServiceDate);
        ImGui::TableSetupColumn("Partner", ImGuiTableColumnFlags_WidthStretch,0.0, Column_Partner);
        ImGui::TableSetupColumn("Izvajalec", ImGuiTableColumnFlags_WidthStretch,0.0, Column_Provider);
        ImGui::TableSetupColumn("STATUS", ImGuiTableColumnFlags_WidthStretch,0.0, Column_Status);
        ImGui::TableSetupColumn("Skupaj", ImGuiTableColumnFlags_WidthStretch,0.0, Column_Total);
        ImGui::TableSetupColumn("DDV%", ImGuiTableColumnFlags_WidthStretch,0.0, Column_Tax);
        ImGui::TableSetupColumn("Funkcije", ImGuiTableColumnFlags_WidthStretch, 0.0,TableColumns::Column_Action);

        ImGui::TableSetupScrollFreeze(0, 1); // Make row always visible
        ImGui::TableHeadersRow();
        for (int i = 0; i< invoices.size(); i++) {
            //Make so if you click on the row it will select the invoice
            ImGui::TableNextRow();
            ImGui::TableNextColumn();
            ImGui::Text("%s", invoices[i].invoice_number);
            ImGui::TableNextColumn();
            ImGui::Text("%s", invoices[i].date);
            ImGui::TableNextColumn();
            ImGui::Text("%s", invoices[i].service_date);
            ImGui::TableNextColumn();
            ImGui::Text("%s", invoices[i].partner.name);
            ImGui::TableNextColumn();
            ImGui::Text("%s", invoices[i].provider.name);
            ImGui::TableNextColumn();
            ImGui::Text("%s", "TODO");
            ImGui::TableNextColumn();
            ImGui::Text("%s", invoices[i].total);
            ImGui::TableNextColumn();
            ImGui::Text("%s", "22%");
            ImGui::TableNextColumn();
            ImGui::PushID(i);
            ImGui::PushStyleColor(ImGuiCol_Button, (ImVec4)ImColor::HSV(7.0f, 0.6f, 0.6f));
            ImGui::PushStyleColor(ImGuiCol_ButtonHovered, (ImVec4)ImColor::HSV(7.0f, 0.7f, 0.7f));
            ImGui::PushStyleColor(ImGuiCol_ButtonActive, (ImVec4)ImColor::HSV(7.0f, 0.8f, 0.8f));
            if(ImGui::Button("Edit")){
                std::cout << "Clicked on invoice: " << invoices[i].invoice_number << std::endl;
                this->current_invoice = &invoices[i];
                if (!edit_mode){
                    std::cout << "Edit mode enabled" << std::endl;
                    this->edit_mode = reinterpret_cast<bool *>(true);
                }

            };
            ImGui::PopStyleColor(3);
            ImGui::PopID();
        }
        ImGui::EndTable();
    }
}

void gui::edit_invoice() {
    ImGui::Begin("Edit invoice");
    ImGui::Text("Selected invoice: %s", this->current_invoice->invoice_number);
    if (ImGui::BeginTabBar("##Tabs", ImGuiTabBarFlags_None))
    {
        if (ImGui::BeginTabItem("Invoice"))
        {
            //Make the input less wide
            ImGui::PushItemWidth(70);
            ImGui::InputText("Invoice number", current_invoice->invoice_number, IM_ARRAYSIZE(current_invoice->invoice_number));
            ImGui::PopItemWidth();
            ImGui::Spacing();
            ImGui::Spacing();
            ImGui::PushItemWidth(100);
            ImGui::InputText("Name", current_invoice->name, IM_ARRAYSIZE(current_invoice->name));
            ImGui::InputText("Address", current_invoice->address, IM_ARRAYSIZE(current_invoice->address));
            ImGui::SameLine();
            ImGui::InputText("City", current_invoice->city, IM_ARRAYSIZE(current_invoice->city));
            ImGui::SameLine();
            ImGui::InputText("State", current_invoice->state, IM_ARRAYSIZE(current_invoice->state));
            ImGui::SameLine();
            ImGui::InputText("Zip", current_invoice->zip, IM_ARRAYSIZE(current_invoice->zip));
            ImGui::Spacing();
            ImGui::Spacing();
            ImGui::InputText("Phone", current_invoice->phone, IM_ARRAYSIZE(current_invoice->phone));
            ImGui::SameLine();
            ImGui::PopItemWidth();
            ImGui::PushItemWidth(160);
            ImGui::InputText("Email", current_invoice->email, IM_ARRAYSIZE(current_invoice->email));
            ImGui::Spacing();
            ImGui::Spacing();
            ImGui::InputText("Invoice Date", current_invoice->date, IM_ARRAYSIZE(current_invoice->date));
            ImGui::InputText("Due date", current_invoice->due_date, IM_ARRAYSIZE(current_invoice->due_date));
            ImGui::InputText("Service date", current_invoice->service_date, IM_ARRAYSIZE(current_invoice->service_date));
            ImGui::Spacing();
            ImGui::Spacing();
            ImGui::Checkbox("Activate Vat?", &current_invoice->tax_active);
            ImGui::PopItemWidth();
            ImGui::PushItemWidth(400);
            for(auto & service : current_invoice->services){
                ImGui::InputTextMultiline("Description", service.description, IM_ARRAYSIZE(service.description));
                ImGui::SameLine();
                ImGui::PushItemWidth(50);
                ImGui::SameLine(500);
                ImGui::InputText("Quantity", service.quantity, IM_ARRAYSIZE(service.quantity), ImGuiInputTextFlags_CharsDecimal);
                ImGui::SameLine();
                ImGui::InputText("Price", service.price, IM_ARRAYSIZE(service.price),ImGuiInputTextFlags_CharsDecimal );
                ImGui::SameLine();
                ImGui::InputText("Total", service.total, IM_ARRAYSIZE(service.total),ImGuiInputTextFlags_CharsDecimal );
                ImGui::SameLine();
                if(ImGui::Button("Delete")){
                    //!TODO delete service
                };
                ImGui::PopItemWidth();

            }
            if(ImGui::Button("Add service")){
                //!TODO add service
            }

            if (ImGui::Button("Save", ImVec2(-FLT_TRUE_MIN, 0.0f))) {
                //TODO save
                //Call a function to save the invoice to the json file
                this->current_invoice = nullptr;
                this->edit_mode = reinterpret_cast<bool *>(false);
            }
            if(ImGui::Button("Cancel", ImVec2(-FLT_TRUE_MIN, 0.0f))){
                this->current_invoice = nullptr;
                this->edit_mode = reinterpret_cast<bool *>(false);
            }
            ImGui::PushID(69);
            //Make the button red
            ImGui::PushStyleColor(ImGuiCol_Button, (ImVec4)ImColor::HSV(0.0f, 0.6f, 0.6f));
            ImGui::PushStyleColor(ImGuiCol_ButtonHovered, (ImVec4)ImColor::HSV(0.0f, 0.7f, 0.7f));
            ImGui::PushStyleColor(ImGuiCol_ButtonActive, (ImVec4)ImColor::HSV(0.0f, 0.8f, 0.8f));
            ImGui::Spacing();
            ImGui::Spacing();
            if(ImGui::Button("Delete", ImVec2(-FLT_TRUE_MIN, 0.0f))){
                for(int i = 0; i < invoices.size(); i++){
                    //!TODO Make sure that every invoice has a unique id or atleast it increments by the newest one
                    if(invoices[i].id == current_invoice->id){
                        invoices.erase(invoices.begin() + i);
                        std::cout << "Invoice with id" <<current_invoice->id  << std::endl;

                    }
                }
                this->current_invoice = nullptr;
                this->edit_mode = reinterpret_cast<bool *>(false);
                std::cout << "Edit mode to false" << std::endl;
            }
            ImGui::PopStyleColor(3);
            ImGui::PopID();
            ImGui::EndTabItem();
        }
        if (ImGui::BeginTabItem("Provider"))
        {
            ImGui::InputText("Name", current_invoice->provider.name, IM_ARRAYSIZE(current_invoice->provider.name));
            ImGui::InputText("Address", current_invoice->provider.address, IM_ARRAYSIZE(current_invoice->provider.address));
            ImGui::InputText("Postal", current_invoice->provider.postal_code, IM_ARRAYSIZE(current_invoice->provider.postal_code));
            ImGui::InputText("IBAN", current_invoice->provider.iban, IM_ARRAYSIZE(current_invoice->provider.iban));
            ImGui::InputText("Swift", current_invoice->provider.swift, IM_ARRAYSIZE(current_invoice->provider.swift));
            ImGui::InputText("Registration number", current_invoice->provider.registration_number, IM_ARRAYSIZE(current_invoice->provider.registration_number));
            ImGui::InputText("VAT ID", current_invoice->provider.vat, IM_ARRAYSIZE(current_invoice->provider.vat));
            ImGui::InputText("Phone", current_invoice->provider.phone, IM_ARRAYSIZE(current_invoice->provider.phone));

            static ImGuiComboFlags flags = ImGuiComboFlags_PopupAlignLeft;

            static int item_current_idx = 0; // Here we store our selection data as an index.
            for (int i = 0; i < 10; ++i) {
                ImGui::Spacing();
            }
            //!WARNING + BUG : The items have to have different names, otherwise the combo box will not work properly
            if (ImGui::BeginCombo("Existing Providers", providers[item_current_idx].name, flags))
            {
                //Todo is to change the provider info on the invoice to the selected provider
                for (int n = 0; n < providers.size(); n++)
                {
                    const bool is_selected = (item_current_idx == n);
                    if (ImGui::Selectable(providers[n].name, is_selected)){
                        strcpy_s(this->current_invoice->provider.name, providers[n].name);
                        strcpy_s(this->current_invoice->provider.address, providers[n].address);
                        strcpy_s(this->current_invoice->provider.postal_code, providers[n].postal_code);
                        strcpy_s(this->current_invoice->provider.iban, providers[n].iban);
                        strcpy_s(this->current_invoice->provider.swift, providers[n].swift);
                        strcpy_s(this->current_invoice->provider.registration_number, providers[n].registration_number);
                        strcpy_s(this->current_invoice->provider.vat, providers[n].vat);
                        strcpy_s(this->current_invoice->provider.phone, providers[n].phone);

                        item_current_idx = n;
                    }

                    // Set the initial focus when opening the combo (scrolling + keyboard navigation focus)
                    if (is_selected)
                        ImGui::SetItemDefaultFocus();
                }
                ImGui::EndCombo();
            }
            ImGui::EndTabItem();
        }
        if (ImGui::BeginTabItem("Partner"))
        {
            ImGui::InputText("Name", current_invoice->partner.name, IM_ARRAYSIZE(current_invoice->partner.name));
            ImGui::InputText("Address", current_invoice->partner.address, IM_ARRAYSIZE(current_invoice->partner.address));
            ImGui::InputText("Postal", current_invoice->partner.postal_code, IM_ARRAYSIZE(current_invoice->partner.postal_code));
            ImGui::InputText("VAT ID", current_invoice->partner.vat, IM_ARRAYSIZE(current_invoice->partner.vat));



            ImGui::EndTabItem();
        }
        ImGui::EndTabBar();
    }

    ImGui::End();
}

void gui::render_parent_header() {
    ImGui::BeginMenuBar();
    if (ImGui::BeginMenu("Racun")) {
        if (ImGui::MenuItem("Ustvari")) {
            //TODO save
        }
        if (ImGui::MenuItem("Nalozi")) {
            //TODO load
        }
        if (ImGui::MenuItem("Nastavitve")) {
            //TODO settings
        }
        ImGui::EndMenu();
    }
    ImGui::EndMenuBar();

}


void gui::show() {
    this->show_header();
    bool show_child_window = false;
    ImGui::Begin("Invoice manager!", reinterpret_cast<bool *>(this->running), ImGuiWindowFlags_MenuBar );
    render_parent_header();
    if(this->show_demo_window){
        ImGui::ShowDemoWindow(&this->show_demo_window);
    }
    this->render_table();
    if (edit_mode)
    {
        this->edit_invoice();
    }


    ImGui::End();

}

void gui::show_header(){
    ImGui::BeginMainMenuBar();
    if (ImGui::BeginMenu("File")) {
        if (ImGui::MenuItem("Save")) {
            //TODO save
        }
        if (ImGui::MenuItem("Load")) {
            //TODO load
        }
        if (ImGui::MenuItem("Settings")) {
            //TODO settings
        }
        ImGui::EndMenu();
    }
    if (ImGui::BeginMenu("Debug")) {
        if (ImGui::MenuItem("Show Demo")) {
            this->show_demo_window = !this->show_demo_window;
        }
        ImGui::EndMenu();
    }
    ImGui::EndMainMenuBar();
}
gui::~gui() {
    delete this;
}

void gui::stop() {
    this->running = false;
    this->~gui();

}
