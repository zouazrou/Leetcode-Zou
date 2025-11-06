#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution
{
public:
    bool is_operator(char c)
    {
        return (c == '+' || c == '-' || c == '*' || c == '/');
    }

    int piority(char c)
    {
        if (c == '/' || c == '*')
            return 2;
        if (c == '+' || c == '-')
            return 1;
        return 0;
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
                s = stck.top();
                stck.pop();
                f = stck.top();
                stck.pop();
                if (posFix.at(i) == '*')
                    stck.push(f * s);
                if (posFix.at(i) == '/')
                    stck.push(f / s);
                if (posFix.at(i) == '+')
                    stck.push(f + s);
                if (posFix.at(i) == '-')
                    stck.push(f - s);
            }                
            else /*(isdigit(posFix.at(i)))*/
            {
                string num;
                for (; posFix[i] && isdigit(posFix[i]); i++)
                    num += posFix[i];                
                stck.push(stoi(num));
            }
        }
        result = stck.top();
        stck.pop();
        return (result);
    }
    
    int calculate(string s)
    {
        string  PosFix;
        stack   <char> stck;

        for (size_t i = 0; s[i]; i++)
        {
            if (isspace(s[i]))
                continue;
            
            if (is_operator(s[i]))
            {
                while (!stck.empty() && piority(s[i]) <= piority(stck.top()))
                {
                    PosFix.push_back(stck.top());
                    stck.pop();
                }
                stck.push(s[i]);
            }
            else if (isdigit(s[i]))
            {
                while (isdigit(s[i]))
                    PosFix += s[i++];
                PosFix += " ";
                i--;                
            }
        }
        while (!stck.empty())
        {
            PosFix.push_back(stck.top());
            stck.pop();
        }
        cout    << "PosFix = " << PosFix << endl;        
        return (ft_eval(PosFix));
    }
};

int main(int ac, char *av[])
{
    Solution    slv;
    string      input;
    
    cout << "--------------------" << endl;
    input = "3+2*2";
    cout << "Input : " << input << endl;
    cout << slv.calculate(input) << endl; 
    // *************************************
    cout << "--------------------" << endl;
    input = "1 + 1";
    cout << "Input : " << input << endl;
    cout << slv.calculate(input) << endl; 
    // *************************************
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
}
    