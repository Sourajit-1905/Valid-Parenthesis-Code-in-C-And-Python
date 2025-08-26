def matchedParenthesis(opening, closing):
    if ((opening == '(' and closing == ')') or
    (opening == '{' and closing == '}') or
    (opening == '[' and closing == ']')):
        return 1

    return 0

def parenthesis_match(exp):
    stack = []
    
    for ch in exp:
        if (ch == '(' or ch == '{' or ch == '['):
            stack.append(ch)

        elif (ch == ')' or ch == '}' or ch == ']'):
            if len(stack) == 0:
                return 0

            poppedChar = stack.pop()
            if not matchedParenthesis(poppedChar, ch):
                return 0
            
    return 1 if len(stack) == 0 else 0
                


def main():
    expression = input("Enter an expression with parentheses: ")

    if parenthesis_match(expression):
        print("The parentheses are balanced.")
    else:
        print("The parentheses are NOT balanced.")

if __name__ == "__main__":
    main()
