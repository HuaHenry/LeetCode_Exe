class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> charStack;
        for (auto i : s)
        {
            if (i == '(' || i == '[' || i == '{')
                charStack.push(i);
            else if (charStack.empty())
                return false;
            else if ((charStack.top() - i) * (charStack.top() - i) == 1 || (charStack.top() - i) * (charStack.top() - i) == 4)
                charStack.pop();
            else
                return false;
        }
        if (charStack.empty())
            return true;
        return false;
    }
};