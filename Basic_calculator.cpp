#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution
{
public:
    bool is_operator(char c)
    {
        return (c == '+' || c == '-');
    }

    int ft_eval(string posFix)
    {
        int f, s;
        int result = 0;
        stack <int> stck;

        for (size_t i = 0; posFix[i]; i++)
        {
            if (is_operator(posFix.at(i)))
            {
                f = s = 0;
                s = stck.top();
                stck.pop();
                if (!stck.empty())
                {
                    f = stck.top();
                    stck.pop();
                }
                else 
                    cout << "is Empty" << endl;
                if (posFix.at(i) == '+')
                    stck.push(f + s);
                if (posFix.at(i) == '-')
                    stck.push(f - s);
            }                
            else
                stck.push(posFix[i] - '0');
        }
        result = stck.top();
        stck.pop();
        return (result);
    }
    
    int calculate(string s)
    {
        int sz = s.length();
        string  PosFix;
        stack   <char> stck;

        for (size_t i = 0; i < sz; i++)
        {
            if (isspace(s[i]))
                continue;
            if (s[i] == '(')
            {
                stck.push(s[i++]);
                while (i < sz && isspace(s[i]))
                    i++;
                if (is_operator(s[i]))
                    PosFix += "0";
                i--;
            }
            else if (s[i] == ')')
            {
                while (stck.top() != '(')
                {
                    PosFix.push_back(stck.top());
                    stck.pop();
                }
                if (stck.top() == '(')
                    stck.pop();
            }
            else if (is_operator(s[i]))
            {
                while (!stck.empty() && is_operator(stck.top()))
                {
                    PosFix.push_back(stck.top());
                    stck.pop();
                }
                stck.push(s[i]);
            }
            else if (isdigit(s[i]))
            {
                PosFix += s[i];
            }

            
            
        }
        while (!stck.empty())
        {
            PosFix.push_back(stck.top());
            stck.pop();
        }
        // cout    << "PosFix = " << PosFix << endl;        
        return (ft_eval(PosFix));
    }
};

int main(int ac, char *av[])
{
    Solution    slv;
    string      input;
    
    cout << "--------------------" << endl;
    input = " 2-1 + 2 ";
    cout << "Input : " << input << endl;
    cout << slv.calculate(input) << endl; 
    // *************************************
    cout << "--------------------" << endl;
    input = "1-1+1";
    cout << "Input : " << input << endl;
    cout << slv.calculate(input) << endl; 
    // *************************************
    cout << "--------------------" << endl;
    input = "(1+(4+5+2)-3)+(6+8)";
    cout << "Input : " << input << endl;
    cout << slv.calculate(input) << endl; 
    // *************************************
    cout << "--------------------" << endl;
    input = "2";
    cout << "Input : " << input << endl;
    cout << slv.calculate(input) << endl; 
    // *************************************
    cout << "--------------------" << endl;
    input = "1-(   -2)";
    cout << "Input : " << input << endl;
    cout << slv.calculate(input) << endl; 
    // *************************************
}
    