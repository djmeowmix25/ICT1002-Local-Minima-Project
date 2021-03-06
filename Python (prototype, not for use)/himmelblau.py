
def valueonly(dim, x):
    if (dim != 2):
        print("Dim is not 2")

    p1 = (x[0] * x[0] + x[1] - 11)
    p2 = (x[0] + x[1] * x[1] - 7)

    ret = p1*p1 + p2*p2

    return ret


def valueandderivatives(dim, x, grad, hessian_vecshaped):
    if (dim != 2):
        print("dim is not 2")
        exit(2)

    ret = valueonly(dim, x)

    # gradient
    p1 = x[0] * x[0] + x[1] - 11
    p2 = x[0] + x[1] * x[1] - 7

    grad[0] = 2 * p1 * 2 * x[0] + 2 * p2
    grad[1] = 2 * p1 + 2 * p2 * 2 * x[1]

    hessian_vecshaped[0][0] = (4 * x[0] * 2 * x[0]) + (2 * p1 * 2) + 2
    hessian_vecshaped[1][1] = 2 + (2 * p2 * 2) + (4 * x[1] * 2 * x[1])
    hessian_vecshaped[0][1] = (4 * x[0]) + (4 * x[1])
    hessian_vecshaped[1][0] = hessian_vecshaped[0][1];

    return ret
