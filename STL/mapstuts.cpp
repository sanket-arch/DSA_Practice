#include <iostream>
#include <map>
using namespace std;

int main()
{
    map<int, string> m; // this will arange in the sorted array accoe=rding to the key value

    m[1] = "sanket"; //time complexity will be o(logn)
    m[2] = "levelhead"; // this is one way to isnert data in map
    m[5] = "kut";

    m.insert({4, "love"}); // another way of inserting data in map where first value is key and another is value

    map<int, string>::iterator iter;                // we create iterator which is used to iterate through map
    for (iter = m.begin(); iter != m.end(); ++iter) // this loop will go from  begining to end
    {
        cout << (*iter).first << " " << (*iter).second << endl;
        //(*iter).first=> will access the key and (*ter).second=> will access the value
    }

// we can iterate through map with using iterator
for(auto &itr:m)
{
    cout<<itr.first<<"  "<<itr.second; 
}


auto it=m.begin();
cout<<(*it).first<<endl;
advance(it,2);
cout<<(*it).first<<endl;

    return 0;
}