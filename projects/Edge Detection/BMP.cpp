//function def

#include "BMP.h"




BMP::BMP()
{
    this->width = 0;
    this->height = 0;
    this->image = 0;
}

BMP::BMP(uint32_t width, uint32_t height)
{
    this->width = width;
    this->height = height;
    this->image = new uint8_t[width*height * 4];
}

BMP::~BMP()
{
    height = NULL;
    width = NULL;
    image = NULL;
    delete image;
    //image = NULL;
    //delete this;
}

BMP::BMP(const BMP &b) :
width(b.width), height(b.height), image(b.image)
{}

BMP& BMP::operator=(const BMP& b)
{
    width = b.width;
    height = b.height;
    image = b.image;
    return *this;
}

void BMP::SetPixel(BMP *bm, int x, int y, uint8_t redByte, uint8_t greenByte, uint8_t blueByte, uint8_t alphaByte)
{
    
    int index = (x + y * bm->width) * 4;
    bm->image[index] = blueByte;
    bm->image[index + 1] = greenByte;
    bm->image[index + 2] = redByte;
    bm->image[index + 3] = alphaByte;
    
}

void BMP::GetPixel(BMP *bm, int x, int y, uint8_t &redByte, uint8_t &greenByte, uint8_t &blueByte, uint8_t &alphaByte)
{
    int index = (x + y * bm->width) * 4;
    blueByte = bm->image[index];
    greenByte = bm->image[index + 1];
    redByte = bm->image[index + 2];
    alphaByte = bm->image[index + 3];
    
}

BMP* BMP::DetectEdges(int threadCount)
{
    BMP* newBMP = new BMP(); //create new image
    newBMP = this; //image is now equal to this make sure u may need to load image
    for(int y = 0; y < newBMP->height; y++)
    {
        for(int x = 0; x < newBMP->width; x++)
        {
            if(y == 0 || y == (newBMP->height - 1))
            {
                continue;
                //no y borders
            }
            if(x == 0 || x == (newBMP->width - 1))
            {
                continue;
                //no x borders
            }
            //cout << x << ", " << y << endl;
            
            uint8_t r, g, b, a; //create new rgb a dont matter
            this->GetPixel(newBMP, x, y, r, g, b, a); //get the pixels at x and y
            int grayStuff;
            grayStuff = newBMP->convolute(newBMP, x, y, r, g, b, a);
            SetPixel(newBMP, x, y, (255 - grayStuff), (255 - grayStuff), (255 - grayStuff), a);
        }
    }
    return newBMP;
    
}



int BMP::convolute(BMP *bm, int xVal, int yVal, uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    
    int matrix[3][3]; //this holds the values of the surround gray values of the pixel
    
    matrix[0][0] = 0;
    matrix[0][1] = 0;
    matrix[0][2] = 1;
    matrix[1][0] = 1;
    matrix[1][1] = 1;
    matrix[1][2] = 1;
    matrix[2][0] = 1;
    matrix[2][1] = 1;
    matrix[2][2] = 1;
    int Mx = 0;
    int My = 0;
    
    for(int y = yVal - 1; y < (yVal + 2); y++) //yval - 1 start in top left corner
    {
        My = My + 1;
        Mx = 0;
        for(int x = xVal; x < (xVal + 2); x++) //xval - 1
        {
            //get each pixel around the current pixel
            //and calculate the gray value
            int element;
            GetPixel(bm, x, y, r, g, b, a);
            element = getGray(r, g, b);
            matrix[Mx][My] = element;
            Mx = Mx + 1;
        }
    }
    int vX = getVx(matrix);
    int vY = getVy(matrix);
    //cout << vY << endl;
    int y = computeGrayPixel(vX, vY);
    //cout << vX << endl;
    return y;
    //now we have the matrix full of values, now we gotta scale em to get vX and vY
    
}



int BMP::getGray(uint8_t r, uint8_t g, uint8_t b)
{
    int grayValue;
    grayValue = (r+g+b)/3;
    return grayValue;
}

