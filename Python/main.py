import numpy as np
import time
#import matplotlib.pyplot as plt

### CHOOSE 1 TO IMPORT, COMMENT OUT THE REST
#from beale2d import valueandderivatives, valueonly
#from matyas import valueandderivatives, valueonly
from himmelblau import valueandderivatives, valueonly

global hessian_vecshaped
global grad
grad = [4,-4]
#identity_matrix = [[1,0],[0,1]]
hessian_vecshaped = np.ndarray(shape=(2,2), dtype=float)

def gradient_simple(x_vector, step, grad):
    for i in range(len(x_vector)):
        x_vector[i] = x_vector[i] - step * grad[i]
    return x_vector

def gradient_momentum(x_vector, m, a, step, grad):
    for i in range(len(x_vector)):
        m[i] = a * m[i] + step * grad[i]
        x_vector[i] = x_vector[i] - m[i]
    return x_vector, m

# def gradient_newton(x_vector, hessian_vecshaped, epsilon, step, grad):
#     for i in range(len(x_vector)):
#         x[i] = x[i] - hessian_vecshaped[i][i]+epsilon*identity_matrix

def gradient_newton(x_vector, hessian_vecshaped, epsilon, grad):
    matrix = np.ndarray(shape=(2,2), dtype=float)
    idMatrix = np.array([[1,0],[0,1]])

    # convert to inverse
    for j in range(len(idMatrix)):
        for i in range(len(idMatrix[j])):
            print(hessian_vecshaped[j][i])
            matrix[j][i] = hessian_vecshaped[j][i]+epsilon*idMatrix[j][i]


    matrix = np.linalg.inv(matrix)


    for i in range(len(x_vector)):
        x_vector[i] = x_vector[i] - matrix[i][i]  * grad[i]
    return x_vector

def checker (x, domain, grad):
    counter = 0 
    for i in range(len(x)):
        if x[i] <= domain[0]:
            counter+=1
            if grad[i] > 0:
                print("Terminated x hit lower domain")
                exit()
            
        elif x[i] >= domain[1]:
            counter+=1
            tempGrad = -1 * grad[i]
            if tempGrad > 0:
                print("Terminated x hit upper domain")
                exit()
    
    if counter >=2:
        print("Two or more")
        exit()
        


def main():
    #x = [3, 0.5]

    # set by user
    step = 0.01 # step
    a = 0.5 # moment
    x = [-4,4] # starting vector
    domain = [-5, 5]
    epsilon  = 0.00001 # epsilon

    # used by algo
    m = [0,0] # gradient momentum
    lowest = 99999999999
    

    while(True):
        fx = valueandderivatives(2, x, grad, hessian_vecshaped)
        #x = gradient_newton(x, hessian_vecshaped, epsilon, grad)
        #x, m = gradient_momentum(x, m, a, step, grad)
        x = gradient_simple(x, step, grad)
        print(x)
        checker (x, domain, grad)

        # Check for x within boundary
        # for i in x:
        #     if(x )

        print(f"f(x): {fx}\tx1: {x[0]}\tx2: {x[1]}\tGrad1: {grad[0]}\tGrad2: {grad[1]}")
        if(fx < lowest):
            lowest = fx
        else:
            break
        time.sleep(0.01)
        
        

if __name__ == "__main__":
    main()
