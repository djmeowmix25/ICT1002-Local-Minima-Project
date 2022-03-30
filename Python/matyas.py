
def valueonly(dim, x):
    if (dim != 2):
        print("Dim is not 2")

    p1 = 0.26 * (x[0]*x[0] + x[1]*x[1])
    p2 = 0.48 * x[0] * x[1]

    ret = p1-p2

    return ret


def valueandderivatives(dim, x, grad, hessian_vecshaped):
    if (dim != 2):
        print("dim is not 2")
        exit(2)

    ret = valueonly(dim, x)

    # gradient
    grad[0] = 0.52*x[0] - 0.48*x[1]
    grad[1] = 0.52*x[1] - 0.48*x[0]


    hessian_vecshaped[0+2*0] = 0.52
    hessian_vecshaped[1+2*1] = 0.52

    hessian_vecshaped[1+2*0] = -0.48

    hessian_vecshaped[0+2*1] = hessian_vecshaped[1+2*0];

    return ret
