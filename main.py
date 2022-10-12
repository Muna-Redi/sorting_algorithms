#!/usr/bin/python3

class Pokemon():

    def __init__(self, name, type):

        self.name = name

        self.type = type

 

    def stringPokemon(self):

        print("Pokemon name is {} and type is {}".format(self.name, self.type))

 

class GrassType(Pokemon):

 

    # overrides the stringPokemon() function on 'Pokemon' class

    def stringPokemon(self):

        print("Grass type pokemon name is {}".format(self.name))
