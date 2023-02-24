//
// Created by Maj on 2/24/2023.
//

#include "gui.h"
#include "imgui.h"
#include  <cstdlib>
gui::gui() {
    running = true;
    show_demo_window = false;
    static ImGuiTableFlags flags = ImGuiTableFlags_SizingFixedFit | ImGuiTableFlags_RowBg | ImGuiTableFlags_Borders | ImGuiTableFlags_Resizable | ImGuiTableFlags_Reorderable | ImGuiTableFlags_Hideable;
    //Load json files and apply the invoices to the gui buffer
    //TODO load json files
    //TODO apply invoices to gui buffer
    for (int i = 0; i < 10; i++) {
        invoices.push_back(generate_invoice());
    }

    strcpy_s(name, "Custom name");

}

gui::invoice gui::generate_invoice(){
    gui::invoice new_invoice;
    strcpy_s(new_invoice.name, "Maj");
    strcpy_s(new_invoice.address, "Kranjska cesta 1");
    strcpy_s(new_invoice.city, "Ljubljana");
    strcpy_s(new_invoice.state, "Ljubljana");
    strcpy_s(new_invoice.zip, "1000");
    strcpy_s(new_invoice.phone, "031 123 456");
    strcpy_s(new_invoice.email, "asda@gmail.com");
    strcpy_s(new_invoice.date, "12.12.2021");
    strcpy_s(new_invoice.due_date, "12.12.2021");
    strcpy_s(new_invoice.invoice_number, "123");
    strcpy_s(new_invoice.description, "Storitev");
    strcpy_s(new_invoice.quantity, "1");
    strcpy_s(new_invoice.price, "100");
    strcpy_s(new_invoice.total, "100");
    return new_invoice;
}

void gui::render_table(){
    if (ImGui::BeginTable("table1", 9, flags))
    {
        ImGui::TableSetupColumn("St racuna", ImGuiTableColumnFlags_WidthFixed);
        ImGui::TableSetupColumn("Datum racuna", ImGuiTableColumnFlags_WidthFixed);
        ImGui::TableSetupColumn("Datum storitve", ImGuiTableColumnFlags_WidthStretch);
        ImGui::TableSetupColumn("Partner", ImGuiTableColumnFlags_WidthStretch);
        ImGui::TableSetupColumn("Izvajalec", ImGuiTableColumnFlags_WidthStretch);
        ImGui::TableSetupColumn("STATUS", ImGuiTableColumnFlags_WidthStretch);
        ImGui::TableSetupColumn("Skupaj", ImGuiTableColumnFlags_WidthStretch);
        ImGui::TableSetupColumn("DDV%", ImGuiTableColumnFlags_WidthStretch);
        ImGui::TableSetupColumn("Funkcije", ImGuiTableColumnFlags_WidthStretch);

        ImGui::TableSetupScrollFreeze(0, 1); // Make row always visible
        ImGui::TableHeadersRow();
        for (int i = 0; i< invoices.size(); i++) {
            ImGui::TableNextRow();
            ImGui::TableNextColumn();
            ImGui::Text("%s", invoices[i].invoice_number);
            ImGui::TableNextColumn();
            ImGui::Text("%s", invoices[i].date);
            ImGui::TableNextColumn();
            ImGui::Text("%s", invoices[i].due_date);
            ImGui::TableNextColumn();
            ImGui::Text("%s", invoices[i].name);
            ImGui::TableNextColumn();
            ImGui::Text("%s",name);
            ImGui::TableNextColumn();
            ImGui::Text("%s", "TODO");
            ImGui::TableNextColumn();
            ImGui::Text("%s", invoices[i].total);
            ImGui::TableNextColumn();
            ImGui::Text("%s", "22%");
            ImGui::TableNextColumn();
            ImGui::Button("Edit", ImVec2(-FLT_MIN, 0.0f));
        }
        ImGui::EndTable();
    }
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
    ImGui::Begin("Hello, world!", nullptr, ImGuiWindowFlags_MenuBar);
    ImGui::SetWindowSize(ImVec2(1280, 720));
    ImGui::Text("This is some useful text.");
    render_parent_header();
    if(this->show_demo_window){
        ImGui::ShowDemoWindow(&this->show_demo_window);
    }
    this->render_table();
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
