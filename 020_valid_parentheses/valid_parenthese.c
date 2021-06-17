class Solution {
public:
    bool isValid(string s) {
        stack<char> char_stack;
        
        for(auto c : s)
        {
            if(c == '(' || c == '[' || c == '{'){
                char_stack.push(c);
                continue;
            } else if(char_stack.empty()){
                return false;
            } else if(c == ')'){
                if(char_stack.top() != '(')
                    return false;
            } else if(c == ']'){
                if(char_stack.top() != '[')
                    return false;
            } else{
                if(char_stack.top() != '{')
                    return false;
            }
            char_stack.pop();
        }
        
        if( char_stack.empty() )
            return true;
        else
            return false;
    }
};