#include <iostream>
#include <sstream>

using namespace std;

class BigDecimalInt{
    public:

        string value ;


        BigDecimalInt (string decStr)
        {
            if (decStr.find_first_not_of("-0123456789") == std::string::npos){
                value = decStr ;
          //      cout <<value<<endl;
                }
            else { cout <<"Invalid Number"<<endl;  }
        }

        BigDecimalInt (int decInt)
        {
            ostringstream temp;
            temp<<decInt;
            value =  temp.str() ;
         //   cout <<value<<endl;
        }

        int size()
        {
            return value.size() ;
        }

        BigDecimalInt operator+ (BigDecimalInt anotherDec)
        {
            string result, not_used , final_res ;
            int reminder;
            result = "" ;
            int result_value ;
            reminder = 0 ;
            int res = 0 ;
            int sizeofloop;
            if (size()>anotherDec.size())
            {
               // cout << "here" <<endl;
                sizeofloop = anotherDec.size();
                int step = size()-anotherDec.size() ;
                not_used = result + value.substr(0,step);
            }
            else
            {
            /*
                cout << "there" <<endl;
                cout << "Number 1 is : "<<value <<endl;
                cout << "Number 2 is : "<<anotherDec <<endl;*/
                sizeofloop = size();
                int step = anotherDec.size() - size() ;
                not_used = anotherDec.value.substr(0,step);
               // cout << not_used <<" <--Not used" <<endl;
              //  cout << sizeofloop <<" <--Size of loop" <<endl;

            }

            int j , k ;
            j = anotherDec.size() -1 ;
            k = size() - 1;

            for(int i = sizeofloop -1 ; i >=0 ; i--)
                {

                    int temp1 =  value[k] - '0';
                    int temp2 =  anotherDec.value[j] - '0' ;
                    if (value[0] == '-') temp1 = -temp1;
                    if (anotherDec.value[0] == '-') temp2 = -temp2;
                    // int res ;
                    res = reminder + temp1 +temp2 ;
                /*    cout << "Reminder is : "<<reminder <<endl;
                    cout << "Num 1 is : "<<temp1 <<endl;
                    cout << "Num 2 is : "<<temp2 <<endl;
                    cout << "Res is : "<<res <<endl; */


                    if (to_string(res).length() >1) {
                       // cout <<"1" <<endl;
                        string t = to_string(res);
                        result = t[1] + result ;
                     //   cout <<"To be taken as res " << result <<endl;
                        reminder = t[0] - '0';
                     //   cout <<"The reminder is " << reminder <<endl;
                                        }
                    else {
                        //cout <<"2" <<endl;
                        result =  to_string(res) + result ;
                        reminder = 0 ;
                            }
                    j -- ;
                    k -- ;
                    //cout << "Result is : "<<result <<endl;
                }
            final_res = not_used + result;
            if (reminder != 0 )
            {
                string nth = to_string(reminder) + result ;
                int f = stoi(final_res) + stoi(nth);
                final_res = to_string(f);
            }
            //cout << "Result after adding reminder is : "<<result <<endl;

            return final_res;
        }

        BigDecimalInt operator= (BigDecimalInt anotherDec)
        {
            return 0 ;
        }

        friend ostream& operator << (ostream& out, BigDecimalInt b)
        {
            int s = b.size();
             for(int i = 0; i < s ; i++)
                { out << b.value[i]; }
            return out;
        }

};



int main()
{

    BigDecimalInt num1("41000000000000000000000000345535");
    BigDecimalInt num2 (191);
    BigDecimalInt num3  = num1 + num2 ;

    BigDecimalInt num4("4325344");
    BigDecimalInt num5 (4535232135435654654);
    BigDecimalInt num6  = num4 + num5 ;

    BigDecimalInt num7("5500000000000000000000000000000000000000000000000000000000000000");
    BigDecimalInt num8 (6);
    BigDecimalInt num9  = num7 + num8 ;

    BigDecimalInt num10("4325344");
    BigDecimalInt num11 (0);
    BigDecimalInt num12  = num10 + num11 ;

    BigDecimalInt num13("88");
    BigDecimalInt num14 (1);
    BigDecimalInt num15  = num13 + num14 ;


    cout << "Test case one result: " <<num3 << endl ;
    cout << "Test case two result: " <<num6 << endl ;
    cout << "Test case three result: " <<num9 << endl ;
    cout << "Test case four result: " <<num12 << endl ;

    cout << "Test case five result: " <<num15 << endl ;
    return 0;
}
