//
// Created by ycx on 2021-06-28.
//

#ifndef DNA_ISING_MODEL_IMAGE_H
#define DNA_ISING_MODEL_IMAGE_H

#include "CImg.h"
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xos.h>
#include <vector>

#define image_height 400
#define image_weight 1024

#define width_of_DNA_sequence 20
#define grey_space 10

void generate_image(const std::vector<int>&);

#endif //DNA_ISING_MODEL_IMAGE_H
