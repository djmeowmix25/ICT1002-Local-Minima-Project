import math

def valueonly(dim, x):
    if (dim != 2):
        print("Dim is not 2")


    p1 = -0.3 * math.exp(-10 * (x[0] - 0.5) ** 2 - 10 * (x[1] - 0.5) ** 2)
    p2 = 0.7 * math.exp(-10 * x[0] ** 2 - 10 * x[1] ** 2)

    ret = p1-p2

    return ret


def valueandderivatives(dim, x, grad, hessian_vecshaped):
    if (dim != 2):
        print("dim is not 2")
        exit(2)

    ret = valueonly(dim, x)


    # gradient
    p1 = math.exp(-10 * (x[0] - 0.5) ** 2 - 10 * (x[1] - 0.5) ** 2)
    p2 = math.exp(-10 * x[0] ** 2 - 10 * x[1] ** 2)
    p3 = x[0] - 0.5
    p4 = x[1] - 0.5

    grad[0] = 20 * 0.3 * p1 * p3 + 20 * 0.7 * p2 * x[0]
    grad[1] = 20 * 0.3 * p1 * p4 + 20 * 0.7 * p2 * x[1]


    hessian_vecshaped[0][0] = -20 * 20 * 0.3 * p1 * p3 ** 2 + 20 * 0.3 * p1 + - 20 * 20 * 0.7 * p2 * x[0] ** 2 + 20 * 0.7 * p2
    hessian_vecshaped[1][1] = -20 * 20 * 0.3 * p1 * p4 ** 2 + 20 * 0.3 * p1 + - 20 * 20 * 0.7 * p2 * x[1] ** 2 + 20 * 0.7 * p2

    hessian_vecshaped[0][1] = -20 * 20 * 0.3 * p1 * p3 * p4 + - 20 * 20 * 0.7 * p2 * x[0] * x[1]

    hessian_vecshaped[1][0] = hessian_vecshaped[0][1];

    return ret
