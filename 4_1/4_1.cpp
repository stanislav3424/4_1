#include <fstream>
#include <iostream>
#include <string>

class Contain
{
  public:
    std::string city{};
    std::string street{};
    std::string house{};
    std::string apartment{};
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

    for (int index{}; index < sum; ++index)
    {
        inputFile >> containArr[index].city;
        inputFile >> containArr[index].street;
        inputFile >> containArr[index].house;
        inputFile >> containArr[index].apartment;
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
    for (int index{}; index < sum; ++index)
    {
        outputFile << containArr[sum - 1 - index].city << ", ";
        outputFile << containArr[sum - 1 - index].street << ", ";
        outputFile << containArr[sum - 1 - index].house << ", ";
        outputFile << containArr[sum - 1 - index].apartment;
        outputFile << std::endl;
    }

    outputFile.close();
    return true;
}

int main()
{
    int sum{};
    Contain* containArr = nullptr;

    if (!read(sum, containArr))
    {
        return 1;
    }

    if (!writeReverse(sum, containArr))
    {
        return 2;
        delete[] containArr;
    }

    delete[] containArr;
    return 0;
}