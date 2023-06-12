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