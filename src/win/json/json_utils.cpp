//
// Created by Maj on 2/26/2023.
//

#include "json_utils.h"
#include "../../../nlohmann/json.hpp"
#include "../gui/gui.h"
#include <fstream>
#include <iostream>

json_utils::json_utils() {
    //Load all data from json files
    std::ifstream file;
    file.open("data.json", std::ios::in);
    //Get path to data.json
    if (file.peek() == std::ifstream::traits_type::eof()) {
        std::cout << "data.json is empty" << std::endl;
        file.close();
        std::ofstream file;
        file.open("data.json", std::ios::out);
        nlohmann::json invoice;
        invoice["invoiceNumber"] = 0;
        invoice["invoiceId"] = 0;
        file << invoice;
        file.close();
        std::cout << "Created data.json" << std::endl;
    }else {
        if (file.is_open()) {
            nlohmann::json data;
            file >> data;
            invoice_count = data["invoice_count"];
            last_invoice_id = data["last_invoice_id"];
            partner_count = data["partner_count"];
            provider_count = data["provider_count"];
            service_count = data["service_count"];
            file.close();
        }
    }

    std::cout << "Loaded data from data.json" << std::endl;
    //Load invoices
    //Load partners
    //Load providers
    //Load services

}

json_utils::~json_utils() {
    //Save all data to json files
    delete this;
}

