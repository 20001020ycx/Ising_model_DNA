//
// Created by ycx on 2021-06-28.
//

#include "image.h"

using namespace cimg_library;

/* Currently, I can't configure the Cmake to link lX11 lib;
 * therefore, the compilation requires the following command:
 * g++ -c *.cpp
 * g++ *.o -o DNA_sequence -pthread -lX11
 * */
void generate_image(const std::vector<int>& DNA_sequence){
    CImg<unsigned char> DNA_sequence_image(image_weight,image_height,1,3);         // Define a 640x400 color image with 8 bits per color component.

    unsigned char white[3] = {0,0,0};
    unsigned char black[3] = {255,255,255};
    unsigned char grey[3] = {112,128,144};

    int DNA_spin_count = 0;
    int column_record = 0;
    for (int i = 0; i < DNA_sequence.size(); i ++){
        if (i > image_weight) {
            i = 0;
            column_record += width_of_DNA_sequence;
            for (int j = column_record; j < grey_space + column_record; j ++) DNA_sequence_image.draw_point(i,j,grey);
            column_record += grey_space;
        }
        if (DNA_sequence[DNA_spin_count] == 0){
            for (int j = column_record; j < width_of_DNA_sequence + column_record; j++) DNA_sequence_image.draw_point(i,j,white);
        }else if (DNA_sequence[DNA_spin_count] == 1){
            for (int j = column_record; j < width_of_DNA_sequence + column_record; j++) DNA_sequence_image.draw_point(i,j,black);
        }else {
            //DNA_sequence_image.draw_point(i,j,grey);
        }
        DNA_spin_count++;
        if (DNA_spin_count == DNA_sequence.size()) {
            //grey out the remaining row pixel
            for (; i < image_weight; i ++){
                for (int j = 0; j < width_of_DNA_sequence + column_record + grey_space; j++){
                    DNA_sequence_image.draw_point(i,j,grey);
                }
            }

            //grey out all remaining pixels
            for (int m = 0; m < image_weight; m++){
                // no grey space is needed
                for (int n = width_of_DNA_sequence + column_record; n < image_height; n ++){
                    DNA_sequence_image.draw_point(m,n,grey);
                }
            }
            break;
        }
    }

    DNA_sequence_image.display("Window Title");
}