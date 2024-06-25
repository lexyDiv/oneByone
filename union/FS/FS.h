#pragma once

#include "../Sound/Sound.cpp"

class FS
{
public:
    template <typename T>
    bool write(string path, T item);
   // rapid<T>

private:
};

template <typename T>
inline bool FS::write(string path, T item)
{
    bool isOk;
    ofstream fout;
    fout.open(path, ofstream::app);
    if (fout.is_open())
    {
        fout.write((char *)item, sizeof(T));
        isOk = true;
    }
    else
    {
        isOk = false;
    }
    fout.close();
    return isOk;
}

