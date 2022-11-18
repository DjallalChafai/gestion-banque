#include <iostream>
#include <string>
#include <utility>
#include <vector>

#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/serialization/vector.hpp>

using namespace std;
    


struct Client
{
    Client();
    Client(const int &number, string &&name,
    vector<int> &&account_numbers);

    int number_ = 0;
    string name_;
    vector<int> account_numbers_;
    friend std::ostream &operator<<(std::ostream &os, const Client &client);
    template <class Archive>
    void serialize(Archive &ar, unsigned int version)
    {
        ar & name_ & number_ & account_numbers_;
    }
};
