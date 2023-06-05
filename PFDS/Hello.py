ft_list = ["Hello", "tata!"]
ft_tuple = ("Hello", "toto!")
ft_set = {"Hello", "tutu!"}
ft_dict = {"Hello" : "titi!"}

#your code here
if ft_list[1] != "World":
    ft_list[1] = "World"
    
if ft_tuple[1] != "France":
    y = list(ft_tuple)
    y[1] = "France"
    ft_tuple = tuple(y)

if "tutu!" in ft_set:
    ft_set.remove("tutu!")
    ft_set.add("Lyon")


if ft_dict["Hello"] != "42Lyon":
    ft_dict["Hello"] = "42Lyon"
print(ft_list)
print(ft_tuple)
print(ft_set)
print(ft_dict)