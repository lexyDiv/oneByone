#pragma once

#include "../Sound/Sound.cpp"

class FS
{
public:
    template <typename T>
    bool write(string path, T item);
    template <typename T>
    rapid<T> read(string path);

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
        console.log("write");
    }
    else
    {
        isOk = false;
    }
    fout.close();
    return isOk;
}

template <typename T>
inline rapid<T> FS::read(string path)
{
    rapid<T> arr;
    ifstream fin;
    fin.open(path);
    if (fin.is_open())
    {
        T item;
        while (fin.read((char *)&item, sizeof(T)))
        {
            arr.backForce(1);
            arr.push(item);
            arr.norm();
        }
    }
    fin.close();
    return arr;
}