int BMP::getVx(int matrix[][3])
{
    int vMask[3][3];
    int VX = 0;
    vMask[0][0] = -1;
    vMask[0][1] = 0;
    vMask[0][2] = 1;
    vMask[1][0] = -2;
    vMask[1][1] = 0;
    vMask[1][2] = 2;
    vMask[2][0] = -1;
    vMask[2][1] = 0;
    vMask[2][2] = 1;
    /*
     * -1 0 1
     * -2 0 2
     * -1 0 1
     */
    
    int h = 2; //x
    int k = 2; //y
    for(int i = 0; i < 3; i++)
    {
        
        h = 2; //reset column
        for(int j = 0; j < 3; j++)
        {
            //cout << "i: " << i << " j: "<< j << " * " <<
            //"k: " << k << " h: "<< h << endl;
            VX += (matrix[i][j] * vMask[k][h]);
            h = h - 1;;
            
        }
        k = k - 1;
    }
    
    return VX;
}

int BMP::getVy(int matrix[][3])
{
    int VY = 0;
    int hMask[3][3];
    hMask[0][0] = -1;
    hMask[0][1] = -2;
    hMask[0][2] = -1;
    hMask[1][0] = 0;
    hMask[1][1] = 0;
    hMask[1][2] = 0;
    hMask[2][0] = 1;
    hMask[2][1] = 2;
    hMask[2][2] = 1;
    
    /*
     * -1 -2 -1
     *  0  0  0
     *  1  2  1
     */
    
    int h = 2; //x
    int k = 2; //y
    for(int i = 0; i < 3; i++)
    {
        //k = k-1;
        h = 2; //reset column
        for(int j = 0; j < 3; j++)
        {
            //cout << "i: " << i << " j: "<< j << " * " <<
            //"k: " << k << " h: "<< h << endl;
            VY += (matrix[i][j] * hMask[k][h]);
            h = h - 1;;
            
        }
        k = k-1;
    }
    
    return VY;
}

int BMP::computeGrayPixel(int vX, int vY)
{
    int x = vX*vX;
    int y = vY*vY;
    int value = (vX * vX) + (vY + vY);
    value = sqrt(value);
    //cout << value << endl;
    return value;
}



