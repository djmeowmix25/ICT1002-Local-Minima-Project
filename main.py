#import numpy as np
#import matplotlib.pyplot as plt
import beale2d
import matyas

global hessian_vecshaped 
global grad
  

def main():
    x = [3, 0.5]
    grad = [0,0]
    hessian_vecshaped = [0,0,0,0]
    #double = valueonly_beale2d(2, x)
    double = beale2d.valueandderivatives_beale2d(2, x, grad, hessian_vecshaped)
    print(double)
    print(hessian_vecshaped)
    print(grad)
    
    hessian_vecshaped = [0,0,0,0]
    grad = [0,0]
    
    y = [0,0]
    double2 = matyas.valueandderivatives_matyas(2, y, grad, hessian_vecshaped)
    print(double2)
    print(hessian_vecshaped)
    print(grad)
    


main()
