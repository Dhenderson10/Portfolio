#include <stdio.h>
#include <iostream>
#include <fstream>
#include <cstdio>
#include <vector>
#include <cstdint>
#include <math.h>
#include <thread>



using namespace std;

#ifndef BMP_H
#define BMP_H


struct BitMapHeaderTwo {
    BitMapHeaderTwo()
    :zero(0), bfOffBits(sizeof(BitMapHeaderTwo) + 2), biSize(40), biPlanes(1),
    biBitCount(32), biCompression(0), biSizeImage(0), biXPelsPerMeter(2835), biYPelsPerMeter(2835),
    biClrUsed(0), biClrImportant(0) {}
    
    uint32_t bfSize;
    uint32_t zero;
    uint32_t bfOffBits;
    
    uint32_t biSize;
    uint32_t biWidth;//set this
    int biHeight; // set this
    uint16_t biPlanes;
    uint16_t biBitCount;
    uint32_t biCompression;
    uint32_t biSizeImage;
    uint32_t biXPelsPerMeter;
    uint32_t biYPelsPerMeter;
    uint32_t biClrUsed;
    uint32_t biClrImportant;
};



class BMP
{
public:
    typedef BMP* BMPPointer;
    //default
    BMP();
    
    //constructor
    BMP(uint32_t width, uint32_t height);
    
    //destructor
    ~BMP();
    
    //copy constructor
    BMP(const BMP &);
    
    //Assignment Operator
    BMP &operator=(const BMP&);
    
    //we dont need this because of constructor
    //BMP *CreateBitMapPic(int width, int height);
    
    //we dont need this cause of destructor
    //void Free(BMPPointer &bm);
    
    BMP *Load(const char *file);
    
    void Save(BMP *bm, const char *file);
    
    void GetPixel(BMP *bm, int x, int y, uint8_t &redByte, uint8_t &greenByte, uint8_t &blueByte, uint8_t &alphaByte);
    
    void SetPixel(BMP *bm, int x, int y, uint8_t redByte, uint8_t greenByte, uint8_t blueByte, uint8_t alphaByte);
    
    BMP* DetectEdges(int threadCount);
    
    bool onBoundry(uint8_t pixel);
    
    int getGray(uint8_t r, uint8_t g, uint8_t b);
    
    int convolute(BMP *bm, int x, int y, uint8_t r, uint8_t g, uint8_t b, uint8_t a);
    
    int getVx(int matrix[][3]);
    
    int getVy(int matrix[][3]);
    
    int computeGrayPixel(int vX, int vY);
    
    BMP* threadsGOGO(BMP* destImage, int x, int y, int xLimit, int yLimit);
    
    
    uint32_t getWidth()
    {
        return width;
    }
    
    uint32_t getHeight()
    {
        return height;
    }
    
    void setWidth(uint32_t input)
    {
        this->width = input;
    }
    
    void setHeight(uint32_t input)
    {
        this->height = input;
    }
    
    void setImage()
    {
        this->image = new uint8_t[width*height * 4];
    }
    
    void setImageNull()
    {
        this->image = new uint8_t[NULL];
    }
    
    
    
    
    
    
    
    
    
private:
    uint32_t width, height;
    uint8_t *image;
    int fileType;
    //0 = 32 bit
    //1 = 32 bit in reverse
    //2 = 24 bit
    //3 = 24 bit in reverse
    
    
    
};

#endif

