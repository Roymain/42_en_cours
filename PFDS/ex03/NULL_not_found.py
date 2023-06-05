import math


def NULL_not_found(object: any) -> int:
    if object == "Brian":
        print("Type not found")
        return 1
    print(object, type(object))
    if math.isnan(object):
        print("cheese")

    return 0