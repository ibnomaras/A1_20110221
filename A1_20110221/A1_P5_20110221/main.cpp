#include <iostream>
#include <map>


using namespace std;
map <string , int> mymap ;
void RecPermute(string soFar, string rest)
{
    if (rest == "" ) // No more characters
    {
        if (mymap.count(soFar)==0)
        {
            cout << soFar << endl;
            mymap.insert(make_pair(soFar,3));
        }
    }
        // Print the word
    else // Still more chars
    {
        for (int i = 0; i < rest.length(); i++)
        {
            string next = soFar + rest[i]; // Glue next char
            string remaining = rest.substr(0, i)+ rest.substr(i+1);
            RecPermute(next, remaining);
        }
    }

}
// "wrapper" function
void ListPermutations(string s)
{
    /*
    string temp = "";
    for (int i = 0 ; i<s.length() ; i++)
    {
        if(temp.find(s[i]) == -1) temp = temp + s[i];
    }

    s = temp ;
    cout << "S Is :" << s <<endl; */
    RecPermute("", s);
}


int main()
{
    string data = "ali";
    string data2 = "makka";
    ListPermutations(data);
    cout << "--------" <<endl;
    ListPermutations(data2);
    return 0;
}
