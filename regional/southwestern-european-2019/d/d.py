def run_program(s):
    stack = []
    last_base = 0

    def pop():
        nonlocal last_base
        if len(stack) == 0:
            last_base += 1
            return last_base
        else:
            return stack.pop()

    for op in s:
        if op == 'C': # Dup
            base = pop()
            stack.append(base)
            stack.append(base)
        elif op == 'D': # Pop
            pop()
        elif op == 'L': # Car
            base = pop()
            if isinstance(base, tuple):
                stack.append(base[0])
            else:
                return 'FAIL'
        elif op == 'P': # Cons
            fst = pop()
            snd = pop()
            stack.append((fst, snd))
        elif op == 'R': # Cdr
            base = pop()
            if isinstance(base, tuple):
                stack.append(base[1])
            else:
                return 'FAIL'
        elif op == 'S': # Swap
            first = pop()
            second = pop()
            stack.append(first)
            stack.append(second)
        elif op == 'U': # Uncons
            base = pop()
            if isinstance(base, tuple):
                stack.append(base[1])
                stack.append(base[0])
            else:
                return 'FAIL'

    return (last_base, stack)

A = input()
B = input()

print(run_program(A) == run_program(B))