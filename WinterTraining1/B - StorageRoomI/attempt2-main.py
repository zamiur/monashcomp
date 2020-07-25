l = int(input()) # Lenght Input
w = int(input()) # Width  ""
h = int(input()) # Height ""

v = l*w*h
# print(f"The volume is {v}")

c = 2*((l*w)+(l*h)+(h*w)) # Surface Area and cost

if (1 <= v <= 1000):
    print(F"the cost is ${c}")
else:
    print("V is not larger than 1 or smaller than 10^3, exiting.")
    exit()
