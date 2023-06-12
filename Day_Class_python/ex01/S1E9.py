from abc import ABC, abstractmethod


class Character(ABC):
    """
    A class to represent a person.
    """

    def __init__(self, name, alive=True):
        """
        init function 
        """
        self.first_name = name
        self.is_alive = alive


    @abstractmethod
    def die(self):
        """
        dead function
        """
        self._is_alive = False
#your code here




class Stark(Character):
    """
    A class to represent a stark, inherits to class character.
    """
    def __init__(self, name, alive=True):
        """
        init function 
        """
        super().__init__(name, alive = alive)    
        
        
    def die(self):
        """
        dead function
        """
        self.is_alive = False
        
        
        
class Baratheon(Character):
    """
    A class to represent a Baratheo, inherits to class character.
    """
    def __init__(self, name, alive=True):
        """
        init function 
        """
        super().__init__(name, alive = alive)
        self.family_name = "Barathon"
        self.eyes = "brown"
        self.hairs = "dark"
        
        
    def die(self):
        """
        dead function
        """
        self.is_alive = False
       
    def __str__(self):
        return "Vector: %s %s %s" % (self.family_name, self.eyes, self.hairs)

    def __repr__(self):
        return "Vector: %s %s %s" % (self.family_name, self.eyes, self.hairs)
 
    #your code here
class Lannister(Character):
    #your code here
    # decorator    
    def __init__(self, name, alive=True):
        """
        init function 
        """
        super().__init__(name, alive = alive)
        self.family_name = "Lannister"
        self.eyes = "Blue"
        self.hairs = "light"
        
        
    def die(self):
        """
        dead function
        """
        self.is_alive = False

    def __str__(self):
        return "Vector: %s %s %s" % (self.family_name, self.eyes, self.hairs)

    def __repr__(self):
        return "Vector: %s %s %s" % (self.family_name, self.eyes, self.hairs)

    @classmethod
    def create_lannister(cls, name, alive):
        return cls(name, alive)