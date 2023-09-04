#include <iostream>
#include <cstdint>

struct Data
{
    std::string name;
    int age;
};

uintptr_t serialize(Data* ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data*>(raw);
}

int main(void) 
{
    Data *data = new Data();
    uintptr_t address;
    data->name = "Zehra";
    data->age = 25;

    address = serialize(data);
    std::cout << "Name: " << deserialize(address)->name << std::endl;
    std::cout << "Age:  " << deserialize(address)->age << std::endl;

    delete data;
    return 0;
}
