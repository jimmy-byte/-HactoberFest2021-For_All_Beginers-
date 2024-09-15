import re


def bisection(f, a, b, TOL, NO):
    if f(a)*f(b) >= 0:
        print("Bisection method fails")
        return None

    i = 1
    FA = f(a)
    print(f'n       a       b       p         f(p)')
    print(f'--------------------------------------')
    print()
    while i <= NO:
        p = (a+b) / 2
        FP = f(p)
        print(
            f'{i}       {a}       {b}       {p}       {f(p)}')

        if FP == 0 or abs(f(p)) < TOL:
            FP = f(p)
            return print('The solution is ', p)

        i += 1

        if FA*FP > 0:
            a = p
            FA = FP

        else:

            b = p
    print("The method fails after N0 iterations. ")
    return None


def f(x): return x**3 + 4*x**2-10  # equation


bisection(f, 1, 2, 0.00001, 50)
