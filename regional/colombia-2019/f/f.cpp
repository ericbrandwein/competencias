from fractions import Fraction

def next_token(text, i):
    if i >= len(text):
        return i, 'END'
    if text[i] in ('+', '-', '(', ')'):
        return i+1, text[i]
    if text[i] in ('0', '1', '2', '3', '4', '5', '6', '7', '8', '9'):
        num_start = i
        i += 1
        while i < len(text) and text[i] in ('0', '1', '2', '3', '4', '5', '6', '7', '8', '9'):
            i += 1
        num_end = i
        i += 1 # skip /
        denom_start = i
        while i < len(text) and text[i] in ('0', '1', '2', '3', '4', '5', '6', '7', '8', '9'):
            i += 1
        denom_end = i

        num = int(text[num_start:num_end])
        denom = int(text[denom_start:denom_end])

        return i, Fraction(num, denom)

def eval(text):
    text_pos = 0
    def advance():
        nonlocal text_pos
        text_pos, token = next_token(text, text_pos)
        return token

    result = Fraction(0, 1)
    curr = advance()
    paren = [1]
    sign = [1]
    while curr != 'END':
        if isinstance(curr, Fraction):
            result += curr * sign.pop() * paren[-1]
        if curr == '+':
            sign.append(1)
        if curr == '-':
            sign.append(-1)
        if curr == '(':
            paren.append(sign.pop())
            sign.append(1)
        if curr == ')':
            paren.pop()
        curr = advance()
    print(f'{result.numerator}/{result.denominator}')

try:
    while True:
        eval(input())
except:
    pass