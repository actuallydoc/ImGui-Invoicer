//
// Created by Maj on 2/25/2023.
//

#ifndef IMGUI_CMAKE_STARTER_GENERATORS_H
#define IMGUI_CMAKE_STARTER_GENERATORS_H

#include "../gui/gui.h"
class generators {
public:
    generators();
    ~generators();
    static gui::invoice generate_invoice();
    static gui::partner generate_partner();
    static gui::provider generate_provider();
};


#endif //IMGUI_CMAKE_STARTER_GENERATORS_H
