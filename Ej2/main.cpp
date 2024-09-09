#include <iostream>
#include <random>

void initializeVector(float vec[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        vec[i] = 0.0;
    }
}

void fillVector(float vec[], int size)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(90.0, 250.0);

    for (int i = 0; i < size; ++i)
    {
        if (i != 25)
        {
            vec[i] = dis(gen);
        }
    }
}

void printVector(float vec[], int size, int columns)
{
    for (int i = 0; i < size; ++i)
    {
        std::cout << vec[i] << " ";
        if ((i + 1) % columns == 0)
            std::cout << '\n';
    }
}

void bubbleSort(float vec[], int size)
{
    for (int i = 0; i < size - 1; ++i)
    {
        for (int j = 0; j < size - i - 1; ++j)
        {
            if (vec[j] > vec[j + 1])
            {
                float temp = vec[j];
                vec[j] = vec[j + 1];
                vec[j + 1] = temp;
            }
        }
    }
}

int main()
{
    const int size = 50;
    float vec[size];

    initializeVector(vec, size);
    fillVector(vec, size);

    std::cout << "Vector inicial:\n";
    printVector(vec, size, 5);

    bubbleSort(vec, size);

    std::cout << "\nVector ordenado:\n";
    printVector(vec, size, 5);

    return 0;
}
