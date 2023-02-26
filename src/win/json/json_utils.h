//
// Created by Maj on 2/26/2023.
//

#ifndef IMGUI_CMAKE_STARTER_JSON_UTILS_H
#define IMGUI_CMAKE_STARTER_JSON_UTILS_H


#include "../gui/gui.h"
#include "vector"
#include "fstream"
#include "iostream"
#include "../../../nlohmann/json.hpp"

class json_utils {
public:
    const char* dir_path = "data";
    json_utils();
    ~json_utils();
    const char* invoice_path = "invoice.json";
    const char* partner_path = "partner.json";
    const char* provider_path = "provider.json";
    const char* service_path = "service.json";
    const char* last_invoice_path = "D:\\dev\\imGUI-Template-main\\data\\data.json";
    int invoice_count;
    int last_invoice_id;
    int partner_count;
    int provider_count;
    int service_count;

};


#endif //IMGUI_CMAKE_STARTER_JSON_UTILS_H
