#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>
#include <vector>

using std::cout;
using std::vector;
using std::string;
using std::endl;
using std::cin;
using std::ifstream;

// calculate distance between password a and b
int distance(const string& a, const string& b) {
    int distance = 0;
    // loop chars
    for (int i = 0; i < (int)std::max(a.size(), b.size()); i++) {
        // if a is longer than b, distance + 1
        if (i >= (int)a.size()) {
            distance += 1;
            continue;
        }
        // if b is longer than a, distance + 1
        if (i >= (int)b.size()) {
            distance += 1;
            continue;
        }
        // if a[i] and b[i] are different, distance + 1
        if (a[i] != b[i]) distance += 1;
    }

    return distance;
}

bool compare_password(string& p1, string& p2) {
    return p1<p2;
}

int main() {
    string password;
    cout<<"Give me a password:"<<endl;
    cin>>password;
    cout<<"You provided a password of "<<password<<endl;
    cout<<"The most similar passwords to "<<password<<" are:"<<endl;

    // read data file
    ifstream passwordfile("common_passwords.txt");
    string curpassword;
    vector<string> passwords;
    while (passwordfile>>curpassword) {
        passwords.push_back(curpassword);
    }

    // sort
    std::sort(passwords.begin(), passwords.end(), compare_password);

    // find min distance
    int mindistance = password.size();
    for(string& cur: passwords){
        int d = distance(cur, password);
        if (d<mindistance) {
            mindistance = d;
        }
    }

    // print result
    for(string& cur: passwords){
        int d = distance(password, cur);
        if (d==mindistance) {
            cout<<cur<<", ";
        }
    }
    cout<<endl;
    cout<<"All of which are "<<mindistance<<" character(s) different."<<endl;

    return 0;
}