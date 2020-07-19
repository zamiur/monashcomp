n = int(input())
if(1 <= n <= 1000):
    if n % 28 == 0:
        print("YES")
    elif n % 4 == 0:
        print("YES")
    elif n % 7 == 0:
        print("YES")
    elif n % 47 == 0:
        print("YES")
    elif n % 74 == 0:
        print("YES")
    elif n % 477 == 0:
        print("YES")
    else:
        print("NO")
else:
    print(f"Cannot take n")