class Solution
{
public:
    bool is_operator(char c)
    {
        return (c == '+' || c == '-');
    }

    int ft_eval(string& posFix)
    {
        int f_operand, s_operand;
        int num;
        stack <int> stck;

        for (size_t i = 0; posFix[i]; i++)
        {
            if (is_operator(posFix[i]))
            {
                f_operand = s_operand = 0;
                s_operand = stck.top();
                stck.pop();
                if (!stck.empty())
                {
                    f_operand = stck.top();
                    stck.pop();
                }
                if (posFix[i] == '+')
                    stck.push(f_operand + s_operand);
                if (posFix[i] == '-')
                    stck.push(f_operand - s_operand);
            }                
            else
            {
                num = 0;
                while (isdigit(posFix[i]))
                    num = num * 10 + (posFix[i++] - '0');
                stck.push(num);
            }
        }
        num = stck.top();
        stck.pop();
        return (num);
    }
    
    int calculate(string s)
    {
        size_t sz = s.length();
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
                    PosFix += "0,";
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
            else
            {
                while (isdigit(s[i]))
                    PosFix += s[i++];
                PosFix += ",";
                i--;
            }
        }
        while (!stck.empty())
        {
            PosFix.push_back(stck.top());
            stck.pop();
        }
        // cout    << "            PosFix = " << PosFix << endl;        
        return (ft_eval(PosFix));
    }
};
