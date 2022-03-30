#import numpy as np
#import matplotlib.pyplot as plt
# test functions
import time
import beale2d
import matyas
import himmelblau

global hessian_vecshaped
global grad
grad = [0,0]
hessian_vecshaped = [0,0,0,0]

def plain_gradient_simple(x_vector, step, grad):
    for i in range(len(x_vector)):
        x_vector[i] = x_vector[i] - step * grad[i]
    return x_vector


def main():
    #x = [3, 0.5]
    step = 0.01
    x = [0,0]
    lowest = 99999999999

    while(True):
        x = plain_gradient_simple(x, step, grad)
        fx = beale2d.valueandderivatives(2, x, grad, hessian_vecshaped)
        print(f"f(x): {fx}\tx1: {x[0]}\tx2: {x[1]}\tGrad1: {grad[0]}\tGrad2: {grad[1]}")
        if(fx < lowest):
            lowest = fx
        else:
            break


    # hessian_vecshaped = [0,0,0,0]
    # #double = valueonly_beale2d(2, x)
    # double = beale2d.valueandderivatives(2, x, grad, hessian_vecshaped)
    # print(double)
    # print(hessian_vecshaped)
    # print(grad)
    #
    #
    #
    # hessian_vecshaped = [0,0,0,0]
    # grad = [0,0]
    # y = [i,j]
    # print (i, j)
    # double2 = matyas.valueandderivatives(2, y, grad, hessian_vecshaped)
    # print(double2)
    # print(hessian_vecshaped)
    # print(grad)



main()
