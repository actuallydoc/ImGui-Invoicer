//
// Created by Maj on 2/25/2023.
//

#include "generators.h"
#include "../gui/gui.h"
gui::partner generators::generate_partner() {
    gui::partner partner;
    strcpy_s(partner.name, "Partner 1");
    strcpy_s(partner.address, "asdad");
    strcpy_s(partner.postal_code, "asdad");
    strcpy_s(partner.vat, "asdad");

    return partner;
}

gui::invoice generators::generate_invoice() {
    gui::invoice invoice;
    strcpy_s(invoice.name, "Invoice 1");
    strcpy_s(invoice.address, "asdad");
    strcpy_s(invoice.city, "asdad");
    strcpy_s(invoice.state, "asdad");
    strcpy_s(invoice.zip, "asdad");
    strcpy_s(invoice.phone, "asdad");
    strcpy_s(invoice.email, "asdad");
    strcpy_s(invoice.date, "asdad");
    strcpy_s(invoice.service_date, "asdad");
    strcpy_s(invoice.due_date, "asdad");
    strcpy_s(invoice.invoice_number, "asdad");
    strcpy_s(invoice.description, "asdad");
    strcpy_s(invoice.quantity, "asdad");
    strcpy_s(invoice.price, "asdad");
    strcpy_s(invoice.total, "asdad");
    return invoice;
}

gui::provider generators::generate_provider() {
    gui::provider provider;
    strcpy_s(provider.name, "Provider 1");
    strcpy_s(provider.address, "asdad");
    strcpy_s(provider.postal_code, "asdad");
    strcpy_s(provider.vat, "asdad");
    strcpy_s(provider.iban, "asdad");
    strcpy_s(provider.swift, "asdad");
    strcpy_s(provider.registration_number, "asdad");
    strcpy_s(provider.phone, "asdad");
    return provider;

}

generators::~generators() {

}

generators::generators() {

}
