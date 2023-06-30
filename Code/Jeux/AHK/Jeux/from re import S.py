from re import S
import sqlite3
import sys
import math
import json

class ScreenXY:
   def _init_(self, resoX, resoY, radius,centerX=-1, centerY=-1):
       self.rX=resoX
       self.rY=resoY
       self.radius=radius
screen = ScreenXY(1,2,4,5)
print(screen.rX)