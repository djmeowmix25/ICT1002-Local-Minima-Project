global hessian_vecshaped 
hessian_vecshaped = [0,0,0,0]
global grad
grad = [0,0]

# def valueonly_himmelblau2d(dim, x):
#     if (dim != 2):
#         print("Dim is not 2")

#     p1 = 2 * (x[0] * x[0] + x[1] - 11)
#     p2 = 2 * (x[0] + x[1] * x[1] - 7)


#     # p3 = 2.625 - x[0] + x[0]*x[1]*x[1]*x[1]

#     ret = p1*p1 + p2*p2 + p3*p3

#     return ret


def valueandderivatives_himmelblau2d(dim, x):
    if (dim != 2):
        print("dim is not 2")
        exit(2)


    # gradient
    p1 = 2 * (x[0] * x[0] + x[1] - 11)
    p2 = 2 * (x[0] + x[1] * x[1] - 7)

    grad[0] = 2 * p1 * 2 * x[0] + 2 * p2
    grad[1] = 2 * p1 + 2 * p2 * 2 * x[1]

    hessian_vecshaped[0+2*0] = 4 * x[0] * 2 * x[0] + 2 * p1 * 2 + 2
    hessian_vecshaped[1+2*1] = 2 + 2 * p2 * 2 + 4 * x[1] * 2 * x[1]
    hessian_vecshaped[1+2*0] = 4 * x[0] + 4 * x[1]
    hessian_vecshaped[0+2*1] = hessian_vecshaped[1+2*0]; 
    
    #return ret

x = [-5, 5]

for i in range (-5, 5, 1):
    x = [i, i+1]
    valueandderivatives_himmelblau2d(2, x)
    print(hessian_vecshaped)
    print(grad)
