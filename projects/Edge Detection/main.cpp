//
//  main.cpp
//  Homework7
//
//  Created by Danny Henderson on 2/23/16.
//  Copyright © 2016 Danny Henderson. All rights reserved.
//

#include <iostream>
#include "bmp.h”
//#include "SharedQ.h"

int main(int argc, const char * argv[])
{
    
    BMP *bm = new BMP(255, 255);
    /*for (int x = 0; x < 255; x++)
     {
     for (int y = 0; y < 255; y++)
     {
     bm->SetPixel(bm, x, y, 255 - y, 255, y, 255);
     }
     }
     std::cout << "Processing test.bmp\n";
     bm->Save(bm, "test.bmp");
     bm->~BMP();*/
    
    // Test #2: A 24-bit file with reversed height; add a 40x40 red square in the lower right corner
    
    std::cout << "Processing picture.bmp\n";
    
    bm->Load("picture.bmp");
    bm->Save(bm->DetectEdges(4), "picture gray.bmp");
    
    /*if (bm == 0)
     {
     std::cout << "Load of 'picture.bmp' failed\n";
     }
     else {
     for (int x = 0; x < 40; x++)
     {
     for (int y = 0; y < 40; y++)
     {
     bm->SetPixel(bm, bm->getWidth() - x - 1, y, 255, 0, 0, 255);
     }
     }
     bm->DetectEdges(4);
     bm->Save(bm, "picture new.bmp");
     bm->~BMP();
     }*/
    
    
    //Test #3: A 24-bit file; add a 40x40 blue square in the upper right corner
    
    std::cout << "Processing train.bmp\n";
    bm->Load("train.bmp");
    bm->Save(bm->DetectEdges(4), "train gray.bmp");
    /*if (bm == 0)
     {
     std::cout << "Load of 'train.bmp' failed\n";
     }
     else {
     for (int x = 0; x < 40; x++)
     {
     for (int y = 0; y < 40; y++)
     {
     bm->SetPixel(bm, bm->getWidth() - x - 1, bm->getHeight() - y - 1, 0, 0, 255, 255);
     }
     }
     bm->Save(bm, "train new.bmp");
     bm->~BMP();
     }*/
    
    // Test #4: A 24-bit file with padding; add a 40x40 blue square in the upper right corner
    
    std::cout << "Processing mountain.bmp\n";
    bm->Load("mountain.bmp");
    bm->Save(bm->DetectEdges(4), "mountain gray.bmp");
    /*if (bm == 0)
     {
     std::cout << "Load of 'mountain.bmp' failed\n";
     }
     else {
     // Convert to grayscale
     for (int x = 0; x < bm->getWidth(); x++)
     {
     for (int y = 0; y < bm->getHeight(); y++)
     {
     uint8_t r, g, b, a;
     bm->GetPixel(bm, x, y, r, g, b, a);
     uint8_t average = (r + g + b) / 3;
     bm->SetPixel(bm, x, y, average, average, average, a);
     }
     }
     bm->Save(bm, "mountain new.bmp");
     bm->~BMP();
     }*/
    
    //Test #4: A 32-bit file with reversed height; extract the green channel
    
    std::cout << "Processing canmore.bmp\n";
    bm->Load("canmore.bmp");
    bm->Save(bm->DetectEdges(4), "canmore gray.bmp");
    /*
     if (bm == 0)
     {
     std::cout << "Load of 'canmore.bmp' failed\n";
     }
     else {
     for (int x = 0; x < bm->getWidth(); x++)
     {
     for (int y = 0; y < bm->getHeight(); y++)
     {
     uint8_t r, g, b, a;
     bm->GetPixel(bm, x, y, r, g, b, a);
     bm->SetPixel(bm, x, y, 0, g, 0, a);
     
     }
     }
     //use this to now do edge detection
     for (int x = 0; x < bm->getWidth(); x++)
     {
     for (int y = 0; y < bm->getHeight(); y++)
     {
     uint8_t r, g, b, a;
     bm->GetPixel(bm, x, y, r, g, b, a);
     bm->SetPixel(bm, x, y, 0, g, 0, a);
     
     }
     }
     bm->Save(bm, "canmore new.bmp");
     bm->~BMP();
     }*/
    
    
    //return 0;
}

