# really cool idea, convert n to base k, then sum the digits.
# example: n = 11, k = 3, in base 3 11 is 102, since its 3^2*1 + 3^1*0 + 3^0*2,
# observe that's 1 + 0 + 2 operations. So we just need to sum these digits
# to convert to another base, you repeat division and record the remainder
# see this site for an example https://madformath.com/calculators/basic-math/base-converters/decimal-to-base-3-converter-with-steps/decimal-to-base-3-converter-with-steps

t = int(input())

for _ in range(t):
    n, k = map(int, input().split())

    if k == 1:
        print(n)

    else:
        num = 0
        while n != 0:
            num += n % k
            n = n // k
        print(num)


tests = int(input())

for test in range(tests):
    k = int(input().split(" ")[1])
    arr = [int(x) for x in input().split(" ")]

    errs = 0
    place = 1
    for num in arr:
        if place % k != num % k:
            errs += 1
            if errs > 2:
                print(str(-1))
                break
        place += 1
    if errs == 2:
        print(1)
    elif errs == 0:
        print(0)
