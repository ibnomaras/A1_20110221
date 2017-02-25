#include <iostream>

using namespace std;

class StudentName
{
    public:
        string name;

        StudentName(string n)
        {
            int counter = 0;
            for(int i = 0 ; i < n.size() ; i++)
            {
                if(n[i] == ' ' && i !=n.size()-1 && i !=0)
                {
                    counter ++;
                }
            }
            if(counter>1) {
                name = n ;
            }
            else
            {
                string to_be_added = " ";

                int last = 0;
                if (counter!=0) last = n.find_last_of(" ");
                to_be_added = n.substr(last,n.size());
                for (int j = 0 ; j < (2-counter) ; j++)
                {
                    if (counter==0) n = n + " ";
                    n = n + to_be_added ;
                }

                name = n ;
            }
        }

    void print()
    {
       cout << "Name is: " << endl;
        int pos = 1 ;
        for (int i = 0 ; i<name.size(); i++){

            if(i==0) cout << pos << ") " << name[i];
            else if (name[i] != ' ')
            {
                cout << name[i];
            }
            else
            {
                pos ++ ;
                cout << endl << pos << ") ";
            }


        }
        cout << endl;
    }

    string Replace(int i,int j)
    {
        string state = "" ;
        int pos1, pos2 ;
        string name1 , name2;
        name1= "";
        name2= "" ;
        pos1 = i -1 ;
        pos2 = j -1 ;
        if(j==1) pos2=0;
        else if (i==1) pos1=0;

        for (int k = 0 ; k<name.size() ; k++)
        {
            if(name[k] == ' ') pos1-- ;
            if (pos1 == 0 && name[k]!=' ')
            {
                name1= name1 + name[k];
            }
        }

        for (int m = 0 ; m<name.size() ; m++)
        {
            if(name[m] == ' ') pos2-- ;
            if (pos2 == 0 && name[m]!=' ')
            {
                name2= name2 + name[m];
            }
        }

        if (pos1>0 || pos2>0)
        {
            state="false";
            cout << pos1 << " " <<pos2 << endl;
            return state ;
        }
        else
        {
            state = "true";
            int posofname1 = name.find(name1) ;
            int posofname2 = name.find(name2) ;
            name.replace(posofname1,name1.length(),name2);
            name.replace(posofname2,name2.length(),name1);
            return state ;
        }

    }

};


int main()
{
    StudentName st1("abdelrahman");
    StudentName st2("abdelrahman omar");
    StudentName st3("abdelrahman omar youssif");
    StudentName st4("abdelrahman omar youssif ismail");
    st4.print();
    cout << st4.Replace(1,4);
    st4.print();
    /*
    st1.print();
    st2.print();
    st3.print();
    st4.print();
    */
    return 0;
}
