#import numpy as np
#import matplotlib.pyplot as plt
import beale2d

global hessian_vecshaped 
hessian_vecshaped = [0,0,0,0]
global grad
grad = [0,0]
  

def main():
    x = [2, 0.5]
    #double = valueonly_beale2d(2, x)
    double = beale2d.valueandderivatives_beale2d(2, x)
    print(double)
    print(hessian_vecshaped)
    print(grad)
    


main()
