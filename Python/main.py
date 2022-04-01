import numpy as np
import time
import pickle
#import matplotlib.pyplot as plt

### CHOOSE 1 TO IMPORT, COMMENT OUT THE REST
#from beale2d import valueandderivatives, valueonly
<<<<<<< HEAD
#from matyas import valueandderivatives, valueonly
from himmelblau import valueandderivatives, valueonly
=======
from matyas import valueandderivatives, valueonly
#from himmelblau import valueandderivatives, valueonly
>>>>>>> 620fd1ee4e53f83dfeda505b390fc070a92a92dd

global hessian_vecshaped
global grad
grad = [0,0]
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
            matrix[j][i] = hessian_vecshaped[j][i]+epsilon*idMatrix[j][i]

    matrix = np.linalg.inv(matrix)

    result = [0,0]
    for i in range(len(matrix)):
        for j in range(len(grad)):
            result[i] += matrix[i][j] * grad[j]
    print(result)

    for i in range(len(x_vector)):
        x_vector[i] = x_vector[i] - result[i]
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
<<<<<<< HEAD
    x = [4,2] # starting vector
    domain = [-5, 5] # domain
    epsilon  = 0.01 # epsilon
=======
    x = [-1,1] # starting vector
    domain = [-10, 10]
    epsilon  = 0.00001 # epsilon
>>>>>>> 620fd1ee4e53f83dfeda505b390fc070a92a92dd

    # used by algo
    m = [0,0] # gradient momentum
    lowest = 99999999999

    with open("steps.txt", "w") as f:
        f.write('')

    # Generate values for 3d contour plot
    first = []
    Z = []
    for x1 in np.linspace(domain[0], domain[1]):
        for x2 in np.linspace(domain[0], domain[1]):
            first.append(valueonly(2, [x1, x2]))
        Z.append(first)
        first = []
    X, Y = np.meshgrid(np.linspace(domain[0], domain[1]), np.linspace(domain[0], domain[1]))
    Z = np.array(Z)
    with open("3d.txt", "ab") as f:
        pickle.dump([X, Y, Z], f)

    from mpl_toolkits import mplot3d

    import matplotlib.pyplot as plt
    fig = plt.figure()
    ax = plt.axes(projection='3d')
    ax.plot_surface(X, Y, Z, rstride=1, cstride=1,
                    cmap='viridis', edgecolor='none')
    ax.set_title('surface');
    #plt.show()
    counter = 0
    while(counter < 1000):
        fx = valueandderivatives(2, x, grad, hessian_vecshaped)
        x = gradient_newton(x, hessian_vecshaped, epsilon, grad)
        #x, m = gradient_momentum(x, m, a, step, grad)
        #x = gradient_simple(x, step, grad)

        # Check for x within boundary
        # for i in x:
        #     if(x )

        print(f"f(x): {fx}\tx1: {x[0]}\tx2: {x[1]}\tGrad1: {grad[0]}\tGrad2: {grad[1]}")
        checker (x, domain, grad)

        with open("steps.txt", "a") as f:
            #f.write(f'f(x): {round(fx, 5)}\tx1: {round(x[0], 5)}\tx2: {round(x[1], 5)}\t\n')
            f.write(f'f(x): {fx}\tx1: {x[0]}\tx2: {x[1]}\t\n')

        lowest = fx
        if(fx < 0.00001):
            break
        counter +=1
        # else:
        #     break
        #time.sleep(0.01)



if __name__ == "__main__":
    main()