void BMP::Save(BMP *bm, const char *file)
{
    // 1. Open the file
    FILE* fileOne;
    fileOne = fopen(file, "w+");
    
    // 2. Create a header and write it to the file
    uint16_t isBM = 0x4D42; //4D42
    
    fwrite(&isBM, sizeof(uint16_t), 1, fileOne);
    BitMapHeaderTwo b = BitMapHeaderTwo();
    b.biWidth = bm->width;
    b.biHeight = bm->height;
    b.biSizeImage = (bm->width* bm->height) * 4;
    
    fwrite(&b, sizeof(BitMapHeaderTwo), 1, fileOne);
    
    
    // 3. Write the bitmap data to the file
    fwrite(bm->image, sizeof(uint8_t), (bm->width * bm->height) * 4, fileOne);
    
    
    
    
    // 4. Close the file
    fclose(fileOne);
}
BMP* BMP::Load(const char *file)
{
    BitMapHeaderTwo head;
    bool negativeHeight = false;
    
    // 1. Open the file
    FILE* fileOne;
    fileOne = fopen(file, "r+");
    if (!file)
    {
        cout << "File does not exist, quitting program" << endl;
        exit(0);
    }
    
    
    // 2a. Read the initial fields of the header; verify that the file type (BM) is correct.
    uint8_t isBM[2];
    //isBM[0] = ' ';
    //isBM[1] = ' ';
    fread(isBM, sizeof(uint8_t), 2, fileOne);
    if (isBM[0] != 0x42 || isBM[1] != 0x4D)
    {
        fclose(fileOne);
        cout << "File is not .bmp " << endl;
        exit(0);
    }
    
    
    
    // 2b. Read the rest of the header.
    
    fseek(fileOne, 2, SEEK_SET);
    fread(&head, sizeof(BitMapHeaderTwo), 1, fileOne);
    
    // 3. Verify if the file is 24 or 32 bits.
    if (head.biBitCount != 32 && head.biBitCount != 24)
    {
        fclose(fileOne);
        cout << "This program only takes 32 or 24 bit files" << endl;
        exit(0);
    }
    
    // 4. Check if the rows are stored in reverse order (due to negative height)
    
    if (head.biHeight < 0)
    {
        head.biHeight = head.biHeight * -1;
        negativeHeight = true;
    }
    
    // 5. Make sure the file isn't compressed (compression should be 0)
    if (head.biCompression != 0)
    {
        fclose(fileOne);
        exit(0);
    }
    
    //NEEDS FIXING
    //BMP* b = new BMP(head.biWidth, head.biHeight);
    this->setWidth(head.biWidth);
    this->setHeight(head.biHeight);
    this->setImage();
    
    
    // 6. Load the file if it is 32 bits
    // 6a. If the file is 32 bits, you can read one row at a time.
    // 6b. If the height is negative, you need to read from disk into the rows in memory in reverse order
    // 6c. 32-bit files are never padded.
    fseek(fileOne, head.bfOffBits, SEEK_SET);
    if (head.biBitCount == 32)
    {
        uint8_t pixel[4];
        
        if (!negativeHeight)
        {
            this->fileType = 1; //32 bit reg so we know file type for later
            
            for (int y = 0; y < head.biHeight; y++)
            {
                for (int x = 0; x < head.biWidth; x++)
                {
                    fread(pixel, 1, 4, fileOne);
                    SetPixel(this, x, y, pixel[2], pixel[1], pixel[0], pixel[3]);
                    cout << x << endl;
                    cout << y << endl;
                    
                }
            }
            cout << head.biHeight << endl;
            cout << head.biWidth << endl;
            
        }
        else
        {
            this->fileType = 0; //32 bit in reverse
            for (int y = head.biHeight - 1; y >= 0; y--)
            {
                for (int x = 0; x < head.biWidth; x++)
                {
                    fread(pixel, 1, 4, fileOne);
                    SetPixel(this, x, y, pixel[2], pixel[1], pixel[0], pixel[3]);
                }
            }
        }
    }
    
    
    // 7. Load the file if it is 24 bits
    // 7a. If the file is 24 bits, you need to read 3 bytes at a time and make space in memory for
    //     the extra byte. (Since your internal storage should always be 32 bits.)
    // 7b. If the height is negative, you need to read from disk into the rows in memory in reverse order
    // 7c. If the length of each line isn't divisible by 4, you need to read extra padding from the file.
    //     This padding shouldn't be stored in the bitmap data in memory.
    
    // 8. Close the file.
    // 9. Return a pointer to the bitmap.
    else if (head.biBitCount == 24)
    {
        uint8_t pixel[3];
        uint8_t pad[4];
        
        if (!negativeHeight)
        {
            for (int y = 0; y < head.biHeight; y++)
            {
                for (int x = 0; x < head.biWidth; x++)
                {
                    fread(pixel, 1, 3, fileOne);
                    SetPixel(this, x, y, pixel[2], pixel[1], pixel[0], 255);
                }
                fread(&pad, 1, (4 - (head.biWidth * 3) & 3) & 3, fileOne);
            }
        }
        else {
            for (int y = head.biHeight - 1; y >= 0; y--)
            {
                for (int x = 0; x < head.biWidth; x++)
                {
                    fread(pixel, 1, 3, fileOne);
                    SetPixel(this, x, y, pixel[2], pixel[1], pixel[0], 255);
                }
                fread(&pad, 1, (4 - (head.biWidth * 3) & 3) & 3, fileOne);
            }
        }
    }
    
    // 8. Close the file.
    fclose(fileOne);
    // 9. Return a pointer to the bitmap.
    return this;
    
}




