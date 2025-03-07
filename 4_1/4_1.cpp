#include <fstream>
#include <iostream>
#include <string>

struct Contain
{
    std::string a{};
    std::string b{};
    std::string c{};
    std::string d{};
};

bool read(int& sum, Contain*& containArr)
{
    std::ifstream inputFile("in.txt");

    if (!inputFile)
    {
        return false;
    }

    inputFile >> sum;
    containArr = new Contain[sum];

    for (int index = 0; index < sum; ++index)
    {
        inputFile >> containArr[index].a;
        inputFile >> containArr[index].b;
        inputFile >> containArr[index].c;
        inputFile >> containArr[index].d;
    }

    inputFile.close();
    return true;
}

bool writeReverse(int& sum, Contain*& containArr)
{
    std::ofstream outputFile("out.txt");

    if (!outputFile)
    {
        return false;
    }

    outputFile << sum << std::endl;
    for (int index = 0; index < sum; ++index)
    {
        outputFile << containArr[sum - 1 - index].a << ", ";
        outputFile << containArr[sum - 1 - index].b << ", ";
        outputFile << containArr[sum - 1 - index].c << ", ";
        outputFile << containArr[sum - 1 - index].d;
        outputFile << std::endl;
    }

    outputFile.close();
    return true;
}

int main()
{
    int sum = 0;
    Contain* containArr = nullptr;

    if (!read(sum, containArr))
    {
        return 1;
    }

    if (!writeReverse(sum, containArr))
    {
        return 2;
    }

    delete[] containArr;
    return 0;
}