#include <iostream>
#include <fstream>
#include <sys/resource.h>
//#include <random>
#include "./sfmlFuncs.h"
#include "./functions.h"


int main() {
    int trainImages[60000][1 + 28 * 28];
    int testImages[10000][1 + 28 * 28];

    std::ifstream newImages;
    std::ifstream newLabels;
    newImages.open("../data/ImagesMnist.bytes", std::ios::in | std::ios::binary);
    newLabels.open("../data/LabelsMnist.bytes", std::ios::in | std::ios::binary);

    int in;
    int te = 28*28;
    for (auto & trainImage : trainImages) {
        newLabels.read((char *) & in, 1);
        trainImage[0] = in;
        for (int j = 0; j < te; j++) {
            newImages.read((char *) & in, 1);
            trainImage[j + 1] = in;
        }
    }
    for (auto & testImage : testImages) {
        newLabels.read((char *) & in, 1);
        testImage[0] = in;
        for (int j = 0; j < te; j++) {
            newImages.read((char *) & in, 1);
            testImage[j + 1] = in;
        }
    }




    // format is label + pix1 + pix2 + ... + pixn
}
