from distutils.core import setup, Extension

module1 = Extension('TestDistutilsAffichage',
                    sources = ['afficher.c'])

setup (name = 'TestDistutilsAffichage',
       version = '1.0',
       description = 'This is a demo package for testing distutils on afficher.c',
       ext_modules = [module1])