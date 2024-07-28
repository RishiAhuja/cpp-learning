#include "dog.h"

using namespace std;

Dog::Dog(const string &name_param, const string &breed_param, unsigned int age_param)
{
    m_name = name_param;
    m_breed = breed_param;
    m_age = age_param;
}

Dog::~Dog()
{
    cout << "Destructor called for: " << this->m_name << " at " << this << endl;
}