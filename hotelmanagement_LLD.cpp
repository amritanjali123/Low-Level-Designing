#include <bits/stdc++.h>
using namespace std;
#define pb push_back

enum parameter { cost, rating };
class Address {
public:
    string place;
    int pinecode;
};
class HotelData {
public:
    string name;
    Address address;
    int rating;
    int cost;
};
class userdata {
public:
    string name;
    string email;
    Address address;
};
map<int, HotelData> HotelList;
map<int, set<int>> hotelList;
map<string, userdata> userList;
class Hotel {
private:
    HotelData hotel;
public:
    int key = rand();
    Hotel(string name, Address add, int rating, int cost) {
        hotel = {name, add, rating, cost};
        HotelList[key] = hotel;
        hotelList[add.pinecode].insert(key);
    }

public:

    void deletHotel()
    {
        HotelData hot = HotelList[key];
        set<int> v = hotelList[hot.address.pinecode];
        auto it = v.find(key);
        v.erase(it);
        hotelList[hot.address.pinecode] = v;
    }
    void UpdateHotelData(int z, string name, Address add, int rating, int cost)
    {
        deletHotel();
        hotel = {name, add, rating, cost};
        HotelList[key] = hotel;
        hotelList[add.pinecode].insert(key);
    }
};
class User {
private:
    vector<HotelData> History;
    userdata use;
public:

    User(string name, string email, Address address) {
        use.name = name;
        use.address = address;
        use.email = email;
        userList[email] = use;
    }
    void update(string name, string email , Address address )
    {
        use.name = name;
        use.address = address;
        use.email = email;
        auto it = userList.find(email);
        userList.erase(it);
        userList[email] = use;
    }
    void deletUser(string email)
    {
        auto it = userList.find(email);
        userList.erase(it);
    }
    vector<HotelData> getHistory()
    {
        return History;
    }

};
bool cmp(HotelData a, HotelData b)
{
    return a.cost > b.cost;
}
bool cmp1(HotelData a, HotelData b)
{
    return a.rating > b.rating;
}
class Search {

public:
    vector<HotelData> getHotelByPincode(int x, parameter c)
    {
        set<int> v = hotelList[x];
        vector<HotelData> ret;

        for (auto it = v.begin(); it != v.end(); it++)
        {
            ret.pb(HotelList[*it]);
        }

        if (c == cost)
        {
            sort(ret.begin(), ret.end(), cmp);
        }
        else {
            sort(ret.begin(), ret.end(), cmp1);
        }
        return ret;
    }
};

int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    Hotel obj1("asd", {"adsfew", 22345} , 5, 100), obj2("qwm", {"ashaadjwqe", 22345}, 4, 500);

    User us1("dsjd", "dsh@gmail.com", {"nfd", 121}), us2("dsjweed", "dsdsh@gmail.com", {"nfd", 1213});

    Search ser;
    vector<HotelData> v = ser.getHotelByPincode(22345, cost);
    cout << v[1].cost;

}