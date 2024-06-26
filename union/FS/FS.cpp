#include "FS.h"

FS fs;


template<typename T>
void write(string path, T item, size_t size)
{
                            ofstream fout;
    fout.open(path, ofstream::app);
    if (fout.is_open())
    {
        fout.write((char *)item, size);
        console.log("write");
    }
    else
    {
        console.log("fuck u");
    }
    fout.close();
}